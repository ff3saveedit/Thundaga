//========================================================================================================
#pragma once
#include "afxcmn.h"
#include "afxwin.h"
//========================================================================================================
class CItemEditor : public CPropertyPage
{
	DECLARE_DYNAMIC(CItemEditor)

public:
	CButton m_Addbtn;
	CButton m_Delbtn;
	CListCtrl m_InvItems;
	CTreeCtrl m_ItemList;
	CImageList m_ImageList;
	CSpinButtonCtrl m_SpinQty;

public:
	CItemEditor();
	virtual ~CItemEditor();
	enum { IDD = IDD_ITEMS_EDITOR };
	afx_msg void OnBnClickedAddItem();
	afx_msg void OnBnClickedRemoveItem();
	afx_msg void OnTvnSelchangedInvItemList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedInventoryItems(NMHDR *pNMHDR, LRESULT *pResult);

protected:
	void UpdateItems();
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()
};
//========================================================================================================