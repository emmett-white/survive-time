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
    UI_CreateRegisterTextDraws(playerid);

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