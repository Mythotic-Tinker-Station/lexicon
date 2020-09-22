


strict namespace FirstTimer
{
	int buttons[256];
	Script "Scene_FirstTimer" open
	{
		delay(2);
		for(int i = 0; i < mapset_count; i++)
		{
			buttons[i] = Button128.Create(20.0, 20.0+fixed(i*24), mapsets[i].name);
			Widgets.SetArg1Str(buttons[i], mapsets[i].startmap);
			Widgets.SetArg2Int(buttons[i], i);
			Widgets.SetFont(buttons[i], "SMALLFONT");
			Widgets.SetTextOffsetY(buttons[i], 9.0);
			Widgets.AddClickedHook(buttons[i], Event_Update);
		}
	}

	function void Event_Update(int id)
	{
		ChangeLevel(Widgets.GetArg1Str(id), 0, CHANGELEVEL_NOINTERMISSION|CHANGELEVEL_RESETHEALTH, -1);
		mapset_current = Widgets.GetArg1int(id);
	}
}


