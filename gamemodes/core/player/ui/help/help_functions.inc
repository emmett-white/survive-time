static
    PlayerText: help_msg_textdraw[MAX_PLAYERS] = {PlayerText: INVALID_TEXT_DRAW, ...};

/**
 * Functions
 */
UI_CreatePlayerHelpMsg(const playerid, bool: status = true)
{
    if (!status) {
        PlayerTextDrawHide(playerid, PlayerText: help_msg_textdraw[playerid]);

        return 1;
    }

    help_msg_textdraw[playerid] = CreatePlayerTextDraw(playerid, 320.499633, 319.313629, "_");
    PlayerTextDrawLetterSize(playerid, help_msg_textdraw[playerid], 0.266399, 0.838399);
    PlayerTextDrawTextSize(playerid, help_msg_textdraw[playerid], 0.000000, 744.000000);
    PlayerTextDrawAlignment(playerid, help_msg_textdraw[playerid], 2);
    PlayerTextDrawColor(playerid, help_msg_textdraw[playerid], -1);
    PlayerTextDrawSetShadow(playerid, help_msg_textdraw[playerid], 0);
    PlayerTextDrawSetOutline(playerid, help_msg_textdraw[playerid], 1);
    PlayerTextDrawBackgroundColor(playerid, help_msg_textdraw[playerid], 255);
    PlayerTextDrawFont(playerid, help_msg_textdraw[playerid], 1);
    PlayerTextDrawSetProportional(playerid, help_msg_textdraw[playerid], 1);

    PlayerTextDrawShow(playerid, PlayerText: help_msg_textdraw[playerid]);

    return 1;
}

UI_ShowPlayerHelpMsg(const playerid, const string: fmt[], va_args<>)
{
    PlayerTextDrawShow(playerid, PlayerText: help_msg_textdraw[playerid]);
    PlayerTextDrawSetString(playerid, PlayerText: help_msg_textdraw[playerid], va_return(fmt, va_start<2>));

    defer hide_help_msg(playerid);

    return 1;
}

/**
 * Hide message timer
 */
timer hide_help_msg[2000](playerid)
{
    UI_CreatePlayerHelpMsg(playerid, false);
}