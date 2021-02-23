static
    char_warn_num[MAX_PLAYERS] = 0;

/**
 * Get/Set functions
 */
stock Player_SetWarns(const playerid, const warns)
{
    if (!IsPlayerConnected(playerid)) {
        return 0;
    }
    
    char_warn_num[playerid] = warns;

    return 1;
}

stock Player_GetWarns(const playerid)
{
    return char_warn_num[playerid];
}

#include <warn_commands>