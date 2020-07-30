struct _scn_selection
{
    int lbl_title;
	int btn_scroll_left;
	int btn_scroll_right;
	int sld_gridbar;
	int img_gridbar;
	int pic_preview;
	int lbl_test;
	int lbl_test2;
	struct vec2 grid;
	struct vec2 tilecount;
	fixed tilecount_x_pixels;
	fixed page_count;

	bool movein;
};

struct _scn_selection scn_selection;


// build the list of rules that the server has enabled
function void guiBuildSelectionScene(void)
{
	// "Select Mapset"
	scn_selection.lbl_title = guiObjectCreate();
	gui.objects[scn_selection.lbl_title].pos.x1 = gui.w_half;
	gui.objects[scn_selection.lbl_title].pos.y1 = 50.0;
	gui.objects[scn_selection.lbl_title].pos.x2 = gui.objects[scn_selection.lbl_title].pos.x1;
	gui.objects[scn_selection.lbl_title].pos.y2 = gui.objects[scn_selection.lbl_title].pos.y1;
    gui.objects[scn_selection.lbl_title].text_font = "SONICFONTHD";
	gui.objects[scn_selection.lbl_title].text = "Select Mapset";
	gui.objects[scn_selection.lbl_title].render_text = true;


	// tile grid
	fixed image_w = 160.0;	// image width
	fixed image_h = 120.0;	// image height

	scn_selection.tilecount.x = fixed(int(gui.w/image_w));
	scn_selection.tilecount.y = fixed(int(gui.h/image_h));

	scn_selection.tilecount_x_pixels = scn_selection.tilecount.x*image_w;

	while(scn_selection.tilecount_x_pixels > gui.w-(image_w*2.0))
	{
		scn_selection.tilecount.x--;
		scn_selection.tilecount_x_pixels = scn_selection.tilecount.x*image_w;
	}

	scn_selection.grid.x = gui.w_half - fixed(int(scn_selection.tilecount_x_pixels/2.0));
	scn_selection.grid.y = 100.0;

	for(fixed x = 0.0; x < scn_selection.tilecount.x; x += 1.0)
	{
		int tile = guiObjectCreate();
		gui.objects[tile].render_text = true;
		gui.objects[tile].hoverable = true;
		gui.objects[tile].pos.x1 = scn_selection.grid.x + (x*image_w);
		gui.objects[tile].pos.y1 = scn_selection.grid.y;
		gui.objects[tile].pos.x2 = gui.objects[tile].pos.x1 + image_w;
		gui.objects[tile].pos.y2 = gui.objects[tile].pos.y1 + image_h;
		gui.objects[tile].text_font = "SCRG0000";
		gui.objects[tile].text = "a";
		gui.objects[tile].text_font_hovered = "SCRN0000";
		gui.objects[tile].text_hovered = "a";
	}

	// left arrow button
	scn_selection.btn_scroll_left = guiObjectCreate();
	gui.objects[scn_selection.btn_scroll_left].pos.x1 = scn_selection.grid.x;
	gui.objects[scn_selection.btn_scroll_left].pos.y1 = scn_selection.grid.y+image_h;
	gui.objects[scn_selection.btn_scroll_left].pos.x2 = gui.objects[scn_selection.btn_scroll_left].pos.x1 + 32.0;
	gui.objects[scn_selection.btn_scroll_left].pos.y2 = gui.objects[scn_selection.btn_scroll_left].pos.y1 + 32.0;
    gui.objects[scn_selection.btn_scroll_left].text_font = "PANELFONT";
	gui.objects[scn_selection.btn_scroll_left].text = "\c[Cyan]R";
	gui.objects[scn_selection.btn_scroll_left].text_font_hovered = "PANELFONT";
	gui.objects[scn_selection.btn_scroll_left].text_hovered = "\c[Blue]R";
	gui.objects[scn_selection.btn_scroll_left].textalign.x = GUI_XALIGN_LEFT;
    gui.objects[scn_selection.btn_scroll_left].textalign.y = GUI_YALIGN_TOP;
	gui.objects[scn_selection.btn_scroll_left].render_text = true;
	gui.objects[scn_selection.btn_scroll_left].hoverable = true;

	// right arrow button
	scn_selection.btn_scroll_right = guiObjectCreate();
	gui.objects[scn_selection.btn_scroll_right].pos.x1 = (scn_selection.grid.x+(scn_selection.tilecount.x*160.0))-32.0;
	gui.objects[scn_selection.btn_scroll_right].pos.y1 = scn_selection.grid.y+image_h;
	gui.objects[scn_selection.btn_scroll_right].pos.x2 = gui.objects[scn_selection.btn_scroll_right].pos.x1 + 32.0;
	gui.objects[scn_selection.btn_scroll_right].pos.y2 = gui.objects[scn_selection.btn_scroll_right].pos.y1 + 32.0;
    gui.objects[scn_selection.btn_scroll_right].text_font = "PANELFONT";
	gui.objects[scn_selection.btn_scroll_right].text = "\c[Cyan]S";
	gui.objects[scn_selection.btn_scroll_right].text_font_hovered = "PANELFONT";
	gui.objects[scn_selection.btn_scroll_right].text_hovered = "\c[Blue]S";
	gui.objects[scn_selection.btn_scroll_right].textalign.x = GUI_XALIGN_RIGHT;
    gui.objects[scn_selection.btn_scroll_right].textalign.y = GUI_YALIGN_TOP;
	gui.objects[scn_selection.btn_scroll_right].render_text = true;
	gui.objects[scn_selection.btn_scroll_right].hoverable = true;

    // slider
	scn_selection.sld_gridbar = guiObjectCreate();
	gui.objects[scn_selection.sld_gridbar].pos.x1 = scn_selection.grid.x+33.0;
	gui.objects[scn_selection.sld_gridbar].pos.y1 = scn_selection.grid.y+image_h+4.0;
	gui.objects[scn_selection.sld_gridbar].pos.x2 = gui.objects[scn_selection.sld_gridbar].pos.x1 + 16.0;
	gui.objects[scn_selection.sld_gridbar].pos.y2 = gui.objects[scn_selection.sld_gridbar].pos.y1 + 24.0;
    gui.objects[scn_selection.sld_gridbar].text_font = "PANELFONT";
	gui.objects[scn_selection.sld_gridbar].text = "\c[Cyan]M";
	gui.objects[scn_selection.sld_gridbar].text_font_hovered = "PANELFONT";
	gui.objects[scn_selection.sld_gridbar].text_hovered = "\c[Blue]M";
    gui.objects[scn_selection.sld_gridbar].textalign.y = GUI_YALIGN_TOP;
	gui.objects[scn_selection.sld_gridbar].render_text = true;
    gui.objects[scn_selection.sld_gridbar].draggable = true;
    gui.objects[scn_selection.sld_gridbar].clickable = true;
	gui.objects[scn_selection.sld_gridbar].hoverable = true;
    gui.objects[scn_selection.sld_gridbar].drag_y = false;
    gui.objects[scn_selection.sld_gridbar].clickhold = true;
    gui.objects[scn_selection.sld_gridbar].draglimit.x1 = gui.objects[scn_selection.sld_gridbar].pos.x1;
    gui.objects[scn_selection.sld_gridbar].draglimit.x2 = gui.objects[scn_selection.btn_scroll_right].pos.x2-32.0;

    // slider back(left corner)
	scn_selection.img_gridbar = guiObjectCreate();
	gui.objects[scn_selection.img_gridbar].pos.x1 = gui.objects[scn_selection.sld_gridbar].pos.x1;
	gui.objects[scn_selection.img_gridbar].pos.y1 = gui.objects[scn_selection.sld_gridbar].pos.y1 + 4.0;
	gui.objects[scn_selection.img_gridbar].pos.x2 = gui.objects[scn_selection.img_gridbar].pos.x1 + 255.0;
	gui.objects[scn_selection.img_gridbar].pos.y2 = gui.objects[scn_selection.img_gridbar].pos.y1 + 16.0;
    gui.objects[scn_selection.img_gridbar].text_font = "PANELFONT";
	gui.objects[scn_selection.img_gridbar].text = "\c[Cyan]T";
    gui.objects[scn_selection.img_gridbar].textalign.x = GUI_XALIGN_LEFT;
    gui.objects[scn_selection.img_gridbar].textalign.y = GUI_YALIGN_TOP;
	gui.objects[scn_selection.img_gridbar].render_text = true;

    // slider back(middle)
	for(fixed x = 0.0; x < scn_selection.tilecount_x_pixels-255.0; x+=255.0)
	{
		int sld_gridbar_back = guiObjectCreate();
		gui.objects[sld_gridbar_back].pos.x1 = gui.objects[scn_selection.sld_gridbar].pos.x1 + x;
		gui.objects[sld_gridbar_back].pos.y1 = gui.objects[scn_selection.sld_gridbar].pos.y1 + 4.0;
		gui.objects[sld_gridbar_back].pos.x2 = gui.objects[sld_gridbar_back].pos.x1;
		gui.objects[sld_gridbar_back].pos.y2 = gui.objects[sld_gridbar_back].pos.y1;
		gui.objects[sld_gridbar_back].text_font = "PANELFONT";
		gui.objects[sld_gridbar_back].text = "\c[Cyan]U";
		gui.objects[sld_gridbar_back].textalign.x = GUI_XALIGN_LEFT;
		gui.objects[sld_gridbar_back].textalign.y = GUI_YALIGN_TOP;
		gui.objects[sld_gridbar_back].render_text = true;
	}

    // slider back(right corner)
	scn_selection.img_gridbar = guiObjectCreate();
	gui.objects[scn_selection.img_gridbar].pos.x1 = gui.objects[scn_selection.btn_scroll_right].pos.x1-4.0;
	gui.objects[scn_selection.img_gridbar].pos.y1 = gui.objects[scn_selection.sld_gridbar].pos.y1 + 4.0;
	gui.objects[scn_selection.img_gridbar].pos.x2 = gui.objects[scn_selection.img_gridbar].pos.x1 + 255.0;
	gui.objects[scn_selection.img_gridbar].pos.y2 = gui.objects[scn_selection.img_gridbar].pos.y1 + 16.0;
    gui.objects[scn_selection.img_gridbar].text_font = "PANELFONT";
	gui.objects[scn_selection.img_gridbar].text = "\c[Cyan]V";
    gui.objects[scn_selection.img_gridbar].textalign.x = GUI_XALIGN_LEFT;
    gui.objects[scn_selection.img_gridbar].textalign.y = GUI_YALIGN_TOP;
	gui.objects[scn_selection.img_gridbar].render_text = true;

	// page numbers
	scn_selection.page_count = fixed(int(mapset_count / scn_selection.tilecount.x))-1.0;
	for(fixed s = 0.0; s <= scn_selection.page_count; s += 1.0)
	{
		fixed x = fixed(int(normalize(s/scn_selection.page_count, gui.objects[scn_selection.btn_scroll_left].pos.x2+10.0, gui.objects[scn_selection.btn_scroll_right].pos.x1-8.0)));
		int page = guiObjectCreate();
		gui.objects[page].pos.x1 = x;
		gui.objects[page].pos.y1 = gui.objects[scn_selection.img_gridbar].pos.y1+25.0;
		gui.objects[page].pos.x2 = gui.objects[page].pos.x1;
		gui.objects[page].pos.y2 = gui.objects[page].pos.y1;
		gui.objects[page].text_font = "SONICFONT";
		gui.objects[page].text = "\c[Cyan]" + str(s);
		gui.objects[page].render_text = true;
		gui.objects[page].clickable = true;
		gui.objects[page].hoverable = true;
	}
}

script "Scene_Selection_Run" (void) clientside
{
	if(!clientCheck()) { terminate; }
	guiBuildSelectionscene();
	guiMove(gui.w, 0.0);
	scn_selection.movein = true;
	while(1)
	{
		// move into position
		if(scn_selection.movein)
		{
			guiMove(-250.0, 0.0);
			if(gui.objects[scn_selection.lbl_title].pos.x1 <= gui.w_half)
			{
				fixed d = gui.w_half - gui.objects[scn_selection.lbl_title].pos.x1;
				guiMove(d, 0.0);
				scn_selection.movein = false;
			}
		}

		// logic to snap slider to page numbers
		if(cursor.dragging == scn_selection.sld_gridbar)
		{
			fixed d = (gui.objects[scn_selection.btn_scroll_left].pos.x2+10.0)-(gui.objects[scn_selection.btn_scroll_right].pos.x1-8.0);
			fixed dw = fixed(int(d/scn_selection.page_count));
			print(f:dw);
			gui.objects[scn_selection.sld_gridbar].pos.x1 = fixed(int(cursor.pos.x/dw));
			gui.objects[scn_selection.sld_gridbar].pos.x2 = gui.objects[scn_selection.sld_gridbar].pos.x1 + 16.0;
		}
		delay(1);
	}
}








