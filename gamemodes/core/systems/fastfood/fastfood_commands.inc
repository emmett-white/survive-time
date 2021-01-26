PLAYER_COMMAND:fastfood(playerid, const params[])
{
    if (!FF_Nearby(playerid)) {
        return err(playerid, "You've to be close to fast food!");
    }

    static
        Float: hp;

    GetPlayerHealth(playerid, hp);

    if (hp >= 80.0) {
        return err(playerid, "You're not hungry or thirsty!");
    }

    task_yield(1);

    static
        dialog_fastfood[e_DIALOG_RESPONSE_INFO];

    task_await_arr(
        Task:ShowPlayerAsyncDialog(
            playerid, DIALOG_STYLE_TABLIST,
            "Fast food", "Burger\t$4\nChips\t$2\nSoda\t$2\nWater\t$1",
            "Buy", "Cancel"
        ), dialog_fastfood
    );

    if (dialog_fastfood[E_DIALOG_RESPONSE_Response]) {
        switch (dialog_fastfood[E_DIALOG_RESPONSE_Listitem]) {
            case 0: {
                if (Player_GetMoney(playerid) < 4) {
                    return err(playerid, "You don't have enough money!");
                }

                GivePlayerMoney(playerid, -4);
                Player_SetMoney(playerid, (Player_GetMoney(playerid) - 4));
                
                GetPlayerHealth(playerid, hp);
                SetPlayerHealth(playerid, (hp + 10.0));

                UI_ShowPlayerHelpMsg(playerid, "~r~-$4");
            }

            case 1: {
                if (Player_GetMoney(playerid) < 2) {
                    return err(playerid, "You don't have enough money!");
                }

                GivePlayerMoney(playerid, -2);
                Player_SetMoney(playerid, (Player_GetMoney(playerid) - 2));

                SetPlayerHealth(playerid, (hp + 5.0));

                UI_ShowPlayerHelpMsg(playerid, "~r~-$2");
            }

            case 2: {
                if (Player_GetMoney(playerid) < 2) {
                    return err(playerid, "You don't have enough money!");
                }

                GivePlayerMoney(playerid, -2);
                Player_SetMoney(playerid, (Player_GetMoney(playerid) - 2));
                
                SetPlayerHealth(playerid, (hp + 3.0));

                UI_ShowPlayerHelpMsg(playerid, "~r~-$2");
            }

            case 3: {
                if (Player_GetMoney(playerid) < 1) {
                    return err(playerid, "You don't have enough money!");
                }

                GivePlayerMoney(playerid, -1);
                Player_SetMoney(playerid, (Player_GetMoney(playerid) - 1));
                
                SetPlayerHealth(playerid, (hp + 4.0));

                UI_ShowPlayerHelpMsg(playerid, "~r~-$1");
            }
        }
    }

    return 1;
}