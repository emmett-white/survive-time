hook OnPlayerText(playerid, text[])
{
    if (char_muted[playerid])
        return fmt_err(playerid, "You're muted for %d minutes.", char_muted_mins[playerid]), 0;

    return Y_HOOKS_CONTINUE_RETURN_1;
}