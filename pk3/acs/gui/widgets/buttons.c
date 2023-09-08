/*
	Lexicon UI by Tribeam
	With help from Popsoap, Michaelis
*/


strict namespace Button
{
    int panels[1024];
    int panelcount;
	function int Create(fixed x, fixed y, fixed w, fixed h, str t)
	{
		int id = Widgets::Create();

		Widgets::SetRectPosition(id, x, y, w, h);

		// make it clickable and hoverable
		Widgets::SetClickable(id, true);
		Widgets::SetHoverable(id, true);

		Widgets::SetRenderText(id, true);
		Widgets::SetRenderImage(id, true);

		Widgets::SetText(id, t);
		Widgets::SetImage(id, "a");

        Widgets::SetTextOffsetY(id, Font::GetCharHeight(Widgets::GetFont(id))-(y/2.0));

        Widgets::AddMovedHook(id, Event_Move);

        panels[id] = Panel::Create(x, y, w, h);
        panelcount++;

		return id;
	}

    function void Event_Move(int id)
	{
        Widgets::SetRectPosition(panels[id], Widgets::GetX1(id), Widgets::GetY1(id), Widgets::GetWidth(id), Widgets::GetHeight(id));
    }
}




strict namespace ButtonCheck
{
	function int Create(fixed x, fixed y, str t)
	{
		int id = Button::Create(x, y, 128.0, 24.0, t);
		Widgets::SetText(id, t);
		Widgets::SetCheckable(id, true);
		Widgets::AddUpdateHook(id, Event_Update);
		return id;
	}

	function void Event_Update(int id)
	{
		if(!Widgets::GetHovered(id) && !Widgets::GetChecked(id))
		{
			Screen::DrawImage("UI_BTN1", "a", Widgets::GetBackColorCurrent(id), Widgets::GetX1(id), Widgets::GetY1(id), Screen::XALIGN_LEFT, Screen::YALIGN_TOP);
		}
		else if(Widgets::GetHovered(id) && !Widgets::GetChecked(id))
		{
			Screen::DrawImage("UI_BTN2", "a", Widgets::GetBackColorCurrent(id), Widgets::GetX1(id), Widgets::GetY1(id), Screen::XALIGN_LEFT, Screen::YALIGN_TOP);
		}
		else if(Widgets::GetChecked(id))
		{
			Screen::DrawImage("UI_BTN3", "a", Widgets::GetBackColorCurrent(id), Widgets::GetX1(id), Widgets::GetY1(id), Screen::XALIGN_LEFT, Screen::YALIGN_TOP);
		}
	}
}


strict namespace ButtonImage
{
	function int Create(fixed x, fixed y, str img, str t)
	{
		int id = Button::Create(x, y, 192.0, 108.0, t);
		//Widgets::SetText(id, t);
		Widgets::SetImage(id, img);
		Widgets::SetTextOffsetY(id, 7.0);
		Widgets::SetBackColorNormal(id, "");
		Widgets::SetBackColorHovered(id, "");
		Widgets::SetBackColorClicked(id, "");
		Widgets::AddUpdateHook(id, Event_Update);
		return id;
	}

	function void Event_Update(int id)
	{

		if(!Widgets::GetHovered(id))
		{
			Screen::DrawImage("UI_FADE", "a", Widgets::GetBackColorCurrent(id), Widgets::GetX1(id), Widgets::GetY1(id), Screen::XALIGN_LEFT, Screen::YALIGN_TOP);
			Screen::DrawImage("UI_MAP", "a", Widgets::GetBackColorCurrent(id), Widgets::GetX1(id), Widgets::GetY1(id), Screen::XALIGN_LEFT, Screen::YALIGN_TOP);
		}
		else
		{
			Screen::DrawImage("UI_MAP2", "a", Widgets::GetBackColorCurrent(id), Widgets::GetX1(id), Widgets::GetY1(id), Screen::XALIGN_LEFT, Screen::YALIGN_TOP);
		}
	}
}








