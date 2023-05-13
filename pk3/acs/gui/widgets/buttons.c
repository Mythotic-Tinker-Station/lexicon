/*
	Lexicon UI by Tribeam
	With help from Popsoap, Michaelis
*/


strict namespace Button
{
	function int Create(fixed x, fixed y, fixed width, fixed height, str t)
	{
		int id = Widgets::Create();

		Widgets::SetRectPosition(id, x, y, width, height);

		// make it clickable and hoverable
		Widgets::SetClickable(id, true);
		Widgets::SetHoverable(id, true);

		Widgets::SetRenderText(id, true);
		Widgets::SetRenderImage(id, true);

		Widgets::SetText(id, t);
		Widgets::SetImage(id, "a");
		return id;
	}
}

strict namespace Button64
{
	function int Create(fixed x, fixed y, str t)
	{
		int id = Button::Create(x, y, 64.0, 24.0, t);
		Widgets::SetImage(id, "b");
		return id;
	}
}

strict namespace Button96
{
	function int Create(fixed x, fixed y, str t)
	{
		int id = Button::Create(x, y, 96.0, 24.0, t);
		Widgets::SetText(id, t);
		Widgets::SetImage(id, "c");
		return id;
	}
}

strict namespace Button128
{
	function int Create(fixed x, fixed y, str t)
	{
		int id = Button::Create(x, y, 128.0, 24.0, t);
		Widgets::SetText(id, t);
		Widgets::SetImage(id, "d");
		return id;
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
			Screen::Draw("UI_BTN1", "a", Widgets::GetBackColorCurrent(id), Widgets::GetX1(id), Widgets::GetY1(id), Screen::XALIGN_LEFT, Screen::YALIGN_TOP);
		}
		else if(Widgets::GetHovered(id) && !Widgets::GetChecked(id))
		{
			Screen::Draw("UI_BTN2", "a", Widgets::GetBackColorCurrent(id), Widgets::GetX1(id), Widgets::GetY1(id), Screen::XALIGN_LEFT, Screen::YALIGN_TOP);
		}
		else if(Widgets::GetChecked(id))
		{
			Screen::Draw("UI_BTN3", "a", Widgets::GetBackColorCurrent(id), Widgets::GetX1(id), Widgets::GetY1(id), Screen::XALIGN_LEFT, Screen::YALIGN_TOP);
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
		Widgets::SetFont(id, "SMALLFONT");
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
			Screen::Draw("UI_FADE", "a", Widgets::GetBackColorCurrent(id), Widgets::GetX1(id), Widgets::GetY1(id), Screen::XALIGN_LEFT, Screen::YALIGN_TOP);
			Screen::Draw("UI_MAP", "a", Widgets::GetBackColorCurrent(id), Widgets::GetX1(id), Widgets::GetY1(id), Screen::XALIGN_LEFT, Screen::YALIGN_TOP);
		}
		else
		{
			Screen::Draw("UI_MAP2", "a", Widgets::GetBackColorCurrent(id), Widgets::GetX1(id), Widgets::GetY1(id), Screen::XALIGN_LEFT, Screen::YALIGN_TOP);
		}
	}
}








