strict namespace Panel
{
	enum
	{
		CUSTOM_COLOR = 0,
		CUSTOM_TEXT = 1,
		CUSTOM_ROUND = 2,
	};

	function int Create(fixed x, fixed y, fixed w, fixed h, str text)
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
		Widgets.obj[id].pos.x2 = Widgets.obj[id].pos.x1+w;
		Widgets.obj[id].pos.y2 = Widgets.obj[id].pos.y1+h;

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
		Widgets.obj[id].pos.x2++;
		Widgets.obj[id].pos.y2++;

		Widgets.CalcSizes(id);
		// filler images
		for(int y = 0; y <= (int(Widgets.obj[id].size.h)/28)-1; y++)
		{
			for(int x = 0; x <= (int(Widgets.obj[id].size.w)/28)-1; x++)
			{
				// left edge, top edge, and fill
				Screen.Draw("UIFONT", "e", Widgets.obj[id].customString[CUSTOM_COLOR], Widgets.obj[id].pos.x1+(fixed(x)*28.0), Widgets.obj[id].pos.y1+(fixed(y)*28.0), Screen.XALIGN_LEFT, Screen.YALIGN_TOP);

				// bottom edge
				if(y == (int(Widgets.obj[id].size.h)/28)-1)
				{
					Screen.Draw("UIFONT", "e", Widgets.obj[id].customString[CUSTOM_COLOR], Widgets.obj[id].pos.x1+(fixed(x)*28.0), Widgets.obj[id].pos.y2, Screen.XALIGN_LEFT, Screen.YALIGN_BOTTOM);
				}
			}
			// right edge
			Screen.Draw("UIFONT", "e", Widgets.obj[id].customString[CUSTOM_COLOR], Widgets.obj[id].pos.x2, Widgets.obj[id].pos.y1+(fixed(y)*28.0), Screen.XALIGN_RIGHT, Screen.YALIGN_TOP);
		}

		// bottom right corner
		Screen.Draw("UIFONT", "e", Widgets.obj[id].customString[CUSTOM_COLOR], Widgets.obj[id].pos.x2, Widgets.obj[id].pos.y2, Screen.XALIGN_RIGHT, Screen.YALIGN_BOTTOM);

		// set default color
		Widgets.obj[id].customString[CUSTOM_COLOR] = "Lime";
	}

	function void Event_Hovered(int id)
	{
		// set hovered color
		Widgets.obj[id].customString[CUSTOM_COLOR] = "Red";
	}

	function void Event_Clicked(int id)
	{
		// set clicked color
		Widgets.obj[id].customString[CUSTOM_COLOR] = "Blue";
	}

}