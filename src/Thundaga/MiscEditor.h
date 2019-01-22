//========================================================================================================
#pragma once
#include "afxwin.h"
#include "afxcmn.h"
//========================================================================================================
class CMiscEditor : public CPropertyPage
{
	DECLARE_DYNAMIC(CMiscEditor)

public:
	CSpinButtonCtrl m_SpinHrs;
	CSpinButtonCtrl m_SpinMins;
	CSpinButtonCtrl m_SpinSecs;
	CSpinButtonCtrl m_GoldSpin;
	CSpinButtonCtrl m_WifiSpin;

public:
	CMiscEditor();
	virtual ~CMiscEditor();
	enum { IDD = IDD_MISC_EDITOR };
	afx_msg void OnEnKillfocusGoldEdit();
	afx_msg void OnEnKillfocusWifiEdit();
	afx_msg void OnEnKillfocusTimeHrsEdit();
	afx_msg void OnEnKillfocusTimeMinsEdit();
	afx_msg void OnEnKillfocusTimeSecsEdit();

protected:
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support;
};
//========================================================================================================