static
    char_muted[MAX_PLAYERS],
    char_muted_mins[MAX_PLAYERS];

// * Set functions *
set_player_muted(const playerid, const int)
{
    if (!IsPlayerConnected(playerid))
        return 0;

    char_muted[playerid] = int;

    new String: str_query_update = str_format(
        "UPDATE \
            characters \
        SET \
            char_muted = '%d' \
        WHERE \
            char_name = '%e'",
        get_player_muted(playerid), ReturnPlayerName(playerid)
    );

    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

set_player_muted_mins(const playerid, const int)
{
    if (!IsPlayerConnected(playerid))
        return 0;

    char_muted_mins[playerid] = int;

    new String: str_query_update = str_format(
        "UPDATE \
            characters \
        SET \
            char_muted = '%d', char_mutedmins = '%d' \
        WHERE \
            char_name = '%e'",
        get_player_muted(playerid), get_player_muted_mins(playerid), ReturnPlayerName(playerid)
    );

    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

// * Get functions *
get_player_muted(const playerid)
{
    return char_muted[playerid];
}

get_player_muted_mins(const playerid)
{
    return char_muted_mins[playerid];
}

#include <mute_timer>
#include <mute_functions>