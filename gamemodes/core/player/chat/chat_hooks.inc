hook OnPlayerText(playerid, text[])
{
    if (char_muted[playerid])
        return fmt_err(playerid, "You're muted for %d minutes.", char_muted_mins[playerid]), 0;

    // Admin chat
    if (IsPlayerAdmin(playerid) || get_admin_level(playerid) >= 1 && text[0] == '#')
        return va_SendClientMessageToAll(
            X11_RED, "(%d) %s: "WHITE"%s", playerid, ReturnPlayerName(playerid), text
        ), 0;

    va_SendClientMessageToAll(
        X11_GRAY, "(%d) %s: "WHITE"%s", playerid, ReturnPlayerName(playerid), text
    );

    return Y_HOOKS_CONTINUE_RETURN_0;
}