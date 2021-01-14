ptask mute_timer[60000](playerid)
{
    if (get_player_muted(playerid)) {
        set_player_muted_mins(playerid, (get_player_muted_mins(playerid) - 1));
    }

    if (!get_player_muted_mins(playerid)) {
        set_player_muted(playerid, 0);
    }
}