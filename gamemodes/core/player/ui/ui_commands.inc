CMD:ui(playerid, const params[])
{
    ui_create_player_textdraws(playerid, (get_player_ui_status(playerid) ? (false) : (true)));

    return 1;
}