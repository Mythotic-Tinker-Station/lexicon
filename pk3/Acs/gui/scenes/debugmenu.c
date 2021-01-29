


strict namespace DebugMenu
{
	function void ApplyCheats(void)
	{
		if(GetCVar("lexicon_debug_instakiller")) { GiveInventory("Lexicon_InstaKiller", 1); }
		if(GetCVar("lexicon_debug_godmode")) { GiveInventory("Lexicon_GodMode", 1); }
		if(GetCVar("lexicon_debug_weapons")) { ConsoleCommand("give weapons"); ConsoleCommand("give ammo"); }
		if(GetCVar("lexicon_debug_keys")) { ConsoleCommand("give keys"); }
		if(GetCVar("lexicon_debug_infammo")) { GiveInventory("Lexicon_InfAmmo", 1); }
	}


	int buttons[256];
	function void Build(void)
	{
		// mapset buttons
		for(int i = 0; i < mapset_count; i++)
		{
			buttons[i] = Button128.Create(20.0, 20.0+fixed(i*24), mapsets[i].name);
			Widgets.SetArg1Str(buttons[i], mapsets[i].startmap);
			Widgets.SetArg2Int(buttons[i], mapsets[i].id);
			Widgets.SetFont(buttons[i], "Smallfont");
			Widgets.SetTextOffsetY(buttons[i], 9.0);
			Widgets.AddClickedHook(buttons[i], Event_MapsetClick);
		}

		// instakiller button
		int instakiller = ButtonCheck.Create(Screen.GetWidth()-144.0, 20.0, "\c[White]Instakiller");
		Widgets.SetFont(instakiller, "Smallfont");
		Widgets.SetTextOffsetY(instakiller, 9.0);
		Widgets.AddClickedHook(instakiller, Event_InstaKillerCheck);

		// god mode button
		int god = ButtonCheck.Create(Screen.GetWidth()-144.0, 50.0, "\c[White]God Mode");
		Widgets.SetFont(god, "Smallfont");
		Widgets.SetTextOffsetY(god, 9.0);
		Widgets.AddClickedHook(god, Event_GodModeCheck);

		// all weapons button
		int weapons = ButtonCheck.Create(Screen.GetWidth()-144.0, 80.0, "\c[White]All Weapons");
		Widgets.SetFont(weapons, "Smallfont");
		Widgets.SetTextOffsetY(weapons, 9.0);
		Widgets.AddClickedHook(weapons, Event_WeaponsCheck);

		// all keys button
		int keys = ButtonCheck.Create(Screen.GetWidth()-144.0, 110.0, "\c[White]All Keys");
		Widgets.SetFont(keys, "Smallfont");
		Widgets.SetTextOffsetY(keys, 9.0);
		Widgets.AddClickedHook(keys, Event_KeysCheck);

		// inf ammo button
		int ammo = ButtonCheck.Create(Screen.GetWidth()-144.0, 140.0, "\c[White]Infinite Ammo");
		Widgets.SetFont(ammo, "Smallfont");
		Widgets.SetTextOffsetY(ammo, 9.0);
		Widgets.AddClickedHook(ammo, Event_AmmoCheck);
	}

	function void Event_InstaKillerCheck(int id) { SetCVar("lexicon_debug_instakiller", int(Widgets.GetChecked(id))); }
	function void Event_GodModeCheck(int id) { SetCVar("lexicon_debug_godmode", int(Widgets.GetChecked(id))); }
	function void Event_WeaponsCheck(int id) { SetCVar("lexicon_debug_weapons", int(Widgets.GetChecked(id))); }
	function void Event_KeysCheck(int id) { SetCVar("lexicon_debug_keys", int(Widgets.GetChecked(id))); }
	function void Event_AmmoCheck(int id) { SetCVar("lexicon_debug_infammo", int(Widgets.GetChecked(id))); }

	function void Event_MapsetClick(int id)
	{
		ChangeLevel(Widgets.GetArg1Str(id), 0, CHANGELEVEL_NOINTERMISSION|CHANGELEVEL_RESETHEALTH, -1);
		SetCVar("lexicon_current_mapset", Widgets.GetArg2int(id));
	}
}


