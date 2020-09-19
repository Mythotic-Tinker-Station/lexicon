









script "Leixcon_AddMapSet" (int acronym)
{
	mapset_count++;
	mapsets[mapset_count].acronym 			= str(acronym);
	mapsets[mapset_count].name 				= getDynLangEntry(mapsets[mapset_count].acronym, "NAME");
	mapsets[mapset_count].description 		= getDynLangEntry(mapsets[mapset_count].acronym, "DESCRIPTION");
	mapsets[mapset_count].credits			= getDynLangEntry(mapsets[mapset_count].acronym, "CREDITS");
	mapsets[mapset_count].mapcount			= getDynLangEntry(mapsets[mapset_count].acronym, "MAPCOUNT");
	mapsets[mapset_count].startmap			= getDynLangEntry(mapsets[mapset_count].acronym, "STARTMAP");
	mapsets[mapset_count].thumbnail			= getDynLangEntry(mapsets[mapset_count].acronym, "THUMBNAIL");

	for(int i = 0; i < 32; i++)
	{
		mapsets[mapset_count].previews[i]	= getDynLangEntry(mapsets[mapset_count].acronym, strparam(s:"PREVIEW", d:i));
	}
}



