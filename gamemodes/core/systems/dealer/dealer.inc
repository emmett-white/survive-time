static
    char_drugs[MAX_PLAYERS];

// * Get/Set functions *
Player_SetDrugs(const playerid, const int)
{
    if (!IsPlayerConnected(playerid)) {
        return 0;
    }

    char_drugs[playerid] = int;

    new String: str_query_drugs_update = String: str_format(
        "UPDATE characters SET char_drugs = '%d' WHERE char_name = '%e'",
        Player_GetDrugs(playerid), ReturnPlayerName(playerid)
    );

    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_drugs_update);

    UI_UpdatePlayerTextDraw(playerid, 3);

    return 1;
}

Player_GetDrugs(const playerid)
{
    return char_drugs[playerid];
}

#include <dealer_functions>
#include <dealer_hooks>
#include <dealer_callbacks>
#include <dealer_commands>