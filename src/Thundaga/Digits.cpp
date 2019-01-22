//========================================================================================================
// Digits.cpp : implementation file
//========================================================================================================
#include "stdafx.h"
#include "Digits.h"
#include "Thundaga.h"
#include "ThundagaDlg.h"
//========================================================================================================
sDigitLookup tblArms[ARMS_SIZE];
sDigitLookup tblBody[ARMOR_SIZE];
sDigitLookup tblHead[HEADGEAR_SIZE];
sDigitLookup tblHands[WEAPONS_SIZE+SHIELDS_SIZE];
sDigitLookup tblMagicLv1[(ALL_MAGIC_SIZE*2)+1];	// White Magic Lv1 + Black Magic Lvl1 + Summon Lvl1
sDigitLookup tblMagicLv2[(ALL_MAGIC_SIZE*2)+1];
sDigitLookup tblMagicLv3[(ALL_MAGIC_SIZE*2)+1];
sDigitLookup tblMagicLv4[(ALL_MAGIC_SIZE*2)+1];
sDigitLookup tblMagicLv5[(ALL_MAGIC_SIZE*2)+1];
sDigitLookup tblMagicLv6[(ALL_MAGIC_SIZE*2)+1];
sDigitLookup tblMagicLv7[(ALL_MAGIC_SIZE*2)+1];
sDigitLookup tblMagicLv8[(ALL_MAGIC_SIZE*2)+1];
//========================================================================================================
void BuildTables()
{
	int i = 0;
	
	// Arms (Gloves)
	TABLE_FOR(ARMS_START, ARMS_SIZE)
	{
		tblArms[i-ARMS_START].ItemDigit = ItemTable[i].ItemDigit;
		strcpy_s(tblArms[i-ARMS_START].szDigitName, _countof(ItemTable[0].szDigitName), ItemTable[i].szDigitName);
	}

	// Right Hand (Weapons + Shields)
	TABLE_FOR(WEAPONS_START, WEAPONS_SIZE+SHIELDS_SIZE)
	{
		tblHands[i-WEAPONS_START].ItemDigit = ItemTable[i].ItemDigit;
		strcpy_s(tblHands[i-WEAPONS_START].szDigitName, _countof(ItemTable[0].szDigitName), ItemTable[i].szDigitName);
	}	

	// Body Armor
	TABLE_FOR(ARMOR_START, ARMOR_SIZE)
	{
		tblBody[i-ARMOR_START].ItemDigit = ItemTable[i].ItemDigit;
		strcpy_s(tblBody[i-ARMOR_START].szDigitName, _countof(ItemTable[0].szDigitName), ItemTable[i].szDigitName);
	}

	// Head Gear
	TABLE_FOR(HEADGEAR_START, HEADGEAR_SIZE)
	{
		tblHead[i-HEADGEAR_START].ItemDigit = ItemTable[i].ItemDigit;
		strcpy_s(tblHead[i-HEADGEAR_START].szDigitName, _countof(ItemTable[0].szDigitName), ItemTable[i].szDigitName);
	}

	// Magic Level 1
	TABLE_FOR(WHITE_MAGIC_LV1_START, ALL_MAGIC_SIZE)
	{
		tblMagicLv1[i-WHITE_MAGIC_LV1_START].ItemDigit = ItemTable[i].ItemDigit;
		strcpy_s(tblMagicLv1[i-WHITE_MAGIC_LV1_START].szDigitName, _countof(ItemTable[0].szDigitName), ItemTable[i].szDigitName);
	}
	TABLE_FOR(BLACK_MAGIC_LV1_START, ALL_MAGIC_SIZE)
	{
		tblMagicLv1[(i-BLACK_MAGIC_LV1_START)+ALL_MAGIC_SIZE].ItemDigit = ItemTable[i].ItemDigit;
		strcpy_s(tblMagicLv1[(i-BLACK_MAGIC_LV1_START)+ALL_MAGIC_SIZE].szDigitName, _countof(ItemTable[0].szDigitName), ItemTable[i].szDigitName);
	}
	tblMagicLv1[(ALL_MAGIC_SIZE*2)].ItemDigit = ItemTable[SUMMON_LV1].ItemDigit;
	strcpy_s(tblMagicLv1[(ALL_MAGIC_SIZE*2)].szDigitName, _countof(ItemTable[0].szDigitName), ItemTable[SUMMON_LV1].szDigitName);

	// Magic Level 2
	TABLE_FOR(WHITE_MAGIC_LV2_START, ALL_MAGIC_SIZE)
	{
		tblMagicLv2[i-WHITE_MAGIC_LV2_START].ItemDigit = ItemTable[i].ItemDigit;
		strcpy_s(tblMagicLv2[i-WHITE_MAGIC_LV2_START].szDigitName, _countof(ItemTable[0].szDigitName), ItemTable[i].szDigitName);
	}
	TABLE_FOR(BLACK_MAGIC_LV2_START, ALL_MAGIC_SIZE)
	{
		tblMagicLv2[(i-BLACK_MAGIC_LV2_START)+ALL_MAGIC_SIZE].ItemDigit = ItemTable[i].ItemDigit;
		strcpy_s(tblMagicLv2[(i-BLACK_MAGIC_LV2_START)+ALL_MAGIC_SIZE].szDigitName, _countof(ItemTable[0].szDigitName), ItemTable[i].szDigitName);
	}
	tblMagicLv2[(ALL_MAGIC_SIZE*2)].ItemDigit = ItemTable[SUMMON_LV2].ItemDigit;
	strcpy_s(tblMagicLv2[(ALL_MAGIC_SIZE*2)].szDigitName, _countof(ItemTable[0].szDigitName), ItemTable[SUMMON_LV2].szDigitName);

	// Magic Level 3
	TABLE_FOR(WHITE_MAGIC_LV3_START, ALL_MAGIC_SIZE)
	{
		tblMagicLv3[i-WHITE_MAGIC_LV3_START].ItemDigit = ItemTable[i].ItemDigit;
		strcpy_s(tblMagicLv3[i-WHITE_MAGIC_LV3_START].szDigitName, _countof(ItemTable[0].szDigitName), ItemTable[i].szDigitName);
	}
	TABLE_FOR(BLACK_MAGIC_LV3_START, ALL_MAGIC_SIZE)
	{
		tblMagicLv3[(i-BLACK_MAGIC_LV3_START)+ALL_MAGIC_SIZE].ItemDigit = ItemTable[i].ItemDigit;
		strcpy_s(tblMagicLv3[(i-BLACK_MAGIC_LV3_START)+ALL_MAGIC_SIZE].szDigitName, _countof(ItemTable[0].szDigitName), ItemTable[i].szDigitName);
	}
	tblMagicLv3[(ALL_MAGIC_SIZE*2)].ItemDigit = ItemTable[SUMMON_LV3].ItemDigit;
	strcpy_s(tblMagicLv3[(ALL_MAGIC_SIZE*2)].szDigitName, _countof(ItemTable[0].szDigitName), ItemTable[SUMMON_LV3].szDigitName);

	// Magic Level 4
	TABLE_FOR(WHITE_MAGIC_LV4_START, ALL_MAGIC_SIZE)
	{
		tblMagicLv4[i-WHITE_MAGIC_LV4_START].ItemDigit = ItemTable[i].ItemDigit;
		strcpy_s(tblMagicLv4[i-WHITE_MAGIC_LV4_START].szDigitName, _countof(ItemTable[0].szDigitName), ItemTable[i].szDigitName);
	}
	TABLE_FOR(BLACK_MAGIC_LV4_START, ALL_MAGIC_SIZE)
	{
		tblMagicLv4[(i-BLACK_MAGIC_LV4_START)+ALL_MAGIC_SIZE].ItemDigit = ItemTable[i].ItemDigit;
		strcpy_s(tblMagicLv4[(i-BLACK_MAGIC_LV4_START)+ALL_MAGIC_SIZE].szDigitName, _countof(ItemTable[0].szDigitName), ItemTable[i].szDigitName);
	}
	tblMagicLv4[(ALL_MAGIC_SIZE*2)].ItemDigit = ItemTable[SUMMON_LV4].ItemDigit;
	strcpy_s(tblMagicLv4[(ALL_MAGIC_SIZE*2)].szDigitName, _countof(ItemTable[0].szDigitName), ItemTable[SUMMON_LV4].szDigitName);

	// Magic Level 5
	TABLE_FOR(WHITE_MAGIC_LV5_START, ALL_MAGIC_SIZE)
	{
		tblMagicLv5[i-WHITE_MAGIC_LV5_START].ItemDigit = ItemTable[i].ItemDigit;
		strcpy_s(tblMagicLv5[i-WHITE_MAGIC_LV5_START].szDigitName, _countof(ItemTable[0].szDigitName), ItemTable[i].szDigitName);
	}
	TABLE_FOR(BLACK_MAGIC_LV5_START, ALL_MAGIC_SIZE)
	{
		tblMagicLv5[(i-BLACK_MAGIC_LV5_START)+ALL_MAGIC_SIZE].ItemDigit = ItemTable[i].ItemDigit;
		strcpy_s(tblMagicLv5[(i-BLACK_MAGIC_LV5_START)+ALL_MAGIC_SIZE].szDigitName, _countof(ItemTable[0].szDigitName), ItemTable[i].szDigitName);
	}
	tblMagicLv5[(ALL_MAGIC_SIZE*2)].ItemDigit = ItemTable[SUMMON_LV5].ItemDigit;
	strcpy_s(tblMagicLv5[(ALL_MAGIC_SIZE*2)].szDigitName, _countof(ItemTable[0].szDigitName), ItemTable[SUMMON_LV5].szDigitName);

	// Magic Level 6
	TABLE_FOR(WHITE_MAGIC_LV6_START, ALL_MAGIC_SIZE)
	{
		tblMagicLv6[i-WHITE_MAGIC_LV6_START].ItemDigit = ItemTable[i].ItemDigit;
		strcpy_s(tblMagicLv6[i-WHITE_MAGIC_LV6_START].szDigitName, _countof(ItemTable[0].szDigitName), ItemTable[i].szDigitName);
	}
	TABLE_FOR(BLACK_MAGIC_LV6_START, ALL_MAGIC_SIZE)
	{
		tblMagicLv6[(i-BLACK_MAGIC_LV6_START)+ALL_MAGIC_SIZE].ItemDigit = ItemTable[i].ItemDigit;
		strcpy_s(tblMagicLv6[(i-BLACK_MAGIC_LV6_START)+ALL_MAGIC_SIZE].szDigitName, _countof(ItemTable[0].szDigitName), ItemTable[i].szDigitName);
	}
	tblMagicLv6[(ALL_MAGIC_SIZE*2)].ItemDigit = ItemTable[SUMMON_LV6].ItemDigit;
	strcpy_s(tblMagicLv6[(ALL_MAGIC_SIZE*2)].szDigitName, _countof(ItemTable[0].szDigitName), ItemTable[SUMMON_LV6].szDigitName);

	// Magic Level 7
	TABLE_FOR(WHITE_MAGIC_LV7_START, ALL_MAGIC_SIZE)
	{
		tblMagicLv7[i-WHITE_MAGIC_LV7_START].ItemDigit = ItemTable[i].ItemDigit;
		strcpy_s(tblMagicLv7[i-WHITE_MAGIC_LV7_START].szDigitName, _countof(ItemTable[0].szDigitName), ItemTable[i].szDigitName);
	}
	TABLE_FOR(BLACK_MAGIC_LV7_START, ALL_MAGIC_SIZE)
	{
		tblMagicLv7[(i-BLACK_MAGIC_LV7_START)+ALL_MAGIC_SIZE].ItemDigit = ItemTable[i].ItemDigit;
		strcpy_s(tblMagicLv7[(i-BLACK_MAGIC_LV7_START)+ALL_MAGIC_SIZE].szDigitName, _countof(ItemTable[0].szDigitName), ItemTable[i].szDigitName);
	}
	tblMagicLv7[(ALL_MAGIC_SIZE*2)].ItemDigit = ItemTable[SUMMON_LV7].ItemDigit;
	strcpy_s(tblMagicLv7[(ALL_MAGIC_SIZE*2)].szDigitName, _countof(ItemTable[0].szDigitName), ItemTable[SUMMON_LV7].szDigitName);

	// Magic Level 8
	TABLE_FOR(WHITE_MAGIC_LV8_START, ALL_MAGIC_SIZE)
	{
		tblMagicLv8[i-WHITE_MAGIC_LV8_START].ItemDigit = ItemTable[i].ItemDigit;
		strcpy_s(tblMagicLv8[i-WHITE_MAGIC_LV8_START].szDigitName, _countof(ItemTable[0].szDigitName), ItemTable[i].szDigitName);
	}
	TABLE_FOR(BLACK_MAGIC_LV8_START, ALL_MAGIC_SIZE)
	{
		tblMagicLv8[(i-BLACK_MAGIC_LV8_START)+ALL_MAGIC_SIZE].ItemDigit = ItemTable[i].ItemDigit;
		strcpy_s(tblMagicLv8[(i-BLACK_MAGIC_LV8_START)+ALL_MAGIC_SIZE].szDigitName, _countof(ItemTable[0].szDigitName), ItemTable[i].szDigitName);
	}
	tblMagicLv8[(ALL_MAGIC_SIZE*2)].ItemDigit = ItemTable[SUMMON_LV8].ItemDigit;
	strcpy_s(tblMagicLv8[(ALL_MAGIC_SIZE*2)].szDigitName, _countof(ItemTable[0].szDigitName), ItemTable[SUMMON_LV8].szDigitName);
};
//========================================================================================================
int iGetIndexFromDigit(sDigitLookup pLook[], int iSize, int iDigit)
{
	int i;
	for (i=0; i<iSize; i++)
	{
		if (pLook[i].ItemDigit == iDigit)
		{
			return i;
		}
	}
	return -1;
}
//========================================================================================================
int iGetIndexFromDigit(sItemTable pLook[], int iSize, int iDigit)
{
	int i;
	for (i=0; i<iSize; i++)
	{
		if (pLook[i].ItemDigit == iDigit)
		{
			return i;
		}
	}
	return -1;
}
//========================================================================================================
int iGetIndexFromString(sItemTable pLook[], int iSize, LPCSTR szItem)
{
	int i;
	for (i=0; i<iSize; i++)
	{
		if (_stricmp(pLook[i].szDigitName, szItem) == 0)
		{
			return i;
		}
	}
	return -1;
}
//========================================================================================================
int iGetDigitFromString(sItemTable pLook[], int iSize, LPCSTR szItem)
{
	int i;
	for (i=0; i<iSize; i++)
	{
		if (_stricmp(pLook[i].szDigitName, szItem) == 0)
		{
			return pLook[i].ItemDigit;
		}
	}
	return -1;
}
//========================================================================================================
char *szGetStringFromDigit(sItemTable pLook[], int iSize, int iDigit)
{
	int i;
	for (i=0; i<iSize; i++)
	{
		if (pLook[i].ItemDigit == iDigit)
		{
			return pLook[i].szDigitName;
		}
	}
	return "NOT FOUND";
}
//========================================================================================================