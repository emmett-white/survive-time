#include <YSI_Coding\y_hooks>

// * Hooks *
hook OnPlayerConnect(playerid)
{
    // Reset variables
    gPlayerLoginAttempts[playerid] =
    char_admin[playerid] =
    char_money[playerid] =
    char_skin[playerid] =
    char_score[playerid] = 0;
    
	check_player_banned(playerid);
    // check_player_account(playerid);

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerSpawn(playerid)
{
    new
		Float: pos_x,
		Float: pos_y,
		Float: pos_z,
		Float: pos_a,

		interior,
		world;

	GetPlayerPos(playerid, pos_x, pos_y, pos_z);
    GetPlayerFacingAngle(playerid, pos_a);

	// We need to set position for avoid small player fall after spawn
	Streamer_UpdateEx(playerid, pos_x, pos_y, pos_z, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid), .compensatedtime = 2000);

	SetPlayerFacingAngle(playerid, pos_a);
	SetPlayerInterior(playerid, interior);
	SetPlayerVirtualWorld(playerid, world);

    return Y_HOOKS_CONTINUE_RETURN_1;
}