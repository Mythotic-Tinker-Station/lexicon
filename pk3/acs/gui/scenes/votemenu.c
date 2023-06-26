strict namespace VoteMenu
{

    int mapset_buttons[2048];
    int expansion_buttons[2048];
    int lbl_expansions;
	function void Build(void)
	{    
        // mapset buttons
		for(int i = 0; i < mapset_count; i++)
		{
			mapset_buttons[i] = ButtonImage::Create(0.0, 0.0, mapsets[i].thumbnail, mapsets[i].name);
			Widgets::SetArg1Str(mapset_buttons[i], mapsets[i].startmap);
			Widgets::SetArg2Int(mapset_buttons[i], mapsets[i].id);
            Widgets::SetVisible(mapset_buttons[i], false);
			Widgets::AddClickedHook(mapset_buttons[i], Event_MapsetClick);
		}

        // expansion buttons
		for(int i = 0; i < expansion_count; i++)
		{
			expansion_buttons[i] = ButtonCheck::Create(0.0, 0.0, expansions[i].name);
            Widgets::SetVisible(expansion_buttons[i], false);
			Widgets::AddClickedHook(expansion_buttons[i], Event_ExpansionClick);
            Widgets::SetText(expansion_buttons[i], expansions[i].name);
            Widgets::SetTextColorNormal(expansion_buttons[i], "White");
		}

        // expansion label
		lbl_expansions = Label::Create(200.0, 200.0, "FANCYFONTBIG", "Expansions");

        // mapset label
        lbl_expansions = Label::Create(Screen::GetCenterX()-((16.0*7.0)/2.0), 200.0, "FANCYFONTBIG", "Mapsets");
    }

	function void Run()
	{
        for(int i = 0; i < expansion_count; i++)
		{
            Widgets::SetVisible(expansion_buttons[i], true);
            Widgets::SetRectPosition(expansion_buttons[i], 200.0, 230.0+(fixed(i)*24.0), 128.0, 24.0);
        }
	}

	function void Event_MapsetClick(int id)
	{

	}
	function void Event_ExpansionClick(int id)
	{

	}
}


