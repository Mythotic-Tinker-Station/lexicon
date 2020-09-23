/*
	Lexicon UI by Tribeam
	With help from Popsoap, Michaelis
*/


strict namespace Button24
{
	function int Create(fixed x, fixed y, str t)
	{
		int id = Widgets.Create();

		Widgets.SetRectPosition(id, x, y, 24.0, 24.0);

		// make it clickable and hoverable
		Widgets.SetClickable(id, true);
		Widgets.SetHoverable(id, true);

		Widgets.SetRenderText(id, true);
		Widgets.SetRenderImage(id, true);

		Widgets.SetText(id, t);
		Widgets.SetImage(id, "a");
		return id;
	}
}

strict namespace Button64
{
	function int Create(fixed x, fixed y, str t)
	{
		int id = Button24.Create(x, y, t);
		Widgets.SetRectPosition(id, x, y, 64.0, 24.0);
		Widgets.SetImage(id, "b");
		return id;
	}
}

strict namespace Button96
{
	function int Create(fixed x, fixed y, str t)
	{
		int id = Button24.Create(x, y, t);
		Widgets.SetRectPosition(id, x, y, 96.0, 24.0);
		Widgets.SetText(id, t);
		Widgets.SetImage(id, "c");
		return id;
	}
}

strict namespace Button128
{
	function int Create(fixed x, fixed y, str t)
	{
		int id = Button24.Create(x, y, t);
		Widgets.SetRectPosition(id, x, y, 128.0, 24.0);
		Widgets.SetText(id, t);
		Widgets.SetImage(id, "d");
		return id;
	}
}

strict namespace ButtonCheck
{
	function int Create(fixed x, fixed y, str t)
	{
		int id = Button24.Create(x, y, t);
		Widgets.SetRectPosition(id, x, y, 128.0, 24.0);
		Widgets.SetText(id, t);
		Widgets.SetImage(id, "d");
		Widgets.SetCheckable(id, true);
		return id;
	}
}


strict namespace ButtonMap
{
	function int Create(fixed x, fixed y, str t)
	{
		int id = Button24.Create(x, y, t);
		Widgets.SetRectPosition(id, x, y, 152.0, 108.0);
		Widgets.SetText(id, t);
		Widgets.SetImage(id, "e");
		Widgets.SetFont(id, "SMALLFONT");
		Widgets.SetTextOffsetY(id, 6.0);
		Widgets.AddUpdateHook(id, Event_Update);
		Widgets.SetBackColorNormal(id, "");
		Widgets.SetBackColorHovered(id, "");
		Widgets.SetBackColorClicked(id, "");

		return id;
	}

	function void Event_Update(int id)
	{
		//Screen.Draw("NGM2", "a", Widgets.GetBackColorCurrent(id), Widgets.GetX1(id)+6.0, Widgets.GetY1(id)+6.0, Screen.XALIGN_LEFT, Screen.YALIGN_TOP);
	}
}








