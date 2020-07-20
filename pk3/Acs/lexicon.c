

#include "../../compiler/lib/zcommon.h"
#library "lexicon"

strict namespace
{

	str mapsets[256];
	#if 1
		#include "lex_gui.c"
		#include "scn_firsttime.c"
		#include "scn_selection.c"

		#include "patches.c"
	#endif
}



