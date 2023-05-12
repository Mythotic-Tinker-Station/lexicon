/*
	Lexicon Scripts by Tribeam, Popsoap, Michaelis
*/

namespace Replacer
{
	// CORE39 decided it wanted to mess everything up
	// so I had to split these numbers from the string list to fix it.
	// (I still don't know why CORE39 did this) - Tri
	int classlist_num[] =
	{
		5,	// 0
		6,	// 1
		7,	// 2
		8,	// 3
		9,	// 4
		10,	// 5
		12,	// 6
		13,	// 7
		15,	// 8
		16,	// 9
		17,	// 10
		18,	// 11
		19,	// 12
		20,	// 13
		21,	// 14
		22,	// 15
		23,	// 16
		24,	// 17
		25,	// 18
		26,	// 19
		27,	// 20
		28,	// 21
		29,	// 22
		30,	// 23
		31,	// 24
		32,	// 25
		33,	// 26
		34,	// 27
		35,	// 28
		36,	// 29
		37,	// 30
		38,	// 31
		39,	// 32
		40,	// 33
		41,	// 34
		42,	// 35
		43,	// 36
		44,	// 37
		45,	// 38
		46,	// 39
		47,	// 40
		48,	// 41
		49,	// 42
		50,	// 43
		51,	// 44
		52,	// 45
		53,	// 46
		54,	// 47
		55,	// 48
		56,	// 49
		57,	// 50
		58,	// 51
		59,	// 52
		60,	// 53
		61,	// 54
		62,	// 55
		63,	// 56
		64,	// 57
		65,	// 58
		66,	// 59
		67,	// 60
		68,	// 61
		69,	// 62
		70,	// 63
		71,	// 64
		72,	// 65
		73,	// 66
		74,	// 67
		75,	// 68
		76,	// 69
		77,	// 70
		78,	// 71
		79,	// 72
		80,	// 73
		81,	// 74
		82,	// 75
		83,	// 76
		84,	// 77
		85,	// 78
		86,	// 79
		87,	// 80
		88,	// 81
		89,	// 82
		888,	// 83
		2001,	// 84
		2002,	// 85
		2003,	// 86
		2004,	// 87
		2005,	// 88
		2006,	// 89
		2007,	// 90
		2008,	// 91
		2010,	// 92
		2011,	// 93
		2012,	// 94
		2013,	// 95
		2014,	// 96
		2015,	// 97
		2018,	// 98
		2019,	// 99
		2022,	// 100
		2023,	// 101
		2024,	// 102
		2025,	// 103
		2026,	// 104
		2028,	// 105
		2035,	// 106
		2045,	// 107
		2046,	// 108
		2047,	// 109
		2048,	// 110
		2049,	// 111
		3001,	// 112
		3002,	// 113
		3003,	// 114
		3004,	// 115
		3005,	// 116
		3006,	// 117
		5003,	// 118
		5004,	// 119
		5005,	// 120
		5006,	// 121
		5007,	// 122
		5008,	// 123
		5010,	// 124
		5011,	// 125
		5012,	// 126
		5013,	// 127
		5014,	// 128
		5015,	// 129
		9037,	// 130
		9050,	// 131
		9051,	// 132
		9052,	// 133
		9053,	// 134
		9054,	// 135
		9055,	// 136
		9056,	// 137
		9057,	// 138
		9058,	// 139
		9059,	// 140
		9060,	// 141
		9061,	// 142
	};

	str classlist[][4] =
	{
		{"BlueCard"             , "2"},	// 0
		{"YellowCard"           , "2"},	// 1
		{"SpiderMastermind"     , "1"},	// 2
		{"Backpack"             , "4"},	// 3
		{"ShotgunGuy"           , "1"},	// 4
		{"GibbedMarine"         , "3"},	// 5
		{"GibbedMarineExtra"    , "3"},	// 6
		{"RedCard"              , "2"},	// 7
		{"DeadMarine"           , "3"},	// 8
		{"Cyberdemon"           , "1"},	// 9
		{"CellPack"             , "4"},	// 10
		{"DeadZombieMan"        , "3"},	// 11
		{"DeadShotgunGuy"       , "3"},	// 12
		{"DeadDoomImp"          , "3"},	// 13
		{"DeadDemon"            , "3"},	// 14
		{"DeadCacodemon"        , "3"},	// 15
		{"DeadLostSoul"         , "3"},	// 16
		{"Gibs"                 , "3"},	// 17
		{"DeadStick"            , "3"},	// 18
		{"LiveStick"            , "3"},	// 19
		{"HeadOnAStick"         , "3"},	// 20
		{"HeadsOnAStick"        , "3"},	// 21
		{"HeadCandles"          , "3"},	// 22
		{"TallGreenColumn"      , "3"},	// 23
		{"ShortGreenColumn"     , "3"},	// 24
		{"TallRedColumn"        , "3"},	// 25
		{"ShortRedColumn"       , "3"},	// 26
		{"Candlestick"          , "3"},	// 27
		{"Candelabra"           , "3"},	// 28
		{"HeartColumn"          , "3"},	// 29
		{"SkullColumn"          , "3"},	// 30
		{"RedSkull"             , "2"},	// 31
		{"YellowSkull"          , "2"},	// 32
		{"BlueSkull"            , "2"},	// 33
		{"EvilEye"              , "3"},	// 34
		{"FloatingSkull"        , "3"},	// 35
		{"TorchTree"            , "3"},	// 36
		{"BlueTorch"            , "3"},	// 37
		{"GreenTorch"           , "3"},	// 38
		{"RedTorch"             , "3"},	// 39
		{"Stalagtite"           , "3"},	// 40
		{"TechPillar"           , "3"},	// 41
		{"BloodyTwitch"         , "3"},	// 42
		{"Meat2"                , "3"},	// 43
		{"Meat3"                , "3"},	// 44
		{"Meat4"                , "3"},	// 45
		{"Meat5"                , "3"},	// 46
		{"BigTree"              , "3"},	// 47
		{"ShortBlueTorch"       , "3"},	// 48
		{"ShortGreenTorch"      , "3"},	// 49
		{"ShortRedTorch"        , "3"},	// 50
		{"Spectre"              , "1"},	// 51
		{"NonsolidMeat2"        , "3"},	// 52
		{"NonsolidMeat4"        , "3"},	// 53
		{"NonsolidMeat3"        , "3"},	// 54
		{"NonsolidMeat5"        , "3"},	// 55
		{"NonsolidTwitch"       , "3"},	// 56
		{"Archvile"             , "1"},	// 57
		{"ChaingunGuy"          , "1"},	// 58
		{"Revenant"             , "1"},	// 59
		{"Fatso"                , "1"},	// 60
		{"Arachnotron"          , "1"},	// 61
		{"HellKnight"           , "1"},	// 62
		{"BurningBarrel"        , "3"},	// 63
		{"PainElemental"        , "1"},	// 64
		{"CommanderKeen"        , "0"},	// 65
		{"HangNoGuts"           , "3"},	// 66
		{"HangBNoBrain"         , "3"},	// 67
		{"HangTLookingDown"     , "3"},	// 68
		{"HangTSkull"           , "3"},	// 69
		{"HangTLookingUp"       , "3"},	// 70
		{"HangTNoBrain"         , "3"},	// 71
		{"ColonGibs"            , "3"},	// 72
		{"SmallBloodPool"       , "3"},	// 73
		{"BrainStem"            , "3"},	// 74
		{"SuperShotgun"         , "5"},	// 75
		{"Megasphere"           , "6"},	// 76
		{"WolfensteinSS"        , "1"},	// 77
		{"TechLamp"             , "3"},	// 78
		{"TechLamp2"            , "3"},	// 79
		{"BossTarget"           , "0"},	// 80
		{"BossBrain"            , "0"},	// 81
		{"BossEye"              , "0"},	// 82
		{"MBFHelperDog"         , "0"},	// 83
		{"Shotgun"              , "5"},	// 84
		{"Chaingun"             , "5"},	// 85
		{"RocketLauncher"       , "5"},	// 86
		{"PlasmaRifle"          , "5"},	// 87
		{"Chainsaw"             , "5"},	// 88
		{"BFG9000"              , "5"},	// 89
		{"Clip"                 , "4"},	// 90
		{"Shell"                , "4"},	// 91
		{"RocketAmmo"           , "4"},	// 92
		{"Stimpack"             , "6"},	// 93
		{"Medikit"              , "6"},	// 94
		{"Soulsphere"           , "6"},	// 95
		{"HealthBonus"          , "6"},	// 96
		{"ArmorBonus"           , "6"},	// 97
		{"GreenArmor"           , "6"},	// 98
		{"BlueArmor"            , "6"},	// 99
		{"InvulnerabilitySphere", "6"},	// 100
		{"Berserk"              , "6"},	// 101
		{"BlurSphere"           , "6"},	// 102
		{"RadSuit"              , "6"},	// 103
		{"Allmap"               , "6"},	// 104
		{"Column"               , "3"},	// 105
		{"ExplosiveBarrel"      , "3"},	// 106
		{"Infrared"             , "6"},	// 107
		{"RocketBox"            , "4"},	// 108
		{"Cell"                 , "4"},	// 109
		{"ClipBox"              , "4"},	// 110
		{"ShellBox"             , "4"},	// 111
		{"DoomImp"              , "1"},	// 112
		{"Demon"                , "1"},	// 113
		{"BaronOfHell"          , "1"},	// 114
		{"ZombieMan"            , "1"},	// 115
		{"Cacodemon"            , "1"},	// 116
		{"LostSoul"             , "1"},	// 117
		{"DarkImp"              , "1"},	// 118
		{"BloodDemon"           , "1"},	// 119
		{"SuperShotgunGuy"      , "1"},	// 120
		{"Cacolantern"          , "1"},	// 121
		{"Hectebus"             , "1"},	// 122
		{"Belphegor"            , "1"},	// 123
		{"Pistol"               , "5"},	// 124
		{"GrenadeLauncher"      , "5"},	// 125
		{"Railgun"              , "5"},	// 126
		{"BFG10K"               , "5"},	// 127
		{"Minigun"              , "5"},	// 128
		{"Abaddon"              , "1"},	// 129
		{"BetaSkull"            , "1"},	// 130
		{"StealthArachnotron"   , "1"},	// 131
		{"StealthArchvile"      , "1"},	// 132
		{"StealthBaron"         , "1"},	// 133
		{"StealthCacodemon"     , "1"},	// 134
		{"StealthChaingunGuy"   , "1"},	// 135
		{"StealthDemon"         , "1"},	// 136
		{"StealthHellKnight"    , "1"},	// 137
		{"StealthDoomImp"       , "1"},	// 138
		{"StealthFatso"         , "1"},	// 139
		{"StealthRevenant"      , "1"},	// 140
		{"StealthShotgunGuy"    , "1"},	// 141
		{"StealthZombieMan"     , "1"},	// 142

		//{9, "SillyBot_ShotgunGuy"     , "100"},	// 143
		//{65, "SillyBot_ChaingunDude"  , "100"},	// 144
		//{3004, "SillyBot_ZombieMan"   , "100"},	// 145
	};



	int randomizer_monsters[16] = { 4, 51, 57, 58, 59, 60, 61, 62, 64, 77, 112, 113, 114, 115, 116, 117 };
	int randomizer_monsters_stealth[28] = { 4, 51, 57, 58, 59, 60, 61, 62, 64, 77, 112, 113, 114, 115, 116, 117, 131, 132, 133, 134, 135, 136, 137, 138, 149, 140, 141, 142 };
	int randomizer_monsters_boss[18] = { 2, 4, 9, 51, 57, 58, 59, 60, 61, 62, 64, 77, 112, 113, 114, 115, 116, 117 };
	int randomizer_monsters_all[30] = { 2, 4, 9, 51, 57, 58, 59, 60, 61, 62, 64, 77, 112, 113, 114, 115, 116, 117, 131, 132, 133, 134, 135, 136, 137, 138, 149, 140, 141, 142 };

	int randomizer_ammo[8] = { 10, 90, 91, 92, 108, 109, 110, 111 };
	int randomizer_items[14] = { 76, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 107 };
	int randomizer_weapons[7] = { 75, 84, 85, 86, 87, 88, 89 };

	str modes[128][3];
	int mode_count = 0;
	bool isnormal = false;
	bool nostartitems = false;

	int mapset_current = 0;

	Script "Re:b:lacer" (void)
	{
		mapset_current = GetCVar("lexicon_current_mapset");
		int newobj = GetActorProperty(0, APROP_Score);

		str class = "Unknown";
		str orgclass = "Unknown";
		str type = "0";

		// get the actor we are suppose to place
		for(int i = 0; i < lengthof(classlist); i++)
		{
			if(newobj == classlist_num[i])
			{
				class = classlist[i][0];
				orgclass = class;
				type = classlist[i][1];

				SpawnForced(class, 0.0, 0.0, 0.0, 22390);
                if(CheckFlag(22390, "DROPPED"))
                {
                    SetActorFlag(22390, "DROPPED", false);
                }
				if(StrCmp(GetActorClass(22390), class) != 0)
				{
					classlist[i][2] = "1";
				}
				Thing_Remove(22390);
			}

		}

		// unknown actor
		if(class == "Unknown")
		{
			PrintBold(s:"Could not find actor : ", d:newobj);
		}


		str mode = GetCVarString("lexicon_replacer_mode");

		int pos1 = 0;
		int pos2 = 0;

		if(mode_count == 0)
		{
			for(int c = 0; c <= StrLen(mode); c++)
			{
				// find the seperator
				if(StrParam(c:GetChar(mode, c)) == " ")
				{
					pos2 = c;
					modes[mode_count][0] = StrMid(mode, pos1, pos2-pos1);
					pos1 = pos2+1;
					mode_count++;
				}
			}

			// get last mode
			pos2 = c;
			modes[mode_count][0] = StrMid(mode, pos1, pos2-pos1);

			// if mode count is still 0
			if(mode_count == 0)
			{
				mode_count = 1;
				modes[0][0] = mode;
			}

			// check for args
			for(int j = 0; j <= mode_count; j++)
			{
				for(int c2 = 0; c2 <= StrLen(modes[j][0]); c2++)
				{
					// find the seperator
					if(StrParam(c:GetChar(modes[j][0], c2)) == ":")
					{
						modes[j][1] = StrMid(modes[j][0], c2+1, StrLen(modes[j][0]));
						modes[j][0] = StrLeft(modes[j][0], c2);
						break;
					}
				}

				// this is a terrible and lazy way to get the 3rd arg...
				for(int c3 = 0; c3 <= StrLen(modes[j][1]); c3++)
				{
					// find the seperator
					if(StrParam(c:GetChar(modes[j][1], c3)) == ":")
					{
						modes[j][2] = StrMid(modes[j][1], c3+1, StrLen(modes[j][1]));
						modes[j][1] = StrLeft(modes[j][1], c3);
						break;
					}
				}

			}
		}

		for(int ii = 0; ii <= mode_count; ii++)
		{
			if(StrCmp(modes[ii][0], "normal") == 0)
			{
				for(int i2 = 0; i2 < 256; i2++)
				{
					if(StrCmp(class, mapsets[mapset_current].replacers[i2][0]) == 0)
					{
						class = mapsets[mapset_current].replacers[i2][1];
						break;
					}
				}
				isnormal = true;
			}

			if(StrCmp(modes[ii][0], "test") == 0)
			{
				if(StrCmp(type, "100") == 0)
				{
					for(int i10 = 0; i10 < 256; i10++)
					{
						if(StrCmp(class, mapsets[mapset_current].replacers[i10][0]) == 0)
						{
							class = mapsets[mapset_current].replacers[i10][1];
							break;
						}
					}
				}
			}

			if(StrCmp(modes[ii][0], "randomize_monsters") == 0)
			{
				if(StrCmp(type, "1") == 0)
				{
					bool stealth = false;
					bool boss = false;

					if(StrCmp(modes[ii][1], "stealth") == 0 || StrCmp(modes[ii][2], "stealth") == 0)
					{
						stealth = true;
					}
					if(StrCmp(modes[ii][1], "boss") == 0 || StrCmp(modes[ii][2], "boss") == 0)
					{
						boss = true;
					}
					// no boss, no stealth
					if(boss == false && stealth == false)
					{
						class = classlist[randomizer_monsters[random(0, 15)]][0];
					}
					// boss, no stealth
					else if(boss == true && stealth == false)
					{
						class = classlist[randomizer_monsters_boss[random(0, 17)]][0];
					}
					// stealth, no boss
					else if(boss == false && stealth == true)
					{
						class = classlist[randomizer_monsters_stealth[random(0, 27)]][0];
					}
					// boss and stealth
					else if(boss == true && stealth == true)
					{
						class = classlist[randomizer_monsters_all[random(0, 29)]][0];
					}
					if(isnormal)
					{
						for(int f1 = 0; f1 < 256; f1++)
						{
							if(StrCmp(class, mapsets[mapset_current].replacers[f1][0]) == 0)
							{
								class = mapsets[mapset_current].replacers[f1][1];
								break;
							}
						}
					}
				}
			}

			if(StrCmp(modes[ii][0], "randomize_ammo") == 0)
			{
				if(StrCmp(type, "4") == 0)
				{
					class = classlist[randomizer_ammo[random(0, 7)]][0];
					if(isnormal)
					{
						for(int f2 = 0; f2 < 256; f2++)
						{
							if(StrCmp(class, mapsets[mapset_current].replacers[f2][0]) == 0)
							{
								class = mapsets[mapset_current].replacers[f2][1];
								break;
							}
						}
					}
				}
			}

			if(StrCmp(modes[ii][0], "randomize_weapons") == 0)
			{
				if(StrCmp(type, "5") == 0)
				{
					class = classlist[randomizer_weapons[random(0, 6)]][0];
					if(isnormal)
					{
						for(int f3 = 0; f3 < 256; f3++)
						{
							if(StrCmp(class, mapsets[mapset_current].replacers[f3][0]) == 0)
							{
								class = mapsets[mapset_current].replacers[f3][1];
								break;
							}
						}
					}
				}

			}

			if(StrCmp(modes[ii][0], "randomize_items") == 0)
			{
				if(StrCmp(type, "6") == 0)
				{
					class = classlist[randomizer_items[random(0, 13)]][0];
					if(isnormal)
					{
						for(int f4 = 0; f4 < 256; f4++)
						{
							if(StrCmp(class, mapsets[mapset_current].replacers[f4][0]) == 0)
							{
								class = mapsets[mapset_current].replacers[f4][1];
								break;
							}
						}
					}
				}
			}

			if(StrCmp(modes[ii][0], "monsters") == 0)
			{
				if(StrCmp(type, "1") == 0)
				{
					for(int i3 = 0; i3 < 256; i3++)
					{
						if(StrCmp(class, mapsets[mapset_current].replacers[i3][0]) == 0)
						{
							class = mapsets[mapset_current].replacers[i3][1];
							break;
						}
					}
					if(StrCmp(modes[ii][1], "") != 0)
					{
						class = modes[ii][1];
						break;
					}
				}
			}
			if(StrCmp(modes[ii][0], "keys") == 0)
			{
				if(StrCmp(type, "2") == 0)
				{
					for(int i4 = 0; i4 < 256; i4++)
					{
						if(StrCmp(class, mapsets[mapset_current].replacers[i4][0]) == 0)
						{
							class = mapsets[mapset_current].replacers[i4][1];
							break;
						}
					}
					if(StrCmp(modes[ii][1], "") != 0)
					{
						class = modes[ii][1];
					}
				}
			}
			if(StrCmp(modes[ii][0], "decoratives") == 0)
			{
				if(StrCmp(type, "3") == 0)
				{
					for(int i5 = 0; i5 < 256; i5++)
					{
						if(StrCmp(class, mapsets[mapset_current].replacers[i5][0]) == 0)
						{
							class = mapsets[mapset_current].replacers[i5][1];
							break;
						}
					}
					if(StrCmp(modes[ii][1], "") != 0)
					{
						class = modes[ii][1];
					}
				}
			}
			if(StrCmp(modes[ii][0], "ammo") == 0)
			{
				if(StrCmp(type, "4") == 0)
				{
					for(int i6 = 0; i6 < 256; i6++)
					{
						if(StrCmp(class, mapsets[mapset_current].replacers[i6][0]) == 0)
						{
							class = mapsets[mapset_current].replacers[i6][1];
							break;
						}
					}
					if(StrCmp(modes[ii][1], "") != 0)
					{
						class = modes[ii][1];
					}
				}
			}
			if(StrCmp(modes[ii][0], "weapons") == 0)
			{
				if(StrCmp(type, "5") == 0)
				{
					for(int i7 = 0; i7 < 256; i7++)
					{
						if(StrCmp(class, mapsets[mapset_current].replacers[i7][0]) == 0)
						{
							class = mapsets[mapset_current].replacers[i7][1];
							break;
						}
					}
					if(StrCmp(modes[ii][1], "") != 0)
					{
						class = modes[ii][1];
					}
				}
			}

			if(StrCmp(modes[ii][0], "items") == 0)
			{
				if(StrCmp(type, "6") == 0)
				{
					for(int i8 = 0; i8 < 256; i8++)
					{
						if(StrCmp(class, mapsets[mapset_current].replacers[i8][0]) == 0)
						{
							class = mapsets[mapset_current].replacers[i8][1];
							break;
						}
					}
					if(StrCmp(modes[ii][1], "") != 0)
					{
						class = modes[ii][1];
					}
				}
			}

			if(StrCmp(modes[ii][0], "ignore") == 0)
			{
				if(StrCmp(modes[ii][1], "") != 0)
				{
					if(StrCmp(orgclass, modes[ii][1]) == 0)
					{
						class = orgclass;
					}
				}
			}

			if(StrCmp(modes[ii][0], "replace") == 0)
			{
				if(StrCmp(modes[ii][1], "") != 0)
				{
					if(StrCmp(modes[ii][2], "") != 0)
					{
						if(StrCmp(orgclass, modes[ii][1]) == 0)
						{
							class = modes[ii][2];
						}
					}
				}
			}
		}

		if(IsModdedClass(orgclass))
		{
			Reblace(orgclass);
		}
		else
		{
			Reblace(class);
		}
	}


	///////////////////////////////////////////////////////////////////////////////
	// Replace actor //////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////// QCDE-Exports //

	int _spec, _args0, _args1, _args2, _args3, _args4;
	Function int Reblace(int class)
	{
		// Spawn replacement
		int x = GetActorX(0);
		int y = GetActorY(0);
		int z = GetActorZ(0);
		int angle = GetActorAngle(0) << 8; // just for logs
		int tid = UniqueTid();

		bool success = SpawnForced(class, x,y,z, tid, angle >> 16);
		if(!success) return false;

		// Transfer flags, store as spawner's tracer and finally transfer tid
		if(CheckFlag(0,"FRIENDLY")) GiveActorInventory(tid, "FriendlyProc", 1);
		if(CheckFlag(0,"AMBUSH"  )) GiveActorInventory(tid,   "AmbushProc", 1);
		if(CheckFlag(0,"DORMANT" )) GiveActorInventory(tid,  "DormantProc", 1);

		if(CheckFlag(tid,"SPAWNCEILING"))
		{
			SetActorPosition(tid, GetActorX(0), GetActorY(0), GetActorCeilingZ(tid) - GetActorProperty(tid, APROP_Height), 0);
		}

		SetPointer(AAPTR_TRACER, tid);
		GiveInventory("TransferSpecialProc", 1); // <-- given to spawner, not spawnee!
		SetThingSpecial(tid, _spec, _args0, _args1, _args2, _args3, _args4);
		Thing_ChangeTid(tid, ActivatorTid());
		Thing_ChangeTid(0, 0); // release tid from spawner itself
		//printbold(s:"\c-Spawned ", s:"\cv", s:class, s:"\c- at (", f:x, s:", ", f:y, s:", ", f:z, s:"; angle ", f:angle, s:").");

		Thing_Remove(0);

		return true;
	}

	Script "XCDE_StoreSpecial1" (int spec, int args0, int args1)
	{
		_spec = spec;
		_args0 = args0;
		_args1 = args1;
	}

	Script "XCDE_StoreSpecial2" (int args2, int args3, int args4)
	{
		_args2 = args2;
		_args3 = args3;
		_args4 = args4;
	}

	function bool IsModdedClass(str class)
	{
		if(GetCVar("lexicon_no_mod_check") == 0)
		{
			for(int c = 0; c < lengthof(classlist); c++)
			{
				if(StrCmp(class, classlist[c][0]) == 0)
				{
					if(StrCmp(classlist[c][2], "1") == 0)
					{
						return true;
					}
				}
			}
		}
		return false;
	}

	function void StartItems()
	{
		if(GetCVar("lexicon_no_start_items") == 0)
		{
			int mapset_current = GetCVar("lexicon_current_mapset");

			for(int t = 0; t < mapsets[mapset_current].takeitem_count; t++)
			{
				TakeInventory(mapsets[mapset_current].takeitems[t], 1);
			}

			for(int s = 0; s < mapsets[mapset_current].startitem_count; s++)
			{
				GiveInventory(mapsets[mapset_current].startitems[s], 1);
			}
		}
	}
}