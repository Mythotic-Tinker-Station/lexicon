strict namespace Panel
{

	int color;
	int round;

	function int Create(fixed x, fixed y, fixed w, fixed h)
	{
		// create a new widget object
		int id = Widgets.Create();

		// position
		Widgets.obj[id].pos.x1 = x;
		Widgets.obj[id].pos.y1 = y;
		Widgets.obj[id].pos.x2 = Widgets.obj[id].pos.x1+w;
		Widgets.obj[id].pos.y2 = Widgets.obj[id].pos.y1+h;

		// we changed the positional vars, recalc the sizes
		Widgets.CalcSizes(id);

		// add hooks to events
		Widgets.AddUpdateHook(id, Event_Update);

		color = Widgets.AddString(id, "Lime");
		round = Widgets.AddBool(id, false);

		return id;
	}

	function void Event_Update(int id)
	{
		// bottom right corner
		Screen.Draw("UIFONT", "e", Widgets.GetString(id, color), Widgets.obj[id].pos.x2, Widgets.obj[id].pos.y2, Screen.XALIGN_RIGHT, Screen.YALIGN_BOTTOM);

		// filler images
		for(int y = 0; y <= (int(Widgets.obj[id].size.h)/28)-1; y++)
		{
			// right edge
			Screen.Draw("UIFONT", "e", Widgets.GetString(id, color), Widgets.obj[id].pos.x2, Widgets.obj[id].pos.y1+(fixed(y)*28.0), Screen.XALIGN_RIGHT, Screen.YALIGN_TOP);

			for(int x = 0; x <= (int(Widgets.obj[id].size.w)/28)-1; x++)
			{
				// bottom edge
				if(y == (int(Widgets.obj[id].size.h)/28)-1)
				{
					Screen.Draw("UIFONT", "e", Widgets.GetString(id, color), Widgets.obj[id].pos.x1+(fixed(x)*28.0), Widgets.obj[id].pos.y2, Screen.XALIGN_LEFT, Screen.YALIGN_BOTTOM);
				}

				// left edge, top edge, and fill
				Screen.Draw("UIFONT", "e", Widgets.GetString(id, color), Widgets.obj[id].pos.x1+(fixed(x)*28.0), Widgets.obj[id].pos.y1+(fixed(y)*28.0), Screen.XALIGN_LEFT, Screen.YALIGN_TOP);
			}
		}
	}
}


