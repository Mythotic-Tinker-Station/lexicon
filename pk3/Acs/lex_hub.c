
// when a player enters the game(server side)
script "SV_HubPlayerEnter" enter
{
    // we have entered the VR map
    if(GetLevelInfo(LEVELINFO_LEVELNUM) == 99)
    {
        // setup player's array slot
        int pnum = playernumber();
        players[pnum] = -1;

        // sync the joining player's vars
        bubble_sort();
        ACS_NamedExecute("Sync_Timer", 0, time_seconds);
        ACS_NamedExecuteAlways("Sync_State", 0, state);

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
script "CL_HubPlayerEnter" enter clientside
{
    //////////////////////////
    // HUB HUD init
    //////////////////////////
    if(GetLevelInfo(LEVELINFO_LEVELNUM) == 99)
    {
        HudSetup("HUDFONT");

        hudmessagebold(l:"UI_WELCOME"; HUDMSG_LOG, 9997, 0, hud_width_half + 0.4, 80.0, 10.0);

        // we have come back from a completed mapset
        if(GetCVar("lexicon_global_sucktime") == 1337)
        {
            hudmessagebold(l:"UI_COMPLETE", s:votenames[GetCVar("lexicon_global_votechosen")][0], s:"!"; 0, 9997, 0, hud_width_half + 0.4, 64.0, 30.0);
            ACS_NamedExecute("Fireworks", 0);
        }

        // force musicbox to play doom2 intermission song
        ACS_NamedExecute("SV_MusicBox", 0, 33);

        // section names
        sectionnames[0] = strparam(s:"\c[Gold](\c[Green]", l:"UI_CAT1", s:"\c[Gold])");
        sectionnames[1] = strparam(s:"\c[Gold](\c[Red]", l:"UI_CAT2", s:"\c[Gold])");
        sectionnames[2] = strparam(s:"\c[Gold](\c[LightBlue]", l:"UI_CAT3", s:"\c[Gold])");

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
            hudmessage(s:"\c[Gold]", l:"UI_DEBUG", s:" I:", i:GetCVar("lexicon_global_instakiller"), s:" G:", i:GetCVar("lexicon_global_godmode"); 0, 9600, 0, hud_width - 160.0, hud_height - 151.0, 0.1);
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
                // time colors
                        if(time_seconds > GetCvar("lexicon_timer_yellow")) { clockcolor = "\c[Green]"; }
                else    if(time_seconds <= GetCvar("lexicon_timer_yellow") && time_seconds > GetCvar("lexicon_timer_orange")) { clockcolor = "\c[Yellow]"; }
                else    if(time_seconds <= GetCvar("lexicon_timer_orange") && time_seconds > GetCvar("lexicon_timer_red")) { clockcolor = "\c[Orange]"; }
                else    if(time_seconds <= GetCvar("lexicon_timer_red")) { clockcolor = "\c[Red]"; }

                // time left
                hudmessagebold(s:clockcolor, l:"UI_TIMELEFT", d:time_seconds; 0, 9998, 0, 192.1, 112.0, 0.1);

                // vote header
                hudmessagebold(s:"\c[Cyan]", l:"UI_VOTES"; 0, 9999, 0, 192.1, 136.0, 0.1);

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
                    hudmessagebold(s:"\c[Green]", l:"UI_YOURVOTE", s:"\c[Gold]", s:votenames[players[playernumber()]][0]; 0, 9700, 0, hud_width_half, hud_height-192.0, 0.1);
                }
            }

            // RESULTS
            else if(state == STATE_RESULTS)
            {
                setfont("hudfont");
                hudmessagebold(s:"\c[Green]", l:"UI_WINNER", s:"\c[Gold]", s:votenames[GetCVar("lexicon_global_votechosen")][0]; 0, 9998, 0, hud_width_half, hud_height_half-128.0, 0.1);

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
script "SV_HubVoteManager" (void)
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
script "SV_HubVotePlayer" (int id)
{
    if(id == -1) { terminate; }

    // doom complete support is not done yet, ignore these ids for now
    switch(id)
    {
        case 50:
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
        case 56:
        case 57:
        case 58:
        terminate;
    }

    if(playernumber() > -1)
    {
        // get player number
        int pnum = playernumber();

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
            ACS_NamedExecuteAlways("Sync_Choice", 0, i, players[pnum]);
        }
    }
}

// sync sorted votes to clients
script "Sync_Votes" (int index, int votes, int id) clientside
{
    votessorted[index][0] = votes;
    votessorted[index][1] = id;
}

// sync timer
script "Sync_Timer" (int time) clientside
{
    time_seconds = time;
}

// sync state
script "Sync_State" (int s) clientside
{
    state = s;
}

// sync player choices
script "Sync_Choice" (int pnum, int id) clientside
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
    ACS_NamedExecuteAlways("Sync_State", 0, state);
    ACS_NamedExecuteAlways("Sync_Timer", 0, state);
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
        ACS_NamedExecuteAlways("Sync_State", 0, state);
    }
}

function void state_countdown(void)
{
    // countdown timer
    time_ticks--;
    time_seconds = time_ticks/35;

    // if times up, or all players voted
    if(time_ticks <= 0 || (GetCvar("lexicon_timer_all_players") == 1 && votecount >= playercount()))
    {
        // set the system to the check tie state
        state = STATE_CHECKTIE;

        // sync
        ACS_NamedExecuteAlways("Sync_State", 0, state);
    }
    // if all votes were canceled
    if(votecount <= 0)
    {
        // reset timer
        time_ticks = GetCvar("lexicon_timer_start")*35;

        // go back to the wait state
        state = STATE_VOTEWAIT;

        // sync
        ACS_NamedExecuteAlways("Sync_State", 0, state);
    }

    // sync clients every second
    if(!(time_ticks%35))
    {
        // sync the timer with the clients
        ACS_NamedExecute("Sync_Timer", 0, time_seconds);
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
    ACS_NamedExecuteAlways("Sync_State", 0, state);

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
            // force musicbox to play first doom2 song
            SetCVar("lexicon_global_musicid", 1);
            TakeInventory("Lexicon_VoteGun", 0x7FFFFFFF);
            ChangeLevel(votenames[GetCVar("lexicon_global_votechosen")][1], 0, CHANGELEVEL_NOINTERMISSION, -1);
        }
    }
}



