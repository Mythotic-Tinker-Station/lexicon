/*
	Lexicon Scripts by Tribeam, Popsoap, Michaelis
*/

#define DOOMEDNUMS 146

namespace Replacer
{
	str classlist[DOOMEDNUMS][4] =
	{
			{   5, "BlueCard"             , "2"},	// 0
			{   6, "YellowCard"           , "2"},	// 1
			{   7, "SpiderMastermind"     , "1"},	// 2
			{   8, "Backpack"             , "4"},	// 3
			{   9, "ShotgunGuy"           , "1"},	// 4
			{  10, "GibbedMarine"         , "3"},	// 5
			{  12, "GibbedMarineExtra"    , "3"},	// 6
			{  13, "RedCard"              , "2"},	// 7
			{  15, "DeadMarine"           , "3"},	// 8
			{  16, "Cyberdemon"           , "1"},	// 9
			{  17, "CellPack"             , "4"},	// 10
			{  18, "DeadZombieMan"        , "3"},	// 11
			{  19, "DeadShotgunGuy"       , "3"},	// 12
			{  20, "DeadDoomImp"          , "3"},	// 13
			{  21, "DeadDemon"            , "3"},	// 14
			{  22, "DeadCacodemon"        , "3"},	// 15
			{  23, "DeadLostSoul"         , "3"},	// 16
			{  24, "Gibs"                 , "3"},	// 17
			{  25, "DeadStick"            , "3"},	// 18
			{  26, "LiveStick"            , "3"},	// 19
			{  27, "HeadOnAStick"         , "3"},	// 20
			{  28, "HeadsOnAStick"        , "3"},	// 21
			{  29, "HeadCandles"          , "3"},	// 22
			{  30, "TallGreenColumn"      , "3"},	// 23
			{  31, "ShortGreenColumn"     , "3"},	// 24
			{  32, "TallRedColumn"        , "3"},	// 25
			{  33, "ShortRedColumn"       , "3"},	// 26
			{  34, "Candlestick"          , "3"},	// 27
			{  35, "Candelabra"           , "3"},	// 28
			{  36, "HeartColumn"          , "3"},	// 29
			{  37, "SkullColumn"          , "3"},	// 30
			{  38, "RedSkull"             , "2"},	// 31
			{  39, "YellowSkull"          , "2"},	// 32
			{  40, "BlueSkull"            , "2"},	// 33
			{  41, "EvilEye"              , "3"},	// 34
			{  42, "FloatingSkull"        , "3"},	// 35
			{  43, "TorchTree"            , "3"},	// 36
			{  44, "BlueTorch"            , "3"},	// 37
			{  45, "GreenTorch"           , "3"},	// 38
			{  46, "RedTorch"             , "3"},	// 39
			{  47, "Stalagtite"           , "3"},	// 40
			{  48, "TechPillar"           , "3"},	// 41
			{  49, "BloodyTwitch"         , "3"},	// 42
			{  50, "Meat2"                , "3"},	// 43
			{  51, "Meat3"                , "3"},	// 44
			{  52, "Meat4"                , "3"},	// 45
			{  53, "Meat5"                , "3"},	// 46
			{  54, "BigTree"              , "3"},	// 47
			{  55, "ShortBlueTorch"       , "3"},	// 48
			{  56, "ShortGreenTorch"      , "3"},	// 49
			{  57, "ShortRedTorch"        , "3"},	// 50
			{  58, "Spectre"              , "1"},	// 51
			{  59, "NonsolidMeat2"        , "3"},	// 52
			{  60, "NonsolidMeat4"        , "3"},	// 53
			{  61, "NonsolidMeat3"        , "3"},	// 54
			{  62, "NonsolidMeat5"        , "3"},	// 55
			{  63, "NonsolidTwitch"       , "3"},	// 56
			{  64, "Archvile"             , "1"},	// 57
			{  65, "ChaingunGuy"          , "1"},	// 58
			{  66, "Revenant"             , "1"},	// 59
			{  67, "Fatso"                , "1"},	// 60
			{  68, "Arachnotron"          , "1"},	// 61
			{  69, "HellKnight"           , "1"},	// 62
			{  70, "BurningBarrel"        , "3"},	// 63
			{  71, "PainElemental"        , "1"},	// 64
			{  72, "CommanderKeen"        , "0"},	// 65
			{  73, "HangNoGuts"           , "3"},	// 66
			{  74, "HangBNoBrain"         , "3"},	// 67
			{  75, "HangTLookingDown"     , "3"},	// 68
			{  76, "HangTSkull"           , "3"},	// 69
			{  77, "HangTLookingUp"       , "3"},	// 70
			{  78, "HangTNoBrain"         , "3"},	// 71
			{  79, "ColonGibs"            , "3"},	// 72
			{  80, "SmallBloodPool"       , "3"},	// 73
			{  81, "BrainStem"            , "3"},	// 74
			{  82, "SuperShotgun"         , "5"},	// 75
			{  83, "Megasphere"           , "6"},	// 76
			{  84, "WolfensteinSS"        , "1"},	// 77
			{  85, "TechLamp"             , "3"},	// 78
			{  86, "TechLamp2"            , "3"},	// 79
			{  87, "BossTarget"           , "0"},	// 80
			{  88, "BossBrain"            , "0"},	// 81
			{  89, "BossEye"              , "0"},	// 82
			{ 888, "MBFHelperDog"         , "0"},	// 83
			{2001, "Shotgun"              , "5"},	// 84
			{2002, "Chaingun"             , "5"},	// 85
			{2003, "RocketLauncher"       , "5"},	// 86
			{2004, "PlasmaRifle"          , "5"},	// 87
			{2005, "Chainsaw"             , "5"},	// 88
			{2006, "BFG9000"              , "5"},	// 89
			{2007, "Clip"                 , "4"},	// 90
			{2008, "Shell"                , "4"},	// 91
			{2010, "RocketAmmo"           , "4"},	// 92
			{2011, "Stimpack"             , "6"},	// 93
			{2012, "Medikit"              , "6"},	// 94
			{2013, "Soulsphere"           , "6"},	// 95
			{2014, "HealthBonus"          , "6"},	// 96
			{2015, "ArmorBonus"           , "6"},	// 97
			{2018, "GreenArmor"           , "6"},	// 98
			{2019, "BlueArmor"            , "6"},	// 99
			{2022, "InvulnerabilitySphere", "6"},	// 100
			{2023, "Berserk"              , "6"},	// 101
			{2024, "BlurSphere"           , "6"},	// 102
			{2025, "RadSuit"              , "6"},	// 103
			{2026, "Allmap"               , "6"},	// 104
			{2028, "Column"               , "3"},	// 105
			{2035, "ExplosiveBarrel"      , "3"},	// 106
			{2045, "Infrared"             , "6"},	// 107
			{2046, "RocketBox"            , "4"},	// 108
			{2047, "Cell"                 , "4"},	// 109
			{2048, "ClipBox"              , "4"},	// 110
			{2049, "ShellBox"             , "4"},	// 111
			{3001, "DoomImp"              , "1"},	// 112
			{3002, "Demon"                , "1"},	// 113
			{3003, "BaronOfHell"          , "1"},	// 114
			{3004, "ZombieMan"            , "1"},	// 115
			{3005, "Cacodemon"            , "1"},	// 116
			{3006, "LostSoul"             , "1"},	// 117
			{5003, "DarkImp"              , "1"},	// 118
			{5004, "BloodDemon"           , "1"},	// 119
			{5005, "SuperShotgunGuy"      , "1"},	// 120
			{5006, "Cacolantern"          , "1"},	// 121
			{5007, "Hectebus"             , "1"},	// 122
			{5008, "Belphegor"            , "1"},	// 123
			{5010, "Pistol"               , "5"},	// 124
			{5011, "GrenadeLauncher"      , "5"},	// 125
			{5012, "Railgun"              , "5"},	// 126
			{5013, "BFG10K"               , "5"},	// 127
			{5014, "Minigun"              , "5"},	// 128
			{5015, "Abaddon"              , "1"},	// 129
			{9037, "BetaSkull"            , "1"},	// 130
			{9050, "StealthArachnotron"   , "1"},	// 131
			{9051, "StealthArchvile"      , "1"},	// 132
			{9052, "StealthBaron"         , "1"},	// 133
			{9053, "StealthCacodemon"     , "1"},	// 134
			{9054, "StealthChaingunGuy"   , "1"},	// 135
			{9055, "StealthDemon"         , "1"},	// 136
			{9056, "StealthHellKnight"    , "1"},	// 137
			{9057, "StealthDoomImp"       , "1"},	// 138
			{9058, "StealthFatso"         , "1"},	// 139
			{9059, "StealthRevenant"      , "1"},	// 140
			{9060, "StealthShotgunGuy"    , "1"},	// 141
			{9061, "StealthZombieMan"     , "1"},	// 142

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
	bool isnormal;

	int mapset_current = 0;

	Script "Re:b:lacer" (void)
	{
		mapset_current = GetCVar("lexicon_current_mapset");
		int newobj = GetActorProperty(0, APROP_Score);

		str class = "Unknown";
		str orgclass = "Unknown";
		str type = "0";

		// get the actor we are suppose to place
		for(int i = 0; i < DOOMEDNUMS; i++)
		{
			if(newobj == classlist[i][0])
			{
				class = classlist[i][1];
				orgclass = class;
				type = classlist[i][2];
			}
		}

		// unknown actor
		if(class == "Unknown")
		{
			PrintBold(s:"Unexpected class replaced: ", d:newobj);
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
						class = classlist[randomizer_monsters[random(0, 15)]][1];
					}
					// boss, no stealth
					else if(boss == true && stealth == false)
					{
						class = classlist[randomizer_monsters_boss[random(0, 17)]][1];
					}
					// stealth, no boss
					else if(boss == false && stealth == true)
					{
						class = classlist[randomizer_monsters_stealth[random(0, 27)]][1];
					}
					// boss and stealth
					else if(boss == true && stealth == true)
					{
						class = classlist[randomizer_monsters_all[random(0, 29)]][1];
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
					class = classlist[randomizer_ammo[random(0, 7)]][1];
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
					class = classlist[randomizer_weapons[random(0, 6)]][1];
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
					class = classlist[randomizer_items[random(0, 13)]][1];
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

		Reblace(class);
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
}