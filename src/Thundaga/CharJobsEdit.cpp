//========================================================================================================
// CharJobsEdit.cpp : implementation file
//========================================================================================================
#include "stdafx.h"
#include "Digits.h"
#include "Thundaga.h"
#include "CharJobsEdit.h"
//========================================================================================================
IMPLEMENT_DYNAMIC(CJobsEdit, CDialog)
//========================================================================================================
CJobsEdit::CJobsEdit(int iCharacter, CWnd* pParent /*=NULL*/)
	: CDialog(CJobsEdit::IDD, pParent)
{
	m_iChar = iCharacter;
}
//========================================================================================================
CJobsEdit::~CJobsEdit()
{
}
//========================================================================================================
void CJobsEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_JOB_LVL01, m_JobLv01);
	DDX_Control(pDX, IDC_EDIT_JOB_EXP01, m_JobEx01);
	DDX_Control(pDX, IDC_EDIT_JOB_LVL02, m_JobLv02);
	DDX_Control(pDX, IDC_EDIT_JOB_EXP02, m_JobEx02);
	DDX_Control(pDX, IDC_EDIT_JOB_LVL03, m_JobLv03);
	DDX_Control(pDX, IDC_EDIT_JOB_EXP03, m_JobEx03);
	DDX_Control(pDX, IDC_EDIT_JOB_LVL04, m_JobLv04);
	DDX_Control(pDX, IDC_EDIT_JOB_EXP04, m_JobEx04);
	DDX_Control(pDX, IDC_EDIT_JOB_LVL05, m_JobLv05);
	DDX_Control(pDX, IDC_EDIT_JOB_EXP05, m_JobEx05);
	DDX_Control(pDX, IDC_EDIT_JOB_LVL06, m_JobLv06);
	DDX_Control(pDX, IDC_EDIT_JOB_EXP06, m_JobEx06);
	DDX_Control(pDX, IDC_EDIT_JOB_LVL07, m_JobLv07);
	DDX_Control(pDX, IDC_EDIT_JOB_EXP07, m_JobEx07);
	DDX_Control(pDX, IDC_EDIT_JOB_LVL08, m_JobLv08);
	DDX_Control(pDX, IDC_EDIT_JOB_EXP08, m_JobEx08);
	DDX_Control(pDX, IDC_EDIT_JOB_LVL09, m_JobLv09);
	DDX_Control(pDX, IDC_EDIT_JOB_EXP09, m_JobEx09);
	DDX_Control(pDX, IDC_EDIT_JOB_LVL10, m_JobLv10);
	DDX_Control(pDX, IDC_EDIT_JOB_EXP10, m_JobEx10);
	DDX_Control(pDX, IDC_EDIT_JOB_LVL11, m_JobLv11);
	DDX_Control(pDX, IDC_EDIT_JOB_EXP11, m_JobEx11);
	DDX_Control(pDX, IDC_EDIT_JOB_LVL12, m_JobLv12);
	DDX_Control(pDX, IDC_EDIT_JOB_EXP12, m_JobEx12);
	DDX_Control(pDX, IDC_EDIT_JOB_LVL13, m_JobLv13);
	DDX_Control(pDX, IDC_EDIT_JOB_EXP13, m_JobEx13);
	DDX_Control(pDX, IDC_EDIT_JOB_LVL14, m_JobLv14);
	DDX_Control(pDX, IDC_EDIT_JOB_EXP14, m_JobEx14);
	DDX_Control(pDX, IDC_EDIT_JOB_LVL15, m_JobLv15);
	DDX_Control(pDX, IDC_EDIT_JOB_EXP15, m_JobEx15);
	DDX_Control(pDX, IDC_EDIT_JOB_LVL16, m_JobLv16);
	DDX_Control(pDX, IDC_EDIT_JOB_EXP16, m_JobEx16);
	DDX_Control(pDX, IDC_EDIT_JOB_LVL17, m_JobLv17);
	DDX_Control(pDX, IDC_EDIT_JOB_EXP17, m_JobEx17);
	DDX_Control(pDX, IDC_EDIT_JOB_LVL18, m_JobLv18);
	DDX_Control(pDX, IDC_EDIT_JOB_EXP18, m_JobEx18);
	DDX_Control(pDX, IDC_EDIT_JOB_LVL19, m_JobLv19);
	DDX_Control(pDX, IDC_EDIT_JOB_EXP19, m_JobEx19);
	DDX_Control(pDX, IDC_EDIT_JOB_LVL20, m_JobLv20);
	DDX_Control(pDX, IDC_EDIT_JOB_EXP20, m_JobEx20);
	DDX_Control(pDX, IDC_EDIT_JOB_LVL21, m_JobLv21);
	DDX_Control(pDX, IDC_EDIT_JOB_EXP21, m_JobEx21);
	DDX_Control(pDX, IDC_EDIT_JOB_LVL22, m_JobLv22);
	DDX_Control(pDX, IDC_EDIT_JOB_EXP22, m_JobEx22);
	DDX_Control(pDX, IDC_EDIT_JOB_LVL23, m_JobLv23);
	DDX_Control(pDX, IDC_EDIT_JOB_EXP23, m_JobEx23);
	DDX_Control(pDX, IDC_COMBO_CURRENT_JOB, m_JobList);
}
//========================================================================================================
BOOL CJobsEdit::OnInitDialog()
{
	char szExp[32] = {0};
	char szLevel[32] = {0};
	CEdit *tblLvlEdits[] = {	&m_JobLv01, &m_JobLv02, &m_JobLv03, &m_JobLv04, &m_JobLv05, &m_JobLv06,
								&m_JobLv07, &m_JobLv08, &m_JobLv09, &m_JobLv10, &m_JobLv11, &m_JobLv12,
								&m_JobLv13, &m_JobLv14, &m_JobLv15, &m_JobLv16, &m_JobLv17, &m_JobLv18,
								&m_JobLv19, &m_JobLv20, &m_JobLv21, &m_JobLv22, &m_JobLv23 };
	CEdit *tblExpEdits[] = {	&m_JobEx01, &m_JobEx02, &m_JobEx03, &m_JobEx04, &m_JobEx05, &m_JobEx06,
								&m_JobEx07, &m_JobEx08, &m_JobEx09, &m_JobEx10, &m_JobEx11, &m_JobEx12,
								&m_JobEx13, &m_JobEx14, &m_JobEx15, &m_JobEx16, &m_JobEx17, &m_JobEx18,
								&m_JobEx19, &m_JobEx20, &m_JobEx21, &m_JobEx22, &m_JobEx23 };
	CDialog::OnInitDialog();

	// Insert Jobs
	for (int i=0; i<JOB_COUNT; i++)
		m_JobList.InsertString(i, JobTable[i].szJobName);

	// Set Current Job
	m_JobList.SetCurSel(pSlot->Char[m_iChar].CurrentJob);

	// Fill Job Information
	for (int i=0; i<_countof(tblExpEdits); i++)
	{
		CEdit *pEditExp = tblExpEdits[i];
		CEdit *pEditLevel = tblLvlEdits[i];

		// Format
		sprintf_s(szLevel, _countof(szLevel), "%d", pSlot->Char[m_iChar].Jobs[i].Level);
		sprintf_s(szExp, _countof(szExp), "%d", pSlot->Char[m_iChar].Jobs[i].SavedExperience);

		// Set
		pEditExp->SetLimitText(2);
		pEditLevel->SetLimitText(2);
		pEditExp->SetWindowText(szExp);
		pEditLevel->SetWindowText(szLevel);
	}
	return TRUE;
}
//========================================================================================================
BEGIN_MESSAGE_MAP(CJobsEdit, CDialog)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_EXP01, &CJobsEdit::EnKillfocusEditJobExp01)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_LVL01, &CJobsEdit::EnKillfocusEditJobLvl01)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_EXP02, &CJobsEdit::EnKillfocusEditJobExp02)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_LVL02, &CJobsEdit::EnKillfocusEditJobLvl02)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_EXP03, &CJobsEdit::EnKillfocusEditJobExp03)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_LVL03, &CJobsEdit::EnKillfocusEditJobLvl03)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_EXP04, &CJobsEdit::EnKillfocusEditJobExp04)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_LVL04, &CJobsEdit::EnKillfocusEditJobLvl04)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_EXP05, &CJobsEdit::EnKillfocusEditJobExp05)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_LVL05, &CJobsEdit::EnKillfocusEditJobLvl05)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_EXP06, &CJobsEdit::EnKillfocusEditJobExp06)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_LVL06, &CJobsEdit::EnKillfocusEditJobLvl06)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_EXP07, &CJobsEdit::EnKillfocusEditJobExp07)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_LVL07, &CJobsEdit::EnKillfocusEditJobLvl07)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_EXP08, &CJobsEdit::EnKillfocusEditJobExp08)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_LVL08, &CJobsEdit::EnKillfocusEditJobLvl08)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_EXP09, &CJobsEdit::EnKillfocusEditJobExp09)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_LVL09, &CJobsEdit::EnKillfocusEditJobLvl09)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_EXP10, &CJobsEdit::EnKillfocusEditJobExp10)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_LVL10, &CJobsEdit::EnKillfocusEditJobLvl10)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_EXP11, &CJobsEdit::EnKillfocusEditJobExp11)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_LVL11, &CJobsEdit::EnKillfocusEditJobLvl11)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_EXP12, &CJobsEdit::EnKillfocusEditJobExp12)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_LVL12, &CJobsEdit::EnKillfocusEditJobLvl12)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_EXP13, &CJobsEdit::EnKillfocusEditJobExp13)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_LVL13, &CJobsEdit::EnKillfocusEditJobLvl13)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_EXP14, &CJobsEdit::EnKillfocusEditJobExp14)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_LVL14, &CJobsEdit::EnKillfocusEditJobLvl14)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_EXP15, &CJobsEdit::EnKillfocusEditJobExp15)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_LVL15, &CJobsEdit::EnKillfocusEditJobLvl15)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_EXP16, &CJobsEdit::EnKillfocusEditJobExp16)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_LVL16, &CJobsEdit::EnKillfocusEditJobLvl16)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_EXP17, &CJobsEdit::EnKillfocusEditJobExp17)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_LVL17, &CJobsEdit::EnKillfocusEditJobLvl17)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_EXP18, &CJobsEdit::EnKillfocusEditJobExp18)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_LVL18, &CJobsEdit::EnKillfocusEditJobLvl18)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_EXP19, &CJobsEdit::EnKillfocusEditJobExp19)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_LVL19, &CJobsEdit::EnKillfocusEditJobLvl19)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_EXP20, &CJobsEdit::EnKillfocusEditJobExp20)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_LVL20, &CJobsEdit::EnKillfocusEditJobLvl20)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_EXP21, &CJobsEdit::EnKillfocusEditJobExp21)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_LVL21, &CJobsEdit::EnKillfocusEditJobLvl21)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_EXP22, &CJobsEdit::EnKillfocusEditJobExp22)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_LVL22, &CJobsEdit::EnKillfocusEditJobLvl22)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_EXP23, &CJobsEdit::EnKillfocusEditJobExp23)
	ON_EN_KILLFOCUS(IDC_EDIT_JOB_LVL23, &CJobsEdit::EnKillfocusEditJobLvl23)
	ON_CBN_SELCHANGE(IDC_COMBO_CURRENT_JOB, &CJobsEdit::OnCbnSelchangeComboCurrentJob)
END_MESSAGE_MAP()
//========================================================================================================
BOOL CJobsEdit::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
			pMsg->wParam = NULL;
	} 
	return CDialog::PreTranslateMessage(pMsg);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobLvl01()
{
	char szLevel[32] = {0};
	if (m_JobLv01.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobLv01.SetFocus();
		return;
	}
	m_JobLv01.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[0].Level = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobExp01()
{
	char szLevel[32] = {0};
	if (m_JobEx01.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobEx01.SetFocus();
		return;
	}
	m_JobEx01.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[0].SavedExperience = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobLvl02()
{
	char szLevel[32] = {0};
	if (m_JobLv02.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobLv02.SetFocus();
		return;
	}
	m_JobLv02.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[1].Level = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobExp02()
{
	char szLevel[32] = {0};
	if (m_JobEx02.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobEx02.SetFocus();
		return;
	}
	m_JobEx02.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[1].SavedExperience = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobLvl03()
{
	char szLevel[32] = {0};
	if (m_JobLv03.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobLv03.SetFocus();
		return;
	}
	m_JobLv03.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[2].Level = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobExp03()
{
	char szLevel[32] = {0};
	if (m_JobEx03.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobEx03.SetFocus();
		return;
	}
	m_JobEx03.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[2].SavedExperience = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobLvl04()
{
	char szLevel[32] = {0};
	if (m_JobLv04.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobLv04.SetFocus();
		return;
	}
	m_JobLv04.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[3].Level = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobExp04()
{
	char szLevel[32] = {0};
	if (m_JobEx04.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobEx04.SetFocus();
		return;
	}
	m_JobEx04.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[3].SavedExperience = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobLvl05()
{
	char szLevel[32] = {0};
	if (m_JobLv05.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobLv05.SetFocus();
		return;
	}
	m_JobLv05.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[4].Level = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobExp05()
{
	char szLevel[32] = {0};
	if (m_JobEx05.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobEx05.SetFocus();
		return;
	}
	m_JobEx05.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[4].SavedExperience = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobLvl06()
{
	char szLevel[32] = {0};
	if (m_JobLv06.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobLv06.SetFocus();
		return;
	}
	m_JobLv06.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[5].Level = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobExp06()
{
	char szLevel[32] = {0};
	if (m_JobEx06.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobEx06.SetFocus();
		return;
	}
	m_JobEx06.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[5].SavedExperience = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobLvl07()
{
	char szLevel[32] = {0};
	if (m_JobLv07.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobLv07.SetFocus();
		return;
	}
	m_JobLv07.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[6].Level = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobExp07()
{
	char szLevel[32] = {0};
	if (m_JobEx07.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobEx07.SetFocus();
		return;
	}
	m_JobEx07.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[6].SavedExperience = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobLvl08()
{
	char szLevel[32] = {0};
	if (m_JobLv08.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobLv08.SetFocus();
		return;
	}
	m_JobLv08.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[7].Level = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobExp08()
{
	char szLevel[32] = {0};
	if (m_JobEx08.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobEx08.SetFocus();
		return;
	}
	m_JobEx08.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[7].SavedExperience = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobLvl09()
{
	char szLevel[32] = {0};
	if (m_JobLv09.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobLv09.SetFocus();
		return;
	}
	m_JobLv09.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[8].Level = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobExp09()
{
	char szLevel[32] = {0};
	if (m_JobEx09.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobEx09.SetFocus();
		return;
	}
	m_JobEx09.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[8].SavedExperience = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobLvl10()
{
	char szLevel[32] = {0};
	if (m_JobLv10.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobLv10.SetFocus();
		return;
	}
	m_JobLv10.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[9].Level = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobExp10()
{
	char szLevel[32] = {0};
	if (m_JobEx10.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobEx10.SetFocus();
		return;
	}
	m_JobEx10.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[9].SavedExperience = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobLvl11()
{
	char szLevel[32] = {0};
	if (m_JobLv11.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobLv11.SetFocus();
		return;
	}
	m_JobLv11.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[10].Level = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobExp11()
{
	char szLevel[32] = {0};
	if (m_JobEx11.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobEx11.SetFocus();
		return;
	}
	m_JobEx11.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[10].SavedExperience = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobLvl12()
{
	char szLevel[32] = {0};
	if (m_JobLv12.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobLv12.SetFocus();
		return;
	}
	m_JobLv12.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[11].Level = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobExp12()
{
	char szLevel[32] = {0};
	if (m_JobEx12.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobEx12.SetFocus();
		return;
	}
	m_JobEx12.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[11].SavedExperience = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobLvl13()
{
	char szLevel[32] = {0};
	if (m_JobLv13.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobLv13.SetFocus();
		return;
	}
	m_JobLv13.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[12].Level = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobExp13()
{
	char szLevel[32] = {0};
	if (m_JobEx13.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobEx13.SetFocus();
		return;
	}
	m_JobEx13.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[12].SavedExperience = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobLvl14()
{
	char szLevel[32] = {0};
	if (m_JobLv14.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobLv14.SetFocus();
		return;
	}
	m_JobLv14.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[13].Level = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobExp14()
{
	char szLevel[32] = {0};
	if (m_JobEx14.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobEx14.SetFocus();
		return;
	}
	m_JobEx14.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[13].SavedExperience = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobLvl15()
{
	char szLevel[32] = {0};
	if (m_JobLv15.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobLv15.SetFocus();
		return;
	}
	m_JobLv15.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[14].Level = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobExp15()
{
	char szLevel[32] = {0};
	if (m_JobEx15.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobEx15.SetFocus();
		return;
	}
	m_JobEx15.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[14].SavedExperience = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobLvl16()
{
	char szLevel[32] = {0};
	if (m_JobLv16.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobLv16.SetFocus();
		return;
	}
	m_JobLv16.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[15].Level = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobExp16()
{
	char szLevel[32] = {0};
	if (m_JobEx16.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobEx16.SetFocus();
		return;
	}
	m_JobEx16.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[15].SavedExperience = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobLvl17()
{
	char szLevel[32] = {0};
	if (m_JobLv17.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobLv17.SetFocus();
		return;
	}
	m_JobLv17.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[16].Level = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobExp17()
{
	char szLevel[32] = {0};
	if (m_JobEx17.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobEx17.SetFocus();
		return;
	}
	m_JobEx17.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[16].SavedExperience = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobLvl18()
{
	char szLevel[32] = {0};
	if (m_JobLv18.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobLv18.SetFocus();
		return;
	}
	m_JobLv18.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[17].Level = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobExp18()
{
	char szLevel[32] = {0};
	if (m_JobEx18.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobEx18.SetFocus();
		return;
	}
	m_JobEx18.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[17].SavedExperience = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobLvl19()
{
	char szLevel[32] = {0};
	if (m_JobLv19.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobLv19.SetFocus();
		return;
	}
	m_JobLv19.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[18].Level = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobExp19()
{
	char szLevel[32] = {0};
	if (m_JobEx19.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobEx19.SetFocus();
		return;
	}
	m_JobEx19.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[18].SavedExperience = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobLvl20()
{
	char szLevel[32] = {0};
	if (m_JobLv20.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobLv20.SetFocus();
		return;
	}
	m_JobLv20.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[19].Level = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobExp20()
{
	char szLevel[32] = {0};
	if (m_JobEx20.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobEx20.SetFocus();
		return;
	}
	m_JobEx20.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[19].SavedExperience = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobLvl21()
{
	char szLevel[32] = {0};
	if (m_JobLv21.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobLv21.SetFocus();
		return;
	}
	m_JobLv21.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[20].Level = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobExp21()
{
	char szLevel[32] = {0};
	if (m_JobEx21.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobEx21.SetFocus();
		return;
	}
	m_JobEx21.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[20].SavedExperience = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobLvl22()
{
	char szLevel[32] = {0};
	if (m_JobLv22.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobLv22.SetFocus();
		return;
	}
	m_JobLv22.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[21].Level = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobExp22()
{
	char szLevel[32] = {0};
	if (m_JobEx22.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobEx22.SetFocus();
		return;
	}
	m_JobEx22.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[21].SavedExperience = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobLvl23()
{
	char szLevel[32] = {0};
	if (m_JobLv23.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobLv23.SetFocus();
		return;
	}
	m_JobLv23.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[22].Level = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::EnKillfocusEditJobExp23()
{
	char szLevel[32] = {0};
	if (m_JobEx23.GetWindowTextLength() == 0)
	{
		MessageBox("Enter a Number.", "Job Information", MB_OK|MB_ICONEXCLAMATION);
		m_JobEx23.SetFocus();
		return;
	}
	m_JobEx23.GetWindowText(szLevel, 3);
	pSlot->Char[m_iChar].Jobs[22].SavedExperience = strtoul(szLevel, NULL, NULL);
}
//========================================================================================================
void CJobsEdit::OnCbnSelchangeComboCurrentJob()
{
	int iJob = NULL;
	iJob = m_JobList.GetCurSel();
	pSlot->Char[m_iChar].CurrentJob = JobTable[iJob].JobIndex;
	pSlot->Char[m_iChar].Battle_Command = JobTable[iJob].Battle_Command;
}
//========================================================================================================
