hook OnPlayerText(playerid, text[])
{
    if (Player_GetMuted(playerid)) {
        return fmt_err(playerid, "You're muted for %d minutes.", Player_GetMutedMins(playerid)), 0;
    }

    // Admin chat
    if (IsPlayerAdmin(playerid) || Admin_GetLevel(playerid) >= 1 && text[0] == '#') {
        return va_SendClientMessageToAll(
            X11_RED, "(%d) %s: "WHITE"%s", playerid, ReturnPlayerName(playerid), text
        ), 0;
    }

    va_SendClientMessageToAll(
        X11_GRAY, "(%d) %s: "WHITE"%s", playerid, ReturnPlayerName(playerid), text
    );

    return Y_HOOKS_CONTINUE_RETURN_0;
}