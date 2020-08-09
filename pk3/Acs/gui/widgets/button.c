


strict namespace button
{
	function int Create(fixed x1, fixed y1, fixed x2, fixed y2)
	{
		int id = Widgets.Create();
		Widgets.obj[id].clickable = true;
		Widgets.obj[id].hoverable = true;
		Widgets.obj[id].func_update = buttonUpdate;
		Widgets.obj[id].pos.x1 = x1;
		Widgets.obj[id].pos.y1 = y1;
		Widgets.obj[id].pos.x2 = x2;
		Widgets.obj[id].pos.y2 = y2;

		// left corner image
		Widgets.obj[id].images[0] = Screen.ImageCreate(Widgets.obj[id].pos.x1, Widgets.obj[id].pos.y1, "Lime", Screen.XALIGN_LEFT, Screen.YALIGN_TOP);

		// filler images
		for(int i = 2; i < int(Widgets.obj[id].size.w)/28; i++)
		{
			Widgets.obj[id].images[i] = Screen.ImageCreate(Widgets.obj[id].pos.x1+(fixed(i)*28.0), Widgets.obj[id].pos.y1, "Lime", Screen.XALIGN_LEFT, Screen.YALIGN_TOP);
		}

		// right corner image
		Widgets.obj[id].images[31] = Screen.ImageCreate(Widgets.obj[id].pos.x2, Widgets.obj[id].pos.y1, "Lime", Screen.XALIGN_RIGHT, Screen.YALIGN_TOP);

		return id;
	}

	function void buttonUpdate(int id)
	{
		// left corner image
		Screen.ImageDraw(Widgets.obj[id].images[0], "UIFONT", "a");

		// filler images
		for(int i = 2; i < int(Widgets.obj[id].size.w-32.0)/28; i++)
		{
			Screen.ImageDraw(Widgets.obj[id].images[i], "UIFONT", "b");
		}

		// right corner image
		Screen.ImageDraw(Widgets.obj[id].images[31], "UIFONT", "c");
	}
}