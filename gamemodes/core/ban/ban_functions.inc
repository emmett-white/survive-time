check_player_banned(const playerid)
{
    task_await(
        MySQL_QueryS(
            str_format(
                "SELECT * FROM banned WHERE banned_player = '%e'", ReturnPlayerName(playerid)
            )
        )
    );

    if (cache_num_rows()) {
        static
            banned_admin[MAX_PLAYER_NAME],
            banned_reason[64],
            
            dialog_banned[e_DIALOG_RESPONSE_INFO];

        cache_get_value_name(0, "banned_admin", banned_admin);
        cache_get_value_name(0, "banned_reason", banned_reason);

        task_yield(1);

        task_await_arr(
            ShowPlayerAsyncDialog(
                playerid, DIALOG_STYLE_MSGBOX,
                "Banned", "You're banned from this server\nAdmin: %s\nReason: %s",
                "Close", ""
            ), dialog_banned
        );

        wait_ms(1000);
        Kick(playerid);

        return 1;
    }

    check_player_account(playerid);

    return 1;
}

/**
  * <param name="playerid">Player who will be banned</param>
  * <param name="adminid">Admin who will ban player</param>
  * <param name="reason">The reason why the player is banned</param>
*/
ban_player(const playerid, const adminid, const string: reason[])
{
    if (playerid == adminid) {
        return err(adminid, "You can't ban yourself!");
    }

    new String: str_query_ban_ins = str_format(
        "INSERT INTO \
            banned (banned_player, banned_admin, banned_reason) \
        VALUES \
            ('%e', '%e', '%e')", ReturnPlayerName(playerid), ReturnPlayerName(adminid), reason
    );

    mysql_tquery_s(MySQL_GetHandle(), str_query_ban_ins);

    va_SendClientMessageToAll(
        X11_RED, "* Ban: "WHITE"Player %s has been banned from this server. Reason: %s",
        ReturnPlayerName(playerid), reason
    );

    va_SendClientMessageToAll(
        X11_RED, "* Ban: "WHITE"Admin %s banned player %s because of %s.",
        ReturnPlayerName(adminid), ReturnPlayerName(playerid), reason
    );

    GameTextForPlayer(playerid, "~r~BANNED", 20000, 3);

    return 1;
}

/**
  * <param name="playerid">Admin who will unban player</param>
  * <param name="name">Player who will be unbanned</param>
*/
unban_player(const playerid, const string: name[])
{
    task_await(
        MySQL_QueryS(
            str_format(
                "SELECT * FROM banned WHERE banned_player = '%e'", name
            )
        )  
    );

    if (!cache_num_rows()) {
        return err(playerid, "That player isn't banned.");
    }

    new String: str_query_ban_del = str_format(
        "DELETE FROM banned WHERE banned_player = '%e'", name
    );

    mysql_tquery_s(MySQL_GetHandle(), str_query_ban_del);

    va_SendClientMessageToAll(X11_RED, "* Un-Ban: "WHITE"Player %s is no longer banned!", name);

    return 1;
}