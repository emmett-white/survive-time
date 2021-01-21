static
    char_drugs[MAX_PLAYERS];

// * Get/Set functions *
set_player_drugs(const playerid, const int)
{
    if (!IsPlayerConnected(playerid)) {
        return 0;
    }

    char_drugs[playerid] = int;

    new String: str_query_drugs_update = String: str_format(
        "UPDATE characters SET char_drugs = '%d' WHERE char_name = '%e'",
        get_player_drugs(playerid), ReturnPlayerName(playerid)
    );

    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_drugs_update);

    ui_update_skin_textdraw(playerid, 3);

    return 1;
}

get_player_drugs(const playerid)
{
    return char_drugs[playerid];
}

#include <dealer_functions>
#include <dealer_hooks>
#include <dealer_callbacks>
#include <dealer_commands>