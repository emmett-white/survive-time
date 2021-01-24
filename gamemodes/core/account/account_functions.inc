CheckPlayerAccExists(const playerid)
{
    task_await(
        Task: MySQL_QueryS(
            String: str_format(
                "SELECT * FROM accounts WHERE account_name = '%e'", ReturnPlayerName(playerid)
            )
        )
    );

    if (cache_num_rows()) {
        // Loading account
        cache_get_value_name_int(0, "account_id", account_id[playerid]);
        cache_get_value_name(0, "account_password", account_password[playerid]);

        // Loading character
        task_await(
            Task: MySQL_QueryS(
                String: str_format(
                    "SELECT * FROM characters WHERE char_name = '%e'", ReturnPlayerName(playerid)
                )
            )
        );

        if (cache_num_rows()) {
            static tmpint = 0;
            
            cache_get_value_name_int(0, "char_score", tmpint);
            Player_SetScore(playerid, tmpint);

            cache_get_value_name_int(0, "char_money", tmpint);
            Player_SetMoney(playerid, tmpint);

            cache_get_value_name_int(0, "char_admin", tmpint);
            Admin_Set(playerid, tmpint);

            cache_get_value_name_int(0, "char_admincode", tmpint);
            Admin_SetCode(playerid, tmpint);

            cache_get_value_name_int(0, "char_skin", tmpint);
            Player_SetSkin(playerid, tmpint);

            cache_get_value_name_int(0, "char_warn", tmpint);
            Player_SetWarns(playerid, tmpint);

            cache_get_value_name_int(0, "char_muted", tmpint);
            Player_SetMuted(playerid, tmpint);

            cache_get_value_name_int(0, "char_mutedmins", tmpint);
            Player_SetMutedMins(playerid, tmpint);

            cache_get_value_name_int(0, "char_drugs", tmpint);
            Player_SetDrugs(playerid, tmpint);
        }

        Auth_DoLogin(playerid);
    
        return 1;
    }

    // Register
    task_yield(1);
    
    static
        dialog_register[e_DIALOG_RESPONSE_INFO];

    task_await_arr(
        Task: ShowPlayerAsyncDialog(
            playerid, DIALOG_STYLE_PASSWORD,
            "Register", "Please, enter your desired password to create an account...",
            "Submit", "Exit"
        ), dialog_register
    );

    if (dialog_register[E_DIALOG_RESPONSE_Response]) {
        if (!(6 <= strlen(dialog_register[E_DIALOG_RESPONSE_InputText]) <= 24)) {
            return err(playerid, "Password is too short or too long.");
        }

        strcopy(account_password[playerid], dialog_register[E_DIALOG_RESPONSE_InputText]);

        new
            String: str_query_acc,
            String: str_query_char;

        str_query_acc = String: str_format(
            "INSERT INTO \
                accounts (account_name, account_password) \
            VALUES \
                ('%e', '%e') \
            ", ReturnPlayerName(playerid), dialog_register[E_DIALOG_RESPONSE_InputText]
        );

        str_query_char = String: str_format(
            "INSERT INTO \
                characters (char_name) \
            VALUES \
                ('%e') \
            ", ReturnPlayerName(playerid)
        );

        mysql_tquery_s(MySQL_GetHandle(), str_query_acc, "OnAccountRegistered", "d", playerid);
        mysql_tquery_s(MySQL_GetHandle(), str_query_char, "OnCharacterRegistered", "d", playerid);

        fmt_info(playerid, "%s welcome to the Survive Time server!", ReturnPlayerName(playerid));

        Player_SetScore(playerid, 1);
        Player_SetMoney(playerid, 100);
        Player_SetSkin(playerid, 26);

        SetPlayerScore(playerid, Player_GetScore(playerid));
        GivePlayerMoney(playerid, Player_GetMoney(playerid));

        GameTextForPlayer(playerid, "~y~CREATING ACCOUNT...", 3000, 3);
        task_await(Task: BindToPlayer(task_ms(3000), playerid));
        Player_SetSpawn(playerid);
    }

    return 1;
}

Auth_DoLogin(const playerid)
{
    task_yield(1);
        
    static
        dialog_login[e_DIALOG_RESPONSE_INFO];

    task_await_arr(
        Task: ShowPlayerAsyncDialog(
            playerid, DIALOG_STYLE_PASSWORD,
            "Login", "Please, enter you correct password to log in...",
            "Submit", "Exit"
        ), dialog_login
    );

    if (dialog_login[E_DIALOG_RESPONSE_Response]) {
        if (!strcmp(dialog_login[E_DIALOG_RESPONSE_InputText], account_password[playerid], false)) {
            fmt_info(playerid, "%s you've successfully logged in.", ReturnPlayerName(playerid));

            SetPlayerScore(playerid, Player_GetScore(playerid));
            GivePlayerMoney(playerid, Player_GetMoney(playerid));

            GameTextForPlayer(playerid, "~y~LOADING ACCOUNT...", 3000, 3);
            task_await(Task: BindToPlayer(task_ms(3000), playerid));
            Player_SetSpawn(playerid);
        }

        else {
            ++player_login_attempts[playerid];
            fmt_err(playerid, "Wrong password, attempts: %d/3.", player_login_attempts[playerid]);

            Auth_DoLogin(playerid);

            if (player_login_attempts[playerid] == 3) {
                return Kick(playerid);
            }
        }
    }
    
    else {
        Kick(playerid);
    }

    return 1;
}