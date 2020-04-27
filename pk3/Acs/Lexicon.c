// written in BCS
#include "../../compiler/lib/zcommon.h"
#library "vote"

strict namespace
{
    #if 1
        #define STATE_INIT -1
        #define STATE_VOTEWAIT 0
        #define STATE_COUNTDOWN 1
        #define STATE_CHECKTIE 2
        #define STATE_RESULTS 3

        #define MAPSET_MAX 192
        #define MAPSET_SECTIONS 3
        #define MAPSET_SECTIONS_MAX 64

        #define PLAYER_MAX 64
    #endif

    /////////////////////
    // vote manager
    /////////////////////
    int votes[MAPSET_MAX];              // holds the votes
    int votessorted[MAPSET_MAX][2];     // all the votes, sorted
    int votecount = 0;                  // amount of votes made

    int time_ticks = 0;                 // the time left in ticks
    int time_seconds = 0;               // the time left in seconds

    int players[PLAYER_MAX];            // all the player info

    int state = STATE_INIT;             // state of the voting system
    int state_clock;                    // custom timer

    /////////////////////
    // hud
    /////////////////////
    fixed hud_width;                    // the position of the right of the screen
    fixed hud_height;                   // the position of the bottom of the screen
    fixed hud_width_half;               // the position of the center of the screen on the x axis
    fixed hud_height_half;              // the position of the center of the screen on the y axis

    struct obj_confetti
    {
        int x;
        int y;
        int velx;
        int vely;
        int animnum;
        int confnum;
        str image;
    };
    struct obj_confetti objs_confetti[128];

    // section names
    str sectionnames[MAPSET_SECTIONS];

    /////////////////////
    // level
    /////////////////////
    int levelstarted = 0;
    int clock = 0;
    int countstart = 0;
    str clockcolor = "\c[Green]";

    // this is where the names that show up in the votes are, and the map names to go to when that wad wins
    str votenames[MAPSET_MAX+1][2] =
    {
        // mapset name                       // the map this vote will take players too
																	// the number a linedef uses to cast the vote
        // Normal mapsets
        { "Nothing",                        "----"          }, 		// 0
        { "Hell on Earth",                  "MAP01"         }, 		// 1
        { "Hell Revealed",                  "HR01"          }, 		// 2
        { "Hell Revealed 2",                "HR201"         }, 		// 3
        { "Kamasutra",                      "KS01"          }, 		// 4
        { "Shai'tans Luck",                 "SL20"          }, 		// 5
        { "Speed Of Doom",                  "SOD01"         }, 		// 6
        { "Vanguard",                       "VAN01"         }, 		// 7
        { "Scythe 2",                       "SC201"         }, 		// 8
		{ "Whispers Of Satan",		        "WOS01"	        }, 		// 9
		{ "UAC Ultra",				        "UAC01"	        }, 		// 10
		{ "Monuments Of Mars",		        "MOM01"	        }, 		// 11
		{ "Khorus's Speedy Shit",	        "KSS01"	        }, 		// 12
		{ "Circle of Caina",		        "COC01"	        }, 		// 13
		{ "Forest Swords",			        "FSW01"	        }, 		// 14
		{ "Doom Core Trilogy",		        "DCOR01"	    }, 		// 15
		{ "Maps of Chaos",	                "MOC01"	        }, 		// 16
		{ "Doom2 The Way ID Did",	        "WID01"         }, 		// 17
		{ "Estranged",				        "EST01"         }, 		// 18
		{ "Going Down",				        "GD01"	        }, 		// 19
		{ "Dark Encounters",		        "DKE01"	        }, 		// 20
        { "Alien Vendetta",                 "AV__01"        }, 		// 21
		{ "Hadephobia",				        "HPH01"         }, 		// 22
		{ "Mayhem 17",				        "MAY01"	        }, 		// 23
		{ "Sunlust",				        "SLU01"	        }, 		// 24
		{ "Hellbound",				        "HLB01"         }, 		// 25
		{ "1994 Tune Up Community Project", "94TU01"        }, 		// 26
		{ "Unholy Realms",			        "UHR01"	        }, 		// 27
        { "Hell Core",			            "HC01"	        }, 		// 28
        { "Ancient Aliens",			        "AA101"	        }, 		// 29
        { "Valiant",			            "VAL01"	        }, 		// 30
        { "Epic",			                "EP101"	        }, 		// 31
        { "Epic 2",			                "EP201"	        }, 		// 32
        { "Nova",			                "NV101"	        }, 		// 33
        { "Community Chest 1",			    "CC101"	        }, 		// 34
        { "Community Chest 2",			    "CC201"	        }, 		// 35
        { "Community Chest 3",			    "CC301"	        }, 		// 36
        { "Community Chest 4",			    "CC401"	        }, 		// 37
        { "Stardate 20x6",			        "SD601"	        }, 		// 38
        { "Stardate 20x7",			        "SD701"	        }, 		// 39
        { "Swim With The Whales",			"SW101"	        }, 		// 40
        { "Congestion 1024",			    "TT101"	        }, 		// 41
        { "Clausterphobia 2",			    "TT201"	        }, 		// 42
        { "Clausterphobia",			        "TT301"	        }, 		// 43
        { "Chainworm",			            "CW101"	        }, 		// 44
        { "Back to Saturn X - EP1",			"BTSX01"	    }, 		// 45
        { "Zones Of Fear",			        "ZOF01"	        }, 		// 46
        { "Zone 300",			            "ZTH01"	        }, 		// 47
        { "Interception",			        "INT01"	        }, 		// 48
        { "Doom2 Redux",			        "REDX01"	    }, 		// 49
        { "*Knee-Deep in the Dead",		    "E1M1"	        }, 		// 50
        { "*The Shores of Hell",		    "E2M1"	        }, 		// 51
        { "*Inferno",			            "E3M1"	        }, 		// 52
        { "*Thy Flesh Consumed",			"E4M1"	        }, 		// 53
        { "*Sigil",			                "E5M1"	        }, 		// 54
        { "*No Rest For The Living",	    "NV_MAP01"	    }, 		// 55
        { "*The Master Levels",			    "ML_MAP01"	    }, 		// 56
        { "*TNT: Evilution",			    "TN_MAP01"	    }, 		// 57
        { "*The Plutonia Experiment",		"PL_MAP01"	    }, 		// 58
        { "Unused",			                "MAP01"	        }, 		// 59
        { "Unused",			                "MAP01"	        }, 		// 60
        { "Unused",			                "MAP01"	        }, 		// 61
        { "Unused",			                "MAP01"	        }, 		// 62
        { "Unused",			                "MAP01"	        }, 		// 63
        { "Unused",			                "MAP01"	        }, 		// 64

        // Slaughter Mapsets
        { "Combat Shock",                   "CS01"             }, 	// 65
        { "Combat Shock 2",                 "CS201"            }, 	// 66
        { "New Gothic Movement 1",          "NG101"            }, 	// 67
        { "Dark Tartarus",                  "TAT01"            }, 	// 68
		{ "Sunder",					        "SND01"            }, 	// 69
		{ "Drown in Blood",			        "DIB01"	           }, 	// 70
		{ "Swift Death",			        "SDE01"            }, 	// 71
        { "Deus Vult",				        "DV01"	           }, 	// 72
        { "Pizza Steve",			        "PIZ01"            }, 	// 73
        { "Deus Vult 2",			        "DV201"            }, 	// 74
        { "SlaughterFest 2012",			    "SF201"            }, 	// 75
        { "New Gothic Movement 2",			"NG201"            }, 	// 76
        { "SlaughterFest 2013",			    "SF301"            }, 	// 77
        { "Chillax",			            "CHX01"            }, 	// 78
        { "Destination Unknown",			"DU101"            }, 	// 79
        { "Unused",			                "MAP01"            }, 	// 80
        { "Unused",			                "MAP01"            }, 	// 81
        { "Unused",			                "MAP01"            }, 	// 82
        { "Unused",			                "MAP01"            }, 	// 83
        { "Unused",			                "MAP01"            }, 	// 84
        { "Unused",			                "MAP01"            }, 	// 85
        { "Unused",			                "MAP01"            }, 	// 86
        { "Unused",			                "MAP01"            }, 	// 87
        { "Unused",			                "MAP01"            }, 	// 88
        { "Unused",			                "MAP01"            }, 	// 89
        { "Unused",			                "MAP01"            }, 	// 90
        { "Unused",			                "MAP01"            }, 	// 91
        { "Unused",			                "MAP01"            }, 	// 92
        { "Unused",			                "MAP01"            }, 	// 92
        { "Unused",			                "MAP01"            }, 	// 94
        { "Unused",			                "MAP01"            }, 	// 95
        { "Unused",			                "MAP01"            }, 	// 96
        { "Unused",			                "MAP01"            }, 	// 97
        { "Unused",			                "MAP01"            }, 	// 98
        { "Unused",			                "MAP01"            }, 	// 99
        { "Unused",			                "MAP01"            }, 	// 100
        { "Unused",			                "MAP01"            }, 	// 101
        { "Unused",			                "MAP01"            }, 	// 102
        { "Unused",			                "MAP01"            }, 	// 103
        { "Unused",			                "MAP01"            }, 	// 104
        { "Unused",			                "MAP01"            }, 	// 105
        { "Unused",			                "MAP01"            }, 	// 106
        { "Unused",			                "MAP01"            }, 	// 107
        { "Unused",			                "MAP01"            }, 	// 108
        { "Unused",			                "MAP01"            }, 	// 109
        { "Unused",			                "MAP01"            }, 	// 110
        { "Unused",			                "MAP01"            }, 	// 111
        { "Unused",			                "MAP01"            }, 	// 112
        { "Unused",			                "MAP01"            }, 	// 113
        { "Unused",			                "MAP01"            }, 	// 114
        { "Unused",			                "MAP01"            }, 	// 115
        { "Unused",			                "MAP01"            }, 	// 116
        { "Unused",			                "MAP01"            }, 	// 117
        { "Unused",			                "MAP01"            }, 	// 118
        { "Unused",			                "MAP01"            }, 	// 119
        { "Unused",			                "MAP01"            }, 	// 120
        { "Unused",			                "MAP01"            }, 	// 121
        { "Unused",			                "MAP01"            }, 	// 122
        { "Unused",			                "MAP01"            }, 	// 123
        { "Unused",			                "MAP01"            }, 	// 124
        { "Unused",			                "MAP01"            }, 	// 125
        { "Unused",			                "MAP01"            }, 	// 126
        { "Unused",			                "MAP01"            }, 	// 127
        { "Unused",			                "MAP01"            }, 	// 128

        // Single Levels
		{ "The Spire",				        "TSP01"            }, 	// 129
		{ "The Eye",				        "EYE01"            }, 	// 130
        { "Sens",			                "HP103"            }, 	// 131
        { "A Clear Line Drawn",	            "AAA01"            }, 	// 132
        { "The Spire 2",			        "TSP201"           }, 	// 133
        { "Unused",			                "MAP01"            }, 	// 134
        { "Unused",			                "MAP01"            }, 	// 135
        { "Unused",			                "MAP01"            }, 	// 136
        { "Unused",			                "MAP01"            }, 	// 137
        { "Unused",			                "MAP01"            }, 	// 138
        { "Unused",			                "MAP01"            }, 	// 139
        { "Unused",			                "MAP01"            }, 	// 140
        { "Unused",			                "MAP01"            }, 	// 141
        { "Unused",			                "MAP01"            }, 	// 142
        { "Unused",			                "MAP01"            }, 	// 143
        { "Unused",			                "MAP01"            }, 	// 144
        { "Unused",			                "MAP01"            }, 	// 145
        { "Unused",			                "MAP01"            }, 	// 146
        { "Unused",			                "MAP01"            }, 	// 147
        { "Unused",			                "MAP01"            }, 	// 148
        { "Unused",			                "MAP01"            }, 	// 149
        { "Unused",			                "MAP01"            }, 	// 150
        { "Unused",			                "MAP01"            }, 	// 151
        { "Unused",			                "MAP01"            }, 	// 152
        { "Unused",			                "MAP01"            }, 	// 153
        { "Unused",			                "MAP01"            }, 	// 154
        { "Unused",			                "MAP01"            }, 	// 155
        { "Unused",			                "MAP01"            }, 	// 156
        { "Unused",			                "MAP01"            }, 	// 157
        { "Unused",			                "MAP01"            }, 	// 158
        { "Unused",			                "MAP01"            }, 	// 159
        { "Unused",			                "MAP01"            }, 	// 160
        { "Unused",			                "MAP01"            }, 	// 161
        { "Unused",			                "MAP01"            }, 	// 162
        { "Unused",			                "MAP01"            }, 	// 163
        { "Unused",			                "MAP01"            }, 	// 164
        { "Unused",			                "MAP01"            }, 	// 165
        { "Unused",			                "MAP01"            }, 	// 166
        { "Unused",			                "MAP01"            }, 	// 167
        { "Unused",			                "MAP01"            }, 	// 168
        { "Unused",			                "MAP01"            }, 	// 169
        { "Unused",			                "MAP01"            }, 	// 170
        { "Unused",			                "MAP01"            }, 	// 171
        { "Unused",			                "MAP01"            }, 	// 172
        { "Unused",			                "MAP01"            }, 	// 173
        { "Unused",			                "MAP01"            }, 	// 174
        { "Unused",			                "MAP01"            }, 	// 175
        { "Unused",			                "MAP01"            }, 	// 176
        { "Unused",			                "MAP01"            }, 	// 177
        { "Unused",			                "MAP01"            }, 	// 178
        { "Unused",			                "MAP01"            }, 	// 179
        { "Unused",			                "MAP01"            }, 	// 180
        { "Unused",			                "MAP01"            }, 	// 181
        { "Unused",			                "MAP01"            }, 	// 182
        { "Unused",			                "MAP01"            }, 	// 183
        { "Unused",			                "MAP01"            }, 	// 184
        { "Unused",			                "MAP01"            }, 	// 185
        { "Unused",			                "MAP01"            }, 	// 186
        { "Unused",			                "MAP01"            }, 	// 187
        { "Unused",			                "MAP01"            }, 	// 188
        { "Unused",			                "MAP01"            }, 	// 189
        { "Unused",			                "MAP01"            }, 	// 190
        { "Unused",			                "MAP01"            }, 	// 191
        { "Unused",			                "MAP01"            }, 	// 192
    };

	#if 1

		#include	"lex_util.c"
		#include	"lex_debug.c"
		#include	"lex_hub.c"
		#include	"lex_musicbox.c"
		#include	"lex_level.c"
		#include	"lex_voteskip.c"
		#include 	"lex_sharekey.c"

	#endif


}
























