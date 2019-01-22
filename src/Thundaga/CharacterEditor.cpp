//========================================================================================================
// CharacterEditor.cpp : implementation file
//========================================================================================================
#include "stdafx.h"
#include "Digits.h"
#include "Thundaga.h"
#include "CharTabCtrl.h"
#include "FileStructure.h"
#include "CharacterEditor.h"
//========================================================================================================
IMPLEMENT_DYNAMIC(CCharacterEditor, CPropertyPage)
//========================================================================================================
CCharacterEditor::CCharacterEditor()
	: CPropertyPage(CCharacterEditor::IDD)
{
	// Load Bitmaps
	m_ArcBMP.LoadBitmap(IDB_ARC);
	m_RefiaBMP.LoadBitmap(IDB_REFIA);
	m_IngusBMP.LoadBitmap(IDB_INGUS);
	m_LunethBMP.LoadBitmap(IDB_LUNETH);
	m_iChar = SaveMgr.iCurrent;
}
//========================================================================================================
CCharacterEditor::~CCharacterEditor()
{
}
//========================================================================================================
void CCharacterEditor::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDITOR_TABS, m_Tabs);
	DDX_Control(pDX, IDC_CHAR_PICTURE, m_CharPic);
}
//========================================================================================================
BOOL CCharacterEditor::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	// Set Needed Tabs
	m_Tabs.InitDialogs();
	m_Tabs.InsertItem(0,"Main");
	m_Tabs.InsertItem(1,"Equipment");
	m_Tabs.InsertItem(2,"Magic");
	m_Tabs.InsertItem(3,"Jobs");
	m_Tabs.InsertItem(4,"Status");

	// Set Bitmaps Based on Character
	switch(pSlot->Char[m_iChar].Player)
	{
	case ARC:
		m_CharPic.SetBitmap(m_ArcBMP);
		break;
	case REFIA:
		m_CharPic.SetBitmap(m_RefiaBMP);
	    break;
	case INGUS:
		m_CharPic.SetBitmap(m_IngusBMP);
		break;
	default:
		m_CharPic.SetBitmap(m_LunethBMP);
	    break;
	}
	m_Tabs.ActivateTabDialogs();
	return TRUE;
}
//========================================================================================================
BEGIN_MESSAGE_MAP(CCharacterEditor, CPropertyPage)
END_MESSAGE_MAP()
//========================================================================================================
