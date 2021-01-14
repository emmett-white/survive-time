CMD:warns(playerid, const params[])
{
    if (!get_player_warns(playerid)) {
        return err(playerid, "You aren't warned!");
    }

    fmt_info(playerid, "You have %d warn(s).", get_player_warns(playerid));
    
    return 1;
}