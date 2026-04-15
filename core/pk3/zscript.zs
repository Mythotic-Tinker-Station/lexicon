version "4.14.3"


// zscript version of the VR 3d skybox
Class Event_3DSky : EventHandler
{
    override void WorldLoaded(WorldEvent e)
    {
        if(Level.mapname == "VR")
        {
            foreach(Actor obj : level.CreateActorIterator(302))
            {
                if(obj)
                {
                    obj.Spawn("Skybox_3D_Controller", obj.pos, NO_REPLACE);
                    break;
                }
            }
        }
    }
}

Class Skybox_3D_Controller : SkyViewpoint
{
    // tag 300 = skybox center
    // tag 301 = play area center
    // tag 302 = skybox 
    Vector3 sky_spot;
    Vector3 play_spot;
    Vector3 player_spot;
    Vector3 delta;

    Actor sky_box;

    Default
    {
        RenderStyle "None";
        +CLIENTSIDE;
        +NOINTERACTION;
        +INVISIBLE;
    }

    override void PostBeginPlay()
    {
        Super.PostBeginPlay();

        // find the skybox center
        foreach(Actor obj : level.CreateActorIterator(300))
        {
            if(obj)
            {
                sky_spot = obj.pos;
                break;
            }
        }

        // find the play area center
        foreach(Actor obj : level.CreateActorIterator(301))
        {
            if(obj)
            {
                play_spot = obj.pos;
                break;
            }
        }

        // find the skybox itself
        foreach(Actor obj : level.CreateActorIterator(302))
        {
            if(obj)
            {
                sky_box = obj;
                break;
            }
        }
    }

    override void Tick()
    {
        if(!sky_box) { return; }
        if(!players[consoleplayer].mo) { return; }
        player_spot = players[consoleplayer].mo.pos;
        delta = player_spot - play_spot;
        sky_box.SetOrigin(sky_spot - (delta.x, delta.y, -delta.z) / 16, true);
    }
}