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
		str credits;					// mapset credits
		str mapcount;					// mapset map count
		str startmap;					// mapset starting map name
		str thumbnail;					// mapset ui thumbnail
		str pistol;						// mapset pistol
		str fist;						// mapset fist
		str previews[32];				// mapset screenshots
		str readme[256];				// mapset readme pages
		str replacers[256][2];			// mapset actor replacers
		str startitems[32];				// mapset start items
		int startamounts[32];			// mapset start amounts
		str takeitems[32];				// mapset take items
		int takeamounts[32];			// mapset take amounts
		int startitem_count;			// amount of start items
		int takeitem_count;				// amount of take items
		int replacer_count;				// amount of replacer defines

		int id;
	};


	struct mapset mapsets[256];			// holds all the mapset info
	int mapset_count = 0;				// how many mapsets exist

	#if 1
		#include "util.c"
		#include "gui/screen.c"
		#include "gui/cursor.c"
		#include "gui/widgets.c"
		#include "gui/gui.c"
		#include "gui/widgets/buttons.c"
		#include "gui/scenes/debugmenu.c"
		#include "replacer.c"
		#include "patches.c"
		#include "expansion.c"
		#include "keys.c"
	#endif

	function void ManageItems()
	{
		int mapset_current = GetCVar("lexicon_current_mapset");
		for(int i = 0; i < mapsets[mapset_current].startitem_count; i++)
		{
			GiveInventory(mapsets[mapset_current].startitems[i], mapsets[mapset_current].startamounts[i]);
		}
		for(int i = 0; i < mapsets[mapset_current].takeitem_count; i++)
		{
			TakeInventory(mapsets[mapset_current].takeitems[i], mapsets[mapset_current].takeamounts[i]);
		}
	}

	Script "Enter" enter
	{
		DebugMenu.ApplyCheats();
		ManageItems();
	}

	Script "Respawn" respawn
	{
		DebugMenu.ApplyCheats();
		ManageItems();
	}

}

