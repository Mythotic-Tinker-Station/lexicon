/*
	Lexicon Scripts by Tribeam
	With help from Popsoap, Michaelis
*/

#import "../../compiler/lib/zcommon.bcs"
#library "lexicon"


//strict namespace
//{

	// size
	struct sizeT
	{
		fixed w;
		fixed h;
		fixed wh;
		fixed hh;
	};

	// 2d point
	struct vec2T
	{
		fixed x;
		fixed y;
	};

	// 3d point
	struct vec3T
	{
		fixed x;
		fixed y;
		fixed z;
	};

	// 2 2d points
	struct vec2x2T
	{
		fixed x1;
		fixed y1;
		fixed x2;
		fixed y2;
	};

	struct colors
	{
		str normal;
		str disabled;
		str clicked;
		str hovered;
		str current;
	};

	struct mapset
	{
		str acronym;					// mapset acronym
		str name;						// mapset name
		str description;				// mapset description
		str credits;					// mapset credits
		str mapcount;					// mapset map count
		str startmap;					// mapset starting map name
		str thumbnail;					// mapset ui thumbnail
		str previews[32];				// mapset screenshots
		str readme[256];				// mapset readme pages
		str replacers[256][2];			// mapset actor replacers
	};

	struct mapset mapsets[256];			// holds all the mapset info
	int mapset_count = 0;				// how many mapsets exist
	int mapset_current = 0;				// the currently loaded mapset

	#if 1
		#include "util.c"
		#include "gui/screen.c"
		#include "gui/cursor.c"
		#include "gui/widgets.c"
		#include "gui/gui.c"
		#include "gui/widgets/button.c"
		#include "gui/scenes/firsttimer.c"
		#include "replacer.c"
		#include "patches.c"
		#include "expansion.c"
	#endif
//}

