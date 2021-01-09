// * Variables *
new
    char_warn_num[MAX_PLAYERS] = 0;

// * Functions *
set_player_warns(const playerid, const warns)
{
    if (!IsPlayerConnected(playerid))
        return 0;
    
    char_warn_num[playerid] = warns;

    return 1;
}

get_player_warns(const playerid)
{
    return char_warn_num[playerid];
}

#include <warn_commands>