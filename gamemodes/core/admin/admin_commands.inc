ACMD:[4 && !IsPlayerAdmin(playerid)]setadmin(playerid, const params[])
{
    static
        targetid,
        level,
        code;


    if (sscanf(params, "rii", targetid, level, code))
        return usage(playerid, "/setadmin [targetid] [level] [code]");

    
    set_admin_level(targetid, playerid, level, code);

    return 1;
}

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