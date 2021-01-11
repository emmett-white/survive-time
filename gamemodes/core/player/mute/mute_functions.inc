mute_player(const playerid, const targetid, const string: reason[], minutes)
{
    // if (targetid == playerid)
    //     return err(playerid, "You can't mute yourself!");

    if (get_player_muted(targetid))
        return err(playerid, "That player is already muted!");

    if (!(1 <= minutes <= MAX_MUTE_MINUTES))
        return fmt_err(playerid, "Minutes can't be less than 0 and more than %d!", MAX_MUTE_MINUTES);

    set_player_muted(targetid, 1);
    set_player_muted_mins(targetid, minutes);

    va_SendClientMessageToAll(
        X11_RED, "* Mute: "WHITE"Player %s has been muted. Reason: %s",
        ReturnPlayerName(targetid), reason
    );

    return 1;
}