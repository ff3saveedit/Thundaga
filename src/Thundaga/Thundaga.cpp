//========================================================================================================
// Thundaga.cpp : Defines the class behaviors for the application.
//========================================================================================================
#include "stdafx.h"
#include "Digits.h"
#include "Thundaga.h"
#include "ThundagaDlg.h"
#include "FileStructure.h"
#include "ThundagaEditor.h"
//========================================================================================================
#ifdef _DEBUG
	#define new DEBUG_NEW
#endif
//========================================================================================================
BEGIN_MESSAGE_MAP(CThundagaApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()
//========================================================================================================
CThundagaApp::CThundagaApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}
//========================================================================================================
CThundagaApp theApp;
//========================================================================================================
BOOL CThundagaApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	// Build Items Table
	printf("Table");
	BuildTables();
	
	CWinApp::InitInstance();

	CThundagaDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
//========================================================================================================
int CThundagaApp::ExitInstance()
{
	CWinApp::ExitInstance();
	return 0;
}
//========================================================================================================