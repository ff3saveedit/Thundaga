//========================================================================================================
// CharEquipEdit.cpp : implementation file
//========================================================================================================
#include "stdafx.h"
#include "Digits.h"
#include "Thundaga.h"
#include "CharEquipEdit.h"
//========================================================================================================
IMPLEMENT_DYNAMIC(CEquipEdit, CDialog)
//========================================================================================================
CEquipEdit::CEquipEdit(int iCharacter, CWnd* pParent /*=NULL*/)
	: CDialog(CEquipEdit::IDD, pParent)
{
	m_iChar = iCharacter;
}
//========================================================================================================
CEquipEdit::~CEquipEdit()
{
}
//========================================================================================================
void CEquipEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_EQUIP_HEAD, m_Head);
	DDX_Control(pDX, IDC_COMBO_EQUIP_BODY, m_Body);
	DDX_Control(pDX, IDC_COMBO_EQUIP_ARMS, m_Arms);
	DDX_Control(pDX, IDC_COMBO_EQUIP_RHAND, m_RHand);
	DDX_Control(pDX, IDC_COMBO_EQUIP_LHAND, m_LHand);

}
//========================================================================================================
BOOL CEquipEdit::OnInitDialog()
{
	int i;
	CDialog::OnInitDialog();
	
	// Insert Defaults
	m_Head.InsertString(0, "<EMPTY>");
	m_Body.InsertString(0, "<EMPTY>");
	m_Arms.InsertString(0, "<EMPTY>");
	m_RHand.InsertString(0, "<EMPTY>");
	m_LHand.InsertString(0, "<EMPTY>");

	// Head Gear
	DIGIT_FOR(HEADGEAR_START, HEADGEAR_SIZE)
		m_Head.InsertString(i-HEADGEAR_START, ItemTable[i-1].szDigitName);

	// Body Armor
	DIGIT_FOR(ARMOR_START, ARMOR_SIZE)
		m_Body.InsertString(i-ARMOR_START, ItemTable[i-1].szDigitName);

	// Arms (Gloves)
	DIGIT_FOR(ARMS_START, ARMS_SIZE)
		m_Arms.InsertString(i-ARMS_START, ItemTable[i-1].szDigitName);

	// Right Hand (Weapons + Shields)
	DIGIT_FOR(WEAPON_SHIELD_START, WEAPON_SHIELD_SIZE)
		m_RHand.InsertString(i-WEAPON_SHIELD_START, ItemTable[i-1].szDigitName);

	// Left Hand (Weapons + Shields)
	DIGIT_FOR(WEAPON_SHIELD_START, WEAPON_SHIELD_SIZE)
		m_LHand.InsertString(i-WEAPON_SHIELD_START, ItemTable[i-1].szDigitName);

	// Current Arms Item
	if (pSlot->Char[m_iChar].ArmsDigit == 0)
		m_Arms.SetCurSel(0);
	else
		m_Arms.SetCurSel(iGetIndexFromDigit(tblArms, ARMS_SIZE, pSlot->Char[m_iChar].ArmsDigit)+1);
	
	// Current Head Item
	if (pSlot->Char[m_iChar].ArmsDigit == 0)
		m_Head.SetCurSel(0);
	else
		m_Head.SetCurSel(iGetIndexFromDigit(tblHead, HEADGEAR_SIZE, pSlot->Char[m_iChar].HeadDigit)+1);

	// Current Body Item
	if (pSlot->Char[m_iChar].ArmsDigit == 0)
		m_Body.SetCurSel(0);
	else
		m_Body.SetCurSel(iGetIndexFromDigit(tblBody, ARMOR_SIZE, pSlot->Char[m_iChar].BodydDigit)+1);

	// Current R. Hand Item
	if (pSlot->Char[m_iChar].ArmsDigit == 0)
		m_RHand.SetCurSel(0);
	else
		m_RHand.SetCurSel(iGetIndexFromDigit(tblHands, WEAPON_SHIELD_SIZE, pSlot->Char[m_iChar].R_HandDigit)+1);

	// Current L. Hand Item
	if (pSlot->Char[m_iChar].ArmsDigit == 0)
		m_LHand.SetCurSel(0);
	else
		m_LHand.SetCurSel(iGetIndexFromDigit(tblHands, WEAPON_SHIELD_SIZE, pSlot->Char[m_iChar].L_HandDigit)+1);

	return TRUE;
}
//========================================================================================================
BEGIN_MESSAGE_MAP(CEquipEdit, CDialog)
	ON_CBN_SELCHANGE(IDC_COMBO_EQUIP_RHAND, &CEquipEdit::OnCbnSelchangeComboEquipRhand)
	ON_CBN_SELCHANGE(IDC_COMBO_EQUIP_LHAND, &CEquipEdit::OnCbnSelchangeComboEquipLhand)
	ON_CBN_SELCHANGE(IDC_COMBO_EQUIP_HEAD, &CEquipEdit::OnCbnSelchangeComboEquipHead)
	ON_CBN_SELCHANGE(IDC_COMBO_EQUIP_BODY, &CEquipEdit::OnCbnSelchangeComboEquipBody)
	ON_CBN_SELCHANGE(IDC_COMBO_EQUIP_ARMS, &CEquipEdit::OnCbnSelchangeComboEquipArms)

END_MESSAGE_MAP()
//========================================================================================================
BOOL CEquipEdit::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
			pMsg->wParam = NULL;
	} 
	return CDialog::PreTranslateMessage(pMsg);
}
//========================================================================================================
void CEquipEdit::OnCbnSelchangeComboEquipRhand()
{
	int iDigit = NULL;
	if (m_RHand.GetCurSel() == 0)
	{
		pSlot->Char[m_iChar].R_HandDigit = 0;
		pSlot->Char[m_iChar].bR_HandEquipped = 0;
		return;
	}
	
	pSlot->Char[m_iChar].R_HandDigit = ItemTable[WEAPONS_START+(m_RHand.GetCurSel()-1)].ItemDigit;
	pSlot->Char[m_iChar].bR_HandEquipped = 1;
}
//========================================================================================================
void CEquipEdit::OnCbnSelchangeComboEquipLhand()
{
	if (m_LHand.GetCurSel() == 0)
	{
		pSlot->Char[m_iChar].L_HandDigit = 0;
		pSlot->Char[m_iChar].bL_HandEquipped = 0;
		return;
	}

	if (m_LHand.GetCurSel() > WEAPONS_SIZE)
	{
		int iDigit = ItemTable[SHIELDS_START+((m_LHand.GetCurSel()-WEAPONS_SIZE)-1)].ItemDigit;
		pSlot->Char[m_iChar].L_HandDigit = iDigit;
		pSlot->Char[m_iChar].bL_HandEquipped = 1;
	}
	else
	{
		pSlot->Char[m_iChar].L_HandDigit = ItemTable[WEAPONS_START+(m_LHand.GetCurSel()-1)].ItemDigit;
		pSlot->Char[m_iChar].bL_HandEquipped = 1;
	}
}
//========================================================================================================
void CEquipEdit::OnCbnSelchangeComboEquipHead()
{
	if (m_Head.GetCurSel() == 0)
	{
		pSlot->Char[m_iChar].HeadDigit = 0;
		pSlot->Char[m_iChar].bHeadEquipped = 0;
		return;
	}

	pSlot->Char[m_iChar].HeadDigit = ItemTable[HEADGEAR_START+(m_Head.GetCurSel()-1)].ItemDigit;
	pSlot->Char[m_iChar].bHeadEquipped = 1;
}
//========================================================================================================
void CEquipEdit::OnCbnSelchangeComboEquipBody()
{
	if (m_Body.GetCurSel() == 0)
	{
		pSlot->Char[m_iChar].BodydDigit = 0;
		pSlot->Char[m_iChar].bBodyEquipped = 0;
		return;
	}

	pSlot->Char[m_iChar].BodydDigit = ItemTable[ARMOR_START+(m_Body.GetCurSel()-1)].ItemDigit;
	pSlot->Char[m_iChar].bBodyEquipped = 1;
}
//========================================================================================================
void CEquipEdit::OnCbnSelchangeComboEquipArms()
{
	if (m_Arms.GetCurSel() == 0)
	{
		pSlot->Char[m_iChar].ArmsDigit = 0;
		pSlot->Char[m_iChar].bArmsEquipped = 0;
		return;
	}

	pSlot->Char[m_iChar].ArmsDigit = ItemTable[ARMS_START+(m_Arms.GetCurSel()-1)].ItemDigit;
	pSlot->Char[m_iChar].bArmsEquipped = 1;
}
//========================================================================================================
