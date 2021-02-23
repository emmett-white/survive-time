/**
  * <param name="playerid">admin who will mute player</param>
  * <param name="targetid">player who will be muted</param>
  * <param name="reason">the reason why player will be muted</param>
  * <param name="minutes">the time how long the player will be muted</param>
*/
stock MutePlayer(const playerid, const targetid, const string: reason[], minutes)
{
    if (targetid == playerid)
        return err(playerid, "You can't mute yourself!");

    if (Player_GetMuted(targetid)) {
        return err(playerid, "That player is already muted!");
    }

    if (!(1 <= minutes <= MAX_MUTE_MINUTES)) {
        return fmt_err(playerid, "Minutes can't be less than 0 and more than %d!", MAX_MUTE_MINUTES);
    }

    Player_SetMuted(targetid, 1);
    Player_SetMutedMins(targetid, minutes);

    va_SendClientMessageToAll(
        X11_RED, "* Mute: "WHITE"Player %s has been muted. Reason: %s",
        ReturnPlayerName(targetid), reason
    );

    return 1;
}

stock UnMutePlayer(const playerid, const targetid)
{
    if (!Player_GetMuted(targetid)) {
        return err(playerid, "That player isn't muted!");
    }

    Player_SetMuted(targetid, 0);
    Player_SetMutedMins(targetid, 0);

    va_SendClientMessageToAll(
        X11_RED, "* Un-Mute: "WHITE"Player %s is no longer muted!", ReturnPlayerName(targetid)  
    );

    return 1;
}