// * Variables *
static
    PlayerText: ui_register[MAX_PLAYERS][12] = {PlayerText: INVALID_TEXT_DRAW, ...};

// * Functions
UI_CreateRegisterTextDraws(const playerid, bool: status = true)
{
    if (!status) {
        for (new i = 0; i < 12; ++i) {
            PlayerTextDrawDestroy(playerid, PlayerText: ui_register[playerid][i]);
        }

        CancelSelectTextDraw(playerid);

        return 1;
    }

    ui_register[playerid][0] = CreatePlayerTextDraw(playerid, 163.125000, 144.500045, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ui_register[playerid][0], 313.000000, 144.000000);
    PlayerTextDrawAlignment(playerid, ui_register[playerid][0], 1);
    PlayerTextDrawColor(playerid, ui_register[playerid][0], 153);
    PlayerTextDrawSetShadow(playerid, ui_register[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_register[playerid][0], 255);
    PlayerTextDrawFont(playerid, ui_register[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, ui_register[playerid][0], 0);

    ui_register[playerid][1] = CreatePlayerTextDraw(playerid, 163.125000, 144.500045, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ui_register[playerid][1], 312.000000, 17.000000);
    PlayerTextDrawAlignment(playerid, ui_register[playerid][1], 1);
    PlayerTextDrawColor(playerid, ui_register[playerid][1], 255);
    PlayerTextDrawSetShadow(playerid, ui_register[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_register[playerid][1], 255);
    PlayerTextDrawFont(playerid, ui_register[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, ui_register[playerid][1], 0);

    ui_register[playerid][2] = CreatePlayerTextDraw(playerid, 162.549926, 260.883209, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ui_register[playerid][2], 312.889892, 26.849996);
    PlayerTextDrawAlignment(playerid, ui_register[playerid][2], 1);
    PlayerTextDrawColor(playerid, ui_register[playerid][2], 255);
    PlayerTextDrawSetShadow(playerid, ui_register[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_register[playerid][2], 255);
    PlayerTextDrawFont(playerid, ui_register[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, ui_register[playerid][2], 0);

    ui_register[playerid][3] = CreatePlayerTextDraw(playerid, 316.875000, 149.166702, "SURVIVE_TIME_COPYRIGHT_(c)_2021");
    PlayerTextDrawLetterSize(playerid, ui_register[playerid][3], 0.204999, 0.742499);
    PlayerTextDrawAlignment(playerid, ui_register[playerid][3], 2);
    PlayerTextDrawColor(playerid, ui_register[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, ui_register[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_register[playerid][3], 255);
    PlayerTextDrawFont(playerid, ui_register[playerid][3], 2);
    PlayerTextDrawSetProportional(playerid, ui_register[playerid][3], 1);

    ui_register[playerid][4] = CreatePlayerTextDraw(playerid, 159.375000, 170.749984, "");
    PlayerTextDrawTextSize(playerid, ui_register[playerid][4], 97.000000, 80.000000);
    PlayerTextDrawAlignment(playerid, ui_register[playerid][4], 1);
    PlayerTextDrawColor(playerid, ui_register[playerid][4], -1);
    PlayerTextDrawBackgroundColor(playerid, ui_register[playerid][4], 0x00000000);
    PlayerTextDrawSetShadow(playerid, ui_register[playerid][4], 0);
    PlayerTextDrawFont(playerid, ui_register[playerid][4], 5);
    PlayerTextDrawSetProportional(playerid, ui_register[playerid][4], 0);
    PlayerTextDrawSetPreviewModel(playerid, ui_register[playerid][4], 26);
    PlayerTextDrawSetPreviewRot(playerid, ui_register[playerid][4], 0.000000, 0.000000, 20.000000, 1.000000);

    ui_register[playerid][5] = CreatePlayerTextDraw(playerid, 247.500000, 165.683547, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ui_register[playerid][5], 0.109999, 90.000000);
    PlayerTextDrawAlignment(playerid, ui_register[playerid][5], 1);
    PlayerTextDrawColor(playerid, ui_register[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, ui_register[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_register[playerid][5], 255);
    PlayerTextDrawFont(playerid, ui_register[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, ui_register[playerid][5], 0);

    ui_register[playerid][6] = CreatePlayerTextDraw(playerid, 449.375000, 145.083343, "particle:bloodpool_64");
    PlayerTextDrawTextSize(playerid, ui_register[playerid][6], 22.000000, 16.000000);
    PlayerTextDrawAlignment(playerid, ui_register[playerid][6], 1);
    PlayerTextDrawColor(playerid, ui_register[playerid][6], -16776961);
    PlayerTextDrawSetShadow(playerid, ui_register[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_register[playerid][6], 255);
    PlayerTextDrawFont(playerid, ui_register[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, ui_register[playerid][6], 0);

    ui_register[playerid][7] = CreatePlayerTextDraw(playerid, 460.000000, 148.583312, "x");
    PlayerTextDrawTextSize(playerid, ui_register[playerid][7], 10.0, 20.0);
    PlayerTextDrawLetterSize(playerid, ui_register[playerid][7], 0.283124, 0.917500);
    PlayerTextDrawAlignment(playerid, ui_register[playerid][7], 2);
    PlayerTextDrawColor(playerid, ui_register[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, ui_register[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_register[playerid][7], 255);
    PlayerTextDrawFont(playerid, ui_register[playerid][7], 2);
    PlayerTextDrawSetProportional(playerid, ui_register[playerid][7], 1);
    PlayerTextDrawSetSelectable(playerid, ui_register[playerid][7], true);

    ui_register[playerid][8] = CreatePlayerTextDraw(playerid, 360.000000, 183.766555, "ENTER_PASSWORD");
    PlayerTextDrawTextSize(playerid, ui_register[playerid][8], 10.0, 20.0);
    PlayerTextDrawLetterSize(playerid, ui_register[playerid][8], 0.375000, 1.967500);
    PlayerTextDrawAlignment(playerid, ui_register[playerid][8], 2);
    PlayerTextDrawColor(playerid, ui_register[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, ui_register[playerid][8], 1);
    PlayerTextDrawBackgroundColor(playerid, ui_register[playerid][8], 255);
    PlayerTextDrawFont(playerid, ui_register[playerid][8], 2);
    PlayerTextDrawSetProportional(playerid, ui_register[playerid][8], 1);
    PlayerTextDrawSetSelectable(playerid, ui_register[playerid][8], true);

    ui_register[playerid][9] = CreatePlayerTextDraw(playerid, 312.749938, 214.967926, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ui_register[playerid][9], 95.000000, 20.000000);
    PlayerTextDrawAlignment(playerid, ui_register[playerid][9], 1);
    PlayerTextDrawColor(playerid, ui_register[playerid][9], -16777072);
    PlayerTextDrawSetShadow(playerid, ui_register[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_register[playerid][9], 255);
    PlayerTextDrawFont(playerid, ui_register[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, ui_register[playerid][9], 0);

    ui_register[playerid][10] = CreatePlayerTextDraw(playerid, 359.375000, 214.299865, "EXIT");
    PlayerTextDrawTextSize(playerid, ui_register[playerid][10], 10.0, 20.0);
    PlayerTextDrawLetterSize(playerid, ui_register[playerid][10], 0.375000, 1.967500);
    PlayerTextDrawAlignment(playerid, ui_register[playerid][10], 2);
    PlayerTextDrawColor(playerid, ui_register[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, ui_register[playerid][10], 1);
    PlayerTextDrawBackgroundColor(playerid, ui_register[playerid][10], 255);
    PlayerTextDrawFont(playerid, ui_register[playerid][10], 2);
    PlayerTextDrawSetProportional(playerid, ui_register[playerid][10], 1);
    PlayerTextDrawSetSelectable(playerid, ui_register[playerid][10], true);

    ui_register[playerid][11] = CreatePlayerTextDraw(playerid, 315.625000, 267.583404, "SURVIVE_TIME_REGISTER_SYSTEM~n~CLICK_ON_'ENTER_PASSWORD'_TO_CREATE_AN_ACCOUNT...");
    PlayerTextDrawLetterSize(playerid, ui_register[playerid][11], 0.182499, 0.713333);
    PlayerTextDrawAlignment(playerid, ui_register[playerid][11], 2);
    PlayerTextDrawColor(playerid, ui_register[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, ui_register[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_register[playerid][11], 255);
    PlayerTextDrawFont(playerid, ui_register[playerid][11], 2);
    PlayerTextDrawSetProportional(playerid, ui_register[playerid][11], 1);

    for (new i = 0; i < 12; ++i) {
        PlayerTextDrawShow(playerid, PlayerText: ui_register[playerid][i]);
    }

    SelectTextDraw(playerid, X11_ORANGE);

    return 1;
}

UI_ClickRegisterTextDraw(const playerid, const index)
{
    return _:ui_register[playerid][index];
}