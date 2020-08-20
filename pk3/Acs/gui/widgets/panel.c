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
		fixed tilesX = fixed(int(Widgets.GetWidth(id)/16.0)-1);
		fixed tilesY = fixed(int(Widgets.GetHeight(id)/16.0)-1);

		for(fixed x = 0.0; x <= tilesX; x += 1.0)
		{
			for(fixed y = 0.0; y <= tilesY; y += 1.0)
			{
				// middle
				if(x > 0.0 && x <= tilesX && y > 0.0 && y <= tilesY)
				{
					Screen.Draw("UIFONT", "I", Widgets.GetColorCurrent(id), Widgets.GetX1(id)+(x*16.0), Widgets.GetY1(id)+(y*16.0), Screen.XALIGN_LEFT, Screen.YALIGN_TOP);
				}

				// top
				if(x > 0.0 && x <= tilesX && y == 0.0)
				{
					Screen.Draw("UIFONT", "B", "Cyan", Widgets.GetX1(id)+(x*16.0), Widgets.GetY1(id), Screen.XALIGN_LEFT, Screen.YALIGN_TOP);
				}

				// left
				if(x == 0.0 && y > 0.0)
				{
					Screen.Draw("UIFONT", "H", "White", Widgets.GetX1(id), Widgets.GetY1(id)+(y*16.0), Screen.XALIGN_LEFT, Screen.YALIGN_TOP);
				}

				// bottom
				if(x > 0.0 && x <= tilesX && y == tilesY)
				{
					Screen.Draw("UIFONT", "F", "Purple", Widgets.GetX1(id)+(x*16.0), Widgets.GetY2(id), Screen.XALIGN_LEFT, Screen.YALIGN_BOTTOM);
				}

				// right
				if(x == tilesX && y > 0.0)
				{
					Screen.Draw("UIFONT", "D", "Orange", Widgets.GetX2(id), Widgets.GetY1(id)+(y*16.0), Screen.XALIGN_RIGHT, Screen.YALIGN_TOP);
				}
			}
		}

		Screen.Draw("UIFONT", "A", "Red", Widgets.GetX1(id), Widgets.GetY1(id), Screen.XALIGN_LEFT, Screen.YALIGN_TOP);
		Screen.Draw("UIFONT", "C", "Blue", Widgets.GetX2(id), Widgets.GetY1(id), Screen.XALIGN_RIGHT, Screen.YALIGN_TOP);
		Screen.Draw("UIFONT", "G", "Green", Widgets.GetX1(id), Widgets.GetY2(id), Screen.XALIGN_LEFT, Screen.YALIGN_BOTTOM);
		Screen.Draw("UIFONT", "E", "Yellow", Widgets.GetX2(id), Widgets.GetY2(id), Screen.XALIGN_RIGHT, Screen.YALIGN_BOTTOM);

	}
}