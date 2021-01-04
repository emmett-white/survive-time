CMD:warn(playerid, const params[])
{
    if (!player_warn_num[playerid])
        return err(playerid, "You aren't warned!");

    fmt_info(playerid, "You have %d warn(s).", player_warn_num[playerid]);

    for (new i = 0; i < player_warn_num[playerid]; ++i)
        fmt_info(playerid, "Warn %d | Reason: %s", (i + 1), player_warn_reason[playerid][i]);

    return 1;
}

// CMD:givewarn(playerid, const params[])
// {
//     ++player_warn_num[playerid];

//     player_warn_reason[playerid][0] = "Test1";
//     player_warn_reason[playerid][1] = "Test2";
//     player_warn_reason[playerid][2] = "Test3";
//     player_warn_reason[playerid][3] = "Test4";

//     if (player_warn_num[playerid] == 5)
//         return info(playerid, "Banned");

//     return 1;
// }