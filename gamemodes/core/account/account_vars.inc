/**
 * Variables
 */
new
    account_id[MAX_PLAYERS],
    account_password[MAX_PLAYERS][64],
    
    player_login_attempts[MAX_PLAYERS],
    
    char_id[MAX_PLAYERS],
    char_score[MAX_PLAYERS],
    char_money[MAX_PLAYERS],
    char_skin[MAX_PLAYERS];

/**
 * Set functions
 */
stock Player_SetScore(const playerid, const int)
{
    if (!IsPlayerConnected(playerid)) {
        return 0;
    }

    char_score[playerid] = int;

    new String: str_query_update = String: str_format(
        "UPDATE \
            characters \
        SET \
            char_score = '%d' \
        WHERE \
            char_name = '%e'",
        Player_GetScore(playerid), ReturnPlayerName(playerid)
    );

    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    UI_UpdatePlayerTextDraw(playerid, 2);

    return 1;
}

stock Player_SetMoney(const playerid, const int)
{
    if (!IsPlayerConnected(playerid)) {
        return 0;
    }

    char_money[playerid] = int;

    new String: str_query_update = String: str_format(
        "UPDATE \
            characters \
        SET \
            char_money = '%d' \
        WHERE \
            char_name = '%e'",
        (GetPlayerMoney(playerid) + Player_GetMoney(playerid)), ReturnPlayerName(playerid)
    );

    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

stock Player_SetSkin(const playerid, const int)
{
    if (!IsPlayerConnected(playerid)) {
        return 0;
    }

    char_skin[playerid] = int;

    new String: str_query_update = String: str_format(
        "UPDATE \
            characters \
        SET \
            char_skin = '%d' \
        WHERE \
            char_name = '%e'",
        Player_GetSkin(playerid), ReturnPlayerName(playerid)
    );

    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    UI_UpdatePlayerTextDraw(playerid, 1);

    return 1;
}

/**
 * Get functions
 */
stock Player_GetScore(const playerid)
{
    return char_score[playerid];
}

stock Player_GetMoney(const playerid)
{
    return char_money[playerid];
}

stock Player_GetSkin(const playerid)
{
    return char_skin[playerid];
}