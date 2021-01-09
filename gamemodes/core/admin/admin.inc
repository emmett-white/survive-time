static
    char_admin[MAX_PLAYERS],
    char_admin_code[MAX_PLAYERS];

// * Set functions *
set_player_admin(const playerid, const int)
{
    if (!IsPlayerConnected(playerid))
        return 0;

    char_admin[playerid] = int;

    return 1;
}

set_player_admin_code(const playerid, const int)
{
    if (!IsPlayerConnected(playerid))
        return 0;

    char_admin_code[playerid] = int;

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
#include <admin_commands>