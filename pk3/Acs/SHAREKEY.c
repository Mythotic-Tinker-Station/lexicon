

bool keysfound[26];
str keynames[26] = 
{
    "RedCard", 
    "YellowCard", 
    "BlueCard", 
    "RedSkull", 
    "YellowSkull", 
    "BlueSkull", 
    "KeyBlue", 
    "KeyGreen", 
    "KeyYellow", 
    "ChexRedCard", 
    "ChexYellowCard",
    "ChexBlueCard", 
    "RedFlemKey", 
    "YellowFlemKey", 
    "BlueFlemKey", 
    "KeyAxe", 
    "KeyCastle", 
    "KeyCave", 
    "KeyDungeon", 
    "KeyEmerald", 
    "KeyFire", 
    "KeyHorn", 
    "KeyRusted", 
    "KeySilver", 
    "KeySteel",
    "KeySwamp"
};

script "GetFoundKeys_Enter" ENTER
{
    if (GetCVar("SV_SharedKeys") == 1)
    {
        for (int i = 0; i < 26; i++)
        {
            if (keysfound[i] == true)
            {
                GiveInventory(keynames[i], 1);
            }
        }
    }
}

script "GetFoundKeys_Respawn" RESPAWN
{
    if (GetCVar("SV_SharedKeys") == 1)
    {
        for (int i = 0; i < 26; i++)
        {
            if (keysfound[i] == true)
            {
                GiveInventory(keynames[i], 1);
            }
        }
    }
}

script "FoundKey" (int index)
{
    if (keysfound[index] == false)
    {
        str key = keynames[index];

        if (GetCVar("SV_SharedKeys") == 1)
        {
            PlaySound(0, "misc/k_pkup", CHAN_AUTO, 1.0, FALSE, ATTN_NONE);
            Log(s:"\cd", n:0, s:"\c- ", l:"UI_KEYGET", s:" \cf", s:key, s:"!");

            for (int i = 0; i < PlayerCount(); i++)
            {
                SetActivatorToPlayer(i);
                GiveInventory(key, 1);
            }
        }
        else
        {
            GiveInventory(key, 1);
        }
    }

    keysfound[index] = true;
}