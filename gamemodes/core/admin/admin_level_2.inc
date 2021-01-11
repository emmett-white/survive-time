ACMD:[2]warn(playerid, const params[])
{
    static
        targetid,
        reason[64];

    if (sscanf(params, "rs[64]", targetid, reason))
        return usage(playerid, "/warn [targetid] [reason]");

    ++char_warn_num[targetid];

    if (char_warn_num[targetid] == (MAX_WARNS + 1)) {
        va_SendClientMessageToAll(
            X11_RED, "* Ban: "WHITE"Player %s has been banned (5 warns).", ReturnPlayerName(targetid)
        );
    
        wait_ms(1000);
        BanEx(targetid, "Max warns (5).");

        return 1;
    }

    va_SendClientMessageToAll(
        X11_RED, "* Warn: "WHITE"Player %s has been warned. Reason: %s",
        ReturnPlayerName(targetid), reason
    );

    return 1;
}