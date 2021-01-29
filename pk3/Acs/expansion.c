
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

	script "Lexicon_AddMapSet" (int acronym)
	{
		mapsets[mapset_count].acronym 			= acronym;
		mapsets[mapset_count].name 				= getDynLangEntryEx(mapsets[mapset_count].acronym, "NAME");
		mapsets[mapset_count].description 		= getDynLangEntryEx(mapsets[mapset_count].acronym, "DESCRIPTION");
		mapsets[mapset_count].credits			= getDynLangEntryEx(mapsets[mapset_count].acronym, "CREDITS");
		mapsets[mapset_count].mapcount			= getDynLangEntryEx(mapsets[mapset_count].acronym, "MAPCOUNT");
		mapsets[mapset_count].startmap			= getDynLangEntryEx(mapsets[mapset_count].acronym, "STARTMAP");
		mapsets[mapset_count].thumbnail			= getDynLangEntryEx(mapsets[mapset_count].acronym, "THUMBNAIL");
		mapsets[mapset_count].id				= mapset_count;

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
				// for each char in the replacer string
				for(int c2 = 0; c2 <= StrLen(startitem); c2++)
				{
					// find the seperator
					if(StrParam(c:GetChar(startitem, c2)) == ":")
					{
						// save item into startitem array
						mapsets[mapset_count].startitems[s] = StrLeft(startitem, c2);
						mapsets[mapset_count].startamounts[s] = StrMid(startitem, c2+1, StrLen(startitem));
						mapsets[mapset_count].startitem_count++;
						break;
					}
				}
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
				// for each char in the replacer string
				for(int c3 = 0; c3 <= StrLen(takeitem); c3++)
				{
					// find the seperator
					if(StrParam(c:GetChar(takeitem, c3)) == ":")
					{
						// save item into startitem array
						mapsets[mapset_count].takeitems[t] = StrLeft(takeitem, c3);
						mapsets[mapset_count].takeamounts[t] = StrMid(takeitem, c3+1, StrLen(takeitem));
						mapsets[mapset_count].takeitem_count++;
						break;
					}
				}
			}
		}
		mapset_count++;
	}
}
















