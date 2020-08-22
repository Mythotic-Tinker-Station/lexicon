/*
	Lexicon Scripts by Tribeam
	With help from Popsoap, Michaelis
*/

#import "../../compiler/lib/zcommon.bcs"
#library "lexicon"

strict namespace
{
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
		str clicked;
		str hovered;
		str current;
	};

	str mapsets[256];
	fixed mapset_count = 256.0;
	#if 1
		#include "util.c"
		#include "gui/screen.c"
		#include "gui/cursor.c"
		#include "gui/widgets.c"
		#include "gui/gui.c"
		//#include "gui/widgets/panel.c"	// an idea that was never used
		#include "gui/widgets/button.c"
		#include "replacer.c"
		#include "patches.c"
	#endif
}
