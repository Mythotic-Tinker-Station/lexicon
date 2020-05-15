////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Object Managment
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#if 1
	// Hud alignment
	#define GUI_XALIGN_CENTER 						0.0					// Align center of text to the x position
	#define GUI_XALIGN_LEFT 						0.1					// Align left of text to the x position
	#define GUI_XALIGN_RIGHT 						0.2					// Align right of text to the x position
	#define GUI_XALIGN_BOXCENTER 					0.4					// What
	#define GUI_XALIGN_BOXLEFT 						0.5					// What
	#define GUI_XALIGN_BOXRIGHT 					0.6					// What

	#define GUI_YALIGN_CENTER 						0.0					// Align center of text to the y position
	#define GUI_YALIGN_TOP 							0.1					// Align the top of text to the y position
	#define GUI_YALIGN_BOTTOM 						0.2					// Align the bottom of text to the y position

	// Gui text types
	#define GUI_TEXTTYPE_STRING 					0					// Tell an object to print a string
	#define GUI_TEXTTYPE_INT						1					// Tell an object to print an int
	#define GUI_TEXTTYPE_FIXED						2					// Tell an object to print a fixed number
	#define GUI_TEXTTYPE_NAME	 					3                   // Tell an object to print a name
	#define GUI_TEXTTYPE_HEX	 					4                   // Tell an object to print a hex number
	#define GUI_TEXTTYPE_BINARY	 					5                   // Tell an object to print a binary number
	#define GUI_TEXTTYPE_CHAR	 					6                   // Tell an object to print a char
	#define GUI_TEXTTYPE_ARRAY	 					7                   // Tell an object to print an array
	#define GUI_TEXTTYPE_KEY	 					8                   // Tell an object to print a input key

	// gui misc
	#define GUI_MAX_OBJECTS 						64					// Max number of objects to loop for
#endif


// size
struct size
{
	fixed w;
	fixed h;
	fixed w_half;
	fixed h_half;
};

// colors
struct color
{
	str normal;
	str hover;
	str clicked;
	str disabled;
	str checked;
	str checked_hover;
	str checked_clicked;
	str checked_disabled;
	str image;
	str image_checked;
	str image2;
	str image_checked2;
	str current;
};

// 2d point
struct vec2
{
	fixed x;
	fixed y;
};

// 3d point
struct vec3
{
	fixed x;
	fixed y;
	fixed z;
};

// 2 2d points
struct vec4
{
	fixed x1;
	fixed y1;
	fixed x2;
	fixed y2;
};


// cursor object
struct _cursor
{
	struct vec2 pos;				            // cursor x/y position
	struct vec2 posadd;				            // amount to add to x/y
	struct vec2 poscalc;			            // calculation of pos with posadd and user's sens settings
	int bflags;						            // button flags
	bool clicked;					            // true if the user is clicking the mouse
	bool clicked_prev;				            // value of the click from the previous frame
	int dragging;					            // object index of what the cursor is dragging
	struct vec4 posdrag;			            // position references for object dragging
};

// gui base object
struct guiobj
{
	// properties
	struct vec4 pos;				            // x1/y1/x2/y2 position of the gui object
	struct vec2 center;				            // x/y of center of object(read only)
	struct size size;				            // w/h of the gui object(read-only)
	struct color color;				            // the 5 colors of an object's background

	struct vec4 draglimit;			            // positions that force dragging to certain bounds

	// text stuff
	str text;						            // string to display over the object when not checked
    str text_checked;				            // string to display over the object when checked
    str text_hovered;				            // string to display over the object when hovered
    str text_current;				            // string to display over the object
	int text_type;					            // type of string to display
	str text_font;					            // type of font to use for the string
    str text_font_checked;  		            // type of font to use for the string when checked
    str text_font_hovered;  		            // type of font to use for the string when hovered
    str text_font_current;  		            // type of font to use for the string
	struct vec2 textpos;			            // x/y of the text
	struct vec2 textoffset;			            // x/y of the text
	struct vec2 textalign;			            // x/y alignment of the text x: -1 = left; 0 = center; 1 = right; y: -1 = top; 0 = center; 1 = bottom
    struct color textcolor;			            // the 5 colors of an object's text

	str text2;						            // string to display over the object
    str text_checked2;				            // string to display over the object when checked
    str text_hovered2;				            // string to display over the object when hovered
    str text_current2;				            // string to display over the object
	int text_type2;					            // type of string to display
	str text_font2;					            // type of font to use for the string
    str text_font_checked2;  		            // type of font to use for the string when checked
    str text_font_hovered2;  		            // type of font to use for the string when hovered
    str text_font_current2;  		            // type of font to use for the string when checked
    struct vec2 textpos2;			            // x/y of the text
	struct vec2 textoffset2;	                // x/y of the text
	struct vec2 textalign2;			            // x/y alignment of the text x: -1 = left; 0 = center; 1 = right; y: -1 = top; 0 = center; 1 = bottom

	// dragging
	bool drag_x;					            // can the object be dragged on it's x axis?
	bool drag_y;					            // can the object be dragged on it's y axis?

	// flags
	bool hoverable;					            // is the object hoverable?
	bool clickable;					            // is the object clickable?
	bool checkable;					            // is the object checkable?
	bool draggable;					            // is the object draggable?
	bool visible;					            // is the object visible?
	bool enabled;					            // can this object be interacted with?
	bool free;						            // is this object alive?
	bool clickhold;					            // when clicked, does the object register a click every frame?
	bool background;				            // render the background?
	bool render_text;				            // render text?
    bool render_text2;				            // render text?
	void function(int)? func;		            // function to call when object is clicked
	int custom1;					            // extra property for object specific info
	raw custom2;					            // extra property for object specific info
	raw custom3;					            // extra property for object specific info
	raw custom4;					            // extra property for object specific info
	raw custom5;					            // extra property for object specific info
	raw custom6;					            // extra property for object specific info

	// events
	bool hovered;					            // is the object hovered over?
	bool clicked;					            // is the object being clicked?
	bool checked;					            // is the object checked?
	bool clicked_prev;				            // was the object clicked on the previous frame?
	bool checked_prev;				            // was the object checked on the previous frame?

};

// object that holds all the gui objects
struct _gui
{
	struct guiobj objects[GUI_MAX_OBJECTS];		// list of all the gui objects
	int count;									// number of gui objects
	fixed w;									// width
	fixed h;									// height
	fixed w_half;								// screen center x
	fixed h_half;								// screen center y
	int blocks;									// screen blocks(what hud the user has selected)
	int nextid;									// next id for the next hudmessage to draw
    int objcount;                               // amount of objects that exist
    int screen;                                 // what screen the client is in
};


struct _cursor cursor;                          // cursor
struct _gui gui;                                // gui


////////////////////////////////////////////////////////
// Helper Functions
////////////////////////////////////////////////////////

function void nullFunc(int i)
{
    print(i:i);
}

// clientcheck
function bool clientCheck()
{
    if(IsNetworkGame()) { if(playerNumber() != consolePlayerNumber()) { return false; } }
	return true;
}


// setup screen size and some variables
function void guiInit(int w, int h)
{
	if(w < 1) { w = GetCVar("vid_defwidth"); }
	if(h < 1) { h = GetCVar("vid_defheight"); }

	gui.w = fixed(w);
	gui.h = fixed(h);
	gui.w_half = (gui.w/2.0);
	gui.h_half = (gui.h/2.0);
	gui.blocks = GetCVar("screenblocks");

	SetHudSize(w, h, true);
}


////////////////////////////////////////////////////////
// Cursor
////////////////////////////////////////////////////////
function void guiCursorInit()
{
	// set the cursor to the center of the screen on start
	cursor.pos.x = gui.w_half;
	cursor.pos.y = gui.h_half;
	cursor.dragging = -1;
}

function void guiCursorRun()
{
	// player input
	cursor.posadd.x = fixed(getPlayerInput(-1, INPUT_YAW));
	cursor.posadd.y = fixed(getPlayerInput(-1, INPUT_PITCH));
	cursor.bflags = getPlayerInput(-1, INPUT_BUTTONS);

	cursor.poscalc.x = -fixed(int(cursor.posadd.x / (51.0 - fixed(getCVar("lexicon_cursor_xsens")))));
	cursor.poscalc.y = -fixed(int(cursor.posadd.y / (51.0 - fixed(getCVar("lexicon_cursor_ysens")))));

	// set position
	if(cursor.posadd.x != 0.0) { cursor.pos.x += cursor.poscalc.x; printbold(f:cursor.poscalc.x); }
	if(cursor.posadd.y != 0.0) { cursor.pos.y += cursor.poscalc.y; }

	// bounds
	if(cursor.pos.x < 0.0) 		{ cursor.pos.x = 0.0; }
    if(cursor.pos.y < 0.0) 		{ cursor.pos.y = 0.0; }
    if(cursor.pos.x > gui.w) 	{ cursor.pos.x = gui.w; }
    if(cursor.pos.y > gui.h) 	{ cursor.pos.y = gui.h; }

	// if mouse1 is pressed
	if(cursor.bflags & BT_ATTACK)
	{
		cursor.clicked = true;
	}
	else
	{
		cursor.clicked = false;
		cursor.dragging = -1;
	}

	//render
	setFont("CURSORFONT");
	guiPrintString(cursor.pos.x + GUI_XALIGN_LEFT, cursor.pos.y + GUI_YALIGN_TOP, GetCVarString("lexicon_cursor_color"), "a");

	// render shadow
	if((bool)getCVar("lexicon_cursor_shadow") == true)
	{
		setFont("CURSOR_S");
		guiPrintString(cursor.pos.x + GUI_XALIGN_LEFT, cursor.pos.y + GUI_YALIGN_TOP, "White", "a");
	}
}


/////////////////////////////////
// create an object
/////////////////////////////////
function int guiObjectCreate()
{
	int index = guiObjectFindFreeSlot();
	if(index == -1) { Log(s:"GUI Error: Could not create object, max number of objects reached."); return -1; }
	gui.objects[index].pos.x1 						= 0.0;
	gui.objects[index].pos.y1 						= 0.0;
	gui.objects[index].pos.x2 						= 10.0;
	gui.objects[index].pos.y2 						= 10.0;
	gui.objects[index].color.normal 				= "gui_normal";
	gui.objects[index].color.hover 					= "gui_hover";
	gui.objects[index].color.clicked 				= "gui_clicked";
	gui.objects[index].color.disabled 				= "gui_disabled";
	gui.objects[index].color.checked				= "gui_checked";
	gui.objects[index].color.checked_hover			= "gui_checked_hovered";
	gui.objects[index].color.checked_disabled		= "gui_checked_disabled";
	gui.objects[index].color.image					= "gui_image";
	gui.objects[index].color.image_checked			= "gui_image_checked";
	gui.objects[index].textcolor.normal				= "gui_text";
	gui.objects[index].textcolor.hover 				= "gui_text_hovered";
	gui.objects[index].textcolor.clicked 			= "gui_text_clicked";
	gui.objects[index].textcolor.disabled 			= "gui_text_disabled";
	gui.objects[index].textcolor.checked			= "gui_text_checked";
	gui.objects[index].textcolor.checked_hover		= "gui_text_checked_hovered";
	gui.objects[index].textcolor.checked_disabled	= "gui_text_checked_disabled";
	gui.objects[index].textpos.x					= 0.0;
	gui.objects[index].textpos.y					= 0.0;
	gui.objects[index].textoffset.x					= 0.0;
	gui.objects[index].textoffset.y					= 0.0;
	gui.objects[index].textalign.x					= GUI_XALIGN_CENTER;
	gui.objects[index].textalign.y					= GUI_YALIGN_CENTER;
	gui.objects[index].text 						= "a";
    gui.objects[index].text_checked 				= "a";
	gui.objects[index].text_type 					= GUI_TEXTTYPE_STRING;
	gui.objects[index].text_font 					= "CLEANDOOMBIG";
    gui.objects[index].text_font_checked 			= "CLEANDOOMBIG";
    gui.objects[index].textpos2.x					= 0.0;
	gui.objects[index].textpos2.y					= 0.0;
	gui.objects[index].textoffset2.x				= 0.0;
	gui.objects[index].textoffset2.y				= 0.0;
	gui.objects[index].textalign2.x					= GUI_XALIGN_CENTER;
	gui.objects[index].textalign2.y					= GUI_YALIGN_CENTER;
	gui.objects[index].text2 						= "a";
    gui.objects[index].text_checked2 				= "a";
	gui.objects[index].text_type2 					= GUI_TEXTTYPE_STRING;
	gui.objects[index].text_font2 					= "CLEANDOOMBIG";
    gui.objects[index].text_font_checked2 			= "CLEANDOOMBIG";
	gui.objects[index].hoverable					= false;
	gui.objects[index].clickable					= false;
	gui.objects[index].checkable					= false;
	gui.objects[index].draggable					= false;
	gui.objects[index].drag_x						= true;
	gui.objects[index].drag_y						= true;
    gui.objects[index].draglimit.x1					= 0.0;
    gui.objects[index].draglimit.y1					= 0.0;
    gui.objects[index].draglimit.x2					= 0.0;
    gui.objects[index].draglimit.y2					= 0.0;
	gui.objects[index].hovered						= false;
	gui.objects[index].clicked						= false;
	gui.objects[index].checked						= false;
	gui.objects[index].clicked_prev					= false;
	gui.objects[index].checked_prev					= false;
	gui.objects[index].visible 						= true;
	gui.objects[index].enabled 						= true;
	gui.objects[index].free 						= false;
	gui.objects[index].clickhold 					= false;
	gui.objects[index].background 					= false;
	gui.objects[index].render_text 					= true;
    gui.objects[index].render_text2 				= false;
	gui.objects[index].func							= nullFunc;
	gui.objects[index].custom1						= 0;
	gui.objects[index].custom2						= 0;
	gui.objects[index].custom3						= 0;
	gui.objects[index].custom4						= 0;
	gui.objects[index].custom5						= 0;
	gui.objects[index].custom6						= 0;

	return index; // return object id
}

/////////////////////////////////
// delete an object by id
/////////////////////////////////
function void guiObjectDelete(int index)
{
	gui.objects[index].free = true;
}

/////////////////////////////////
// find an unused slot
/////////////////////////////////
function int guiObjectFindFreeSlot()
{
	for(int i = 0; i < GUI_MAX_OBJECTS; i++)
	{
		if(gui.objects[i].free) { return i; }
	}
	return -1;
}

/////////////////////////////////
// clean out entire object pool
/////////////////////////////////
function void guiObjectsClear()
{
	// mark all slots as free
	for(int i = 0; i < GUI_MAX_OBJECTS; i++)
	{
		gui.objects[i].free = true;
	}
    guiClearScreen();
}

/////////////////////////////////
// make entire object pool disabled
/////////////////////////////////
function void guiObjectsDisable()
{
	// mark all slots as free
	for(int i = 0; i < GUI_MAX_OBJECTS; i++)
	{
		gui.objects[i].enabled = false;
	}
}

/////////////////////////////////
// move entire object pool
/////////////////////////////////
function int guiMove(fixed x, fixed y)
{
	fixed x1h;
	fixed x2h;
	fixed y1h;
	fixed y2h;
	for(int i = 0; i < GUI_MAX_OBJECTS; i++)
	{
		if(!gui.objects[i].free)
		{
			gui.objects[i].pos.x1 += x;
			gui.objects[i].pos.x2 += x;
			gui.objects[i].pos.y1 += y;
			gui.objects[i].pos.y2 += y;

			if(gui.objects[i].pos.x1 > x1h) { x1h = gui.objects[i].pos.x1; }
			if(gui.objects[i].pos.x2 > x2h) { x2h = gui.objects[i].pos.x2; }
			if(gui.objects[i].pos.y1 > y1h) { y1h = gui.objects[i].pos.y1; }
			if(gui.objects[i].pos.y2 > y2h) { y2h = gui.objects[i].pos.y2; }
		}
	}
	if(x1h >= gui.w) { return 1; }
	if(x2h <= 0.0) { return 2; }
	if(y1h >= gui.w) { return 3; }
	if(y2h <= 0.0) { return 4; }
	return 0;
}

/////////////////////////////////
// run the system
/////////////////////////////////
function void guiObjectsRun(void)
{
    // go through the object pool
    for(int i = 0; i < GUI_MAX_OBJECTS; i++)
    {
        guiObjectUpdate(i);
        guiObjectRender(i);
    }
}

/////////////////////////////////
// run object updates
/////////////////////////////////
function void guiObjectUpdate(int i)
{
	// if the object is alive
	if(!gui.objects[i].free)
	{
		// if the object is visible
		if(gui.objects[i].visible)
		{

			// keep track of the w/h of the object, these values are readonly
			gui.objects[i].size.w = gui.objects[i].pos.x2-gui.objects[i].pos.x1;
			gui.objects[i].size.h = gui.objects[i].pos.y2-gui.objects[i].pos.y1;
			gui.objects[i].size.w_half = gui.objects[i].size.w/2.0;
			gui.objects[i].size.h_half = gui.objects[i].size.h/2.0;
			gui.objects[i].center.x = gui.objects[i].pos.x1+gui.objects[i].size.w_half;
			gui.objects[i].center.y = gui.objects[i].pos.y1+gui.objects[i].size.h_half;

			// if the object is enabled
			if(gui.objects[i].enabled)
			{

				gui.objects[i].clicked_prev = gui.objects[i].clicked;
				gui.objects[i].checked_prev = gui.objects[i].checked;

				// set color as normal
				if(gui.objects[i].checked)
				{
					gui.objects[i].color.current = gui.objects[i].color.checked;
					gui.objects[i].textcolor.current = gui.objects[i].textcolor.checked;
				}
				else
				{
					gui.objects[i].color.current = gui.objects[i].color.normal;
					gui.objects[i].textcolor.current = gui.objects[i].textcolor.normal;
				}

				// if cursor is within bounds
				if(cursor.pos.x > gui.objects[i].pos.x1 && cursor.pos.x < gui.objects[i].pos.x2 && cursor.pos.y > gui.objects[i].pos.y1 && cursor.pos.y < gui.objects[i].pos.y2)
				{
					// is the object clickable?
					if(gui.objects[i].clickable)
					{
						// is the cursor dragging something?
						if(cursor.dragging == -1)
						{
							// is the objcet clicked?
							if(cursor.clicked)
							{
								// clicked color
								gui.objects[i].color.current = gui.objects[i].color.clicked;
								gui.objects[i].textcolor.current = gui.objects[i].textcolor.clicked;

								// if the hold flag is set
								if(gui.objects[i].clickhold)
								{
									// set clicked event for each frame
									gui.objects[i].clicked = true;
									if(gui.objects[i].draggable)
									{
										cursor.dragging = i;
										cursor.posdrag.x1 = cursor.pos.x - gui.objects[i].pos.x1;
										cursor.posdrag.y1 = cursor.pos.y - gui.objects[i].pos.y1;
										cursor.posdrag.x2 = gui.objects[i].size.w;
										cursor.posdrag.y2 = gui.objects[i].size.h;
									}
									gui.objects[i].func(i);
								}
								// if the hold flag is not set
								else
								{
									// if previous frame was false
									if(!cursor.clicked_prev)
									{
										// set clicked event for 1 frame
										gui.objects[i].clicked = true;

										// if the checkable flag is set
										if(gui.objects[i].checkable)
										{
											gui.objects[i].checked = !gui.objects[i].checked;
										}

										if(gui.objects[i].draggable)
										{
											cursor.dragging = i;
											cursor.posdrag.x1 = cursor.pos.x - gui.objects[i].pos.x1;
											cursor.posdrag.y1 = cursor.pos.y - gui.objects[i].pos.y1;
											cursor.posdrag.x2 = gui.objects[i].size.w;
											cursor.posdrag.y2 = gui.objects[i].size.h;
										}

										gui.objects[i].func(i);
									}
									// if previous frame was not false
									else
									{
										// clicked is false
										gui.objects[i].clicked = false;
										gui.objects[i].color.current = gui.objects[i].color.normal;
										gui.objects[i].textcolor.current = gui.objects[i].textcolor.normal;
									}
								}
							}
							// object is not clicked
							else
							{
								// clicked is false
								gui.objects[i].clicked = false;

								// if object is checked
								if(gui.objects[i].checked)
								{
									gui.objects[i].color.current = gui.objects[i].color.checked;
									gui.objects[i].textcolor.current = gui.objects[i].textcolor.checked;
								}
								else
								{
									gui.objects[i].color.current = gui.objects[i].color.normal;
									gui.objects[i].textcolor.current = gui.objects[i].textcolor.normal;
								}
							}


							// is the object hoverable?
							if(gui.objects[i].hoverable)
							{
								// if object is checked
								if(gui.objects[i].checked)
								{
									// hovered and checked color
									gui.objects[i].color.current = gui.objects[i].color.checked_hover;
									gui.objects[i].textcolor.current = gui.objects[i].textcolor.checked_hover;
								}
								// if object is not checked
								else
								{
									// hovered not checked color
									gui.objects[i].color.current = gui.objects[i].color.hover;
									gui.objects[i].textcolor.current = gui.objects[i].textcolor.hover;
								}

								// set hovered flag
								gui.objects[i].hovered = true;
							}
						}
					}
				}

				//if cursor is not within bounds
				else
				{
					// normal color
					gui.objects[i].color.current = gui.objects[i].color.normal;
					gui.objects[i].textcolor.current = gui.objects[i].textcolor.normal;

					// we are not hovered or clicked if the cursor is not within bounds
					gui.objects[i].hovered = false;
					gui.objects[i].clicked = false;

					// if object is checked
					if(gui.objects[i].checked)
					{
						gui.objects[i].color.current = gui.objects[i].color.checked;
						gui.objects[i].textcolor.current = gui.objects[i].textcolor.checked;
					}
					// if object is not checked
					else
					{
						gui.objects[i].color.current = gui.objects[i].color.normal;
						gui.objects[i].textcolor.current = gui.objects[i].textcolor.normal;
					}
				}
			}

			// if the object is disabled
			else
			{
				// disabled color
				gui.objects[i].color.current = gui.objects[i].color.disabled;
				gui.objects[i].textcolor.current = gui.objects[i].textcolor.disabled;

				// object is checked and disabled
				if(gui.objects[i].checked)
				{
					gui.objects[i].color.current = gui.objects[i].color.checked_disabled;
					gui.objects[i].textcolor.current = gui.objects[i].textcolor.checked_disabled;
				}
			}

			//////////////////////////
			// Dragging
			//////////////////////////
			if(cursor.dragging == i)
			{
				if(gui.objects[i].drag_x)
				{
					gui.objects[i].pos.x1 = cursor.pos.x - cursor.posdrag.x1;
					gui.objects[i].pos.x2 = gui.objects[i].pos.x1 + gui.objects[i].size.w;

					if(gui.objects[i].pos.x1 < gui.objects[i].draglimit.x1)
					{
						gui.objects[i].pos.x1 = gui.objects[i].draglimit.x1;
						gui.objects[i].pos.x2 = gui.objects[i].pos.x1 + gui.objects[i].size.w;
					}
					if(gui.objects[i].pos.x2 > gui.objects[i].draglimit.x2)
					{
						gui.objects[i].pos.x2 = gui.objects[i].draglimit.x2;
						gui.objects[i].pos.x1 = gui.objects[i].pos.x2 - gui.objects[i].size.w;
					}
				}
				if(gui.objects[i].drag_y)
				{
					gui.objects[i].pos.y1 = cursor.pos.y - cursor.posdrag.y1;
					gui.objects[i].pos.y2 = gui.objects[i].pos.y1 + cursor.posdrag.y2;

					if(gui.objects[i].pos.y1 < gui.objects[i].draglimit.y1)
					{
						gui.objects[i].pos.y1 = gui.objects[i].draglimit.y1;
						gui.objects[i].pos.y2 = gui.objects[i].pos.y1 + cursor.posdrag.y2;
					}
					if(gui.objects[i].pos.y2 > gui.objects[i].draglimit.y2)
					{
						gui.objects[i].pos.y2 = gui.objects[i].draglimit.y2;
						gui.objects[i].pos.y1 = gui.objects[i].pos.y2 - cursor.posdrag.y2;
					}
				}
                gui.objects[i].func(i);
			}

			//////////////////////////
			// Text
			//////////////////////////
			if(gui.objects[i].render_text)
			{
				// text x alignment
				switch(gui.objects[i].textalign.x)
				{
					// if we align the x position to the left
					case GUI_XALIGN_LEFT:
						gui.objects[i].textpos.x = gui.objects[i].pos.x1 + GUI_XALIGN_LEFT;
					break;

					// if we align the x position to the center
					case GUI_XALIGN_CENTER:
						gui.objects[i].textpos.x = gui.objects[i].pos.x1 + gui.objects[i].size.w_half + GUI_XALIGN_CENTER;
					break;

					// if we align the x position to the right
					case GUI_XALIGN_RIGHT:
						gui.objects[i].textpos.x = gui.objects[i].pos.x2 + GUI_XALIGN_RIGHT;
					break;
				}

				// text y alignment
				switch(gui.objects[i].textalign.y)
				{
					// if we align the y position to the top
					case GUI_YALIGN_TOP:
						gui.objects[i].textpos.y = gui.objects[i].pos.y1 + GUI_YALIGN_TOP;
					break;

					// if we align the y position to the center
					case GUI_YALIGN_CENTER:
						gui.objects[i].textpos.y = gui.objects[i].pos.y1 + gui.objects[i].size.h_half + GUI_YALIGN_CENTER;
					break;

					// if we align the y position to the bottom
					case GUI_YALIGN_BOTTOM:
						gui.objects[i].textpos.y = gui.objects[i].pos.y2 + GUI_YALIGN_BOTTOM;
					break;
				}
			}

			//////////////////////////
			// Text2
			//////////////////////////
			if(gui.objects[i].render_text2)
			{
				// text x alignment
				switch(gui.objects[i].textalign2.x)
				{
					// if we align the x position to the left
					case GUI_XALIGN_LEFT:
						gui.objects[i].textpos2.x = gui.objects[i].pos.x1 + GUI_XALIGN_LEFT;
					break;

					// if we align the x position to the center
					case GUI_XALIGN_CENTER:
						gui.objects[i].textpos2.x = gui.objects[i].pos.x1 + gui.objects[i].size.w_half + GUI_XALIGN_CENTER;
					break;

					// if we align the x position to the right
					case GUI_XALIGN_RIGHT:
						gui.objects[i].textpos2.x = gui.objects[i].pos.x2 + GUI_XALIGN_RIGHT;
					break;
				}

				// text y alignment
				switch(gui.objects[i].textalign2.y)
				{
					// if we align the y position to the top
					case GUI_YALIGN_TOP:
						gui.objects[i].textpos2.y = gui.objects[i].pos.y1 + GUI_YALIGN_TOP;
					break;

					// if we align the y position to the center
					case GUI_YALIGN_CENTER:
						gui.objects[i].textpos2.y = gui.objects[i].pos.y1 + gui.objects[i].size.h_half + GUI_YALIGN_CENTER;
					break;

					// if we align the y position to the bottom
					case GUI_YALIGN_BOTTOM:
						gui.objects[i].textpos2.y = gui.objects[i].pos.y2 + GUI_YALIGN_BOTTOM;
					break;
				}
			}
		}
		gui.objcount++;
	}
}

/////////////////////////////////
// run object rendering
/////////////////////////////////
function void guiObjectRender(int i)
{
	// if the object is alive
	if(!gui.objects[i].free)
	{
		// if the object is visible
		if(gui.objects[i].visible)
		{
			//////////////////////////
			// Render
			//////////////////////////

			if(gui.objects[i].render_text)
			{
				// set object's font
                if(gui.objects[i].checked)
                {
                    gui.objects[i].text_current = gui.objects[i].text_checked;
                    gui.objects[i].text_font_current = gui.objects[i].text_font_checked;
                }
                else
                {

                    if(gui.objects[i].hovered)
                    {
                        gui.objects[i].text_current = gui.objects[i].text_hovered;
                        gui.objects[i].text_font_current = gui.objects[i].text_font_hovered;
                    }
                    else
                    {
                        gui.objects[i].text_current = gui.objects[i].text;
                        gui.objects[i].text_font_current = gui.objects[i].text_font;
                    }
                }




                setFont(gui.objects[i].text_font_current);

				// check what type of text we need to print
				switch(gui.objects[i].text_type)
				{

					// print a string?
					case GUI_TEXTTYPE_STRING: 	guiPrintString(gui.objects[i].textpos.x + gui.objects[i].textoffset.x, gui.objects[i].textpos.y + gui.objects[i].textoffset.y, gui.objects[i].textcolor.current, gui.objects[i].text_current); break;

					// print an int?
					case GUI_TEXTTYPE_INT: 		guiPrintInt(gui.objects[i].textpos.x + gui.objects[i].textoffset.x, gui.objects[i].textpos.y + gui.objects[i].textoffset.y, gui.objects[i].textcolor.current, (int)gui.objects[i].text_current); break;

					// print a fixed?
					case GUI_TEXTTYPE_FIXED: 	guiPrintFixed(gui.objects[i].textpos.x + gui.objects[i].textoffset.x, gui.objects[i].textpos.y + gui.objects[i].textoffset.y, gui.objects[i].textcolor.current, (raw)gui.objects[i].text_current); break;

					// print a player name?
					case GUI_TEXTTYPE_NAME: 	guiPrintName(gui.objects[i].textpos.x + gui.objects[i].textoffset.x, gui.objects[i].textpos.y + gui.objects[i].textoffset.y, gui.objects[i].textcolor.current, gui.objects[i].text_current); break;
				}
			}

			if(gui.objects[i].render_text2)
			{
                if(gui.objects[i].checked)
                {
                    gui.objects[i].text_current2 = gui.objects[i].text_checked2;
                    gui.objects[i].text_font_current2 = gui.objects[i].text_font_checked2;
                }
                else
                {
                    if(gui.objects[i].hovered)
                    {
                        gui.objects[i].text_current2 = gui.objects[i].text_hovered2;
                        gui.objects[i].text_font_current2 = gui.objects[i].text_font_hovered2;
                    }
                    else
                    {
                        gui.objects[i].text_current2 = gui.objects[i].text2;
                        gui.objects[i].text_font_current2 = gui.objects[i].text_font2;
                    }

                }


                setFont(gui.objects[i].text_font_current2);

				// check what type of text we need to print
				switch(gui.objects[i].text_type2)
				{
					// print a string?
					case GUI_TEXTTYPE_STRING: 	guiPrintString(gui.objects[i].textpos2.x + gui.objects[i].textoffset2.x, gui.objects[i].textpos2.y + gui.objects[i].textoffset2.y, gui.objects[i].textcolor.current, gui.objects[i].text_current2); break;

					// print an int?
					case GUI_TEXTTYPE_INT: 		guiPrintInt(gui.objects[i].textpos2.x + gui.objects[i].textoffset2.x, gui.objects[i].textpos2.y + gui.objects[i].textoffset2.y, gui.objects[i].textcolor.current, (int)gui.objects[i].text_current2); break;

					// print a fixed?
					case GUI_TEXTTYPE_FIXED: 	guiPrintFixed(gui.objects[i].textpos2.x + gui.objects[i].textoffset2.x, gui.objects[i].textpos2.y + gui.objects[i].textoffset2.y, gui.objects[i].textcolor.current, (raw)gui.objects[i].text_current2); break;

					// print a player name?
					case GUI_TEXTTYPE_NAME: 	guiPrintName(gui.objects[i].textpos2.x + gui.objects[i].textoffset2.x, gui.objects[i].textpos2.y + gui.objects[i].textoffset2.y, gui.objects[i].textcolor.current, gui.objects[i].text_current2); break;
				}
			}
		}
	}
}

////////////////////////////////////////////////////////
// Helpers
////////////////////////////////////////////////////////

// clears all hudmessage ids, this fixes the slight delay in clearing objects
function void guiClearScreen(void)
{
	for(int i = 0; i < GUI_MAX_OBJECTS; i++)
    {
    	hudmessage(s:""; 0, i, 0, 0.0, 0.0, 0.0);
    }
}


// shorter alias for hudmessage with auto ID
function int guiPrintString(fixed x, fixed y, str color, str msg)
{
	gui.nextid++;
	hudmessage(s:"\c[", s:color, s:"]", s:msg; 0, gui.nextid, 0, x, y, 0.1);
	return gui.nextid;
}

function int guiPrintInt(fixed x, fixed y, str color, int msg)
{
	gui.nextid++;
	hudmessage(s:"\c[", s:color, s:"]", i:msg; 0, gui.nextid, 0, x, y, 0.1);
	return gui.nextid;
}

function int guiPrintFixed(fixed x, fixed y, str color, fixed msg)
{
	gui.nextid++;
	hudmessage(s:"\c[", s:color, s:"]", f:msg; 0, gui.nextid, 0, x, y, 0.1);
	return gui.nextid;
}


function int guiPrintName(fixed x, fixed y, str color, str msg)
{
	gui.nextid++;
	switch(msg)
	{
		case "0": hudmessage(s:"\c[", s:color, s:"]", n:0; 0, gui.nextid, 0, x, y, 0.1); break;
		case "1": hudmessage(s:"\c[", s:color, s:"]", n:1; 0, gui.nextid, 0, x, y, 0.1); break;
		case "2": hudmessage(s:"\c[", s:color, s:"]", n:2; 0, gui.nextid, 0, x, y, 0.1); break;
		case "3": hudmessage(s:"\c[", s:color, s:"]", n:3; 0, gui.nextid, 0, x, y, 0.1); break;
		case "4": hudmessage(s:"\c[", s:color, s:"]", n:4; 0, gui.nextid, 0, x, y, 0.1); break;
		case "5": hudmessage(s:"\c[", s:color, s:"]", n:5; 0, gui.nextid, 0, x, y, 0.1); break;
		case "6": hudmessage(s:"\c[", s:color, s:"]", n:6; 0, gui.nextid, 0, x, y, 0.1); break;
		case "7": hudmessage(s:"\c[", s:color, s:"]", n:7; 0, gui.nextid, 0, x, y, 0.1); break;
		case "8": hudmessage(s:"\c[", s:color, s:"]", n:8; 0, gui.nextid, 0, x, y, 0.1); break;
	}
	return gui.nextid;
}

function int guiPrintHex(fixed x, fixed y, str color, int msg)
{
	gui.nextid++;
	hudmessage(s:"\c[", s:color, s:"]", x:msg; 0, gui.nextid, 0, x, y, 0.1);
	return gui.nextid;
}

function int guiPrintBinary(fixed x, fixed y, str color, int msg)
{
	gui.nextid++;
	hudmessage(s:"\c[", s:color, s:"]", b:msg; 0, gui.nextid, 0, x, y, 0.1);
	return gui.nextid;
}

function int guiPrintChar(fixed x, fixed y, str color, int msg)
{
	gui.nextid++;
	hudmessage(s:"\c[", s:color, s:"]", c:msg; 0, gui.nextid, 0, x, y, 0.1);
	return gui.nextid;
}

function int guiPrintKey(fixed x, fixed y, str color, int msg)
{
	gui.nextid++;
	hudmessage(s:"\c[", s:color, s:"]", x:msg; 0, gui.nextid, 0, x, y, 0.1);
	return gui.nextid;
}




////////////////////////////////////////////////////////
// Scripts
////////////////////////////////////////////////////////
script "CL_GUI" enter clientside
{
	if(GetLevelInfo(LEVELINFO_LEVELNUM) != 99) { terminate; }

	// client check
	if(!clientCheck()) { terminate; }

	// setup gui
	guiInit(0, 0);
    guiObjectsClear();
    guiCursorInit();

	int state = 0;

	while(1)
	{
		// run cursor
		guiCursorRun();

        // run all gui objects
        guiObjectsRun();

		// reset hud ID counter
		gui.nextid = 0;
		gui.objcount = 0;
		delay(1);
		cursor.clicked_prev = cursor.clicked;
	}
}


