//========================================================================================================
// SaveMgr.cpp : implementation file
//========================================================================================================
#include "stdafx.h"
#include "gzip.h"
#include "SaveMgr.h"
#include "Thundaga.h"
#include "ThundagaDlg.h"
using namespace zlib;
//========================================================================================================
CGZip gzip;
//========================================================================================================
#ifdef _DEBUG
	#define new DEBUG_NEW
#endif
//========================================================================================================
static unsigned long M3Footer[256] = {
	0x544F4F42, 0x59535000, 0x3346462D, 0x53444E55, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x59535000, 0x3346462D, 0x444E2E55, 0x00000053, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
//========================================================================================================
unsigned long M3Footer_Org[256] = {
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
//========================================================================================================
static unsigned long DSX_Header[6] = {
		0xCD850001, 0x46412CC4, 0x46464546, 0x00000033, 0x00000000, 0x00010000 };
//========================================================================================================
bool CSaveMgr::bLoadDsXFile(TCHAR *szFile)
{
	
	if (!gzip.Open(szFile, CGZip::ArchiveModeRead, 24))
	{
		MessageBox(AfxGetMainWnd()->GetSafeHwnd(), TEXT("Unable to open file for reading"), TEXT("File Error!"), MB_OK );	   
		return FALSE;
	}

	void* pBuffer=NULL;
	size_t iLength;
	gzip.ReadBuffer(&pBuffer, iLength);
	gzip.Close();

	// Allocate Enough Memory
	lpLoadedFile = (char *)malloc(iLength + 4);
	if (!lpLoadedFile)
	{
		MessageBox(AfxGetMainWnd()->GetSafeHwnd(), TEXT("Unable to malloc Memory"), TEXT("Memory Error!"), MB_OK );
		return FALSE;
	}

	// Read the Entire File
	memset(lpLoadedFile, 0, iLength);
	memcpy(lpLoadedFile, pBuffer, iLength);
	delete[] pBuffer;

	// Look for a Valid Save File
	if (_stricmp(lpLoadedFile+(0x10000-0x20), "This card was initialized.") != 0)
	{
		if (lpLoadedFile)
		{
			free(lpLoadedFile);
			lpLoadedFile = NULL;
		}
		MessageBox(AfxGetMainWnd()->GetSafeHwnd(), TEXT("Unable to Find a Valid Save"), TEXT("Save Error!"), MB_OK );
		return FALSE;
	}

	bChanged = FALSE;
	return TRUE;	
};
//========================================================================================================
bool CSaveMgr::bLoadSaveFile(TCHAR *szFile)
{
	errno_t err;
	TCHAR *szPosition;
	TCHAR szExt[32] = {0};
	long lLength, lFileStart;

	// Get File Extension
	szPosition = (szFile+strlen(szFile));
	while (szPosition >= szFile && *szPosition != 0x2E)
		--szPosition;
	strcpy_s(szExt, _countof(szExt), szPosition);

	// Try to Open the Save
	if ((err = fopen_s( &lpOrgFile, szFile, TEXT("rb") )) !=0 )
	{
	   MessageBox(AfxGetMainWnd()->GetSafeHwnd(), TEXT("Unable to open file for reading"), TEXT("File Error!"), MB_OK );	   
	   return FALSE;
	}

	// File Length
	lFileStart = ftell(lpOrgFile);
	fseek(lpOrgFile, 0L, SEEK_END);
	lLength = ftell(lpOrgFile);
	fseek(lpOrgFile, lFileStart, SEEK_SET);

	// Allocate Enough Memory
	lpLoadedFile = (char *)malloc(lLength + 4);
	if (!lpLoadedFile)
	{
	   MessageBox(AfxGetMainWnd()->GetSafeHwnd(), TEXT("Unable to malloc Memory"), TEXT("Memory Error!"), MB_OK );
	   return FALSE;
	}

	// Read the Entire File
	memset(lpLoadedFile, 0, lLength);
	fread(lpLoadedFile, 1, lLength, lpOrgFile);
	fclose(lpOrgFile);
	lpOrgFile = NULL;
	
	// Look for a Valid Save File
	if (_stricmp(lpLoadedFile+(0x10000-0x20), "This card was initialized.") != 0)
	{
		if (lpLoadedFile)
		{
			free(lpLoadedFile);
			lpLoadedFile = NULL;
		}
		MessageBox(AfxGetMainWnd()->GetSafeHwnd(), TEXT("Unable to Find a Valid Save"), TEXT("Save Error!"), MB_OK );
		return FALSE;
	}

	// If the save is m3, copy its header for later
	if (bSaveM3)
	{
		memcpy(M3Footer_Org, lpLoadedFile+0x40000, 1024);
	}

	bChanged = FALSE;
	return TRUE;
}
//========================================================================================================
DWORD CSaveMgr::GetCheckSum(byte *pData)
{
	int i;
	DWORD dwCheckSum = NULL;
	DWORD *pStart = (DWORD *)pData;

	// Calculate CheckSum
	for (i=0; i<=0x0EB7; i++)
	{
		dwCheckSum += pStart[i];
	}

	return dwCheckSum;
}
//========================================================================================================
bool CSaveMgr::NotifyChanges(bool bExit)
{
	int iReply = IDYES;

	if (bExit)
		iReply = MessageBox(AfxGetMainWnd()->GetSafeHwnd(), TEXT("The save file has changed.\r\n\r\nDo you want to save the changes?"), TEXT("Thundaga Save Editor"), MB_YESNOCANCEL );
	else
		iReply = MessageBox(AfxGetMainWnd()->GetSafeHwnd(), TEXT("The save file has changed.\r\n\r\nDo you want to save the changes?"), TEXT("Thundaga Save Editor"), MB_YESNO );
	
	if (iReply == IDYES)
	{
		DoSave();
		bChanged = FALSE;
		return TRUE;
	}
	if (iReply == IDNO)
	{
		bChanged = FALSE;
		return TRUE;
	}
	if (iReply == IDCANCEL)
	{
		return FALSE;
	}

	return TRUE;
	
}
//========================================================================================================
void CSaveMgr::DoSave()
{
	TCHAR szFile[MAX_PATH];
	OPENFILENAME ofn;
	ZeroMemory(szFile, sizeof(szFile));
	ZeroMemory(&ofn, sizeof(OPENFILENAME));

	ofn.lStructSize       = sizeof(OPENFILENAME);
	ofn.hwndOwner         = AfxGetMainWnd()->GetSafeHwnd();         
	ofn.lpstrFilter       = TEXT("g6 Save (*.0)\0*.0\0m3 Save (*.dat)\0*.dat\0DS-Xtreme Save (*.sav)\0*.sav\0Supercard Save (*.sav)\0*.sav\0Raw Save (*.sav)\0*.sav\0");
	ofn.lpstrFile         =	szFile;
	ofn.nMaxFile		  = sizeof(szFile);  
	ofn.lpstrTitle        = TEXT("Select a Final Fantasy 3 Save File");
	ofn.lpstrDefExt       = TEXT("0"); 
	ofn.Flags             = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY;

	if (GetSaveFileName(&ofn) != TRUE)
	{
		MessageBox(AfxGetMainWnd()->GetSafeHwnd(), TEXT("Unable to Save to that File"), TEXT("Error"), MB_OK);
		return;
	}

	switch(ofn.nFilterIndex)
	{
	case 1:			// g6
	case 4:			// Supercard
		SaveG6SCFile(szFile);
		break;
	case 3:			// DS-Xtreme
		SaveDSXFile(szFile);
		break;
	case 2:			// m3
		SaveM3File(szFile);
	    break;
	default:		// Raw Save
		SaveRawFile(szFile);
		break;
	}

}
//========================================================================================================
void CSaveMgr::SaveDSXFile(TCHAR *szFile)
{
	errno_t err;
	FILE *pFile;
	long lLength, lFileStart;

	char *pSaveBuffer = (char *)malloc(0x40000+sizeof(DSX_Header)+4);
	if (!pSaveBuffer)
	{
		MessageBox(AfxGetMainWnd()->GetSafeHwnd(), TEXT("Call to malloc failed"), TEXT("Memory Error!"), MB_OK );
		return;
	}
	
	memset(pSaveBuffer, 0, 0x40000+sizeof(DSX_Header)+4);
	memcpy(pSaveBuffer+sizeof(DSX_Header), lpLoadedFile, 0x10000);
	memset(pSaveBuffer+sizeof(DSX_Header)+0x10000, 0xFF, 0x30000);

	if (!gzip.Open(szFile, CGZip::ArchiveModeWrite, 0))
	{
		MessageBox(AfxGetMainWnd()->GetSafeHwnd(), TEXT("Unable to open file for Writing"), TEXT("File Error!"), MB_OK );	   
		return;
	}

	gzip.WriteBuffer(pSaveBuffer+sizeof(DSX_Header), 0x10000);
	gzip.Close();

	memset(pSaveBuffer+sizeof(DSX_Header), 0, 0x40000);
	if ((err = fopen_s( &pFile, szFile, TEXT("rb") )) !=0 )
	{
		MessageBox(AfxGetMainWnd()->GetSafeHwnd(), TEXT("Unable to open file for Saving"), TEXT("File Error!"), MB_OK );
		return;
	}

	// File Length
	lFileStart = ftell(pFile);
	fseek(pFile, 0L, SEEK_END);
	lLength = ftell(pFile);
	fseek(pFile, lFileStart, SEEK_SET);
	fread(pSaveBuffer+sizeof(DSX_Header), 1, lLength, pFile);
	fclose(pFile);

	if ((err = fopen_s( &pFile, szFile, TEXT("wb") )) !=0 )
	{
		MessageBox(AfxGetMainWnd()->GetSafeHwnd(), TEXT("Unable to open file for Saving"), TEXT("File Error!"), MB_OK );
		return;
	}

	memcpy(pSaveBuffer, DSX_Header, sizeof(DSX_Header));
	fwrite(pSaveBuffer, 1, lLength+sizeof(DSX_Header), pFile);
	fclose(pFile);


}
//========================================================================================================
void CSaveMgr::SaveM3File(TCHAR *szFile)
{
	int i;
	errno_t err;
	FILE *pFile;

	// Try to open the file
	if ((err = fopen_s( &pFile, szFile, TEXT("wb") )) !=0 )
	{
		MessageBox(AfxGetMainWnd()->GetSafeHwnd(), TEXT("Unable to open file for Saving"), TEXT("File Error!"), MB_OK );
		return;
	}

	// Write first 64KB
	fwrite(lpLoadedFile, 1, 0x10000, pFile);

	// Write Filler
	for (i=0; i<0x30000; i++)
	{
		fputc(0xFF, pFile);
	}

	if (bSaveM3)
	{
		// Write Original M3 Footer
		fwrite(M3Footer_Org, 1, sizeof(M3Footer_Org), pFile);
	}
	else
	{
		// Write Static M3 Footer
		fwrite(M3Footer, 1, sizeof(M3Footer), pFile);
	}
	fclose(pFile);
}
//========================================================================================================
void CSaveMgr::SaveG6SCFile(TCHAR *szFile)
{
	int i;
	errno_t err;
	FILE *pFile;

	// Try to open the file
	if ((err = fopen_s( &pFile, szFile, TEXT("wb") )) !=0 )
	{
		MessageBox(AfxGetMainWnd()->GetSafeHwnd(), TEXT("Unable to open file for Saving"), TEXT("File Error!"), MB_OK );
		return;
	}

	// Write first 64KB
	fwrite(lpLoadedFile, 1, 0x10000, pFile);

	// Write Filler
	for (i=0; i<0x30000; i++)
	{
		fputc(0xFF, pFile);
	}
	fclose(pFile);
}
//========================================================================================================
void CSaveMgr::SaveRawFile(TCHAR *szFile)
{
	errno_t err;
	FILE *pFile;

	// Try to open the file
	if ((err = fopen_s( &pFile, szFile, TEXT("wb") )) !=0 )
	{
		MessageBox(AfxGetMainWnd()->GetSafeHwnd(), TEXT("Unable to open file for Saving"), TEXT("File Error!"), MB_OK );
		return;
	}

	// Write File
	fwrite(lpLoadedFile, 1, 0x10000, pFile);
	fclose(pFile);
}
//========================================================================================================
