// ThundagaEditor.cpp : implementation file
//

#include "stdafx.h"
#include "Thundaga.h"
#include "ThundagaEditor.h"


// CThundagaEditor

IMPLEMENT_DYNAMIC(CThundagaEditor, CPropertySheet)

CThundagaEditor::CThundagaEditor()
{

}

CThundagaEditor::CThundagaEditor(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	
}

CThundagaEditor::~CThundagaEditor()
{
}

BOOL CThundagaEditor::OnInitDialog()
{
	CPropertySheet::OnInitDialog();
	SetWindowText("Thundaga Save Editor v1.02");
	return TRUE;
}

BEGIN_MESSAGE_MAP(CThundagaEditor, CPropertySheet)
END_MESSAGE_MAP()


// CThundagaEditor message handlers
