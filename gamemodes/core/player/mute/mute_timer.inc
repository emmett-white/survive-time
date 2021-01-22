ptask mute_timer[60000](playerid)
{
    if (Player_GetMuted(playerid)) {
        Player_SetMutedMins(playerid, (Player_GetMutedMins(playerid) - 1));
    }

    if (!Player_GetMutedMins(playerid)) {
        Player_SetMutedMins(playerid, 0);
    }
}