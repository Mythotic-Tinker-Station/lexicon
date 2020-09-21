

// returns the text of a language.txt definition
function str getDynLangEntryEx(int p1, int p2)
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

script "Lexicon_AddMapSet" (int acronym)
{
	mapset_count++;
	mapsets[mapset_count].acronym 			= acronym;
	mapsets[mapset_count].name 				= getDynLangEntryEx(mapsets[mapset_count].acronym, "NAME");
	mapsets[mapset_count].description 		= getDynLangEntryEx(mapsets[mapset_count].acronym, "DESCRIPTION");
	mapsets[mapset_count].credits			= getDynLangEntryEx(mapsets[mapset_count].acronym, "CREDITS");
	mapsets[mapset_count].mapcount			= getDynLangEntryEx(mapsets[mapset_count].acronym, "MAPCOUNT");
	mapsets[mapset_count].startmap			= getDynLangEntryEx(mapsets[mapset_count].acronym, "STARTMAP");
	mapsets[mapset_count].thumbnail			= getDynLangEntryEx(mapsets[mapset_count].acronym, "THUMBNAIL");
	for(int i = 0; i < 32; i++)
	{
		mapsets[mapset_count].previews[i]	= getDynLangEntryEx(mapsets[mapset_count].acronym, strparam(s:"PREVIEW", d:i));
	}

	for(int ii = 0; ii < 256; ii++)
	{
		mapsets[mapset_count].readme[ii]	= getDynLangEntryEx(mapsets[mapset_count].acronym, strparam(s:"README", d:ii));
	}



}



