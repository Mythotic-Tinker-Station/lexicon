


// check for empty server
script "SV_EmptyWatch" open
{
    // if level is the HUB map
    if(GetLevelInfo(LEVELINFO_LEVELNUM) == 99)
    {
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
                delay(35);
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
                hudmessagebold(s:clockcolor, l:"UI_RETURN", i:clock; 0, 9998, 0, hud_width_half, 112.0, 1.1);

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


// displays the level credits
script "CL_LevelCredits" enter clientside
{
    // prevent this script from running multiple times on each client, for each client
    if(playernumber() != ConsolePlayerNumber()) { Terminate; }

    // do not show the credits stuff in the hub or the titlemap
    if(GetLevelInfo(LEVELINFO_LEVELNUM) != 99 && GameType() != GAME_TITLE_MAP)
    {
        str credits = GetDynLangEntry("C", strparam(n:PRINTNAME_LEVEL));
        str mapset = GetDynLangEntry("C", StrLeft(strparam(n:PRINTNAME_LEVEL), StrLen(strparam(n:PRINTNAME_LEVEL))-2));

        // mapset/mapname/creds
        HudSetup("HUDFONT");

        Hudmessage(s:"\c[White]", l:"UI_MAPSET", s:"\c[Cyan]", s:mapset, s:"\n\c[White]", l:"UI_MAP", s:"\c[Cyan]", n:PRINTNAME_LEVELNAME, s:"\n\c[White]", l:"UI_CREDITS", s:"\c[Cyan]", s:credits; HUDMSG_FADEINOUT, 8562, 0, hud_width + 0.2, hud_height - 180.0, 5.0, 1.0, 1.0);

        // run through the doom2 music in order per level
        ACS_NamedExecute("SV_MusicBox", 0, 0);
    }
}

