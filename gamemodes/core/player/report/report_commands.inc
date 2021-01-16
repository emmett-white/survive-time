CMD:report(playerid, const params[])
{
    if (gettime() < get_player_report_time(playerid)) {
        return err(playerid, "You can use this command every 2 minutes!");
    }

    extract params -> new targetid, string: reason[MAX_REASON_TEXT]; else {
        return usage(playerid, "/report [targetid] [reason]");
    }

    report_player(targetid, playerid, reason);

    return 1;
}

CMD:reportbug(playerid, const params[])
{
    if (gettime() < get_player_report_time(playerid)) {
        return err(playerid, "You can use this command every 2 minutes!");
    }

    if (isnull(params)) {
        return usage(playerid, "/reportbug [bug]");
    }

    report_bug(playerid, params);

    return 1;
}