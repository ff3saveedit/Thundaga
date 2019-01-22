//========================================================================================================
// ItemEditor.cpp : implementation file
//========================================================================================================
#include "stdafx.h"
#include "Digits.h"
#include "Thundaga.h"
#include "ItemEditor.h"
//========================================================================================================
IMPLEMENT_DYNAMIC(CItemEditor, CPropertyPage)
//========================================================================================================
CItemEditor::CItemEditor()
	: CPropertyPage(CItemEditor::IDD)
{

}
//========================================================================================================
CItemEditor::~CItemEditor()
{
}
//========================================================================================================
void CItemEditor::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ADD_ITEM, m_Addbtn);
	DDX_Control(pDX, IDC_SPIN_QTY, m_SpinQty);
	DDX_Control(pDX, IDC_REMOVE_ITEM, m_Delbtn);
	DDX_Control(pDX, IDC_INV_ITEM_LIST, m_ItemList);
	DDX_Control(pDX, IDC_INVENTORY_ITEMS, m_InvItems);
}
//========================================================================================================
BOOL CItemEditor::OnInitDialog() 
{
	CBitmap bmp;
	int i = NULL;
	int dx = NULL;
	LVITEM lvItem;
	int iIndex = NULL;
	HTREEITEM trList[23];
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
	trList[0] = m_ItemList.InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM, "Items",		0, 0, 0, NULL, 0x7777, TVI_ROOT, TVI_LAST);
	trList[1] = m_ItemList.InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM, "White Magic",	1, 1, 0, NULL, 0x7777, TVI_ROOT, TVI_LAST);
	trList[2] = m_ItemList.InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM, "Black Magic",	2, 2, 0, NULL, 0x7777, TVI_ROOT, TVI_LAST);
	trList[3] = m_ItemList.InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM, "Summons",		3, 3, 0, NULL, 0x7777, TVI_ROOT, TVI_LAST);
	trList[4] = m_ItemList.InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM, "Knifes",		4, 4, 0, NULL, 0x7777, TVI_ROOT, TVI_LAST);
	trList[5] = m_ItemList.InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM, "Swords",		5, 5, 0, NULL, 0x7777, TVI_ROOT, TVI_LAST);
	trList[6] = m_ItemList.InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM, "Dark Swords",	6, 6, 0, NULL, 0x7777, TVI_ROOT, TVI_LAST);
	trList[7] = m_ItemList.InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM, "Staves",		7, 7, 0, NULL, 0x7777, TVI_ROOT, TVI_LAST);
	trList[8] = m_ItemList.InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM, "Rods",			8, 8, 0, NULL, 0x7777, TVI_ROOT, TVI_LAST);
	trList[9] = m_ItemList.InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM, "Bows",			9, 9, 0, NULL, 0x7777, TVI_ROOT, TVI_LAST);
	trList[10] = m_ItemList.InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM, "Arrows",		10, 10, 0, NULL, 0x7777, TVI_ROOT, TVI_LAST);
	trList[11] = m_ItemList.InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM, "Books",		11, 11, 0, NULL, 0x7777, TVI_ROOT, TVI_LAST);
	trList[12] = m_ItemList.InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM, "Claws",		12, 12, 0, NULL, 0x7777, TVI_ROOT, TVI_LAST);
	trList[13] = m_ItemList.InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM, "Hammers",		13, 13, 0, NULL, 0x7777, TVI_ROOT, TVI_LAST);
	trList[14] = m_ItemList.InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM, "Axes",		14, 14, 0, NULL, 0x7777, TVI_ROOT, TVI_LAST);
	trList[15] = m_ItemList.InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM, "Spears",		15, 15, 0, NULL, 0x7777, TVI_ROOT, TVI_LAST);
	trList[16] = m_ItemList.InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM, "Throwables",	16, 16, 0, NULL, 0x7777, TVI_ROOT, TVI_LAST);
	trList[17] = m_ItemList.InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM, "Bells",		17, 17, 0, NULL, 0x7777, TVI_ROOT, TVI_LAST);
	trList[18] = m_ItemList.InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM, "Harps",		18, 18, 0, NULL, 0x7777, TVI_ROOT, TVI_LAST);
	trList[19] = m_ItemList.InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM, "Shields",		19, 19, 0, NULL, 0x7777, TVI_ROOT, TVI_LAST);
	trList[20] = m_ItemList.InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM, "Headgear",	20, 20, 0, NULL, 0x7777, TVI_ROOT, TVI_LAST);
	trList[21] = m_ItemList.InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM, "Armor",		21, 21, 0, NULL, 0x7777, TVI_ROOT, TVI_LAST);
	trList[22] = m_ItemList.InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM, "Accessories", 22, 22, 0, NULL, 0x7777, TVI_ROOT, TVI_LAST);
	
	// A Simple table, so we can add all the items in a simple loop.
	sSimpleTable tblInfo[] = { 
		{ITEMS_START, ITEMS_SIZE},				{WHITE_MAGIC_START, WHITE_MAGIC_SIZE},	{BLACK_MAGIC_START, BLACK_MAGIC_SIZE}, 			
		{SUMMONS_START, SUMMONS_SIZE},			{KNIFES_START, KNIFES_SIZE},			{SWORDS_START, SWORDS_SIZE}, 
		{DARK_SWORDS_START, DARK_SWORDS_SIZE},	{STAVES_START, STAVES_SIZE},			{RODS_START, RODS_SIZE},
		{BOWS_START, BOWS_SIZE},				{ARROWS_START, ARROWS_SIZE},			{BOOKS_START, BOOKS_SIZE},
		{CLAWS_START, CLAWS_SIZE},				{HAMMERS_START, HAMMERS_SIZE},			{AXES_START, AXES_SIZE},
		{SPEARS_START, SPEARS_SIZE},			{THROWABLES_START, THROWABLES_SIZE},	{BELLS_START, BELLS_SIZE},
		{HARPS_START, HARPS_SIZE},				{SHIELDS_START, SHIELDS_SIZE},			{HEADGEAR_START, HEADGEAR_SIZE},
		{ARMOR_START, ARMOR_SIZE},				{ACCESSORIES_START, ACCESSORIES_SIZE} };
	
	// Loop through each Item Category, adding it to a the Category Tree.
	for (dx=0; dx<23; dx++)
	{
		i = NULL;
		TABLE_FOR(tblInfo[dx].iStart, tblInfo[dx].iSize)
		{
			m_ItemList.InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM, ItemTable[i].szDigitName, dx, dx, 0, 0, ItemTable[i].ItemDigit, trList[dx], TVI_LAST);
		}

	}

	// Set the ImageList + Columns for the Current Inventory
	m_InvItems.SetImageList(&m_ImageList, LVSIL_SMALL);
	m_InvItems.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_InvItems.InsertColumn(0, "Item", LVCFMT_LEFT, 120);
	m_InvItems.InsertColumn(1, "Qty", LVCFMT_LEFT, 35);


	// Load each item and set as Needed
	lvItem.iSubItem = 0;
	for (int i=0; i<324; i++)
	{
		iIndex = iGetIndexFromDigit(ItemTable, _countof(ItemTable), pSlot->Items[i].ItemDigit);
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
			sprintf_s(szQty, _countof(szQty), "%u", pSlot->Items[i].Quantity);
			m_InvItems.SetItem(i, 1, LVIF_TEXT, szQty, 0, 0, 0, 0);
		}
	}
	return TRUE;
}
//========================================================================================================
BEGIN_MESSAGE_MAP(CItemEditor, CPropertyPage)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_INVENTORY_ITEMS, &CItemEditor::OnLvnItemchangedInventoryItems)
	ON_NOTIFY(TVN_SELCHANGED, IDC_INV_ITEM_LIST, &CItemEditor::OnTvnSelchangedInvItemList)
	ON_BN_CLICKED(IDC_ADD_ITEM, &CItemEditor::OnBnClickedAddItem)
	ON_BN_CLICKED(IDC_REMOVE_ITEM, &CItemEditor::OnBnClickedRemoveItem)
END_MESSAGE_MAP()
//========================================================================================================
// Used to stop Changing Messages triggering themselves.
extern bool bNoUpdate;
//========================================================================================================
// All Credits go to Qhimm (www.qhimm.com) from "Jenova - A Final Fantasy 7 Save Editor"
// Thanks!
//========================================================================================================
void CItemEditor::OnLvnItemchangedInventoryItems(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	
	// Skip
	if (bNoUpdate)
	{
		*pResult = 0;
		return;
	}

	int i;
	HTREEITEM itmCurrent, itmLast, itmTypes[23];

	// Get the First Item
	itmTypes[0] = m_ItemList.GetRootItem();

	// Get all the Category's
	for (i=1; i<23; i++)
	{
		itmTypes[i] = m_ItemList.GetNextSiblingItem(itmTypes[i-1]);
	}

	// Loop through each category, and search for the desired Item.
	for (i=0; i<23; i++)
	{
		itmCurrent = m_ItemList.GetChildItem(itmTypes[i]);
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
	}

	bNoUpdate = TRUE;
	m_ItemList.SelectItem(NULL);
	bNoUpdate = FALSE;
	*pResult = 0;
}
//========================================================================================================
void CItemEditor::OnTvnSelchangedInvItemList(NMHDR *pNMHDR, LRESULT *pResult)
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
	for (i=0; i<324; i++)
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
void CItemEditor::UpdateItems()
{
	int i = NULL;
	char szQty[32] = {0};

	for (i=0; i<324; i++)
	{
		// Get Item Digit
		pSlot->Items[i].ItemDigit = m_InvItems.GetItemData(i);

		// Get Quantity
		m_InvItems.GetItemText(i, 1, szQty, _countof(szQty));
		pSlot->Items[i].Quantity = strtoul(szQty, NULL, NULL);
	}
}
//========================================================================================================
void CItemEditor::OnBnClickedAddItem()
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
	for (i=0; i<324; i++)
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
void CItemEditor::OnBnClickedRemoveItem()
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
	for (i=0; i<324; i++)
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