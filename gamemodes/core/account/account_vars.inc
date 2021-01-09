// * Variables *
new
    account_id[MAX_PLAYERS],
    account_password[MAX_PLAYERS][64],
    
    player_login_attempts[MAX_PLAYERS],
    
    char_id[MAX_PLAYERS],
    char_score[MAX_PLAYERS],
    char_money[MAX_PLAYERS],
    char_skin[MAX_PLAYERS];

// * Set functions *
set_player_score(const playerid, const int)
{
    if (!IsPlayerConnected(playerid))
        return 0;

    char_score[playerid] = int;

    return 1;
}

set_player_money(const playerid, const int)
{
    if (!IsPlayerConnected(playerid))
        return 0;

    char_money[playerid] = int;

    return 1;
}

set_player_skin(const playerid, const int)
{
    if (!IsPlayerConnected(playerid))
        return 0;

    char_skin[playerid] = int;

    return 1;
}