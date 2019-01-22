// Digits.h : header file
//
#pragma once
#include "stdafx.h"
#include <stdlib.h>
#include "SaveMgr.h"
#include "Thundaga.h"
#include "ThundagaDlg.h"
#include "FileStructure.h"
//========================================================================================================
#define JOB_COUNT 23					// Amount of Jobs
enum { LUNETH = 0, ARC, REFIA, INGUS }; // Characters
//========================================================================================================
// Items Location Inside ItemTable
//========================================================================================================
#define ITEMS_START			0
#define ITEMS_SIZE			36
#define KEY_ITEMS_START		36
#define KEY_ITEMS_SIZE		41
#define WHITE_MAGIC_START	77
#define WHITE_MAGIC_SIZE	24
#define BLACK_MAGIC_START	101	
#define BLACK_MAGIC_SIZE	24
#define SUMMONS_START		125
#define SUMMONS_SIZE		8
#define KNIFES_START		159
#define KNIFES_SIZE			11
#define SWORDS_START		170
#define SWORDS_SIZE			21
#define DARK_SWORDS_START	191
#define DARK_SWORDS_SIZE	6
#define STAVES_START		197
#define STAVES_SIZE			9
#define RODS_START			206
#define RODS_SIZE			8
#define BOWS_START			214
#define BOWS_SIZE			9
#define ARROWS_START		223
#define ARROWS_SIZE			11
#define BOOKS_START			234
#define BOOKS_SIZE			8
#define CLAWS_START			242
#define CLAWS_SIZE			12
#define HAMMERS_START		254
#define HAMMERS_SIZE		6
#define AXES_START			260
#define AXES_SIZE			7
#define SPEARS_START		267	
#define SPEARS_SIZE			9
#define THROWABLES_START	276
#define THROWABLES_SIZE		5
#define BELLS_START			281
#define BELLS_SIZE			4
#define HARPS_START			285
#define HARPS_SIZE			5
#define SHIELDS_START		290
#define SHIELDS_SIZE		10
#define HEADGEAR_START		300
#define HEADGEAR_SIZE		18
#define ARMOR_START			318
#define ARMOR_SIZE			29
#define ACCESSORIES_START	347
#define ACCESSORIES_SIZE	16
#define ARMS_START			347
#define ARMS_SIZE			16
#define WEAPONS_START		159
#define WEAPONS_SIZE		131
#define WEAPON_SHIELD_START 159
#define WEAPON_SHIELD_SIZE (WEAPONS_SIZE+SHIELDS_SIZE) // Combo of Weapons + Shields for Equipment (Hands)
//========================================================================================================
// Image Numbers
//========================================================================================================
enum {	IMAGE_ITEMS = 0,	IMAGE_WHITE_MAGIC,	IMAGE_BLACK_MAGIC,	IMAGE_SUMMONS, 
		IMAGE_KNIFES,		IMAGE_SWORDS,		IMAGE_DARK_SWORDS,	IMAGE_STAVES,		
		IMAGE_RODS,			IMAGE_BOWS,			IMAGE_ARROWS,		IMAGE_BOOKS,
		IMAGE_CLAWS,		IMAGE_HAMMERS,		IMAGE_AXES,			IMAGE_SPEARS,	
		IMAGE_THROWABLES,	IMAGE_BELLS,		IMAGE_HARPS,		IMAGE_SHIELDS,		
		IMAGE_HEADGEAR,		IMAGE_ARMOR,		IMAGE_ACCESSORIES,	IMAGE_NONE };
//========================================================================================================
// Magic Location inside ItemTable
//========================================================================================================
#define ALL_MAGIC_SIZE	3
#define WHITE_MAGIC_LV1_START	77
#define WHITE_MAGIC_LV2_START	80
#define WHITE_MAGIC_LV3_START	83
#define WHITE_MAGIC_LV4_START	86
#define WHITE_MAGIC_LV5_START	89
#define WHITE_MAGIC_LV6_START	92
#define WHITE_MAGIC_LV7_START	95
#define WHITE_MAGIC_LV8_START	98
#define BLACK_MAGIC_LV1_START	101
#define BLACK_MAGIC_LV2_START	104
#define BLACK_MAGIC_LV3_START	107
#define BLACK_MAGIC_LV4_START	110
#define BLACK_MAGIC_LV5_START	113
#define BLACK_MAGIC_LV6_START	116
#define BLACK_MAGIC_LV7_START	119
#define BLACK_MAGIC_LV8_START	122
#define SUMMON_LV1				125
#define SUMMON_LV2				126
#define SUMMON_LV3				127
#define SUMMON_LV4				128
#define SUMMON_LV5				129
#define SUMMON_LV6				130
#define SUMMON_LV7				131
#define SUMMON_LV8				132
//========================================================================================================
// Status Effects
//========================================================================================================
#define PETRIFIED	0x02 
#define TOAD		0x04 
#define SILENCE		0x08 
#define MINI		0x10 
#define BLIND		0x20 
#define POISON		0x40
//========================================================================================================
#define IsToad(dw)		(((dw) & (TOAD)) != 0L)
#define IsMini(dw)		(((dw) & (MINI)) != 0L)
#define IsBlind(dw)		(((dw) & (BLIND)) != 0L)
#define IsPoison(dw)	(((dw) & (POISON)) != 0L)
#define IsSilence(dw)	(((dw) & (SILENCE)) != 0L)
#define IsPetrified(dw)	(((dw) & (PETRIFIED)) != 0L)
//========================================================================================================
#define TABLE_FOR(x,y)	for (i=x; i<(x+y); i++)
#define DIGIT_FOR(x,y)	for (i=x+1; i<(x+y)+1; i++) // Start + 1 to include "<EMPTY>"
//========================================================================================================
extern CSaveMgr SaveMgr;
//========================================================================================================
static sJobTypes JobTable[] =
{
	{0x032E, 0x00, "Freelancer"},
	{0x032E, 0x01, "Onion Knight"},
	{0x030B, 0x02, "Warrior"},
	{0x0324, 0x03, "Monk"},
	{0x0306, 0x04, "White Mage"},
	{0x0305, 0x05, "Black Mage"},
	{0x032E, 0x06, "Red Mage"},
	{0x0319, 0x07, "Ranger"},
	{0x1506, 0x08, "Knight"},
	{0x0807, 0x09, "Thief"},
	{0x1A2E, 0x0A, "Scholar"},
	{0x0320, 0x0B, "Geomancer"},
	{0x031D, 0x0C, "Dragoon"},
	{0x032D, 0x0D, "Viking"},
	{0x031E, 0x0E, "Dark Knight"},
	{0x030D, 0x0F, "Evoker"},
	{0x0312, 0x10, "Bard"},
	{0x0323, 0x11, "Black Belt"},
	{0x0306, 0x12, "Devout"},
	{0x0305, 0x13, "Magus"},
	{0x030D, 0x14, "Summoner"},
	{0x032E, 0x15, "Sage"},
	{0x0328, 0x16, "Ninja"}
};
//========================================================================================================
static sDigitLookup MagicTable[] =
{
	{ 0x0FA1, "Cure" },
	{ 0x0FA2, "Poisona" },
	{ 0x0FA3, "Sight" },
	{ 0x1005, "Fire" },
	{ 0x1006, "Blizzard" },
	{ 0x1007, "Sleep" },
	{ 0x1069, "Escape" },
	{ 0x0FA4, "Aero" },
	{ 0x0FA5, "Toad" },
	{ 0x0FA6, "Mini" },
	{ 0x1008, "Thunder" },
	{ 0x1009, "Poison" },
	{ 0x100A, "Blind" },
	{ 0x106A, "Icen" },
	{ 0x0FA7, "Cura" },
	{ 0x0FA8, "Teleport" },
	{ 0x0FA9, "Blindna" },
	{ 0x100B, "Fira" },
	{ 0x100C, "Blizzara" },
	{ 0x100D, "Thundara" },
	{ 0x106B, "Spark" },
	{ 0x0FAA, "Libra" },
	{ 0x0FAB, "Confuse" },
	{ 0x0FAC, "Silence" },
	{ 0x100E, "Break" },
	{ 0x100F, "Blizzaga" },
	{ 0x1010, "Shade" },
	{ 0x106C, "Heatra" },
	{ 0x0FAD, "Curaga" },
	{ 0x0FAE, "Raise" },
	{ 0x0FAF, "Protect" },
	{ 0x1011, "Thundaga" },
	{ 0x1012, "Raze" },
	{ 0x1013, "Erase" },
	{ 0x106D, "Hyper" },
	{ 0x0FB0, "Aeroga" },
	{ 0x0FB1, "Stona" },
	{ 0x0FB2, "Haste" },
	{ 0x1014, "Firaga" },
	{ 0x1015, "Bio" },
	{ 0x1016, "Warp" },
	{ 0x106E, "Catastro" },
	{ 0x0FB3, "Curaja" },
	{ 0x0FB4, "Esuna" },
	{ 0x0FB5, "Reflect" },
	{ 0x1017, "Quake" },
	{ 0x1018, "Breakga" },
	{ 0x1019, "Drain" },
	{ 0x106F, "Leviath" },
	{ 0x0FB6, "Tornado" },
	{ 0x0FB7, "Arise" },
	{ 0x0FB8, "Holy" },
	{ 0x101A, "Flare" },
	{ 0x101B, "Death" },
	{ 0x101C, "Meteor" },
	{ 0x1070, "Bahamur" }
};
//========================================================================================================
static sItemTable ItemTable[] = 
{
	{ IMAGE_ITEMS, 0x1389, "Potion" },
	{ IMAGE_ITEMS, 0x138A, "Hi-Potion" },
	{ IMAGE_ITEMS, 0x138B, "Antidote" },
	{ IMAGE_ITEMS, 0x138C, "Eye Drops" },
	{ IMAGE_ITEMS, 0x138D, "Echo Herbs" },
	{ IMAGE_ITEMS, 0x138E, "Gold Needle" },
	{ IMAGE_ITEMS, 0x138F, "Maiden's Kiss" },
	{ IMAGE_ITEMS, 0x1390, "Mallet" },
	{ IMAGE_ITEMS, 0x1391, "Ottershroom" },
	{ IMAGE_ITEMS, 0x1392, "Phoenix Down" },
	{ IMAGE_ITEMS, 0x1393, "Elixir" },
	{ IMAGE_ITEMS, 0x1394, "Gnomish Bread" },
	{ IMAGE_ITEMS, 0x1395, "Magic Key" },
	{ IMAGE_ITEMS, 0x1396, "Gysahl Greens" },
	{ IMAGE_ITEMS, 0x13ED, "Antarctic Wind" },
	{ IMAGE_ITEMS, 0x13EE, "Zeus's Wrath" },
	{ IMAGE_ITEMS, 0x13EF, "Bomb Fragment" },
	{ IMAGE_ITEMS, 0x13F0, "Lamia Scale" },
	{ IMAGE_ITEMS, 0x13F1, "Bacchus's Cider" },
	{ IMAGE_ITEMS, 0x13F2, "Tranquilizer" },
	{ IMAGE_ITEMS, 0x13F3, "Bomb Arm" },
	{ IMAGE_ITEMS, 0x13F4, "Arctic Wind" },
	{ IMAGE_ITEMS, 0x13F5, "Heavenly Wrath" },
	{ IMAGE_ITEMS, 0x13F6, "Earthen Drums" },
	{ IMAGE_ITEMS, 0x13F7, "Turtle Shell" },
	{ IMAGE_ITEMS, 0x13F8, "Angel's Sigh" },
	{ IMAGE_ITEMS, 0x13F9, "Black Hole" },
	{ IMAGE_ITEMS, 0x13FA, "Black Musk" },
	{ IMAGE_ITEMS, 0x13FB, "Lilith's Kiss" },
	{ IMAGE_ITEMS, 0x13FC, "Raven's Yawn" },
	{ IMAGE_ITEMS, 0x13FD, "Shell Breaker" },
	{ IMAGE_ITEMS, 0x13FE, "Silence Seal" },
	{ IMAGE_ITEMS, 0x13FF, "Sheep Pillow" },
	{ IMAGE_ITEMS, 0x1400, "Shining Curtain" },
	{ IMAGE_ITEMS, 0x1401, "Chocobo's Wrath" },
	{ IMAGE_ITEMS, 0x1402, "White Musk" },
	{ IMAGE_ITEMS, 0x1451, "Nepto Eye" },
	{ IMAGE_ITEMS, 0x1452, "Horn of Ice" },
	{ IMAGE_ITEMS, 0x1453, "Wheel of Time" },
	{ IMAGE_ITEMS, 0x1454, "Noah's Lute" },
	{ IMAGE_ITEMS, 0x1455, "Eureka Key" },
	{ IMAGE_ITEMS, 0x1456, "Syrcus Key" },
	{ IMAGE_ITEMS, 0x1457, "Fang of Water" },
	{ IMAGE_ITEMS, 0x1458, "Fang of Wind" },
	{ IMAGE_ITEMS, 0x1459, "Fang of Fire" },
	{ IMAGE_ITEMS, 0x145A, "Fang of Earth" },
	{ IMAGE_ITEMS, 0x145B, "Chain Key" },
	{ IMAGE_ITEMS, 0x145C, "Folding Canoe" },
	{ IMAGE_ITEMS, 0x145D, "Levigrass Shoes" },
	{ IMAGE_ITEMS, 0x145E, "Sara's Pendant" },
	{ IMAGE_ITEMS, 0x145F, "Sara's Pendant" },
	{ IMAGE_ITEMS, 0x1460, "Unknown Metal" },
	{ IMAGE_ITEMS, 0x1461, "Orichalcum" },
	{ IMAGE_ITEMS, 0x1462, "Freelancer Card" },
	{ IMAGE_ITEMS, 0x1463, "Onion Knight Card" },
	{ IMAGE_ITEMS, 0x1464, "Warrior Card" },
	{ IMAGE_ITEMS, 0x1465, "Monk Card" },
	{ IMAGE_ITEMS, 0x1466, "White Mage Card" },
	{ IMAGE_ITEMS, 0x1467, "Black Mage Card" },
	{ IMAGE_ITEMS, 0x1468, "Red Mage Card" },
	{ IMAGE_ITEMS, 0x1469, "Ranger Card" },
	{ IMAGE_ITEMS, 0x146A, "Knight Card" },
	{ IMAGE_ITEMS, 0x146B, "Thief Card" },
	{ IMAGE_ITEMS, 0x146C, "Scholar Card" },
	{ IMAGE_ITEMS, 0x146D, "Geomancer Card" },
	{ IMAGE_ITEMS, 0x146E, "Dragoon Card" },
	{ IMAGE_ITEMS, 0x146F, "Viking Card" },
	{ IMAGE_ITEMS, 0x1470, "Dark Knight Card" },
	{ IMAGE_ITEMS, 0x1471, "Evoker Card" },
	{ IMAGE_ITEMS, 0x1472, "Bard Card" },
	{ IMAGE_ITEMS, 0x1473, "Black Belt Card" },
	{ IMAGE_ITEMS, 0x1474, "Devout Card" },
	{ IMAGE_ITEMS, 0x1475, "Magus Card" },
	{ IMAGE_ITEMS, 0x1476, "Summoner Card" },
	{ IMAGE_ITEMS, 0x1477, "Sage Card" },
	{ IMAGE_ITEMS, 0x1478, "Ninja Card" },
	{ IMAGE_ITEMS, 0x1479, "Metal Card" },
	{ IMAGE_WHITE_MAGIC, 0x0FA1, "Cure" },
	{ IMAGE_WHITE_MAGIC, 0x0FA2, "Poisona" },
	{ IMAGE_WHITE_MAGIC, 0x0FA3, "Sight" },
	{ IMAGE_WHITE_MAGIC, 0x0FA4, "Aero" },
	{ IMAGE_WHITE_MAGIC, 0x0FA5, "Toad" },
	{ IMAGE_WHITE_MAGIC, 0x0FA6, "Mini" },
	{ IMAGE_WHITE_MAGIC, 0x0FA7, "Cura" },
	{ IMAGE_WHITE_MAGIC, 0x0FA8, "Teleport" },
	{ IMAGE_WHITE_MAGIC, 0x0FA9, "Blindna" },
	{ IMAGE_WHITE_MAGIC, 0x0FAA, "Libra" },
	{ IMAGE_WHITE_MAGIC, 0x0FAB, "Confuse" },
	{ IMAGE_WHITE_MAGIC, 0x0FAC, "Silence" },
	{ IMAGE_WHITE_MAGIC, 0x0FAD, "Curaga" },
	{ IMAGE_WHITE_MAGIC, 0x0FAE, "Raise" },
	{ IMAGE_WHITE_MAGIC, 0x0FAF, "Protect" },
	{ IMAGE_WHITE_MAGIC, 0x0FB0, "Aeroga" },
	{ IMAGE_WHITE_MAGIC, 0x0FB1, "Stona" },
	{ IMAGE_WHITE_MAGIC, 0x0FB2, "Haste" },
	{ IMAGE_WHITE_MAGIC, 0x0FB3, "Curaja" },
	{ IMAGE_WHITE_MAGIC, 0x0FB4, "Esuna" },
	{ IMAGE_WHITE_MAGIC, 0x0FB5, "Reflect" },
	{ IMAGE_WHITE_MAGIC, 0x0FB6, "Tornado" },
	{ IMAGE_WHITE_MAGIC, 0x0FB7, "Arise" },
	{ IMAGE_WHITE_MAGIC, 0x0FB8, "Holy" },
	{ IMAGE_BLACK_MAGIC, 0x1005, "Fire" },
	{ IMAGE_BLACK_MAGIC, 0x1006, "Blizzard" },
	{ IMAGE_BLACK_MAGIC, 0x1007, "Sleep" },
	{ IMAGE_BLACK_MAGIC, 0x1008, "Thunder" },
	{ IMAGE_BLACK_MAGIC, 0x1009, "Poison" },
	{ IMAGE_BLACK_MAGIC, 0x100A, "Blind" },
	{ IMAGE_BLACK_MAGIC, 0x100B, "Fira" },
	{ IMAGE_BLACK_MAGIC, 0x100C, "Blizzara" },
	{ IMAGE_BLACK_MAGIC, 0x100D, "Thundara" },
	{ IMAGE_BLACK_MAGIC, 0x100E, "Break" },
	{ IMAGE_BLACK_MAGIC, 0x100F, "Blizzaga" },
	{ IMAGE_BLACK_MAGIC, 0x1010, "Shade" },
	{ IMAGE_BLACK_MAGIC, 0x1011, "Thundaga" },
	{ IMAGE_BLACK_MAGIC, 0x1012, "Raze" },
	{ IMAGE_BLACK_MAGIC, 0x1013, "Erase" },
	{ IMAGE_BLACK_MAGIC, 0x1014, "Firaga" },
	{ IMAGE_BLACK_MAGIC, 0x1015, "Bio" },
	{ IMAGE_BLACK_MAGIC, 0x1016, "Warp" },
	{ IMAGE_BLACK_MAGIC, 0x1017, "Quake" },
	{ IMAGE_BLACK_MAGIC, 0x1018, "Breakga" },
	{ IMAGE_BLACK_MAGIC, 0x1019, "Drain" },
	{ IMAGE_BLACK_MAGIC, 0x101A, "Flare" },
	{ IMAGE_BLACK_MAGIC, 0x101B, "Death" },
	{ IMAGE_BLACK_MAGIC, 0x101C, "Meteor" },
	{ IMAGE_SUMMONS, 0x1069, "Escape" },
	{ IMAGE_SUMMONS, 0x106A, "Icen" },
	{ IMAGE_SUMMONS, 0x106B, "Spark" },
	{ IMAGE_SUMMONS, 0x106C, "Heatra" },
	{ IMAGE_SUMMONS, 0x106D, "Hyper" },
	{ IMAGE_SUMMONS, 0x106E, "Catastro" },
	{ IMAGE_SUMMONS, 0x106F, "Leviath" },
	{ IMAGE_SUMMONS, 0x1070, "Bahamur" },
	{ IMAGE_ITEMS, 0x1771, "Minne" },
	{ IMAGE_ITEMS, 0x1772, "Minuet" },
	{ IMAGE_ITEMS, 0x1773, "Paeon" },
	{ IMAGE_ITEMS, 0x1774, "Requiem" },
	{ IMAGE_ITEMS, 0x1775, "Elegy" },
	{ IMAGE_ITEMS, 0x1776, "Paeon" },
	{ IMAGE_ITEMS, 0x1777, "Requiem" },
	{ IMAGE_ITEMS, 0x1778, "Etude" },
	{ IMAGE_ITEMS, 0x1965, "Wind Slash" },
	{ IMAGE_ITEMS, 0x1966, "Ice Storm" },
	{ IMAGE_ITEMS, 0x1967, "Magma" },
	{ IMAGE_ITEMS, 0x1968, "Flame Burst" },
	{ IMAGE_ITEMS, 0x1969, "Ice Pillar" },
	{ IMAGE_ITEMS, 0x196A, "Whirlpool" },
	{ IMAGE_ITEMS, 0x196B, "Earthquake" },
	{ IMAGE_ITEMS, 0x196C, "Cave-In" },
	{ IMAGE_ITEMS, 0x196D, "Black Hole" },
	{ IMAGE_ITEMS, 0x196E, "Shadowflare" },
	{ IMAGE_ITEMS, 0x196F, "Earthquake 2" },
	{ IMAGE_ITEMS, 0x1970, "Quicksand" },
	{ IMAGE_ITEMS, 0x1971, "Quicksand 2" },
	{ IMAGE_ITEMS, 0x1972, "Quicksand 3" },
	{ IMAGE_ITEMS, 0x1973, "Quicksand 4" },
	{ IMAGE_ITEMS, 0x1974, "Evil Eye" },
	{ IMAGE_ITEMS, 0x1975, "Evil Eye 2" },
	{ IMAGE_ITEMS, 0x1976, "Evil Eye 3" },
	{ IMAGE_KNIFES, 0x03E9, "Knife" },
	{ IMAGE_KNIFES, 0x03EB, "Dagger" },
	{ IMAGE_KNIFES, 0x03ED, "Mythril Knife" },
	{ IMAGE_KNIFES, 0x03EF, "Spark Dagger" },
	{ IMAGE_KNIFES, 0x03F1, "Main Gauche" },
	{ IMAGE_KNIFES, 0x03F3, "Poison Dagger" },
	{ IMAGE_KNIFES, 0x03F5, "Behemoth Knife" },
	{ IMAGE_KNIFES, 0x03F7, "Air Knife" },
	{ IMAGE_KNIFES, 0x03F9, "Dark Knife" },
	{ IMAGE_KNIFES, 0x03FB, "Lust Dagger" },
	{ IMAGE_KNIFES, 0x03FD, "Gladius" },
	{ IMAGE_SWORDS, 0x044D, "Golden Sword" },
	{ IMAGE_SWORDS, 0x044F, "Long Sword" },
	{ IMAGE_SWORDS, 0x0451, "Wight Slayer" },
	{ IMAGE_SWORDS, 0x0453, "Mythril Sword" },
	{ IMAGE_SWORDS, 0x0455, "Tyrving" },
	{ IMAGE_SWORDS, 0x0457, "Salamander Sword" },
	{ IMAGE_SWORDS, 0x0459, "Freeze Blade" },
	{ IMAGE_SWORDS, 0x045B, "Serpent Sword" },
	{ IMAGE_SWORDS, 0x045D, "Royal Sword" },
	{ IMAGE_SWORDS, 0x045F, "Blood Sword" },
	{ IMAGE_SWORDS, 0x0461, "Ancient's Sword" },
	{ IMAGE_SWORDS, 0x0463, "Defender" },
	{ IMAGE_SWORDS, 0x0465, "Break Blade" },
	{ IMAGE_SWORDS, 0x0467, "Excalibur" },
	{ IMAGE_SWORDS, 0x0468, "Ragnarok" },
	{ IMAGE_SWORDS, 0x0469, "Onion Sword" },
	{ IMAGE_SWORDS, 0x046B, "Adaman Sword" },
	{ IMAGE_SWORDS, 0x046D, "Save The Queen" },
	{ IMAGE_SWORDS, 0x046F, "Onion Blade" },
	{ IMAGE_SWORDS, 0x0471, "Ultimate Weapon" },
	{ IMAGE_SWORDS, 0x0473, "Desch's Sword" },
	{ IMAGE_DARK_SWORDS, 0x047F, "Ashura" },
	{ IMAGE_DARK_SWORDS, 0x0481, "Kotetsu" },
	{ IMAGE_DARK_SWORDS, 0x0483, "Kiku-Ichimonji" },
	{ IMAGE_DARK_SWORDS, 0x0485, "Masamune" },
	{ IMAGE_DARK_SWORDS, 0x0489, "Murakumo" },
	{ IMAGE_DARK_SWORDS, 0x048B, "Muramasa" },
	{ IMAGE_STAVES, 0x04B1, "Staff" },
	{ IMAGE_STAVES, 0x04B3, "Fire Staff" },
	{ IMAGE_STAVES, 0x04B5, "Ice Staff" },
	{ IMAGE_STAVES, 0x04B7, "Light Staff" },
	{ IMAGE_STAVES, 0x04B9, "Golem Staff" },
	{ IMAGE_STAVES, 0x04BB, "Rune Staff" },
	{ IMAGE_STAVES, 0x04BD, "Elder Staff" },
	{ IMAGE_STAVES, 0x04BF, "Holy Wand" },
	{ IMAGE_STAVES, 0x04C1, "Sage Staff" },
	{ IMAGE_RODS, 0x0515, "Mythril Rod" },
	{ IMAGE_RODS, 0x0517, "Wizard Rod" },
	{ IMAGE_RODS, 0x0519, "Fire Rod" },
	{ IMAGE_RODS, 0x051B, "Ice Rod" },
	{ IMAGE_RODS, 0x051D, "Light Rod" },
	{ IMAGE_RODS, 0x051F, "Omnirod" },
	{ IMAGE_RODS, 0x0521, "Lilith Rod" },
	{ IMAGE_RODS, 0x0523, "Millennium Rod" },
	{ IMAGE_BOWS, 0x0579, "Bow" },
	{ IMAGE_BOWS, 0x057B, "Great Bow" },
	{ IMAGE_BOWS, 0x057D, "Killer Bow" },
	{ IMAGE_BOWS, 0x057F, "Rune Bow" },
	{ IMAGE_BOWS, 0x0581, "Selene Bow" },
	{ IMAGE_BOWS, 0x0583, "Yoichi Bow" },
	{ IMAGE_BOWS, 0x0585, "Eurytos Bow" },
	{ IMAGE_BOWS, 0x0587, "Elven Bow" },
	{ IMAGE_BOWS, 0x0589, "Artemis Bow" },
	{ IMAGE_ARROWS, 0x05DD, "Wooden Arrow" },
	{ IMAGE_ARROWS, 0x05DF, "Holy Arrow" },
	{ IMAGE_ARROWS, 0x05E1, "Iron Arrow" },
	{ IMAGE_ARROWS, 0x05E3, "Fire Arrow" },
	{ IMAGE_ARROWS, 0x05E5, "Ice Arrow" },
	{ IMAGE_ARROWS, 0x05E7, "Light Arrow" },
	{ IMAGE_ARROWS, 0x05E9, "Sleep Arrow" },
	{ IMAGE_ARROWS, 0x05EB, "Poison Arrow" },
	{ IMAGE_ARROWS, 0x05ED, "Medusa Arrow" },
	{ IMAGE_ARROWS, 0x05EF, "Magic Arrow" },
	{ IMAGE_ARROWS, 0x05F1, "Yoichi Arrow" },
	{ IMAGE_BOOKS, 0x0641, "Book of Fire" },
	{ IMAGE_BOOKS, 0x0643, "Book of Ice" },
	{ IMAGE_BOOKS, 0x0645, "Book of Light" },
	{ IMAGE_BOOKS, 0x0647, "Tome of Fire" },
	{ IMAGE_BOOKS, 0x0649, "Tome of Ice" },
	{ IMAGE_BOOKS, 0x064B, "Tome of Light" },
	{ IMAGE_BOOKS, 0x064D, "Cognitome" },
	{ IMAGE_BOOKS, 0x064F, "Omnitome" },
	{ IMAGE_CLAWS, 0x06A5, "Bronze Knuckles" },
	{ IMAGE_CLAWS, 0x06A7, "Sonic Knuckles" },
	{ IMAGE_CLAWS, 0x06A9, "Impact Claws" },
	{ IMAGE_CLAWS, 0x06AB, "Kaiser Knuckles" },
	{ IMAGE_CLAWS, 0x06AD, "Cat Claws" },
	{ IMAGE_CLAWS, 0x06AF, "Wyvern Claws" },
	{ IMAGE_CLAWS, 0x06B1, "Tiger Claws" },
	{ IMAGE_CLAWS, 0x06B3, "Faerie Claws" },
	{ IMAGE_CLAWS, 0x06B5, "Metal Knuckles" },
	{ IMAGE_CLAWS, 0x06B7, "Dark Claws" },
	{ IMAGE_CLAWS, 0x06B9, "Hellish Claws" },
	{ IMAGE_CLAWS, 0x06BB, "Tigerfangs" },
	{ IMAGE_HAMMERS, 0x0709, "Hammer" },
	{ IMAGE_HAMMERS, 0x070B, "Dragon Hammer" },
	{ IMAGE_HAMMERS, 0x070D, "Triton Hammer" },
	{ IMAGE_HAMMERS, 0x070F, "Platinum Hammer" },
	{ IMAGE_HAMMERS, 0x0711, "Blessed Hammer" },
	{ IMAGE_HAMMERS, 0x0713, "Mighty Hammer" },
	{ IMAGE_AXES, 0x076D, "Viking Axe" },
	{ IMAGE_AXES, 0x076E, "Battleaxe" },
	{ IMAGE_AXES, 0x076F, "Dual Tomahawk" },
	{ IMAGE_AXES, 0x0771, "Rune Axe" },
	{ IMAGE_AXES, 0x0773, "Demon Axe" },
	{ IMAGE_AXES, 0x0775, "Dual Haken" },
	{ IMAGE_AXES, 0x0777, "Gigantic Axe" },
	{ IMAGE_SPEARS, 0x07D1, "Thunder Spear" },
	{ IMAGE_SPEARS, 0x07D3, "Wind Spear" },
	{ IMAGE_SPEARS, 0x07D5, "Heavy Lance" },
	{ IMAGE_SPEARS, 0x07D7, "Blood Lance" },
	{ IMAGE_SPEARS, 0x07D9, "Trident" },
	{ IMAGE_SPEARS, 0x07DB, "Dragon Lance" },
	{ IMAGE_SPEARS, 0x07DD, "Holy Lance" },
	{ IMAGE_SPEARS, 0x07DF, "Gungnir" },
	{ IMAGE_SPEARS, 0x07E1, "Magic Lance" },
	{ IMAGE_THROWABLES, 0x0835, "Boomerang" },
	{ IMAGE_THROWABLES, 0x0837, "Chakram" },
	{ IMAGE_THROWABLES, 0x0839, "Rising Sun" },
	{ IMAGE_THROWABLES, 0x083B, "Moonring Blade" },
	{ IMAGE_THROWABLES, 0x083D, "Shuriken" },
	{ IMAGE_BELLS, 0x0899, "Diamond Bell" },
	{ IMAGE_BELLS, 0x089B, "Earthen Bell" },
	{ IMAGE_BELLS, 0x089D, "Rune Bell" },
	{ IMAGE_BELLS, 0x089F, "Blessed Bell" },
	{ IMAGE_HARPS, 0x08FD, "Madhura Harp" },
	{ IMAGE_HARPS, 0x08FF, "Loki Harp" },
	{ IMAGE_HARPS, 0x0901, "Lamia Harp" },
	{ IMAGE_HARPS, 0x0903, "Dream Harp" },
	{ IMAGE_HARPS, 0x0905, "Apollo Harp" },
	{ IMAGE_SHIELDS, 0x0BB9, "Leather Shield" },
	{ IMAGE_SHIELDS, 0x0BBB, "Mythril Shield" },
	{ IMAGE_SHIELDS, 0x0BBD, "Ice Shield" },
	{ IMAGE_SHIELDS, 0x0BBF, "Heroic Shield" },
	{ IMAGE_SHIELDS, 0x0BC1, "Demon Shield" },
	{ IMAGE_SHIELDS, 0x0BC3, "Diamond Shield" },
	{ IMAGE_SHIELDS, 0x0BC5, "Aegis Shield" },
	{ IMAGE_SHIELDS, 0x0BC7, "Genji Shield" },
	{ IMAGE_SHIELDS, 0x0BC9, "Crystal Shield" },
	{ IMAGE_SHIELDS, 0x0BCB, "Onion Shield" },
	{ IMAGE_HEADGEAR, 0x0C1D, "Leather Cap" },
	{ IMAGE_HEADGEAR, 0x0C1F, "Mythril Helm" },
	{ IMAGE_HEADGEAR, 0x0C21, "Shell Helm" },
	{ IMAGE_HEADGEAR, 0x0C23, "Headband" },
	{ IMAGE_HEADGEAR, 0x0C25, "Ice Helm" },
	{ IMAGE_HEADGEAR, 0x0C27, "Feathered Hat" },
	{ IMAGE_HEADGEAR, 0x0C29, "Scholar Hat" },
	{ IMAGE_HEADGEAR, 0x0C2B, "Black Cowl" },
	{ IMAGE_HEADGEAR, 0x0C2D, "Chakra Band" },
	{ IMAGE_HEADGEAR, 0x0C2F, "Dragon Helm" },
	{ IMAGE_HEADGEAR, 0x0C31, "Viking Helm" },
	{ IMAGE_HEADGEAR, 0x0C33, "Diamond Helm" },
	{ IMAGE_HEADGEAR, 0x0C34, "Ribbon" },
	{ IMAGE_HEADGEAR, 0x0C35, "Genji Helm" },
	{ IMAGE_HEADGEAR, 0x0C37, "Crystal Helm" },
	{ IMAGE_HEADGEAR, 0x0C3B, "Onion Helm" },
	{ IMAGE_HEADGEAR, 0x0C3D, "Royal Crown" },
	{ IMAGE_HEADGEAR, 0x0C3F, "Ballad Crown" },
	{ IMAGE_ARMOR, 0x0C81, "Vest" },
	{ IMAGE_ARMOR, 0x0C83, "Rusty Mail" },
	{ IMAGE_ARMOR, 0x0C85, "Leather Armor" },
	{ IMAGE_ARMOR, 0x0C87, "Mythril Armor" },
	{ IMAGE_ARMOR, 0x0C89, "Mage Robe" },
	{ IMAGE_ARMOR, 0x0C8B, "Shell Armor" },
	{ IMAGE_ARMOR, 0x0C8D, "Ice Armor" },
	{ IMAGE_ARMOR, 0x0C8F, "Kenpo Gi" },
	{ IMAGE_ARMOR, 0x0C91, "Scholar Robe" },
	{ IMAGE_ARMOR, 0x0C93, "Flame Mail" },
	{ IMAGE_ARMOR, 0x0C95, "Knight Armor" },
	{ IMAGE_ARMOR, 0x0C97, "Black Garb" },
	{ IMAGE_ARMOR, 0x0C99, "Reflect Mail" },
	{ IMAGE_ARMOR, 0x0C9B, "White Robe" },
	{ IMAGE_ARMOR, 0x0C9D, "Black Robe" },
	{ IMAGE_ARMOR, 0x0C9F, "Bard Vest" },
	{ IMAGE_ARMOR, 0x0CA1, "Black Belt Gi" },
	{ IMAGE_ARMOR, 0x0CA3, "Dragon Mail" },
	{ IMAGE_ARMOR, 0x0CA5, "Gaia Vest" },
	{ IMAGE_ARMOR, 0x0CA7, "Viking Mail" },
	{ IMAGE_ARMOR, 0x0CA9, "Demon Mail" },
	{ IMAGE_ARMOR, 0x0CAB, "Diamond Mail" },
	{ IMAGE_ARMOR, 0x0CAD, "Genji Armor" },
	{ IMAGE_ARMOR, 0x0CAE, "Fuma Garb" },
	{ IMAGE_ARMOR, 0x0CAF, "Crystal Mail" },
	{ IMAGE_ARMOR, 0x0CB1, "Onion Armor" },
	{ IMAGE_ARMOR, 0x0CB3, "Angel Robe" },
	{ IMAGE_ARMOR, 0x0CB5, "Crimson Vest" },
	{ IMAGE_ARMOR, 0x0CB9, "Master Dogi" },
	{ IMAGE_ACCESSORIES, 0x0CE5, "Bronze Bracers" },
	{ IMAGE_ACCESSORIES, 0x0CE7, "Mythril Bracers" },
	{ IMAGE_ACCESSORIES, 0x0CE9, "Mythril Gloves" },
	{ IMAGE_ACCESSORIES, 0x0CEB, "Gauntlets" },
	{ IMAGE_ACCESSORIES, 0x0CED, "Thief Gloves" },
	{ IMAGE_ACCESSORIES, 0x0CEF, "Rune Bracers" },
	{ IMAGE_ACCESSORIES, 0x0CF1, "Power Bracers" },
	{ IMAGE_ACCESSORIES, 0x0CF3, "Diamond Bracers" },
	{ IMAGE_ACCESSORIES, 0x0CF5, "Diamond Gloves" },
	{ IMAGE_ACCESSORIES, 0x0CF7, "Protect Ring" },
	{ IMAGE_ACCESSORIES, 0x0CF9, "Genji Gloves" },
	{ IMAGE_ACCESSORIES, 0x0CFB, "Onion Gauntlets" },
	{ IMAGE_ACCESSORIES, 0x0CFD, "Crystal Gloves" },
	{ IMAGE_ACCESSORIES, 0x0CFF, "Celestial Gloves" },
	{ IMAGE_ACCESSORIES, 0x0D01, "Shura Gloves" },
	{ IMAGE_ACCESSORIES, 0x0D03, "Astral Bracers" }
};
//========================================================================================================
extern sDigitLookup tblArms[ARMS_SIZE];
extern sDigitLookup tblBody[ARMOR_SIZE];
extern sDigitLookup tblHead[HEADGEAR_SIZE];
extern sDigitLookup tblHands[WEAPONS_SIZE+SHIELDS_SIZE];
extern sDigitLookup tblMagicLv1[(ALL_MAGIC_SIZE*2)+1];	// White Magic Lv1 + Black Magic Lvl1 + Summon Lvl1
extern sDigitLookup tblMagicLv2[(ALL_MAGIC_SIZE*2)+1];
extern sDigitLookup tblMagicLv3[(ALL_MAGIC_SIZE*2)+1];
extern sDigitLookup tblMagicLv4[(ALL_MAGIC_SIZE*2)+1];
extern sDigitLookup tblMagicLv5[(ALL_MAGIC_SIZE*2)+1];
extern sDigitLookup tblMagicLv6[(ALL_MAGIC_SIZE*2)+1];
extern sDigitLookup tblMagicLv7[(ALL_MAGIC_SIZE*2)+1];
extern sDigitLookup tblMagicLv8[(ALL_MAGIC_SIZE*2)+1];
//========================================================================================================
void BuildTables();
int iGetIndexFromDigit(sItemTable pLook[], int iSize, int iDigit);
int iGetIndexFromDigit(sDigitLookup pLook[], int iSize, int iDigit);
int iGetIndexFromString(sDigitLookup pLook[], int iSize, LPCSTR szItem);
int iGetDigitFromString(sDigitLookup pLook[], int iSize, LPCSTR szItem);
char *szGetStringFromDigit(sDigitLookup pLook[], int iSize, int iDigit);
//========================================================================================================