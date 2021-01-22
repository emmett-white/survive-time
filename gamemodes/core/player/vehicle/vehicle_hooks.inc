#include <YSI_Coding\y_hooks>

// * Hooks *
hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    // Vehicle engine
    if (PRESSED(KEY_SUBMISSION) && IsPlayerInAnyVehicle(playerid)) {
        Vehicle_SetEngineState(GetPlayerVehicleID(playerid),
            Vehicle_GetEngineState(GetPlayerVehicleID(playerid)) ? (E_ENGINE_STATE_OFF) : (E_ENGINE_STATE_ON)
        );

        UI_ShowPlayerHelpMsg(
            playerid, "~w~You_have_switched_%s_~w~the_vehice_engine.",
            Vehicle_GetEngineState(GetPlayerVehicleID(playerid)) ? ("~g~on") : ("~r~off")
        );
    }

    // Vehicle lights
    if (PRESSED(KEY_YES) && IsPlayerInAnyVehicle(playerid)) {
        Vehicle_SetLightsRunState(GetPlayerVehicleID(playerid),
            Vehicle_GetLightsRunState(GetPlayerVehicleID(playerid)) ? (E_LIGHTS_OFF) : (E_LIGHTS_ON)
        );

        UI_ShowPlayerHelpMsg(
            playerid, "~w~You_have_switched_%s_~w~the_vehice_lights.",
            Vehicle_GetLightsRunState(GetPlayerVehicleID(playerid)) ? ("~g~on") : ("~r~off")
        );
    }

    // Vehicle lock
    if (PRESSED(KEY_NO) && IsPlayerInAnyVehicle(playerid)) {
        Vehicle_SetLockState(GetPlayerVehicleID(playerid),
            Vehicle_GetLockState(GetPlayerVehicleID(playerid)) ? (E_LOCK_STATE_OFF) : (E_LOCK_STATE_ON)
        );

        UI_ShowPlayerHelpMsg(
            playerid, "~w~You_have_%s_~w~the_vehice.",
            Vehicle_GetLockState(GetPlayerVehicleID(playerid)) ? ("~r~locked") : ("~g~unlocked")
        );
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerEnterVehicle(playerid, vehicleid, bool:ispassenger)
{
    Vehicle_SetLockState(vehicleid, E_LOCK_STATE_OFF);

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerExitVehicle(playerid, vehicleid)
{
    Vehicle_SetLockState(vehicleid, E_LOCK_STATE_OFF);

    return Y_HOOKS_CONTINUE_RETURN_1;
}