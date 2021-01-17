#include <YSI_Coding\y_hooks>

// * Hooks *
hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    // Vehicle engine
    if (PRESSED(KEY_SUBMISSION) && IsPlayerInAnyVehicle(playerid)) {
        Vehicle_SetEngineState(GetPlayerVehicleID(playerid),
            Vehicle_GetEngineState(GetPlayerVehicleID(playerid)) ? (E_ENGINE_STATE_OFF) : (E_ENGINE_STATE_ON)
        );

        show_player_help_msg(
            playerid, "~w~You_have_switched_%s_~w~the_vehice_engine.",
            Vehicle_GetEngineState(GetPlayerVehicleID(playerid)) ? ("~g~on") : ("~r~off")
        );
    }

    // Vehicle lights

    // Vehicle lock

    return Y_HOOKS_CONTINUE_RETURN_1;
}