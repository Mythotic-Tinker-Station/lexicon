

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

	struct imageT images[1024];
	struct sizeT size;
	int blocks;
	int image_amount;
	int nextid;

	// image object
	struct imageT
	{
		struct vec2T pos;
		struct vec2T align;
		str color;
	};


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
			if(i >= image_amount) { return; }
		}
	}

	// clear all hudmessage ids
	function void ResetHudIDs()
	{
		nextid = 0;
	}

	// draw text or an image(alias for hudmessage with font arg and auto id)
	function int Draw(str font, str msg, str color, fixed x, fixed y, fixed xalign = 0.0, fixed yalign = 0.0)
	{
		nextid++;
		setFont(font);
		hudMessage(s:"\c[", s:color, s:"]", s:msg; 0, nextid, 0, x+xalign, y+yalign, 0.01);
		return nextid;
	}
}





