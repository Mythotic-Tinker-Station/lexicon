function fixed abs (fixed x)
{
    if (x < 0.0)
        return -x;

    return x;
}


function fixed normalize(fixed v, fixed min, fixed max)
{
	return v * (max - min) + min;
}