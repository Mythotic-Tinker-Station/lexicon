


strict namespace DebugMenu
{

	Script "Debug_Mode_Enter" enter
	{
		ApplyCheats();
	}

	Script "Debug_Mode_Respawn" respawn
	{
		ApplyCheats();
	}

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
			Widgets.SetArg2Int(buttons[i], i);
			Widgets.SetFont(buttons[i], "SMALLFONT");
			Widgets.SetTextOffsetY(buttons[i], 9.0);
			Widgets.AddClickedHook(buttons[i], Event_MapsetClick);
		}

		// instakiller button
		int instakiller = ButtonCheck.Create(Screen.GetWidth()-144.0, 20.0, "Instakiller");
		Widgets.SetFont(instakiller, "SMALLFONT");
		Widgets.SetTextOffsetY(instakiller, 9.0);
		Widgets.AddClickedHook(instakiller, Event_InstaKillerCheck);

		// god mode button
		int god = ButtonCheck.Create(Screen.GetWidth()-144.0, 50.0, "God Mode");
		Widgets.SetFont(god, "SMALLFONT");
		Widgets.SetTextOffsetY(god, 9.0);
		Widgets.AddClickedHook(god, Event_GodModeCheck);

		// all weapons button
		int weapons = ButtonCheck.Create(Screen.GetWidth()-144.0, 80.0, "All Weapons");
		Widgets.SetFont(weapons, "SMALLFONT");
		Widgets.SetTextOffsetY(weapons, 9.0);
		Widgets.AddClickedHook(weapons, Event_WeaponsCheck);

		// all keys button
		int keys = ButtonCheck.Create(Screen.GetWidth()-144.0, 110.0, "All Keys");
		Widgets.SetFont(keys, "SMALLFONT");
		Widgets.SetTextOffsetY(keys, 9.0);
		Widgets.AddClickedHook(keys, Event_KeysCheck);

		// inf ammo button
		int ammo = ButtonCheck.Create(Screen.GetWidth()-144.0, 140.0, "Infinite Ammo");
		Widgets.SetFont(ammo, "SMALLFONT");
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
		mapset_current = Widgets.GetArg1int(id);
	}
}


