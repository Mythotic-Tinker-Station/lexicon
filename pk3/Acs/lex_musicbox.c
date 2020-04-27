script "SV_MusicBox" (int id)
{
    switch(GetCVar("lexicon_global_votechosen"))
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
        break;
    }

    if(GetCVar("lexicon_global_miscpk3") == 0)
    {
        str track = "";
        int lastid = GetCVar("lexicon_global_musicid");

        if(id == 0)
        {
            SetCVar("lexicon_global_musicid", GetCVar("lexicon_global_musicid")+1);
            if(GetCVar("lexicon_global_musicid") > 32) { SetCVar("lexicon_global_musicid", 1); }
            lastid++;
        }
        else
        {
            SetCVar("lexicon_global_musicid", id);
        }

        switch(GetCVar("lexicon_global_musicid"))
        {
            case 1: track   = "d_runnin";   break;
            case 2: track   = "d_stalks";   break;
            case 3: track   = "d_countd";   break;
            case 4: track   = "d_betwee";   break;
            case 5: track   = "d_doom";     break;
            case 6: track   = "d_the_da";   break;
            case 7: track   = "d_shawn";    break;
            case 8: track   = "d_ddtblu";   break;
            case 9: track   = "d_in_cit";   break;
            case 10: track  = "d_dead";     break;
            case 11: track  = "d_stlks2";   break;
            case 12: track  = "d_theda2";   break;
            case 13: track  = "d_doom2";    break;
            case 14: track  = "d_ddtbl2";   break;
            case 15: track  = "d_runni2";   break;
            case 16: track  = "d_dead2";    break;
            case 17: track  = "d_stlks3";   break;
            case 18: track  = "d_romero";   break;
            case 19: track  = "d_shawn2";   break;
            case 20: track  = "d_messag";   break;
            case 21: track  = "d_count2";   break;
            case 22: track  = "d_ddtbl3";   break;
            case 23: track  = "d_ampie";    break;
            case 24: track  = "d_theda3";   break;
            case 25: track  = "d_adrian";   break;
            case 26: track  = "d_messg2";   break;
            case 27: track  = "d_romer2";   break;
            case 28: track  = "d_tense";    break;
            case 29: track  = "d_shawn3";   break;
            case 30: track  = "d_openin";   break;
            case 31: track  = "d_evil";     break;
            case 32: track  = "d_ultima";   break;
            case 33: track  = "d_read_m";   break;
        }
        LocalSetMusic(track);
        SetCVar("lexicon_global_musicid", lastid);
    }
}