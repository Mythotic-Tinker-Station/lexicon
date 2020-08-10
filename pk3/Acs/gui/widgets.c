
strict namespace Widgets
{
	enum : int
	{
		// Hud alignment
		MAX_WIDGETS 		= 256,						// Max number of widgets
		MAX_HOOKS			= 6,						// Max number of hooks
		MAX_CUSTOMS			= 32,						// Max number of custom variables
	};

	// base widget
	struct objT
	{
		// properties
		struct vec2x2T pos;								// x1, y1, x2, y2 positions of widget
		struct vec2x2T pos_prev;						// x1, y1, x2, y2 positions of widget on the previous frame
		struct sizeT size;								// w, h, wh, hh sizes of widget
		struct vec2T center;							// x, y of the center of the widget

		// flags
		bool alive;										// is this widget alive?(false marks this to be overwritten by a new widget)
		bool visible;									// render this widget?
		bool enabled;									// can the user intereact with this widget?
		bool click_repeat;								// does this widget call it's clicked function every frame?
		bool hover_repeat;								// does this widget call it's hovered function every frame?
		bool clickable;									// is this widget clickable?
		bool hoverable;									// is this widget hoverable?

		// internal vars
		bool hovered;									// true when the mouse is hovering over this widget
		bool clicked;									// true when the mouse is clicking this widget
		int event_update_count;							// number of update hooks
		int event_clicked_count;						// number of clicked hooks
		int event_hovered_count;						// number of hovered hooks
		int event_moved_count;							// number of moved hooks

		// callback events
		void function(int)? event_update[MAX_HOOKS];	// callback function for every update
		void function(int)? event_clicked[MAX_HOOKS];	// callback function when this widget is clicked
		void function(int)? event_hovered[MAX_HOOKS];	// callback function when this widget is hovered
		void function(int)? event_moved[MAX_HOOKS];		// callback function when this widget position or size changes

		// custom variables used by widget definitions
		fixed customFixed[MAX_CUSTOMS];					// custom fixed vars for widgets to use
		int customInt[MAX_CUSTOMS];						// custom int vars for widgets to use
		bool customBool[MAX_CUSTOMS];					// custom bool vars for widgets to use
		str customString[MAX_CUSTOMS];					// custom string vars for widgets to use

	};
	struct objT obj[MAX_WIDGETS];				// list of all the widgets

	// create a basic widget
	function int Create()
	{
		// find a slot to put widget in
		int id = FindFreeSlot();

		// max number of widgets reached
		if(id == -1) { Log(s:"GUI Error: Could not create widget, max number of widgets reached."); return -1; }

		// set widget's default values
		// the system never actually deletes a widget in the pool
		// it simply marks it's slot to be overwriten when the alive property is false
		obj[id].pos.x1 			= 0.0;
		obj[id].pos.y1 			= 0.0;
		obj[id].pos.x2 			= 10.0;
		obj[id].pos.y2 			= 10.0;
		obj[id].pos_prev.x1 	= 0.0;
		obj[id].pos_prev.y1 	= 0.0;
		obj[id].pos_prev.x2 	= 10.0;
		obj[id].pos_prev.y2 	= 10.0;
		obj[id].size.w 			= obj[id].pos.x2-obj[id].pos.x1;
		obj[id].size.h 			= obj[id].pos.y2-obj[id].pos.y1;
		obj[id].size.wh 		= obj[id].size.w/2.0;
		obj[id].size.hh 		= obj[id].size.h/2.0;
		obj[id].center.x 		= obj[id].pos.x1+obj[id].size.wh;
		obj[id].center.y 		= obj[id].pos.y1+obj[id].size.hh;
		obj[id].alive 			= true;
		obj[id].visible 		= true;
		obj[id].enabled 		= true;
		obj[id].click_repeat 	= false;
		obj[id].hover_repeat 	= false;
		obj[id].clickable		= false;
		obj[id].hoverable 		= false;
		obj[id].hovered			= false;
		obj[id].clicked			= false;

		// default all custom vars
		for(int i = 0; i < MAX_CUSTOMS; i++)
		{
			obj[id].customFixed[i] = 0.0;
			obj[id].customInt[i] = 0;
			obj[id].customBool[i] = false;
			obj[id].customString[i] = "";
		}

		// null the hooks
		for(int i = 0; i < MAX_HOOKS; i++)
		{
			obj[id].event_update[i]	= nullFunc;
			obj[id].event_clicked[i] = nullFunc;
			obj[id].event_hovered[i] = nullFunc;
			obj[id].event_moved[i] = nullFunc;
		}

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

	// hook a function to the update event
	function void AddUpdateHook(int id, void function(int)? func)
	{
		obj[id].event_update[obj[id].event_update_count] = func;
		obj[id].event_update_count++;
	}

	// hook a function to the clicked event
	function void AddClickedHook(int id, void function(int)? func)
	{
		obj[id].event_clicked[obj[id].event_clicked_count] = func;
		obj[id].event_clicked_count++;
	}

	// hook a function to the hovered event
	function void AddHoveredHook(int id, void function(int)? func)
	{
		obj[id].event_hovered[obj[id].event_hovered_count] = func;
		obj[id].event_hovered_count++;
	}

	// hook a function to the hovered event
	function void AddMovedHook(int id, void function(int)? func)
	{
		obj[id].event_moved[obj[id].event_moved_count] = func;
		obj[id].event_moved_count++;
	}

	// call all update hooks
	function void CallUpdateHooks(int id)
	{
		for(int i = 0; i < MAX_HOOKS; i++)
		{
			if(obj[id].event_update[i] != nullFunc)
			{
				obj[id].event_update[i](id);
			}
		}
	}

	// call all hovered hooks
	function void CallHoveredHooks(int id)
	{
		for(int i = 0; i < MAX_HOOKS; i++)
		{
			if(obj[id].event_hovered[i] != nullFunc)
			{
				obj[id].event_hovered[i](id);
			}
		}
	}

	// call all clicked hooks
	function void CallClickedHooks(int id)
	{
		for(int i = 0; i < MAX_HOOKS; i++)
		{
			if(obj[id].event_clicked[i] != nullFunc)
			{
				obj[id].event_clicked[i](id);
			}
		}
	}

	// call all clicked hooks
	function void CallMovedHooks(int id)
	{
		for(int i = 0; i < MAX_HOOKS; i++)
		{
			if(obj[id].event_moved[i] != nullFunc)
			{
				obj[id].event_moved[i](id);
			}
		}
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
					// is cursor within bounds?
					if(cursor.pos.x > obj[id].pos.x1 && cursor.pos.x < obj[id].pos.x2 && cursor.pos.y > obj[id].pos.y1 && cursor.pos.y < obj[id].pos.y2)
					{
						// is this object hoverable?
						if(obj[id].hoverable)
						{
							// is the widget set to call it's hovered function every frame?
							if(obj[id].hover_repeat)
							{
								CallHoveredHooks(id);
							}
							// only call the clicked function once
							else
							{
								if(!obj[id].hovered)
								{
									CallHoveredHooks(id);
									obj[id].hovered = true;
								}
							}
						}

						// is this object clickable?
						if(obj[id].clickable)
						{
							// is the user clicking the mouse?
							if(cursor.clicked)
							{
								// set object's clicked bool
								obj[id].clicked = true;

								// is the widget set to call it's clicked function every frame as the user holds the mouse?
								if(obj[id].click_repeat)
								{
									// call object's clicked callback
									CallClickedHooks(id);
								}
								// only call the clicked function once
								else
								{
									// was the cursor clicked on the previous frame?
									if(!cursor.clicked_prev)
									{
										// call object's clicked callback
										CallClickedHooks(id);
									}
								}
							}
							// user is no longer clicking
							else
							{
								// unset object's clicked bool
								obj[id].clicked = false;
							}
						}
					}
					// cursor is not within bounds
					else
					{
						obj[id].hovered = false;
						obj[id].clicked = false;
					}

					// has the widget moved or changed size?
					if(obj[id].pos_prev.x1 != obj[id].pos.x1 || obj[id].pos_prev.y1 != obj[id].pos.y1 || obj[id].pos_prev.x2 != obj[id].pos.x2 || obj[id].pos_prev.y2 != obj[id].pos.y2)
					{
						// call object's moved callback
						CallMovedHooks(id);
					}
				}
				// call object's update callback
				CallUpdateHooks(id);

				obj[id].pos_prev.x1 = obj[id].pos.x1;
				obj[id].pos_prev.y1 = obj[id].pos.y1;
				obj[id].pos_prev.x2 = obj[id].pos.x2;
				obj[id].pos_prev.y2 = obj[id].pos.y2;
			}
		}
	}
}