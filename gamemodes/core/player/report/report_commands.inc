CMD:report(playerid, const params[])
{
    if (gettime() < get_player_report_time(playerid)) {
        return err(playerid, "You can use this commands every 2 minutes!");
    }

    extract params -> new targetid, string: reason[MAX_REASON_TEXT]; else {
        return usage(playerid, "/report [targetid] [reason]");
    }

    report_player(targetid, playerid, reason);

    return 1;
}