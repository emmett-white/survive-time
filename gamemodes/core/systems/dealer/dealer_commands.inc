PLAYER_COMMAND:dealer(playerid, const params[])
{
    if (!Dealer_Nearby(playerid)) {
        return err(playerid, "You've to be close to the dealer!");
    }

    task_yield(1);

    static
        dialog_dealer[e_DIALOG_RESPONSE_INFO];

    task_await_arr(
        Task: ShowPlayerAsyncDialog(
            playerid, DIALOG_STYLE_TABLIST,
            "Dealer offers", "9mm Pistol\t$45\nBuy drugs (10g)\t$55\nSell drugs (10g)\t$35",
            "Submit", "Cancel"
        ), dialog_dealer
    );

    if (dialog_dealer[E_DIALOG_RESPONSE_Response]) {
        switch (dialog_dealer[E_DIALOG_RESPONSE_Listitem]) {
            case 0: {
                if (Player_GetMoney(playerid) < 45) {
                    return err(playerid, "You don't have enough money!");
                }

                GivePlayerMoney(playerid, -45);
                GivePlayerWeapon(playerid, 22, 50);

                Player_SetMoney(playerid, (Player_GetMoney(playerid) - 45));
                UI_ShowPlayerHelpMsg(playerid, "~y~9mm Pistol (%d)", GetPlayerAmmo(playerid));
            }

            case 1: {
                if (Player_GetMoney(playerid) < 55) {
                    return err(playerid, "You don't have enough money!");
                }

                GivePlayerMoney(playerid, -55);

                Player_SetMoney(playerid, (Player_GetMoney(playerid) - 55));
                Player_SetDrugs(playerid, (Player_GetDrugs(playerid) + 10));

                UI_ShowPlayerHelpMsg(playerid, "~y~10g drugs");
            }

            case 2: {
                if (!Player_GetDrugs(playerid)) {
                    return err(playerid, "You don't have drugs!");
                }

                GivePlayerMoney(playerid, 35);
                
                Player_SetMoney(playerid, (Player_GetMoney(playerid) + 35));
                Player_SetDrugs(playerid, (Player_GetDrugs(playerid) - 10));

                UI_ShowPlayerHelpMsg(playerid, "~r~-10g drugs");
            }
        }
    }

    return 1;
}