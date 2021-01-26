ADMIN_COMMAND:[MAX_ADMIN_LEVEL && !IsPlayerAdmin(playerid)]setadmin(playerid, const params[])
{
    extract params -> new targetid, level, code; else {
        return usage(playerid, "/setadmin [targetid] [level] [code]");
    }

    SetPlayerAdminLevel(targetid, playerid, level, code);

    return 1;
}

ADMIN_COMMAND:[MAX_ADMIN_LEVEL]givemoney(playerid, const params[])
{
    extract params -> new targetid, amt; else {
        return usage(playerid, "/givemoney [targetid] [amount]");
    }

    if (!(1 <= amt <= 1000000)) {
        return err(playerid, "You can't give less than $1 and more than $1.000.000!");
    }

    Player_SetMoney(playerid, amt);
    GivePlayerMoney(targetid, amt);

    fmt_info(playerid, "You gave $%d to %s.", amt, ReturnPlayerName(targetid));
    fmt_info(targetid, "Admin %s gave you $%d.", ReturnPlayerName(playerid), amt);

    return 1;
}

ADMIN_COMMAND:[MAX_ADMIN_LEVEL]setlevel(playerid, const params[])
{
    extract params -> new targetid, level; else {
        return usage(playerid, "/setlevel [targetid] [level]");
    }

    if (!(1 <= level <= 10000)) {
        return err(playerid, "You can't set a level less than 1 and more than 10000!");
    }

    SetPlayerScore(targetid, level);
    Player_SetScore(playerid, level);

    fmt_info(playerid, "You set %s a score to %d.", ReturnPlayerName(targetid), level);
    fmt_info(targetid, "Admin %s set your score to %d.", ReturnPlayerName(playerid), level);

    return 1;
}

ADMIN_COMMAND:[MAX_ADMIN_LEVEL]createdealer(playerid, const params[])
{
    extract params -> new skin, string: name[25]; else {
        return usage(playerid, "/createdealer [skin] [name]");
    }

    static
        x,
        y,
        z,
        a;
    
    GetPlayerPos(playerid, Float: x, Float: y, Float: z);
    GetPlayerFacingAngle(playerid, Float: a);

    Dealer_Create(skin, name, Float: x, Float: y, Float: z, Float: a);

    return 1;
}

ADMIN_COMMAND:[MAX_ADMIN_LEVEL]givedrugs(playerid, const params[])
{
    if (isnull(params)) {
        return usage(playerid, "/givedrugs [targetid]");
    }

    Player_SetDrugs(strval(params), (Player_GetDrugs(strval(params)) + 10));

    fmt_info(strval(params), "Admin %s gave you 10g of drugs. Drugs: %d", ReturnPlayerName(playerid), Player_GetDrugs(strval(params)));
    fmt_info(playerid, "You gave 10g of drugs to %s. Drugs: %d", ReturnPlayerName(strval(params)), Player_GetDrugs(strval(params)));

    return 1;
}

ADMIN_COMMAND:[MAX_ADMIN_LEVEL]createfastfood(playerid, const params[])
{
    FF_Create(playerid);

    return 1;
}