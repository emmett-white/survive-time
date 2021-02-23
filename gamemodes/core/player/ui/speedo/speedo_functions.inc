static
    PlayerText: ui_speedometer[MAX_PLAYERS][17] = {PlayerText: INVALID_TEXT_DRAW, ...};
    
stock UI_CreatePlayerSpeedometer(const playerid, bool: status = true)
{
    if (!status) {
        for (new i = 0; i < 17; ++i) {
            PlayerTextDrawDestroy(playerid, PlayerText: ui_speedometer[playerid][i]);
        }

        return 1;
    }

    ui_speedometer[playerid][0] = CreatePlayerTextDraw(playerid, 243.345947, 374.011077, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ui_speedometer[playerid][0], 154.000000, 109.000000);
    PlayerTextDrawAlignment(playerid, ui_speedometer[playerid][0], 1);
    PlayerTextDrawColor(playerid, ui_speedometer[playerid][0], -308521985);
    PlayerTextDrawSetShadow(playerid, ui_speedometer[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_speedometer[playerid][0], 255);
    PlayerTextDrawFont(playerid, ui_speedometer[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, ui_speedometer[playerid][0], 0);

    ui_speedometer[playerid][1] = CreatePlayerTextDraw(playerid, 244.925323, 374.344207, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ui_speedometer[playerid][1], 152.200988, 109.000000);
    PlayerTextDrawAlignment(playerid, ui_speedometer[playerid][1], 1);
    PlayerTextDrawColor(playerid, ui_speedometer[playerid][1], 255);
    PlayerTextDrawSetShadow(playerid, ui_speedometer[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_speedometer[playerid][1], 255);
    PlayerTextDrawFont(playerid, ui_speedometer[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, ui_speedometer[playerid][1], 0);

    ui_speedometer[playerid][2] = CreatePlayerTextDraw(playerid, 318.499084, 375.366607, vehicle_names[GetVehicleModel(GetPlayerVehicleID(playerid)) - 400]);
    PlayerTextDrawLetterSize(playerid, ui_speedometer[playerid][2], 0.226873, 0.975832);
    PlayerTextDrawAlignment(playerid, ui_speedometer[playerid][2], 2);
    PlayerTextDrawColor(playerid, ui_speedometer[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, ui_speedometer[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_speedometer[playerid][2], 255);
    PlayerTextDrawFont(playerid, ui_speedometer[playerid][2], 2);
    PlayerTextDrawSetProportional(playerid, ui_speedometer[playerid][2], 1);

    ui_speedometer[playerid][3] = CreatePlayerTextDraw(playerid, 246.125000, 385.366424, "LD_BEAT:CHIT");
    PlayerTextDrawTextSize(playerid, ui_speedometer[playerid][3], 42.000000, 49.000000);
    PlayerTextDrawAlignment(playerid, ui_speedometer[playerid][3], 1);
    PlayerTextDrawColor(playerid, ui_speedometer[playerid][3], -308521985);
    PlayerTextDrawSetShadow(playerid, ui_speedometer[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_speedometer[playerid][3], 255);
    PlayerTextDrawFont(playerid, ui_speedometer[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, ui_speedometer[playerid][3], 0);

    ui_speedometer[playerid][4] = CreatePlayerTextDraw(playerid, 325.599975, 365.377807, "");
    PlayerTextDrawTextSize(playerid, ui_speedometer[playerid][4], 82.000000, 101.000000);
    PlayerTextDrawAlignment(playerid, ui_speedometer[playerid][4], 1);
    PlayerTextDrawColor(playerid, ui_speedometer[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, ui_speedometer[playerid][4], 0);
    PlayerTextDrawFont(playerid, ui_speedometer[playerid][4], 5);
    PlayerTextDrawBackgroundColor(playerid, ui_speedometer[playerid][4], 0x00000000);
    PlayerTextDrawSetProportional(playerid, ui_speedometer[playerid][4], 0);
    PlayerTextDrawSetPreviewModel(playerid, ui_speedometer[playerid][4], GetVehicleModel(GetPlayerVehicleID(playerid)));
    PlayerTextDrawSetPreviewRot(playerid, ui_speedometer[playerid][4], -10.000000, 0.000000, -25.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, ui_speedometer[playerid][4], 1, 1);

    ui_speedometer[playerid][5] = CreatePlayerTextDraw(playerid, 285.524505, 385.277679, "LD_BEAT:CHIT");
    PlayerTextDrawTextSize(playerid, ui_speedometer[playerid][5], 42.000000, 49.000000);
    PlayerTextDrawAlignment(playerid, ui_speedometer[playerid][5], 1);
    PlayerTextDrawColor(playerid, ui_speedometer[playerid][5], -308521985);
    PlayerTextDrawSetShadow(playerid, ui_speedometer[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_speedometer[playerid][5], 255);
    PlayerTextDrawFont(playerid, ui_speedometer[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, ui_speedometer[playerid][5], 0);

    ui_speedometer[playerid][6] = CreatePlayerTextDraw(playerid, 284.799957, 389.910980, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ui_speedometer[playerid][6], 1.000000, 44.000000);
    PlayerTextDrawAlignment(playerid, ui_speedometer[playerid][6], 1);
    PlayerTextDrawColor(playerid, ui_speedometer[playerid][6], -308521985);
    PlayerTextDrawSetShadow(playerid, ui_speedometer[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_speedometer[playerid][6], 255);
    PlayerTextDrawFont(playerid, ui_speedometer[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, ui_speedometer[playerid][6], 0);

    ui_speedometer[playerid][7] = CreatePlayerTextDraw(playerid, 279.275024, 389.905670, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ui_speedometer[playerid][7], 6.579897, 0.899999);
    PlayerTextDrawAlignment(playerid, ui_speedometer[playerid][7], 1);
    PlayerTextDrawColor(playerid, ui_speedometer[playerid][7], -308521985);
    PlayerTextDrawSetShadow(playerid, ui_speedometer[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_speedometer[playerid][7], 255);
    PlayerTextDrawFont(playerid, ui_speedometer[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, ui_speedometer[playerid][7], 0);

    ui_speedometer[playerid][8] = CreatePlayerTextDraw(playerid, 285.450927, 432.983612, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ui_speedometer[playerid][8], 6.579897, 0.899999);
    PlayerTextDrawAlignment(playerid, ui_speedometer[playerid][8], 1);
    PlayerTextDrawColor(playerid, ui_speedometer[playerid][8], -308521985);
    PlayerTextDrawSetShadow(playerid, ui_speedometer[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_speedometer[playerid][8], 255);
    PlayerTextDrawFont(playerid, ui_speedometer[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, ui_speedometer[playerid][8], 0);

    ui_speedometer[playerid][9] = CreatePlayerTextDraw(playerid, 267.000000, 428.372436, "SPEED");
    PlayerTextDrawLetterSize(playerid, ui_speedometer[playerid][9], 0.143123, 0.783333);
    PlayerTextDrawAlignment(playerid, ui_speedometer[playerid][9], 2);
    PlayerTextDrawColor(playerid, ui_speedometer[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, ui_speedometer[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_speedometer[playerid][9], 255);
    PlayerTextDrawFont(playerid, ui_speedometer[playerid][9], 2);
    PlayerTextDrawSetProportional(playerid, ui_speedometer[playerid][9], 1);

    ui_speedometer[playerid][10] = CreatePlayerTextDraw(playerid, 306.292053, 428.050231, "HEALTH");
    PlayerTextDrawLetterSize(playerid, ui_speedometer[playerid][10], 0.138124, 0.765833);
    PlayerTextDrawAlignment(playerid, ui_speedometer[playerid][10], 2);
    PlayerTextDrawColor(playerid, ui_speedometer[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, ui_speedometer[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_speedometer[playerid][10], 255);
    PlayerTextDrawFont(playerid, ui_speedometer[playerid][10], 2);
    PlayerTextDrawSetProportional(playerid, ui_speedometer[playerid][10], 1);

    ui_speedometer[playerid][11] = CreatePlayerTextDraw(playerid, 278.849822, 432.939300, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ui_speedometer[playerid][11], 6.579897, 0.899999);
    PlayerTextDrawAlignment(playerid, ui_speedometer[playerid][11], 1);
    PlayerTextDrawColor(playerid, ui_speedometer[playerid][11], -308521985);
    PlayerTextDrawSetShadow(playerid, ui_speedometer[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_speedometer[playerid][11], 255);
    PlayerTextDrawFont(playerid, ui_speedometer[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, ui_speedometer[playerid][11], 0);

    ui_speedometer[playerid][12] = CreatePlayerTextDraw(playerid, 285.124664, 390.044555, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ui_speedometer[playerid][12], 6.579897, 0.899999);
    PlayerTextDrawAlignment(playerid, ui_speedometer[playerid][12], 1);
    PlayerTextDrawColor(playerid, ui_speedometer[playerid][12], -308521985);
    PlayerTextDrawSetShadow(playerid, ui_speedometer[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_speedometer[playerid][12], 255);
    PlayerTextDrawFont(playerid, ui_speedometer[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, ui_speedometer[playerid][12], 0);

    ui_speedometer[playerid][13] = CreatePlayerTextDraw(playerid, 247.121917, 385.966461, "LD_BEAT:CHIT");
    PlayerTextDrawTextSize(playerid, ui_speedometer[playerid][13], 40.000000, 48.000000);
    PlayerTextDrawAlignment(playerid, ui_speedometer[playerid][13], 1);
    PlayerTextDrawColor(playerid, ui_speedometer[playerid][13], 255);
    PlayerTextDrawSetShadow(playerid, ui_speedometer[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_speedometer[playerid][13], 255);
    PlayerTextDrawFont(playerid, ui_speedometer[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, ui_speedometer[playerid][13], 0);

    ui_speedometer[playerid][14] = CreatePlayerTextDraw(playerid, 286.497863, 385.649993, "LD_BEAT:CHIT");
    PlayerTextDrawTextSize(playerid, ui_speedometer[playerid][14], 40.000000, 48.000000);
    PlayerTextDrawAlignment(playerid, ui_speedometer[playerid][14], 1);
    PlayerTextDrawColor(playerid, ui_speedometer[playerid][14], 255);
    PlayerTextDrawSetShadow(playerid, ui_speedometer[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_speedometer[playerid][14], 255);
    PlayerTextDrawFont(playerid, ui_speedometer[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, ui_speedometer[playerid][14], 0);

    ui_speedometer[playerid][15] = CreatePlayerTextDraw(playerid, 266.700134, 402.022399, "220");
    PlayerTextDrawLetterSize(playerid, ui_speedometer[playerid][15], 0.267498, 1.384166);
    PlayerTextDrawTextSize(playerid, ui_speedometer[playerid][15], 0.000000, 0.069999);
    PlayerTextDrawAlignment(playerid, ui_speedometer[playerid][15], 2);
    PlayerTextDrawColor(playerid, ui_speedometer[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, ui_speedometer[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_speedometer[playerid][15], 255);
    PlayerTextDrawFont(playerid, ui_speedometer[playerid][15], 3);
    PlayerTextDrawSetProportional(playerid, ui_speedometer[playerid][15], 1);

    ui_speedometer[playerid][16] = CreatePlayerTextDraw(playerid, 306.490905, 402.511169, "1000");
    PlayerTextDrawLetterSize(playerid, ui_speedometer[playerid][16], 0.267498, 1.384166);
    PlayerTextDrawTextSize(playerid, ui_speedometer[playerid][16], 0.000000, 0.069999);
    PlayerTextDrawAlignment(playerid, ui_speedometer[playerid][16], 2);
    PlayerTextDrawColor(playerid, ui_speedometer[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, ui_speedometer[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_speedometer[playerid][16], 255);
    PlayerTextDrawFont(playerid, ui_speedometer[playerid][16], 3);
    PlayerTextDrawSetProportional(playerid, ui_speedometer[playerid][16], 1);

    for (new i = 0; i < 17; ++i) {
        PlayerTextDrawShow(playerid, PlayerText: ui_speedometer[playerid][i]);
    }

    return 1;
}

stock GetVehicleSpeed(vehicleid)
{
    static
        pos_y,
        pos_x,
        pos_z,
        Float: veh_speed;

    GetVehicleVelocity(vehicleid, Float: pos_x, Float: pos_y, Float: pos_z);
    veh_speed = (floatsqroot((Float: pos_x * Float: pos_x) + (Float: pos_y * Float: pos_y) + (Float: pos_z * Float: pos_z)) * 200);
    
    return floatround(Float: veh_speed, floatround_round);
}

stock GetVehicleHP(vehicleid)
{
    static
        health;

    GetVehicleHealth(vehicleid, Float: health);

    return _:health;
}

/**
 * Vehicle speed and health(damage) timer
 */
ptask update_vehicle[1](playerid)
{
    if (IsPlayerInAnyVehicle(playerid)) {
        va_PlayerTextDrawSetString(
            playerid, PlayerText: ui_speedometer[playerid][15],
            "%d", GetVehicleSpeed(GetPlayerVehicleID(playerid))
        );

        va_PlayerTextDrawSetString(
            playerid, PlayerText: ui_speedometer[playerid][16],
            "%.0f", GetVehicleHP(GetPlayerVehicleID(playerid))
        );
    }
}