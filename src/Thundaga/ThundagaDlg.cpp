//========================================================================================================
// ThundagaDlg.cpp : implementation file
//========================================================================================================
#include "stdafx.h"
#include "Digits.h"
#include <stdlib.h>
#include "SaveMgr.h"
#include "Thundaga.h"
#include "MiscEditor.h"
#include "ItemEditor.h"
#include "ThundagaDlg.h"
#include "KeyItemEditor.h"
#include "FileStructure.h"
#include "ThundagaEditor.h"
#include "CharacterEditor.h"
#include "ChocoItemEditor.h"
//========================================================================================================
#ifdef _DEBUG
	#define new DEBUG_NEW
#endif
//========================================================================================================
CSaveMgr SaveMgr;
sSaveSlot *pSlot;
sSaveFile *pSaveFile;
//========================================================================================================
// CThundagaDlg dialog
//========================================================================================================
CThundagaDlg::CThundagaDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CThundagaDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINICON);
}
//========================================================================================================
void CThundagaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GILTOTAL, m_Gold);
	DDX_Control(pDX, IDC_OPEN_BTN, m_OpenBtn);
	DDX_Control(pDX, IDC_PLAYTIME, m_Playtime);
	DDX_Control(pDX, IDC_SLOTINFO, m_SlotInfo);
	DDX_Control(pDX, IDC_FIX_BTN, m_FixBtn);
	DDX_Control(pDX, IDC_START_EDIT_BTN, m_EditBtn);
	DDX_Control(pDX, IDC_SLOT_TITLE, m_SlotTitle);
}
//========================================================================================================
BEGIN_MESSAGE_MAP(CThundagaDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_CLOSE()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_OPEN_BTN, &CThundagaDlg::OnBnClickedOpenEdit)
	ON_BN_CLICKED(IDC_FIX_BTN, &CThundagaDlg::OnBnClickedFixEdit)
	ON_BN_CLICKED(IDC_START_EDIT_BTN, &CThundagaDlg::OnBnClickedStartEdit)
	ON_BN_CLICKED(IDC_BUTTON_SAVE_SLOT1, &CThundagaDlg::OnBnClickedSlot1)
	ON_BN_CLICKED(IDC_BUTTON_SAVE_SLOT2, &CThundagaDlg::OnBnClickedSlot2)
	ON_BN_CLICKED(IDC_BUTTON_SAVE_SLOT3, &CThundagaDlg::OnBnClickedSlot3)
	ON_NOTIFY(LVN_ITEMCHANGING, IDC_SLOTINFO, &CThundagaDlg::OnLvnItemchangingList)
END_MESSAGE_MAP()
//========================================================================================================
BOOL CThundagaDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// Reset Save Manager
	pSlot = NULL;
	pSaveFile = NULL;
	SaveMgr.bChanged = FALSE;
	SaveMgr.lpLoadedFile = NULL;

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// Disabled Unneeded Buttons
	GetDlgItem(IDC_FIX_BTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_START_EDIT_BTN)->EnableWindow(FALSE);

	// Set Needed Column's
	m_SlotInfo.InsertColumn(0, TEXT("Name"), LVCFMT_LEFT, 80);
	m_SlotInfo.InsertColumn(1, TEXT("Level"), LVCFMT_CENTER, 40);
	m_SlotInfo.InsertColumn(2, TEXT("Current Job"), LVCFMT_CENTER, 90);
	m_SlotInfo.InsertColumn(3, TEXT("Job Level"), LVCFMT_CENTER, 60);

	// Set Fonts
	m_Gold.SetFontStyle(FS_BOLD);
	m_Gold.m_dwColor = RGB(0,128,0);
	m_Playtime.SetFontStyle(FS_BOLD);
	m_Playtime.m_dwColor = RGB(0,128,0);
	m_SlotTitle.SetFontStyle(FS_BOLD);
	m_SlotTitle.m_dwColor = RGB(190,0,0);
	
	// Set a Blank Status Message, to initiate Open file
	m_Gold.SetWindowText(TEXT("Click \"Open File\""));
	m_Playtime.SetWindowText(TEXT("Then Choose a Save file to Begin."));

	// Disabled Fix Checksum + Editor Button Until needed
	m_FixBtn.EnableWindow(FALSE);
	m_EditBtn.EnableWindow(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}
//========================================================================================================
void CThundagaDlg::OnClose()
{
	if (SaveMgr.bChanged)
	{
		// They Clicked Cancel in the End
		if (SaveMgr.NotifyChanges(TRUE) == FALSE)
			return;
	}

	if (SaveMgr.lpLoadedFile)
		free(SaveMgr.lpLoadedFile);

	CDialog::OnClose();
}
//========================================================================================================
void CThundagaDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}
//========================================================================================================
HCURSOR CThundagaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
//========================================================================================================
// Make Slot Info Items Untouchable!
//========================================================================================================
void CThundagaDlg::OnLvnItemchangingList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = TRUE;
}
//========================================================================================================
// Clicked Open Save
//========================================================================================================
void CThundagaDlg::OnBnClickedOpenEdit()
{
	// Reset State
	m_SlotInfo.DeleteAllItems();
	m_FixBtn.EnableWindow(FALSE);
	m_EditBtn.EnableWindow(FALSE);

	if (SaveMgr.bChanged)
	{
		SaveMgr.NotifyChanges(FALSE);
	}

	pSlot = NULL;
	pSaveFile = NULL;
	if (SaveMgr.lpLoadedFile)
	{
		free(SaveMgr.lpLoadedFile);
		SaveMgr.lpLoadedFile = NULL;
	}

	OPENFILENAME ofn;
	ZeroMemory(m_szFile, sizeof(m_szFile));
	ZeroMemory(&ofn, sizeof(OPENFILENAME));
	
	ofn.lStructSize       = sizeof(OPENFILENAME);
	ofn.hwndOwner         = AfxGetMainWnd()->GetSafeHwnd();         
	ofn.lpstrFilter       = TEXT("g6 Save (*.0)\0*.0\0m3 Save (*.dat)\0*.dat\0DS-Xtreme Save (*.sav)\0*.sav\0Supercard Save (*.sav)\0*.sav\0Raw Save (*.sav)\0*.sav\0");
	ofn.lpstrFile         =	m_szFile;
	ofn.nMaxFile		  = sizeof(m_szFile);  
	ofn.lpstrTitle        = TEXT("Select a Final Fantasy 3 Save File");
	ofn.lpstrDefExt       = TEXT("0"); 
	ofn.Flags             = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY;
	
	if (GetOpenFileName(&ofn) != TRUE)
	{
		// Set a Blank Status Message, to initiate Open file
		m_Gold.SetWindowText(TEXT("Click \"Open File\""));
		m_Playtime.SetWindowText(TEXT("Then Chosoe a Save file to Begin."));
		MessageBox(TEXT("Unable to Open A Save File"), TEXT("Error"), MB_OK);
		return;
	}

	if (ofn.nFilterIndex == 3)
	{
		if (SaveMgr.bLoadDsXFile(m_szFile) == FALSE)
		{
			// Set a Blank Status Message, to initiate Open file
			m_Gold.SetWindowText(TEXT("Click \"Open File\""));
			m_Playtime.SetWindowText(TEXT("Then Choose a Save file to Begin."));
			return;
		}		
	}
	else
	{
		// If its a m3 Save Originally Copy its Header
		if (ofn.nFilterIndex == 2) // m3 *.dat
			SaveMgr.bSaveM3 = TRUE;
		else
			SaveMgr.bSaveM3 = FALSE;

		if (SaveMgr.bLoadSaveFile(m_szFile) == FALSE)
		{
			// Set a Blank Status Message, to initiate Open file
			m_Gold.SetWindowText(TEXT("Click \"Open File\""));
			m_Playtime.SetWindowText(TEXT("Then Choose a Save file to Begin."));
			return;
		}
	}

	// Enable Slot 1 By Default
	pSlot = SetSaveSlot((sSaveFile *)SaveMgr.lpLoadedFile, 1);

	// Enable Editor Button + Slot 1
	m_EditBtn.EnableWindow(TRUE);
	::SendMessage(::GetDlgItem(GetSafeHwnd(),IDC_BUTTON_SAVE_SLOT1), BM_CLICK, TRUE, 0);
	
}
//========================================================================================================
// Clicked Start Editing
//========================================================================================================
void CThundagaDlg::OnBnClickedStartEdit()
{
	if (!SaveMgr.lpLoadedFile)
		return;

	if (!pSlot)
		return;

	// Other Editors
	CMiscEditor MiscEdit;
	CItemEditor ItemEdit;
	CThundagaEditor EditDlg;
	CKeyItemEditor KeyItemEdit;
	CChocoItemEditor ChocoItemEdit;
	
	// Character Editors
	SaveMgr.iCurrent = 0;
	CCharacterEditor Character1;
	SaveMgr.iCurrent = 1;
	CCharacterEditor Character2;
	SaveMgr.iCurrent = 2;
	CCharacterEditor Character3;
	SaveMgr.iCurrent = 3;
	CCharacterEditor Character4;

	// Set Needed Flags (Hide Help + Apply) + (Titles)

	EditDlg.m_psh.dwFlags &= ~PSH_HASHELP;
	EditDlg.m_psh.dwFlags |= PSH_NOAPPLYNOW;
	ItemEdit.m_psp.dwFlags &= ~PSP_HASHELP;
	ItemEdit.m_psp.dwFlags |= PSP_USETITLE;
	KeyItemEdit.m_psp.dwFlags &= ~PSP_HASHELP;
	KeyItemEdit.m_psp.dwFlags |= PSP_USETITLE;
	ChocoItemEdit.m_psp.dwFlags &= ~PSP_HASHELP;
	ChocoItemEdit.m_psp.dwFlags |= PSP_USETITLE;
	MiscEdit.m_psp.dwFlags &= ~PSP_HASHELP;
	MiscEdit.m_psp.dwFlags |= PSP_USETITLE;
	Character1.m_psp.dwFlags &= ~PSP_HASHELP;
	Character1.m_psp.dwFlags |= PSP_USETITLE;
	Character2.m_psp.dwFlags &= ~PSP_HASHELP;
	Character2.m_psp.dwFlags |= PSP_USETITLE;
	Character3.m_psp.dwFlags &= ~PSP_HASHELP;
	Character3.m_psp.dwFlags |= PSP_USETITLE;
	Character4.m_psp.dwFlags &= ~PSP_HASHELP;
	Character4.m_psp.dwFlags |= PSP_USETITLE;

	// Set Other Titles
	ItemEdit.m_psp.pszTitle =		"Inventory Items";
	KeyItemEdit.m_psp.pszTitle =	"Key Items";
	ChocoItemEdit.m_psp.pszTitle =	"Fat Chocobo Storage";
	MiscEdit.m_psp.pszTitle =		"Miscellaneous";

	// Set Titles Based on Character Names
	Character1.m_psp.pszTitle = pSlot->Char[Character1.m_iChar].Name;
	Character2.m_psp.pszTitle = pSlot->Char[Character2.m_iChar].Name;
	Character3.m_psp.pszTitle = pSlot->Char[Character3.m_iChar].Name;
	Character4.m_psp.pszTitle = pSlot->Char[Character4.m_iChar].Name;

	EditDlg.AddPage(&Character1);
	EditDlg.AddPage(&Character2);
	EditDlg.AddPage(&Character3);
	EditDlg.AddPage(&Character4);
	EditDlg.AddPage(&ItemEdit);
	EditDlg.AddPage(&KeyItemEdit);
	EditDlg.AddPage(&ChocoItemEdit);
	EditDlg.AddPage(&MiscEdit);
	EditDlg.DoModal();
	SaveMgr.bChanged = TRUE;
	pSlot->CheckSum = SaveMgr.GetCheckSum(pSlot->SaveHeader);
	UpdateSlotInfo();
}
//========================================================================================================
// Clicked Fix Checksum
//========================================================================================================
void CThundagaDlg::OnBnClickedFixEdit()
{
	SaveMgr.bChanged = TRUE;
	DWORD dwCheckSum = SaveMgr.GetCheckSum((byte *)&pSlot->SaveHeader);
	pSlot->CheckSum = (long)dwCheckSum;
	UpdateSlotInfo();
}
//========================================================================================================
sSaveSlot *CThundagaDlg::SetSaveSlot(sSaveFile *pSaveFile, int iSlot)
{
	switch(iSlot)
	{
	case 2:
		return &pSaveFile->Slot2;
		break;
	case 3:
		return &pSaveFile->Slot3;
	    break;
	default:
		return &pSaveFile->Slot1;
	    break;
	}
}
//========================================================================================================
void CThundagaDlg::UpdateSlotInfo()
{
	int i;
	sJobInfo *pJob;
	sCharacterBlock *pChar;
	char szLevel[32] = {0};
	char szGold[100] = {0};
	char szPlaytime[100] = {0};

	if (!pSlot)
		return;

	// Default Info
	m_SlotInfo.DeleteAllItems();
	m_FixBtn.EnableWindow(FALSE);
	m_EditBtn.EnableWindow(TRUE);
	
	// Empty Slot
	if (pSlot->CheckSum == 0 && pSlot->SaveHeader[0] == 0x0)
	{
		m_FixBtn.EnableWindow(FALSE);
		m_EditBtn.EnableWindow(FALSE);
		m_Gold.SetWindowText(TEXT(""));
		m_Playtime.SetWindowText(TEXT("<EMPTY SLOT>"));
		return;
	}

	// Bad Checksum
	if (pSlot->CheckSum != SaveMgr.GetCheckSum((byte *)&pSlot->SaveHeader))
	{
		m_FixBtn.EnableWindow(TRUE);
		m_EditBtn.EnableWindow(FALSE);
		m_Gold.SetWindowText(TEXT("Checksum Incorrect"));
		m_Playtime.SetWindowText(TEXT("Click \"Fix Checksum\" to Correct It."));
		return;
	}

	// Calculate Playtime + Gold
	sprintf_s(szPlaytime, _countof(szPlaytime), "Play Time: %02u:%02u:%02u",
		div((int)pSlot->PlayTime,3600).quot,
		div(div((int)pSlot->PlayTime,60).quot,60).rem,
		div((int)pSlot->PlayTime,60).rem);
	sprintf_s(szGold, _countof(szGold), "Total Gil: %d", pSlot->TotalGil);

	// Set Information
	m_Gold.SetWindowText(szGold);
	m_Playtime.SetWindowText(szPlaytime);

	// Display Character Information
	pChar = &pSlot->Char[0];
	for (i=0; i<4; i++)
	{
		pJob = pChar->Jobs;
		pJob += pChar->CurrentJob;
		m_SlotInfo.InsertItem(i, pChar->Name);
		sprintf_s(szLevel, _countof(szLevel), "%d", pChar->Level);
		m_SlotInfo.SetItem(i, 1, LVIF_TEXT, szLevel, 0, NULL, NULL, NULL);
		m_SlotInfo.SetItem(i, 2, LVIF_TEXT, JobTable[pChar->CurrentJob].szJobName, 0, NULL, NULL, NULL);
		sprintf_s(szLevel, _countof(szLevel), "%d", pJob->Level);
		m_SlotInfo.SetItem(i, 3, LVIF_TEXT, szLevel, 0, NULL, NULL, NULL);
		pChar++;
	}
}
//========================================================================================================
void CThundagaDlg::OnBnClickedSlot1()
{
	if (!SaveMgr.lpLoadedFile)
		return;

	pSlot = SetSaveSlot((sSaveFile *)SaveMgr.lpLoadedFile, 1);
	if (pSlot)
		UpdateSlotInfo();
}
//========================================================================================================
void CThundagaDlg::OnBnClickedSlot2()
{
	if (!SaveMgr.lpLoadedFile)
		return;

	pSlot = SetSaveSlot((sSaveFile *)SaveMgr.lpLoadedFile, 2);
	if (pSlot)
		UpdateSlotInfo();
}
//========================================================================================================
void CThundagaDlg::OnBnClickedSlot3()
{
	if (!SaveMgr.lpLoadedFile)
		return;

	pSlot = SetSaveSlot((sSaveFile *)SaveMgr.lpLoadedFile, 3);
	if (pSlot)
		UpdateSlotInfo();
}
//========================================================================================================