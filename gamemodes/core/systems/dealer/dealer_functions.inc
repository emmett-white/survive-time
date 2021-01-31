const MAX_DEALERS = 50;

/**
 * Variables
 */
new
    Iterator: Iter_Dealers<MAX_DEALERS>,
    Text3D: dealer_label[MAX_DEALERS],

    dealer_id[MAX_DEALERS],
    dealer_actor[MAX_DEALERS],
    dealer_skin[MAX_DEALERS],

    Float: dealer_x[MAX_DEALERS],
    Float: dealer_y[MAX_DEALERS],
    Float: dealer_z[MAX_DEALERS],
    Float: dealer_a[MAX_DEALERS],
    
    dealer_name[MAX_DEALERS][MAX_PLAYER_NAME];

/**
  * <param name="skin">Skin of the dealer actor</param>
  * <param name="name">Name of the dealer (3D Text Label)</param>
  * <param name="x">Dealer x pos</param>
  * <param name="y">Dealer y pos</param>
  * <param name="z">Dealer z pos</param>
  * <param name="a">Dealer angle</param>
*/
Dealer_Create(const skin, const string: name[], Float: x, Float: y, Float: z, Float: a)
{
    new
        id = Iter_Alloc(Iter_Dealers);

    if (!(1 <= skin <= 299)) {
        return 0;
    }

    dealer_skin[id] = skin;
    dealer_x[id] = x;
    dealer_y[id] = y;
    dealer_z[id] = z;
    dealer_a[id] = a;

    strcopy(dealer_name[id], name);

    dealer_actor[id] = CreateActor(
        dealer_skin[id], Float: dealer_x[id], Float: dealer_y[id], Float: dealer_z[id], Float: dealer_a[id]
    );

    new String: str_dealer_label = String: str_format("[DEALER (%d) %s]\n/dealer", (id + 1), name);
    dealer_label[id] = Text3D: fmt_Create3DTextLabel(
        str_dealer_label, X11_YELLOW,
        Float: dealer_x[id], Float: dealer_y[id], Float: dealer_z[id], Float: 30.0, 0
    );

    // Query
    new String: str_query_dealer_add = String: str_format(
        "INSERT INTO \
            dealers (dealer_name, dealer_skin, dealer_x, dealer_y, dealer_z, dealer_a) \
        VALUES \
            ('%e', '%d', '%f', '%f', '%f', '%f')",
        dealer_name[id], dealer_skin[id], Float: dealer_x[id], Float: dealer_y[id], Float: dealer_z[id], Float: dealer_a[id]
    );

    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_dealer_add, "OnDealerCreated", "d", id);

    return 1;
}

Dealer_Goto(const playerid, const dealerid)
{
    task_await(
        Task: MySQL_QueryS(
            String: str_format(
                "SELECT * FROM dealers WHERE dealer_id = '%d'", dealerid
            )
        )
    );

    if (!cache_num_rows()) {
        return err(playerid, "Invalid dealer ID!");
    }

    SetPlayerPos(playerid, (dealer_x[(dealerid - 1)] + 2.0), dealer_y[(dealerid - 1)], dealer_z[(dealerid - 1)]);

    return 1;
}

Dealer_Nearby(const playerid)
{
    foreach (new i: Iter_Dealers) {
        if (IsPlayerInRangeOfPoint(playerid, Float: 2.0, dealer_x[i], dealer_y[i], dealer_z[i])) {
            return 1;
        }
    }

    return 0;
}

Player_DrugEffects(const playerid, bool: status = true)
{
    if (!status) {
        SetPlayerWeather(playerid, 1);

        return 1;
    }

    SetPlayerWeather(playerid, -1337);
    task_await(Task: BindToPlayer(task_ms(2000), playerid));

    SetPlayerWeather(playerid, 44);
    task_await(Task: BindToPlayer(task_ms(2000), playerid));

    SetPlayerWeather(playerid, 21);

    task_await(Task: BindToPlayer(task_ms(5000), playerid));
    Player_DrugEffects(playerid, false);

    return 1;
}