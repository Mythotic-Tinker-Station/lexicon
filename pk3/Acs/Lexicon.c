// written in BCS
#include "../../compiler/lib/zcommon.h"
#library "vote"

strict namespace
{
    #if 1
    
        #include "skybox.c"

        // dont touch this
        #define STATE_INIT -1
        #define STATE_VOTEWAIT 0
        #define STATE_COUNTDOWN 1
        #define STATE_CHECKTIE 2
        #define STATE_RESULTS 3
    #endif
    
    // this is where the names that show up in the votes are, and the map names to go to when that wad wins
    str votenames[64][2] =
    {
        // wad name                 // the map this vote will take players too
        { "Doom 2",                 "MAP01"  }, // 0
        { "Combat Shock",           "CS01"  }, // 1 Slaughter Map
        { "Combat Shock 2",         "CS201" }, // 2 Slaughter Map
        { "Hell Revealed",          "HR01"  }, // 3
        { "Hell Revealed 2",        "HR201" }, // 4
        { "Kamasutra",              "KS01"  }, // 5
        { "New Gothic Movement 1",  "NG101" }, // 6 Slaughter Map
        { "Shai'tans Luck",         "SL20"  }, // 7
        { "Speed Of Doom",          "SOD01" }, // 8
        { "Dark Tartarus",          "TAT01" }, // 9 Slaughter Map
        { "VanGaurd",               "VAN01" }, // 10
        { "Scythe 2",               "SC201" }, // 11
		{ "Whispers Of Satan",		"WOS01"	}, // 12
		{ "UAC Ultra",				"UAC01"	}, // 13
		{ "Monuments Of Mars",		"MOM01"	}, // 14
		{ "Khorus's Speedy Shit",	"KSS01"	}, // 15
		{ "Circle of Caina",		"COC01"	}, // 16
		{ "Forest Swords",			"FSW01"	}, // 17
		{ "Doom Core Trilogy",		"DC01"	}, // 18
		{ "Maps of Chaos",	        "MOC01"	}, // 19
		{ "Sunder",					"SND01" }, // 20 Slaughter Map
		{ "Doom 2 The Way ID Did",	"WID01" }, // 21
		{ "Drown in Blood",			"DIB01"	}, // 22 Slaughter Map
		{ "Swift Death",			"SDE01" }, // 23 Slaughter Map
		{ "Estranged",				"EST01" }, // 24
		{ "Going Down",				"GD01"	}, // 25
		{ "Dark Encounters",		"DKE01"	}, // 26
        { "Alien Vendetta",         "AV01"  }, // 27
		{ "Hadephobia",				"HPH01" }, // 28
		{ "Deus Vult",				"DV01"	}, // 29 Slaughter Map
		{ "Mayhem 17",				"MAY01"	}, // 30
		{ "Sunlust",				"SLU01"	}, // 31
		{ "Pizza Steve",			"PIZ01" }, // 32 Slaughter Map
		{ "Hellbound",				"HLB01" }, // 33
		{ "1994 Tune Up Community Project",		"TU01" }, // 34
    };
    /////////////////////
    // vote manager
    /////////////////////
    int votes[64];                      // holds the votes
    int votessorted[64][2];             // all the votes, sorted
    int votecount = 0;                  // amount of votes made

    int time_ticks = 0;                 // the time left in ticks
    int time_seconds = 0;               // the time left in seconds

    int players[64];                    // all the player info
    
    int state = STATE_INIT;             // state of the voting system
    int state_clock;                    // custom timer

    global int 2:votechosen;            // the winner
    
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
    
    /////////////////////
    // debug
    /////////////////////
    global int  0:godmode;
    global int  1:instakiller;

    
    // stuff that runs during any level
    script "SV_Level" open
    {
        if(GetLevelInfo(LEVELINFO_LEVELNUM) == 99) { terminate; }
        
        levelstarted = 0;
        clock = GetCvar("lexicon_timer_reset");

        while(1)
        {
            // if the level has started and the countdown is not started
            if(levelstarted == 1 && countstart == 0)
            {
                // if the playercount goes back to 0
                if(playercount() == 0)
                {
                    countstart = 1;
                }
            }
            // if nobody has joined yet
            else
            {
                // wait for someone to join
                if(playercount() > 0)
                {
                    //the level has been started
                    levelstarted = 1;
                }
            }
            
            // countdown has started
            if(countstart == 1)
            {
                // countdown
                clock--;
                if(countstart == 1)
                {
                    // these hudmessages were in the cl_lexicon_hud script
                    // it had to be moved here as zandronum terminates player scripts when they spectate
                    // resulting in these hudmessages not showing
                    HudSetup(0, 0);
                    SetFont("HUDFONT");
                    if(clock > 7)
                    {
                        hudmessagebold(s:"\c[Green]Going back to the lexicon in: ", i:clock; 0, 9998, 0, hud_width_half, 112.0, 1.1);
                    }
                    else if(clock <= 7 && clock > 4)
                    {
                        hudmessagebold(s:"\c[Yellow]Going back to the lexicon in: ", i:clock; 0, 9998, 0, hud_width_half, 112.0, 1.1);
                    }
                    else if(clock <= 4 && clock > 1)
                    {
                        hudmessagebold(s:"\c[Orange]Going back to the lexicon in: ", i:clock; 0, 9998, 0, hud_width_half, 112.0, 1.1);
                    }
                    else if(clock <= 1 && clock >= 0)
                    {
                        hudmessagebold(s:"\c[Red]Going back to the lexicon in: ", i:clock; 0, 9998, 0, hud_width_half, 112.0, 1.1);
                    }
                }
                 // when time is up
                if(clock < 0)
                {
                    // go back to hub
                    ChangeLevel("Hub", 0, 0, -1);
                }
                delay(34);
            }
            delay(1);
        }
    }



    // when a player enters the game(server side)
    script "SV_PlayerEnter" enter
    {
    
        Thing_ChangeTID(0, playernumber()+1337);

        // this entire file should of been in the map script, oh well
        if(GetLevelInfo(LEVELINFO_LEVELNUM) == 99) 
        { 
            int pnum = playernumber();
            players[pnum] = -1;

            // sync the joining player's vars
            bubble_sort();
            ACS_Execute(568, 0, votechosen);
            ACS_Execute(569, 0, time_seconds);
            ACS_ExecuteAlways(570, 0, state);
        }
    }

    // when a player enters the game(client side)
    script "CL_Lexicon_Hud" enter clientside
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
            HudSetup(0, 0);
            setfont("hudfont");
            Hudmessage(s:"\c[White]Mapset:\c[Cyan]", s:votenames[votechosen][0], s:"\n\c[White]Level:\c[Cyan]", n:PRINTNAME_LEVELNAME, s:"\n\c[White]Credits:\c[Cyan]", s:credits; HUDMSG_FADEINOUT, 8562, 0, hud_width + 0.2, hud_height - 160.0, 5.0, 1.0, 1.0);
        }
        
        //////////////////////////
        // HUB HUD init
        //////////////////////////
        else
        {
            HudSetup(0, 0);
            setfont("hudfont");
            hudmessagebold(s:"\c[White]Welcome to the Lexicon Voting Room\n\n\c[White]This is still Work in Progress. You can follow progress on discord via\n\c[Cyan]https://discord.gg/qj9GASW"; HUDMSG_LOG, 9997, 0, hud_width_half + 0.4, 64.0, 10.0);

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
            HudSetup(0, 0);
            setfont("HUDFONT");
            
            //////////////////////////
            // Debug Mode
            //////////////////////////
            if(GetCVar("lexicon_debug_mode") == 1)
            {
                hudmessage(s:"\c[Gold]debug mode:", s:" I:", i:instakiller, s:" G:", i:godmode; 0, 9600, 0, hud_width - 160.0, hud_height - 151.0, 0.1);
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
                    for(int i = 0; i < 64; i++)
                    {
                        if(votessorted[i][0] > 0)
                        {
                            y += 23.0;
                            hudmessagebold(s:"\c[Gold]", d:votessorted[i][0], s:" : ", s:votenames[votessorted[i][1]][0]; 0, i+10000, 0, 225.1, y, 0.1);
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
                    hudmessagebold(s:"\c[Green]", s:"Winner: \c[Gold]", s:votenames[votechosen][0]; 0, 9998, 0, hud_width_half, hud_height_half-128.0, 0.1);

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
        if(id == -1)
        {
            // there was something else here but i removed it, and all the blank switches were set for this case, but now its just a waste
            // however, am leaving this here incase i do wanna use this for something
            terminate;
        }

        if(playernumber() > -1)
        {
            // get player number
            int pnum = playernumber();

            //pnum = random(1,7);

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
            godmode = 0;
            instakiller = 0;
        }
        if(godmode)
        {
            for(int i = 0; i < 63; i++)
            {
                GiveActorInventory(1337+i, "Lexicon_GodMode", 1);
            }
        }
        if(instakiller)
        {
            for(int i = 0; i < 63; i++)
            {
                GiveActorInventory(1337+i, "Lexicon_InstaKiller", 1);
            }
        }
    }


    script "DebugMode_Switch" (int id)
    {
        switch(id)
        {
            case 0: 
                if(godmode == 0) { godmode = 1; break; }
                if(godmode == 1) { godmode = 0; break; }
                break;
            case 2: 
                if(instakiller == 0) { instakiller = 1; break; }
                if(instakiller == 1) { instakiller = 0; break; }
                break;
        }
        ACS_ExecuteAlways(572, 0, godmode);
        ACS_ExecuteAlways(573, 0, instakiller);
    }

    // sync sorted votes to clients
    script 567 (int index, int votes, int id) clientside
    {
        votessorted[index][0] = votes;
        votessorted[index][1] = id;
    }

    // sync voted choice
    script 568 (int v) clientside
    {
        votechosen = v;
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

    // sync debug godmode
    script 572 (int v) clientside
    {
        godmode = v;
    }
    
    // sync debug instakiller
    script 573 (int v) clientside
    {
        instakiller = v;
    }

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
        for(int i = 1; i < 64; i++)
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
            votechosen = votessorted[random(0, tiecount)][1];
        }
        else
        {
            // otherwise just choose the winner
            votechosen = votessorted[0][1];
        }

        // sync the clients
        ACS_Execute(568, 0, votechosen);

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
            ChangeLevel(votenames[votechosen][1], 0, 0, -1);
        }
    }

    // sort voted list
    function void bubble_sort(void)
    {
        int t;
        int j = 64;
        int s = 1;
        int v;
        for (int i = 0; i < 64; i++)
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

        for(int i = 0; i < 63; i++)
        {
            ACS_ExecuteAlways(567, 0, i, votessorted[i][0], votessorted[i][1]);
        }
    }

    function void hudsetup(int xres, int yres)
    {
        int x = xres;
        int y = yres;

        if(x < 1) { x = GetCVar("vid_defwidth"); }
        if(y < 1) { y = GetCVar("vid_defheight"); }

        hud_width = (fixed)(x*65536);
        hud_height = (fixed)(y*65536);

        hud_width_half = hud_width/2.0;
        hud_height_half = hud_height/2.0;

        SetHudSize(x, y, true);
        SetFont("BIGFONT");
    }
}
