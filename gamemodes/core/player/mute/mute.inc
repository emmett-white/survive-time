static
    char_muted[MAX_PLAYERS],
    char_muted_mins[MAX_PLAYERS];

// * Set functions *
set_player_muted(const playerid, const int)
{
    if (!IsPlayerConnected(playerid))
        return 0;

    char_muted[playerid] = int;

    return 1;
}

set_player_muted_mins(const playerid, const int)
{
    if (!IsPlayerConnected(playerid))
        return 0;

    char_muted_mins[playerid] = int;

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
#include <mute_commands>