//========================================================================================================
// CharTabCtrl.cpp : implementation file
// Written By: ?? (Found on Google -_-)
//========================================================================================================
#include "stdafx.h"
#include "resource.h"
#include "SaveMgr.h"
#include "ThundagaDlg.h"
#include "CharTabCtrl.h"
#include "CharMainEdit.h"
#include "CharJobsEdit.h"
#include "CharEquipEdit.h"
#include "CharMagicEdit.h"
#include "CharStatusEdit.h"
//========================================================================================================
#ifdef _DEBUG
	#define new DEBUG_NEW
#endif
//========================================================================================================
CharTabCtrl::CharTabCtrl()
{
	iChar = SaveMgr.iCurrent;
	m_DialogID[0] = IDD_CHAR_MAIN_EDIT;
	m_DialogID[1] = IDD_CHAR_EQUIP_EDIT;
	m_DialogID[2] = IDD_CHAR_MAGIC_EDIT;
	m_DialogID[3] = IDD_CHAR_JOBS_EDIT;
	m_DialogID[4] = IDD_CHAR_STATUS_EDIT;

	m_Dialog[0] = new CMainEdit(iChar);
	m_Dialog[1] = new CEquipEdit(iChar);
	m_Dialog[2] = new CMagicEdit(iChar);
	m_Dialog[3] = new CJobsEdit(iChar);
	m_Dialog[4] = new CStatusEdit(iChar);

	m_nPageCount = 5;
}
//========================================================================================================
CharTabCtrl::~CharTabCtrl()
{
	delete m_Dialog[0];
	delete m_Dialog[1];
	delete m_Dialog[2];
	delete m_Dialog[3];
	delete m_Dialog[4];
}
//========================================================================================================
void CharTabCtrl::InitDialogs()
{
	// Create Tabs
	m_Dialog[0]->Create(m_DialogID[0],GetParent());
	m_Dialog[1]->Create(m_DialogID[1],GetParent());
	m_Dialog[2]->Create(m_DialogID[2],GetParent());
	m_Dialog[3]->Create(m_DialogID[3],GetParent());
	m_Dialog[4]->Create(m_DialogID[4],GetParent());
}
//========================================================================================================
BEGIN_MESSAGE_MAP(CharTabCtrl, CTabCtrl)
	//{{AFX_MSG_MAP(MyTabCtrl)
	ON_NOTIFY_REFLECT(TCN_SELCHANGE, OnSelchange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
//========================================================================================================
void CharTabCtrl::OnSelchange(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	ActivateTabDialogs();
	*pResult = 0;
}
//========================================================================================================
void CharTabCtrl::ActivateTabDialogs()
{

	int nSel = GetCurSel();
	if (m_Dialog[nSel]->m_hWnd)
		m_Dialog[nSel]->ShowWindow(SW_HIDE);

	CRect l_rectClient;
	CRect l_rectWnd;

	GetClientRect(l_rectClient);
	AdjustRect(FALSE,l_rectClient);
	GetWindowRect(l_rectWnd);
	GetParent()->ScreenToClient(l_rectWnd);
	l_rectClient.OffsetRect(l_rectWnd.left,l_rectWnd.top);
	for (int nCount=0; nCount < m_nPageCount; nCount++){
		m_Dialog[nCount]->SetWindowPos(&wndTop, l_rectClient.left,l_rectClient.top,l_rectClient.Width(),l_rectClient.Height(),SWP_HIDEWINDOW);
	}
	m_Dialog[nSel]->SetWindowPos(&wndTop,l_rectClient.left,l_rectClient.top,l_rectClient.Width(),l_rectClient.Height(),SWP_SHOWWINDOW);

	m_Dialog[nSel]->ShowWindow(SW_SHOW);
}
//========================================================================================================
