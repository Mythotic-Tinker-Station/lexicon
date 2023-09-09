strict namespace VoteMenu
{

    int mapset_buttons[2048];
    int expansion_buttons[2048];
    int lbl_expansions;
    fixed bgx;
    fixed bgy;
    int test;
	function void Build(void)
	{    
        /*
        // mapset buttons
		for(int i = 0; i < mapset_count; i++)
		{
			mapset_buttons[i] = ButtonImage::Create(0.0, 0.0, mapsets[i].thumbnail, mapsets[i].name);
			Widgets::SetArg1Str(mapset_buttons[i], mapsets[i].startmap);
			Widgets::SetArg2Int(mapset_buttons[i], mapsets[i].id);
            Widgets::SetVisible(mapset_buttons[i], false);
			Widgets::AddClickedHook(mapset_buttons[i], Event_MapsetClick);
		}
*/
/*
        // expansion buttons
		for(int i = 0; i < expansion_count; i++)
		{
			expansion_buttons[i] = ButtonCheck::Create(0.0, 0.0, expansions[i].name);
            Widgets::SetVisible(expansion_buttons[i], false);
			Widgets::AddClickedHook(expansion_buttons[i], Event_ExpansionClick);
            Widgets::SetFont(expansion_buttons[i], Font::font_fancybig);
            Widgets::SetText(expansion_buttons[i], expansions[i].name);
            Widgets::SetTextColorNormal(expansion_buttons[i], "White");

		}
*/

        test = Button::Create(100.0, 100.0, 200.0, 24.0, "test");

        // expansion label
		//lbl_expansions = Label::Create(200.0, 200.0, Font::font_fancybig, "Expansions");

        // mapset label
        //lbl_expansions = Label::Create(Screen::GetCenterX()-((16.0*7.0)/2.0), 200.0, Font::font_fancybig, "Mapsets");
    }

	function void Run()
	{
        // background
        bgx += 1.0;
        bgy += 1.0;

        if(bgx > 320.0) { bgx -= 320.0; }
        if(bgy > 200.0) { bgy -= 200.0; }

        for(fixed x = -320.0; x < Screen::GetWidth(); x += 320.0)
        {
            for(fixed y = -200.0; y < Screen::GetHeight(); y += 200.0)
            {
                Screen::DrawImage("VOTEBG", "a", "Red", x+bgx, y+bgy, Screen::XALIGN_LEFT, Screen::YALIGN_TOP);
            }
        }
        
        //vignette
        Screen::DrawImage("VIGT", "a", "Black", 0.0, 0.0, Screen::XALIGN_LEFT, Screen::YALIGN_TOP);
        Screen::DrawImage("VIGB", "a", "Black", 0.0, Screen::GetHeight()-478.0, Screen::XALIGN_LEFT, Screen::YALIGN_TOP);
        Screen::DrawImage("VIGL", "a", "Black", 0.0, 0.0, Screen::XALIGN_LEFT, Screen::YALIGN_TOP);
        Screen::DrawImage("VIGR", "a", "Black", Screen::GetWidth()-478.0, 0.0, Screen::XALIGN_LEFT, Screen::YALIGN_TOP);

/*
        // expansion buttons
        for(int i = 0; i < expansion_count; i++)
		{
            Widgets::SetVisible(expansion_buttons[i], true);
            Widgets::SetRectPosition(expansion_buttons[i], 200.0, 230.0+(fixed(i)*32.0), 128.0, 24.0);
        }
*/
	}

	function void Event_MapsetClick(int id)
	{

	}
	function void Event_ExpansionClick(int id)
	{

	}
}


