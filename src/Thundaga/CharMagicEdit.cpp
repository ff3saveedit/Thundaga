//========================================================================================================
// CharMagicEdit.cpp : implementation file
//========================================================================================================
#include "stdafx.h"
#include "Digits.h"
#include "Thundaga.h"
#include "CharMagicEdit.h"
//========================================================================================================
IMPLEMENT_DYNAMIC(CMagicEdit, CDialog)
//========================================================================================================
CMagicEdit::CMagicEdit(int iCharacter, CWnd* pParent /*=NULL*/)
	: CDialog(CMagicEdit::IDD, pParent)
{
	m_iChar = iCharacter;
}
//========================================================================================================
CMagicEdit::~CMagicEdit()
{
}
//========================================================================================================
void CMagicEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_MAGIC_LV1_SLOT1, m_MagicLv1Slot1);
	DDX_Control(pDX, IDC_COMBO_MAGIC_LV1_SLOT2, m_MagicLv1Slot2);
	DDX_Control(pDX, IDC_COMBO_MAGIC_LV1_SLOT3, m_MagicLv1Slot3);
	DDX_Control(pDX, IDC_COMBO_MAGIC_LV2_SLOT1, m_MagicLv2Slot1);
	DDX_Control(pDX, IDC_COMBO_MAGIC_LV2_SLOT2, m_MagicLv2Slot2);
	DDX_Control(pDX, IDC_COMBO_MAGIC_LV2_SLOT3, m_MagicLv2Slot3);
	DDX_Control(pDX, IDC_COMBO_MAGIC_LV3_SLOT1, m_MagicLv3Slot1);
	DDX_Control(pDX, IDC_COMBO_MAGIC_LV3_SLOT2, m_MagicLv3Slot2);
	DDX_Control(pDX, IDC_COMBO_MAGIC_LV3_SLOT3, m_MagicLv3Slot3);
	DDX_Control(pDX, IDC_COMBO_MAGIC_LV4_SLOT1, m_MagicLv4Slot1);
	DDX_Control(pDX, IDC_COMBO_MAGIC_LV4_SLOT2, m_MagicLv4Slot2);
	DDX_Control(pDX, IDC_COMBO_MAGIC_LV4_SLOT3, m_MagicLv4Slot3);
	DDX_Control(pDX, IDC_COMBO_MAGIC_LV5_SLOT1, m_MagicLv5Slot1);
	DDX_Control(pDX, IDC_COMBO_MAGIC_LV5_SLOT2, m_MagicLv5Slot2);
	DDX_Control(pDX, IDC_COMBO_MAGIC_LV5_SLOT3, m_MagicLv5Slot3);
	DDX_Control(pDX, IDC_COMBO_MAGIC_LV6_SLOT1, m_MagicLv6Slot1);
	DDX_Control(pDX, IDC_COMBO_MAGIC_LV6_SLOT2, m_MagicLv6Slot2);
	DDX_Control(pDX, IDC_COMBO_MAGIC_LV6_SLOT3, m_MagicLv6Slot3);
	DDX_Control(pDX, IDC_COMBO_MAGIC_LV7_SLOT1, m_MagicLv7Slot1);
	DDX_Control(pDX, IDC_COMBO_MAGIC_LV7_SLOT2, m_MagicLv7Slot2);
	DDX_Control(pDX, IDC_COMBO_MAGIC_LV7_SLOT3, m_MagicLv7Slot3);
	DDX_Control(pDX, IDC_COMBO_MAGIC_LV8_SLOT1, m_MagicLv8Slot1);
	DDX_Control(pDX, IDC_COMBO_MAGIC_LV8_SLOT2, m_MagicLv8Slot2);
	DDX_Control(pDX, IDC_COMBO_MAGIC_LV8_SLOT3, m_MagicLv8Slot3);
}
//========================================================================================================
#define TABLE(id) tblMagicLv ##id
#define CONTROL(id)  m_MagicLv ##id
#define MAGIC_LOOP(x)	{	\
			CONTROL(##x)Slot1.InsertString(0, "<EMPTY>"); \
			CONTROL(##x)Slot2.InsertString(0, "<EMPTY>"); \
			CONTROL(##x)Slot3.InsertString(0, "<EMPTY>"); \
			CONTROL(##x)Slot1.SetCurSel(0); \
			CONTROL(##x)Slot2.SetCurSel(0); \
			CONTROL(##x)Slot3.SetCurSel(0); \
			for (i=0; i<((ALL_MAGIC_SIZE*2)+1); i++)	{	  \
			CONTROL(##x)Slot1.InsertString(i+1, TABLE(##x)[i].szDigitName); 	\
			CONTROL(##x)Slot2.InsertString(i+1, TABLE(##x)[i].szDigitName); 	\
			CONTROL(##x)Slot3.InsertString(i+1, TABLE(##x)[i].szDigitName); };	\
}
//========================================================================================================
int iGetSlot(int iDigit, int *pOutIndex)
{
	int i;
	int iIndex = NULL;
	for (i=0; i<_countof(MagicTable); i++)
	{
		if (i % 7 == 0)
			iIndex = 0;

		if (MagicTable[i].ItemDigit == iDigit)
		{
			*pOutIndex = iIndex+1;
			return (i/7)+1;
		}
		iIndex++;
	}
	*pOutIndex = NULL;
	return -1;
}
//========================================================================================================
bool bInit = FALSE;
//========================================================================================================
BOOL CMagicEdit::OnInitDialog()
{
	int i;
	CDialog::OnInitDialog();
	sCharacterBlock *pChar = &pSlot->Char[m_iChar];
	CComboBox *pLevel1[] = { &m_MagicLv1Slot1, &m_MagicLv1Slot2, &m_MagicLv1Slot3};
	CComboBox *pLevel2[] = { &m_MagicLv2Slot1, &m_MagicLv2Slot2, &m_MagicLv2Slot3};
	CComboBox *pLevel3[] = { &m_MagicLv3Slot1, &m_MagicLv3Slot2, &m_MagicLv3Slot3};
	CComboBox *pLevel4[] = { &m_MagicLv4Slot1, &m_MagicLv4Slot2, &m_MagicLv4Slot3};
	CComboBox *pLevel5[] = { &m_MagicLv5Slot1, &m_MagicLv5Slot2, &m_MagicLv5Slot3};
	CComboBox *pLevel6[] = { &m_MagicLv6Slot1, &m_MagicLv6Slot2, &m_MagicLv6Slot3};
	CComboBox *pLevel7[] = { &m_MagicLv7Slot1, &m_MagicLv7Slot2, &m_MagicLv7Slot3};
	CComboBox *pLevel8[] = { &m_MagicLv8Slot1, &m_MagicLv8Slot2, &m_MagicLv8Slot3};
	void *pTable[] = { pLevel1, pLevel2, pLevel3, pLevel4, pLevel5, pLevel6, pLevel7, pLevel8 };


	bInit = TRUE;
	int dx = NULL;
	int iLevel = -1;
	DWORD *pCurrent;
	CComboBox *pCombo = NULL;
	for (i=0; i<8; i++)
	{
		pCurrent = (DWORD *)pTable[i];
		pCombo = (CComboBox *)pCurrent[0];
		pCombo->InsertString(0, "<EMPTY>");
		pCombo->SetCurSel(0);
		pCombo = (CComboBox *)pCurrent[1];
		pCombo->InsertString(0, "<EMPTY>");
		pCombo->SetCurSel(0);
		pCombo = (CComboBox *)pCurrent[2];
		pCombo->InsertString(0, "<EMPTY>");
		pCombo->SetCurSel(0);
	}

	for (i=1; i<(8*7)+1; i++)
	{	
		if (i % 7 == 1)
		{
			dx = 0;
			iLevel++;
		}

		pCurrent = (DWORD *)pTable[iLevel];
		pCombo = (CComboBox *)pCurrent[0];
		pCombo->InsertString(dx+1, MagicTable[i-1].szDigitName);
		pCombo = (CComboBox *)pCurrent[1];
		pCombo->InsertString(dx+1, MagicTable[i-1].szDigitName);
		pCombo = (CComboBox *)pCurrent[2];
		pCombo->InsertString(dx+1, MagicTable[i-1].szDigitName);
		dx++;
	}

	int iLevel1, iLevel2, iLevel3, iLevel4, iLevel5, iLevel6, iLevel7, iLevel8;
	iLevel1 = iLevel2 = iLevel3 = iLevel4 = iLevel5 = iLevel6 = iLevel7 = iLevel8 = NULL;

	int iSlot = NULL;
	int iIndex = NULL;	
	for (i=0; i<24; i++)
	{
		iSlot = iGetSlot(pChar->MagicSlots[i].ItemDigit, &iIndex);
		
		if (iSlot == -1)
			continue;

		switch(iSlot)
		{
		case 1:
			{
				if (iLevel1 < 3)
				{
					pLevel1[iLevel1]->SetCurSel(iIndex);
					iLevel1++;
				}
			}
			break;
		case 2:
			{
				if (iLevel2 < 3)
				{
					pLevel2[iLevel2]->SetCurSel(iIndex);
					iLevel2++;
				}
			}
			break;
		case 3:
			{
				if (iLevel3 < 3)
				{
					pLevel3[iLevel3]->SetCurSel(iIndex);
					iLevel3++;
				}
			}
			break;
		case 4:
			{
				if (iLevel4 < 3)
				{
					pLevel4[iLevel4]->SetCurSel(iIndex);
					iLevel4++;
				}
			}
			break;
		case 5:
			{
				if (iLevel5 < 3)
				{
					pLevel5[iLevel5]->SetCurSel(iIndex);
					iLevel5++;
				}
			}
			break;
		case 6:
			{
				if (iLevel6 < 3)
				{
					pLevel6[iLevel6]->SetCurSel(iIndex);
					iLevel6++;
				}
			}
			break;
		case 7:
			{
				if (iLevel7 < 3)
				{
					pLevel7[iLevel7]->SetCurSel(iIndex);
					iLevel7++;
				}
			}
			break;
		case 8:
			{
				if (iLevel8 < 3)
				{
					pLevel8[iLevel8]->SetCurSel(iIndex);
					iLevel8++;
				}
			}
			break;
		default:
		    break;
		}
	}
	bInit = FALSE;
	return TRUE;
}
//========================================================================================================
BEGIN_MESSAGE_MAP(CMagicEdit, CDialog)
	ON_CBN_SELCHANGE(IDC_COMBO_MAGIC_LV1_SLOT1, &CMagicEdit::UpdateMagicSlot)
	ON_CBN_SELCHANGE(IDC_COMBO_MAGIC_LV1_SLOT2, &CMagicEdit::UpdateMagicSlot)
	ON_CBN_SELCHANGE(IDC_COMBO_MAGIC_LV1_SLOT3, &CMagicEdit::UpdateMagicSlot)
	ON_CBN_SELCHANGE(IDC_COMBO_MAGIC_LV2_SLOT1, &CMagicEdit::UpdateMagicSlot)
	ON_CBN_SELCHANGE(IDC_COMBO_MAGIC_LV2_SLOT2, &CMagicEdit::UpdateMagicSlot)
	ON_CBN_SELCHANGE(IDC_COMBO_MAGIC_LV2_SLOT3, &CMagicEdit::UpdateMagicSlot)
	ON_CBN_SELCHANGE(IDC_COMBO_MAGIC_LV3_SLOT1, &CMagicEdit::UpdateMagicSlot)
	ON_CBN_SELCHANGE(IDC_COMBO_MAGIC_LV3_SLOT2, &CMagicEdit::UpdateMagicSlot)
	ON_CBN_SELCHANGE(IDC_COMBO_MAGIC_LV3_SLOT3, &CMagicEdit::UpdateMagicSlot)
	ON_CBN_SELCHANGE(IDC_COMBO_MAGIC_LV4_SLOT1, &CMagicEdit::UpdateMagicSlot)
	ON_CBN_SELCHANGE(IDC_COMBO_MAGIC_LV4_SLOT2, &CMagicEdit::UpdateMagicSlot)
	ON_CBN_SELCHANGE(IDC_COMBO_MAGIC_LV4_SLOT3, &CMagicEdit::UpdateMagicSlot)
	ON_CBN_SELCHANGE(IDC_COMBO_MAGIC_LV5_SLOT1, &CMagicEdit::UpdateMagicSlot)
	ON_CBN_SELCHANGE(IDC_COMBO_MAGIC_LV5_SLOT2, &CMagicEdit::UpdateMagicSlot)
	ON_CBN_SELCHANGE(IDC_COMBO_MAGIC_LV5_SLOT3, &CMagicEdit::UpdateMagicSlot)
	ON_CBN_SELCHANGE(IDC_COMBO_MAGIC_LV6_SLOT1, &CMagicEdit::UpdateMagicSlot)
	ON_CBN_SELCHANGE(IDC_COMBO_MAGIC_LV6_SLOT2, &CMagicEdit::UpdateMagicSlot)
	ON_CBN_SELCHANGE(IDC_COMBO_MAGIC_LV6_SLOT3, &CMagicEdit::UpdateMagicSlot)
	ON_CBN_SELCHANGE(IDC_COMBO_MAGIC_LV7_SLOT1, &CMagicEdit::UpdateMagicSlot)
	ON_CBN_SELCHANGE(IDC_COMBO_MAGIC_LV7_SLOT2, &CMagicEdit::UpdateMagicSlot)
	ON_CBN_SELCHANGE(IDC_COMBO_MAGIC_LV7_SLOT3, &CMagicEdit::UpdateMagicSlot)
	ON_CBN_SELCHANGE(IDC_COMBO_MAGIC_LV8_SLOT1, &CMagicEdit::UpdateMagicSlot)
	ON_CBN_SELCHANGE(IDC_COMBO_MAGIC_LV8_SLOT2, &CMagicEdit::UpdateMagicSlot)
	ON_CBN_SELCHANGE(IDC_COMBO_MAGIC_LV8_SLOT3, &CMagicEdit::UpdateMagicSlot)
END_MESSAGE_MAP()
//========================================================================================================
BOOL CMagicEdit::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
			pMsg->wParam = NULL;
	} 
	return CDialog::PreTranslateMessage(pMsg);
}
//========================================================================================================
void CMagicEdit::UpdateMagicSlot()
{
	if (bInit)
		return;

	int i;
	int dx;
	DWORD *pCurrent;
	int iIndex = NULL;
	int iSelection = NULL;
	CComboBox *pCombo = NULL;
	
	CComboBox *pLevel1[] = { &m_MagicLv1Slot1, &m_MagicLv1Slot2, &m_MagicLv1Slot3};
	CComboBox *pLevel2[] = { &m_MagicLv2Slot1, &m_MagicLv2Slot2, &m_MagicLv2Slot3};
	CComboBox *pLevel3[] = { &m_MagicLv3Slot1, &m_MagicLv3Slot2, &m_MagicLv3Slot3};
	CComboBox *pLevel4[] = { &m_MagicLv4Slot1, &m_MagicLv4Slot2, &m_MagicLv4Slot3};
	CComboBox *pLevel5[] = { &m_MagicLv5Slot1, &m_MagicLv5Slot2, &m_MagicLv5Slot3};
	CComboBox *pLevel6[] = { &m_MagicLv6Slot1, &m_MagicLv6Slot2, &m_MagicLv6Slot3};
	CComboBox *pLevel7[] = { &m_MagicLv7Slot1, &m_MagicLv7Slot2, &m_MagicLv7Slot3};
	CComboBox *pLevel8[] = { &m_MagicLv8Slot1, &m_MagicLv8Slot2, &m_MagicLv8Slot3};
	void *pTable[] = { pLevel1, pLevel2, pLevel3, pLevel4, pLevel5, pLevel6, pLevel7, pLevel8 };


	for (i=0; i<3; i++)
	{
		pCurrent = (DWORD *)pTable[0];
		pCombo = (CComboBox *)pCurrent[iIndex];
		iSelection = pCombo->GetCurSel();
		if (iSelection == 0)
		{
			pSlot->Char[m_iChar].MagicSlots[i].ItemDigit = 0xFC19;
			pSlot->Char[m_iChar].MagicSlots[i].Quantity = -1;
		}
		else
		{
			pSlot->Char[m_iChar].MagicSlots[i].ItemDigit = tblMagicLv1[iSelection-1].ItemDigit;
			pSlot->Char[m_iChar].MagicSlots[i].Quantity = 0;
		}
		iIndex++;
	}

	// Magic Level 2
	dx = i+3;
	iIndex = NULL;
	for (i=i; i<dx; i++)
	{
		pCurrent = (DWORD *)pTable[1];
		pCombo = (CComboBox *)pCurrent[iIndex];
		iSelection = pCombo->GetCurSel();
		if (iSelection == 0)
		{
			pSlot->Char[m_iChar].MagicSlots[i].ItemDigit = 0xFC19;
			pSlot->Char[m_iChar].MagicSlots[i].Quantity = -1;
		}
		else
		{
			pSlot->Char[m_iChar].MagicSlots[i].ItemDigit = tblMagicLv2[iSelection-1].ItemDigit;
			pSlot->Char[m_iChar].MagicSlots[i].Quantity = 0;
		}
		iIndex++;
	}

	// Magic Level 3
	dx = i+3;
	iIndex = NULL;
	for (i=i; i<dx; i++)
	{
		pCurrent = (DWORD *)pTable[2];
		pCombo = (CComboBox *)pCurrent[iIndex];
		iSelection = pCombo->GetCurSel();
		if (iSelection == 0)
		{
			pSlot->Char[m_iChar].MagicSlots[i].ItemDigit = 0xFC19;
			pSlot->Char[m_iChar].MagicSlots[i].Quantity = -1;
		}
		else
		{
			pSlot->Char[m_iChar].MagicSlots[i].ItemDigit = tblMagicLv3[iSelection-1].ItemDigit;
			pSlot->Char[m_iChar].MagicSlots[i].Quantity = 0;
		}
		iIndex++;
	}

	// Magic Level 4
	dx = i+3;
	iIndex = NULL;
	for (i=i; i<dx; i++)
	{
		pCurrent = (DWORD *)pTable[3];
		pCombo = (CComboBox *)pCurrent[iIndex];
		iSelection = pCombo->GetCurSel();
		if (iSelection == 0)
		{
			pSlot->Char[m_iChar].MagicSlots[i].ItemDigit = 0xFC19;
			pSlot->Char[m_iChar].MagicSlots[i].Quantity = -1;
		}
		else
		{
			pSlot->Char[m_iChar].MagicSlots[i].ItemDigit = tblMagicLv4[iSelection-1].ItemDigit;
			pSlot->Char[m_iChar].MagicSlots[i].Quantity = 0;
		}
		iIndex++;
	}

	// Magic Level 5
	dx = i+3;
	iIndex = NULL;
	for (i=i; i<dx; i++)
	{
		pCurrent = (DWORD *)pTable[4];
		pCombo = (CComboBox *)pCurrent[iIndex];
		iSelection = pCombo->GetCurSel();
		if (iSelection == 0)
		{
			pSlot->Char[m_iChar].MagicSlots[i].ItemDigit = 0xFC19;
			pSlot->Char[m_iChar].MagicSlots[i].Quantity = -1;
		}
		else
		{
			pSlot->Char[m_iChar].MagicSlots[i].ItemDigit = tblMagicLv5[iSelection-1].ItemDigit;
			pSlot->Char[m_iChar].MagicSlots[i].Quantity = 0;
		}
		iIndex++;
	}

	// Magic Level 6
	dx = i+3;
	iIndex = NULL;
	for (i=i; i<dx; i++)
	{
		pCurrent = (DWORD *)pTable[5];
		pCombo = (CComboBox *)pCurrent[iIndex];
		iSelection = pCombo->GetCurSel();
		if (iSelection == 0)
		{
			pSlot->Char[m_iChar].MagicSlots[i].ItemDigit = 0xFC19;
			pSlot->Char[m_iChar].MagicSlots[i].Quantity = -1;
		}
		else
		{
			pSlot->Char[m_iChar].MagicSlots[i].ItemDigit = tblMagicLv6[iSelection-1].ItemDigit;
			pSlot->Char[m_iChar].MagicSlots[i].Quantity = 0;
		}
		iIndex++;
	}

	// Magic Level 7
	dx = i+3;
	iIndex = NULL;
	for (i=i; i<dx; i++)
	{
		pCurrent = (DWORD *)pTable[6];
		pCombo = (CComboBox *)pCurrent[iIndex];
		iSelection = pCombo->GetCurSel();
		if (iSelection == 0)
		{
			pSlot->Char[m_iChar].MagicSlots[i].ItemDigit = 0xFC19;
			pSlot->Char[m_iChar].MagicSlots[i].Quantity = -1;
		}
		else
		{
			pSlot->Char[m_iChar].MagicSlots[i].ItemDigit = tblMagicLv7[iSelection-1].ItemDigit;
			pSlot->Char[m_iChar].MagicSlots[i].Quantity = 0;
		}
		iIndex++;
	}

	// Magic Level 8
	dx = i+3;
	iIndex = NULL;
	for (i=i; i<dx; i++)
	{
		pCurrent = (DWORD *)pTable[7];
		pCombo = (CComboBox *)pCurrent[iIndex];
		iSelection = pCombo->GetCurSel();
		if (iSelection == 0)
		{
			pSlot->Char[m_iChar].MagicSlots[i].ItemDigit = 0xFC19;
			pSlot->Char[m_iChar].MagicSlots[i].Quantity = -1;
		}
		else
		{
			pSlot->Char[m_iChar].MagicSlots[i].ItemDigit = tblMagicLv8[iSelection-1].ItemDigit;
			pSlot->Char[m_iChar].MagicSlots[i].Quantity = 0;
		}
		iIndex++;
	}
}
//========================================================================================================
