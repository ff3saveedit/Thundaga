//========================================================================================================
// ItemEditor.cpp : implementation file
//========================================================================================================
#include "stdafx.h"
#include "Digits.h"
#include "Thundaga.h"
#include "KeyItemEditor.h"
//========================================================================================================
IMPLEMENT_DYNAMIC(CKeyItemEditor, CPropertyPage)
//========================================================================================================
CKeyItemEditor::CKeyItemEditor()
	: CPropertyPage(CKeyItemEditor::IDD)
{

}
//========================================================================================================
CKeyItemEditor::~CKeyItemEditor()
{
}
//========================================================================================================
void CKeyItemEditor::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ADD_ITEM, m_Addbtn);
	DDX_Control(pDX, IDC_SPIN_QTY, m_SpinQty);
	DDX_Control(pDX, IDC_REMOVE_ITEM, m_Delbtn);
	DDX_Control(pDX, IDC_INV_ITEM_LIST, m_ItemList);
	DDX_Control(pDX, IDC_INVENTORY_ITEMS, m_InvItems);
}
//========================================================================================================
BOOL CKeyItemEditor::OnInitDialog() 
{
	CBitmap bmp;
	int i = NULL;
	int dx = NULL;
	LVITEM lvItem;
	HTREEITEM tRoot;
	int iIndex = NULL;
	char szQty[32] = {0};
	CPropertyPage::OnInitDialog();

	m_SpinQty.SetRange(1, 99);
	m_SpinQty.SetPos(1);

	// Load the "Item" bitmap, and create a ImageList
	bmp.LoadBitmap(IDB_ITEMS);
	m_ImageList.Create(18,20,ILC_COLOR16 | ILC_MASK,0,20);
	m_ImageList.Add(&bmp,RGB(255,0,255));
	bmp.DeleteObject();

	// Using the ImageList we just created.
	m_ItemList.SetImageList(&m_ImageList, TVSIL_NORMAL);

	// The Category's we want.
	tRoot = m_ItemList.InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM, "Key Items", 0, 0, 0, NULL, 0x7777, TVI_ROOT, TVI_LAST);
	
	// Loop through each Item Category, adding it to a the Category Tree.
	TABLE_FOR(KEY_ITEMS_START, KEY_ITEMS_SIZE)
	{
		m_ItemList.InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM, ItemTable[i].szDigitName, dx, dx, 0, 0, ItemTable[i].ItemDigit, tRoot, TVI_LAST);
	}

	// Set the ImageList + Columns for the Current Inventory
	m_InvItems.SetImageList(&m_ImageList, LVSIL_SMALL);
	m_InvItems.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_InvItems.InsertColumn(0, "Item", LVCFMT_LEFT, 120);
	m_InvItems.InsertColumn(1, "Qty", LVCFMT_LEFT, 35);


	// Load each item and set as Needed
	lvItem.iSubItem = 0;
	for (int i=0; i<64; i++)
	{
		iIndex = iGetIndexFromDigit(ItemTable, _countof(ItemTable), pSlot->KeyItems[i].ItemDigit);
		if (iIndex == -1)
		{
			// Not a Known Item, so Set as a Empty Slot
			lvItem.iItem = i;
			lvItem.mask = LVIF_TEXT | LVIF_PARAM | LVIF_IMAGE;
			lvItem.pszText = "";
			lvItem.iImage = IMAGE_NONE;
			lvItem.lParam = 0xFFFF;
			m_InvItems.InsertItem(&lvItem);
			m_InvItems.SetItem(i, 1, LVIF_TEXT, "", 0, 0, 0, 0);
		}
		else
		{
			// Known Item
			lvItem.iItem = i;
			lvItem.mask = LVIF_TEXT | LVIF_PARAM | LVIF_IMAGE;
			lvItem.pszText = ItemTable[iIndex].szDigitName;
			lvItem.iImage = ItemTable[iIndex].Picture;
			lvItem.lParam = ItemTable[iIndex].ItemDigit;
			m_InvItems.InsertItem(&lvItem);
			sprintf_s(szQty, _countof(szQty), "%u", pSlot->KeyItems[i].Quantity);
			m_InvItems.SetItem(i, 1, LVIF_TEXT, szQty, 0, 0, 0, 0);
		}
	}
	return TRUE;
}
//========================================================================================================
BEGIN_MESSAGE_MAP(CKeyItemEditor, CPropertyPage)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_INVENTORY_ITEMS, &CKeyItemEditor::OnLvnItemchangedInventoryItems)
	ON_NOTIFY(TVN_SELCHANGED, IDC_INV_ITEM_LIST, &CKeyItemEditor::OnTvnSelchangedInvItemList)
	ON_BN_CLICKED(IDC_ADD_ITEM, &CKeyItemEditor::OnBnClickedAddItem)
	ON_BN_CLICKED(IDC_REMOVE_ITEM, &CKeyItemEditor::OnBnClickedRemoveItem)
END_MESSAGE_MAP()
//========================================================================================================
// Used to stop Changing Messages triggering themselves.
bool bNoUpdate = FALSE;
//========================================================================================================
// All Credits go to Qhimm (www.qhimm.com) from "Jenova - A Final Fantasy 7 Save Editor"
//========================================================================================================
void CKeyItemEditor::OnLvnItemchangedInventoryItems(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	
	// Skip
	if (bNoUpdate)
	{
		*pResult = 0;
		return;
	}

	HTREEITEM itmCurrent, itmLast, itmRoot;

	// Get the First Item
	itmRoot = m_ItemList.GetRootItem();

	// Loop through each category, and search for the desired Item.
	itmCurrent = m_ItemList.GetChildItem(itmRoot);
	while (itmCurrent != NULL)
	{
		if (m_ItemList.GetItemData(itmCurrent) == (ULONG)pNMLV->lParam)
		{
			bNoUpdate = TRUE;
			m_ItemList.SelectItem(itmCurrent);
			m_ItemList.EnsureVisible(itmCurrent);
			bNoUpdate = FALSE;
			m_Addbtn.EnableWindow(TRUE);
			m_Delbtn.EnableWindow(TRUE);
			*pResult = 0;
			return;
		}
		itmLast = itmCurrent;
		itmCurrent = m_ItemList.GetNextSiblingItem(itmLast);
	}

	bNoUpdate = TRUE;
	m_ItemList.SelectItem(NULL);
	bNoUpdate = FALSE;
	*pResult = 0;
}
//========================================================================================================
void CKeyItemEditor::OnTvnSelchangedInvItemList(NMHDR *pNMHDR, LRESULT *pResult)
{

	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	
	// Skip
	if (bNoUpdate)
	{
		*pResult = 0;
		return;
	}

	// Enable/Disable "Add/Remove" if Category head is Selected.
	if (pNMTreeView->itemNew.lParam == 0x7777)
	{
		m_Addbtn.EnableWindow(FALSE);
		m_Delbtn.EnableWindow(FALSE);
		*pResult = 0;
		return;
	}
	else
	{
		m_Addbtn.EnableWindow(TRUE);
		m_Delbtn.EnableWindow(TRUE);
	}

	int i;
	LVITEM lvItem;
	bool bFound = FALSE;

	// Don't Search Sub Items, and Retrieve the "lParam"
	lvItem.iSubItem = 0;
	lvItem.mask = LVIF_PARAM;
	

	// Search for the Item
	for (i=0; i<64; i++)
	{
		lvItem.iItem = i;
		m_InvItems.GetItem(&lvItem);
		if (lvItem.lParam == pNMTreeView->itemNew.lParam)
		{
			bFound = TRUE;
			break;
		}
	}

	// If we Found the Item, make it Selected
	if (bFound)
	{
		lvItem.stateMask = LVIS_SELECTED;
		lvItem.state = LVIS_SELECTED;
		lvItem.iSubItem = 0;
		lvItem.mask = LVIF_STATE;
		bNoUpdate = TRUE;
		m_InvItems.SetItem(&lvItem);
		m_InvItems.EnsureVisible(i, FALSE);
		bNoUpdate = FALSE;
	}
	*pResult = 0;
}
//========================================================================================================
void CKeyItemEditor::UpdateItems()
{
	int i = NULL;
	char szQty[32] = {0};

	for (i=0; i<64; i++)
	{
		// Get Item Digit
		pSlot->KeyItems[i].ItemDigit = m_InvItems.GetItemData(i);

		// Get Quantity
		m_InvItems.GetItemText(i, 1, szQty, _countof(szQty));
		pSlot->KeyItems[i].Quantity = strtoul(szQty, NULL, NULL);
	}
}
//========================================================================================================
void CKeyItemEditor::OnBnClickedAddItem()
{

	// Nothing Selected to Add
	if (m_ItemList.GetSelectedItem() == NULL)
		return;

	// Blah!
	int i = NULL;
	LVITEM lvItem;
	int iIndex = NULL;
	ULONG lData = NULL;
	bool bFound = FALSE;
	char szQty[32] = {0};
	int iEmptySlot = NULL;
	bool bEmptySlot = FALSE;
	int iQtyCur, iQtyAdd, iQtyTotal;
	iQtyCur = iQtyAdd = iQtyTotal = NULL;

	// Reset Structure
	memset(&lvItem, 0, sizeof(lvItem));

	// Get Needed Information
	iQtyAdd = m_SpinQty.GetPos();
	lData = (ULONG)m_ItemList.GetItemData(m_ItemList.GetSelectedItem());

	// Locate the item inside "Inventory List" if not, use the first Empty Slot found.
	lvItem.mask = LVIF_PARAM;
	for (i=0; i<64; i++)
	{
		lvItem.iItem = i;
		m_InvItems.GetItem(&lvItem);

		if (!bEmptySlot)
		{
			if (lvItem.lParam == 0xFFFF)
			{
				iEmptySlot = i;
				bEmptySlot = TRUE;
			}
		}
		if (lvItem.lParam == lData)
		{
			bFound = TRUE;
			break;
		}
	}

	// Found the Item
	if (bFound)
	{
		lvItem.mask = LVIF_TEXT;
		lvItem.iSubItem = 1;
		lvItem.pszText = szQty;
		lvItem.cchTextMax = _countof(szQty);
		m_InvItems.GetItem(&lvItem);
		iQtyCur = strtoul(szQty, NULL, NULL);	
	}

	// Not Found, But we have a Empty Slot
	else if (bEmptySlot)
	{
		iIndex = iGetIndexFromDigit(ItemTable, _countof(ItemTable), lData);
		if (iIndex == -1)
		{
			// Not a Known Digit (Program Error)
			MessageBox("Serious Error", "Error", MB_OK);
			return;
		}
		iQtyCur = 0;
		lvItem.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_STATE | LVIF_PARAM;
		lvItem.iItem = iEmptySlot;
		lvItem.iSubItem = 0;
		lvItem.lParam = lData;
		lvItem.pszText = ItemTable[iIndex].szDigitName;
		lvItem.iImage = ItemTable[iIndex].Picture;
		lvItem.stateMask = LVIS_SELECTED;
		lvItem.state = LVIS_SELECTED;
		bNoUpdate = TRUE;
		m_InvItems.SetItem(&lvItem);
		bNoUpdate = FALSE;
		i = iEmptySlot;
	}

	// No Empty Slots
	else
	{
		MessageBox("Item Inventory is full", "Error", MB_OK);
		return;
	}

	// Simple check to keep below 99
	if (iQtyCur+iQtyAdd > 99) 
		iQtyAdd = (99 - iQtyCur);

	// Format the Quantity into a String.
	sprintf_s(szQty, _countof(szQty), "%u", (iQtyCur+iQtyAdd));

	// Set the Quantity Item
	lvItem.iSubItem = 1;
	lvItem.mask = LVIF_TEXT;
	lvItem.pszText = szQty;
	bNoUpdate = TRUE;
	m_InvItems.SetItem(&lvItem);
	bNoUpdate = FALSE;	

	// Make it Selected
	lvItem.stateMask = LVIS_SELECTED;
	lvItem.state = LVIS_SELECTED;
	lvItem.iSubItem = 0;
	lvItem.mask = LVIF_STATE;
	bNoUpdate = TRUE;
	m_InvItems.SetItem(&lvItem);
	bNoUpdate = FALSE;
	m_InvItems.EnsureVisible(i, FALSE);

	// Update Save File
	UpdateItems();
}
//========================================================================================================
void CKeyItemEditor::OnBnClickedRemoveItem()
{
	// Nothing Selected to Remove
	if (m_ItemList.GetSelectedItem() == NULL)
		return;

	int i = NULL;
	LVITEM lvItem;
	ULONG lData = NULL;
	bool bFound = FALSE;
	char szQty[32] = {0};
	int iQtyCur, iQtyDel, iQtyTotal;
	iQtyCur = iQtyDel = iQtyTotal = NULL;

	// Reset Structure
	memset(&lvItem, 0, sizeof(lvItem));

	// Get Needed Information
	iQtyDel = m_SpinQty.GetPos();
	lData = (ULONG)m_ItemList.GetItemData(m_ItemList.GetSelectedItem());

	// Locate the Item inside "Inventory List" if not, use the first Empty Slot found.
	lvItem.mask = LVIF_PARAM;
	for (i=0; i<64; i++)
	{
		lvItem.iItem = i;
		m_InvItems.GetItem(&lvItem);
		if (lvItem.lParam == lData)
		{
			bFound = TRUE;
			break;
		}
	}

	// Found the Item, so it can be Deleted
	if (bFound)
	{

		// Get Current Quantity
		lvItem.mask = LVIF_TEXT;
		lvItem.iSubItem = 1;
		lvItem.pszText = szQty;
		lvItem.cchTextMax = _countof(szQty);
		m_InvItems.GetItem(&lvItem);
		iQtyCur = strtoul(szQty, NULL, NULL);

		// If its all Gone, Remove it!
		if((iQtyCur - iQtyDel) < 1)
		{
			lvItem.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM | LVIF_STATE;
			lvItem.iSubItem = 0;
			lvItem.lParam = 0xFFFF;
			lvItem.pszText = "";
			lvItem.iImage = IMAGE_NONE;
			lvItem.stateMask = LVIS_SELECTED;
			lvItem.state = LVIS_SELECTED;
			bNoUpdate = TRUE;
			m_InvItems.SetItem(&lvItem);
			m_InvItems.EnsureVisible(i, FALSE);
			lvItem.mask = LVIF_TEXT;
			lvItem.iSubItem = 1;
			lvItem.pszText = "";
			m_InvItems.SetItem(&lvItem);
			bNoUpdate = FALSE;
		}
		else
		{
			// Format Quantity String
			sprintf_s(szQty, _countof(szQty), "%u", (iQtyCur-iQtyDel));

			lvItem.mask = LVIF_TEXT;
			lvItem.iSubItem = 1;
			lvItem.pszText = szQty;
			lvItem.mask = LVIF_TEXT;
			bNoUpdate = TRUE;
			m_InvItems.SetItem(&lvItem);
			bNoUpdate = FALSE;

			lvItem.stateMask = LVIS_SELECTED;
			lvItem.state = LVIS_SELECTED;
			lvItem.iSubItem = 0;
			lvItem.mask = LVIF_STATE;
			bNoUpdate = TRUE;
			m_InvItems.SetItem(&lvItem);
			m_InvItems.EnsureVisible(i, FALSE);
			bNoUpdate = FALSE;
		}
	}

	// Update Save File
	UpdateItems();
}
//========================================================================================================