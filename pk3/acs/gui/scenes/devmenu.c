strict namespace DevMenu
{
    int mapset_buttons[2048];
    int lblTitle;
    int lblAuthors;
    int lblDescription;
    int lblCustom;
    int lblMaps;
    int lblDate;

    fixed bgx;
    fixed bgy;
    function void Build(void)
    {   
        fixed gridWidth = Screen::GetWidth() - 64.0;
        fixed gridHeight = Screen::GetHeight() / 2.0;
        fixed gridOffsetX = 0.0;
        fixed gridOffsetY = -128.0;
        fixed cellWidth = 192.0;
        fixed cellHeight = 108.0;
        fixed cellWidthPad = 4.0;
        fixed cellHeightPad = 4.0;
        
        fixed cellCountX = fixed(int(gridWidth / cellWidth));
        fixed cellCountY = fixed(int(gridHeight / cellHeight));
        int cellCount = int(cellCountX * cellCountY);

        fixed cX = (Screen::GetWidth() - (cellCountX * (cellWidth + cellWidthPad))) / 2.0;
        fixed cY = (Screen::GetHeight() - (cellCountY * (cellHeight + cellHeightPad))) / 2.0;

        for (int i = 0; i < cellCount; i++)
        {
            fixed x = gridOffsetX + cX + fixed(i % int(cellCountX)) * (cellWidth + cellWidthPad);
            fixed y = gridOffsetY + cY + fixed(i / int(cellCountX)) * (cellHeight + cellHeightPad);

            mapset_buttons[i] = Button::Create(x, y, cellWidth, cellHeight, mapSets[i].title);
            Widgets::SetVisible(mapset_buttons[i], true);
            Widgets::SetRenderBack(mapset_buttons[i], false);
            Widgets::SetFont(mapset_buttons[i], Font::font_fancysmall);
            Widgets::SetText(mapset_buttons[i], mapSets[i].title);
            Widgets::SetTextColorNormal(mapset_buttons[i], "White");
            Widgets::SetRenderImage(mapset_buttons[i], true);
            Widgets::SetImage(mapset_buttons[i], mapSets[i].thumbnail);
            Widgets::SetClickable(mapset_buttons[i], true);
            Widgets::SetHoverable(mapset_buttons[i], true);
            Widgets::AddClickedHook(mapset_buttons[i], Event_ExpansionClick);
        }

        fixed infoX = gridOffsetX + cX;
        fixed infoY = gridOffsetY + cY + fixed(cellCount / int(cellCountX)) * (cellHeight + cellHeightPad) + 32.0;
        lblTitle = Label::Create(infoX, infoY, Font::font_lexiconbig, mapSets[0].title);
        lblAuthors = Label::Create(infoX, infoY + 32.0, Font::font_lexiconbig, mapSets[0].authors);
        lblDescription = Label::Create(infoX, infoY + 64.0, Font::font_lexiconbig, mapSets[0].description);
        lblCustom = Label::Create(infoX, infoY + 96.0, Font::font_lexiconbig, mapSets[0].custom);
        lblMaps = Label::Create(infoX, infoY + 128.0, Font::font_lexiconbig, mapSets[0].maps);
        lblDate = Label::Create(infoX, infoY + 160.0, Font::font_lexiconbig, mapSets[0].date);

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
        Label::SetText(lblTitle,        strParam(s:"Title: ",   s:mapSets[id].title));
        Label::SetText(lblAuthors,      strParam(s:"Authors: ", s:mapSets[id].authors));
        Label::SetText(lblDescription,  strParam(s:"Description: ", s:mapSets[id].description));
        Label::SetText(lblCustom,       strParam(s:"Custom: ", s:mapSets[id].custom));
        Label::SetText(lblMaps,         strParam(s:"Maps: ", s:mapSets[id].maps));
        Label::SetText(lblDate,         strParam(s:"Date: ", s:mapSets[id].date));
	}
}


