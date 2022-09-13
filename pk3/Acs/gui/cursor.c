/*
	Lexicon UI by Tribeam
	With help from Popsoap, Michaelis

	fixed Cursor.GetX() 						// returns the x position of the cursor
	fixed Cursor.GetY() 						// returns the y position of the cursor
	fixed Cursor.GetDeltaX() 					// returns the delta x of the cursor (the amount of movement to make on the x axis)
	fixed Cursor.GetDeltaY() 					// returns the delta y of the cursor (the amount of movement to make on the y axis)

	// get flags
	bool Cursor.GetClicked() 					// returns if the cursor is clicked
	bool Cursor.GetClickedPrev() 				// returns if the cursor was clicked on the previous frame

	// get buttons
	int Cursor.GetButtons() 					// returns what buttons the player is pressing

	// set positions
	void Cursor.SetX(fixed value) 				// sets the x position of the cursor
	void Cursor.SetY(fixed value) 				// sets the y position of the cursor
	void Cursor.SetDeltaX(fixed value) 			// sets the delta x position of the cursor (the amount of movement to make on the x axis)
	void Cursor.SetDeltaY(fixed value) 			// sets the delta y position of the cursor (the amount of movement to make on the y axis)

	// set flags
	void Cursor.SetClicked(bool value) 			// sets if the cursor is clicked
	void Cursor.SetClickedPrev(bool value) 		// sets if the cursor was clicked on the previous frame

	void Init()
*/



strict namespace Cursor
{

	// the T at the end of this name is a special BCS thing
	// see: https://github.com/wormt/bcc/wiki/Declarations#type-names

	// cursor object

	int buttons;			// button flags

	bool clicked;			// true if the user is clicking the mouse
	bool clicked_prev;		// value of the click from the previous frame
	struct vec2T pos;		// cursor x/y position
	struct vec2T delta;		// amount to add to x/y
	struct vec2T calc;		// calculation of pos with delta and user's sens settings

	// get positions
	function fixed GetX() 						{ return pos.x; }
	function fixed GetY() 						{ return pos.y; }
	function fixed GetDeltaX() 					{ return delta.x; }
	function fixed GetDeltaY() 					{ return delta.y; }

	// get flags
	function bool GetClicked() 					{ return clicked; }
	function bool GetClickedPrev() 				{ return clicked_prev; }

	// get buttons
	function int GetButtons() 					{ return buttons; }

	// set positions
	function void SetX(fixed value) 			{ pos.x = value; }
	function void SetY(fixed value) 			{ pos.y = value; }
	function void SetDeltaX(fixed value) 		{ delta.x = value; }
	function void SetDeltaY(fixed value) 		{ delta.y = value; }


	// set flags
	function void SetClicked(bool value) 		{ clicked = value; }
	function void SetClickedPrev(bool value) 	{ clicked_prev = value; }

	function void Init()
	{
		// set the cursor to the center of the screen on start
		pos.x = Screen.GetCenterX();
		pos.y = Screen.GetCenterY();
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
		if(pos.x < 0.0) 				{ pos.x = 0.0; }
		if(pos.y < 0.0) 				{ pos.y = 0.0; }
		if(pos.x > Screen.GetWidth()) 	{ pos.x = Screen.GetWidth(); }
		if(pos.y > Screen.GetHeight()) 	{ pos.y = Screen.GetHeight(); }

		// if mouse1 is pressed
		clicked_prev = clicked;
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
	}
}




