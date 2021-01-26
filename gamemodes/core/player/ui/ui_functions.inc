static
    PlayerText: ui_textdraw[MAX_PLAYERS][14] = {PlayerText: INVALID_TEXT_DRAW, ...},
    ui_status[MAX_PLAYERS];

// * Functions *
UI_CreatePlayerTextDraws(const playerid, bool: status = true)
{
    if (!status) {
        for (new i = 0; i < 14; ++i) {
            PlayerTextDrawDestroy(playerid, PlayerText: ui_textdraw[playerid][i]);
        }

        Player_SetUIStatus(playerid, 0);

        return 1;
    }

    ui_textdraw[playerid][0] = CreatePlayerTextDraw(playerid, 525.200134, 7.066679, "~y~discord.gg/3vux22UJG5");
    PlayerTextDrawLetterSize(playerid, ui_textdraw[playerid][0], 0.247999, 0.898133);
    PlayerTextDrawAlignment(playerid, ui_textdraw[playerid][0], 1);
    PlayerTextDrawColor(playerid, ui_textdraw[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, ui_textdraw[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, ui_textdraw[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, ui_textdraw[playerid][0], 255);
    PlayerTextDrawFont(playerid, ui_textdraw[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, ui_textdraw[playerid][0], 1);

    ui_textdraw[playerid][1] = CreatePlayerTextDraw(playerid, 526.599670, 346.893463, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ui_textdraw[playerid][1], 117.000000, 115.000000);
    PlayerTextDrawAlignment(playerid, ui_textdraw[playerid][1], 1);
    PlayerTextDrawColor(playerid, ui_textdraw[playerid][1], 858993663);
    PlayerTextDrawSetShadow(playerid, ui_textdraw[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_textdraw[playerid][1], 255);
    PlayerTextDrawFont(playerid, ui_textdraw[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, ui_textdraw[playerid][1], 0);

    ui_textdraw[playerid][2] = CreatePlayerTextDraw(playerid, 551.298828, 426.553680, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ui_textdraw[playerid][2], 68.000000, 14.000000);
    PlayerTextDrawAlignment(playerid, ui_textdraw[playerid][2], 1);
    PlayerTextDrawColor(playerid, ui_textdraw[playerid][2], 144);
    PlayerTextDrawSetShadow(playerid, ui_textdraw[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_textdraw[playerid][2], 255);
    PlayerTextDrawFont(playerid, ui_textdraw[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, ui_textdraw[playerid][2], 0);

    ui_textdraw[playerid][3] = CreatePlayerTextDraw(playerid, 585.700256, 428.933441, "________");
    PlayerTextDrawLetterSize(playerid, ui_textdraw[playerid][3], 0.228799, 1.017599);
    PlayerTextDrawTextSize(playerid, ui_textdraw[playerid][3], 0.000000, 295.000000);
    PlayerTextDrawAlignment(playerid, ui_textdraw[playerid][3], 2);
    PlayerTextDrawColor(playerid, ui_textdraw[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, ui_textdraw[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_textdraw[playerid][3], 255);
    PlayerTextDrawFont(playerid, ui_textdraw[playerid][3], 2);
    PlayerTextDrawSetProportional(playerid, ui_textdraw[playerid][3], 1);

    ui_textdraw[playerid][4] = CreatePlayerTextDraw(playerid, 583.999938, 351.826629, ReturnPlayerName(playerid));
    PlayerTextDrawLetterSize(playerid, ui_textdraw[playerid][4], 0.228799, 1.017599);
    PlayerTextDrawTextSize(playerid, ui_textdraw[playerid][4], 0.000000, 295.000000);
    PlayerTextDrawAlignment(playerid, ui_textdraw[playerid][4], 2);
    PlayerTextDrawColor(playerid, ui_textdraw[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, ui_textdraw[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_textdraw[playerid][4], 255);
    PlayerTextDrawFont(playerid, ui_textdraw[playerid][4], 2);
    PlayerTextDrawSetProportional(playerid, ui_textdraw[playerid][4], 1);

    ui_textdraw[playerid][5] = va_CreatePlayerTextDraw(playerid, 585.899047, 368.006713, "SCORE: ~y~%d", Player_GetScore(playerid));
    PlayerTextDrawLetterSize(playerid, ui_textdraw[playerid][5], 0.228799, 1.017599);
    PlayerTextDrawTextSize(playerid, ui_textdraw[playerid][5], 0.000000, 1024.000000);
    PlayerTextDrawAlignment(playerid, ui_textdraw[playerid][5], 2);
    PlayerTextDrawColor(playerid, ui_textdraw[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, ui_textdraw[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_textdraw[playerid][5], 255);
    PlayerTextDrawFont(playerid, ui_textdraw[playerid][5], 2);
    PlayerTextDrawSetProportional(playerid, ui_textdraw[playerid][5], 1);

    ui_textdraw[playerid][6] = va_CreatePlayerTextDraw(playerid, 585.199218, 383.707672, "DRUGS: ~y~%d", Player_GetDrugs(playerid));
    PlayerTextDrawLetterSize(playerid, ui_textdraw[playerid][6], 0.228799, 1.017599);
    PlayerTextDrawTextSize(playerid, ui_textdraw[playerid][6], 0.000000, 1024.000000);
    PlayerTextDrawAlignment(playerid, ui_textdraw[playerid][6], 2);
    PlayerTextDrawColor(playerid, ui_textdraw[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, ui_textdraw[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_textdraw[playerid][6], 255);
    PlayerTextDrawFont(playerid, ui_textdraw[playerid][6], 2);
    PlayerTextDrawSetProportional(playerid, ui_textdraw[playerid][6], 1);

    ui_textdraw[playerid][7] = CreatePlayerTextDraw(playerid, 551.898498, 381.904785, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ui_textdraw[playerid][7], 68.000000, 14.000000);
    PlayerTextDrawAlignment(playerid, ui_textdraw[playerid][7], 1);
    PlayerTextDrawColor(playerid, ui_textdraw[playerid][7], 144);
    PlayerTextDrawSetShadow(playerid, ui_textdraw[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_textdraw[playerid][7], 255);
    PlayerTextDrawFont(playerid, ui_textdraw[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, ui_textdraw[playerid][7], 0);

    ui_textdraw[playerid][8] = CreatePlayerTextDraw(playerid, 551.898498, 366.203826, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ui_textdraw[playerid][8], 68.000000, 14.000000);
    PlayerTextDrawAlignment(playerid, ui_textdraw[playerid][8], 1);
    PlayerTextDrawColor(playerid, ui_textdraw[playerid][8], 144);
    PlayerTextDrawSetShadow(playerid, ui_textdraw[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_textdraw[playerid][8], 255);
    PlayerTextDrawFont(playerid, ui_textdraw[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, ui_textdraw[playerid][8], 0);

    ui_textdraw[playerid][9] = va_CreatePlayerTextDraw(playerid, 585.199218, 399.408630, "SKIN: ~y~%d", GetPlayerSkin(playerid));
    PlayerTextDrawLetterSize(playerid, ui_textdraw[playerid][9], 0.228799, 1.017599);
    PlayerTextDrawTextSize(playerid, ui_textdraw[playerid][9], 0.000000, 1024.000000);
    PlayerTextDrawAlignment(playerid, ui_textdraw[playerid][9], 2);
    PlayerTextDrawColor(playerid, ui_textdraw[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, ui_textdraw[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_textdraw[playerid][9], 255);
    PlayerTextDrawFont(playerid, ui_textdraw[playerid][9], 2);
    PlayerTextDrawSetProportional(playerid, ui_textdraw[playerid][9], 1);

    ui_textdraw[playerid][10] = CreatePlayerTextDraw(playerid, 551.898498, 397.405731, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ui_textdraw[playerid][10], 68.000000, 14.000000);
    PlayerTextDrawAlignment(playerid, ui_textdraw[playerid][10], 1);
    PlayerTextDrawColor(playerid, ui_textdraw[playerid][10], 144);
    PlayerTextDrawSetShadow(playerid, ui_textdraw[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_textdraw[playerid][10], 255);
    PlayerTextDrawFont(playerid, ui_textdraw[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, ui_textdraw[playerid][10], 0);

    ui_textdraw[playerid][11] = CreatePlayerTextDraw(playerid, 563.898376, 418.212402, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ui_textdraw[playerid][11], 41.000000, 1.000000);
    PlayerTextDrawAlignment(playerid, ui_textdraw[playerid][11], 1);
    PlayerTextDrawColor(playerid, ui_textdraw[playerid][11], 144);
    PlayerTextDrawSetShadow(playerid, ui_textdraw[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_textdraw[playerid][11], 255);
    PlayerTextDrawFont(playerid, ui_textdraw[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, ui_textdraw[playerid][11], 0);

    ui_textdraw[playerid][12] = CreatePlayerTextDraw(playerid, 527.400329, 347.440124, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ui_textdraw[playerid][12], 1.000000, 99.000000);
    PlayerTextDrawAlignment(playerid, ui_textdraw[playerid][12], 1);
    PlayerTextDrawColor(playerid, ui_textdraw[playerid][12], 144);
    PlayerTextDrawSetShadow(playerid, ui_textdraw[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_textdraw[playerid][12], 255);
    PlayerTextDrawFont(playerid, ui_textdraw[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, ui_textdraw[playerid][12], 0);

    ui_textdraw[playerid][13] = CreatePlayerTextDraw(playerid, 527.400329, 346.940093, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ui_textdraw[playerid][13], 156.000000, 1.130000);
    PlayerTextDrawAlignment(playerid, ui_textdraw[playerid][13], 1);
    PlayerTextDrawColor(playerid, ui_textdraw[playerid][13], 144);
    PlayerTextDrawSetShadow(playerid, ui_textdraw[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_textdraw[playerid][13], 255);
    PlayerTextDrawFont(playerid, ui_textdraw[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, ui_textdraw[playerid][13], 0);

    for (new i = 0; i < 14; ++i) {
        PlayerTextDrawShow(playerid, PlayerText: ui_textdraw[playerid][i]);
    }

    Player_SetUIStatus(playerid, 1);

    return 1;
}

UI_UpdatePlayerTextDraw(const playerid, value)
{
    switch (value) {
        case 1: {
            va_PlayerTextDrawSetString(
                playerid, PlayerText: ui_textdraw[playerid][9],
                "SKIN: ~y~%d", GetPlayerSkin(playerid)
            );
        }

        case 2: {
            va_PlayerTextDrawSetString(
                playerid, PlayerText: ui_textdraw[playerid][5],
                "SCORE: ~y~%d", Player_GetScore(playerid)
            );
        }

        case 3: {
            va_PlayerTextDrawSetString(
                playerid, PlayerText: ui_textdraw[playerid][6],
                "DRUGS: ~y~%d", Player_GetDrugs(playerid)
            );
        }
    }

    return 1;
}

// * Get/Set functions *
Player_SetUIStatus(const playerid, const int)
{
    ui_status[playerid] = int;

    return 1;
}

Player_GetUIStatus(const playerid)
{
    return ui_status[playerid];
}

// * Clock timer *
ptask clock_timer[1000](playerid)
{
    new
        Timestamp: ts = Timestamp: Now(),
        ts_format[12];

    TimeFormat(Timestamp: ts, ISO6801_TIME, ts_format, sizeof ts_format);
    PlayerTextDrawSetString(playerid, PlayerText: ui_textdraw[playerid][3], ts_format);
}