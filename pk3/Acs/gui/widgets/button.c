


strict namespace button
{
	function int Create(fixed x1, fixed y1, fixed x2, fixed y2)
	{
		int id = gui.WidgetCreate();
		gui.widgets[id].clickable = true;
		gui.widgets[id].hoverable = true;
		gui.widgets[id].update = buttonUpdate;
		gui.widgets[id].pos.x1 = x1;
		gui.widgets[id].pos.y1 = y1;
		gui.widgets[id].pos.x2 = x2;
		gui.widgets[id].pos.y2 = y2;

		gui.widgets[id].images[0] = Screen.ImageCreate(gui.widgets[id].pos.x1, gui.widgets[id].pos.y1, "Green", Screen.XALIGN_LEFT, Screen.YALIGN_TOP);
		gui.widgets[id].images[1] = Screen.ImageCreate(gui.widgets[id].pos.x1, gui.widgets[id].pos.y1, "Green", Screen.XALIGN_LEFT, Screen.YALIGN_TOP);

		// filler images
		for(int i = 2; i < int(gui.widgets[id].size.w-70.0)/28; i++)
		{
			gui.widgets[id].images[i] = Screen.ImageCreate(gui.widgets[id].pos.x1+16.0+(fixed(i)*28.0), gui.widgets[id].pos.y1, "Green", Screen.XALIGN_LEFT, Screen.YALIGN_TOP);
		}

		gui.widgets[id].images[30] = Screen.ImageCreate(gui.widgets[id].pos.x1, gui.widgets[id].pos.y1, "Green", Screen.XALIGN_RIGHT, Screen.YALIGN_TOP);
		gui.widgets[id].images[31] = Screen.ImageCreate(gui.widgets[id].pos.x1, gui.widgets[id].pos.y1, "Green", Screen.XALIGN_RIGHT, Screen.YALIGN_TOP);

		return id;
	}

	function void buttonUpdate(int id)
	{
		// left corner image
		//Screen.ImageSetPos(gui.widgets[id].images[0], gui.widgets[id].pos.x1, gui.widgets[id].pos.y1);
		Screen.ImageDraw(gui.widgets[id].images[0], "UI_BTN_L");

		// middle image first
		//Screen.ImageSetPos(gui.widgets[id].images[1], gui.widgets[id].pos.x1+16.0, gui.widgets[id].pos.y1);
		Screen.ImageDraw(gui.widgets[id].images[1], "UI_BTN_M");

		// filler images
		for(int i = 2; i < int(gui.widgets[id].size.w-32.0)/28; i++)
		{
			//Screen.ImageSetPos(gui.widgets[id].images[i], gui.widgets[id].pos.x1+16.0+(fixed(i)*28.0), gui.widgets[id].pos.y1);
			Screen.ImageDraw(gui.widgets[id].images[i], "UI_BTN_M");
		}

		// middle image last
		//Screen.ImageSetPos(gui.widgets[id].images[30], gui.widgets[id].pos.x2-16.0, gui.widgets[id].pos.y1);
		Screen.ImageDraw(gui.widgets[id].images[30], "UI_BTN_M");

		// right corner image
		//Screen.ImageSetPos(gui.widgets[id].images[31], gui.widgets[id].pos.x2, gui.widgets[id].pos.y1);
		Screen.ImageDraw(gui.widgets[id].images[31], "UI_BTN_R");
	}
}