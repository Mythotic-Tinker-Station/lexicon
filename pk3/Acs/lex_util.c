

// sort voted list
function void bubble_sort(void)
{
    int t;
    int j = MAPSET_MAX;
    int s = 1;
    int v;
    for (int i = 0; i < MAPSET_MAX; i++)
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

    for(int i = 0; i < MAPSET_MAX; i++)
    {
        ACS_NamedExecuteAlways("Sync_Votes", 0, i, votessorted[i][0], votessorted[i][1]);
    }
}

function void HudSetup(str font)
{
    int x = GetScreenWidth();
    int y = GetScreenHeight();

    hud_width = (fixed)(x*65536);
    hud_height = (fixed)(y*65536);

    hud_width_half = hud_width/2.0;
    hud_height_half = hud_height/2.0;

    SetHudSize(x, y, true);
    SetFont(font);
}

// get language.txt entries with a specific format
function str getDynLangEntry(str p1, str p2)
{
    // get entry
    str name = strparam(s:p1, s:"_", s:p2);
    str text = strparam(l:name);

    // check if listing exists
    if(text == name)
    {
        text = strparam(s:p1, s:"_", s:"ERR");
    }
    return text;
}

script "RottenEggs" (int id) clientside
{
    // get lore
    str lore = getDynLangEntry("LORE", strparam(i:id));

    // display lore
    HudSetup("HUDFONT");
    hudmessage(s:lore; HUDMSG_LOG, 9701, 0, hud_width_half, hud_height_half, 10.0);
}