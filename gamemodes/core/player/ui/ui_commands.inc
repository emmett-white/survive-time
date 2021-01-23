PLAYER_COMMAND:ui(playerid, const params[])
{
    UI_CreatePlayerTextDraws(playerid, (Player_GetUIStatus(playerid) ? (false) : (true)));

    return 1;
}