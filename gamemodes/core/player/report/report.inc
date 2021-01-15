static
    player_report_time[MAX_PLAYERS];

// * Get/Set functions *
set_player_report_time(const playerid, const int)
{
    if (!IsPlayerConnected(playerid)) {
        return 0;
    }

    player_report_time[playerid] = int;

    return 1;
}

get_player_report_time(const playerid)
{
    return player_report_time[playerid];
}

#include <report_functions>
#include <report_commands>