/*
	Lexicon UI by Tribeam
	With help from Popsoap, Michaelis
*/


strict namespace Button
{
	enum
	{
		CUSTOM_COLOR = 0,
		CUSTOM_TEXT = 1,
		CUSTOM_ROUND = 2,
	};

	int text;

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

		text = Widgets.AddString(id, t);

		return id;
	}

	function void Event_Update(int id)
	{
		// text
		Screen.Draw("SMALLFONT", Widgets.GetString(id, text), "White", Widgets.obj[id].center.x, Widgets.obj[id].center.y);

		Widgets.SetString(id, Panel.color, "White");
	}

	function void Event_Hovered(int id)
	{
		// set hovered color
		Widgets.SetString(id, Panel.color, "Red");
	}

	function void Event_Clicked(int id)
	{
		// set clicked color
		Widgets.SetString(id, Panel.color, "Blue");
	}

}