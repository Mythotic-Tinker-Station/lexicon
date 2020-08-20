/*
	Lexicon UI by Tribeam
	With help from Popsoap, Michaelis
*/


strict namespace Label
{
	enum
	{
		CUSTOM_COLOR = 0,
		CUSTOM_TEXT = 1,
		CUSTOM_ROUND = 2,
	};

	int text;

	function int Create(fixed x, fixed y, str t)
	{
		// create a new blank object
		int id = Widgets.Create();

		// position
		Widgets.SetRectPosition(id, x, y);

		// we changed the positional vars, recalc the sizes
		Widgets.CalcSizes(id);

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