

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

	// create an image object
	function int ImageCreate(fixed x, fixed y, str color = "White", fixed xalign = 0.0, fixed yalign = 0.0)
	{
		image_amount++;
		images[image_amount].pos.x = x;
		images[image_amount].pos.y = y;
		images[image_amount].align.x = xalign;
		images[image_amount].align.y = yalign;
		images[image_amount].color = color;
		return image_amount;
	}



	// draw an image object
	// sending the font string here has to happen because of volatile strings(they last only 1 tic)
	function int ImageDraw(int id, str font)
	{
		nextid++;
		setFont(font);
		hudMessage(s:"\c[", s:images[id].color, s:"]", s:"a"; 0, nextid, 0, images[id].pos.x+images[id].align.x, images[id].pos.y+images[id].align.y, 0.1);
		return nextid;
	}

	// set the position of an image object
	function void ImageSetPos(int id, fixed x, fixed y)
	{
		images[id].pos.x = x;
		images[id].pos.y = y;
	}

	// set the origin alignment of an image object
	function void ImageSetAlignments(int id, fixed x, fixed y)
	{
		images[id].align.x = x;
		images[id].align.y = y;
	}
}
