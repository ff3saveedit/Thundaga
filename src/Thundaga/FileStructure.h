// FileStructure.h : header file
//

#pragma once
#include "stdafx.h"
#include "Digits.h"
#include "SaveMgr.h"
#include "Thundaga.h"
#include "ThundagaDlg.h"
//========================================================================================================
typedef unsigned int uint;
typedef unsigned short ushort;
//========================================================================================================
#pragma pack(push, 1)
//========================================================================================================
struct sJobTypes
{
	ushort Battle_Command;
	uint JobIndex;
	char szJobName[0x18];
};
//========================================================================================================
struct sSimpleTable
{
	int iStart;
	int iSize;
};
//========================================================================================================
struct sItemTable
{
	uint	Picture;
	ushort	ItemDigit;
	char	szDigitName[0x18];
};
//========================================================================================================
struct sDigitLookup
{
	ushort ItemDigit;
	char szDigitName[0x18];
};
//========================================================================================================
struct sItemSlot
{
	ushort ItemDigit;
	ushort Quantity;
};
//========================================================================================================
struct sJobInfo
{
	byte Level;
	byte SavedExperience;
	byte z_UnknownA[0x12];
};
//========================================================================================================
struct sCharacterBlock
{
	byte		bEnabled;
	char		Name[0x0D];
	byte        Player;
	byte		Level;
	uint		Experience;
	uint		z_UnknownA;
	uint		CurrentHP;
	uint		MaximumHP;
	byte		z_UnknownB[0x22];
	byte		BattlePosition;
	byte		CurrentStatus;
	byte		z_UnknownC[0x42];
	ushort		R_HandDigit;
	byte		bR_HandEquipped;
	byte		z_UnknownD;
	ushort		L_HandDigit;
	byte		bL_HandEquipped;
	byte		z_UnknownE;
	ushort		HeadDigit;
	byte		bHeadEquipped;
	byte		z_UnknownF;
	ushort		BodydDigit;
	byte		bBodyEquipped;
	byte		z_UnknownG;
	ushort		ArmsDigit;
	byte		bArmsEquipped;
	byte		z_UnknownH;
	ushort		z_UnknownI;
	sItemSlot	MagicSlots[0x18];
	byte		CurrentJob;
	byte		z_UnknwonJ[0x07];
	sJobInfo	Jobs[0x17];
	byte		z_UnknownK[0x03];
	ushort		Battle_Command;
	byte		z_UnknownL[0x13];
	uint		Battle_Transition;
};
//========================================================================================================
struct sSaveSlot
{
	byte FileHeader[0x1C];
	uint CheckSum;
	ushort SaveSize;
	byte z_PaddingA[0x0E];
	byte SaveHeader[0x18];
	byte z_UnknownA[0x08];
	byte WifiMailSent;
	byte z_UnknownB[0x1F];
	sCharacterBlock Char[0x04];
	byte z_UnknownC[0x08];
	sItemSlot Items[0x180];
	sItemSlot KeyItems[0x40];
	sItemSlot ChocoStore[0x180];
	uint TotalGil;
	uint PlayTime;
	byte z_UnknownD[0x21E0];
};
//========================================================================================================
struct sSaveFile
{
	sSaveSlot Slot1;
	sSaveSlot Slot2;
	sSaveSlot Slot3;
	sSaveSlot QuickSave;
	byte z_Unknwon[0x13C0];
};
//========================================================================================================
#pragma pack(pop)
//========================================================================================================
extern sSaveSlot *pSlot;
extern sSaveFile *pSaveFile;
//========================================================================================================