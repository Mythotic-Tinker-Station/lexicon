


function fixed dist2(fixed x1, fixed y1, fixed z1, fixed x2,fixed y2, fixed z2)
{
    int x, y, z;
    x = int(x1 - x2); // Convert fixed point to integer
    y = int(y1 - y2);
    z = int(z1 - z2);
    return fixed(Sqrt( x*x + y*y + z*z ));
}

// tid 300 = skybox center(center reference point inside the skybox)
// tid 301 = level center(center reference point inside the level)
// tid 302 = skybox(skybox viewpoint tag)

script "SkyBox" enter clientside
{
    Thing_ChangeTid(0, playernumber()+1337);
    SetActivator(302);
    fixed cx1 = GetActorX(300);
    fixed cy1 = GetActorY(300);
    fixed cz1 = GetActorZ(300);
    fixed cx2 = GetActorX(301);
    fixed cy2 = GetActorY(301);
    fixed cz2 = GetActorZ(301);

    fixed px = GetActorX(1337);
    fixed py = GetActorY(1337);
    fixed pz = GetActorZ(1337);

    fixed dx = cx2 - px;
    fixed dy = cy2 - py;
    fixed dz = cz2 - pz;

    fixed a = 0.0;

    fixed sx = 0.0;
    fixed sy = 0.0;
    fixed sz = 0.0;

    fixed d = 0.0;

    while(1)
    {
        // if any map scripts move the reference points, we should know about it
        cx1 = GetActorX(300);
        cy1 = GetActorY(300);
        cz1 = GetActorZ(300);
        cx2 = GetActorX(301);
        cy2 = GetActorY(301);
        cz2 = GetActorZ(301);

        px = GetActorX(1337);
        py = GetActorY(1337);
        pz = GetActorZ(1337);

        dx = px - cx2;
        dy = py - cy2;
        dz = pz - cz2;

        a = VectorAngle(dx, dy);
        d = dist2(px, py, 0.0, cx2, cy2, 0.0) / 8.0;

        sx = cx1 + (cos(a)*d);
        sy = cy1 + (sin(a)*d);
        sz = cz1 + dz/8.0;

        Warp(302, sx, sy, sz, 0.0, WARPF_INTERPOLATE|WARPF_ABSOLUTEPOSITION|WARPF_ABSOLUTEANGLE|WARPF_NOCHECKPOSITION);

        delay(1);
    }
}

/*
int cycle[12][3] =
{
	{ 0xFF, 0xFF, 0x00 },
	{ 0x7F, 0xFF, 0x00 },
	{ 0x00, 0xFF, 0x00 },
	{ 0x00, 0xFF, 0x7F },
	{ 0x00, 0xFF, 0xFF },
	{ 0x00, 0x7F, 0xFF },
	{ 0x00, 0x00, 0xFF },
	{ 0x7F, 0x00, 0xFF },
	{ 0xFF, 0x00, 0xFF },
	{ 0xFF, 0x00, 0x7F },
	{ 0xFF, 0x00, 0x00 },
	{ 0xFF, 0x7F, 0x00 }
};


script 1 open clientside
{
	int i = 0;
	int i2 = 1;
	int r = 0;
	int g = 0;
	int b = 0;
	while(1)
	{
		int t = 0;
		while(t < 1.0)
		{
			t += 0.005;

			r = cycle[i][0]+lerpf(cycle[i][0], cycle[i2][0], t);
			g = cycle[i][1]+lerpf(cycle[i][1], cycle[i2][1], t);
			b = cycle[i][2]+lerpf(cycle[i][2], cycle[i2][2], t);

			// lazy inaccuracy fix
			if(r > 255) { r = 255; }
			if(g > 255) { g = 255; }
			if(b > 255) { b = 255; }
			if(r < 0) { r = 0; }
			if(g < 0) { g = 0; }
			if(b < 0) { b = 0; }

			Sector_SetColor(8, r, g, b);
			Sector_SetColor(3, r, g, b);
			Sector_SetColor(1, r, g, b);
			delay(1);
		}
		i++;
		i2 = i+1;
		if(i > 11) { i = 0; i2 = 1; }
		if(i2 > 11) { i2 = 0; }
	}
}
*/










