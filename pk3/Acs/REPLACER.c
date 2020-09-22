// September 2020
// by Michaelis
// for Lexicon

#define DOOMEDNUMS 145


str classlist[DOOMEDNUMS][4] =
{
		{   5, "BlueCard"             , "2"},
		{   6, "YellowCard"           , "2"},
		{   7, "SpiderMastermind"     , "1"},
		{   8, "Backpack"             , "4"},
		{   9, "ShotgunGuy"           , "1"},
		{  10, "GibbedMarine"         , "3"},
		{  12, "GibbedMarineExtra"    , "3"},
		{  13, "RedCard"              , "2"},
		{  15, "DeadMarine"           , "3"},
		{  16, "Cyberdemon"           , "1"},
		{  17, "CellPack"             , "4"},
		{  18, "DeadZombieMan"        , "3"},
		{  19, "DeadShotgunGuy"       , "3"},
		{  20, "DeadDoomImp"          , "3"},
		{  21, "DeadDemon"            , "3"},
		{  22, "DeadCacodemon"        , "3"},
		{  23, "DeadLostSoul"         , "3"},
		{  24, "Gibs"                 , "3"},
		{  25, "DeadStick"            , "3"},
		{  26, "LiveStick"            , "3"},
		{  27, "HeadOnAStick"         , "3"},
		{  28, "HeadsOnAStick"        , "3"},
		{  29, "HeadCandles"          , "3"},
		{  30, "TallGreenColumn"      , "3"},
		{  31, "ShortGreenColumn"     , "3"},
		{  32, "TallRedColumn"        , "3"},
		{  33, "ShortRedColumn"       , "3"},
		{  34, "Candlestick"          , "3"},
		{  35, "Candelabra"           , "3"},
		{  36, "HeartColumn"          , "3"},
		{  37, "SkullColumn"          , "3"},
		{  38, "RedSkull"             , "2"},
		{  39, "YellowSkull"          , "2"},
		{  40, "BlueSkull"            , "2"},
		{  41, "EvilEye"              , "3"},
		{  42, "FloatingSkull"        , "3"},
		{  43, "TorchTree"            , "3"},
		{  44, "BlueTorch"            , "3"},
		{  45, "GreenTorch"           , "3"},
		{  46, "RedTorch"             , "3"},
		{  47, "Stalagtite"           , "3"},
		{  48, "TechPillar"           , "3"},
		{  49, "BloodyTwitch"         , "3"},
		{  50, "Meat2"                , "3"},
		{  51, "Meat3"                , "3"},
		{  52, "Meat4"                , "3"},
		{  53, "Meat5"                , "3"},
		{  54, "BigTree"              , "3"},
		{  55, "ShortBlueTorch"       , "3"},
		{  56, "ShortGreenTorch"      , "3"},
		{  57, "ShortRedTorch"        , "3"},
		{  58, "Spectre"              , "1"},
		{  59, "NonsolidMeat2"        , "3"},
		{  60, "NonsolidMeat4"        , "3"},
		{  61, "NonsolidMeat3"        , "3"},
		{  62, "NonsolidMeat5"        , "3"},
		{  63, "NonsolidTwitch"       , "3"},
		{  64, "Archvile"             , "1"},
		{  65, "ChaingunGuy"          , "1"},
		{  66, "Revenant"             , "1"},
		{  67, "Fatso"                , "1"},
		{  68, "Arachnotron"          , "1"},
		{  69, "HellKnight"           , "1"},
		{  70, "BurningBarrel"        , "3"},
		{  71, "PainElemental"        , "1"},
		{  72, "CommanderKeen"        , "0"},
		{  73, "HangNoGuts"           , "3"},
		{  74, "HangBNoBrain"         , "3"},
		{  75, "HangTLookingDown"     , "3"},
		{  76, "HangTSkull"           , "3"},
		{  77, "HangTLookingUp"       , "3"},
		{  78, "HangTNoBrain"         , "3"},
		{  79, "ColonGibs"            , "3"},
		{  80, "SmallBloodPool"       , "3"},
		{  81, "BrainStem"            , "3"},
		{  82, "SuperShotgun"         , "5"},
		{  83, "Megasphere"           , "6"},
		{  84, "WolfensteinSS"        , "1"},
		{  85, "TechLamp"             , "3"},
		{  86, "TechLamp2"            , "3"},
		{  87, "BossTarget"           , "0"},
		{  88, "BossBrain"            , "0"},
		{  89, "BossEye"              , "0"},
		{ 888, "MBFHelperDog"         , "0"},
		{2001, "Shotgun"              , "5"},
		{2002, "Chaingun"             , "5"},
		{2003, "RocketLauncher"       , "5"},
		{2004, "PlasmaRifle"          , "5"},
		{2005, "Chainsaw"             , "5"},
		{2006, "BFG9000"              , "5"},
		{2007, "Clip"                 , "4"},
		{2008, "Shell"                , "4"},
		{2010, "RocketAmmo"           , "4"},
		{2011, "Stimpack"             , "6"},
		{2012, "Medikit"              , "6"},
		{2013, "Soulsphere"           , "6"},
		{2014, "HealthBonus"          , "6"},
		{2015, "ArmorBonus"           , "6"},
		{2018, "GreenArmor"           , "6"},
		{2019, "BlueArmor"            , "6"},
		{2022, "InvulnerabilitySphere", "6"},
		{2023, "Berserk"              , "6"},
		{2024, "BlurSphere"           , "6"},
		{2025, "RadSuit"              , "6"},
		{2026, "Allmap"               , "6"},
		{2028, "Column"               , "3"},
		{2035, "ExplosiveBarrel"      , "3"},
		{2045, "Infrared"             , "6"},
		{2046, "RocketBox"            , "4"},
		{2047, "Cell"                 , "4"},
		{2048, "ClipBox"              , "4"},
		{2049, "ShellBox"             , "4"},
		{3001, "DoomImp"              , "1"},
		{3002, "Demon"                , "1"},
		{3003, "BaronOfHell"          , "1"},
		{3004, "ZombieMan"            , "1"},
		{3005, "Cacodemon"            , "1"},
		{3006, "LostSoul"             , "1"},
		{5003, "DarkImp"              , "1"},
		{5004, "BloodDemon"           , "1"},
		{5005, "SuperShotgunGuy"      , "1"},
		{5006, "Cacolantern"          , "1"},
		{5007, "Hectebus"             , "1"},
		{5008, "Belphegor"            , "1"},
		{5010, "Pistol"               , "5"},
		{5011, "GrenadeLauncher"      , "5"},
		{5012, "Railgun"              , "5"},
		{5013, "BFG10K"               , "5"},
		{5014, "Minigun"              , "5"},
		{5015, "Abaddon"              , "1"},
		{9037, "BetaSkull"            , "1"},
		{9050, "StealthArachnotron"   , "1"},
		{9051, "StealthArchvile"      , "1"},
		{9052, "StealthBaron"         , "1"},
		{9053, "StealthCacodemon"     , "1"},
		{9054, "StealthChaingunGuy"   , "1"},
		{9055, "StealthDemon"         , "1"},
		{9056, "StealthHellKnight"    , "1"},
		{9057, "StealthDoomImp"       , "1"},
		{9058, "StealthFatso"         , "1"},
		{9059, "StealthRevenant"      , "1"},
		{9060, "StealthShotgunGuy"    , "1"},
		{9061, "StealthZombieMan"     , "1"},
};

str modes[128][3];
int mode_count = 0;


Script "Re:b:lacer" (void)
{
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
			if(StrParam(c:GetChar(mode, c)) == "|")
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
