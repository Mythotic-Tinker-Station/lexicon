


strict namespace button
{

	enum
	{
		CUSTOM_COLOR,
		CUSTOM_TEXT,
	};

	function int Create(fixed x, fixed y, fixed w, str text)
	{
		int id = Widgets.Create();
		Widgets.obj[id].clickable = true;
		Widgets.obj[id].hoverable = true;
		Widgets.obj[id].hover_repeat = true;
		Widgets.obj[id].click_repeat = true;
		Widgets.obj[id].func_update = Event_Update;
		Widgets.obj[id].func_hovered = Event_Hovered;
		Widgets.obj[id].func_clicked = Event_Clicked;
		Widgets.obj[id].pos.x1 = x;
		Widgets.obj[id].pos.y1 = y;
		Widgets.obj[id].pos.x2 = x+w;
		Widgets.obj[id].pos.y2 = y+28.0;

		// we changed the positional vars, recalc the sizes
		Widgets.CalcSizes(id);

		// current color
		Widgets.obj[id].customString[CUSTOM_COLOR] = "Lime";
		Widgets.obj[id].customString[CUSTOM_TEXT] = text;

		return id;
	}

	function void Event_Update(int id)
	{
		// text
		Screen.Draw("SONICFONT", Widgets.obj[id].customString[CUSTOM_TEXT], "White", Widgets.obj[id].center.x, Widgets.obj[id].center.y);

		// left corner image
		Screen.Draw("UIFONT", "a", Widgets.obj[id].customString[CUSTOM_COLOR], Widgets.obj[id].pos.x1, Widgets.obj[id].pos.y1, Screen.XALIGN_LEFT, Screen.YALIGN_TOP);

		// filler images
		for(int i = 0; i < (int(Widgets.obj[id].size.w-32.0)/28)-1; i++)
		{
			Screen.Draw("UIFONT", "b", Widgets.obj[id].customString[CUSTOM_COLOR], Widgets.obj[id].pos.x1+(fixed(i)*28.0)+48.0, Widgets.obj[id].pos.y1, Screen.XALIGN_LEFT, Screen.YALIGN_TOP);
		}

		// right corner image
		Screen.Draw("UIFONT", "c", Widgets.obj[id].customString[CUSTOM_COLOR], Widgets.obj[id].pos.x2, Widgets.obj[id].pos.y1, Screen.XALIGN_RIGHT, Screen.YALIGN_TOP);

		Widgets.obj[id].customString[CUSTOM_COLOR] = "Lime";
	}

	function void Event_Hovered(int id)
	{
		Widgets.obj[id].customString[CUSTOM_COLOR] = "Red";
	}

	function void Event_Clicked(int id)
	{
		Widgets.obj[id].customString[CUSTOM_COLOR] = "Blue";
	}

}