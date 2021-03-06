static
    char_report_time[MAX_PLAYERS];

/**
 * Get/Set functions
 */
stock Player_SetReportTime(const playerid, const int)
{
    if (!IsPlayerConnected(playerid)) {
        return 0;
    }

    char_report_time[playerid] = int;

    return 1;
}

stock Player_GetReportTime(const playerid)
{
    return char_report_time[playerid];
}

#include <report_functions>
#include <report_commands>