ACMD:[2]warn(playerid, const params[])
{
    extract params -> new targetid, string: reason[MAX_REASON_TEXT]; else
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

ACMD:[2]goto(playerid, const params[])
{
    if (isnull(params))
        return usage(playerid, "/goto [targetid]");

    if (strval(params) == playerid)
        return 0;

    static
        x,
        y,
        z;

    GetPlayerPos(strval(params), Float: x, Float: y, Float: z);
    SetPlayerPos(playerid, Float: x, Float: y, Float: z);

    return 1;
}

ACMD:[2]get(playerid, const params[])
{
    if (isnull(params))
        return usage(playerid, "/get [targetid]");

    if (strval(params) == playerid)
        return 0;

    static
        x,
        y,
        z;

    GetPlayerPos(playerid, Float: x, Float: y, Float: z);
    SetPlayerPos(strval(params), Float: x, Float: y, Float: z);

    return 1;
}