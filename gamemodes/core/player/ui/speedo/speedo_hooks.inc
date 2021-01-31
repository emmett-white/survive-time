#include <YSI_Coding\y_hooks>

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    UI_CreatePlayerSpeedometer(playerid, (newstate == PLAYER_STATE_DRIVER ? (true) : (false)));

    return Y_HOOKS_CONTINUE_RETURN_1;
}