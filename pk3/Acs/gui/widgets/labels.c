/*
	Lexicon UI by Tribeam
	With help from Popsoap, Michaelis
*/

strict namespace Label
{
	function int Create(fixed x, fixed y, str font, str t)
	{
		int id = Widgets.Create();
		Widgets.SetRenderText(id, true);
		Widgets.SetFont(id, font);
		Widgets.SetText(id, t);

		Widgets.SetRectPosition(id, x, y, fixed(t.length())*10.0, 1.0);

		return id;
	}
}