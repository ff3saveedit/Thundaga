//========================================================================================================
#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "SaveMgr.h"
#include "Digits.h"
#include "FontStatic.h"
#include "FileStructure.h"
//========================================================================================================
class CThundagaDlg : public CDialog
{

public:
	CButton m_FixBtn;
	CButton m_OpenBtn;
	CButton m_EditBtn;
	CListCtrl m_SlotInfo;
	CFontStatic m_Gold;
	CFontStatic m_Playtime;
	CFontStatic m_SlotTitle;
	TCHAR m_szFile[MAX_PATH];
	enum { IDD = IDD_THUNDAGA_DIALOG };

public:
	void UpdateSlotInfo();
	afx_msg void OnBnClickedSlot1();
	afx_msg void OnBnClickedSlot2();
	afx_msg void OnBnClickedSlot3();
	afx_msg void OnBnClickedFixEdit();
	afx_msg void OnBnClickedOpenEdit();
	afx_msg void OnBnClickedStartEdit();
	CThundagaDlg(CWnd* pParent = NULL);
	sSaveSlot *SetSaveSlot(sSaveFile *pSaveFile, int iSlot);
	afx_msg void OnLvnItemchangingList(NMHDR *pNMHDR, LRESULT *pResult);

protected:
	HICON m_hIcon;
	afx_msg void OnPaint();
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void DoDataExchange(CDataExchange* pDX);
	DECLARE_MESSAGE_MAP()
};
//========================================================================================================