

strict namespace Gui
{
	////////////////////////////////////////////////////////
	// gui functions
	////////////////////////////////////////////////////////

	// enable entire widget pool
	function void Enable()
	{
		for(int id = 0; id < Widgets.MAX_WIDGETS; id++)
		{
			Widgets.obj[id].enabled = true;
		}
	}

	// disable entire widget pool
	function void Disable()
	{
		for(int id = 0; id < Widgets.MAX_WIDGETS; id++)
		{
			Widgets.obj[id].enabled = false;
		}
	}

	// hide entire widget pool
	function void Hide()
	{
		for(int id = 0; id < Widgets.MAX_WIDGETS; id++)
		{
			Widgets.obj[id].visible = true;
		}
	}

	// show entire widget pool
	function void Show()
	{
		for(int id = 0; id < Widgets.MAX_WIDGETS; id++)
		{
			Widgets.obj[id].visible = false;
		}
	}

	// clean out entire widget pool
	function void Clear()
	{
		// mark all slots as free
		for(int id = 0; id < Widgets.MAX_WIDGETS; id++)
		{
			Widgets.obj[id].alive = false;
		}
		Screen.Clear();
	}

	// move entire widget pool
	function int Move(fixed x, fixed y)
	{
		fixed x1h;
		fixed x2h;
		fixed y1h;
		fixed y2h;
		for(int id = 0; id < Widgets.MAX_WIDGETS; id++)
		{
			if(Widgets.obj[id].alive)
			{
				Widgets.obj[id].pos.x1 += x;
				Widgets.obj[id].pos.x2 += x;
				Widgets.obj[id].pos.y1 += y;
				Widgets.obj[id].pos.y2 += y;

				if(Widgets.obj[id].pos.x1 > x1h) { x1h = Widgets.obj[id].pos.x1; }
				if(Widgets.obj[id].pos.x2 > x2h) { x2h = Widgets.obj[id].pos.x2; }
				if(Widgets.obj[id].pos.y1 > y1h) { y1h = Widgets.obj[id].pos.y1; }
				if(Widgets.obj[id].pos.y2 > y2h) { y2h = Widgets.obj[id].pos.y2; }
			}
		}
		if(x1h >= Screen.size.w) { return 1; }
		if(x2h <= 0.0) { return 2; }
		if(y1h >= Screen.size.w) { return 3; }
		if(y2h <= 0.0) { return 4; }
		return 0;
	}

	////////////////////////////////////////////////////////
	// Scripts
	////////////////////////////////////////////////////////
	script "CL_GUI" enter clientside
	{
		// check if we are on the hub map
		if(GetLevelInfo(LEVELINFO_LEVELNUM) != 99) { terminate; }

		// check if we are the local client
		if(!clientCheck()) { terminate; }

		// setup the Screen
		Screen.Init();

		int test1 = Panel.Create(100.0, 100.0, 128.0, 128.0, "test1");
		Widgets.obj[test1].customBool[Button.CUSTOM_ROUND] = true;

		while(1)
		{
			Cursor.Run();
			Widgets.Run();
			Screen.ResetHudIDs();
			delay(1);
		}
	/*
		// setup gui
		guiInit();

		int state = 0;

		while(1)
		{
			// run cursor
			guiCursorRun();

			// run all gui objects
			guiWidgetsRun();


			// scene switch
			if(gui.scene != gui.scene_prev)
			{
				switch(gui.scene)
				{
					case SCENE_FIRST_TIME:
						ACS_NamedExecute("Scene_FirstTime_Run", 0);
						break;

					case SCENE_SELECTION:
						ACS_NamedExecute("Scene_Selection_Run", 0);
						break;
				}
			}

			// reset hud ID counter
			gui.nextid = 0;
			gui.objcount = 0;
			delay(1);
			cursor.clicked_prev = cursor.clicked;

			// if the resolution changes, terminate scenes and restart
			if(GetCVar("vid_defwidth") != gui.vid_w || GetCVar("vid_defheight") != gui.vid_h)
			{
				ACS_NamedTerminate("Scene_FirstTime_Run", 0);
				ACS_NamedTerminate("Scene_Selection_Run", 0);
				restart;
			}
		}
		*/
	}
}