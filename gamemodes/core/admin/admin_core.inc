// * Variable *
const MAX_ADMIN_LEVEL = (4);

enum {
    e_ADMIN_LEVEL_1 = 1,
    e_ADMIN_LEVEL_2,
    e_ADMIN_LEVEL_3,
    e_ADMIN_LEVEL_4
};

/**
  * <param name="playerid">The player to whom the admin will be assigned/removed</param>
  * <param name="adminid">The admin who assigns/removes admin to playerid</param>
  * <param name="level">the level of playerid's admin</param>
*/
SetPlayerAdminLevel(const playerid, const adminid, level = 0, code)
{
    if (!(0 <= level <= MAX_ADMIN_LEVEL)) {
        return err(adminid, "* Error: "WHITE"Admin level can't be less than 0 and greater than 4!");
    }

    if (level == Admin_GetLevel(playerid)) {
        return err(adminid, "* Error: "WHITE"That player is already that admin level!");
    }

    Admin_Set(playerid, level);
    Admin_SetCode(playerid, code);

    if (level == 0) {
        Player_SetSkin(playerid, 26);

        SetPlayerSkin(playerid, Player_GetSkin(playerid));
        GameTextForPlayer(playerid, "~r~You're no longer an administrator!", 3000, 3);

        return 1;
    }

    Player_SetSkin(playerid, 294);
    SetPlayerSkin(playerid, Player_GetSkin(playerid));

    va_GameTextForPlayer(playerid, "~w~You're now an administrator level ~y~%d.", 3000, 3, Admin_GetLevel(playerid));
    fmt_info(playerid, "Your admin code is: %d", Admin_GetCode(playerid));

    return 1;
}