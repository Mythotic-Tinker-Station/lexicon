strict namespace Font
{
	struct font
	{
		str name;
        fixed cwidth;
        fixed cheight;
	};

    struct font fonts[16];
    int font_count = 0;

    int font_fancybig;
    int font_fancysmall;

    function int Create(str name, fixed cwidth, fixed cheight)
	{    
        fonts[font_count].name = name;
        fonts[font_count].cwidth = cwidth;
        fonts[font_count].cwidth = cheight;
        font_count++;
        return font_count;
    }

    function str GetName(int id)               { return fonts[id].name; }
    function fixed GetCharWidth(int id)          { return fonts[id].cwidth; }
    function fixed GetCharHeight(int id)         { return fonts[id].cheight; }

    function void Set(int id)
    {
        setFont(fonts[id].name);
    }

    function void Init()
	{    
        font_fancybig = Font::Create("FANCYBIG", 16.0, 16.0);
        font_fancysmall = Font::Create("FANCYSMALL", 8.0, 9.0);
    }    
}