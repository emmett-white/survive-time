ADMIN_COMMAND:[2]warn(playerid, const params[])
{
    extract params -> new targetid, string: reason[MAX_REASON_TEXT]; else {
        return usage(playerid, "/warn [targetid] [reason]");
    }

    Player_SetWarns(targetid, (Player_GetWarns(targetid) + 1));

    if (Player_GetWarns(targetid) == (MAX_WARNS + 1)) {
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

ADMIN_COMMAND:[2]goto(playerid, const params[])
{
    if (isnull(params)) {
        return usage(playerid, "/goto [targetid]");
    }

    static
        x,
        y,
        z;

    GetPlayerPos(strval(params), Float: x, Float: y, Float: z);
    SetPlayerPos(playerid, Float: x, Float: y, Float: z);

    fmt_info(strval(params), "Admin %s has teleported to you.", ReturnPlayerName(playerid));
    fmt_info(strval(params), "You've teleported to the player %s.", ReturnPlayerName(strval(params)));

    return 1;
}

ADMIN_COMMAND:[2]get(playerid, const params[])
{
    if (isnull(params)) {
        return usage(playerid, "/get [targetid]");
    }

    static
        x,
        y,
        z;

    GetPlayerPos(playerid, Float: x, Float: y, Float: z);
    SetPlayerPos(strval(params), Float: x, Float: y, Float: z);

    fmt_info(strval(params), "Admin %s teleported you to him.", ReturnPlayerName(playerid));
    fmt_info(strval(params), "You've teleported player %s to you.", ReturnPlayerName(strval(params)));

    return 1;
}