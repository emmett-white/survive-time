static
    PlayerText: ui_textdraw[MAX_PLAYERS][3] = {PlayerText: INVALID_TEXT_DRAW, ...},
    ui_status[MAX_PLAYERS];

// * Functions *
ui_create_player_textdraws(const playerid, bool: status = true)
{
    if (!status) {
        for (new i = 0; i < 3; ++i) {
            PlayerTextDrawDestroy(playerid, PlayerText: ui_textdraw[playerid][i]);
        }

        set_player_ui_status(playerid, 0);

        return 1;
    }

    ui_textdraw[playerid][0] = CreatePlayerTextDraw(playerid, 593.199829, 8.560035, "SURVIVE_~w~TIME");
    PlayerTextDrawLetterSize(playerid, ui_textdraw[playerid][0], 0.282399, 1.375999);
    PlayerTextDrawTextSize(playerid, ui_textdraw[playerid][0], 0.000000, 258.000000);
    PlayerTextDrawAlignment(playerid, ui_textdraw[playerid][0], 2);
    PlayerTextDrawColor(playerid, ui_textdraw[playerid][0], -308521985);
    PlayerTextDrawSetShadow(playerid, ui_textdraw[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, ui_textdraw[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, ui_textdraw[playerid][0], 255);
    PlayerTextDrawFont(playerid, ui_textdraw[playerid][0], 3);
    PlayerTextDrawSetProportional(playerid, ui_textdraw[playerid][0], 1);

    ui_textdraw[playerid][1] = CreatePlayerTextDraw(playerid, 591.599243, 21.953382, "discord.gg/3vux22UJG5");
    PlayerTextDrawLetterSize(playerid, ui_textdraw[playerid][1], 0.187200, 0.875732);
    PlayerTextDrawTextSize(playerid, ui_textdraw[playerid][1], 0.000000, 258.000000);
    PlayerTextDrawAlignment(playerid, ui_textdraw[playerid][1], 2);
    PlayerTextDrawColor(playerid, ui_textdraw[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, ui_textdraw[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, ui_textdraw[playerid][1], 1);
    PlayerTextDrawBackgroundColor(playerid, ui_textdraw[playerid][1], 255);
    PlayerTextDrawFont(playerid, ui_textdraw[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, ui_textdraw[playerid][1], 1);

    ui_textdraw[playerid][2] = CreatePlayerTextDraw(playerid, 316.400573, 423.706695, "________");
    PlayerTextDrawLetterSize(playerid, ui_textdraw[playerid][2], 0.327999, 1.525333);
    PlayerTextDrawAlignment(playerid, ui_textdraw[playerid][2], 2);
    PlayerTextDrawColor(playerid, ui_textdraw[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, ui_textdraw[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, ui_textdraw[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, ui_textdraw[playerid][2], 255);
    PlayerTextDrawFont(playerid, ui_textdraw[playerid][2], 2);
    PlayerTextDrawSetProportional(playerid, ui_textdraw[playerid][2], 1);

    for (new i = 0; i < 3; ++i) {
        PlayerTextDrawShow(playerid, PlayerText: ui_textdraw[playerid][i]);
    }

    set_player_ui_status(playerid, 1);

    return 1;
}

// * Get/Set functions *
set_player_ui_status(const playerid, const int)
{
    ui_status[playerid] = int;

    return 1;
}

get_player_ui_status(const playerid)
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
    PlayerTextDrawSetString(playerid, PlayerText: ui_textdraw[playerid][2], ts_format);
}