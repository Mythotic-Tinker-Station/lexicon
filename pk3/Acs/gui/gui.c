

strict namespace Gui
{
	#define GUI_MAX_WIDGETS					256	// Max Objects

	struct widgetT widgets[GUI_MAX_WIDGETS];	// list of all the gui objects

	// base widget
	struct widgetT
	{
		// properties
		struct vec2x2T pos;						// x1, y1, x2, y2 positions of widget
		struct vec2x2T pos_prev;				// x1, y1, x2, y2 positions of widget on the previous frame
		struct sizeT size;						// w, h, wh, hh sizes of widget
		struct vec2T center;					// x, y of the center of the widget

		// flags
		bool alive;								// is this widget alive?(false marks this to be overwritten by a new widget)
		bool visible;							// render this widget?
		bool enabled;							// can the user intereact with this widget?
		bool click_repeat;						// does this widget call it's clicked function every frame?
		bool hover_repeat;						// does this widget call it's hovered function every frame?
		bool clickable;							// is this widget clickable?
		bool hoverable;							// is this widget hoverable?

		// internal vars
		bool hovered;

		// callback events
		void function(int)? func_update;		// callback function for every update
		void function(int)? func_clicked;		// callback function when this widget is clicked
		void function(int)? func_hovered;		// callback function when this widget is hovered
		void function(int)? func_moved;			// callback function when this widget position or size changes

		int images[32];							// images to display

	};

	////////////////////////////////////////////////////////
	// gui functions
	////////////////////////////////////////////////////////

	// enable entire widget pool
	function void Enable()
	{
		for(int id = 0; id < GUI_MAX_WIDGETS; id++)
		{
			widgets[id].enabled = true;
		}
	}

	// disable entire widget pool
	function void Disable()
	{
		for(int id = 0; id < GUI_MAX_WIDGETS; id++)
		{
			widgets[id].enabled = false;
		}
	}

	// hide entire widget pool
	function void Hide()
	{
		for(int id = 0; id < GUI_MAX_WIDGETS; id++)
		{
			widgets[id].visible = true;
		}
	}

	// show entire widget pool
	function void Show()
	{
		for(int id = 0; id < GUI_MAX_WIDGETS; id++)
		{
			widgets[id].visible = false;
		}
	}

	// clean out entire widget pool
	function void Clear()
	{
		// mark all slots as free
		for(int id = 0; id < GUI_MAX_WIDGETS; id++)
		{
			widgets[id].alive = false;
		}
		Screen.Clear();
	}

	// move entire widget pool
	function int Move(fixed x, fixed y)
	{
		fixed x1h;
		fixed x2h;
		fixed y1h;
		fixed y2h;
		for(int id = 0; id < GUI_MAX_WIDGETS; id++)
		{
			if(widgets[id].alive)
			{
				widgets[id].pos.x1 += x;
				widgets[id].pos.x2 += x;
				widgets[id].pos.y1 += y;
				widgets[id].pos.y2 += y;

				if(widgets[id].pos.x1 > x1h) { x1h = widgets[id].pos.x1; }
				if(widgets[id].pos.x2 > x2h) { x2h = widgets[id].pos.x2; }
				if(widgets[id].pos.y1 > y1h) { y1h = widgets[id].pos.y1; }
				if(widgets[id].pos.y2 > y2h) { y2h = widgets[id].pos.y2; }
			}
		}
		if(x1h >= Screen.size.w) { return 1; }
		if(x2h <= 0.0) { return 2; }
		if(y1h >= Screen.size.w) { return 3; }
		if(y2h <= 0.0) { return 4; }
		return 0;
	}

	////////////////////////////////////////////////////////
	// widget functions
	////////////////////////////////////////////////////////

	// create a basic widget
	function int WidgetCreate()
	{
		int id = WidgetFindFreeSlot();
		if(id == -1) { Log(s:"GUI Error: Could not create widget, max number of widgets reached."); return -1; }
		widgets[id].pos.x1 			= 0.0;
		widgets[id].pos.y1 			= 0.0;
		widgets[id].pos.x2 			= 10.0;
		widgets[id].pos.y2 			= 10.0;
		widgets[id].size.w 			= 10.0;
		widgets[id].size.h 			= 10.0;
		widgets[id].size.wh 		= 5.0;
		widgets[id].size.hh 		= 5.0;
		widgets[id].alive 			= true;
		widgets[id].visible 		= true;
		widgets[id].enabled 		= true;
		widgets[id].click_repeat 	= false;
		widgets[id].hover_repeat 	= false;
		widgets[id].clickable		= false;
		widgets[id].hoverable 		= false;
		widgets[id].func_update		= nullFunc;
		widgets[id].func_clicked	= nullFunc;
		widgets[id].func_hovered	= nullFunc;
		widgets[id].func_moved		= nullFunc;
		widgets[id].hovered			= false;
		return id;
	}

	// delete an object by id
	function void WidgetDelete(int id)
	{
		widgets[id].alive = false;
	}

	// find an unused slot
	function int WidgetFindFreeSlot()
	{
		for(int id = 0; id < GUI_MAX_WIDGETS; id++)
		{
			if(!widgets[id].alive) { return id; }
		}
		return -1;
	}

	// find an unused slot
	function void WidgetRun()
	{
		for(int id = 0; id < GUI_MAX_WIDGETS; id++)
		{
			WidgetUpdate(id);
		}
	}

	// widget functionalities
	function void WidgetUpdate(int id)
	{
		// is the widget not marked for being overwritten?
		if(widgets[id].alive)
		{
			// is the widget visible?
			if(widgets[id].visible)
			{
				// keep track of width/heights (read only)
				widgets[id].size.w = widgets[id].pos.x2-widgets[id].pos.x1;
				widgets[id].size.h = widgets[id].pos.y2-widgets[id].pos.y1;
				widgets[id].size.wh = widgets[id].size.w/2.0;
				widgets[id].size.hh = widgets[id].size.h/2.0;
				widgets[id].center.x = widgets[id].pos.x1+widgets[id].size.wh;
				widgets[id].center.y = widgets[id].pos.y1+widgets[id].size.hh;

				// is the user able to interact with this widget?
				if(widgets[id].enabled)
				{
					// is cursor is within bounds?
					if(cursor.pos.x > widgets[id].pos.x1 && cursor.pos.x < widgets[id].pos.x2 && cursor.pos.y > widgets[id].pos.y1 && cursor.pos.y < widgets[id].pos.y2)
					{
						// is this object clickable?
						if(widgets[id].clickable)
						{
							// is the user clicking the mouse?
							if(cursor.clicked)
							{
								// is the widget set to call it's clicked function every frame as the user holds the mouse?
								if(widgets[id].click_repeat)
								{
									widgets[id].clicked(id);
								}
								// only call the clicked function once
								else
								{
									if(!cursor.clicked_prev)
									{
										widgets[id].clicked(id);
									}
								}
							}
						}

						// is this object hoverable?
						if(widgets[id].hoverable)
						{
							// is the widget set to call it's hovered function every frame?
							if(widgets[id].hover_repeat)
							{
								widgets[id].hovered(id);
							}
							// only call the clicked function once
							else
							{
								if(!widgets[id].hovered)
								{
									widgets[id].hovered(id);
									widgets[id].hovered = true;
								}
							}
						}
					}
					// cursor is not within bounds
					else
					{
						widgets[id].hovered = false;
					}

					// has the widget moved or changed size?
					if(widgets[id].pos_prev.x1 != widgets[id].pos.x1 || widgets[id].pos_prev.y1 != widgets[id].pos.y1 || widgets[id].pos_prev.x2 != widgets[id].pos.x2 || widgets[id].pos_prev.y2 != widgets[id].pos.y2)
					{
						widgets[id].moved(id);
					}

				}
				widgets[id].update(id);

				widgets[id].pos_prev.x1 = widgets[id].pos.x1;
				widgets[id].pos_prev.y1 = widgets[id].pos.y1;
				widgets[id].pos_prev.x2 = widgets[id].pos.x2;
				widgets[id].pos_prev.y2 = widgets[id].pos.y2;
			}
		}
	}

	////////////////////////////////////////////////////////
	// Scripts
	////////////////////////////////////////////////////////
	script "CL_GUI" enter clientside
	{

		// check if we are on the hub map
		if(GetLevelInfo(LEVELINFO_LEVELNUM) != 99) { terminate; }

		// check if we are the local client
		if(!clientCheck()) { terminate; }

		// setup the Screen
		Screen.Init();

		button.Create(100.0, 100.0, 600.0, 150.0);

		while(1)
		{
			Cursor.Run();
			WidgetRun();
			Screen.ResetHudIDs();
			delay(1);
		}
	/*
		// setup gui
		guiInit();

		int state = 0;

		while(1)
		{
			// run cursor
			guiCursorRun();

			// run all gui objects
			guiWidgetsRun();


			// scene switch
			if(gui.scene != gui.scene_prev)
			{
				switch(gui.scene)
				{
					case SCENE_FIRST_TIME:
						ACS_NamedExecute("Scene_FirstTime_Run", 0);
						break;

					case SCENE_SELECTION:
						ACS_NamedExecute("Scene_Selection_Run", 0);
						break;
				}
			}

			// reset hud ID counter
			gui.nextid = 0;
			gui.objcount = 0;
			delay(1);
			cursor.clicked_prev = cursor.clicked;

			// if the resolution changes, terminate scenes and restart
			if(GetCVar("vid_defwidth") != gui.vid_w || GetCVar("vid_defheight") != gui.vid_h)
			{
				ACS_NamedTerminate("Scene_FirstTime_Run", 0);
				ACS_NamedTerminate("Scene_Selection_Run", 0);
				restart;
			}
		}
		*/
	}
}