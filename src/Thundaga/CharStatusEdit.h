//========================================================================================================
#pragma once
#include "afxcmn.h"
#include "afxwin.h"
//========================================================================================================
class CStatusEdit : public CDialog
{
	DECLARE_DYNAMIC(CStatusEdit)

public:
	int m_iChar;
	CButton m_Toad;
	CButton m_Mini;
	CButton m_Blind;
	CButton m_Poison;
	CButton m_Silence;
	CButton m_Petrified;
	enum { IDD = IDD_CHAR_STATUS_EDIT };
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CStatusEdit(int iCharacter, CWnd* pParent = NULL);   // standard constructor
	virtual ~CStatusEdit();

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheckPetri();
public:
	afx_msg void OnBnClickedCheckToad();
public:
	afx_msg void OnBnClickedCheckSiln();
public:
	afx_msg void OnBnClickedCheckMini();
public:
	afx_msg void OnBnClickedCheckBlnd();
public:
	afx_msg void OnBnClickedCheckPsnd();
};
//========================================================================================================