#include <YSI_Coding\y_hooks>

// * Hooks *
hook OnPlayerConnect(playerid)
{
	CheckPlayerBanStatus(playerid);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_PISTOL, 50);

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerSpawn(playerid)
{
    new
		pos_x,
		pos_y,
		pos_z,
		pos_a,

		interior,
		world;

	GetPlayerPos(playerid, Float: pos_x, Float: pos_y, Float: pos_z);
    GetPlayerFacingAngle(playerid, Float: pos_a);

	// We need to set position for avoid small player fall after spawn
	Streamer_UpdateEx(playerid, Float: pos_x, Float: pos_y, Float: pos_z, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid), .compensatedtime = 2000);

	SetPlayerFacingAngle(playerid, Float: pos_a);
	SetPlayerInterior(playerid, interior);
	SetPlayerVirtualWorld(playerid, world);
	SetPlayerSkin(playerid, Player_GetSkin(playerid));
	
	UI_CreatePlayerTextDraws(playerid);
	UI_CreatePlayerHelpMsg(playerid);

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
	if (playertextid == PlayerText: UI_ClickRegisterTextDraw(playerid, 8)) {
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
			UI_CreateRegisterTextDraws(playerid, false);
		}

		return 1;
	}
	
	if (playertextid == PlayerText: UI_ClickRegisterTextDraw(playerid, 7) || PlayerText: UI_ClickRegisterTextDraw(playerid, 10)) {
		UI_CreateRegisterTextDraws(playerid, false);
		
		task_await(Task: BindToPlayer(task_ms(1000), playerid));
		Kick(playerid);

		return 1;
	}

	return Y_HOOKS_CONTINUE_RETURN_0;
}