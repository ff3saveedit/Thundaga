//========================================================================================================
#pragma once
#include "afxcmn.h"
#include "afxwin.h"
//========================================================================================================
class CJobsEdit : public CDialog
{
	DECLARE_DYNAMIC(CJobsEdit)

public:
	int m_iChar;
	CEdit m_JobLv01;
	CEdit m_JobEx01;
	CEdit m_JobLv02;
	CEdit m_JobEx02;
	CEdit m_JobLv03;
	CEdit m_JobEx03;
	CEdit m_JobLv04;
	CEdit m_JobEx04;
	CEdit m_JobLv05;
	CEdit m_JobEx05;
	CEdit m_JobLv06;
	CEdit m_JobEx06;
	CEdit m_JobLv07;
	CEdit m_JobEx07;
	CEdit m_JobLv08;
	CEdit m_JobEx08;
	CEdit m_JobLv09;
	CEdit m_JobEx09;
	CEdit m_JobLv10;
	CEdit m_JobEx10;
	CEdit m_JobLv11;
	CEdit m_JobEx11;
	CEdit m_JobLv12;
	CEdit m_JobEx12;
	CEdit m_JobLv13;
	CEdit m_JobEx13;
	CEdit m_JobLv14;
	CEdit m_JobEx14;
	CEdit m_JobLv15;
	CEdit m_JobEx15;
	CEdit m_JobLv16;
	CEdit m_JobEx16;
	CEdit m_JobLv17;
	CEdit m_JobEx17;
	CEdit m_JobLv18;
	CEdit m_JobEx18;
	CEdit m_JobLv19;
	CEdit m_JobEx19;
	CEdit m_JobLv20;
	CEdit m_JobEx20;
	CEdit m_JobLv21;
	CEdit m_JobEx21;
	CEdit m_JobLv22;
	CEdit m_JobEx22;
	CEdit m_JobLv23;
	CEdit m_JobEx23;
	CComboBox m_JobList;
	enum { IDD = IDD_CHAR_JOBS_EDIT };
	afx_msg void EnKillfocusEditJobExp01();
	afx_msg void EnKillfocusEditJobLvl01();
	afx_msg void EnKillfocusEditJobExp02();
	afx_msg void EnKillfocusEditJobLvl02();
	afx_msg void EnKillfocusEditJobExp03();
	afx_msg void EnKillfocusEditJobLvl03();
	afx_msg void EnKillfocusEditJobExp04();
	afx_msg void EnKillfocusEditJobLvl04();
	afx_msg void EnKillfocusEditJobExp05();
	afx_msg void EnKillfocusEditJobLvl05();
	afx_msg void EnKillfocusEditJobExp06();
	afx_msg void EnKillfocusEditJobLvl06();
	afx_msg void EnKillfocusEditJobExp07();
	afx_msg void EnKillfocusEditJobLvl07();
	afx_msg void EnKillfocusEditJobExp08();
	afx_msg void EnKillfocusEditJobLvl08();
	afx_msg void EnKillfocusEditJobExp09();
	afx_msg void EnKillfocusEditJobLvl09();
	afx_msg void EnKillfocusEditJobExp10();
	afx_msg void EnKillfocusEditJobLvl10();
	afx_msg void EnKillfocusEditJobExp11();
	afx_msg void EnKillfocusEditJobLvl11();
	afx_msg void EnKillfocusEditJobExp12();
	afx_msg void EnKillfocusEditJobLvl12();
	afx_msg void EnKillfocusEditJobExp13();
	afx_msg void EnKillfocusEditJobLvl13();
	afx_msg void EnKillfocusEditJobExp14();
	afx_msg void EnKillfocusEditJobLvl14();
	afx_msg void EnKillfocusEditJobExp15();
	afx_msg void EnKillfocusEditJobLvl15();
	afx_msg void EnKillfocusEditJobExp16();
	afx_msg void EnKillfocusEditJobLvl16();
	afx_msg void EnKillfocusEditJobExp17();
	afx_msg void EnKillfocusEditJobLvl17();
	afx_msg void EnKillfocusEditJobExp18();
	afx_msg void EnKillfocusEditJobLvl18();
	afx_msg void EnKillfocusEditJobExp19();
	afx_msg void EnKillfocusEditJobLvl19();
	afx_msg void EnKillfocusEditJobExp20();
	afx_msg void EnKillfocusEditJobLvl20();
	afx_msg void EnKillfocusEditJobExp21();
	afx_msg void EnKillfocusEditJobLvl21();
	afx_msg void EnKillfocusEditJobExp22();
	afx_msg void EnKillfocusEditJobLvl22();
	afx_msg void EnKillfocusEditJobExp23();
	afx_msg void EnKillfocusEditJobLvl23();
	afx_msg void OnCbnSelchangeComboCurrentJob();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CJobsEdit(int iCharacter, CWnd* pParent = NULL);   // standard constructor
	virtual ~CJobsEdit();

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()
	
};
//========================================================================================================