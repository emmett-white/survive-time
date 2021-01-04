forward init_player_account(const playerid);
public init_player_account(const playerid)
{
    account_id[playerid] = cache_insert_id();
    return 1;
}

forward init_player_character(const playerid);
public init_player_character(const playerid)
{
    char_id[playerid] = cache_insert_id();
    return 1;
}