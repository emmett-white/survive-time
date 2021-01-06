// * Variable *
const MAX_ADMIN_LEVEL = (4);

// * Functions *

get_admin_level(const playerid)
{
    return char_admin[playerid];
}

/*
  * <param name="playerid">The player to whom the admin will be assigned/removed</param>
  * <param name="adminid">The admin who assigns/removes admin to playerid</param>
  * <param name="level">the level of playerid's admin</param>
*/
set_admin_level(const playerid, const adminid, level = 0, code)
{
    if (!(0 <= level < 5))
        return SendClientMessage(adminid, X11_ORANGE, "* Error: "WHITE"Admin level can't be less than 0 and greater than 4!");

    if (level == char_admin[playerid])
        return SendClientMessage(adminid, X11_ORANGE, "* Error: "WHITE"That player is already that admin level!");


    char_admin[playerid] = level;
    char_admin_code[playerid] = code;

    new String: str_query_update_admin = str_format(
        "UPDATE characters SET char_admin = '%d', char_admincode = '%d' WHERE char_name = '%e'",
        char_admin[playerid], char_admin_code[playerid], ReturnPlayerName(playerid)
    );

    mysql_tquery_s(MySQL_GetHandle(), str_query_update_admin);

    if (level == 0) {
        char_skin[playerid] = 26;

        SetPlayerSkin(playerid, char_skin[playerid]);
        GameTextForPlayer(playerid, "~r~You're no longer an administrator!", 3000, 3);

        return 1;
    }

    char_skin[playerid] = 294;

    SetPlayerSkin(playerid, char_skin[playerid]);

    va_GameTextForPlayer(playerid, "~w~You're now an administrator level ~y~%d.", 3000, 3, char_admin[playerid]);
    va_SendClientMessage(playerid, X11_ORANGE, "*Info: "WHITE"Your admin code is: %d", char_admin_code[playerid]);

    return 1;
}