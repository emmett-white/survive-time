check_player_account(const playerid)
{
    task_await(
        MySQL_QueryS(
            str_format(
                "SELECT * FROM accounts WHERE account_name = '%e'", ReturnPlayerName(playerid)
            )
        )
    );

    if (cache_num_rows())
    {
        // Loading account
        cache_get_value_name_int(0, "account_id", account_id[playerid]);
        cache_get_value_name(0, "account_password", account_password[playerid]);

        // Loading character
        task_await(
            MySQL_QueryS(
                str_format(
                    "SELECT * FROM characters WHERE char_name = '%e'", ReturnPlayerName(playerid)
                )
            )
        );

        if (cache_num_rows()) {
            static tmpint = 0;
            
            cache_get_value_name_int(0, "char_score", tmpint);
            set_player_score(playerid, tmpint);

            cache_get_value_name_int(0, "char_money", tmpint);
            set_player_money(playerid, tmpint);

            cache_get_value_name_int(0, "char_admin", tmpint);
            set_player_admin(playerid, tmpint);

            cache_get_value_name_int(0, "char_admincode", tmpint);
            set_player_admin_code(playerid, tmpint);

            cache_get_value_name_int(0, "char_skin", tmpint);
            set_player_skin(playerid, tmpint);

            cache_get_value_name_int(0, "char_warn", tmpint);
            set_player_warns(playerid, tmpint);

            cache_get_value_name_int(0, "char_muted", tmpint);
            set_player_muted(playerid, tmpint);

            cache_get_value_name_int(0, "char_mutedmins", tmpint);
            set_player_muted_mins(playerid, tmpint);
        }

        do_auth_login(playerid);
    
        return 1;
    }

    // Register
    task_yield(1);
    
    static
        dialog_register[e_DIALOG_RESPONSE_INFO];

    task_await_arr(
        ShowPlayerAsyncDialog(
            playerid, DIALOG_STYLE_PASSWORD,
            "Register", "bla bla bla bla",
            "Submit", "Exit"
        ), dialog_register
    );

    if (dialog_register[E_DIALOG_RESPONSE_Response]) {
        if (!(6 <= strlen(dialog_register[E_DIALOG_RESPONSE_InputText]) <= 24))
            return SendClientMessage(playerid, X11_ORANGE, "* Error: Password is too short or too long.");


        strcopy(account_password[playerid], dialog_register[E_DIALOG_RESPONSE_InputText]);

        new
            String: str_query_acc,
            String: str_query_char;

        str_query_acc = str_format(
            "INSERT INTO \
                accounts (account_name, account_password) \
            VALUES \
                ('%e', '%e') \
            ", ReturnPlayerName(playerid), dialog_register[E_DIALOG_RESPONSE_InputText]
        );

        str_query_char = str_format(
            "INSERT INTO \
                characters (char_name) \
            VALUES \
                ('%e') \
            ", ReturnPlayerName(playerid)
        );

        mysql_tquery_s(MySQL_GetHandle(), str_query_acc, "init_player_account", "d", playerid);
        mysql_tquery_s(MySQL_GetHandle(), str_query_char, "init_player_character", "d", playerid);
    }

    return 1;
}

do_auth_login(const playerid)
{
    task_yield(1);
        
    static
        dialog_login[e_DIALOG_RESPONSE_INFO];

    task_await_arr(
        ShowPlayerAsyncDialog(
            playerid, DIALOG_STYLE_PASSWORD,
            "Login", "bla bla bla bla",
            "Submit", "Exit"
        ), dialog_login
    );

    if (dialog_login[E_DIALOG_RESPONSE_Response]) {
        if (!strcmp(dialog_login[E_DIALOG_RESPONSE_InputText], account_password[playerid], false)) {
            va_SendClientMessage(
                playerid, X11_ORANGE,
                "Info: "WHITE"%s you've successfully logged in.",
                ReturnPlayerName(playerid)
            );

            // Assign variables to player
            char_score[playerid] = 1;
            char_skin[playerid] = 26;
            char_money[playerid] = 10000;

            SetPlayerScore(playerid, char_score[playerid]);
            GivePlayerMoney(playerid, char_money[playerid]);

            // Change coordinates of spawn
            SetSpawnInfo(playerid, 0, char_skin[playerid], 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);
            SpawnPlayer(playerid);
        }

        else {
            ++player_login_attempts[playerid];
            va_SendClientMessage(playerid, X11_ORANGE, "* Wrong password, attempts: %d/3.", player_login_attempts[playerid]);

            do_auth_login(playerid);

            if (player_login_attempts[playerid] == 3)
                return Kick(playerid);
        }
    } else Kick(playerid);

    return 1;
}