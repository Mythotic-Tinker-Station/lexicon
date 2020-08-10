/*
	Lexicon UI by Tribeam
	With help from Popsoap, Michaelis
*/



strict namespace Cursor
{

	// the T at the end of this name is a special BCS thing
	// see: https://github.com/wormt/bcc/wiki/Declarations#type-names

	// cursor object

	int buttons;			// button flags
	int image;				// image id to draw(cursor)
	int image2;				// image id to draw(shadow)
	bool clicked;			// true if the user is clicking the mouse
	bool clicked_prev;		// value of the click from the previous frame
	struct vec2T pos;		// cursor x/y position
	struct vec2T delta;		// amount to add to x/y
	struct vec2T calc;		// calculation of pos with delta and user's sens settings

	function void Init()
	{
		// set the cursor to the center of the screen on start
		pos.x = Screen.size.wh;
		pos.y = Screen.size.hh;
	}

	function void Run()
	{
		// player input
		delta.x = fixed(getPlayerInput(-1, INPUT_YAW));
		delta.y = fixed(getPlayerInput(-1, INPUT_PITCH));
		buttons = getPlayerInput(-1, INPUT_BUTTONS);

		// maths
		calc.x = -fixed(int(delta.x / (51.0 - fixed(getCVar("lexicon_cursor_xsens")))));
		calc.y = -fixed(int(delta.y / (51.0 - fixed(getCVar("lexicon_cursor_ysens")))));

		// set position
		if(delta.x != 0.0) { pos.x += calc.x; }
		if(delta.y != 0.0) { pos.y += calc.y; }

		// bounds
		if(pos.x < 0.0) 			{ pos.x = 0.0; }
		if(pos.y < 0.0) 			{ pos.y = 0.0; }
		if(pos.x > Screen.size.w) 	{ pos.x = Screen.size.w; }
		if(pos.y > Screen.size.h) 	{ pos.y = Screen.size.h; }

		// if mouse1 is pressed
		if(buttons & BT_ATTACK)
		{
			clicked = true;
		}
		else
		{
			clicked = false;
		}

		Screen.Draw("CURSORFONT", "a", getCVarString("lexicon_cursor_color"), pos.x, pos.y, Screen.XALIGN_LEFT, Screen.YALIGN_TOP, 1);

		// render shadow
		if((bool)getCVar("lexicon_cursor_shadow") == true)
		{
			Screen.Draw("CURSORFONT", "b", "", pos.x, pos.y, Screen.XALIGN_LEFT, Screen.YALIGN_TOP, 2);
		}


		clicked_prev = clicked;
	}
}




