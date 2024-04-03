
/*
	Lexicon Scripts by Tribeam, Popsoap, Michaelis
*/

// returns the text of a language.txt definition
function str getDynLangEntry(str p1, str p2)
{
    // get entry
    str name = strparam(s:p1, s:"_", s:p2);
    str text = strparam(l:name);

    // check if listing exists
    if(text == name)
    {
		// if it doesnt, return some string to tell us it doesnt exist
        return "_LANG_UNDEFINED_";
    }

	// return the string from language
    return text;
}

// a null function for blank ui actions
function void nullFunc(int i)
{
    print(s:"No action for obj number: " , i:i);
}

// checks if the currently running clientside script is the local client
function bool clientCheck()
{
    if(IsNetworkGame()) { if(playerNumber() != consolePlayerNumber()) { return false; } }
	return true;
}

// absolute value
function fixed abs (fixed x)
{
    if (x < 0.0)
        return -x;

    return x;
}

// normalize a min max range of numbers to 0.0 - 1.0
function fixed normalize(fixed v, fixed min, fixed max)
{
	return v * (max - min) + min;
}

function void applyCheats(void)
{
	if(GetCVar("lexicon_debug_instakiller")) { GiveInventory("Lexicon_InstaKiller", 1); }
	if(GetCVar("lexicon_debug_godmode")) { GiveInventory("Lexicon_GodMode", 1); }
	if(GetCVar("lexicon_debug_weapons")) { ConsoleCommand("give weapons"); ConsoleCommand("give ammo"); }
	if(GetCVar("lexicon_debug_keys")) { ConsoleCommand("give keys"); }
	if(GetCVar("lexicon_debug_infammo")) { GiveInventory("Lexicon_InfAmmo", 1); }
    if(GetCVar("lexicon_debug_nothinggun")) { GiveInventory("Lexicon_TheNothingGun", 1); }
}
