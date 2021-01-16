#include <YSI_Coding\y_hooks>

// * Hooks *
hook OnPlayerConnect(playerid)
{
	check_player_banned(playerid);

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerSpawn(playerid)
{
    new
		pos_x,
		pos_y,
		pos_z,
		pos_a,

		interior,
		world;

	GetPlayerPos(playerid, Float: pos_x, Float: pos_y, Float: pos_z);
    GetPlayerFacingAngle(playerid, Float: pos_a);

	// We need to set position for avoid small player fall after spawn
	Streamer_UpdateEx(playerid, Float: pos_x, Float: pos_y, Float: pos_z, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid), .compensatedtime = 2000);

	SetPlayerFacingAngle(playerid, Float: pos_a);
	SetPlayerInterior(playerid, interior);
	SetPlayerVirtualWorld(playerid, world);
	SetPlayerSkin(playerid, get_player_skin(playerid));

	ui_create_player_textdraws(playerid);

    return Y_HOOKS_CONTINUE_RETURN_1;
}