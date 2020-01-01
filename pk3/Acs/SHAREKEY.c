#define KEY_COUNT 3
#define KEY_SYNC_DELAY 10
#define PICKUP_SOUND_COUNT 2

bool keysFound[KEY_COUNT];
str keyNames[KEY_COUNT] =
{
    "RedCard",
    "YellowCard",
    "BlueCard"
};
str pickupSounds[PICKUP_SOUND_COUNT] =
{
    "misc/k_pkup",
    "mayhem17/i_pkup"
};

script "SharedKey_Enter" ENTER
{
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

script "SharedKey_Pickup" (int i, int snd)
{
    int alreadyFound = 1;

    if (keysFound[i] == FALSE)
    {
        if (GetCVar("SV_ShareKeys") == 1)
        {
            AmbientSound(pickupSounds[snd], 127);
            Log(s:"\cd", n:0, s:"\c- ", l:"UI_KEYGET", s:" \cf", s:keyNames[i], s:"!");

            GiveActorInventory(0, keyNames[i], 1);
        }
        else
        {
            ActivatorSound(pickupSounds[snd], 127);

            GiveInventory(keyNames[i], 1);
        }

        keysFound[i] = TRUE;
        alreadyFound = 0;
    }

    SetResultValue(alreadyFound);
}