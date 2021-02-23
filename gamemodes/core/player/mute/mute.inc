static
    char_muted[MAX_PLAYERS],
    char_muted_mins[MAX_PLAYERS];

/**
 * Set functions
 */
stock Player_SetMuted(const playerid, const int)
{
    if (!IsPlayerConnected(playerid)) {
        return 0;
    }

    char_muted[playerid] = int;

    new String: str_query_update = String: String: str_format(
        "UPDATE \
            characters \
        SET \
            char_muted = '%d' \
        WHERE \
            char_name = '%e'",
        Player_GetMuted(playerid), ReturnPlayerName(playerid)
    );

    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

stock Player_SetMutedMins(const playerid, const int)
{
    if (!IsPlayerConnected(playerid)) {
        return 0;
    }

    char_muted_mins[playerid] = int;

    new String: str_query_update = String: String: str_format(
        "UPDATE \
            characters \
        SET \
            char_muted = '%d', char_mutedmins = '%d' \
        WHERE \
            char_name = '%e'",
        Player_GetMuted(playerid), Player_GetMutedMins(playerid), ReturnPlayerName(playerid)
    );

    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

/**
 * Get functions
 */
stock Player_GetMuted(const playerid)
{
    return char_muted[playerid];
}

stock Player_GetMutedMins(const playerid)
{
    return char_muted_mins[playerid];
}

#include <mute_timer>
#include <mute_functions>