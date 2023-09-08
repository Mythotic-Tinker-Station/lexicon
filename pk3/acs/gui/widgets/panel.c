/*
	Lexicon UI by Tribeam
	With help from Popsoap, Michaelis
*/

strict namespace Panel
{

	function int Create(int size, fixed x, fixed y, fixed w, fixed h)
	{
		// create a new widget object
		int id = Widgets::Create();

		// position
		Widgets::SetRectPosition(id, x, y, w, h);

		// add hooks to events
		Widgets::AddUpdateHook(id, Event_Update);

        Widgets::SetArg1Int(id, size);

		return id;
	}

	function void Event_Update(int id)
	{
        // this is broken in zandronum
        //SetHudClipRect(int(Widgets::GetX1(id)), int(Widgets::GetY1(id)), int(Widgets::GetWidth(id)), int(Widgets::GetHeight(id)), 0, true);

        fixed size = fixed(Widgets::GetArg1Int(id));
		fixed cols = fixed(int(Widgets::GetWidth(id)/ size))-1.0;
		fixed rows = fixed(int(Widgets::GetHeight(id)/ size))-1.0;

        string c = "A";
        switch(size)
        {
            case 8: c = "A"; break;
            case 16: c = "B"; break;
            case 32: c = "C"; break;
            case 64: c = "D"; break;
            case 128: c = "E"; break;
        }

        // top right and middle
		for(fixed x = 0.0; x <= cols; x += 1.0)
		{
			for(fixed y = 0.0; y <= rows; y += 1.0)
			{
				Screen::DrawImage("UIFONT", c, Widgets::GetBackColorCurrent(id), Widgets::GetX1(id)+(x* size), Widgets::GetY1(id)+(y* size), Screen::XALIGN_LEFT, Screen::YALIGN_TOP);
			}
		}

        // right
		for(fixed y = 0.0; y <= rows; y += 1.0)
		{
			Screen::DrawImage("UIFONT", c, Widgets::GetBackColorCurrent(id), Widgets::GetX2(id), Widgets::GetY1(id)+(y* size), Screen::XALIGN_RIGHT, Screen::YALIGN_TOP);
		}

        // bottom
		for(fixed x = 0.0; x <= cols; x += 1.0)
		{
			Screen::DrawImage("UIFONT", c, Widgets::GetBackColorCurrent(id), Widgets::GetX1(id)+(x* size), Widgets::GetY2(id), Screen::XALIGN_LEFT, Screen::YALIGN_BOTTOM);
		}

        // bottom right corner
        Screen::DrawImage("UIFONT", c, Widgets::GetBackColorCurrent(id), Widgets::GetX2(id), Widgets::GetY2(id), Screen::XALIGN_RIGHT, Screen::YALIGN_BOTTOM);
	}
}