// debug mode
script "SV_DebugOpen" open
{
    if(GetLevelInfo(LEVELINFO_LEVELNUM) == 99)
    {
        SetCVar("lexicon_global_godmode", 0);
        SetCVar("lexicon_global_instakiller", 0);
        TakeActorInventory(0, "Lexicon_GodMode", 999);
        TakeActorInventory(0, "Lexicon_InstaKiller", 999);
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

script "SV_DebugSwitch" (int id)
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