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
	gui.objects[scn_selection.lbl_title].pos.y1 = 50.0;
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
	fixed image_w = 128.0;	// image width
	fixed image_h = 96.0;	// image height

	fixed gapsize = 6.0;	// gap size between each tile

	fixed tilecount_x = gui.w/image_w;
	fixed tilecount_y = gui.h/image_h;

	fixed tilecount_x_pixels = tilecount_x*image_w;

	while(tilecount_x_pixels > gui.w-(image_w*3.0))
	{
		tilecount_x--;
		tilecount_x_pixels = tilecount_x*image_w;
	}

	fixed grid_x = gui.w_half - (tilecount_x_pixels/2.0);
	fixed grid_y = 100.0;

	for(fixed x = 0.0; x < tilecount_x; x++)
	{
		for(fixed y = 0.0; y < 2.0; y++)
		{
			int tile = guiObjectCreate();
			gui.objects[tile].pos.x1 = (grid_x) + (x*image_w);
			gui.objects[tile].pos.y1 = (grid_y) + (y*image_h);
			gui.objects[tile].pos.x2 = gui.objects[tile].pos.x1 + image_w;
			gui.objects[tile].pos.y2 = gui.objects[tile].pos.y1 + image_h;
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

