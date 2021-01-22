static
    player_report_time[MAX_PLAYERS];

// * Get/Set functions *
Player_SetReportTime(const playerid, const int)
{
    if (!IsPlayerConnected(playerid)) {
        return 0;
    }

    player_report_time[playerid] = int;

    return 1;
}

Player_GetReportTime(const playerid)
{
    return player_report_time[playerid];
}

#include <report_functions>
#include <report_commands>