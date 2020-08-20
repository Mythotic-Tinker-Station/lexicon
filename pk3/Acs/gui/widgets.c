/*
	Lexicon UI by Tribeam
	With help from Popsoap, Michaelis

	Widgets Namespace:
		int 	Widgets.Create()														// Create a new default widget; returns an id number of said widget;
		void 	Widgets.Delete(int id)													// Deletes a widget;
		int 	Widgets.FindFreeSlot()													// Finds the next available slot in the widget pool;
		void 	Widgets.Run()															// Run the widgets!;
		void	Widgets.CalcSizes(int id)												// Recalculates the width, height, half width and half height vars;
		void	Widgets.AddUpdateHook(int id, function f)								// Adds a function to the update event;
		void	Widgets.AddHoveredHook(int id, function f)								// Adds a function to the hovered event;
		void	Widgets.AddClickedHook(int id, function f)								// Adds a function to the clicked event;
		void	Widgets.AddMovedHook(int id, function f)								// Adds a function to the moved event;
		void	Widgets.CallUpdateHooks(int id)											// Calls all the functions hooked to the update event;
		void	Widgets.CallHoveredHooks(int id)										// Calls all the functions hooked to the hovered event;
		void	Widgets.CallClickedHooks(int id)										// Calls all the functions hooked to the clicked event;
		void	Widgets.CallMovedHooks(int id)											// Calls all the functions hooked to the moved event;

		fixed	Widgets.GetX1(int id)													// Returns the x1 point of the widget;
		fixed	Widgets.GetY1(int id)													// Returns the x2 point of the widget;
		fixed	Widgets.GetX2(int id)													// Returns the y1 point of the widget;
		fixed	Widgets.GetY2(int id)													// Returns the y2 point of the widget;
		fixed	Widgets.GetCenterX(int id)												// Returns the center x point of the widget;
		fixed	Widgets.GetCenterY(int id)												// Returns the center y point of the widget;

		str		Widgets.GetColorNormal(int id)											// returns the base color of the widget;
		str		Widgets.GetColorHovered(int id)											// returns the hovered color of the widget;
		str		Widgets.GetColorClicked(int id)											// returns the clicked color of the widget;

		str		Widgets.GetText(int id)													// returns the text of the widget;

		fixed	Widgets.GetWidth(int id)												// Returns the width of the widget;
		fixed	Widgets.GetHeight(int id)												// Returns the height of the widget;
		fixed	Widgets.GetWidth_Half(int id)											// Returns the half width of the widget;
		fixed	Widgets.GetHeight_Half(int id)											// Returns the half height of the widget;

		// yeah, i know
		int 	Widgets.GetCustomInt1(int id)											// Returns custom int 1;
		int 	Widgets.GetCustomInt2(int id)											// Returns custom int 2;
		int 	Widgets.GetCustomInt3(int id)											// Returns custom int 3;
		int 	Widgets.GetCustomInt4(int id)											// Returns custom int 4;
		int 	Widgets.GetCustomInt5(int id)											// Returns custom int 5;
		int 	Widgets.GetCustomInt6(int id)											// Returns custom int 6;
		fixed 	Widgets.GetCustomfixed1(int id)											// Returns custom fixed 1;
		fixed 	Widgets.GetCustomfixed2(int id)											// Returns custom fixed 2;
		fixed 	Widgets.GetCustomfixed3(int id)											// Returns custom fixed 3;
		fixed 	Widgets.GetCustomfixed4(int id)											// Returns custom fixed 4;
		fixed 	Widgets.GetCustomfixed5(int id)											// Returns custom fixed 5;
		fixed 	Widgets.GetCustomfixed6(int id)											// Returns custom fixed 6;
		str 	Widgets.GetCustomString1(int id)										// Returns custom string 1;
		str 	Widgets.GetCustomString2(int id)										// Returns custom string 2;
		str 	Widgets.GetCustomString3(int id)										// Returns custom string 3;
		str 	Widgets.GetCustomString4(int id)										// Returns custom string 4;
		str 	Widgets.GetCustomString5(int id)										// Returns custom string 5;
		str 	Widgets.GetCustomString6(int id)										// Returns custom string 6;
		bool 	Widgets.GetCustomBool1(int id)											// Returns custom bool 1;
		bool 	Widgets.GetCustomBool2(int id)											// Returns custom bool 2;
		bool 	Widgets.GetCustomBool3(int id)											// Returns custom bool 3;
		bool 	Widgets.GetCustomBool4(int id)											// Returns custom bool 4;
		bool 	Widgets.GetCustomBool5(int id)											// Returns custom bool 5;
		bool 	Widgets.GetCustomBool6(int id)											// Returns custom bool 6;

		void	Widgets.SetX1(int id, fixed x1)											// Sets the x1 point of the widget;
		void	Widgets.SetY1(int id, fixed y1)											// Sets the x2 point of the widget;
		void	Widgets.SetX2(int id, fixed x2)											// Sets the y1 point of the widget;
		void	Widgets.SetY2(int id, fixed y2)											// Sets the y2 point of the widget;

		void 	Widgets.SetTopLeftPosition(int id, fixed x, fixed y)					// Sets the x, y of the top left position of the widget;
		void 	Widgets.SetBottomRightPosition(int id, fixed x, fixed y)				// Sets the x, y of the bottom right position of the widget;
		void 	Widgets.SetPosition(int id, fixed x1, fixed y1, fixed x2, fixed y2)		// Sets the x1, y1, x2, y2 positions of the widget;
		void 	Widgets.SetRectPosition(int id, fixed x1, fixed y1, fixed w, fixed h)	// Sets the x1, y1, x2, y2 positions of the widget with a width/height;

		void	Widgets.SetColorNormal(int id)											// Sets the base color of the widget;
		void	Widgets.SetColorHovered(int id)											// Sets the hovered color of the widget;
		void	Widgets.SetColorClicked(int id)											// Sets the clicked color of the widget;

		void	Widgets.SetText(int id, str value)										// Sets the text of the widget;

		void	Widgets.SetCustomInt1(int id, int value)								// Set custom int 1;
		void	Widgets.SetCustomInt2(int id, int value)								// Set custom int 2;
		void	Widgets.SetCustomInt3(int id, int value)								// Set custom int 3;
		void	Widgets.SetCustomInt4(int id, int value)								// Set custom int 4;
		void	Widgets.SetCustomInt5(int id, int value)								// Set custom int 5;
		void	Widgets.SetCustomInt6(int id, int value)								// Set custom int 6;
		void	Widgets.SetCustomfixed1(int id, fixed value)							// Set custom fixed 1;
		void	Widgets.SetCustomfixed2(int id, fixed value)							// Set custom fixed 2;
		void	Widgets.SetCustomfixed3(int id, fixed value)							// Set custom fixed 3;
		void	Widgets.SetCustomfixed4(int id, fixed value)							// Set custom fixed 4;
		void	Widgets.SetCustomfixed5(int id, fixed value)							// Set custom fixed 5;
		void	Widgets.SetCustomfixed6(int id, fixed value)							// Set custom fixed 6;
		void	Widgets.SetCustomString1(int id, str value)								// Set custom string 1;
		void	Widgets.SetCustomString2(int id, str value)								// Set custom string 2;
		void	Widgets.SetCustomString3(int id, str value)								// Set custom string 3;
		void	Widgets.SetCustomString4(int id, str value)								// Set custom string 4;
		void	Widgets.SetCustomString5(int id, str value)								// Set custom string 5;
		void	Widgets.SetCustomString6(int id, str value)								// Set custom string 6;
		void	Widgets.SetCustomBool1(int id, bool value)								// Set custom bool 1;
		void	Widgets.SetCustomBool2(int id, bool value)								// Set custom bool 2;
		void	Widgets.SetCustomBool3(int id, bool value)								// Set custom bool 3;
		void	Widgets.SetCustomBool4(int id, bool value)								// Set custom bool 4;
		void	Widgets.SetCustomBool5(int id, bool value)								// Set custom bool 5;
		void	Widgets.SetCustomBool6(int id, bool value)								// Set custom bool 6;


		void	Widgets.Update(int id)													// Updates the widget;
*/



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
		struct colors backcolor;						// background colors
		struct colors textcolor;						// text colors

		str text;										// text to display

		int custom_int1;								// custom int for specific widget stuff
		int custom_int2;								// custom int for specific widget stuff
		int custom_int3;								// custom int for specific widget stuff
		int custom_int4;								// custom int for specific widget stuff
		int custom_int5;								// custom int for specific widget stuff
		int custom_int6;								// custom int for specific widget stuff
		fixed custom_fixed1;							// custom fixed number for specific widget stuff
		fixed custom_fixed2;							// custom fixed number for specific widget stuff
		fixed custom_fixed3;							// custom fixed number for specific widget stuff
		fixed custom_fixed4;							// custom fixed number for specific widget stuff
		fixed custom_fixed5;							// custom fixed number for specific widget stuff
		fixed custom_fixed6;							// custom fixed number for specific widget stuff
		str custom_string1;								// custom string for specific widget stuff
		str custom_string2;								// custom string for specific widget stuff
		str custom_string3;								// custom string for specific widget stuff
		str custom_string4;								// custom string for specific widget stuff
		str custom_string5;								// custom string for specific widget stuff
		str custom_string6;								// custom string for specific widget stuff
		bool custom_bool1;								// custom bool for specific widget stuff
		bool custom_bool2;								// custom bool for specific widget stuff
		bool custom_bool3;								// custom bool for specific widget stuff
		bool custom_bool4;								// custom bool for specific widget stuff
		bool custom_bool5;								// custom bool for specific widget stuff
		bool custom_bool6;								// custom bool for specific widget stuff

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
		obj[id].backcolor.normal 	= "Green";
		obj[id].backcolor.clicked	= "Cyan";
		obj[id].backcolor.hovered	= "Blue";
		obj[id].backcolor.current	= "Green";
		obj[id].textcolor.normal 	= "White";
		obj[id].textcolor.clicked	= "White";
		obj[id].textcolor.hovered	= "White";
		obj[id].textcolor.current	= "White";
		obj[id].text				= "";
		obj[id].custom_int1			= 0;
		obj[id].custom_int2			= 0;
		obj[id].custom_int3			= 0;
		obj[id].custom_int4			= 0;
		obj[id].custom_int5			= 0;
		obj[id].custom_int6			= 0;
		obj[id].custom_fixed1		= 0.0;
		obj[id].custom_fixed2		= 0.0;
		obj[id].custom_fixed3		= 0.0;
		obj[id].custom_fixed4		= 0.0;
		obj[id].custom_fixed5		= 0.0;
		obj[id].custom_fixed6		= 0.0;
		obj[id].custom_string1		= "";
		obj[id].custom_string2		= "";
		obj[id].custom_string3		= "";
		obj[id].custom_string4		= "";
		obj[id].custom_string5		= "";
		obj[id].custom_string6		= "";
		obj[id].custom_bool1		= false;
		obj[id].custom_bool2		= false;
		obj[id].custom_bool3		= false;
		obj[id].custom_bool4		= false;
		obj[id].custom_bool5		= false;
		obj[id].custom_bool6		= false;

		// flags
		obj[id].alive 			= true;
		obj[id].visible 		= true;
		obj[id].enabled 		= true;
		obj[id].click_repeat 	= false;
		obj[id].hover_repeat 	= false;
		obj[id].clickable		= false;
		obj[id].hoverable 		= false;
		obj[id].hovered			= false;
		obj[id].clicked			= false;

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

	// get specific positions
	function fixed GetX1(int id) { return obj[id].pos.x1; }
	function fixed GetY1(int id) { return obj[id].pos.y1; }
	function fixed GetX2(int id) { return obj[id].pos.x2; }
	function fixed GetY2(int id) { return obj[id].pos.y2; }

	function fixed GetCenterX(int id) { return obj[id].center.x; }
	function fixed GetCenterY(int id) { return obj[id].center.y; }

	function fixed GetWidth(int id) { return obj[id].size.w; }
	function fixed GetHeight(int id) { return obj[id].size.h; }
	function fixed GetWidth_Half(int id) { return obj[id].size.wh; }
	function fixed GetHeight_Half(int id) { return obj[id].size.hh; }

	function str GetColorNormal(int id) { return obj[id].backcolor.normal; }
	function str GetColorHovered(int id) { return obj[id].backcolor.hovered; }
	function str GetColorClicked(int id) { return obj[id].backcolor.clicked; }
	function str GetColorCurrent(int id) { return obj[id].backcolor.current; }

	function str GetText(int id) { return obj[id].text; }

	// get specific customs
	function int GetCustomInt1(int id) { return obj[id].custom_int1; }
	function int GetCustomInt2(int id) { return obj[id].custom_int2; }
	function int GetCustomInt3(int id) { return obj[id].custom_int3; }
	function int GetCustomInt4(int id) { return obj[id].custom_int4; }
	function int GetCustomInt5(int id) { return obj[id].custom_int5; }
	function int GetCustomInt6(int id) { return obj[id].custom_int6; }
	function fixed GetCustomfixed1(int id) { return obj[id].custom_fixed1; }
	function fixed GetCustomfixed2(int id) { return obj[id].custom_fixed2; }
	function fixed GetCustomfixed3(int id) { return obj[id].custom_fixed3; }
	function fixed GetCustomfixed4(int id) { return obj[id].custom_fixed4; }
	function fixed GetCustomfixed5(int id) { return obj[id].custom_fixed5; }
	function fixed GetCustomfixed6(int id) { return obj[id].custom_fixed6; }
	function str GetCustomString1(int id) { return obj[id].custom_string1; }
	function str GetCustomString2(int id) { return obj[id].custom_string2; }
	function str GetCustomString3(int id) { return obj[id].custom_string3; }
	function str GetCustomString4(int id) { return obj[id].custom_string4; }
	function str GetCustomString5(int id) { return obj[id].custom_string5; }
	function str GetCustomString6(int id) { return obj[id].custom_string6; }
	function bool GetCustomBool1(int id) { return obj[id].custom_bool1; }
	function bool GetCustomBool2(int id) { return obj[id].custom_bool2; }
	function bool GetCustomBool3(int id) { return obj[id].custom_bool3; }
	function bool GetCustomBool4(int id) { return obj[id].custom_bool4; }
	function bool GetCustomBool5(int id) { return obj[id].custom_bool5; }
	function bool GetCustomBool6(int id) { return obj[id].custom_bool6; }


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
		obj[id].pos.x1 = x1;
		obj[id].pos.y1 = y1;
		obj[id].pos.x2 = x1+w;
		obj[id].pos.y2 = y1+h;
		CalcSizes(id);
	}

	function void SetColorNormal(int id, str value) { obj[id].backcolor.normal = value; }
	function void SetColorHovered(int id, str value) { obj[id].backcolor.hovered = value; }
	function void SetColorClicked(int id, str value) { obj[id].backcolor.clicked = value; }
	function void SetColorCurrent(int id, str value) { obj[id].backcolor.current = value; }

	function void SetText(int id, str value) { obj[id].text = value; }

	// set specific customs
	function void SetCustomInt1(int id, int value) { obj[id].custom_int1 = value; }
	function void SetCustomInt2(int id, int value) { obj[id].custom_int2 = value; }
	function void SetCustomInt3(int id, int value) { obj[id].custom_int3 = value; }
	function void SetCustomInt4(int id, int value) { obj[id].custom_int4 = value; }
	function void SetCustomInt5(int id, int value) { obj[id].custom_int5 = value; }
	function void SetCustomInt6(int id, int value) { obj[id].custom_int6 = value; }
	function void SetCustomfixed1(int id, fixed value) { obj[id].custom_fixed1 = value; }
	function void SetCustomfixed2(int id, fixed value) { obj[id].custom_fixed2 = value; }
	function void SetCustomfixed3(int id, fixed value) { obj[id].custom_fixed3 = value; }
	function void SetCustomfixed4(int id, fixed value) { obj[id].custom_fixed4 = value; }
	function void SetCustomfixed5(int id, fixed value) { obj[id].custom_fixed5 = value; }
	function void SetCustomfixed6(int id, fixed value) { obj[id].custom_fixed6 = value; }
	function void SetCustomString1(int id, str value) { obj[id].custom_string1 = value; }
	function void SetCustomString2(int id, str value) { obj[id].custom_string2 = value; }
	function void SetCustomString3(int id, str value) { obj[id].custom_string3 = value; }
	function void SetCustomString4(int id, str value) { obj[id].custom_string4 = value; }
	function void SetCustomString5(int id, str value) { obj[id].custom_string5 = value; }
	function void SetCustomString6(int id, str value) { obj[id].custom_string6 = value; }
	function void SetCustomBool1(int id, bool value) { obj[id].custom_bool1 = value; }
	function void SetCustomBool2(int id, bool value) { obj[id].custom_bool2 = value; }
	function void SetCustomBool3(int id, bool value) { obj[id].custom_bool3 = value; }
	function void SetCustomBool4(int id, bool value) { obj[id].custom_bool4 = value; }
	function void SetCustomBool5(int id, bool value) { obj[id].custom_bool5 = value; }
	function void SetCustomBool6(int id, bool value) { obj[id].custom_bool6 = value; }

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