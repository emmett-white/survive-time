CMD:warns(playerid, const params[])
{
    if (!char_warn_num[playerid])
        return err(playerid, "You aren't warned!");

    fmt_info(playerid, "You have %d warn(s).", char_warn_num[playerid]);
    
    return 1;
}