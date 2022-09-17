strict namespace VoteMenu
{
	int buttons[256];
	int lbl_title;
	int lbl_debug;
	function void Build(void)
	{
		// Title
		lbl_title = Label.Create(112.0, 32.0, "CP437_BIG", "Please cast your vote:");

		// mapset buttons
		for(int i = 0; i < mapset_count; i++)
		{
			fixed x = fixed(i % int((Screen.GetWidth()/192.0)-2.0))*192.0;
			fixed y = fixed(i / int((Screen.GetHeight()/108.0)-2.0))*108.0;

			buttons[i] = ButtonImage.Create(128.0+x, 96.0+y, mapsets[i].thumbnail, mapsets[i].name);
			Widgets.SetFont(buttons[i], "CP437");
			Widgets.SetArg2Int(buttons[i], mapsets[i].id);
            Widgets.SetArg1Str(buttons[i], mapsets[i].startmap);
			Widgets.AddClickedHook(buttons[i], Event_MapsetClick);
		}

		if(GetCVar("lexicon_debug_mode") == 1)
		{
			lbl_debug = Label.Create(Screen.GetWidth()-144.0, 32.0, "CP437", "Debug mode:");
			Widgets.SetTextOffsetX(lbl_debug, -4.0);

			// instakiller button
			int instakiller = ButtonCheck.Create(Screen.GetWidth()-144.0, 50.0, "\c[White]Instakiller");
			Widgets.SetFont(instakiller, "CP437");
			Widgets.SetTextOffsetY(instakiller, 4.0);
			Widgets.AddClickedHook(instakiller, Event_InstaKillerCheck);

			// god mode button
			int god = ButtonCheck.Create(Screen.GetWidth()-144.0, 80.0, "\c[White]God Mode");
			Widgets.SetFont(god, "CP437");
			Widgets.SetTextOffsetY(god, 4.0);
			Widgets.AddClickedHook(god, Event_GodModeCheck);

			// all weapons button
			int weapons = ButtonCheck.Create(Screen.GetWidth()-144.0, 110.0, "\c[White]All Weapons");
			Widgets.SetFont(weapons, "CP437");
			Widgets.SetTextOffsetY(weapons, 4.0);
			Widgets.AddClickedHook(weapons, Event_WeaponsCheck);
            Widgets.SetEnabled(weapons, false);

			// all keys button
			int keys = ButtonCheck.Create(Screen.GetWidth()-144.0, 140.0, "\c[White]All Keys");
			Widgets.SetFont(keys, "CP437");
			Widgets.SetTextOffsetY(keys, 4.0);
			Widgets.AddClickedHook(keys, Event_KeysCheck);
            Widgets.SetEnabled(keys, false);

			// inf ammo button
			int ammo = ButtonCheck.Create(Screen.GetWidth()-144.0, 170.0, "\c[White]Infinite Ammo");
			Widgets.SetFont(ammo, "CP437");
			Widgets.SetTextOffsetY(ammo, 4.0);
			Widgets.AddClickedHook(ammo, Event_AmmoCheck);
		}
	}

	function void Event_InstaKillerCheck(int id) { NamedRequestScriptPuke("Event_InstaKillerCheck_SV", int(Widgets.GetChecked(id)));  }
	function void Event_GodModeCheck(int id) { NamedRequestScriptPuke("Event_GodModeCheck_SV", int(Widgets.GetChecked(id)));  }
	function void Event_WeaponsCheck(int id) { NamedRequestScriptPuke("Event_WeaponsCheck_SV", int(Widgets.GetChecked(id)));  }
	function void Event_KeysCheck(int id) { NamedRequestScriptPuke("Event_KeysCheck_SV", int(Widgets.GetChecked(id)));  }
	function void Event_AmmoCheck(int id) { NamedRequestScriptPuke("Event_AmmoCheck_SV", int(Widgets.GetChecked(id)));  }
	function void Event_MapsetClick(int id) { NamedRequestScriptPuke("Event_MapsetClick_SV", Widgets.GetArg2int(id)); }


    script "Event_InstaKillerCheck_SV" (int v) NET
    {
        if(GetLevelInfo(LEVELINFO_LEVELNUM) != 99) { terminate; }
        SetCVar("lexicon_debug_instakiller", v);
    }

    script "Event_GodModeCheck_SV" (int v) NET
    {
        if(GetLevelInfo(LEVELINFO_LEVELNUM) != 99) { terminate; }
        SetCVar("lexicon_debug_godmode", v);
    }

    script "Event_WeaponsCheck_SV" (int v) NET
    {
        if(GetLevelInfo(LEVELINFO_LEVELNUM) != 99) { terminate; }
        SetCVar("lexicon_debug_weapons", v);
    }

    script "Event_KeysCheck_SV" (int v) NET
    {
        if(GetLevelInfo(LEVELINFO_LEVELNUM) != 99) { terminate; }
        SetCVar("lexicon_debug_keys", v);
    }

    script "Event_AmmoCheck_SV" (int v) NET
    {
        if(GetLevelInfo(LEVELINFO_LEVELNUM) != 99) { terminate; }
        SetCVar("lexicon_debug_infammo", v);
    }

    script "Event_MapsetClick_SV" (int id) NET
    {
        if(GetLevelInfo(LEVELINFO_LEVELNUM) != 99) { terminate; }
		ChangeLevel(mapsets[id].startmap, 0, CHANGELEVEL_NOINTERMISSION|CHANGELEVEL_RESETHEALTH, -1);
        SetCVar("lexicon_current_mapset", mapsets[id].id);
    }

	function void Run()
	{
		
	}

}
