version "4.10"
/*
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
    Actor sky_spot;
    Actor play_spot;
    Vector3 player_spot;
    double dist;

    Actor sky_box;

    Default
    {
        RenderStyle "None";
        +NOINTERACTION;
        +INVISIBLE;
       // +CLIENTSIDEONLY;
    }

    override void PostBeginPlay()
    {
        Super.PostBeginPlay();

        // find the skybox center
        foreach(Actor obj : level.CreateActorIterator(300))
        {
            if(obj)
            {
                sky_spot = obj;
                break;
            }
        }

        // find the play area center
        foreach(Actor obj : level.CreateActorIterator(301))
        {
            if(obj)
            {
                play_spot = obj;
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
        TextureID uzdoom_detector = TexMan.CheckForTexture("skymist1");
        if(!uzdoom_detector.isValid())
        {
            Destroy();
        }
    }

    override void Tick()
    {
        if(!sky_box) { return; }
        if(!players[consoleplayer].mo) { return; }
        let player = players[consoleplayer].mo;
        dist = player.Distance3D(play_spot) / 16;

        int x = sky_spot.pos.x + (cos(AngleTo(sky_box) * dist));
        int y = sky_spot.pos.y + (sin(AngleTo(sky_box) * dist));
        int z = sky_spot.pos.z + dist;

        //sky_box.SetOrigin((x, y, z), true);
    }
}*/