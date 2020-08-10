


strict namespace button
{
	enum
	{
		CUSTOM_COLOR = 0,
		CUSTOM_TEXT = 1,
		CUSTOM_ROUND = 2,
	};

	function int Create(fixed x, fixed y, fixed w, str text)
	{
		// create a new eidget object
		int id = Widgets.Create();

		// make it clickable and hoverable
		Widgets.obj[id].clickable = true;
		Widgets.obj[id].hoverable = true;

		// call the clicked and hovered events per frame
		Widgets.obj[id].hover_repeat = true;
		Widgets.obj[id].click_repeat = true;

		// position
		Widgets.obj[id].pos.x1 = x;
		Widgets.obj[id].pos.y1 = y;
		Widgets.obj[id].pos.x2 = x+w;
		Widgets.obj[id].pos.y2 = y+28.0;

		// add hooks to events
		Widgets.AddUpdateHook(id, Event_Update);
		Widgets.AddClickedHook(id, Event_Clicked);
		Widgets.AddHoveredHook(id, Event_Hovered);

		// we changed the positional vars, recalc the sizes
		Widgets.CalcSizes(id);

		Widgets.obj[id].customString[CUSTOM_COLOR] = "Lime";
		Widgets.obj[id].customString[CUSTOM_TEXT] = text;
		Widgets.obj[id].customBool[CUSTOM_ROUND] = false;

		return id;
	}

	function void Event_Update(int id)
	{
		// text
		Screen.Draw("SMALLFONT", Widgets.obj[id].customString[CUSTOM_TEXT], "White", Widgets.obj[id].center.x, Widgets.obj[id].center.y);

		// left corner image
		if(Widgets.obj[id].customBool[CUSTOM_ROUND])
		{
			Screen.Draw("UIFONT", "a", Widgets.obj[id].customString[CUSTOM_COLOR], Widgets.obj[id].pos.x1, Widgets.obj[id].pos.y1, Screen.XALIGN_LEFT, Screen.YALIGN_TOP);
		}
		else
		{
			Screen.Draw("UIFONT", "b", Widgets.obj[id].customString[CUSTOM_COLOR], Widgets.obj[id].pos.x1, Widgets.obj[id].pos.y1, Screen.XALIGN_LEFT, Screen.YALIGN_TOP);
		}

		// filler images
		for(int i = 0; i < (int(Widgets.obj[id].size.w)/28)-1; i++)
		{
			Screen.Draw("UIFONT", "b", Widgets.obj[id].customString[CUSTOM_COLOR], Widgets.obj[id].pos.x1+(fixed(i)*28.0)+28.0, Widgets.obj[id].pos.y1, Screen.XALIGN_LEFT, Screen.YALIGN_TOP);
		}

		// right corner image
		if(Widgets.obj[id].customBool[CUSTOM_ROUND])
		{
			Screen.Draw("UIFONT", "c", Widgets.obj[id].customString[CUSTOM_COLOR], Widgets.obj[id].pos.x2, Widgets.obj[id].pos.y1, Screen.XALIGN_RIGHT, Screen.YALIGN_TOP);
		}
		else
		{
			Screen.Draw("UIFONT", "b", Widgets.obj[id].customString[CUSTOM_COLOR], Widgets.obj[id].pos.x2, Widgets.obj[id].pos.y1, Screen.XALIGN_RIGHT, Screen.YALIGN_TOP);
		}

		// set default color
		Widgets.obj[id].customString[CUSTOM_COLOR] = "UI_Lime";
	}

	function void Event_Hovered(int id)
	{
		// set hovered color
		Widgets.obj[id].customString[CUSTOM_COLOR] = "UI_Red";
	}

	function void Event_Clicked(int id)
	{
		// set clicked color
		Widgets.obj[id].customString[CUSTOM_COLOR] = "UI_Blue";
	}

}