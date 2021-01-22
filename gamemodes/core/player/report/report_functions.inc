/*
  * <param name="targetid">player who will be reported</param>
  * <param name="playerid">player who will report player (targetid)</param>
  * <param name="reason">the reason why targetid will be reported</param>
*/
ReportPlayer(const targetid, const playerid, const string: reason[])
{
    if (targetid == playerid) {
        return err(playerid, "You can't report yourself!");
	}

    SendMessageToAdmins(
        X11_RED, "[Player Report]: "WHITE"%s reported player %s for %s.",
        ReturnPlayerName(playerid), ReturnPlayerName(targetid), reason
    );

    Player_SetReportTime(playerid, (gettime() + 120));

    return 1;
}

ReportBug(const playerid, const string: reason[])
{
	task_await(
		Task: MySQL_QueryS(
			String: str_format(
				"SELECT * FROM reports where report_reason = '%e'", reason
			)
		)
	);

	if (cache_num_rows()) {
		return err(playerid, "That report already exists!");
	}

	new String: str_query_report_update = String: str_format(
		"INSERT INTO \
			reports (report_player, report_reason) \
		VALUES \
			('%e', '%e')", ReturnPlayerName(playerid), reason
	);

	mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_report_update);
	Player_SetReportTime(playerid, (gettime() + 120));

	return 1;
}