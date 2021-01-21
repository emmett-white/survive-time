#include <YSI_Coding\y_hooks>

static
    BitArray: LAYING_ANIMATION<MAX_PLAYERS>;

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if (PRESSED(KEY_NO)  && !IsPlayerInAnyVehicle(playerid)) {
        if (!Bit_Get(LAYING_ANIMATION, playerid)) {
            // Smth like lay animation...
            ApplyAnimation(playerid, "PED", "KO_shot_front", 4.0, 0, 1, 1, 1, 0);

            Bit_Let(LAYING_ANIMATION, playerid);

            return 1;
        }

        Bit_Set(LAYING_ANIMATION, playerid, false);
        ClearAnimations(playerid);
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}