//========================================================================================================
#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "Digits.h"
//========================================================================================================
class CEquipEdit : public CDialog
{
	DECLARE_DYNAMIC(CEquipEdit)

public:
	int m_iChar;
	CComboBox m_Head;
	CComboBox m_Body;
	CComboBox m_Arms;
	CComboBox m_RHand;
	CComboBox m_LHand;
	enum { IDD = IDD_CHAR_EQUIP_EDIT };
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnCbnSelchangeComboEquipHead();
	afx_msg void OnCbnSelchangeComboEquipBody();
	afx_msg void OnCbnSelchangeComboEquipArms();
	afx_msg void OnCbnSelchangeComboEquipRhand();
	afx_msg void OnCbnSelchangeComboEquipLhand();
	CEquipEdit(int iCharacter, CWnd* pParent = NULL);   // standard constructor
	virtual ~CEquipEdit();

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()
};
//========================================================================================================