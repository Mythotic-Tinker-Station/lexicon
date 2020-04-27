#define KEY_COUNT 6
#define KEY_SYNC_DELAY 10
#define PICKUP_SOUND_COUNT 2

bool keysFound[KEY_COUNT];
str keyNames[KEY_COUNT] =
{
    "RedCard",
    "YellowCard",
    "BlueCard",
    "RedSkull",
    "YellowSkull",
    "BlueSkull"
};
str pickupSounds[PICKUP_SOUND_COUNT] =
{
    "misc/k_pkup",
    "mayhem17/i_pkup"
};

script "SharedKey_Enter" ENTER
{
    if (GameType() != GAME_NET_COOPERATIVE)
    {
        terminate;
    }

    while (TRUE)
    {
        if (GetCVar("SV_ShareKeys") == 1)
        {
            for (int i = 0; i < KEY_COUNT; i++)
            {
                if (keysFound[i] == TRUE)
                {
                    GiveInventory(keyNames[i], 1);
                }
            }
        }

        Delay(KEY_SYNC_DELAY);
    }
}

script "SharedKey_Pickup" (int key, int snd)
{
    if (keysFound[key] == FALSE)
    {
        if (GetCVar("SV_ShareKeys") == 1 && GameType() == GAME_NET_COOPERATIVE)
        {
            AmbientSound(pickupSounds[snd], 127);
            Log(s:"\cd", n:0, s:"\c- ", l:"UI_KEYGET", s:" \cf", s:keyNames[key], s:"!");

            GiveActorInventory(0, keyNames[key], 1);
        }
        else
        {
            GiveInventory(keyNames[key], 1);
        }

        keysFound[key] = TRUE;
        SetResultValue(0);
    }
    else
    {
        GiveInventory(keyNames[key], 1);
        SetResultValue(1);
    }
}