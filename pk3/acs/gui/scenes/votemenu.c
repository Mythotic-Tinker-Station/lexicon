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

    }


	function void RunBGVignette()
	{
        //vignette
        Screen::DrawImage("VIGT", "a", "Black", 0.0, 0.0, Screen::XALIGN_LEFT, Screen::YALIGN_TOP);
        Screen::DrawImage("VIGB", "a", "Black", 0.0, Screen::GetHeight()-478.0, Screen::XALIGN_LEFT, Screen::YALIGN_TOP);
        Screen::DrawImage("VIGL", "a", "Black", 0.0, 0.0, Screen::XALIGN_LEFT, Screen::YALIGN_TOP);
        Screen::DrawImage("VIGR", "a", "Black", Screen::GetWidth()-478.0, 0.0, Screen::XALIGN_LEFT, Screen::YALIGN_TOP);
    }

	function void RunBG()
	{

        bgx += 1.0;
        bgy += 1.0;

        if(bgx > 320.0) { bgx -= 320.0; }
        if(bgy > 200.0) { bgy -= 200.0; }

        for(fixed x = -320.0; x < Screen::GetWidth(); x += 320.0)
        {
            for(fixed y = -200.0; y < Screen::GetHeight(); y += 200.0)
            {
                Screen::DrawImage("VOTEBG", "a", "White", x+bgx, y+bgy, Screen::XALIGN_LEFT, Screen::YALIGN_TOP);
            }
        }
	}

    function void RunWidgets()
	{
        
    }

	function void Event_MapsetClick(int id)
	{

	}
	function void Event_ExpansionClick(int id)
	{

	}
}


