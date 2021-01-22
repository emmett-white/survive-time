CMD:report(playerid, const params[])
{
    if (gettime() < Player_GetReportTime(playerid)) {
        return err(playerid, "You can use this command every 2 minutes!");
    }

    extract params -> new targetid, string: reason[MAX_REASON_TEXT]; else {
        return usage(playerid, "/report [targetid] [reason]");
    }

    ReportPlayer(targetid, playerid, reason);

    return 1;
}

CMD:reportbug(playerid, const params[])
{
    if (gettime() < Player_GetReportTime(playerid)) {
        return err(playerid, "You can use this command every 2 minutes!");
    }

    if (isnull(params)) {
        return usage(playerid, "/reportbug [bug]");
    }

    ReportBug(playerid, params);

    return 1;
}