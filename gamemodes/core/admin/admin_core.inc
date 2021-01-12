// * Variable *
const MAX_ADMIN_LEVEL = (4);

/**
  * <param name="playerid">The player to whom the admin will be assigned/removed</param>
  * <param name="adminid">The admin who assigns/removes admin to playerid</param>
  * <param name="level">the level of playerid's admin</param>
*/
set_admin_level(const playerid, const adminid, level = 0, code)
{
    if (!(0 <= level < 5))
        return err(adminid, "* Error: "WHITE"Admin level can't be less than 0 and greater than 4!");

    if (level == get_player_admin(playerid))
        return err(adminid, "* Error: "WHITE"That player is already that admin level!");

    set_player_admin(playerid, level);
    set_player_admin_code(playerid, code);

    if (level == 0) {
        set_player_skin(playerid, 26);

        SetPlayerSkin(playerid, char_skin[playerid]);
        GameTextForPlayer(playerid, "~r~You're no longer an administrator!", 3000, 3);

        return 1;
    }

    set_player_skin(playerid, 294);

    SetPlayerSkin(playerid, char_skin[playerid]);

    va_GameTextForPlayer(playerid, "~w~You're now an administrator level ~y~%d.", 3000, 3, get_player_admin(playerid));
    va_SendClientMessage(playerid, X11_ORANGE, "*Info: "WHITE"Your admin code is: %d", get_player_admin_code(playerid));

    return 1;
}