



script "UR11Fix" enter
{
    // if we are on the level we wanna fix
    if(!StrIcmp(StrParam(n:PRINTNAME_LEVEL), "UR__11"))
    {
		// wait for the cyberdemon to be killed
        while(ThingCountName("CyberDemon",0) > 0) { delay(35); }

		// raise exit
		Ceiling_RaiseToNearest(666, 6);
    }
}