//========================================================================================================
// MiscEditor.cpp : implementation file
//========================================================================================================
#include "stdafx.h"
#include "Digits.h"
#include "Thundaga.h"
#include "MiscEditor.h"
//========================================================================================================
IMPLEMENT_DYNAMIC(CMiscEditor, CPropertyPage)
//========================================================================================================
CMiscEditor::CMiscEditor()
	: CPropertyPage(CMiscEditor::IDD)
{

}
//========================================================================================================
CMiscEditor::~CMiscEditor()
{
}
//========================================================================================================
void CMiscEditor::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SPIN_HRS, m_SpinHrs);
	DDX_Control(pDX, IDC_SPIN_MINS, m_SpinMins);
	DDX_Control(pDX, IDC_SPIN_SECS, m_SpinSecs);
	DDX_Control(pDX, IDC_SPIN_GOLD, m_GoldSpin);
	DDX_Control(pDX, IDC_SPIN_WIFI, m_WifiSpin);
}
//========================================================================================================
BOOL CMiscEditor::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// 0 -> 9999999
	m_GoldSpin.SetRange32(0, 0x98967F);
	m_GoldSpin.SetPos32(pSlot->TotalGil);

	m_WifiSpin.SetRange(0, 99);
	m_WifiSpin.SetPos(pSlot->WifiMailSent);

	m_SpinHrs.SetRange(0,255);
	m_SpinMins.SetRange(0,59);
	m_SpinSecs.SetRange(0,59);

	m_SpinHrs.SetPos(div(pSlot->PlayTime, 3600).quot);
	m_SpinMins.SetPos(div(div(pSlot->PlayTime, 3600).rem,60).quot);
	m_SpinSecs.SetPos(div(div(pSlot->PlayTime, 3600).rem,60).rem);
	return TRUE;
}
//========================================================================================================
BEGIN_MESSAGE_MAP(CMiscEditor, CPropertyPage)
	ON_EN_KILLFOCUS(IDC_GOLD_EDIT, &CMiscEditor::OnEnKillfocusGoldEdit)
	ON_EN_KILLFOCUS(IDC_WIFI_EDIT, &CMiscEditor::OnEnKillfocusWifiEdit)
	ON_EN_KILLFOCUS(IDC_TIME_HRS_EDIT, &CMiscEditor::OnEnKillfocusTimeHrsEdit)
	ON_EN_KILLFOCUS(IDC_TIME_MINS_EDIT, &CMiscEditor::OnEnKillfocusTimeMinsEdit)
	ON_EN_KILLFOCUS(IDC_TIME_SECS_EDIT, &CMiscEditor::OnEnKillfocusTimeSecsEdit)
END_MESSAGE_MAP()
//========================================================================================================
void CMiscEditor::OnEnKillfocusGoldEdit()
{
	pSlot->TotalGil = m_GoldSpin.GetPos32();
}
//========================================================================================================
void CMiscEditor::OnEnKillfocusWifiEdit()
{
	pSlot->WifiMailSent = m_WifiSpin.GetPos();
}
//========================================================================================================
void CMiscEditor::OnEnKillfocusTimeHrsEdit()
{
	pSlot->PlayTime = ((m_SpinHrs.GetPos() * 3600) + (m_SpinMins.GetPos() * 60) + m_SpinSecs.GetPos()); 
}
//========================================================================================================
void CMiscEditor::OnEnKillfocusTimeMinsEdit()
{
	pSlot->PlayTime = ((m_SpinHrs.GetPos() * 3600) + (m_SpinMins.GetPos() * 60) + m_SpinSecs.GetPos()); 
}
//========================================================================================================
void CMiscEditor::OnEnKillfocusTimeSecsEdit()
{
	pSlot->PlayTime = ((m_SpinHrs.GetPos() * 3600) + (m_SpinMins.GetPos() * 60) + m_SpinSecs.GetPos()); 
}
//========================================================================================================