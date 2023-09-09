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
        Widgets::SetRenderBack(id, true);
		return id;
	}
}