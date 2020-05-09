struct _scn_selection
{
    int lbl_title;
	int pic_preview;
	int lbl_test;
	int lbl_test2;
	bool movein;
};

struct _scn_selection scn_selection;


// build the list of rules that the server has enabled
function void guiBuildSelectionScene(void)
{
	scn_selection.lbl_title = guiObjectCreate();
	gui.objects[scn_selection.lbl_title].pos.x1 = gui.w_half;
	gui.objects[scn_selection.lbl_title].pos.y1 = gui.h_half - 360.0;
	gui.objects[scn_selection.lbl_title].pos.x2 = gui.objects[scn_selection.lbl_title].pos.x1;
	gui.objects[scn_selection.lbl_title].pos.y2 = gui.objects[scn_selection.lbl_title].pos.y1;
    gui.objects[scn_selection.lbl_title].text_font = "SONICFONTHD";
	gui.objects[scn_selection.lbl_title].text = "Select Mapset";
	gui.objects[scn_selection.lbl_title].render_text = true;

	guiBuildTiles();
/*
	scn_selection.pic_preview = guiObjectCreate();
	gui.objects[scn_selection.pic_preview].pos.x1 = gui.w_half - 470.0;
	gui.objects[scn_selection.pic_preview].pos.y1 = gui.h_half + 256.0;
	gui.objects[scn_selection.pic_preview].pos.x2 = gui.objects[scn_selection.pic_preview].pos.x1;
	gui.objects[scn_selection.pic_preview].pos.y2 = gui.objects[scn_selection.pic_preview].pos.y1;
    gui.objects[scn_selection.pic_preview].text_font = "PANELFONT";
	gui.objects[scn_selection.pic_preview].text = "Q";
	gui.objects[scn_selection.pic_preview].render_text = true;
*/

}

function void guiBuildTiles(void)
{
	fixed tile_w = 128.0;
	fixed tile_h = 96.0;

	fixed gapsize = 6.0;

	fixed totalsize_w = tile_w+gapsize;
	fixed totalsize_h = tile_h+gapsize;

	int tilecount_x = int(gui.w/totalsize_w);
	int tilecount_y = int(gui.h/totalsize_h)-4;

	fixed grid_x = gui.w_half - 500.0;
	fixed grid_y = gui.h_half - ((totalsize_h*fixed(tilecount_y))/2.0);

	for(int y = 0; y < tilecount_y; y++)
	{
		for(int x = 0; x < 2; x++)
		{
			int tile = guiObjectCreate();
			gui.objects[tile].pos.x1 = (grid_x) + (fixed(x)*totalsize_w);
			gui.objects[tile].pos.y1 = (grid_y) + (fixed(y)*totalsize_h);
			gui.objects[tile].pos.x2 = gui.objects[tile].pos.x1 + tile_w;
			gui.objects[tile].pos.y2 = gui.objects[tile].pos.y1 + tile_h;
			gui.objects[tile].text_font = "SCRN0000";
			gui.objects[tile].text = "a";
			gui.objects[tile].text_font_hovered = "SCRN0000";
			gui.objects[tile].text_hovered = "a";
			gui.objects[tile].render_text = true;
			gui.objects[tile].hoverable = true;
		}
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
		delay(1);
	}
}

