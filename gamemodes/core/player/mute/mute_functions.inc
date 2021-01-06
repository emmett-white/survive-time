mute_player(const targetid, const playerid, const string: reason[], minutes)
{
    #pragma unused reason

    if (char_muted[targetid])
        return err(playerid, "That player is already muted!");

    if (!(0 <= minutes <= MAX_MUTE_MINUTES))
        return fmt_err(playerid, "Minutes can't be less than 0 (unmute) and more than %d!", MAX_MUTE_MINUTES);

    // if (targetid == playerid)
    //     return err(playerid, "You can't mute yourself!");

    if (minutes != 0)
        return char_muted[targetid] = !char_muted[targetid];

    char_muted[targetid] = 0;

    new String: str_query_mute_set = str_format(
        "UPDATE characters SET char_muted = '%d', char_mutedmins = '%d' WHERE char_id = '%d'",
        char_muted[targetid], char_muted_mins[targetid], char_id[targetid]
    );

    mysql_tquery_s(MySQL_GetHandle(), str_query_mute_set);

    return 1;
}

CMD:test(playerid, const params[])
{
    static
        targetid,
        reason[64],
        minutes;

    if (sscanf(params, "rs[64]i", targetid, reason, minutes))
        return usage(playerid, "/mute [targetid] [reason] [minutes(0-9999)]");

    mute_player(targetid, playerid, reason, minutes);

    return 1;
}