//========================================================================================================
#pragma once
#include "afxcmn.h"
#include "afxwin.h"
//========================================================================================================
class CharTabCtrl : public CTabCtrl
{

public:
	int iChar;
	int m_nPageCount;
	int m_DialogID[5];
	CDialog *m_Dialog[5];

public:
	CharTabCtrl();
	void InitDialogs();
	void ActivateTabDialogs();
	virtual ~CharTabCtrl();

protected:
	afx_msg void OnSelchange(NMHDR* pNMHDR, LRESULT* pResult);
	DECLARE_MESSAGE_MAP()
};
//========================================================================================================