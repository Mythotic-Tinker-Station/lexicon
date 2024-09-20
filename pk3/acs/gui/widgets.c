/*
	Lexicon UI by Tribeam
	With help from Popsoap, Michaelis

	Widgets Namespace:
		int 	Widgets::Create()														// Create a new default widget; returns an id number of said widget;
		void 	Widgets::Delete(int id)													// Deletes a widget;
		int 	Widgets::FindFreeSlot()													// Finds the next available slot in the widget pool;
		void 	Widgets::Run()															// Run the widgets!;
		void	Widgets::CalcSizes(int id)												// Recalculates the width, height, half width and half height vars;
		void	Widgets::AddUpdateHook(int id, function f)								// Adds a function to the update event;
		void	Widgets::AddHoveredHook(int id, function f)								// Adds a function to the hovered event;
		void	Widgets::AddClickedHook(int id, function f)								// Adds a function to the clicked event;
		void	Widgets::AddMovedHook(int id, function f)								// Adds a function to the moved event;
		void	Widgets::CallUpdateHooks(int id)											// Calls all the functions hooked to the update event;
		void	Widgets::CallHoveredHooks(int id)										// Calls all the functions hooked to the hovered event;
		void	Widgets::CallClickedHooks(int id)										// Calls all the functions hooked to the clicked event;
		void	Widgets::CallMovedHooks(int id)											// Calls all the functions hooked to the moved event;

		fixed	Widgets::GetX1(int id)													// Returns the x1 point of the widget;
		fixed	Widgets::GetY1(int id)													// Returns the x2 point of the widget;
		fixed	Widgets::GetX2(int id)													// Returns the y1 point of the widget;
		fixed	Widgets::GetY2(int id)													// Returns the y2 point of the widget;
		fixed	Widgets::GetCenterX(int id)												// Returns the center x point of the widget;
		fixed	Widgets::GetCenterY(int id)												// Returns the center y point of the widget;

		str		Widgets::GetColorNormal(int id)											// returns the base color of the widget;
		str		Widgets::GetColorHovered(int id)											// returns the hovered color of the widget;
		str		Widgets::GetColorClicked(int id)											// returns the clicked color of the widget;

		str		Widgets::GetText(int id)													// returns the text of the widget;

		fixed	Widgets::GetWidth(int id)												// Returns the width of the widget;
		fixed	Widgets::GetHeight(int id)												// Returns the height of the widget;
		fixed	Widgets::GetWidth_Half(int id)											// Returns the half width of the widget;
		fixed	Widgets::GetHeight_Half(int id)											// Returns the half height of the widget;

		void	Widgets::SetX1(int id, fixed x1)											// Sets the x1 point of the widget;
		void	Widgets::SetY1(int id, fixed y1)											// Sets the x2 point of the widget;
		void	Widgets::SetX2(int id, fixed x2)											// Sets the y1 point of the widget;
		void	Widgets::SetY2(int id, fixed y2)											// Sets the y2 point of the widget;

		void 	Widgets::SetTopLeftPosition(int id, fixed x, fixed y)					// Sets the x, y of the top left position of the widget;
		void 	Widgets::SetBottomRightPosition(int id, fixed x, fixed y)				// Sets the x, y of the bottom right position of the widget;
		void 	Widgets::SetPosition(int id, fixed x1, fixed y1, fixed x2, fixed y2)		// Sets the x1, y1, x2, y2 positions of the widget;
		void 	Widgets::SetRectPosition(int id, fixed x1, fixed y1, fixed w, fixed h)	// Sets the x1, y1, x2, y2 positions of the widget with a width/height;

		void	Widgets::SetColorNormal(int id)											// Sets the base color of the widget;
		void	Widgets::SetColorHovered(int id)											// Sets the hovered color of the widget;
		void	Widgets::SetColorClicked(int id)											// Sets the clicked color of the widget;

		void	Widgets::SetText(int id, str value)										// Sets the text of the widget;



		void	Widgets::Update(int id)													// Updates the widget;
*/



strict namespace Widgets
{
	enum : int
	{
		// Hud alignment
		MAX_WIDGETS 		= 2048,						// Max number of widgets
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
		struct colorsT backcolor;						// background colors
		struct colorsT textcolor;						// text colors
		struct vec2T text_offset;						// offset the position of the text

		str text;										// text to display
		str image;										// image to display
		int font;										// font of the text to display

		// flags
		bool alive;										// is this widget alive?(false marks this to be overwritten by a new widget)
		bool visible;									// render this widget?
		bool enabled;									// can the user intereact with this widget?
		bool click_repeat;								// does this widget call it's clicked function every frame?
		bool hover_repeat;								// does this widget call it's hovered function every frame?
		bool clickable;									// is this widget clickable?
		bool hoverable;									// is this widget hoverable?
		bool checkable;									// is this widget checkable?
		bool render_text;								// should this widget render text?
		bool render_image;								// should this widget render an image?
        bool render_back;                               // should this widget render its background?

		// internal vars
        int panelsize;                                  // size of the images to use for the background
		bool hovered;									// true when the mouse is hovering over this widget
		bool clicked;									// true when the mouse is clicking this widget
		bool checked;									// true when the widget is checked(this only works if click_repeat is false)
		int event_update_count;							// number of update hooks
		int event_clicked_count;						// number of clicked hooks
		int event_hovered_count;						// number of hovered hooks
		int event_moved_count;							// number of moved hooks

		// callback events
		void function(int)? event_update[MAX_HOOKS];	// callback function for every update
		void function(int)? event_clicked[MAX_HOOKS];	// callback function when this widget is clicked
		void function(int)? event_hovered[MAX_HOOKS];	// callback function when this widget is hovered
		void function(int)? event_moved[MAX_HOOKS];		// callback function when this widget position or size changes

		// custom vars
		int arg1int;
		int arg2int;
		int arg3int;
		int arg4int;
		int arg5int;

		str arg1str;
		str arg2str;
		str arg3str;
		str arg4str;
		str arg5str;

	};
	struct objT obj[MAX_WIDGETS];						// list of all the widgets

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

		// properties
		obj[id].pos.x1 				= 0.0;
		obj[id].pos.y1 				= 0.0;
		obj[id].pos.x2 				= 10.0;
		obj[id].pos.y2 				= 10.0;
		obj[id].pos_prev.x1 		= 0.0;
		obj[id].pos_prev.y1 		= 0.0;
		obj[id].pos_prev.x2 		= 10.0;
		obj[id].pos_prev.y2 		= 10.0;
		obj[id].size.w 				= obj[id].pos.x2-obj[id].pos.x1;
		obj[id].size.h 				= obj[id].pos.y2-obj[id].pos.y1;
		obj[id].size.wh 			= fixed(int(obj[id].size.w/2.0));
		obj[id].size.hh 			= fixed(int(obj[id].size.h/2.0));
		obj[id].center.x 			= obj[id].pos.x1+obj[id].size.wh;
		obj[id].center.y 			= obj[id].pos.y1+obj[id].size.hh;
		obj[id].text_offset.x		= 0.0;
		obj[id].text_offset.y		= 0.0;
		obj[id].backcolor.normal 	= "UI_Main_Normal";
		obj[id].backcolor.disabled 	= "UI_Main_Clicked";
		obj[id].backcolor.clicked	= "UI_Main_Clicked";
		obj[id].backcolor.hovered	= "UI_Main_Hovered";
		obj[id].backcolor.checked	= "UI_Main_Checked";
		obj[id].backcolor.current	= "UI_Main_Normal";
		obj[id].textcolor.normal 	= "White";
		obj[id].textcolor.disabled 	= "White";
		obj[id].textcolor.clicked	= "White";
		obj[id].textcolor.hovered	= "White";
		obj[id].textcolor.checked	= "Blue";
		obj[id].textcolor.current	= "Gray";
		obj[id].text				= "";
		obj[id].image				= "a";
		obj[id].font				= Font::font_fancysmall;
        obj[id].panelsize           = 16;

		obj[id].arg1int 			= 0;
		obj[id].arg2int 			= 0;
		obj[id].arg3int 			= 0;
		obj[id].arg4int 			= 0;
		obj[id].arg5int 			= 0;

		obj[id].arg1str 			= "";
		obj[id].arg2str 			= "";
		obj[id].arg3str 			= "";
		obj[id].arg4str 			= "";
		obj[id].arg5str 			= "";

		// flags
		obj[id].alive 			= true;
		obj[id].visible 		= true;
		obj[id].enabled 		= true;
		obj[id].click_repeat 	= false;
		obj[id].hover_repeat 	= false;
		obj[id].clickable		= false;
		obj[id].hoverable 		= false;
		obj[id].checkable 		= false;
		obj[id].hovered			= false;
		obj[id].clicked			= false;
		obj[id].checked			= false;
		obj[id].render_text		= false;
		obj[id].render_image	= false;
        obj[id].render_back 	= false;

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
		obj[id].size.wh = fixed(int(obj[id].size.w/2.0));
		obj[id].size.hh = fixed(int(obj[id].size.h/2.0));
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

	// hook a function to the moved event
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

	// get specific positions
	function fixed GetX1(int id) 				{ return obj[id].pos.x1; }
	function fixed GetY1(int id) 				{ return obj[id].pos.y1; }
	function fixed GetX2(int id) 				{ return obj[id].pos.x2; }
	function fixed GetY2(int id) 				{ return obj[id].pos.y2; }
	function fixed GetPrevX1(int id) 			{ return obj[id].pos_prev.x1; }
	function fixed GetPrevY1(int id) 			{ return obj[id].pos_prev.y1; }
	function fixed GetPrevX2(int id) 			{ return obj[id].pos_prev.x2; }
	function fixed GetPrevY2(int id) 			{ return obj[id].pos_prev.y2; }
	function fixed GetCenterX(int id) 			{ return obj[id].center.x; }
	function fixed GetCenterY(int id) 			{ return obj[id].center.y; }
	function fixed GetWidth(int id) 			{ return obj[id].size.w; }
	function fixed GetHeight(int id) 			{ return obj[id].size.h; }
	function fixed GetWidth_Half(int id) 		{ return obj[id].size.wh; }
	function fixed GetHeight_Half(int id) 		{ return obj[id].size.hh; }

	function fixed GetTextOffsetX(int id) 		{ return obj[id].text_offset.x; }
	function fixed GetTextOffsetY(int id) 		{ return obj[id].text_offset.y; }

	// colors
	function str GetBackColorNormal(int id) 	{ return obj[id].backcolor.normal; }
	function str GetBackColorHovered(int id) 	{ return obj[id].backcolor.hovered; }
	function str GetBackColorClicked(int id) 	{ return obj[id].backcolor.clicked; }
	function str GetBackColorCurrent(int id) 	{ return obj[id].backcolor.current; }

	function str GetTextColorNormal(int id) 	{ return obj[id].textcolor.normal; }
	function str GetTextColorHovered(int id) 	{ return obj[id].textcolor.hovered; }
	function str GetTextColorClicked(int id) 	{ return obj[id].textcolor.clicked; }
	function str GetTextColorCurrent(int id) 	{ return obj[id].textcolor.current; }


	// text and image
	function str GetText(int id) 				{ return obj[id].text; }
	function str GetImage(int id) 				{ return obj[id].image; }
	function int GetFont(int id) 				{ return obj[id].font; }

	// flags
	function bool GetAlive(int id) 				{ return obj[id].alive; }
	function bool GetVisible(int id) 			{ return obj[id].visible; }
	function bool GetEnabled(int id) 			{ return obj[id].enabled; }
	function bool GetHoverRepeat(int id) 		{ return obj[id].hover_repeat; }
	function bool GetClickRepeat(int id) 		{ return obj[id].click_repeat; }
	function bool GetHoverable(int id) 			{ return obj[id].hoverable; }
	function bool GetClickable(int id) 			{ return obj[id].clickable; }
	function bool GetCheckable(int id) 			{ return obj[id].checkable; }
	function bool GetRenderText(int id) 		{ return obj[id].render_text; }
	function bool GetRenderImage(int id) 		{ return obj[id].render_image; }
    function bool GetRenderBack(int id) 		{ return obj[id].render_back; }

	// event properties
	function bool GetHovered(int id) 			{ return obj[id].hovered; }
	function bool GetClicked(int id) 			{ return obj[id].clicked; }
	function bool GetChecked(int id) 			{ return obj[id].checked; }

	// other bits of information
	function int GetArg1Int(int id) 			{ return obj[id].arg1int; }
	function int GetArg2Int(int id) 			{ return obj[id].arg2int; }
	function int GetArg3Int(int id) 			{ return obj[id].arg3int; }
	function int GetArg4Int(int id) 			{ return obj[id].arg4int; }
	function int GetArg5Int(int id) 			{ return obj[id].arg5int; }

	function str GetArg1Str(int id) 			{ return obj[id].arg1str; }
	function str GetArg2Str(int id) 			{ return obj[id].arg2str; }
	function str GetArg3Str(int id) 			{ return obj[id].arg3str; }
	function str GetArg4Str(int id) 			{ return obj[id].arg4str; }
	function str GetArg5Str(int id) 			{ return obj[id].arg5str; }

	// get x1 point
	function void SetX1(int id, fixed x1)
	{
		obj[id].pos.x1 = x1;
		CalcSizes(id);
	}

	// get y1 point
	function void SetY1(int id, fixed y1)
	{
		obj[id].pos.y1 = y1;
		CalcSizes(id);
	}

	// get x2 point
	function void SetX2(int id, fixed x2)
	{
		obj[id].pos.x2 = x2;
		CalcSizes(id);
	}

	// get y2 point
	function void SetY2(int id, fixed y2)
	{
		obj[id].pos.y2 = y2;
		CalcSizes(id);
	}

	// get previous x1 point
	function void SetPrevX1(int id, fixed x1)
	{
		obj[id].pos_prev.x1 = x1;
	}

	// get previous y1 point
	function void SetPrevY1(int id, fixed y1)
	{
		obj[id].pos_prev.y1 = y1;
	}

	// get previous x2 point
	function void SetPrevX2(int id, fixed x2)
	{
		obj[id].pos_prev.x2 = x2;
	}

	// get previous y2 point
	function void SetPrevY2(int id, fixed y2)
	{
		obj[id].pos_prev.y2 = y2;
	}

	// set the x,y of the top left position
	function void SetTopLeftPosition(int id, fixed x, fixed y)
	{
		obj[id].pos.x1 = x;
		obj[id].pos.y1 = y;
		CalcSizes(id);
	}

	// set the x,y of the bottom right position
	function void SetBottomRightPosition(int id, fixed x, fixed y)
	{
		obj[id].pos.x2 = x;
		obj[id].pos.y2 = y;
		CalcSizes(id);
	}

	// set the x1,y1,x2,y2 of the widget
	function void SetPosition(int id, fixed x1, fixed y1, fixed x2, fixed y2)
	{
		obj[id].pos.x1 = x1;
		obj[id].pos.y1 = y1;
		obj[id].pos.x2 = x2;
		obj[id].pos.y2 = y2;
		CalcSizes(id);
	}

	// set the x1,y1,x2,y2 of the widget
	function void SetRectPosition(int id, fixed x1, fixed y1, fixed w, fixed h)
	{
		obj[id].pos.x1 = fixed(int(x1));
		obj[id].pos.y1 = fixed(int(y1));
		obj[id].pos.x2 = fixed(int(x1+w));
		obj[id].pos.y2 = fixed(int(y1+h));
		CalcSizes(id);
	}

	function void SetTextOffsetX(int id, fixed value) 		{ obj[id].text_offset.x = value; }
	function void SetTextOffsetY(int id, fixed value) 		{ obj[id].text_offset.y = value; }

	// colors
	function void SetBackColorNormal(int id, str value) 	{ obj[id].backcolor.normal = value; }
	function void SetBackColorHovered(int id, str value) 	{ obj[id].backcolor.hovered = value; }
	function void SetBackColorClicked(int id, str value) 	{ obj[id].backcolor.clicked = value; }
	function void SetBackColorCurrent(int id, str value) 	{ obj[id].backcolor.current = value; }

	function void SetTextColorNormal(int id, str value) 	{ obj[id].backcolor.normal = value; }
	function void SetTextColorHovered(int id, str value) 	{ obj[id].backcolor.hovered = value; }
	function void SetTextColorClicked(int id, str value) 	{ obj[id].backcolor.clicked = value; }
	function void SetTextColorCurrent(int id, str value) 	{ obj[id].backcolor.current = value; }

	// text and image
	function void SetText(int id, str value) 				{  obj[id].text = value; }
	function void SetImage(int id, str value) 				{  obj[id].image = value; }
	function void SetFont(int id, int value) 				{  obj[id].font = value; }

	// flags
	function void SetAlive(int id, bool value) 				{ obj[id].alive = value; }
	function void SetVisible(int id, bool value) 			{ obj[id].visible = value; }
	function void SetEnabled(int id, bool value) 			{ obj[id].enabled = value; }
	function void SetHoverRepeat(int id, bool value) 		{ obj[id].hover_repeat = value; }
	function void SetClickRepeat(int id, bool value) 		{ obj[id].click_repeat = value; }
	function void SetHoverable(int id, bool value) 			{ obj[id].hoverable = value; }
	function void SetClickable(int id, bool value) 			{ obj[id].clickable = value; }
	function void SetCheckable(int id, bool value) 			{ obj[id].checkable = value; }
	function void SetRenderText(int id, bool value) 		{ obj[id].render_text = value; }
	function void SetRenderImage(int id, bool value) 		{ obj[id].render_image = value; }
    function void SetRenderBack(int id, bool value) 		{ obj[id].render_back = value; }

	// event properties
	function void SetHovered(int id, bool value) 			{ obj[id].hovered = value; }
	function void SetClicked(int id, bool value) 			{ obj[id].clicked = value; }
	function void SetChecked(int id, bool value) 			{ obj[id].checked = value; }

	// other bits of information
	function void SetArg1Int(int id, int value) 			{ obj[id].arg1int = value; }
	function void SetArg2Int(int id, int value) 			{ obj[id].arg2int = value; }
	function void SetArg3Int(int id, int value) 			{ obj[id].arg3int = value; }
	function void SetArg4Int(int id, int value) 			{ obj[id].arg4int = value; }
	function void SetArg5Int(int id, int value) 			{ obj[id].arg5int = value; }

	function void SetArg1Str(int id, str value) 			{ obj[id].arg1Str = value; }
	function void SetArg2Str(int id, str value) 			{ obj[id].arg2Str = value; }
	function void SetArg3Str(int id, str value) 			{ obj[id].arg3Str = value; }
	function void SetArg4Str(int id, str value) 			{ obj[id].arg4Str = value; }
	function void SetArg5Str(int id, str value) 			{ obj[id].arg5Str = value; }

	// widget functionalities
	function void Update(int id)
	{
		// is the widget not marked for being overwritten?
		if(GetAlive(id))
		{
			// is the widget visible?
			if(GetVisible(id))
			{
				// is the user able to interact with this widget?
				if(GetEnabled(id))
				{
					// is the widget checked?
					if(GetChecked(id))
					{
						// checked colored
						obj[id].backcolor.current = obj[id].backcolor.checked;
						obj[id].textcolor.current = obj[id].textcolor.checked;
					}
					else
					{
						// normal colored
						obj[id].backcolor.current = obj[id].backcolor.normal;
						obj[id].textcolor.current = obj[id].textcolor.normal;
					}

					// is cursor within bounds?
					if(Cursor::GetX() >= GetX1(id) && Cursor::GetX() <= GetX2(id) && Cursor::GetY() >= GetY1(id) && Cursor::GetY() <= GetY2(id))
					{
						// is this object hoverable?
						if(GetHoverable(id))
						{
							// hover colored
							obj[id].backcolor.current = obj[id].backcolor.hovered;
							obj[id].textcolor.current = obj[id].textcolor.hovered;

							// is the widget set to call it's hovered function every frame?
							if(GetHoverRepeat(id))
							{
								CallHoveredHooks(id);
							}
							// only call the clicked function once
							else
							{
								if(!GetHovered(id))
								{
									CallHoveredHooks(id);
									SetHovered(id, true);;
								}
							}
						}

						// is this object clickable?
						if(GetClickable(id))
						{
							// is the user clicking the mouse?
							if(Cursor::GetClicked())
							{
								// click colored
								obj[id].backcolor.current = obj[id].backcolor.clicked;
								obj[id].textcolor.current = obj[id].textcolor.clicked;

								// set object's clicked bool
								SetClicked(id, true);

								// is the widget set to call it's clicked function every frame as the user holds the mouse?
								if(GetClickRepeat(id))
								{
									// call object's clicked callback
									CallClickedHooks(id);
								}
								// only call the clicked function once
								else
								{
									// was the cursor not clicked on the previous frame?
									if(!Cursor::GetClickedPrev())
									{
										// check the widget
										if(GetCheckable(id))
										{
											SetChecked(id, !GetChecked(id));
										}
										//call object's clicked callback
										CallClickedHooks(id);
									}
								}
							}
							// user is no longer clicking
							else
							{
								// unset object's clicked bool
								SetClicked(id, false);
							}
						}
					}
					// cursor is not within bounds
					else
					{
						SetHovered(id, false);
						SetClicked(id, false);
					}

					// has the widget moved or changed size?
					if(GetPrevX1(id) != GetX1(id) || GetPrevY1(id) != GetY1(id) || GetPrevX2(id) != GetX2(id) || GetPrevY2(id) != GetY2(id))
					{
						// set all the size variables
						CalcSizes(id);

						// call object's moved callback
						CallMovedHooks(id);
					}
				}
				else
				{
					// disable colored
					obj[id].backcolor.current = obj[id].backcolor.disabled;
					obj[id].textcolor.current = obj[id].textcolor.disabled;
				}
                
                if(GetRenderBack(id))
                {
                    // this is broken in zandronum
                    //SetHudClipRect(int(Widgets::GetX1(id)), int(Widgets::GetY1(id)), int(Widgets::GetWidth(id)), int(Widgets::GetHeight(id)), 0, true);

                    fixed size = fixed(obj[id].panelsize);
                    fixed cols = fixed(int(GetWidth(id) / size))-1.0;
                    fixed rows = fixed(int(GetHeight(id) / size))-1.0;

                    str c = "A";
                    switch(size)
                    {
                        case 8.0: c = "A"; break;
                        case 16.0: c = "B"; break;
                        case 32.0: c = "C"; break;
                        case 64.0: c = "D"; break;
                        case 128.0: c = "E"; break;
                    }

                    // top right and middle
                    for(fixed x = 0.0; x <= cols; x += 1.0)
                    {
                        for(fixed y = 0.0; y <= rows; y += 1.0)
                        {
                            Screen::DrawImage("LXUIFONT", c, GetBackColorCurrent(id), GetX1(id)+(x*size), GetY1(id)+(y*size), Screen::XALIGN_LEFT, Screen::YALIGN_TOP);
                        }
                    }

                    // right
                    for(fixed y = 0.0; y <= rows; y += 1.0)
                    {
                        Screen::DrawImage("LXUIFONT", c, GetBackColorCurrent(id), GetX2(id), GetY1(id)+(y*size), Screen::XALIGN_RIGHT, Screen::YALIGN_TOP);
                    }

                    // bottom
                    for(fixed x = 0.0; x <= cols; x += 1.0)
                    {
                       Screen::DrawImage("LXUIFONT", c, GetBackColorCurrent(id), GetX1(id)+(x*size), GetY2(id)-size, Screen::XALIGN_LEFT, Screen::YALIGN_TOP);
                    }

                    // bottom right corner
                    Screen::DrawImage("LXUIFONT", c, GetBackColorCurrent(id), GetX2(id), GetY2(id)-size, Screen::XALIGN_RIGHT, Screen::YALIGN_TOP);
                }

				// call object's update callback
				CallUpdateHooks(id);

				// should we render the back image?
				if(GetRenderImage(id))
				{
					Screen::DrawImage(GetImage(id), "a", GetBackColorCurrent(id), GetX1(id), GetY1(id), Screen::XALIGN_LEFT, Screen::YALIGN_TOP);
				}


				// should we render the text?
				if(GetRenderText(id))
				{
					Screen::DrawText(GetFont(id), GetText(id), GetTextColorCurrent(id), GetCenterX(id) + GetTextOffsetX(id), GetY1(id) + GetTextOffsetY(id), Screen::XALIGN_CENTER, Screen::YALIGN_TOP);
				}




				SetPrevX1(id, GetX1(id));
				SetPrevY1(id, GetY1(id));
				SetPrevX2(id, GetX2(id));
				SetPrevY1(id, GetY2(id));
			}
		}
	}
}

/*




*/