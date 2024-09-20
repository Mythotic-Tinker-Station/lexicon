strict namespace DevMenu
{
    int mapset_buttons[2048];

    fixed bgx;
    fixed bgy;
	function void Build(void)
	{   
        fixed gridWidth = Screen::GetWidth() - 64.0;
        fixed gridHeight = Screen::GetHeight() - 432.0;
        fixed cellWidth = 192.0;
        fixed cellHeight = 108.0;
        fixed cellWidthPad = 4.0;
        fixed cellHeightPad = 4.0;
        fixed cellCountX = fixed(int(gridWidth / cellWidth));
        fixed cellCountY = fixed(int(gridHeight / cellHeight));
        int cellCount = int(cellCountX * cellCountY);

        fixed gridX = (Screen::GetWidth() - (cellCountX * (cellWidth + cellWidthPad))) / 2.0;
        fixed gridY = (Screen::GetHeight() - (cellCountY * (cellHeight + cellHeightPad))) / 2.0;

        for (int i = 0; i < cellCount; i++)
        {
            fixed x = gridX + fixed(i % int(cellCountX)) * (cellWidth + cellWidthPad);
            fixed y = gridY + fixed(i / int(cellCountX)) * (cellHeight + cellHeightPad);
            mapset_buttons[i] = Button::Create(x, y, cellWidth, cellHeight, mapSets[i].title);
            Widgets::SetVisible(mapset_buttons[i], true);
            Widgets::AddClickedHook(mapset_buttons[i], Event_ExpansionClick);
            Widgets::SetFont(mapset_buttons[i], Font::font_fancysmall);
            Widgets::SetText(mapset_buttons[i], mapSets[i].title);
            Widgets::SetTextColorNormal(mapset_buttons[i], "White");
            Widgets::SetRenderBack(mapset_buttons[i], false);
            Widgets::SetImage(mapset_buttons[i], "BLNKTN");
            Widgets::SetRenderImage(mapset_buttons[i], true);
        }
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
        //vignette
        Screen::DrawImage("VIGT", "a", "Black", 0.0, 0.0, Screen::XALIGN_LEFT, Screen::YALIGN_TOP);
        Screen::DrawImage("VIGB", "a", "Black", 0.0, Screen::GetHeight()-478.0, Screen::XALIGN_LEFT, Screen::YALIGN_TOP);
        Screen::DrawImage("VIGL", "a", "Black", 0.0, 0.0, Screen::XALIGN_LEFT, Screen::YALIGN_TOP);
        Screen::DrawImage("VIGR", "a", "Black", Screen::GetWidth()-478.0, 0.0, Screen::XALIGN_LEFT, Screen::YALIGN_TOP);
	}

	function void Event_MapsetClick(int id)
	{

	}
	function void Event_ExpansionClick(int id)
	{

	}
}


