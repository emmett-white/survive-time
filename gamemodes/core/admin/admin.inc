static
    char_admin[MAX_PLAYERS],
    char_admin_code[MAX_PLAYERS];

// * Functions *
msg_admin(colour, const string: text[], va_args<>)
{
    foreach (new i: Player) {
        if (get_player_admin(i)) {
            return SendClientMessage(i, colour, va_return(text, va_start<2>));
        }
    }

    return 1;
}

// * Set functions *
set_player_admin(const playerid, const int)
{
    if (!IsPlayerConnected(playerid)) {
        return 0;
    }

    char_admin[playerid] = int;

    new String: str_query_update = String: str_format(
        "UPDATE \
            characters \
        SET \
            char_admin = '%d' \
        WHERE \
            char_name = '%e'",
        get_player_admin(playerid), ReturnPlayerName(playerid)
    );

    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

set_player_admin_code(const playerid, const int)
{
    if (!IsPlayerConnected(playerid)) {
        return 0;
    }

    char_admin_code[playerid] = int;

    new String: str_query_update = String: str_format(
        "UPDATE \
            characters \
        SET \
            char_admincode = '%d' \
        WHERE \
            char_name = '%e'",
        get_player_admin_code(playerid), ReturnPlayerName(playerid)
    );

    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

// * Get functions *
get_player_admin(const playerid)
{
    return char_admin[playerid];
}

get_player_admin_code(const playerid)
{
    return char_admin_code[playerid];
}

#include <admin_core>
#include <admin_level_1>
#include <admin_level_2>
#include <admin_level_3>
#include <admin_level_4>