CMD:warns(playerid, const params[])
{
    if (!player_warn_num[playerid])
        return err(playerid, "You aren't warned!");

    fmt_info(playerid, "You have %d warn(s).", player_warn_num[playerid]);

    for (new i = 0; i < player_warn_num[playerid]; ++i)
        fmt_info(playerid, "Warn %d | Reason: %s", (i + 1), player_warn_reason[playerid][i]);

    return 1;
}