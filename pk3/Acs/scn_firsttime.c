
struct _scn_firsttime
{
    int lbl_title;
    int lbl_cursorcolor;
    int btn_cursorcolor1;
    int btn_cursorcolor2;
    int btn_cursorcolor3;
    int btn_cursorcolor4;
    int btn_cursorcolor5;
    int btn_cursorcolor6;
    int btn_cursorcolor7;
    int btn_cursorcolor8;
    int btn_cursorcolor9;
    int btn_cursorcolor10;
    int btn_cursorcolor11;
    int btn_cursorcolor12;
    int btn_cursorcolor13;
    int btn_cursorcolor14;
    int btn_cursorcolor15;
    int lbl_cursorshadow;
    int btn_cursorshadow;
    int lbl_cursorxsens;
    int sld_cursorxsens;
    int img_cursorxsens;
    int lbl_cursorysens;
    int sld_cursorysens;
    int img_cursorysens;
    int lbl_dontshow;
    int btn_dontshow;
    int lbl_notes;
    int btn_confirmfirst;
	bool movein;
	bool confirmed;
};

struct _scn_firsttime scn_firsttime;


// build the list of rules that the server has enabled
function void guiBuildSettingsScene(void)
{
    // settings label
	scn_firsttime.lbl_title = guiObjectCreate();
	gui.objects[scn_firsttime.lbl_title].pos.x1 = gui.w_half;
	gui.objects[scn_firsttime.lbl_title].pos.y1 = gui.h_half - 256.0 - 32.0;
	gui.objects[scn_firsttime.lbl_title].pos.x2 = gui.objects[scn_firsttime.lbl_title].pos.x1;
	gui.objects[scn_firsttime.lbl_title].pos.y2 = gui.objects[scn_firsttime.lbl_title].pos.y1;
    gui.objects[scn_firsttime.lbl_title].text_font = "SONICFONTHD";
	gui.objects[scn_firsttime.lbl_title].text = "First Time Setup";
	gui.objects[scn_firsttime.lbl_title].render_text = true;

    // cursor color label
	scn_firsttime.lbl_cursorcolor = guiObjectCreate();
	gui.objects[scn_firsttime.lbl_cursorcolor].pos.x1 = gui.w_half - 96.0;
	gui.objects[scn_firsttime.lbl_cursorcolor].pos.y1 = gui.h_half - 160.0;
	gui.objects[scn_firsttime.lbl_cursorcolor].pos.x2 = gui.objects[scn_firsttime.lbl_cursorcolor].pos.x1;
	gui.objects[scn_firsttime.lbl_cursorcolor].pos.y2 = gui.objects[scn_firsttime.lbl_cursorcolor].pos.y1;
    gui.objects[scn_firsttime.lbl_cursorcolor].text_font = "SONICFONTHD";
	gui.objects[scn_firsttime.lbl_cursorcolor].text = "Cursor Color:";
    gui.objects[scn_firsttime.lbl_cursorcolor].textalign.x = GUI_XALIGN_RIGHT;
	gui.objects[scn_firsttime.lbl_cursorcolor].render_text = true;


    // cursor color 1 (Red)
    scn_firsttime.btn_cursorcolor1 = guiObjectCreate();
	gui.objects[scn_firsttime.btn_cursorcolor1].pos.x1 = gui.w_half - 32.0;
	gui.objects[scn_firsttime.btn_cursorcolor1].pos.y1 = gui.h_half - 160.0 - 16.0;
	gui.objects[scn_firsttime.btn_cursorcolor1].pos.x2 = gui.objects[scn_firsttime.btn_cursorcolor1].pos.x1 + 32.0;
	gui.objects[scn_firsttime.btn_cursorcolor1].pos.y2 = gui.objects[scn_firsttime.btn_cursorcolor1].pos.y1 + 32.0;
    gui.objects[scn_firsttime.btn_cursorcolor1].text_font = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorcolor1].text = "\c[Red]H";
    gui.objects[scn_firsttime.btn_cursorcolor1].text_font_checked = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorcolor1].text_checked = "\c[Red]K";
    gui.objects[scn_firsttime.btn_cursorcolor1].textalign.x = GUI_XALIGN_LEFT;
    gui.objects[scn_firsttime.btn_cursorcolor1].textalign.y = GUI_YALIGN_TOP;
    gui.objects[scn_firsttime.btn_cursorcolor1].clickable = true;
    gui.objects[scn_firsttime.btn_cursorcolor1].checkable = true;
    gui.objects[scn_firsttime.btn_cursorcolor1].func = guiChangeCursorColor;

    // cursor color 2 (Ornage)
    scn_firsttime.btn_cursorcolor2 = guiObjectCreate();
	gui.objects[scn_firsttime.btn_cursorcolor2].pos.x1 = gui.w_half;
	gui.objects[scn_firsttime.btn_cursorcolor2].pos.y1 = gui.h_half - 160.0 - 16.0;
	gui.objects[scn_firsttime.btn_cursorcolor2].pos.x2 = gui.objects[scn_firsttime.btn_cursorcolor2].pos.x1 + 32.0;
	gui.objects[scn_firsttime.btn_cursorcolor2].pos.y2 = gui.objects[scn_firsttime.btn_cursorcolor2].pos.y1 + 32.0;
    gui.objects[scn_firsttime.btn_cursorcolor2].text_font = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorcolor2].text = "\c[Orange]H";
    gui.objects[scn_firsttime.btn_cursorcolor2].text_font_checked = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorcolor2].text_checked = "\c[Orange]K";
    gui.objects[scn_firsttime.btn_cursorcolor2].textalign.x = GUI_XALIGN_LEFT;
    gui.objects[scn_firsttime.btn_cursorcolor2].textalign.y = GUI_YALIGN_TOP;
    gui.objects[scn_firsttime.btn_cursorcolor2].clickable = true;
    gui.objects[scn_firsttime.btn_cursorcolor2].checkable = true;
    gui.objects[scn_firsttime.btn_cursorcolor2].func = guiChangeCursorColor;

    // cursor color 3 (Yellow)
    scn_firsttime.btn_cursorcolor3 = guiObjectCreate();
	gui.objects[scn_firsttime.btn_cursorcolor3].pos.x1 = gui.w_half + 32.0;
	gui.objects[scn_firsttime.btn_cursorcolor3].pos.y1 = gui.h_half - 160.0 - 16.0;
	gui.objects[scn_firsttime.btn_cursorcolor3].pos.x2 = gui.objects[scn_firsttime.btn_cursorcolor3].pos.x1 + 32.0;
	gui.objects[scn_firsttime.btn_cursorcolor3].pos.y2 = gui.objects[scn_firsttime.btn_cursorcolor3].pos.y1 + 32.0;
    gui.objects[scn_firsttime.btn_cursorcolor3].text_font = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorcolor3].text = "\c[Yellow]H";
    gui.objects[scn_firsttime.btn_cursorcolor3].text_font_checked = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorcolor3].text_checked = "\c[Yellow]K";
    gui.objects[scn_firsttime.btn_cursorcolor3].textalign.x = GUI_XALIGN_LEFT;
    gui.objects[scn_firsttime.btn_cursorcolor3].textalign.y = GUI_YALIGN_TOP;
    gui.objects[scn_firsttime.btn_cursorcolor3].clickable = true;
    gui.objects[scn_firsttime.btn_cursorcolor3].checkable = true;
    gui.objects[scn_firsttime.btn_cursorcolor3].func = guiChangeCursorColor;

    // cursor color 4 (SpringGreen)
    scn_firsttime.btn_cursorcolor4 = guiObjectCreate();
	gui.objects[scn_firsttime.btn_cursorcolor4].pos.x1 = gui.w_half + 64.0;
	gui.objects[scn_firsttime.btn_cursorcolor4].pos.y1 = gui.h_half - 160.0 - 16.0;
	gui.objects[scn_firsttime.btn_cursorcolor4].pos.x2 = gui.objects[scn_firsttime.btn_cursorcolor4].pos.x1 + 32.0;
	gui.objects[scn_firsttime.btn_cursorcolor4].pos.y2 = gui.objects[scn_firsttime.btn_cursorcolor4].pos.y1 + 32.0;
    gui.objects[scn_firsttime.btn_cursorcolor4].text_font = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorcolor4].text = "\c[SpringGreen]H";
    gui.objects[scn_firsttime.btn_cursorcolor4].text_font_checked = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorcolor4].text_checked = "\c[SpringGreen]K";
    gui.objects[scn_firsttime.btn_cursorcolor4].textalign.x = GUI_XALIGN_LEFT;
    gui.objects[scn_firsttime.btn_cursorcolor4].textalign.y = GUI_YALIGN_TOP;
    gui.objects[scn_firsttime.btn_cursorcolor4].clickable = true;
    gui.objects[scn_firsttime.btn_cursorcolor4].checkable = true;
    gui.objects[scn_firsttime.btn_cursorcolor4].func = guiChangeCursorColor;

    // cursor color 5 (Lime)
    scn_firsttime.btn_cursorcolor5 = guiObjectCreate();
	gui.objects[scn_firsttime.btn_cursorcolor5].pos.x1 = gui.w_half + 96.0;
	gui.objects[scn_firsttime.btn_cursorcolor5].pos.y1 = gui.h_half - 160.0 - 16.0;
	gui.objects[scn_firsttime.btn_cursorcolor5].pos.x2 = gui.objects[scn_firsttime.btn_cursorcolor5].pos.x1 + 32.0;
	gui.objects[scn_firsttime.btn_cursorcolor5].pos.y2 = gui.objects[scn_firsttime.btn_cursorcolor5].pos.y1 + 32.0;
    gui.objects[scn_firsttime.btn_cursorcolor5].text_font = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorcolor5].text = "\c[Lime]H";
    gui.objects[scn_firsttime.btn_cursorcolor5].text_font_checked = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorcolor5].text_checked = "\c[Lime]K";
    gui.objects[scn_firsttime.btn_cursorcolor5].textalign.x = GUI_XALIGN_LEFT;
    gui.objects[scn_firsttime.btn_cursorcolor5].textalign.y = GUI_YALIGN_TOP;
    gui.objects[scn_firsttime.btn_cursorcolor5].clickable = true;
    gui.objects[scn_firsttime.btn_cursorcolor5].checkable = true;
    gui.objects[scn_firsttime.btn_cursorcolor5].func = guiChangeCursorColor;

    // cursor color 6 (Chartreuse)
    scn_firsttime.btn_cursorcolor6 = guiObjectCreate();
	gui.objects[scn_firsttime.btn_cursorcolor6].pos.x1 = gui.w_half + 128.0;
	gui.objects[scn_firsttime.btn_cursorcolor6].pos.y1 = gui.h_half - 160.0 - 16.0;
	gui.objects[scn_firsttime.btn_cursorcolor6].pos.x2 = gui.objects[scn_firsttime.btn_cursorcolor6].pos.x1 + 32.0;
	gui.objects[scn_firsttime.btn_cursorcolor6].pos.y2 = gui.objects[scn_firsttime.btn_cursorcolor6].pos.y1 + 32.0;
    gui.objects[scn_firsttime.btn_cursorcolor6].text_font = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorcolor6].text = "\c[Chartreuse]H";
    gui.objects[scn_firsttime.btn_cursorcolor6].text_font_checked = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorcolor6].text_checked = "\c[Chartreuse]K";
    gui.objects[scn_firsttime.btn_cursorcolor6].textalign.x = GUI_XALIGN_LEFT;
    gui.objects[scn_firsttime.btn_cursorcolor6].textalign.y = GUI_YALIGN_TOP;
    gui.objects[scn_firsttime.btn_cursorcolor6].clickable = true;
    gui.objects[scn_firsttime.btn_cursorcolor6].checkable = true;
    gui.objects[scn_firsttime.btn_cursorcolor6].func = guiChangeCursorColor;

    // cursor color 7 (Cyan)
    scn_firsttime.btn_cursorcolor7 = guiObjectCreate();
	gui.objects[scn_firsttime.btn_cursorcolor7].pos.x1 = gui.w_half + 160.0;
	gui.objects[scn_firsttime.btn_cursorcolor7].pos.y1 = gui.h_half - 160.0 - 16.0;
	gui.objects[scn_firsttime.btn_cursorcolor7].pos.x2 = gui.objects[scn_firsttime.btn_cursorcolor7].pos.x1 + 32.0;
	gui.objects[scn_firsttime.btn_cursorcolor7].pos.y2 = gui.objects[scn_firsttime.btn_cursorcolor7].pos.y1 + 32.0;
    gui.objects[scn_firsttime.btn_cursorcolor7].text_font = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorcolor7].text = "\c[Cyan]H";
    gui.objects[scn_firsttime.btn_cursorcolor7].text_font_checked = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorcolor7].text_checked = "\c[Cyan]K";
    gui.objects[scn_firsttime.btn_cursorcolor7].textalign.x = GUI_XALIGN_LEFT;
    gui.objects[scn_firsttime.btn_cursorcolor7].textalign.y = GUI_YALIGN_TOP;
    gui.objects[scn_firsttime.btn_cursorcolor7].clickable = true;
    gui.objects[scn_firsttime.btn_cursorcolor7].checkable = true;
    gui.objects[scn_firsttime.btn_cursorcolor7].func = guiChangeCursorColor;

    // cursor color 8 (Azure)
    scn_firsttime.btn_cursorcolor8 = guiObjectCreate();
	gui.objects[scn_firsttime.btn_cursorcolor8].pos.x1 = gui.w_half + 192.0;
	gui.objects[scn_firsttime.btn_cursorcolor8].pos.y1 = gui.h_half - 160.0 - 16.0;
	gui.objects[scn_firsttime.btn_cursorcolor8].pos.x2 = gui.objects[scn_firsttime.btn_cursorcolor8].pos.x1 + 32.0;
	gui.objects[scn_firsttime.btn_cursorcolor8].pos.y2 = gui.objects[scn_firsttime.btn_cursorcolor8].pos.y1 + 32.0;
    gui.objects[scn_firsttime.btn_cursorcolor8].text_font = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorcolor8].text = "\c[Azure]H";
    gui.objects[scn_firsttime.btn_cursorcolor8].text_font_checked = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorcolor8].text_checked = "\c[Azure]K";
    gui.objects[scn_firsttime.btn_cursorcolor8].textalign.x = GUI_XALIGN_LEFT;
    gui.objects[scn_firsttime.btn_cursorcolor8].textalign.y = GUI_YALIGN_TOP;
    gui.objects[scn_firsttime.btn_cursorcolor8].clickable = true;
    gui.objects[scn_firsttime.btn_cursorcolor8].checkable = true;
    gui.objects[scn_firsttime.btn_cursorcolor8].func = guiChangeCursorColor;

    // cursor color 9 (Blue)
    scn_firsttime.btn_cursorcolor9 = guiObjectCreate();
	gui.objects[scn_firsttime.btn_cursorcolor9].pos.x1 = gui.w_half + 224.0;
	gui.objects[scn_firsttime.btn_cursorcolor9].pos.y1 = gui.h_half - 160.0 - 16.0;
	gui.objects[scn_firsttime.btn_cursorcolor9].pos.x2 = gui.objects[scn_firsttime.btn_cursorcolor9].pos.x1 + 32.0;
	gui.objects[scn_firsttime.btn_cursorcolor9].pos.y2 = gui.objects[scn_firsttime.btn_cursorcolor9].pos.y1 + 32.0;
    gui.objects[scn_firsttime.btn_cursorcolor9].text_font = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorcolor9].text = "\c[Blue]H";
    gui.objects[scn_firsttime.btn_cursorcolor9].text_font_checked = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorcolor9].text_checked = "\c[Blue]K";
    gui.objects[scn_firsttime.btn_cursorcolor9].textalign.x = GUI_XALIGN_LEFT;
    gui.objects[scn_firsttime.btn_cursorcolor9].textalign.y = GUI_YALIGN_TOP;
    gui.objects[scn_firsttime.btn_cursorcolor9].clickable = true;
    gui.objects[scn_firsttime.btn_cursorcolor9].checkable = true;
    gui.objects[scn_firsttime.btn_cursorcolor9].func = guiChangeCursorColor;

    // cursor color 10 (Purple)
    scn_firsttime.btn_cursorcolor10 = guiObjectCreate();
	gui.objects[scn_firsttime.btn_cursorcolor10].pos.x1 = gui.w_half + 256.0;
	gui.objects[scn_firsttime.btn_cursorcolor10].pos.y1 = gui.h_half - 160.0 - 16.0;
	gui.objects[scn_firsttime.btn_cursorcolor10].pos.x2 = gui.objects[scn_firsttime.btn_cursorcolor10].pos.x1 + 32.0;
	gui.objects[scn_firsttime.btn_cursorcolor10].pos.y2 = gui.objects[scn_firsttime.btn_cursorcolor10].pos.y1 + 32.0;
    gui.objects[scn_firsttime.btn_cursorcolor10].text_font = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorcolor10].text = "\c[Purple]H";
    gui.objects[scn_firsttime.btn_cursorcolor10].text_font_checked = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorcolor10].text_checked = "\c[Purple]K";
    gui.objects[scn_firsttime.btn_cursorcolor10].textalign.x = GUI_XALIGN_LEFT;
    gui.objects[scn_firsttime.btn_cursorcolor10].textalign.y = GUI_YALIGN_TOP;
    gui.objects[scn_firsttime.btn_cursorcolor10].clickable = true;
    gui.objects[scn_firsttime.btn_cursorcolor10].checkable = true;
    gui.objects[scn_firsttime.btn_cursorcolor10].func = guiChangeCursorColor;

    // cursor color 11 (Magenta)
    scn_firsttime.btn_cursorcolor11 = guiObjectCreate();
	gui.objects[scn_firsttime.btn_cursorcolor11].pos.x1 = gui.w_half + 288.0;
	gui.objects[scn_firsttime.btn_cursorcolor11].pos.y1 = gui.h_half - 160.0 - 16.0;
	gui.objects[scn_firsttime.btn_cursorcolor11].pos.x2 = gui.objects[scn_firsttime.btn_cursorcolor11].pos.x1 + 32.0;
	gui.objects[scn_firsttime.btn_cursorcolor11].pos.y2 = gui.objects[scn_firsttime.btn_cursorcolor11].pos.y1 + 32.0;
    gui.objects[scn_firsttime.btn_cursorcolor11].text_font = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorcolor11].text = "\c[Magenta]H";
    gui.objects[scn_firsttime.btn_cursorcolor11].text_font_checked = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorcolor11].text_checked = "\c[Magenta]K";
    gui.objects[scn_firsttime.btn_cursorcolor11].textalign.x = GUI_XALIGN_LEFT;
    gui.objects[scn_firsttime.btn_cursorcolor11].textalign.y = GUI_YALIGN_TOP;
    gui.objects[scn_firsttime.btn_cursorcolor11].clickable = true;
    gui.objects[scn_firsttime.btn_cursorcolor11].checkable = true;
    gui.objects[scn_firsttime.btn_cursorcolor11].func = guiChangeCursorColor;

    // cursor color 12 (Rose)
    scn_firsttime.btn_cursorcolor12 = guiObjectCreate();
	gui.objects[scn_firsttime.btn_cursorcolor12].pos.x1 = gui.w_half + 320.0;
	gui.objects[scn_firsttime.btn_cursorcolor12].pos.y1 = gui.h_half - 160.0 - 16.0;
	gui.objects[scn_firsttime.btn_cursorcolor12].pos.x2 = gui.objects[scn_firsttime.btn_cursorcolor12].pos.x1 + 32.0;
	gui.objects[scn_firsttime.btn_cursorcolor12].pos.y2 = gui.objects[scn_firsttime.btn_cursorcolor12].pos.y1 + 32.0;
    gui.objects[scn_firsttime.btn_cursorcolor12].text_font = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorcolor12].text = "\c[Rose]H";
    gui.objects[scn_firsttime.btn_cursorcolor12].text_font_checked = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorcolor12].text_checked = "\c[Rose]K";
    gui.objects[scn_firsttime.btn_cursorcolor12].textalign.x = GUI_XALIGN_LEFT;
    gui.objects[scn_firsttime.btn_cursorcolor12].textalign.y = GUI_YALIGN_TOP;
    gui.objects[scn_firsttime.btn_cursorcolor12].clickable = true;
    gui.objects[scn_firsttime.btn_cursorcolor12].checkable = true;
    gui.objects[scn_firsttime.btn_cursorcolor12].func = guiChangeCursorColor;

    // cursor color 13 (White)
    scn_firsttime.btn_cursorcolor13 = guiObjectCreate();
	gui.objects[scn_firsttime.btn_cursorcolor13].pos.x1 = gui.w_half + 352.0;
	gui.objects[scn_firsttime.btn_cursorcolor13].pos.y1 = gui.h_half - 160.0 - 16.0;
	gui.objects[scn_firsttime.btn_cursorcolor13].pos.x2 = gui.objects[scn_firsttime.btn_cursorcolor13].pos.x1 + 32.0;
	gui.objects[scn_firsttime.btn_cursorcolor13].pos.y2 = gui.objects[scn_firsttime.btn_cursorcolor13].pos.y1 + 32.0;
    gui.objects[scn_firsttime.btn_cursorcolor13].text_font = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorcolor13].text = "\c[White]H";
    gui.objects[scn_firsttime.btn_cursorcolor13].text_font_checked = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorcolor13].text_checked = "\c[White]K";
    gui.objects[scn_firsttime.btn_cursorcolor13].textalign.x = GUI_XALIGN_LEFT;
    gui.objects[scn_firsttime.btn_cursorcolor13].textalign.y = GUI_YALIGN_TOP;
    gui.objects[scn_firsttime.btn_cursorcolor13].clickable = true;
    gui.objects[scn_firsttime.btn_cursorcolor13].checkable = true;
    gui.objects[scn_firsttime.btn_cursorcolor13].func = guiChangeCursorColor;

    // cursor color 14 (Black)
    scn_firsttime.btn_cursorcolor14 = guiObjectCreate();
	gui.objects[scn_firsttime.btn_cursorcolor14].pos.x1 = gui.w_half + 384.0;
	gui.objects[scn_firsttime.btn_cursorcolor14].pos.y1 = gui.h_half - 160.0 - 16.0;
	gui.objects[scn_firsttime.btn_cursorcolor14].pos.x2 = gui.objects[scn_firsttime.btn_cursorcolor14].pos.x1 + 32.0;
	gui.objects[scn_firsttime.btn_cursorcolor14].pos.y2 = gui.objects[scn_firsttime.btn_cursorcolor14].pos.y1 + 32.0;
    gui.objects[scn_firsttime.btn_cursorcolor14].text_font = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorcolor14].text = "\c[Black]H";
    gui.objects[scn_firsttime.btn_cursorcolor14].text_font_checked = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorcolor14].text_checked = "\c[Black]K";
    gui.objects[scn_firsttime.btn_cursorcolor14].textalign.x = GUI_XALIGN_LEFT;
    gui.objects[scn_firsttime.btn_cursorcolor14].textalign.y = GUI_YALIGN_TOP;
    gui.objects[scn_firsttime.btn_cursorcolor14].clickable = true;
    gui.objects[scn_firsttime.btn_cursorcolor14].checkable = true;
    gui.objects[scn_firsttime.btn_cursorcolor14].func = guiChangeCursorColor;

    // cursor color 15 (Brown)
    scn_firsttime.btn_cursorcolor15 = guiObjectCreate();
	gui.objects[scn_firsttime.btn_cursorcolor15].pos.x1 = gui.w_half + 416.0;
	gui.objects[scn_firsttime.btn_cursorcolor15].pos.y1 = gui.h_half - 160.0 - 16.0;
	gui.objects[scn_firsttime.btn_cursorcolor15].pos.x2 = gui.objects[scn_firsttime.btn_cursorcolor15].pos.x1 + 32.0;
	gui.objects[scn_firsttime.btn_cursorcolor15].pos.y2 = gui.objects[scn_firsttime.btn_cursorcolor15].pos.y1 + 32.0;
    gui.objects[scn_firsttime.btn_cursorcolor15].text_font = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorcolor15].text = "\c[Brown]H";
    gui.objects[scn_firsttime.btn_cursorcolor15].text_font_checked = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorcolor15].text_checked = "\c[Brown]K";
    gui.objects[scn_firsttime.btn_cursorcolor15].textalign.x = GUI_XALIGN_LEFT;
    gui.objects[scn_firsttime.btn_cursorcolor15].textalign.y = GUI_YALIGN_TOP;
    gui.objects[scn_firsttime.btn_cursorcolor15].clickable = true;
    gui.objects[scn_firsttime.btn_cursorcolor15].checkable = true;
    gui.objects[scn_firsttime.btn_cursorcolor15].func = guiChangeCursorColor;

    // check the box represented by the cvar value
    switch(GetCVarString("lexicon_cursor_color"))
    {
        case "Red": gui.objects[scn_firsttime.btn_cursorcolor1].checked = true; break;
        case "Orange": gui.objects[scn_firsttime.btn_cursorcolor2].checked = true; break;
        case "Yellow": gui.objects[scn_firsttime.btn_cursorcolor3].checked = true; break;
        case "SpringGreen": gui.objects[scn_firsttime.btn_cursorcolor4].checked = true; break;
        case "Lime": gui.objects[scn_firsttime.btn_cursorcolor5].checked = true; break;
        case "Chartreuse": gui.objects[scn_firsttime.btn_cursorcolor6].checked = true; break;
        case "Cyan": gui.objects[scn_firsttime.btn_cursorcolor7].checked = true; break;
        case "Azure": gui.objects[scn_firsttime.btn_cursorcolor8].checked = true; break;
        case "Blue": gui.objects[scn_firsttime.btn_cursorcolor9].checked = true; break;
        case "Purple": gui.objects[scn_firsttime.btn_cursorcolor10].checked = true; break;
        case "Magenta": gui.objects[scn_firsttime.btn_cursorcolor11].checked = true; break;
        case "Rose": gui.objects[scn_firsttime.btn_cursorcolor12].checked = true; break;
        case "White": gui.objects[scn_firsttime.btn_cursorcolor13].checked = true; break;
        case "Black": gui.objects[scn_firsttime.btn_cursorcolor14].checked = true; break;
        case "Brown": gui.objects[scn_firsttime.btn_cursorcolor15].checked = true; break;
    }


    // cursor shadow label
	scn_firsttime.lbl_cursorshadow = guiObjectCreate();
	gui.objects[scn_firsttime.lbl_cursorshadow].pos.x1 = gui.w_half - 96.0;
	gui.objects[scn_firsttime.lbl_cursorshadow].pos.y1 = gui.h_half - 112.0;
	gui.objects[scn_firsttime.lbl_cursorshadow].pos.x2 = gui.objects[scn_firsttime.lbl_cursorshadow].pos.x1;
	gui.objects[scn_firsttime.lbl_cursorshadow].pos.y2 = gui.objects[scn_firsttime.lbl_cursorshadow].pos.y1;
    gui.objects[scn_firsttime.lbl_cursorshadow].text_font = "SONICFONTHD";
	gui.objects[scn_firsttime.lbl_cursorshadow].text = "Cursor Shadow:";
    gui.objects[scn_firsttime.lbl_cursorshadow].textalign.x = GUI_XALIGN_RIGHT;
	gui.objects[scn_firsttime.lbl_cursorshadow].render_text = true;

     // cursor shadow button
    scn_firsttime.btn_cursorshadow = guiObjectCreate();
	gui.objects[scn_firsttime.btn_cursorshadow].pos.x1 = gui.w_half - 32.0;
	gui.objects[scn_firsttime.btn_cursorshadow].pos.y1 = gui.h_half - 112.0 - 16.0;
	gui.objects[scn_firsttime.btn_cursorshadow].pos.x2 = gui.objects[scn_firsttime.btn_cursorshadow].pos.x1 + 32.0;
	gui.objects[scn_firsttime.btn_cursorshadow].pos.y2 = gui.objects[scn_firsttime.btn_cursorshadow].pos.y1 + 32.0;
    gui.objects[scn_firsttime.btn_cursorshadow].text_font = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorshadow].text = "\c[White]H";
    gui.objects[scn_firsttime.btn_cursorshadow].text_font_checked = "PANELFONT";
	gui.objects[scn_firsttime.btn_cursorshadow].text_checked = "\c[Cyan]K";
    gui.objects[scn_firsttime.btn_cursorshadow].textalign.x = GUI_XALIGN_LEFT;
    gui.objects[scn_firsttime.btn_cursorshadow].textalign.y = GUI_YALIGN_TOP;
    gui.objects[scn_firsttime.btn_cursorshadow].clickable = true;
    gui.objects[scn_firsttime.btn_cursorshadow].checkable = true;
    gui.objects[scn_firsttime.btn_cursorshadow].func = guiChangeCursorShadow;
    if(GetCVar("lexicon_cursor_shadow") == 1) { gui.objects[scn_firsttime.btn_cursorshadow].checked = true; }


    // cursor xsens label
	scn_firsttime.lbl_cursorxsens = guiObjectCreate();
	gui.objects[scn_firsttime.lbl_cursorxsens].pos.x1 = gui.w_half - 96.0;
	gui.objects[scn_firsttime.lbl_cursorxsens].pos.y1 = gui.h_half - 64.0;
	gui.objects[scn_firsttime.lbl_cursorxsens].pos.x2 = gui.objects[scn_firsttime.lbl_cursorxsens].pos.x1;
	gui.objects[scn_firsttime.lbl_cursorxsens].pos.y2 = gui.objects[scn_firsttime.lbl_cursorxsens].pos.y1;
    gui.objects[scn_firsttime.lbl_cursorxsens].text_font = "SONICFONTHD";
	gui.objects[scn_firsttime.lbl_cursorxsens].text = "Cursor X Sens:";
    gui.objects[scn_firsttime.lbl_cursorxsens].textalign.x = GUI_XALIGN_RIGHT;
	gui.objects[scn_firsttime.lbl_cursorxsens].render_text = true;


    // cursor xsens slider
	scn_firsttime.sld_cursorxsens = guiObjectCreate();
	gui.objects[scn_firsttime.sld_cursorxsens].pos.x1 = gui.w_half - 32.0;
	gui.objects[scn_firsttime.sld_cursorxsens].pos.y1 = gui.h_half - 64.0 - 16.0;
	gui.objects[scn_firsttime.sld_cursorxsens].pos.x2 = gui.objects[scn_firsttime.sld_cursorxsens].pos.x1 + 16.0;
	gui.objects[scn_firsttime.sld_cursorxsens].pos.y2 = gui.objects[scn_firsttime.sld_cursorxsens].pos.y1 + 24.0;
    gui.objects[scn_firsttime.sld_cursorxsens].text_font = "PANELFONT";
	gui.objects[scn_firsttime.sld_cursorxsens].text = "\c[White]M";
    gui.objects[scn_firsttime.sld_cursorxsens].textalign.y = GUI_YALIGN_TOP;
	gui.objects[scn_firsttime.sld_cursorxsens].render_text = true;
    gui.objects[scn_firsttime.sld_cursorxsens].draggable = true;
    gui.objects[scn_firsttime.sld_cursorxsens].clickable = true;
    gui.objects[scn_firsttime.sld_cursorxsens].drag_y = false;
    gui.objects[scn_firsttime.sld_cursorxsens].clickhold = true;
    gui.objects[scn_firsttime.sld_cursorxsens].draglimit.x1 = gui.objects[scn_firsttime.sld_cursorxsens].pos.x1;
    gui.objects[scn_firsttime.sld_cursorxsens].draglimit.x2 = gui.objects[scn_firsttime.sld_cursorxsens].pos.x1 + 255.0;
    gui.objects[scn_firsttime.sld_cursorxsens].func = guiCursorSliderCalc;


    // cursor xsens slider back
	scn_firsttime.img_cursorxsens = guiObjectCreate();
	gui.objects[scn_firsttime.img_cursorxsens].pos.x1 = gui.objects[scn_firsttime.sld_cursorxsens].pos.x1;
	gui.objects[scn_firsttime.img_cursorxsens].pos.y1 = gui.objects[scn_firsttime.sld_cursorxsens].pos.y1 + 4.0;
	gui.objects[scn_firsttime.img_cursorxsens].pos.x2 = gui.objects[scn_firsttime.img_cursorxsens].pos.x1 + 255.0;
	gui.objects[scn_firsttime.img_cursorxsens].pos.y2 = gui.objects[scn_firsttime.img_cursorxsens].pos.y1 + 16.0;
    gui.objects[scn_firsttime.img_cursorxsens].text_font = "PANELFONT";
	gui.objects[scn_firsttime.img_cursorxsens].text = "\c[White]N";
    gui.objects[scn_firsttime.img_cursorxsens].textalign.x = GUI_XALIGN_LEFT;
    gui.objects[scn_firsttime.img_cursorxsens].textalign.y = GUI_YALIGN_TOP;
	gui.objects[scn_firsttime.img_cursorxsens].render_text = true;


    fixed min = gui.objects[scn_firsttime.img_cursorxsens].pos.x1;
    fixed max = gui.objects[scn_firsttime.img_cursorxsens].pos.x2 - 16.0;
    fixed value = fixed(GetCVar("lexicon_cursor_xsens"));
    fixed length = max-min;
    fixed vnorm = ((value-5.0) / (55.0 - 5.0));
    fixed pos = (vnorm*length) + min;

    gui.objects[scn_firsttime.sld_cursorxsens].pos.x1 = fixed(int(pos));
    gui.objects[scn_firsttime.sld_cursorxsens].pos.x2 = gui.objects[scn_firsttime.sld_cursorxsens].pos.x1 + 16.0;


    // cursor ysens label
	scn_firsttime.lbl_cursorysens = guiObjectCreate();
	gui.objects[scn_firsttime.lbl_cursorysens].pos.x1 = gui.w_half - 96.0;
	gui.objects[scn_firsttime.lbl_cursorysens].pos.y1 = gui.h_half - 16.0;
	gui.objects[scn_firsttime.lbl_cursorysens].pos.x2 = gui.objects[scn_firsttime.lbl_cursorysens].pos.x1;
	gui.objects[scn_firsttime.lbl_cursorysens].pos.y2 = gui.objects[scn_firsttime.lbl_cursorysens].pos.y1;
    gui.objects[scn_firsttime.lbl_cursorysens].text_font = "SONICFONTHD";
	gui.objects[scn_firsttime.lbl_cursorysens].text = "Cursor Y Sens:";
    gui.objects[scn_firsttime.lbl_cursorysens].textalign.x = GUI_XALIGN_RIGHT;
	gui.objects[scn_firsttime.lbl_cursorysens].render_text = true;


    // cursor ysens slider
	scn_firsttime.sld_cursorysens = guiObjectCreate();
	gui.objects[scn_firsttime.sld_cursorysens].pos.x1 = gui.w_half - 32.0;
	gui.objects[scn_firsttime.sld_cursorysens].pos.y1 = gui.h_half - 16.0 - 16.0;
	gui.objects[scn_firsttime.sld_cursorysens].pos.x2 = gui.objects[scn_firsttime.sld_cursorysens].pos.x1 + 16.0;
	gui.objects[scn_firsttime.sld_cursorysens].pos.y2 = gui.objects[scn_firsttime.sld_cursorysens].pos.y1 + 24.0;
    gui.objects[scn_firsttime.sld_cursorysens].text_font = "PANELFONT";
	gui.objects[scn_firsttime.sld_cursorysens].text = "\c[White]M";
    gui.objects[scn_firsttime.sld_cursorysens].textalign.y = GUI_YALIGN_TOP;
	gui.objects[scn_firsttime.sld_cursorysens].render_text = true;
    gui.objects[scn_firsttime.sld_cursorysens].draggable = true;
    gui.objects[scn_firsttime.sld_cursorysens].clickable = true;
    gui.objects[scn_firsttime.sld_cursorysens].drag_y = false;
    gui.objects[scn_firsttime.sld_cursorysens].clickhold = true;
    gui.objects[scn_firsttime.sld_cursorysens].draglimit.x1 = gui.objects[scn_firsttime.sld_cursorysens].pos.x1;
    gui.objects[scn_firsttime.sld_cursorysens].draglimit.x2 = gui.objects[scn_firsttime.sld_cursorysens].pos.x1 + 255.0;
    gui.objects[scn_firsttime.sld_cursorysens].func = guiCursorSliderCalc;

    // cursor ysens slider back
	scn_firsttime.img_cursorysens = guiObjectCreate();
	gui.objects[scn_firsttime.img_cursorysens].pos.x1 = gui.objects[scn_firsttime.sld_cursorysens].pos.x1;
	gui.objects[scn_firsttime.img_cursorysens].pos.y1 = gui.objects[scn_firsttime.sld_cursorysens].pos.y1 + 4.0;
	gui.objects[scn_firsttime.img_cursorysens].pos.x2 = gui.objects[scn_firsttime.img_cursorysens].pos.x1 + 255.0;
	gui.objects[scn_firsttime.img_cursorysens].pos.y2 = gui.objects[scn_firsttime.img_cursorysens].pos.y1 + 16.0;
    gui.objects[scn_firsttime.img_cursorysens].text_font = "PANELFONT";
	gui.objects[scn_firsttime.img_cursorysens].text = "\c[White]N";
    gui.objects[scn_firsttime.img_cursorysens].textalign.x = GUI_XALIGN_LEFT;
    gui.objects[scn_firsttime.img_cursorysens].textalign.y = GUI_YALIGN_TOP;
	gui.objects[scn_firsttime.img_cursorysens].render_text = true;

    fixed min2 = gui.objects[scn_firsttime.img_cursorysens].pos.x1;
    fixed max2 = gui.objects[scn_firsttime.img_cursorysens].pos.x2 - 16.0;
    fixed value2 = fixed(GetCVar("lexicon_cursor_ysens"));
    fixed length2 = max2-min2;
    fixed vnorm2 = ((value2-5.0) / (55.0 - 5.0));
    fixed pos2 = (vnorm2*length2) + min2;

    gui.objects[scn_firsttime.sld_cursorysens].pos.x1 = fixed(int(pos2));
    gui.objects[scn_firsttime.sld_cursorysens].pos.x2 = gui.objects[scn_firsttime.sld_cursorysens].pos.x1 + 16.0;

    // dont show at startup label
	scn_firsttime.lbl_dontshow = guiObjectCreate();
	gui.objects[scn_firsttime.lbl_dontshow].pos.x1 = gui.w_half - 96.0;
	gui.objects[scn_firsttime.lbl_dontshow].pos.y1 = gui.h_half + 32.0;
	gui.objects[scn_firsttime.lbl_dontshow].pos.x2 = gui.objects[scn_firsttime.lbl_dontshow].pos.x1;
	gui.objects[scn_firsttime.lbl_dontshow].pos.y2 = gui.objects[scn_firsttime.lbl_dontshow].pos.y1;
    gui.objects[scn_firsttime.lbl_dontshow].text_font = "SONICFONTHD";
	gui.objects[scn_firsttime.lbl_dontshow].text = "Show at startup:";
    gui.objects[scn_firsttime.lbl_dontshow].textalign.x = GUI_XALIGN_RIGHT;
	gui.objects[scn_firsttime.lbl_dontshow].render_text = true;

    // dont show at startup button
    scn_firsttime.btn_dontshow = guiObjectCreate();
	gui.objects[scn_firsttime.btn_dontshow].pos.x1 = gui.w_half - 32.0;
	gui.objects[scn_firsttime.btn_dontshow].pos.y1 = gui.h_half + 32.0 - 16.0;
	gui.objects[scn_firsttime.btn_dontshow].pos.x2 = gui.objects[scn_firsttime.btn_dontshow].pos.x1 + 32.0;
	gui.objects[scn_firsttime.btn_dontshow].pos.y2 = gui.objects[scn_firsttime.btn_dontshow].pos.y1 + 32.0;
    gui.objects[scn_firsttime.btn_dontshow].text_font = "PANELFONT";
	gui.objects[scn_firsttime.btn_dontshow].text = "\c[White]H";
    gui.objects[scn_firsttime.btn_dontshow].text_font_checked = "PANELFONT";
	gui.objects[scn_firsttime.btn_dontshow].text_checked = "\c[Cyan]K";
    gui.objects[scn_firsttime.btn_dontshow].textalign.x = GUI_XALIGN_LEFT;
    gui.objects[scn_firsttime.btn_dontshow].textalign.y = GUI_YALIGN_TOP;
    gui.objects[scn_firsttime.btn_dontshow].clickable = true;
    gui.objects[scn_firsttime.btn_dontshow].checkable = true;
    gui.objects[scn_firsttime.btn_dontshow].func = guiChangeDontShow;
    if(GetCVar("lexicon_first_run") == 1) { gui.objects[scn_firsttime.btn_dontshow].checked = true; }

    // notes
	scn_firsttime.lbl_notes = guiObjectCreate();
	gui.objects[scn_firsttime.lbl_notes].pos.x1 = gui.w_half - 400.0;
	gui.objects[scn_firsttime.lbl_notes].pos.y1 = gui.h_half + 128.0;
	gui.objects[scn_firsttime.lbl_notes].pos.x2 = gui.objects[scn_firsttime.lbl_notes].pos.x1;
	gui.objects[scn_firsttime.lbl_notes].pos.y2 = gui.objects[scn_firsttime.lbl_notes].pos.y1;
    gui.objects[scn_firsttime.lbl_notes].text_font = "SONICFONT";
	gui.objects[scn_firsttime.lbl_notes].text =   "\c[Green]Note\c[White]: These settings will be used every time you launch lexicon.\n\n\c[Green]Note\c[White]: Cursor sensitivity will not effect your zandronum mouse sensitivity.\n          \c[White]Cursor sens is divided by your current mouse sens, so lower is faster.\n\n\c[Green]Note\c[White]: You can change these settings later in the lexicon menu.";
    gui.objects[scn_firsttime.lbl_notes].textalign.x = GUI_XALIGN_LEFT;
	gui.objects[scn_firsttime.lbl_notes].render_text = true;

    // confirm button
    scn_firsttime.btn_confirmfirst = guiObjectCreate();
	gui.objects[scn_firsttime.btn_confirmfirst].pos.x1 = gui.w_half - 64.0;
	gui.objects[scn_firsttime.btn_confirmfirst].pos.y1 = gui.h_half + 192.0;
	gui.objects[scn_firsttime.btn_confirmfirst].pos.x2 = gui.objects[scn_firsttime.btn_confirmfirst].pos.x1 + 128.0;
	gui.objects[scn_firsttime.btn_confirmfirst].pos.y2 = gui.objects[scn_firsttime.btn_confirmfirst].pos.y1 + 64.0;
    gui.objects[scn_firsttime.btn_confirmfirst].text_font = "SONICFONTHD";
	gui.objects[scn_firsttime.btn_confirmfirst].text = "Confirm";
	gui.objects[scn_firsttime.btn_confirmfirst].textalign.x = GUI_XALIGN_CENTER;
    gui.objects[scn_firsttime.btn_confirmfirst].text_font2 = "PANELFONT";
	gui.objects[scn_firsttime.btn_confirmfirst].text2 = "\c[White]a";
    gui.objects[scn_firsttime.btn_confirmfirst].render_text2 = true;
    gui.objects[scn_firsttime.btn_confirmfirst].clickable = true;
    gui.objects[scn_firsttime.btn_confirmfirst].func = guiConfirm;
}

// change cursor sens
function void guiCursorSliderCalc(int id)
{
    fixed min = gui.objects[scn_firsttime.img_cursorxsens].pos.x1;
    fixed max = gui.objects[scn_firsttime.img_cursorxsens].pos.x2 - 16.0;
    fixed value = gui.objects[id].pos.x1;
    fixed percent = ((value-min) / (max-min)) * 20.0;
    gui.objects[id].custom1 = int(percent);

    if(id == scn_firsttime.sld_cursorxsens) { SetCVar("lexicon_cursor_xsens", gui.objects[id].custom1 + 5); }
    if(id == scn_firsttime.sld_cursorysens) { SetCVar("lexicon_cursor_ysens", gui.objects[id].custom1 + 5); }
}


// change show at startup
function void guiChangeDontShow(int id)
{
    if(gui.objects[id].checked) { SetCVar("lexicon_first_run", 1); }
    if(!gui.objects[id].checked) { SetCVar("lexicon_first_run", 0); }
}

// change cursor shadow
function void guiChangeCursorShadow(int id)
{
    if(gui.objects[id].checked) { SetCVar("lexicon_cursor_shadow", 1); }
    if(!gui.objects[id].checked) { SetCVar("lexicon_cursor_shadow", 0); }
}

// change cursor color
function void guiChangeCursorColor(int id)
{
   // uncheck all the things
    for(int i = 0; i <= 15; i++)
    {
        gui.objects[scn_firsttime.btn_cursorcolor1+i].checked = false;
    }

    // check the button that called this function
    gui.objects[id].checked = true;

    // set user setting
    if(scn_firsttime.btn_cursorcolor1 == id) { SetCVarString("lexicon_cursor_color",  "Red"); }
    if(scn_firsttime.btn_cursorcolor2 == id) { SetCVarString("lexicon_cursor_color",  "Orange"); }
    if(scn_firsttime.btn_cursorcolor3 == id) { SetCVarString("lexicon_cursor_color",  "Yellow"); }
    if(scn_firsttime.btn_cursorcolor4 == id) { SetCVarString("lexicon_cursor_color",  "SpringGreen"); }
    if(scn_firsttime.btn_cursorcolor5 == id) { SetCVarString("lexicon_cursor_color",  "Lime"); }
    if(scn_firsttime.btn_cursorcolor6 == id) { SetCVarString("lexicon_cursor_color",  "Chartreuse"); }
    if(scn_firsttime.btn_cursorcolor7 == id) { SetCVarString("lexicon_cursor_color",  "Cyan"); }
    if(scn_firsttime.btn_cursorcolor8 == id) { SetCVarString("lexicon_cursor_color",  "Azure"); }
    if(scn_firsttime.btn_cursorcolor9 == id) { SetCVarString("lexicon_cursor_color",  "Blue"); }
    if(scn_firsttime.btn_cursorcolor10 == id) { SetCVarString("lexicon_cursor_color", "Purple"); }
    if(scn_firsttime.btn_cursorcolor11 == id) { SetCVarString("lexicon_cursor_color", "Magenta"); }
    if(scn_firsttime.btn_cursorcolor12 == id) { SetCVarString("lexicon_cursor_color", "Rose"); }
    if(scn_firsttime.btn_cursorcolor13 == id) { SetCVarString("lexicon_cursor_color", "White"); }
    if(scn_firsttime.btn_cursorcolor14 == id) { SetCVarString("lexicon_cursor_color", "Black"); }
    if(scn_firsttime.btn_cursorcolor15 == id) { SetCVarString("lexicon_cursor_color", "Brown"); }
}

// change cursor shadow
function void guiConfirm(int id)
{
	scn_firsttime.confirmed = true;
}

script "Scene_FirstTime_Run" enter clientside
{

	if(!clientCheck()) { terminate; }
	if(GetLevelInfo(LEVELINFO_LEVELNUM) != 99) { terminate; }

	// this must wait a tic to let the gui scripts run first
	delay(1);

	if(GetCVar("lexicon_first_run") == 1)
	{
		guiBuildSettingsscene();
		guiMove(gui.w, 0.0);
		scn_firsttime.movein = true;
	}
	else
	{
		scn_firsttime.confirmed = true;
	}
	while(1)
	{
		// move into position
		if(scn_firsttime.movein)
		{
			guiMove(-250.0, 0.0);
			if(gui.objects[scn_firsttime.lbl_title].pos.x1 <= gui.w_half)
			{
				fixed d = gui.w_half - gui.objects[scn_firsttime.lbl_title].pos.x1;
				guiMove(d, 0.0);
				scn_firsttime.movein = false;
			}
		}

		// move out of scene and go to the next scene
		if(scn_firsttime.confirmed)
		{
			if(guiMove(-250.0, 0.0) == 2)
			{
				guiObjectsClear();
				ACS_NamedExecute("Scene_Selection_Run", 0);
				terminate;
			}
		}
		delay(1);
	}
}


