ADMIN_COMMAND:[e_ADMIN_LEVEL_3]settime(playerid, const params[])
{
    if (isnull(params)) {
        return usage(playerid, "/settime [time (1-24)]");
    }

    if (!isnumeric(params)) {
        return 0;
    }

    if (!(1 <= strval(params) <= 24)) {
        return err(playerid, "Invalid time (1-24)!");
    }

    SetWorldTime(strval(params));

    return 1;
}

ADMIN_COMMAND:[e_ADMIN_LEVEL_3]setweather(playerid, const params[])
{
    if (isnull(params)) {
        return usage(playerid, "/setweather [time (0-255)]");
    }

    if (!isnumeric(params)) {
        return 0;
    }

    if (!(0 <= strval(params) <= 255)) {
        return err(playerid, "Invalid time (0-255)!");
    }

    SetWeather(strval(params));

    return 1;
}