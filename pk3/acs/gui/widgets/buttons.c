/*
	Lexicon UI by Tribeam
	With help from Popsoap, Michaelis
*/


strict namespace Button
{
	function int Create(fixed x, fixed y, fixed w, fixed h, str t)
	{
		int id = Widgets::Create();

		Widgets::SetRectPosition(id, x, y, w, h);

		// make it clickable and hoverable
		Widgets::SetClickable(id, true);
		Widgets::SetHoverable(id, true);

		Widgets::SetText(id, t);

        Widgets::SetTextOffsetY(id, Font::GetCharHeight(Widgets::GetFont(id)));

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
		return id;
	}
}







