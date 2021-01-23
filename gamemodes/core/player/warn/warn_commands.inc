PLAYER_COMMAND:warns(playerid, const params[])
{
    if (!Player_GetWarns(playerid)) {
        return err(playerid, "You aren't warned!");
    }

    fmt_info(playerid, "You have %d warn(s).", Player_GetWarns(playerid));
    
    return 1;
}