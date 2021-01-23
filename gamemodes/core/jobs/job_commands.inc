PLAYER_COMMAND:takejob(playerid, const params[])
{
    if (Player_GetJob(playerid)) {
        return err(playerid, "You already have a job! (/jobquit)");
    }

    if (IsPlayerInRangeOfPoint(playerid, Float: 2.0, Float: 1222.0521, Float: -1812.2341, Float: 16.5938)) {
        Player_SetJob(playerid, _:E_PLAYER_JOB_BUS);
        info(playerid, "Your current job is a bus driver.");
    }

    return 1;
}

PLAYER_COMMAND:equipment(playerid, const params[])
{
    if (!Player_GetJob(playerid)) {
        return err(playerid, "You don't have a job!");
    }

    if (Player_GetJobEquipment(playerid)) {
        Player_SetJobEquipment(playerid, false);
        SetPlayerSkin(playerid, Player_GetSkin(playerid));
    }

    if (IsPlayerInRangeOfPoint(playerid, Float: 2.0, Float: 1216.5745, Float: -1812.1322, Float: 16.5938)) {
        SetPlayerSkin(playerid, 61);
        Player_SetJobEquipment(playerid);
    }

    return 1;
}

PLAYER_COMMAND:jobquit(playerid, const params[])
{
    if (!Player_GetJob(playerid)) {
        return err(playerid, "You don't have a job!");
    }

    if (Player_GetJobEquipment(playerid)) {
        Player_SetJobEquipment(playerid, false);
    }

    if (Player_GetJob(playerid)) {
        Player_SetJob(playerid, _:E_PLAYER_JOB_NONE);
        SetPlayerSkin(playerid, Player_GetSkin(playerid));
    }

    return 1;
}