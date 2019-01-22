//========================================================================================================
// CharStatusEdit.cpp : implementation file
//========================================================================================================
#include "stdafx.h"
#include "Digits.h"
#include "Thundaga.h"
#include "CharStatusEdit.h"
//========================================================================================================
IMPLEMENT_DYNAMIC(CStatusEdit, CDialog)
//========================================================================================================
CStatusEdit::CStatusEdit(int iCharacter, CWnd* pParent /*=NULL*/)
	: CDialog(CStatusEdit::IDD, pParent)
{
	m_iChar = iCharacter;
}
//========================================================================================================
CStatusEdit::~CStatusEdit()
{
}
//========================================================================================================
void CStatusEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK_TOAD, m_Toad);
	DDX_Control(pDX, IDC_CHECK_MINI, m_Mini);
	DDX_Control(pDX, IDC_CHECK_BLND, m_Blind);
	DDX_Control(pDX, IDC_CHECK_PSND, m_Poison);
	DDX_Control(pDX, IDC_CHECK_SILN, m_Silence);
	DDX_Control(pDX, IDC_CHECK_PETRI, m_Petrified);
}
//========================================================================================================
BOOL CStatusEdit::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_Toad.SetCheck(IsToad(pSlot->Char[m_iChar].CurrentStatus));
	m_Mini.SetCheck(IsMini(pSlot->Char[m_iChar].CurrentStatus));
	m_Blind.SetCheck(IsBlind(pSlot->Char[m_iChar].CurrentStatus));
	m_Poison.SetCheck(IsPoison(pSlot->Char[m_iChar].CurrentStatus));
	m_Silence.SetCheck(IsSilence(pSlot->Char[m_iChar].CurrentStatus));
	m_Petrified.SetCheck(IsPetrified(pSlot->Char[m_iChar].CurrentStatus));
	return TRUE;
}
//========================================================================================================
BEGIN_MESSAGE_MAP(CStatusEdit, CDialog)
	ON_BN_CLICKED(IDC_CHECK_PETRI, &CStatusEdit::OnBnClickedCheckPetri)
	ON_BN_CLICKED(IDC_CHECK_TOAD, &CStatusEdit::OnBnClickedCheckToad)
	ON_BN_CLICKED(IDC_CHECK_SILN, &CStatusEdit::OnBnClickedCheckSiln)
	ON_BN_CLICKED(IDC_CHECK_MINI, &CStatusEdit::OnBnClickedCheckMini)
	ON_BN_CLICKED(IDC_CHECK_BLND, &CStatusEdit::OnBnClickedCheckBlnd)
	ON_BN_CLICKED(IDC_CHECK_PSND, &CStatusEdit::OnBnClickedCheckPsnd)
END_MESSAGE_MAP()
//========================================================================================================
BOOL CStatusEdit::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
			pMsg->wParam = NULL;
	} 
	return CDialog::PreTranslateMessage(pMsg);
}
//========================================================================================================
void CStatusEdit::OnBnClickedCheckPetri()
{
	switch(m_Petrified.GetCheck())
	{
	case 1:
		{
			pSlot->Char[m_iChar].CurrentStatus |= PETRIFIED;
		}
		break;
	default:
		{
			pSlot->Char[m_iChar].CurrentStatus &= ~PETRIFIED;
		}
	    break;
	}
}
//========================================================================================================
void CStatusEdit::OnBnClickedCheckToad()
{
	switch(m_Toad.GetCheck())
	{
	case 1:
		{
			pSlot->Char[m_iChar].CurrentStatus |= TOAD;
		}
		break;
	default:
		{
			pSlot->Char[m_iChar].CurrentStatus &= ~TOAD;
		}
		break;
	}

}
//========================================================================================================
void CStatusEdit::OnBnClickedCheckSiln()
{
	switch(m_Silence.GetCheck())
	{
	case 1:
		{
			pSlot->Char[m_iChar].CurrentStatus |= SILENCE;
		}
		break;
	default:
		{
			pSlot->Char[m_iChar].CurrentStatus &= ~SILENCE;
		}
		break;
	}
}
//========================================================================================================
void CStatusEdit::OnBnClickedCheckMini()
{
	switch(m_Mini.GetCheck())
	{
	case 1:
		{
			pSlot->Char[m_iChar].CurrentStatus |= MINI;
		}
		break;
	default:
		{
			pSlot->Char[m_iChar].CurrentStatus &= ~MINI;
		}
		break;
	}
}
//========================================================================================================
void CStatusEdit::OnBnClickedCheckBlnd()
{
	switch(m_Blind.GetCheck())
	{
	case 1:
		{
			pSlot->Char[m_iChar].CurrentStatus |= BLIND;
		}
		break;
	default:
		{
			pSlot->Char[m_iChar].CurrentStatus &= ~BLIND;
		}
		break;
	}
}
//========================================================================================================
void CStatusEdit::OnBnClickedCheckPsnd()
{
	switch(m_Poison.GetCheck())
	{
	case 1:
		{
			pSlot->Char[m_iChar].CurrentStatus |= POISON;
		}
		break;
	default:
		{
			pSlot->Char[m_iChar].CurrentStatus &= ~POISON;
		}
		break;
	}
}
//========================================================================================================