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

ACMD:[2]warn(playerid, const params[])
{
    static
        targetid,
        reason[64];

    if (sscanf(params, "rs[64]", targetid, reason))
        return usage(playerid, "/warn [targetid] [reason]");

    ++player_warn_num[targetid];

    if (player_warn_num[targetid] == (MAX_WARNS + 1)) {
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

ACMD:[MAX_ADMIN_LEVEL]givemoney(playerid, const params[])
{
    static
        targetid,
        amt;

    if (sscanf(params, "ri", targetid, amt))
        return usage(playerid, "/givemoney [targetid] [amount]");

    if (!(1 <= amt <= 1000000))
        return err(playerid, "You can't give less than $1 and more than $1.000.000!");

    char_money[targetid] += amt;
    GivePlayerMoney(targetid, amt);

    new String: str_query_money_add = str_format(
        "UPDATE characters SET char_money = '%d' WHERE char_id = '%d'", amt, char_id[targetid]
    );

    mysql_tquery_s(MySQL_GetHandle(), str_query_money_add);

    fmt_info(playerid, "You gave $%d to %s.", amt, ReturnPlayerName(targetid));
    fmt_info(targetid, "Admin %s gave you $%d.", ReturnPlayerName(playerid), amt);

    return 1;
}