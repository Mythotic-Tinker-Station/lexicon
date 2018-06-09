

// written in BCS
#include "../../compiler/lib/zcommon.h"
#library "vote"

strict namespace
{
    #if 1
        #define TIME_START 60    // in ticks, 35 = 1 second; 15*35 = 15 seconds, ect
        #define TIME_YELLOW 15   // the time at which the timer goes yellow
        #define TIME_ORANGE 10   // same as above, just orange
        #define TIME_RED 5       // red
        
        // dont touch this
        #define STATE_VOTEWAIT 0
        #define STATE_COUNTDOWN 1
        #define STATE_TIE 2
        #define STATE_RESULTS 3
    #endif
    
    // this is where the names that show up in the votes are, and the map names to go to when that wad wins
    str votenames[64][2] =
    {
        // wad name                 // the map this vote will take players too
        { "Alien Vendetta",         "AV01"  }, // 0
        { "Combat Shock",           "CS01"  }, // 1
        { "Combat Shock 2",         "CS201" }, // 2
        { "Hell Revealed",          "HR01"  }, // 3
        { "Hell Revealed 2",        "HR201" }, // 4
        { "Kamasutra",              "KS01"  }, // 5
        { "New Gothic",             "NG101" }, // 6
        { "Shai'tans Luck",         "SL20"  }, // 7
        { "Speed Of Doom",          "SOD01" }, // 8
        { "Dark Tartarus",          "TAT01" }, // 9
        { "VanGaurd",               "VAN01" }, // 10
        { "Scythe 2",               "SC201" }, // 11
    };
    
    
    
    int votes[64];
    int votessorted[64][2];
    int votecount = 0;
    int votechosen = 0;
    
    int time_ticks = TIME_START*35;
    int time_seconds = TIME_START;
    
    int players[64];
    int player_majority_count = 0;
    
    fixed hud_width;
    fixed hud_height;
    fixed hud_width_half;
    fixed hud_height_half;

    int state;
    int state_clock;

    // when a player enters the game, set them to have no vote
    script "PlayerEnter" enter
    {
        if(GetLevelInfo(LEVELINFO_LEVELNUM) != 99) { Terminate; } // this entire file should of been in the map script, oh well
        int pnum = playernumber();
        players[pnum] = -1;
        
        // sync the joining player's vars
        modified_bubble_sort();
        ACS_Execute(568, 0, votechosen);
        ACS_Execute(569, 0, time_seconds);
        ACS_ExecuteAlways(570, 0, state);
    }
    


    // keeps track of votes and what to do with them
    script "VoteManager" (void)
    {
        // loop
        while(1)
        {
            switch(state)
            {
                case STATE_VOTEWAIT:    state_waitforvote();    break;
                case STATE_COUNTDOWN:   state_countdown();      break;
                case STATE_TIE:         state_tie();            break;
                case STATE_RESULTS:     state_results();        break;
            }
            delay(1);
        }
    }


    script "VoteHud" enter clientside
    {
        if(GetLevelInfo(LEVELINFO_LEVELNUM) != 99) { Terminate; }
        if(playernumber() != ConsolePlayerNumber()) { Terminate; }
        HudSetup(0 ,0);
        while(1)
        {
            if(state == STATE_COUNTDOWN)
            {
                // vote header
                hudmessagebold(s:"\c[Cyan]Votes:"; 0, 9999, 0, 32.1, 80.0, 0.1);
                
                // vote list
                fixed y = 80.0;
                for(int i = 0; i < 64; i++)
                {
                    if(votessorted[i][0] > 0)
                    {
                        y += 16.0;
                        hudmessagebold(s:"\c[Gold]", d:votessorted[i][0], s:" : ", s:votenames[votessorted[i][1]][0]; 0, i+10000, 0, 64.1, y, 0.1);
                    }
                }
                
                // timer
                if(time_seconds > TIME_YELLOW)
                {
                    hudmessagebold(s:"\c[Green]", s:"Time Left: ", d:time_seconds; 0, 9998, 0, 32.1, 64.0, 0.1);
                }
                else if(time_seconds <= TIME_YELLOW && time_seconds > TIME_ORANGE)
                {
                    hudmessagebold(s:"\c[Yellow]", s:"Time Left: ", d:time_seconds; 0, 9998, 0, 32.1, 64.0, 0.1);
                }
                else if(time_seconds <= TIME_ORANGE && time_seconds > TIME_RED)
                {
                    hudmessagebold(s:"\c[Orange]", s:"Time Left: ", d:time_seconds; 0, 9998, 0, 32.1, 64.0, 0.1);
                }
                else if(time_seconds <= TIME_RED)
                {
                    hudmessagebold(s:"\c[Red]", s:"Time Left: ", d:time_seconds; 0, 9998, 0, 32.1, 64.0, 0.1);
                }
            }
            
            // end results
            else if(state == STATE_RESULTS)
            {
                hudmessagebold(s:"\c[Green]", s:"Winner: \c[Gold]", s:votenames[votechosen][0]; 0, 9998, 0, hud_width_half, hud_height_half-256.0, 0.1);
            }
            
            delay(1);
        }
    }

    // called by players to manage their votes
    script "VotePlayer" (int id)
    {
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
            modified_bubble_sort();
        }
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








    function void state_waitforvote(void)
    {
        if(votecount > 0)
        {
            state = STATE_COUNTDOWN;
            ACS_ExecuteAlways(570, 0, state);
        }
    }
    
    function void state_countdown(void)
    {
        time_ticks--;
        time_seconds = time_ticks/35;
        if(time_ticks <= 0)// || votecount >= playercount())
        {
            state = STATE_TIE;
            ACS_ExecuteAlways(570, 0, state);
        }
        if(votecount <= 0)
        {
            time_ticks = TIME_START*35;
            state = STATE_VOTEWAIT;
            ACS_ExecuteAlways(570, 0, state);
        }
        if(!(time_ticks%35))
        {
            // sync the timer with the clients
            ACS_Execute(569, 0, time_seconds);
        }
    }

    function void state_tie(void)
    {
        modified_bubble_sort();
        int tiecount = 0;
        for(int i = 1; i < 64; i++)
        {
            if(votessorted[i][0] == votessorted[0][0])
            {
                tiecount++;
            }
        }
        if(tiecount > 0)
        {
            votechosen = votessorted[random(0, tiecount)][1];
        }
        else
        {
            votechosen = votessorted[0][1];
        }
        
        // sync the clients
        ACS_Execute(568, 0, votechosen);
        
        state = STATE_RESULTS;
        ACS_ExecuteAlways(570, 0, state);
        state_clock = 0;
    }
    
    function void state_results(void)
    {
        state_clock++;
        if(state_clock > 5*35)
        {
            ChangeLevel(votenames[votechosen][1], 0, 0, -1);
        }
    }















    // sort voted list
    function void modified_bubble_sort(void)
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
  