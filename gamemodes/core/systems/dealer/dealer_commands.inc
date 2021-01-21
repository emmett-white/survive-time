CMD:dealer(playerid, const params[])
{
    if (!dealer_nearby(playerid)) {
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
                if (get_player_money(playerid) < 45) {
                    return err(playerid, "You don't have enough money!");
                }

                GivePlayerMoney(playerid, -45);
                set_player_money(playerid, (get_player_money(playerid) - 45));

                GivePlayerWeapon(playerid, 22, 50);

                show_player_help_msg(playerid, "~y~9mm Pistol (%d)", GetPlayerAmmo(playerid));
            }

            case 1: {
                if (get_player_money(playerid) < 55) {
                    return err(playerid, "You don't have enough money!");
                }

                GivePlayerMoney(playerid, -55);
                set_player_money(playerid, (get_player_money(playerid) - 55));

                set_player_drugs(playerid, (get_player_drugs(playerid) + 10));

                show_player_help_msg(playerid, "~y~10g drugs");
            }

            case 2: {
                if (!get_player_drugs(playerid)) {
                    return err(playerid, "You don't have drugs!");
                }

                GivePlayerMoney(playerid, 35);
                set_player_money(playerid, (get_player_money(playerid) + 35));

                set_player_drugs(playerid, (get_player_drugs(playerid) - 10));

                show_player_help_msg(playerid, "~r~-10g drugs");
            }
        }
    }

    return 1;
}