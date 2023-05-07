/*
	Lexicon Scripts by Tribeam, Popsoap, Michaelis
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

	struct colorsT
	{
		str normal;
		str disabled;
		str clicked;
		str hovered;
		str checked;
		str current;
	};

	struct mapset
	{
		str acronym;					// mapset acronym
		str name;						// mapset name
		str description;				// mapset description
		str mapcount;					// mapset map count
		str startmap;					// mapset starting map name
		str thumbnail;					// mapset ui thumbnail
		str pistol;						// mapset pistol
		str fist;						// mapset fist
		str previews[32];				// mapset screenshots
		str readme[256];				// mapset readme pages
		str credits[256];				// mapset credits
		str replacers[256][2];			// mapset actor replacers
		str startitems[32];				// mapset start items
		str takeitems[32];				// mapset take items
		int startitem_count;			// amount of start items
		int takeitem_count;				// amount of take items
		int replacer_count;				// amount of replacer defines

		int id;
	};


	struct mapset mapsets[2048];	    // holds all the mapset info
	int mapset_count = 0;				// how many mapsets exist

	#if 1
		#include "util.c"
		#include "gui/screen.c"
		#include "gui/cursor.c"
		#include "gui/widgets.c"
		#include "gui/gui.c"
		#include "gui/widgets/buttons.c"
		#include "gui/widgets/labels.c"
		#include "gui/scenes/votemenu.c"
		#include "replacer.c"
		#include "patches.c"
		#include "expansion.c"
		#include "keys.c"
	#endif

	Script "Lexicon_Open" Open
	{
	}

	Script "Lexicon_Enter" enter
	{
		applyCheats();
		Replacer::StartItems();
	}

	Script "Lexicon_Respawn" respawn
	{
		applyCheats();
		Replacer::StartItems();
	}

}

