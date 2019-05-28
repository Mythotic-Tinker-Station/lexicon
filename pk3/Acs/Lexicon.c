// written in BCS
#include "../../compiler/lib/zcommon.h"
#library "vote"

strict namespace
{
    #if 1
    
        //unused
        //#include "skybox.c"

        #define STATE_INIT -1
        #define STATE_VOTEWAIT 0
        #define STATE_COUNTDOWN 1
        #define STATE_CHECKTIE 2
        #define STATE_RESULTS 3
        
        #define MAPSET_MAX 192
        #define MAPSET_SECTIONS 3
        #define MAPSET_SECTIONS_MAX 64
        
        #define PLAYER_MAX 64
        
        #define MESSAGE_WELCOME "\c[White]Welcome to the Lexicon\n\n\c[White]-=Alpha version=-\n\n\c[White]Please report any problems you have to our discord via\n\c[Cyan]https://discord.gg/qj9GASW"
        #define MESSAGE_RETURN "Going back to the lexicon in: "
        #define MESSAGE_COMPLETE "\c[White]Congratulations!\n\n\c[White]You and your team have completed\n\c[Gold]"
    
    #endif
    
    // this is where all the lore messages go
    str lore[16] =
    {
        //switch id         // msg
        /* 0  */            "Nothing to see here.",
        /* 1  */            "\c[White]TherianThrope Segment\n\n\c[White]--------------------\n\n\c[White]The Archmage normaly comes to this particular space at his own leisure to read.\n\c[White]This comic strip he left open is from a comic, though may as well be a manga\n\c[White]Called TherianThrope. To Summarise it its about a girl named Aria who happens to have amnesia\n\c[White]And who is hunted by some scary looking monsters known as 'Therianthrope'\n\c[White]The archmage is reminded of demons from hell when looking at this same strip.\n\n\n\c[Cyan] It's a good read, be sure to sub @RigRug on Patreon!",
        /* 2  */            "\c[Gold]The Painting of Afina\n\n\c[White]--------------------\n\n\c[White]You found a rather mysterious painting. By zapping it with your votegun\n\c[White]you received some knowledge. This is a painting of a very powerfull wizard named Afina.\n\c[White]It's rumored she is very beautiful but also a powerfull adept in the school of runic magic\n\c[White]You feel as if theres massive power oozing off the picture. You wonder why out of all places, this picture is here\n\c[White]As you would think, it belongs in a frame. There is more to this painting and you have became curious",
        /* 3  */            "Unused",
        /* 4  */            "Unused",
        /* 5  */            "Unused",
        /* 6  */            "Unused",
        /* 7  */            "Unused",
        /* 8  */            "Unused",
        /* 9  */            "Unused",
        /* 10 */            "Unused",
        /* 11 */            "Unused",
        /* 12 */            "Unused",
        /* 13 */            "Unused",
        /* 14 */            "Unused",
        /* 15 */            "Unused",
    };    
    
    // section names
    str sectionnames[MAPSET_SECTIONS] =
    {
        "\c[Gold](\c[Green]Normal\c[Gold])",
        "\c[Gold](\c[Red]Slaughter\c[Gold])",
        "\c[Gold](\c[LightBlue]Single\c[Gold])",
    };
    
    // this is where the names that show up in the votes are, and the map names to go to when that wad wins
    str votenames[MAPSET_MAX+1][2] =
    {
        // mapset name                       // the map this vote will take players too
                                                                // the number a linedef uses to cast the vote
        // Normal mapsets
        { "Nothing",                        "----"          }, // 0
        { "Doom 2",                         "MAP01"         }, // 1
        { "Hell Revealed",                  "HR01"          }, // 2
        { "Hell Revealed 2",                "HR201"         }, // 3
        { "Kamasutra",                      "KS01"          }, // 4
        { "Shai'tans Luck",                 "SL20"          }, // 5
        { "Speed Of Doom",                  "SOD01"         }, // 6
        { "Vanguard",                       "VAN01"         }, // 7
        { "Scythe 2",                       "SC201"         }, // 8
		{ "Whispers Of Satan",		        "WOS01"	        }, // 9
		{ "UAC Ultra",				        "UAC01"	        }, // 10
		{ "Monuments Of Mars",		        "MOM01"	        }, // 11
		{ "Khorus's Speedy Shit",	        "KSS01"	        }, // 12
		{ "Circle of Caina",		        "COC01"	        }, // 13
		{ "Forest Swords",			        "FSW01"	        }, // 14
		{ "Doom Core Trilogy",		        "DC01"	        }, // 15
		{ "Maps of Chaos",	                "MOC01"	        }, // 16
		{ "Doom 2 The Way ID Did",	        "WID01"         }, // 17
		{ "Estranged",				        "EST01"         }, // 18
		{ "Going Down",				        "GD01"	        }, // 19
		{ "Dark Encounters",		        "DKE01"	        }, // 20
        { "Alien Vendetta",                 "AV01"          }, // 21
		{ "Hadephobia",				        "HPH01"         }, // 22
		{ "Mayhem 17",				        "MAY01"	        }, // 23
		{ "Sunlust",				        "SLU01"	        }, // 24
		{ "Hellbound",				        "HLB01"         }, // 25
		{ "1994 Tune Up Community Project", "TU01"          }, // 26
		{ "Unholy Realms",			        "UHR01"	        }, // 27
        { "Hell Core",			            "HC01"	        }, // 28
        { "Unused",			                "MAP01"	        }, // 29
        { "Unused",			                "MAP01"	        }, // 30
        { "Unused",			                "MAP01"	        }, // 31
        { "Unused",			                "MAP01"	        }, // 32
        { "Unused",			                "MAP01"	        }, // 33
        { "Unused",			                "MAP01"	        }, // 34
        { "Unused",			                "MAP01"	        }, // 35
        { "Unused",			                "MAP01"	        }, // 36
        { "Unused",			                "MAP01"	        }, // 37
        { "Unused",			                "MAP01"	        }, // 38
        { "Unused",			                "MAP01"	        }, // 39
        { "Unused",			                "MAP01"	        }, // 40
        { "Unused",			                "MAP01"	        }, // 41
        { "Unused",			                "MAP01"	        }, // 42
        { "Unused",			                "MAP01"	        }, // 43
        { "Unused",			                "MAP01"	        }, // 44
        { "Unused",			                "MAP01"	        }, // 45
        { "Unused",			                "MAP01"	        }, // 46
        { "Unused",			                "MAP01"	        }, // 47
        { "Unused",			                "MAP01"	        }, // 48
        { "Unused",			                "MAP01"	        }, // 49
        { "Unused",			                "MAP01"	        }, // 50
        { "Unused",			                "MAP01"	        }, // 51
        { "Unused",			                "MAP01"	        }, // 52
        { "Unused",			                "MAP01"	        }, // 53
        { "Unused",			                "MAP01"	        }, // 54
        { "Unused",			                "MAP01"	        }, // 55
        { "Unused",			                "MAP01"	        }, // 56
        { "Unused",			                "MAP01"	        }, // 57
        { "Unused",			                "MAP01"	        }, // 58
        { "Unused",			                "MAP01"	        }, // 59
        { "Unused",			                "MAP01"	        }, // 60
        { "Unused",			                "MAP01"	        }, // 61
        { "Unused",			                "MAP01"	        }, // 62
        { "Unused",			                "MAP01"	        }, // 63
        { "Unused",			                "MAP01"	        }, // 64
        
        // Slaughter Mapsets
        { "Combat Shock",                   "CS01"             }, // 65
        { "Combat Shock 2",                 "CS201"            }, // 66
        { "New Gothic Movement 1",          "NG101"            }, // 67
        { "Dark Tartarus",                  "TAT01"            }, // 68
		{ "Sunder",					        "SND01"            }, // 69
		{ "Drown in Blood",			        "DIB01"	           }, // 70
		{ "Swift Death",			        "SDE01"            }, // 71
        { "Deus Vult",				        "DV01"	           }, // 72
        { "Pizza Steve",			        "PIZ01"            }, // 73
        { "Unused",			                "MAP01"            }, // 74
        { "Unused",			                "MAP01"            }, // 75
        { "Unused",			                "MAP01"            }, // 76
        { "Unused",			                "MAP01"            }, // 77
        { "Unused",			                "MAP01"            }, // 78
        { "Unused",			                "MAP01"            }, // 79
        { "Unused",			                "MAP01"            }, // 80
        { "Unused",			                "MAP01"            }, // 81
        { "Unused",			                "MAP01"            }, // 82
        { "Unused",			                "MAP01"            }, // 83
        { "Unused",			                "MAP01"            }, // 84
        { "Unused",			                "MAP01"            }, // 85
        { "Unused",			                "MAP01"            }, // 86
        { "Unused",			                "MAP01"            }, // 87
        { "Unused",			                "MAP01"            }, // 88
        { "Unused",			                "MAP01"            }, // 89
        { "Unused",			                "MAP01"            }, // 90
        { "Unused",			                "MAP01"            }, // 91
        { "Unused",			                "MAP01"            }, // 92
        { "Unused",			                "MAP01"            }, // 92
        { "Unused",			                "MAP01"            }, // 94
        { "Unused",			                "MAP01"            }, // 95
        { "Unused",			                "MAP01"            }, // 96
        { "Unused",			                "MAP01"            }, // 97
        { "Unused",			                "MAP01"            }, // 98
        { "Unused",			                "MAP01"            }, // 99
        { "Unused",			                "MAP01"            }, // 100
        { "Unused",			                "MAP01"            }, // 101
        { "Unused",			                "MAP01"            }, // 102
        { "Unused",			                "MAP01"            }, // 103
        { "Unused",			                "MAP01"            }, // 104
        { "Unused",			                "MAP01"            }, // 105
        { "Unused",			                "MAP01"            }, // 106
        { "Unused",			                "MAP01"            }, // 107
        { "Unused",			                "MAP01"            }, // 108
        { "Unused",			                "MAP01"            }, // 109
        { "Unused",			                "MAP01"            }, // 110
        { "Unused",			                "MAP01"            }, // 111
        { "Unused",			                "MAP01"            }, // 112
        { "Unused",			                "MAP01"            }, // 113
        { "Unused",			                "MAP01"            }, // 114
        { "Unused",			                "MAP01"            }, // 115
        { "Unused",			                "MAP01"            }, // 116
        { "Unused",			                "MAP01"            }, // 117
        { "Unused",			                "MAP01"            }, // 118
        { "Unused",			                "MAP01"            }, // 119
        { "Unused",			                "MAP01"            }, // 120
        { "Unused",			                "MAP01"            }, // 121
        { "Unused",			                "MAP01"            }, // 122
        { "Unused",			                "MAP01"            }, // 123
        { "Unused",			                "MAP01"            }, // 124
        { "Unused",			                "MAP01"            }, // 125
        { "Unused",			                "MAP01"            }, // 126
        { "Unused",			                "MAP01"            }, // 127
        { "Unused",			                "MAP01"            }, // 128
        
        // Single Levels
		{ "The Spire",				        "TSP01"            }, // 129
		{ "The Eye",				        "EYE01"            }, // 130
        { "Unused",			                "MAP01"            }, // 131
        { "Unused",			                "MAP01"            }, // 132
        { "Unused",			                "MAP01"            }, // 133
        { "Unused",			                "MAP01"            }, // 134
        { "Unused",			                "MAP01"            }, // 135
        { "Unused",			                "MAP01"            }, // 136
        { "Unused",			                "MAP01"            }, // 137
        { "Unused",			                "MAP01"            }, // 138
        { "Unused",			                "MAP01"            }, // 139
        { "Unused",			                "MAP01"            }, // 140
        { "Unused",			                "MAP01"            }, // 141
        { "Unused",			                "MAP01"            }, // 142
        { "Unused",			                "MAP01"            }, // 143
        { "Unused",			                "MAP01"            }, // 144
        { "Unused",			                "MAP01"            }, // 145
        { "Unused",			                "MAP01"            }, // 146
        { "Unused",			                "MAP01"            }, // 147
        { "Unused",			                "MAP01"            }, // 148
        { "Unused",			                "MAP01"            }, // 149
        { "Unused",			                "MAP01"            }, // 150
        { "Unused",			                "MAP01"            }, // 151
        { "Unused",			                "MAP01"            }, // 152
        { "Unused",			                "MAP01"            }, // 153
        { "Unused",			                "MAP01"            }, // 154
        { "Unused",			                "MAP01"            }, // 155
        { "Unused",			                "MAP01"            }, // 156
        { "Unused",			                "MAP01"            }, // 157
        { "Unused",			                "MAP01"            }, // 158
        { "Unused",			                "MAP01"            }, // 159
        { "Unused",			                "MAP01"            }, // 160
        { "Unused",			                "MAP01"            }, // 161
        { "Unused",			                "MAP01"            }, // 162
        { "Unused",			                "MAP01"            }, // 163
        { "Unused",			                "MAP01"            }, // 164
        { "Unused",			                "MAP01"            }, // 165
        { "Unused",			                "MAP01"            }, // 166
        { "Unused",			                "MAP01"            }, // 167
        { "Unused",			                "MAP01"            }, // 168
        { "Unused",			                "MAP01"            }, // 169
        { "Unused",			                "MAP01"            }, // 170
        { "Unused",			                "MAP01"            }, // 171
        { "Unused",			                "MAP01"            }, // 172
        { "Unused",			                "MAP01"            }, // 173
        { "Unused",			                "MAP01"            }, // 174
        { "Unused",			                "MAP01"            }, // 175
        { "Unused",			                "MAP01"            }, // 176
        { "Unused",			                "MAP01"            }, // 177
        { "Unused",			                "MAP01"            }, // 178
        { "Unused",			                "MAP01"            }, // 179
        { "Unused",			                "MAP01"            }, // 180
        { "Unused",			                "MAP01"            }, // 181
        { "Unused",			                "MAP01"            }, // 182
        { "Unused",			                "MAP01"            }, // 183
        { "Unused",			                "MAP01"            }, // 184
        { "Unused",			                "MAP01"            }, // 185
        { "Unused",			                "MAP01"            }, // 186
        { "Unused",			                "MAP01"            }, // 187
        { "Unused",			                "MAP01"            }, // 188
        { "Unused",			                "MAP01"            }, // 189
        { "Unused",			                "MAP01"            }, // 190
        { "Unused",			                "MAP01"            }, // 191
        { "Unused",			                "MAP01"            }, // 192
    };

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
    
    /////////////////////
    // level
    /////////////////////
    int levelstarted = 0;
    int clock = 0;
    int countstart = 0;
    str clockcolor = "\c[Green]";







    ///////////////////////////////////////////////////////////////
    // Scripts
    ///////////////////////////////////////////////////////////////

    // stuff that runs during any level
    script "SV_Level" open
    {
        // if level is the HUB map
        if(GetLevelInfo(LEVELINFO_LEVELNUM) == 99)
        { 
            // we have come back from a completed mapset
            if(GetCVar("lexicon_global_sucktime") == 1337)
            {
                // woo! fireworks! yay!
                ACS_NamedExecute("Fireworks", 0);
            }
            terminate;
        }
        
        // if the level is anything but the HUB map
        else
        {
            // get suck time
            SetCVar("lexicon_global_sucktime", GetLevelInfo(LEVELINFO_SUCK_TIME));

            // is the mapset reset timer enabled?
            if(GetCvar("lexicon_timer_reset_enabled") == 1)
            {
                // set levelstart to 0
                levelstarted = 0;
                countstart = 0;
                
                // loop until levelstart and countstart are 1
                while(levelstarted == 0 || countstart == 0)
                {
                    // if the level has started and the countdown is not started
                    if(levelstarted == 1 && countstart == 0)
                    {
                        // if the playercount goes back to 0
                        if(playercount() == 0)
                        {
                            // start clock
                            countstart = 1;
                        }
                    }
                    
                    // if level has not started
                    if(levelstarted == 0)
                    {
                        // wait for someone to join
                        if(playercount() > 0)
                        {
                            //the level has been started
                            levelstarted = 1;
                        }
                    }
                    delay(1);
                }

                // clock
                clock = GetCvar("lexicon_timer_reset");

                // setup hud
                HudSetup("HUDFONT");

                // countdown
                while(1)
                {
                    // count down the clock
                    clock--;
                    
                    // change the color of the clock
                            if(clock > 7)                  { clockcolor = "\c[Green]";     }
                    else    if(clock <= 7 && clock > 4)    { clockcolor = "\c[Yellow]";    }
                    else    if(clock <= 4 && clock > 1)    { clockcolor = "\c[Orange]";    }
                    else    if(clock <= 1 && clock >= 0)   { clockcolor = "\c[Red]";       }
                        
                    // draw clock
                    hudmessagebold(s:clockcolor, s:MESSAGE_RETURN, i:clock; 0, 9998, 0, hud_width_half, 112.0, 1.1);
                    
                     // when time is up
                    if(clock < 0)
                    {
                        // go back to hub
                        SetCVar("lexicon_global_sucktime", 0);
                        ChangeLevel("VR", 0, 0, -1);
                    }
                    
                    // seconds
                    delay(35);
                }
            }
        }
    }
    
    // when a player enters the game(server side)
    script "SV_PlayerEnter" enter
    {
        // we have entered the VR map
        if(GetLevelInfo(LEVELINFO_LEVELNUM) == 99) 
        { 
            // setup player's array slot
            int pnum = playernumber();
            players[pnum] = -1;

            // sync the joining player's vars
            bubble_sort();
            ACS_Execute(569, 0, time_seconds);
            ACS_ExecuteAlways(570, 0, state);
            
            // clear out player's inventory
            if(GetCVar("lexicon_clear_inventory") == 1)
            {
                ClearInventory();
            }
            
            // give player the votegun
            GiveInventory("Lexicon_VoteGun", 1);
            SetWeapon("Lexicon_VoteGun");
        }
    }

    // when a player enters the game(client side)
    script "CL_PlayerEnter" enter clientside
    {
        // prevent this script from running multiple times on each client, for each client
        if(playernumber() != ConsolePlayerNumber()) { Terminate; }
        
        //////////////////////////
        // Map Credits
        //////////////////////////
        // do not show the credits stuff in the hub or the titlemap
        if(GetLevelInfo(LEVELINFO_LEVELNUM) != 99 && GameType() != GAME_TITLE_MAP) 
        {
            // get level credits
            str credits = strparam(s:"C_", n:PRINTNAME_LEVEL);
            credits = strparam(l:credits);
            
            // check if credits listing exists
            if(strLeft(credits, 2) == "C_")
            {
                credits = "Unknown";
            }

            // mapset/mapname/creds
            HudSetup("HUDFONT");

            Hudmessage(s:"\c[White]Mapset:\c[Cyan]", s:votenames[GetCVar("lexicon_global_votechosen")][0], s:"\n\c[White]Level:\c[Cyan]", n:PRINTNAME_LEVELNAME, s:"\n\c[White]Credits:\c[Cyan]", s:credits; HUDMSG_FADEINOUT, 8562, 0, hud_width + 0.2, hud_height - 160.0, 5.0, 1.0, 1.0);
        }
        
        //////////////////////////
        // HUB HUD init
        //////////////////////////
        else
        {
            HudSetup("HUDFONT");
            
            hudmessagebold(s:MESSAGE_WELCOME; HUDMSG_LOG, 9997, 0, hud_width_half + 0.4, 80.0, 10.0);
                        
            // we have come back from a completed mapset
            if(GetCVar("lexicon_global_sucktime") == 1337)
            {
                hudmessagebold(s:MESSAGE_COMPLETE, s:votenames[GetCVar("lexicon_global_votechosen")][0], s:"!"; 0, 9997, 0, hud_width_half + 0.4, 64.0, 30.0);
            }


            // setup the confetti
            for(int c = 0; c < 64; c++)
            {
                objs_confetti[c].x = 0;
                objs_confetti[c].y = (int)hud_height/65535;
                objs_confetti[c].velx = random(1, 64);
                objs_confetti[c].vely = random(-64, -1);
                objs_confetti[c].confnum = random(0, 17);
                objs_confetti[c].animnum = random(0, 7);
            }
            for(int c = 64; c < 128; c++)
            {
                objs_confetti[c].x = (int)hud_width/65535;
                objs_confetti[c].y = (int)hud_height/65535;
                objs_confetti[c].velx = random(-64, -1);
                objs_confetti[c].vely = random(-64, -1);
                objs_confetti[c].confnum = random(0, 17);
                objs_confetti[c].animnum = random(0, 7);
            }
        }
        
        ///////////////
        // The Loop
        ///////////////
        while(1)
        {
            HudSetup("HUDFONT");
            
            //////////////////////////
            // Debug Mode
            //////////////////////////
            if(GetCVar("lexicon_debug_mode") == 1)
            {
                hudmessage(s:"\c[Gold]debug mode:", s:" I:", i:GetCVar("lexicon_global_instakiller"), s:" G:", i:GetCVar("lexicon_global_godmode"); 0, 9600, 0, hud_width - 160.0, hud_height - 151.0, 0.1);
            }

            //////////////////////////
            // HUB HUD
            //////////////////////////
            // if we are on the hub map
            if(GetLevelInfo(LEVELINFO_LEVELNUM) == 99)
            {            
                // COUNTDOWN
                if(state == STATE_COUNTDOWN)
                {
                    // timer
                    if(time_seconds > GetCvar("lexicon_timer_yellow"))
                    {
                        hudmessagebold(s:"\c[Green]", s:"Time Left: ", d:time_seconds; 0, 9998, 0, 192.1, 112.0, 0.1);
                    }
                    else if(time_seconds <= GetCvar("lexicon_timer_yellow") && time_seconds > GetCvar("lexicon_timer_orange"))
                    {
                        hudmessagebold(s:"\c[Yellow]", s:"Time Left: ", d:time_seconds; 0, 9998, 0, 192.1, 112.0, 0.1);
                    }
                    else if(time_seconds <= GetCvar("lexicon_timer_orange") && time_seconds > GetCvar("lexicon_timer_red"))
                    {
                        hudmessagebold(s:"\c[Orange]", s:"Time Left: ", d:time_seconds; 0, 9998, 0, 192.1, 112.0, 0.1);
                    }
                    else if(time_seconds <= GetCvar("lexicon_timer_red"))
                    {
                        hudmessagebold(s:"\c[Red]", s:"Time Left: ", d:time_seconds; 0, 9998, 0, 192.1, 112.0, 0.1);
                    }

                    // vote header
                    hudmessagebold(s:"\c[Cyan]Votes"; 0, 9999, 0, 192.1, 136.0, 0.1);

                    // vote list
                    fixed y = 136.0;
                    for(int i = 0; i < PLAYER_MAX; i++)
                    {
                        if(votessorted[i][0] > 0)
                        {
                            y += 23.0;
                            
                            // mapset name
                            hudmessagebold(s:"\c[Gold]", d:votessorted[i][0], s:" : ", s:votenames[votessorted[i][1]][0]; 0, i+10000, 0, 300.1, y, 0.1);
                            
                            // perfix handling
                            for(int p = 0; p < MAPSET_SECTIONS; p++)
                            {
                                if(votessorted[i][1] >= (MAPSET_SECTIONS_MAX*p)+1 && votessorted[i][1] <= (MAPSET_SECTIONS_MAX*(p+1)+1))
                                {
                                    hudmessagebold(s:sectionnames[p], s:" "; 0, i+11001, 0, 300.2, y, 0.1);
                                }
                            }
                        }
                    }

                    // if the player has a vote
                    if(players[playernumber()] != -1)
                    {
                        // show player's vote
                        hudmessagebold(s:"\c[Green]Your Vote: \c[Gold]", s:votenames[players[playernumber()]][0]; 0, 9700, 0, hud_width_half, hud_height-192.0, 0.1);
                    }
                }
                
                // RESULTS
                else if(state == STATE_RESULTS)
                {
                    setfont("hudfont");
                    hudmessagebold(s:"\c[Green]", s:"Winner: \c[Gold]", s:votenames[GetCVar("lexicon_global_votechosen")][0]; 0, 9998, 0, hud_width_half, hud_height_half-128.0, 0.1);

                    // confetti :D
                    for(int c = 0; c < 128; c++)
                    {
                        // slow down the confetti
                        if(objs_confetti[c].velx > 0){ objs_confetti[c].velx -= 1; }
                        if(objs_confetti[c].velx < 0){ objs_confetti[c].velx += 1; }

                        // add gravity
                        objs_confetti[c].vely += 1;

                        // apply velocities
                        objs_confetti[c].x += objs_confetti[c].velx;
                        objs_confetti[c].y += objs_confetti[c].vely;

                        // animate it
                        objs_confetti[c].animnum++;
                        if(objs_confetti[c].animnum > 7) { objs_confetti[c].animnum = 0; }
                        objs_confetti[c].image = StrParam(s:"CN", i:objs_confetti[c].confnum, i:objs_confetti[c].animnum);

                        // show it
                        setfont(objs_confetti[c].image);
                        hudmessagebold(s:"a"; 0, c+9800, 0, (fixed)(objs_confetti[c].x*65535), (fixed)(objs_confetti[c].y*65535), 0.1);
                    }
                }
            }
            delay(1);
        }
    }

    // keeps track of votes and what to do with them
    script "VoteManager" (void)
    {
        // loop
        while(1)
        {
            switch(state)
            {
                case STATE_INIT:        state_init();           break;
                case STATE_VOTEWAIT:    state_waitforvote();    break;
                case STATE_COUNTDOWN:   state_countdown();      break;
                case STATE_CHECKTIE:    state_checktie();       break;
                case STATE_RESULTS:     state_results();        break;
            }
            delay(1);
        }
    }

    // called by players to manage their votes
    script "VotePlayer" (int id)
    {
        if(id == -1) { terminate; }

        if(playernumber() > -1)
        {
            // get player number
            int pnum = playernumber();

            // special vr map logic so players cant vote from shooting the invisible parts of the linedef
            if(GetActorZ(0) < 1144.0) { terminate; }
            
            // if the player has not voted...
            if (players[pnum] < 0)
            {
                // keep track of player's vote
                players[pnum] = id;

                // count a vote for a specific id
                votes[id]++;

                // count up total votes
                votecount++;
            }
            // if the player has already voted
            else
            {
                // if the vote id is different
                if(players[pnum] != id)
                {
                    // remove the vote from previous id
                    votes[players[pnum]]--;

                    // set the player's vote to the new id
                    players[pnum] = id;

                    // add the vote to the new id
                    votes[id]++;
                }
                // if the vote id is the same
                else
                {
                    // remove the player's vote
                    players[pnum] = -1;

                    // remove a vote for a specific id
                    votes[id]--;

                    // count down total votes
                    votecount--;
                }
            }
            // sort votes
            bubble_sort();

            // sync player votes
            for(int i = 0; i < 63; i++)
            {
                ACS_ExecuteAlways(571, 0, i, players[pnum]);
            }
        }
    }

    // debug mode
    script "DebugMode" open
    {
        if(GetLevelInfo(LEVELINFO_LEVELNUM) == 99)
        {
            SetCVar("lexicon_global_godmode", 0);
            SetCVar("lexicon_global_instakiller", 0);
        }
        if(GetCVar("lexicon_global_godmode") == 1)
        {
            GiveActorInventory(0, "Lexicon_GodMode", 1);
        }
        if(GetCVar("lexicon_global_instakiller") == 1)
        {
            GiveActorInventory(0, "Lexicon_InstaKiller", 1);
        }
    }


    script "DebugMode_Switch" (int id)
    {
        if(GetCvar("lexicon_debug_mode") == 1)
        {
            switch(id)
            {
                case 0: 
                    if(GetCVar("lexicon_global_godmode") == 0) { SetCVar("lexicon_global_godmode", 1); break; }
                    if(GetCVar("lexicon_global_godmode") == 1) { SetCVar("lexicon_global_godmode", 0); break; }
                    break;
                case 2: 
                    if(GetCVar("lexicon_global_instakiller") == 0) { SetCVar("lexicon_global_instakiller", 1); break; }
                    if(GetCVar("lexicon_global_instakiller") == 1) { SetCVar("lexicon_global_instakiller", 0); break; }
                    break;
            }
        }
    }

    // sync sorted votes to clients
    script 567 (int index, int votes, int id) clientside
    {
        votessorted[index][0] = votes;
        votessorted[index][1] = id;
    }

    // sync timer
    script 569 (int time) clientside
    {
        time_seconds = time;
    }

    // sync state
    script 570 (int s) clientside
    {
        state = s;
    }

    // sync player choices
    script 571 (int pnum, int id) clientside
    {
        players[pnum] = id;
    }









    





    ///////////////////////////////////////////////////////////////
    // Functions
    ///////////////////////////////////////////////////////////////

    function void state_init(void)
    {

        time_ticks = GetCvar("lexicon_timer_start")*35;
        time_seconds = time_ticks/35;
        
        // set the system to the countdown state
        state = STATE_VOTEWAIT;

        // sync clients
        ACS_ExecuteAlways(570, 0, state);
        ACS_ExecuteAlways(569, 0, state);
    }

    function void state_waitforvote(void)
    {
        // if a vote was made
        if(votecount > 0)
        {
            // if the server has the ignore timer flag set and there is only 1 player in
            if(PlayerCount() == 1 && GetCvar("lexicon_timer_1p_ignore") == 1)
            {
                time_ticks = 0;
            }
            
            // set the system to the countdown state
            state = STATE_COUNTDOWN;

            // sync clients
            ACS_ExecuteAlways(570, 0, state);
        }
    }

    function void state_countdown(void)
    {
        // countdown timer
        time_ticks--;
        time_seconds = time_ticks/35;

        // if time up, or all players voted, or majority have voted
        if(time_ticks <= 0) // votecount >= playercount() || votessorted[0][0] > (playercount()/3)*2)
        { 
            // set the system to the check tie state
            state = STATE_CHECKTIE;

            // sync
            ACS_ExecuteAlways(570, 0, state);
        }
        // if all votes were canceled
        if(votecount <= 0)
        {
            // reset timer
            time_ticks = GetCvar("lexicon_timer_start")*35;

            // go back to the wait state
            state = STATE_VOTEWAIT;

            // sync
            ACS_ExecuteAlways(570, 0, state);
        }

        // sync clients every second
        if(!(time_ticks%35))
        {
            // sync the timer with the clients
            ACS_Execute(569, 0, time_seconds);
        }
    }

    function void state_checktie(void)
    {
        // sort votes
        bubble_sort();
        int tiecount = 0;

        // for every wad
        for(int i = 1; i < MAPSET_MAX; i++)
        {
            // if a wad's vote count is the same as the winner
            if(votessorted[i][0] == votessorted[0][0])
            {
                // count up the tie amount
                tiecount++;
            }
        }

        // if there is a tie
        if(tiecount > 0)
        {
            // randomly choose a wad
            SetCVar("lexicon_global_votechosen", votessorted[random(0, tiecount)][1]);
        }
        else
        {
            // otherwise just choose the winner
            SetCVar("lexicon_global_votechosen", votessorted[0][1]);
        }

        // set the system to the results state
        state = STATE_RESULTS;

        // sync
        ACS_ExecuteAlways(570, 0, state);

        // reset timer
        state_clock = 0;

        AmbientSound("partyhorn", 127);
    }

    function void state_results(void)
    {
        // count up custom timer
        state_clock++;

        // if 5 seconds have past
        if(state_clock > 5*35)
        {
            // go to chosen level
            if(GetCVar("lexicon_clear_inventory") == 1)
            {
                ChangeLevel(votenames[GetCVar("lexicon_global_votechosen")][1], 0, CHANGELEVEL_RESETHEALTH | CHANGELEVEL_RESETINVENTORY | CHANGELEVEL_NOINTERMISSION, -1);
            }
            else
            {
                TakeInventory("Lexicon_VoteGun", 0x7FFFFFFF);
                ChangeLevel(votenames[GetCVar("lexicon_global_votechosen")][1], 0, CHANGELEVEL_NOINTERMISSION, -1);
            }
        }
    }

    // sort voted list
    function void bubble_sort(void)
    {
        int t;
        int j = MAPSET_MAX;
        int s = 1;
        int v;
        for (int i = 0; i < MAPSET_MAX; i++)
        {
            votessorted[i][0] = votes[i];
            votessorted[i][1] = i;
        }
        while(s)
        {
            s = 0;
            for (int i = j; i >= 0; i--)
            {
                if (votessorted[i][0] < votessorted[i + 1][0])
                {
                    t = votessorted[i][0];
                    v = votessorted[i][1];
                    votessorted[i][0] = votessorted[i + 1][0];
                    votessorted[i][1] = votessorted[i + 1][1];
                    votessorted[i + 1][0] = t;
                    votessorted[i + 1][1] = v;
                    s = 1;
                }
            }
            j--;
        }

        for(int i = 0; i < MAPSET_MAX; i++)
        {
            ACS_ExecuteAlways(567, 0, i, votessorted[i][0], votessorted[i][1]);
        }
    }

    function void HudSetup(str font)
    {
        int x = GetScreenWidth();
        int y = GetScreenHeight();

        hud_width = (fixed)(x*65536);
        hud_height = (fixed)(y*65536);

        hud_width_half = hud_width/2.0;
        hud_height_half = hud_height/2.0;

        SetHudSize(x, y, true);
        SetFont(font);
    }
    
    ////// Easter egg shit because i need the hud vars

    script "Eggs" (int id) clientside
    {
        HudSetup("HUDFONT");
        hudmessage(s:lore[id]; HUDMSG_LOG, 9701, 0, hud_width_half, hud_height_half, 10.0);
    }
}





















