strict namespace VoteMenu
{
	int buttons[256];
	function void Build(void)
	{
		// mapset buttons
		for(int i = 0; i < mapset_count; i++)
		{
			buttons[i] = ButtonImage.Create(20.0+(fixed(i)*192.0), 20.0, mapsets[i].thumbnail, mapsets[i].name);
			Widgets.SetFont(buttons[i], "Smallfont");
			Widgets.SetArg1Str(buttons[i], mapsets[i].startmap);
			Widgets.SetArg2Int(buttons[i], mapsets[i].id);
			Widgets.SetTextOffsetY(buttons[i], 9.0);
			Widgets.AddClickedHook(buttons[i], Event_MapsetClick);
		}
	}

	function void Event_MapsetClick(int id)
	{
		ChangeLevel(Widgets.GetArg1Str(id), 0, CHANGELEVEL_NOINTERMISSION|CHANGELEVEL_RESETHEALTH, -1);
		SetCVar("lexicon_current_mapset", Widgets.GetArg2int(id));
	}
}
