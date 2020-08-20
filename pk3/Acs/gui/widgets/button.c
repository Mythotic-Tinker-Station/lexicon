/*
	Lexicon UI by Tribeam
	With help from Popsoap, Michaelis
*/


strict namespace Button
{
	function int Create(fixed x, fixed y, fixed w, fixed h, str t)
	{
		// create a new panel object
		int id = Panel.Create(x, y, w, h);

		// make it clickable and hoverable
		Widgets.obj[id].clickable = true;
		Widgets.obj[id].hoverable = true;

		// call the clicked and hovered events per frame
		Widgets.obj[id].hover_repeat = true;
		Widgets.obj[id].click_repeat = true;

		// add hooks to events
		Widgets.AddUpdateHook(id, Event_Update);
		Widgets.AddClickedHook(id, Event_Clicked);
		Widgets.AddHoveredHook(id, Event_Hovered);

		Widgets.SetText(id, t);

		return id;
	}

	function void Event_Update(int id)
	{
		Widgets.SetX2(id, Widgets.GetX2(id)+1.0);
		Widgets.SetY2(id, Widgets.GetY2(id)+1.0);
		// text
		Screen.Draw("SMALLFONT", Widgets.GetText(id), "White", Widgets.GetCenterX(id), Widgets.GetCenterY(id));

		if(!Widgets.obj[id].clicked && !Widgets.obj[id].hovered) { Widgets.SetColorCurrent(id, Widgets.GetColorNormal(id)); }
	}

	function void Event_Hovered(int id)
	{
		// set hovered color
		Widgets.SetColorCurrent(id, Widgets.GetColorHovered(id));
	}

	function void Event_Clicked(int id)
	{
		// set clicked color
		Widgets.SetColorCurrent(id, Widgets.GetColorClicked(id));

	}

}