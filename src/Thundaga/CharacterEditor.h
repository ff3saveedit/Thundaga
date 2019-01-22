//========================================================================================================
#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "CharTabCtrl.h"
//========================================================================================================
class CCharacterEditor : public CPropertyPage
{
	DECLARE_DYNAMIC(CCharacterEditor)

public:
	int m_iChar;
	CStatic m_CharPic;
	CharTabCtrl m_Tabs;
	CCharacterEditor();
	virtual ~CCharacterEditor();
	enum { IDD = IDD_CHARACTER_EDIT };

protected:
	CBitmap m_ArcBMP;
	CBitmap m_RefiaBMP;
	CBitmap m_IngusBMP;
	CBitmap m_LunethBMP;
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()
};
//========================================================================================================