strict namespace VoteMenu
{
	int buttons[256];
	int title;

	function void Build(void)
	{
		// Title
		title = Label.Create(64.0, 32.0, "BIGFONT", "Vote");

		// mapset buttons
		for(int i = 0; i < mapset_count; i++)
		{
			fixed x = fixed(i % 2)*192.0;
			fixed y = fixed(i / 2)*108.0;

			buttons[i] = ButtonImage.Create(128.0+x, 96.0+y, mapsets[i].thumbnail, mapsets[i].name);
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

	function void Run()
	{
		Screen.Draw("UI_BACK1", "a", "None", 0.0, 0.0, Screen.XALIGN_LEFT, Screen.YALIGN_TOP);
		Screen.Draw("UI_BACK2", "a", "None", 0.0, Screen.GetHeight(), Screen.XALIGN_LEFT, Screen.YALIGN_BOTTOM);
	}

}
