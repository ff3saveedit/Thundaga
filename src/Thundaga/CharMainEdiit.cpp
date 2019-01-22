//========================================================================================================
// CharMainEdit.cpp : implementation file
//========================================================================================================
#include "stdafx.h"
#include "Digits.h"
#include "Thundaga.h"
#include "CharMainEdit.h"
//========================================================================================================
IMPLEMENT_DYNAMIC(CMainEdit, CDialog)
//========================================================================================================
CMainEdit::CMainEdit(int iCharacter, CWnd* pParent /*=NULL*/)
	: CDialog(CMainEdit::IDD, pParent)
{
	m_iChar = iCharacter;
}
//========================================================================================================
CMainEdit::~CMainEdit()
{
}
//========================================================================================================
void CMainEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_EXP, m_CharExp);
	DDX_Control(pDX, IDC_SPIN_LEVEL, m_SpinLvl);
	DDX_Control(pDX, IDC_SPIN_CURHP, m_SpinCurHp);
	DDX_Control(pDX, IDC_SPIN_MAXHP, m_SpinMaxHp);
	DDX_Control(pDX, IDC_EDIT_NAME, m_szCharName);
	DDX_Control(pDX, IDC_SPIN_JOB_PEN, m_SpinPen);
	DDX_Control(pDX, IDC_CHECK_CHAR_ENABLED, m_CharEnabled);
}
//========================================================================================================
BOOL CMainEdit::OnInitDialog()
{
	char szName[64] = {0};
	char szExperience[64] = {0};
	CDialog::OnInitDialog();

	sprintf_s(szName, _countof(szName), "%s", pSlot->Char[m_iChar].Name);
	sprintf_s(szExperience, _countof(szExperience), "%d", pSlot->Char[m_iChar].Experience);

	m_SpinPen.SetRange(0, 99);
	m_SpinPen.SetPos(pSlot->Char[m_iChar].Battle_Transition);

	m_CharExp.SetLimitText(7);
	m_szCharName.SetLimitText(8);

	m_SpinLvl.SetRange(0, 99);
	m_SpinCurHp.SetRange(0, 9999);
	m_SpinMaxHp.SetRange(1, 9999);
	
	m_SpinLvl.SetPos(pSlot->Char[m_iChar].Level);
	m_SpinCurHp.SetPos(pSlot->Char[m_iChar].CurrentHP);
	m_SpinMaxHp.SetPos(pSlot->Char[m_iChar].MaximumHP);

	m_szCharName.SetWindowText(szName);
	m_CharExp.SetWindowText(szExperience);

	m_CharEnabled.SetCheck(pSlot->Char[m_iChar].bEnabled);

	return TRUE;
}
//========================================================================================================
BOOL CMainEdit::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
			pMsg->wParam = NULL;
	} 
	return CDialog::PreTranslateMessage(pMsg);
}
//========================================================================================================
BEGIN_MESSAGE_MAP(CMainEdit, CDialog)
	ON_EN_KILLFOCUS(IDC_EDIT_EXP, &CMainEdit::EnKillfocusEditExp)
	ON_EN_KILLFOCUS(IDC_EDIT_NAME, &CMainEdit::EnKillfocusEditName)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_PEN, &CMainEdit::EnKillfocusEditJobPen)
	ON_EN_KILLFOCUS(IDC_EDIT_LEVEL, &CMainEdit::OnEnKillfocusEditLevel)
	ON_EN_KILLFOCUS(IDC_EDIT_CURHP, &CMainEdit::OnEnKillfocusEditCurhp)
	ON_EN_KILLFOCUS(IDC_EDIT_MAXHP, &CMainEdit::OnEnKillfocusEditMaxhp)
	ON_BN_CLICKED(IDC_CHECK_CHAR_ENABLED, &CMainEdit::OnBnClickedCheckCharEnabled)
END_MESSAGE_MAP()
//========================================================================================================
void CMainEdit::EnKillfocusEditName()
{
	char szName[32] = {0};
	if (m_szCharName.GetWindowTextLength() == 0)
	{
		MessageBox("Please Enter a Name.", "Name Information", MB_OK|MB_ICONEXCLAMATION);
		m_szCharName.SetFocus();
		return;
	}
	m_szCharName.GetWindowText(szName, 9);
	strcpy_s(pSlot->Char[m_iChar].Name, _countof(pSlot->Char[0].Name), szName);
}
//========================================================================================================
void CMainEdit::EnKillfocusEditExp()
{

	char szExperience[32] = {0};
	if (m_CharExp.GetWindowTextLength() == 0)
	{
		MessageBox("Please Enter a Number", "Experience Information", MB_OK|MB_ICONEXCLAMATION);
		m_szCharName.SetFocus();
		return;
	}
	m_CharExp.GetWindowText(szExperience, 8);
	pSlot->Char[m_iChar].Experience = strtoul(szExperience, NULL, NULL);
}
//========================================================================================================
void CMainEdit::EnKillfocusEditJobPen()
{
	pSlot->Char[m_iChar].Battle_Transition = m_SpinPen.GetPos();
}
//========================================================================================================
void CMainEdit::OnBnClickedCheckCharEnabled()
{
	pSlot->Char[m_iChar].bEnabled = m_CharEnabled.GetCheck();
}
//========================================================================================================
void CMainEdit::OnEnKillfocusEditLevel()
{
	pSlot->Char[m_iChar].Level = m_SpinLvl.GetPos();
}
//========================================================================================================
void CMainEdit::OnEnKillfocusEditCurhp()
{
	pSlot->Char[m_iChar].CurrentHP = m_SpinCurHp.GetPos();
}
//========================================================================================================
void CMainEdit::OnEnKillfocusEditMaxhp()
{
	pSlot->Char[m_iChar].MaximumHP = m_SpinMaxHp.GetPos();
}
//========================================================================================================