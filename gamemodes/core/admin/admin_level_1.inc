ACMD:[1]ban(playerid, const params[])
{
    static
        targetid,
        reason[64];

    if (sscanf(params, "rs[64]", targetid, reason))
        return usage(playerid, "/ban [targetid] [reason]");

    ban_player(targetid, playerid, reason);

    return 1;
}

ACMD:[1]unban(playerid, const params[])
{
    static
        name[MAX_PLAYER_NAME];

    if (sscanf(params, "s[" #MAX_PLAYER_NAME "]", name))
        return usage(playerid, "/unban [name]");

    unban_player(playerid, name);

    return 1;
}

ACMD:[1]kick(playerid, const params[])
{
    static
        targetid,
        reason[64];

    if (sscanf(params, "rs[64]", targetid, reason))
        return usage(playerid, "/kick [targetid] [reason]");

    if (targetid == playerid)
        return err(playerid, "You can't kick yourself!");

    GameTextForPlayer(targetid, "~r~KICKED", 10000, 3);

    va_SendClientMessageToAll(
        X11_RED, "* Kick: "WHITE"Player %s has been kicked from this server. Reason: %s",
        ReturnPlayerName(targetid), reason
    );

    Kick(targetid);

    return 1;
}

ACMD:[1]cc(playerid, const params[])
{
    if (isnull(params))
        return usage(playerid, "/cc [line(s)]");

    for (new i = 0; i < strval(params); ++i)
        SendClientMessageToAll(-1, " ");

    SendClientMessageToAll(-1, "Chatbox cleared.");

    return 1;
}

ACMD:[1]mute(playerid, const params[])
{
    static
        targetid,
        minutes,
        reason[MAX_REASON_TEXT];

    if (sscanf(params, "rs["#MAX_REASON_TEXT"]i", targetid, reason, minutes))
        return usage(playerid, "/mute [targetid] [reason] [minutes]");

    mute_player(playerid, targetid, reason, minutes);
    
    return 1;
}

ACMD:[1]unmute(playerid, const params[])
{
    if (isnull(params))
        return usage(playerid, "/unmute [targetid]");

    if (!IsPlayerConnected(strval(params)))
        return 0;

    unmute_player(playerid, strval(params));

    return 1;
}