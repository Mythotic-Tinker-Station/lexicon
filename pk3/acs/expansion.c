
/*
	Lexicon Scripts by Tribeam, Popsoap, Michaelis
*/

namespace Expansion
{
	str weapons[8] = {"Pistol", "Shotgun", "SuperShotgun", "Chaingun", "RocketLauncher", "PlasmaRifle", "BFG9000", "Chainsaw"};


	// returns the text of a language.txt definition
	function str getDynLangEntryEx(str p1, str p2)
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
	script "Lexicon_AddExpansion" (int exname)
	{
        expansions[expansion_count].name = exname;
        expansion_count++;
    }

	script "Lexicon_AddMapSet" (int acronym)
	{
		mapsets[mapset_count].acronym 			= acronym;
		mapsets[mapset_count].name 				= getDynLangEntryEx(mapsets[mapset_count].acronym, "NAME");
		mapsets[mapset_count].description 		= getDynLangEntryEx(mapsets[mapset_count].acronym, "DESCRIPTION");
		mapsets[mapset_count].mapcount			= getDynLangEntryEx(mapsets[mapset_count].acronym, "MAPCOUNT");
		mapsets[mapset_count].startmap			= getDynLangEntryEx(mapsets[mapset_count].acronym, "STARTMAP");
		mapsets[mapset_count].thumbnail			= getDynLangEntryEx(mapsets[mapset_count].acronym, "THUMBNAIL");
		mapsets[mapset_count].id				= mapset_count;
        mapsets[mapset_count].expansion         = expansions[expansion_count].name;

		if(mapsets[mapset_count].thumbnail == "_LANG_UNDEFINED_")
		{
			mapsets[mapset_count].thumbnail = "BLNKTN";
		}

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

		// credits
		for(int cr = 0; cr < 256; cr++)
		{
			mapsets[mapset_count].credits[cr]	= getDynLangEntryEx(mapsets[mapset_count].acronym, strparam(s:"CREDITS", d:cr));
		}

		// actor replacers
		for(int r = 0; r < 256; r++)
		{
			// get the replacer string from langauge
			str replacer = getDynLangEntryEx(mapsets[mapset_count].acronym, strparam(s:"REPLACER", i:r));

			// check if this language define exists
			if(replacer != "_LANG_UNDEFINED_")
			{
				// for each char in the replacer string
				for(int c = 0; c <= StrLen(replacer); c++)
				{
					// find the seperator
					if(StrParam(c:GetChar(replacer, c)) == ":")
					{
						// split the replacer string into its 2 parts, the replacee and the replacer
						mapsets[mapset_count].replacers[r][0] = StrLeft(replacer, c);
						mapsets[mapset_count].replacers[r][1] = StrMid(replacer, c+1, StrLen(replacer));
						mapsets[mapset_count].replacer_count++;
						break;
					}
				}
			}
		}

		// startitems
		for(int s = 0; s < 32; s++)
		{
			// get the replacer string from langauge
			str startitem = getDynLangEntryEx(mapsets[mapset_count].acronym, strparam(s:"STARTITEM", i:s));

			// check if this language define exists
			if(startitem != "_LANG_UNDEFINED_")
			{
				// save item into startitem array
				mapsets[mapset_count].startitems[s] = startitem;
				mapsets[mapset_count].startitem_count++;
			}
		}

		// takeitems
		for(int t = 0; t < 32; t++)
		{
			// get the replacer string from langauge
			str takeitem = getDynLangEntryEx(mapsets[mapset_count].acronym, strparam(s:"TAKEITEM", i:t));

			// check if this language define exists
			if(takeitem != "_LANG_UNDEFINED_")
			{
				// save item into startitem array
				mapsets[mapset_count].takeitems[t] = takeitem;
				mapsets[mapset_count].takeitem_count++;
			}
		}
		mapset_count++;
	}
}
















