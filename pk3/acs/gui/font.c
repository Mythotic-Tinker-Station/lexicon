strict namespace Font
{
	struct font
	{
		str name;
        fixed cwidth;
        fixed cheight;
        fixed cwidthhalf;
        fixed cheighthalf;        
	};

    struct font fonts[16];
    int font_count = -1;

    int font_fancybig;
    int font_fancysmall;
    int font_lexiconbig;

    function int Create(str name, fixed cwidth, fixed cheight)
	{   
        font_count++;
        fonts[font_count].name = name;
        fonts[font_count].cwidth = cwidth;
        fonts[font_count].cheight = cheight;
        fonts[font_count].cwidthhalf = cwidth/2.0;
        fonts[font_count].cheighthalf = cheight/2.0;

        return font_count;
    }

    function str GetName(int id)                 { return fonts[id].name; }
    function fixed GetCharWidth(int id)          { return fonts[id].cwidth; }
    function fixed GetCharHeight(int id)         { return fonts[id].cheight; }
    function fixed GetCharWidthHalf(int id)      { return fonts[id].cwidthhalf; }
    function fixed GetCharHeightHalf(int id)     { return fonts[id].cheighthalf; }


    function void Set(int id)
    {
        SetFont(fonts[id].name);
    }

    function void Init()
	{    
        font_fancybig = Font::Create("BIGFONT", 16.0, 16.0);
        font_fancysmall = Font::Create("SMALLFONT", 8.0, 9.0);
        font_lexiconbig = Font::Create("LXBIGFONT", 18.0, 32.0);
    }    
}