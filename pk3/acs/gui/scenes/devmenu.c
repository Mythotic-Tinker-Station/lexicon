// dev menu and votemenu will be the same for now, just use devmenu and we'll move it to votemenu.c later
// TODO: Add grid pages
// TODO: Fix the vote button
// TODO: Add a back button
// TODO: Hook up vote system

strict namespace DevMenu
{
    // these variables hold the widget ids for the mapset buttons and labels
    int mapset_buttons[2048];
    int lblTitle;
    int lblAuthors;
    int lblDescription;
    int lblCustom;
    int lblMaps;
    int lblDate;
    int btnVote;
    int btnLeft;
    int btnRight;
    str mapAcronym;

    fixed bgx;
    fixed bgy;

    // entry point, called in gui.c by CL_GUI script, which is currently an enter script for debugging purposes
    // but in release CL_GUI will be called by a user clicking the lexicon cube
    function void Build(void)
    {
        // make the mapset tile grid
        // see gui/screen.c for Screen namespace functions
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

            // button::create returns an id number, which is stored in the mapset_buttons array
            // you can find this function in the gui/widgets/buttons.c file
            mapset_buttons[i] = Button::Create(x, y, cellWidth, cellHeight, mapSets[i].title);

            // all of these methods use the id number provided by the create function to set properties of the button
            // all of these methods and more are documented in the gui/widgets.c file
            Widgets::SetVisible(mapset_buttons[i], true);
            Widgets::SetFont(mapset_buttons[i], Font::font_lexiconsmall);
            Widgets::SetText(mapset_buttons[i], mapSets[i].title);
            Widgets::SetTextColorNormal(mapset_buttons[i], "White");
            Widgets::SetRenderText(mapset_buttons[i], true);
            Widgets::SetRenderImage(mapset_buttons[i], true);
            Widgets::SetImage(mapset_buttons[i], mapSets[i].thumbnail);
            Widgets::SetClickable(mapset_buttons[i], true);
            Widgets::SetHoverable(mapset_buttons[i], true);

            // add a clicked hook to the button, which is a function that is called when the button is clicked
            // Event_MapsetClick is a function defined below
            Widgets::AddClickedHook(mapset_buttons[i], Event_MapsetClick);
        }

        fixed infoX = gridOffsetX + cX;
        fixed infoY = gridOffsetY + cY + fixed(cellCount / int(cellCountX)) * (cellHeight + cellHeightPad) + 32.0;

        // similar to the mapset buttons, these are labels that display information about the selected mapset
        // you can find the create function in the gui/widgets/labels.c file
        lblTitle = Label::Create(infoX, infoY, Font::font_lexiconbig, mapSets[0].title);
        lblAuthors = Label::Create(infoX, infoY + 32.0, Font::font_lexiconbig, mapSets[0].authors);
        lblDescription = Label::Create(infoX, infoY + 64.0, Font::font_lexiconbig, mapSets[0].description);
        lblCustom = Label::Create(infoX, infoY + 96.0, Font::font_lexiconbig, mapSets[0].custom);
        lblMaps = Label::Create(infoX, infoY + 128.0, Font::font_lexiconbig, mapSets[0].maps);
        lblDate = Label::Create(infoX, infoY + 160.0, Font::font_lexiconbig, mapSets[0].date);
        mapAcronym = mapSets[0].acronym;

        // left button
        btnLeft = Button::Create(gridOffsetX + cX - 32.0, gridOffsetY + cY, 16.0, gridHeight, "Left");
        Widgets::SetRenderImage(btnLeft, true);
        Widgets::SetImage(btnLeft, "ARROWL");

        // right button
        btnRight = Button::Create(gridOffsetX + cX + gridWidth - 80.0, gridOffsetY + cY, 16.0, gridHeight, "Right");
        Widgets::SetRenderImage(btnRight, true);
        Widgets::SetImage(btnRight, "ARROWR");

        // vote button
        btnVote = Button::Create(infoX, infoY + 196.0, 128.0, 32.0, "Vote");
		Widgets::SetRenderText(btnVote, true);
        Widgets::SetFont(btnVote, Font::font_lexiconbig);
		Widgets::AddClickedHook(btnVote, Event_MapsetVote);
    }

    // the scrolling translucent purple intermission background
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

    // user clicked a mapset
	function void Event_MapsetClick(int id)
	{
        // set the text of the labels to the information of the selected mapset
        Widgets::SetText(lblTitle,        strParam(l:"LEXICON_UI_MAPSET_TITLE", s:mapSets[id].title));
        Widgets::SetText(lblAuthors,      strParam(l:"LEXICON_UI_MAPSET_AUTHORS", s:mapSets[id].authors));
        Widgets::SetText(lblDescription,  strParam(l:"LEXICON_UI_MAPSET_DESCRIPTION", s:mapSets[id].description));
        Widgets::SetText(lblCustom,       strParam(l:"LEXICON_UI_MAPSET_CUSTOM", s:mapSets[id].custom));
        Widgets::SetText(lblMaps,         strParam(l:"LEXICON_UI_MAPSET_MAPS", s:mapSets[id].maps));
        Widgets::SetText(lblDate,         strParam(l:"LEXICON_UI_MAPSET_DATE", s:mapSets[id].date));
        mapAcronym = mapSets[id].acronym;
	}
	
	// user voted a mapset
	function void Event_MapsetVote(int id)
	{
		SetPlayerProperty(1, 0, PROP_TOTALLYFROZEN);
		ChangeLevel(strParam(s:mapAcronym, d:0, d:1), 0, CHANGELEVEL_NOINTERMISSION, -1);
	}
}


