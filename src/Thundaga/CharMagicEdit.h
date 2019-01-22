//========================================================================================================
#pragma once
#include "afxcmn.h"
#include "afxwin.h"
//========================================================================================================
class CMagicEdit : public CDialog
{
	DECLARE_DYNAMIC(CMagicEdit)

public:
	int m_iChar;
	CComboBox m_MagicLv1Slot1;
	CComboBox m_MagicLv1Slot2;
	CComboBox m_MagicLv1Slot3;
	CComboBox m_MagicLv2Slot1;
	CComboBox m_MagicLv2Slot2;
	CComboBox m_MagicLv2Slot3;
	CComboBox m_MagicLv3Slot1;
	CComboBox m_MagicLv3Slot2;
	CComboBox m_MagicLv3Slot3;
	CComboBox m_MagicLv4Slot1;
	CComboBox m_MagicLv4Slot2;
	CComboBox m_MagicLv4Slot3;
	CComboBox m_MagicLv5Slot1;
	CComboBox m_MagicLv5Slot2;
	CComboBox m_MagicLv5Slot3;
	CComboBox m_MagicLv6Slot1;
	CComboBox m_MagicLv6Slot2;
	CComboBox m_MagicLv6Slot3;
	CComboBox m_MagicLv7Slot1;
	CComboBox m_MagicLv7Slot2;
	CComboBox m_MagicLv7Slot3;
	CComboBox m_MagicLv8Slot1;
	CComboBox m_MagicLv8Slot2;
	CComboBox m_MagicLv8Slot3;
	afx_msg void UpdateMagicSlot();
	enum { IDD = IDD_CHAR_MAGIC_EDIT };
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CMagicEdit(int iCharacter, CWnd* pParent = NULL);   // standard constructor
	virtual ~CMagicEdit();

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()
};
//========================================================================================================
