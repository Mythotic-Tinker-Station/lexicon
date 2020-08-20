/*
	Lexicon UI by Tribeam
	With help from Popsoap, Michaelis
*/

strict namespace Panel
{
	function int Create(fixed x, fixed y, fixed w, fixed h)
	{
		// create a new widget object
		int id = Widgets.Create();

		// position
		Widgets.SetRectPosition(id, x, y, w, h);

		// we changed the positional vars, recalc the sizes
		Widgets.CalcSizes(id);

		// add hooks to events
		Widgets.AddUpdateHook(id, Event_Update);

		return id;
	}

	function void Event_Update(int id)
	{
		// bottom right corner
		Screen.Draw("UIFONT", "e", Widgets.GetColorCurrent(id), Widgets.GetX2(id), Widgets.GetY2(id), Screen.XALIGN_RIGHT, Screen.YALIGN_BOTTOM);

		// filler images
		for(int y = 0; y <= (int(Widgets.GetHeight(id))/28)-1; y++)
		{
			// right edge
			Screen.Draw("UIFONT", "e", Widgets.GetColorCurrent(id), Widgets.GetX2(id), Widgets.GetY1(id)+(fixed(y)*28.0), Screen.XALIGN_RIGHT, Screen.YALIGN_TOP);

			for(int x = 0; x <= (int(Widgets.GetWidth(id))/28)-1; x++)
			{
				// bottom edge
				if(y == (int(Widgets.GetHeight(id))/28)-1)
				{
					Screen.Draw("UIFONT", "e", Widgets.GetColorCurrent(id), Widgets.GetX1(id)+(fixed(x)*28.0), Widgets.GetY2(id), Screen.XALIGN_LEFT, Screen.YALIGN_BOTTOM);
				}

				// left edge, top edge, and fill
				Screen.Draw("UIFONT", "e", Widgets.GetColorCurrent(id), Widgets.GetX1(id)+(fixed(x)*28.0), Widgets.GetY1(id)+(fixed(y)*28.0), Screen.XALIGN_LEFT, Screen.YALIGN_TOP);
			}
		}
	}
}