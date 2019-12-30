


#define KEY_COUNT 3

bool keysfound[KEY_COUNT];
str keynames[KEY_COUNT] = 
{
    "RedCard", 
    "YellowCard", 
    "BlueCard"
};


function void GetFoundKeys(void)
{
    if (GetCVar("SV_SharedKeys") == 1)
    {
        for (int i = 0; i < KEY_COUNT; i++)
        {
            if (keysfound[i] == true)
            {
                GiveInventory(keynames[i], 1);
            }
        }
    }
}

script "SharedKey_Enter" ENTER
{
    GetFoundKeys();
}

script "SharedKey_Respawn" RESPAWN
{
    GetFoundKeys();
}

script "SharedKey_Pickup" (int i, int snd)
{
    if (keysfound[i] == false)
    {
        if (GetCVar("SV_SharedKeys") == 1)
        {
            switch(snd)
            {
                case 0: PlaySound(0, "misc/k_pkup", CHAN_AUTO, 1.0, FALSE, ATTN_NONE); break;
                case 1: PlaySound(0, "mayhem17/i_pkup", CHAN_AUTO, 1.0, FALSE, ATTN_NONE); break;
            }
            
            Log(s:"\cd", n:0, s:"\c- ", l:"UI_KEYGET", s:" \cf", s:keynames[i], s:"!");
            for (int p = 0; p < PlayerCount(); p++)
            {
                SetActivatorToPlayer(p);
                GiveInventory(keynames[i], 1);
            }
        }
        else
        {
            GiveInventory(keynames[i], 1);
        }
    }

    keysfound[i] = true;
}