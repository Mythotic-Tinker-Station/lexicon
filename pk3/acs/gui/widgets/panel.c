/*
	Lexicon UI by Tribeam
	With help from Popsoap, Michaelis
*/

strict namespace Panel
{
	function int Create(fixed x, fixed y, fixed w, fixed h)
	{
		// create a new widget object
		int id = Widgets::Create();

		// position
		Widgets::SetRectPosition(id, x, y, w, h);

		// add hooks to events
		Widgets::AddUpdateHook(id, Event_Update);

		return id;
	}

	function void Event_Update(int id)
	{
        // this is broken in zandronum
        //SetHudClipRect(int(Widgets::GetX1(id)), int(Widgets::GetY1(id)), int(Widgets::GetWidth(id)), int(Widgets::GetHeight(id)), 0, true);

		fixed cols = fixed(int(Widgets::GetWidth(id)/64.0))-1.0;
		fixed rows = fixed(int(Widgets::GetHeight(id)/64.0))-1.0;

        // top right and middle
		for(fixed x = 0.0; x <= cols; x += 1.0)
		{
			for(fixed y = 0.0; y <= rows; y += 1.0)
			{
				Screen::DrawImage("UIFONT", "D", Widgets::GetBackColorCurrent(id), Widgets::GetX1(id)+(x*64.0), Widgets::GetY1(id)+(y*64.0), Screen::XALIGN_LEFT, Screen::YALIGN_TOP);
			}
		}

        // right
		for(fixed y = 0.0; y <= rows; y += 1.0)
		{
			Screen::DrawImage("UIFONT", "D", Widgets::GetBackColorCurrent(id), Widgets::GetX2(id), Widgets::GetY1(id)+(y*64.0), Screen::XALIGN_RIGHT, Screen::YALIGN_TOP);
		}

        // bottom
		for(fixed x = 0.0; x <= cols; x += 1.0)
		{
			Screen::DrawImage("UIFONT", "D", Widgets::GetBackColorCurrent(id), Widgets::GetX1(id)+(x*64.0), Widgets::GetY2(id), Screen::XALIGN_LEFT, Screen::YALIGN_BOTTOM);
		}

        // bottom right corner
        Screen::DrawImage("UIFONT", "D", Widgets::GetBackColorCurrent(id), Widgets::GetX2(id), Widgets::GetY2(id), Screen::XALIGN_RIGHT, Screen::YALIGN_BOTTOM);
	}
}