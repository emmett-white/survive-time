ACMD:[MAX_ADMIN_LEVEL && !IsPlayerAdmin(playerid)]setadmin(playerid, const params[])
{
    extract params -> new targetid, level, code; else
        return usage(playerid, "/setadmin [targetid] [level] [code]");

    set_admin_level(targetid, playerid, level, code);

    return 1;
}

ACMD:[MAX_ADMIN_LEVEL]givemoney(playerid, const params[])
{
    extract params -> new targetid, amt; else
        return usage(playerid, "/givemoney [targetid] [amount]");

    if (!(1 <= amt <= 1000000))
        return err(playerid, "You can't give less than $1 and more than $1.000.000!");

    set_player_money(playerid, amt);
    GivePlayerMoney(targetid, amt);

    fmt_info(playerid, "You gave $%d to %s.", amt, ReturnPlayerName(targetid));
    fmt_info(targetid, "Admin %s gave you $%d.", ReturnPlayerName(playerid), amt);

    return 1;
}

ACMD:[MAX_ADMIN_LEVEL]setlevel(playerid, const params[])
{
    extract params -> new targetid, level; else
        return usage(playerid, "/setlevel [targetid] [level]");

    if (!(1 <= level <= 10000))
        return err(playerid, "You can't set a level less than 1 and more than 10000!");

    SetPlayerScore(targetid, level);
    set_player_score(playerid, level);

    fmt_info(playerid, "You set %s a score to %d.", ReturnPlayerName(targetid), level);
    fmt_info(targetid, "Admin %s set your score to %d.", ReturnPlayerName(playerid), level);

    return 1;
}