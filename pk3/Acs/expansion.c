

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
	mapsets[mapset_count].acronym 			= acronym;
	mapsets[mapset_count].name 				= getDynLangEntryEx(mapsets[mapset_count].acronym, "NAME");
	mapsets[mapset_count].description 		= getDynLangEntryEx(mapsets[mapset_count].acronym, "DESCRIPTION");
	mapsets[mapset_count].credits			= getDynLangEntryEx(mapsets[mapset_count].acronym, "CREDITS");
	mapsets[mapset_count].mapcount			= getDynLangEntryEx(mapsets[mapset_count].acronym, "MAPCOUNT");
	mapsets[mapset_count].startmap			= getDynLangEntryEx(mapsets[mapset_count].acronym, "STARTMAP");
	mapsets[mapset_count].thumbnail			= getDynLangEntryEx(mapsets[mapset_count].acronym, "THUMBNAIL");

	// previews
	for(int p = 0; p < 32; p++)
	{
		mapsets[mapset_count].previews[p]	= getDynLangEntryEx(mapsets[mapset_count].acronym, strparam(s:"PREVIEW", d:p));
	}

	// readme pages
	for(int rm = 0; rm < 256; rm++)
	{
		mapsets[mapset_count].readme[rm]	= getDynLangEntryEx(mapsets[mapset_count].acronym, strparam(s:"README", d:rm));
	}

	// replacers
	for(int r = 0; r < 256; r++)
	{
		// get the replacer string from langauge
		str info = getDynLangEntryEx(mapsets[mapset_count].acronym, strparam(s:"REPLACER", d:r));

		// check if this language define exists
		if(info != "_LANG_UNDEFINED_")
		{
			// for each char in the replacer string
			for(int c = 0; c <= StrLen(info); c++)
			{
				// find the seperator
				if(StrParam(c:GetChar(info, c)) == ":")
				{
					// split the replacer string into its 2 parts, the replacee and the replacer
					mapsets[mapset_count].replacers[r][0] = StrLeft(info, c);
					mapsets[mapset_count].replacers[r][1] = StrMid(info, c+1, StrLen(info));
					break;
				}
			}
		}
	}
	mapset_count++;
}

















