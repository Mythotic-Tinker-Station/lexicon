#library "command"
#include "../../compiler/lib/zcommon.h"

private int currentMapset;

private function bool StrStartsWith(str str1, str str2)
{
    int len = StrLen(str2);

    if (len > StrLen(str1))
    {
        return false;
    }

    return !StrIcmp(str1, str2, len);
}

private function int GetCurrentMapset(void)
{
    str mapset = StrParam(n:PRINTNAME_LEVEL);

    if (StrStartsWith(mapset, "CS0") || StrStartsWith(mapset, "CS2"))
    {
        return 2;
    }
    else if (StrStartsWith(mapset, "SC2"))
    {
        return 3;
    }
    else if (StrStartsWith(mapset, "MAY"))
    {
        return 4;
    }
    else if (StrStartsWith(mapset, "HC0") || StrStartsWith(mapset, "HC1"))
    {
        return 5;
    }
    else if (StrStartsWith(mapset, "VAL"))
    {
        return 6;
    }
    else if (StrStartsWith(mapset, "EP1") || StrStartsWith(mapset, "EP2"))
    {
        return 7;
    }
    else if (StrStartsWith(mapset, "AA1"))
    {
        return 8;
    }
    else if (StrStartsWith(mapset, "SD6") || StrStartsWith(mapset, "SD7"))
    {
        return 9;
    }

    return 1;
}

script "Maniac" (void)
{
    if (!currentMapset)
    {
        currentMapset = GetCurrentMapset();
    }

    SetResultValue(currentMapset);
}