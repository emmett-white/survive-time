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
        get_player_score(playerid), ReturnPlayerName(playerid)
    );

    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

set_player_money(const playerid, const int)
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
        (GetPlayerMoney(playerid) + get_player_money(playerid)), ReturnPlayerName(playerid)
    );

    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

set_player_skin(const playerid, const int)
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
        get_player_skin(playerid), ReturnPlayerName(playerid)
    );

    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

// * Get functions *
get_player_score(const playerid)
{
    return char_score[playerid];
}

get_player_money(const playerid)
{
    return char_money[playerid];
}

get_player_skin(const playerid)
{
    return char_skin[playerid];
}