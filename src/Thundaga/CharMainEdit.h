//========================================================================================================
#pragma once
#include "afxcmn.h"
#include "afxwin.h"
//========================================================================================================
class CMainEdit : public CDialog
{
	DECLARE_DYNAMIC(CMainEdit)

public:
	int m_iChar;
	
	CEdit m_CharExp;
	CEdit m_szCharName;
	CButton m_CharEnabled;
	CSpinButtonCtrl m_SpinPen;
	CSpinButtonCtrl m_SpinLvl;
	CSpinButtonCtrl m_SpinCurHp;
	CSpinButtonCtrl m_SpinMaxHp;
	enum { IDD = IDD_CHAR_MAIN_EDIT };
	afx_msg void EnKillfocusEditExp();
	afx_msg void EnKillfocusEditName();
	afx_msg void EnKillfocusEditJobPen();
	afx_msg void OnEnKillfocusEditLevel();
	afx_msg void OnEnKillfocusEditCurhp();
	afx_msg void OnEnKillfocusEditMaxhp();
	afx_msg void OnBnClickedCheckCharEnabled();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CMainEdit(int iCharacter, CWnd* pParent = NULL);   // standard constructor
	virtual ~CMainEdit();

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()
};
//========================================================================================================
