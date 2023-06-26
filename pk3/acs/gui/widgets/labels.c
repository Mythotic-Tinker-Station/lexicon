/*
	Lexicon UI by Tribeam
	With help from Popsoap, Michaelis
*/

strict namespace Label
{
	function int Create(fixed x, fixed y, int font, str t)
	{
		int id = Widgets::Create();
		Widgets::SetRenderText(id, true);
		Widgets::SetFont(id, font);
		Widgets::SetText(id, t);
		Widgets::SetRectPosition(id, x, y, fixed(StrLen(t))*Font::GetCharWidth(font), 1.0);

		return id;
	}
}