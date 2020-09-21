// September 2020
// by Michaelis
// for Lexicon

#define DOOMEDNUMS 145


Script "Re:b:lacer" (void)
{
	int newobj = GetActorProperty(0, APROP_Score);

	str class = "Unknown";

	switch(newobj)
	{
		case    5: class = "BlueCard"              ; break ;
		case    6: class = "YellowCard"            ; break ;
		case    7: class = "SpiderMastermind"      ; break ;
		case    8: class = "Backpack"              ; break ;
		case    9: class = "ShotgunGuy"            ; break ;
		case   10: class = "GibbedMarine"          ; break ;
		case   12: class = "GibbedMarineExtra"     ; break ;
		case   13: class = "RedCard"               ; break ;
		case   14: class = "TeleportDest"          ; break ;
		case   15: class = "DeadMarine"            ; break ;
		case   16: class = "Cyberdemon"            ; break ;
		case   17: class = "CellPack"              ; break ;
		case   18: class = "DeadZombieMan"         ; break ;
		case   19: class = "DeadShotgunGuy"        ; break ;
		case   20: class = "DeadDoomImp"           ; break ;
		case   21: class = "DeadDemon"             ; break ;
		case   22: class = "DeadCacodemon"         ; break ;
		case   23: class = "DeadLostSoul"          ; break ;
		case   24: class = "Gibs"                  ; break ;
		case   25: class = "DeadStick"             ; break ;
		case   26: class = "LiveStick"             ; break ;
		case   27: class = "HeadOnAStick"          ; break ;
		case   28: class = "HeadsOnAStick"         ; break ;
		case   29: class = "HeadCandles"           ; break ;
		case   30: class = "TallGreenColumn"       ; break ;
		case   31: class = "ShortGreenColumn"      ; break ;
		case   32: class = "TallRedColumn"         ; break ;
		case   33: class = "ShortRedColumn"        ; break ;
		case   34: class = "Candlestick"           ; break ;
		case   35: class = "Candelabra"            ; break ;
		case   36: class = "HeartColumn"           ; break ;
		case   37: class = "SkullColumn"           ; break ;
		case   38: class = "RedSkull"              ; break ;
		case   39: class = "YellowSkull"           ; break ;
		case   40: class = "BlueSkull"             ; break ;
		case   41: class = "EvilEye"               ; break ;
		case   42: class = "FloatingSkull"         ; break ;
		case   43: class = "TorchTree"             ; break ;
		case   44: class = "BlueTorch"             ; break ;
		case   45: class = "GreenTorch"            ; break ;
		case   46: class = "RedTorch"              ; break ;
		case   47: class = "Stalagtite"            ; break ;
		case   48: class = "TechPillar"            ; break ;
		case   49: class = "BloodyTwitch"          ; break ;
		case   50: class = "Meat2"                 ; break ;
		case   51: class = "Meat3"                 ; break ;
		case   52: class = "Meat4"                 ; break ;
		case   53: class = "Meat5"                 ; break ;
		case   54: class = "BigTree"               ; break ;
		case   55: class = "ShortBlueTorch"        ; break ;
		case   56: class = "ShortGreenTorch"       ; break ;
		case   57: class = "ShortRedTorch"         ; break ;
		case   58: class = "Spectre"               ; break ;
		case   59: class = "NonsolidMeat2"         ; break ;
		case   60: class = "NonsolidMeat4"         ; break ;
		case   61: class = "NonsolidMeat3"         ; break ;
		case   62: class = "NonsolidMeat5"         ; break ;
		case   63: class = "NonsolidTwitch"        ; break ;
		case   64: class = "Archvile"              ; break ;
		case   65: class = "ChaingunGuy"           ; break ;
		case   66: class = "Revenant"              ; break ;
		case   67: class = "Fatso"                 ; break ;
		case   68: class = "Arachnotron"           ; break ;
		case   69: class = "HellKnight"            ; break ;
		case   70: class = "BurningBarrel"         ; break ;
		case   71: class = "PainElemental"         ; break ;
		case   72: class = "CommanderKeen"         ; break ;
		case   73: class = "HangNoGuts"            ; break ;
		case   74: class = "HangBNoBrain"          ; break ;
		case   75: class = "HangTLookingDown"      ; break ;
		case   76: class = "HangTSkull"            ; break ;
		case   77: class = "HangTLookingUp"        ; break ;
		case   78: class = "HangTNoBrain"          ; break ;
		case   79: class = "ColonGibs"             ; break ;
		case   80: class = "SmallBloodPool"        ; break ;
		case   81: class = "BrainStem"             ; break ;
		case   82: class = "SuperShotgun"          ; break ;
		case   83: class = "Megasphere"            ; break ;
		case   84: class = "WolfensteinSS"         ; break ;
		case   85: class = "TechLamp"              ; break ;
		case   86: class = "TechLamp2"             ; break ;
		case   87: class = "BossTarget"            ; break ;
		case   88: class = "BossBrain"             ; break ;
		case   89: class = "BossEye"               ; break ;
		case  888: class = "MBFHelperDog"          ; break ;
		case 2001: class = "Shotgun"               ; break ;
		case 2002: class = "Chaingun"              ; break ;
		case 2003: class = "RocketLauncher"        ; break ;
		case 2004: class = "PlasmaRifle"           ; break ;
		case 2005: class = "Chainsaw"              ; break ;
		case 2006: class = "BFG9000"               ; break ;
		case 2007: class = "Clip"                  ; break ;
		case 2008: class = "Shell"                 ; break ;
		case 2010: class = "RocketAmmo"            ; break ;
		case 2011: class = "Stimpack"              ; break ;
		case 2012: class = "Medikit"               ; break ;
		case 2013: class = "Soulsphere"            ; break ;
		case 2014: class = "HealthBonus"           ; break ;
		case 2015: class = "ArmorBonus"            ; break ;
		case 2018: class = "GreenArmor"            ; break ;
		case 2019: class = "BlueArmor"             ; break ;
		case 2022: class = "InvulnerabilitySphere" ; break ;
		case 2023: class = "Berserk"               ; break ;
		case 2024: class = "BlurSphere"            ; break ;
		case 2025: class = "RadSuit"               ; break ;
		case 2026: class = "Allmap"                ; break ;
		case 2028: class = "Column"                ; break ;
		case 2035: class = "ExplosiveBarrel"       ; break ;
		case 2045: class = "Infrared"              ; break ;
		case 2046: class = "RocketBox"             ; break ;
		case 2047: class = "Cell"                  ; break ;
		case 2048: class = "ClipBox"               ; break ;
		case 2049: class = "ShellBox"              ; break ;
		case 3001: class = "DoomImp"               ; break ;
		case 3002: class = "Demon"                 ; break ;
		case 3003: class = "BaronOfHell"           ; break ;
		case 3004: class = "ZombieMan"             ; break ;
		case 3005: class = "Cacodemon"             ; break ;
		case 3006: class = "LostSoul"              ; break ;
		case 5003: class = "DarkImp"               ; break ;
		case 5004: class = "BloodDemon"            ; break ;
		case 5005: class = "SuperShotgunGuy"       ; break ;
		case 5006: class = "Cacolantern"           ; break ;
		case 5007: class = "Hectebus"              ; break ;
		case 5008: class = "Belphegor"             ; break ;
		case 5010: class = "Pistol"                ; break ;
		case 5011: class = "GrenadeLauncher"       ; break ;
		case 5012: class = "Railgun"               ; break ;
		case 5013: class = "BFG10K"                ; break ;
		case 5014: class = "Minigun"               ; break ;
		case 5015: class = "Abaddon"               ; break ;
		case 9037: class = "BetaSkull"             ; break ;
		case 9050: class = "StealthArachnotron"    ; break ;
		case 9051: class = "StealthArchvile"       ; break ;
		case 9052: class = "StealthBaron"          ; break ;
		case 9053: class = "StealthCacodemon"      ; break ;
		case 9054: class = "StealthChaingunGuy"    ; break ;
		case 9055: class = "StealthDemon"          ; break ;
		case 9056: class = "StealthHellKnight"     ; break ;
		case 9057: class = "StealthDoomImp"        ; break ;
		case 9058: class = "StealthFatso"          ; break ;
		case 9059: class = "StealthRevenant"       ; break ;
		case 9060: class = "StealthShotgunGuy"     ; break ;
		case 9061: class = "StealthZombieMan"      ; break ;
		default: PrintBold(s:"Unexpected class replaced: ", d:newobj);
	}

	// for each replacer object
	for(int i = 0; i < 128; i++)
	{
		if(class == mapsets[mapset_current].replacers[i][0])
		{
			class = mapsets[mapset_current].replacers[i][1];
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
