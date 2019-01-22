//========================================================================================================
#pragma once
#include "afxcmn.h"
#include "afxwin.h"
//========================================================================================================
class CSaveMgr
{
	public:
		int iCurrent;
		bool bChanged;
		char *lpLoadedFile;

	public:
		bool bSaveM3;
		bool NotifyChanges(bool bExit);
		DWORD GetCheckSum(byte *pData);
		bool bLoadDsXFile(TCHAR *szFile);
		bool bLoadSaveFile(TCHAR *szFile);

		
	private:
		FILE *lpOrgFile;
		void DoSave();
		void SaveDSXFile(TCHAR *szFile);
		void SaveM3File(TCHAR *szFile);
		void SaveG6SCFile(TCHAR *szFile);
		void SaveRawFile(TCHAR *szFile);	
};
//========================================================================================================