

#import "../../compiler/lib/zcommon.bcs"
#library "lexicon"

strict namespace
{
	str mapsets[256];
	fixed mapset_count = 256.0;
	#if 1
		#include "util.c"
		#include "gui/screen.c"
		#include "gui/cursor.c"
		#include "gui/gui.c"
		#include "gui/widgets/button.c"
		#include "replacer.c"
		#include "patches.c"
	#endif
}
