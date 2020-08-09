
strict namespace Widgets
{
	enum : int
	{
		// Hud alignment
		MAX_WIDGETS 		= 256,				// Max number of widgets
	};

	// base widget
	struct objT
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
	struct objT obj[MAX_WIDGETS];	// list of all the widgets

	// create a basic widget
	function int Create()
	{
		int id = FindFreeSlot();
		if(id == -1) { Log(s:"GUI Error: Could not create widget, max number of widgets reached."); return -1; }
		obj[id].pos.x1 			= 0.0;
		obj[id].pos.y1 			= 0.0;
		obj[id].pos.x2 			= 10.0;
		obj[id].pos.y2 			= 10.0;
		obj[id].size.w 			= 10.0;
		obj[id].size.h 			= 10.0;
		obj[id].size.wh 		= 5.0;
		obj[id].size.hh 		= 5.0;
		obj[id].alive 			= true;
		obj[id].visible 		= true;
		obj[id].enabled 		= true;
		obj[id].click_repeat 	= false;
		obj[id].hover_repeat 	= false;
		obj[id].clickable		= false;
		obj[id].hoverable 		= false;
		obj[id].func_update		= nullFunc;
		obj[id].func_clicked	= nullFunc;
		obj[id].func_hovered	= nullFunc;
		obj[id].func_moved		= nullFunc;
		obj[id].hovered			= false;
		return id;
	}

	// delete an object by id
	function void Delete(int id)
	{
		obj[id].alive = false;
	}

	// find an unused slot
	function int FindFreeSlot()
	{
		for(int id = 0; id < MAX_WIDGETS; id++)
		{
			if(!obj[id].alive) { return id; }
		}
		return -1;
	}

	// find an unused slot
	function void Run()
	{
		for(int id = 0; id < MAX_WIDGETS; id++)
		{
			Update(id);
		}
	}

	// calculate the sizes of a widget
	function void CalcSizes(int id)
	{
		// keep track of width/heights (read only)
		obj[id].size.w = obj[id].pos.x2-obj[id].pos.x1;
		obj[id].size.h = obj[id].pos.y2-obj[id].pos.y1;
		obj[id].size.wh = obj[id].size.w/2.0;
		obj[id].size.hh = obj[id].size.h/2.0;
		obj[id].center.x = obj[id].pos.x1+obj[id].size.wh;
		obj[id].center.y = obj[id].pos.y1+obj[id].size.hh;
	}

	// widget functionalities
	function void Update(int id)
	{
		// is the widget not marked for being overwritten?
		if(obj[id].alive)
		{
			// is the widget visible?
			if(obj[id].visible)
			{
				// calculate the sizes of a widget
				CalcSizes(id);

				// is the user able to interact with this widget?
				if(obj[id].enabled)
				{
					// is cursor is within bounds?
					if(cursor.pos.x > obj[id].pos.x1 && cursor.pos.x < obj[id].pos.x2 && cursor.pos.y > obj[id].pos.y1 && cursor.pos.y < obj[id].pos.y2)
					{
						// is this object clickable?
						if(obj[id].clickable)
						{
							// is the user clicking the mouse?
							if(cursor.clicked)
							{
								// is the widget set to call it's clicked function every frame as the user holds the mouse?
								if(obj[id].click_repeat)
								{
									obj[id].func_clicked(id);
								}
								// only call the clicked function once
								else
								{
									if(!cursor.clicked_prev)
									{
										obj[id].func_clicked(id);
									}
								}
							}
						}

						// is this object hoverable?
						if(obj[id].hoverable)
						{
							// is the widget set to call it's hovered function every frame?
							if(obj[id].hover_repeat)
							{
								obj[id].func_hovered(id);
							}
							// only call the clicked function once
							else
							{
								if(!obj[id].hovered)
								{
									obj[id].func_hovered(id);
									obj[id].hovered = true;
								}
							}
						}
					}
					// cursor is not within bounds
					else
					{
						obj[id].hovered = false;
					}

					// has the widget moved or changed size?
					if(obj[id].pos_prev.x1 != obj[id].pos.x1 || obj[id].pos_prev.y1 != obj[id].pos.y1 || obj[id].pos_prev.x2 != obj[id].pos.x2 || obj[id].pos_prev.y2 != obj[id].pos.y2)
					{
						obj[id].func_moved(id);
					}

				}
				obj[id].func_update(id);

				obj[id].pos_prev.x1 = obj[id].pos.x1;
				obj[id].pos_prev.y1 = obj[id].pos.y1;
				obj[id].pos_prev.x2 = obj[id].pos.x2;
				obj[id].pos_prev.y2 = obj[id].pos.y2;
			}
		}
	}
}