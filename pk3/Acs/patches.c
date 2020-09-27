/*
	Lexicon Scripts by Tribeam, Popsoap, Michaelis
*/

// this file contains fixes to mapsets
// we have a policy not to edit the original mapsets
// only under the condition that a level cannot be completed
// for various reasons


/////////////////////////////////////////////////////
// Doom 2 the way ID did
/////////////////////////////////////////////////////
script 218 (void)
{
    Delay(85);
    Exit_Normal(0);
}

/////////////////////////////////////////////////////
// UAC Ultra
/////////////////////////////////////////////////////
script 219 (void)
{
    Floor_LowerToHighest(6, 16, 0, 0);
    Delay(35 * 4);
    Exit_Normal(0);
}

/////////////////////////////////////////////////////
// Unholy Realms
/////////////////////////////////////////////////////
script "UR11Fix" enter
{
    // if we are on the level we wanna fix
    if(!StrIcmp(StrParam(n:PRINTNAME_LEVEL), "UR__11"))
    {
		// wait for the cyberdemon to be killed
        while(ThingCountName("CyberDemon",0) > 0) { delay(35); }

		// raise exit
		Ceiling_RaiseToNearest(666, 6);
    }
}

/////////////////////////////////////////////////////
// 1994 tune up project
/////////////////////////////////////////////////////
script 1994 enter
{
    // if we are on the level we wanna fix
    if(!StrIcmp(StrParam(n:PRINTNAME_LEVEL), "94TU07"))
    {
        // spawn a actor enters sector thing in a specific spot in the map
        Spawn("SecActEnter", -1040.0, 2288.0, -530.0, 1994);

        // give the sector action a...action...to execute script 1995
        Thing_SetSpecial(1994, 80, 1995, 0, 0);
    }
}

bool nftu_activated = false;
script 1995 (void)
{
    if(!nftu_activated)
    {
        delay(35*3);
        nftu_activated = true;
        SpawnForced("Fatso", -1504.0, 1952.0, -580.0, 0, 32);
        SpawnForced("Fatso", -1376.0, 2080.0, -580.0, 0, 32);
        SpawnForced("Fatso", -1312.0, 1824.0, -580.0, 0, 32);

        SpawnForced("Archvile", -1040.0, 1872.0, -580.0, 0, 64);

        SpawnForced("Fatso", -544.0, 1952.0, -580.0, 0, 96);
        SpawnForced("Fatso", -672.0, 2080.0, -580.0, 0, 96);
        SpawnForced("Fatso", -736.0, 1824.0, -580.0, 0, 96);
    }
}