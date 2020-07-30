

#import "../../compiler/lib/zcommon.bcs"
#library "lexicon"

strict namespace
{
	str mapsets[256];
	fixed mapset_count = 256.0;
	#if 1
		#include "util.c"
		#include "lex_gui.c"
		#include "scn_firsttime.c"
		#include "scn_selection.c"
		#include "replacer.c"
		#include "patches.c"
	#endif
}



/*

// all of this will be in the main lexicon code
// out global list of mapset data
str mapsets[2048][10] = {};
int mapset_count = 0;

// this function can search and determain if a language definition exists
function str getDynLangEntry(str p1, str p2)
{
    // get entry
    str name = strparam(s:p1, s:":", s:p2);
    str text = strparam(l:name);

    // check if listing exists
    if(text == name)
    {
		// if it doesnt, return some string to tell us it doesnt exist
        return "_Nothing_";
    }

	// return the string from language
    return text;
}


// a function that an extention pk3 can use to add mapset acronyms
// this function would be exposed as a library function or something
function void addMapSetAcronym(str acronym)
{
	mapsets[mapset_count][0] = acronym
	mapset_count++;
}

// this function would run when lexicon loads
function void findMapSetData()
{
	for(i = 0; i < mapset_count; i++)
	{
		str acronym = mapsets[i][0];
		mapsets[i][1] = getDynLangEntry(acronym, "NAME");
		mapsets[i][2] = getDynLangEntry(acronym, "DESC");
		mapsets[i][3] = getDynLangEntry(acronym, "ICON");
		mapsets[i][4] = getDynLangEntry(acronym, "ICON_HOVER");
		mapsets[i][5] = getDynLangEntry(acronym, "SHOT1");
		mapsets[i][6] = getDynLangEntry(acronym, "SHOT2");
		mapsets[i][7] = getDynLangEntry(acronym, "SHOT3");
		mapsets[i][8] = getDynLangEntry(acronym, "SHOT4");
		mapsets[i][9] = getDynLangEntry(acronym, "SHOT5");
		mapsets[i][10] = getDynLangEntry(acronym, "SHOT6");
	}
}

// our extention pk3's ACS
script 420 open
{
	addMapSetAcronym("UR__");
	addMapSetAcronym("94TU");
	addMapSetAcronym("AV__");
}


// our extention pk3's language.txt
UR__:NAME 		= "Unholy Realms"; 	// mapset name
UR__:DESC 		= "Unholy Realms is a something or other wad with maps and created by people.";
UR__:ICON 		= "SCRG0000";		// mapset button preview (gray)
UR__:ICON_HOVER = "SCRN0000";		// mapset button preview (hovered)
UR__:SHOT1 		= "SHOT0001";		// screenshot 1
UR__:SHOT2 		= "SHOT0002";		// screenshot 2
UR__:SHOT3 		= "SHOT0003";		// screenshot 3
UR__:SHOT4 		= "SHOT0004";		// screenshot 4
UR__:SHOT5 		= "SHOT0005";		// screenshot 5

94TU:NAME 		= "1994 tune up project";
94TU:DESC 		= "1994 tune up project is a something or other wad with maps and created by people.";
94TU:ICON 		= "SCRG0000";
94TU:ICON_HOVER = "SCRN0000";
94TU:SHOT1 		= "SHOT0001";
94TU:SHOT2 		= "SHOT0002";
94TU:SHOT3 		= "SHOT0003";
94TU:SHOT4 		= "SHOT0004";
94TU:SHOT5 		= "SHOT0005";

AV__:NAME 		= "Alien Vandeta";
AV__:DESC 		= "Alien Vandeta is a something or other wad with maps and created by people.";
AV__:ICON 		= "SCRG0000";
AV__:ICON_HOVER = "SCRN0000";
AV__:SHOT1 		= "SHOT0001";
AV__:SHOT2 		= "SHOT0002";
AV__:SHOT3 		= "SHOT0003";
AV__:SHOT4 		= "SHOT0004";
AV__:SHOT5 		= "SHOT0005";

ect...*/