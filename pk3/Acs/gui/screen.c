/*
	Lexicon UI by Tribeam
	With help from Popsoap, Michaelis

	Screen namespace:
		fixed 	Screen::GetWidth() 			// returns the width of the screen
		fixed 	Screen::GetHeight() 			// returns the height of the screen
		fixed 	Screen::GetWidthHalf() 		// returns the center x of the screen
		fixed 	Screen::GetHeightHalf() 		// returns the center y of the screen
		bool 	Screen::GetScreenBlocks() 	// returns the screenblocks cvar
		int 	Screen::GetNextID() 			// returns the nextid to be used
		void 	Screen::Init()				// Setup the screen;
		void 	Screen::Clear()				// Clear out all hudmessages;
		void 	Screen::ResetHudIDs()		// resets the hudmessage id counter;

		// alias to hudmessage with auto id and alignment, returns the id used
		int Screen::Draw(str font, str msg, str color, fixed x, fixed y, fixed xalign = 0.0, fixed yalign = 0.0, int id = -1)
*/

strict namespace Screen
{
	enum : fixed
	{
		// Hud alignment
		XALIGN_CENTER 			= 0.0,				// Align center of text to the x position
		XALIGN_LEFT 			= 0.1,				// Align left of text to the x position
		XALIGN_RIGHT 			= 0.2,				// Align right of text to the x position
		XALIGN_BOXCENTER 		= 0.4,				// What
		XALIGN_BOXLEFT 			= 0.5,				// What
		XALIGN_BOXRIGHT 		= 0.6,				// What

		YALIGN_CENTER 			= 0.0,				// Align center of text to the y position
		YALIGN_TOP 				= 0.1,				// Align the top of text to the y position
		YALIGN_BOTTOM 			= 0.2,				// Align the bottom of text to the y position
	};

	struct sizeT size;
	int blocks;
	int nextid;

	function fixed GetWidth() 				{ return size.w; }
	function fixed GetHeight() 				{ return size.h; }
	function fixed GetCenterX() 			{ return size.wh; }
	function fixed GetCenterY() 			{ return size.hh; }
	function bool GetScreenBlocks() 		{ return Bool(blocks); }
	function int GetNextID() 				{ return nextid; }

	// setup Screen size and some variables
	function void Init()
	{
		int vw = GetCVar("vid_defwidth");
		int vh = GetCVar("vid_defheight");

		size.w = fixed(vw);
		size.h = fixed(vh);
		size.wh = size.w/2.0;
		size.hh = size.h/2.0;
		blocks = GetCVar("Screenblocks");
		SetHudSize(vw, vh, true);
	}

	// clear all hudmessage ids
	function void Clear()
	{
		for(int i = 0; i < 65535; i++)
		{
			hudmessage(s:""; 0, i, 0, 0.0, 0.0, 0.0);
		}
	}

	// clear all hudmessage ids
	function void ResetHudIDs()
	{
		nextid = 65535;
	}

	// draw text or an image(alias for hudmessage with font arg and auto id)
	function int Draw(str font, str msg, str color, fixed x, fixed y, fixed xalign = 0.0, fixed yalign = 0.0, int id = -1)
	{
		nextid--;
		setFont(font);

		if(id > -1)
		{
			hudMessage(s:"\c[", s:color, s:"]", s:msg; 0, id, 0, x+xalign, y+yalign, 0.1);
		}
		else
		{
			hudMessage(s:"\c[", s:color, s:"]", s:msg; 0, nextid, 0, x+xalign, y+yalign, 0.1);
		}
		return nextid;
	}
}





