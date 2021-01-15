/*
  * <param name="targetid">player who will be reported</param>
  * <param name="playerid">player who will report player (targetid)</param>
  * <param name="reason">the reason why targetid will be reported</param>
*/
report_player(const targetid, const playerid, const string: reason[])
{
    // if (targetid == playerid)
    //     return err(playerid, "You can't report yourself!");

    msg_admin(
        X11_RED, "[Player Report]: "WHITE"%s reported player %s for %s.",
        ReturnPlayerName(playerid), ReturnPlayerName(targetid), reason
    );

    set_player_report_time(playerid, (gettime() + 120));

    return 1;
}