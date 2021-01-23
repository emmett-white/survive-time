forward OnAccountRegistered(const playerid);
public OnAccountRegistered(const playerid)
{
    account_id[playerid] = cache_insert_id();
    return 1;
}

forward OnCharacterRegistered(const playerid);
public OnCharacterRegistered(const playerid)
{
    char_id[playerid] = cache_insert_id();
    return 1;
}