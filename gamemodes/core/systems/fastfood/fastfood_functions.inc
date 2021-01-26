const
    MAX_FASTFOODS = 100,
    FF_OBJECT_ID  = 1571;

// * Variables *
new
    Iterator: Iter_Fastfoods<MAX_FASTFOODS>,
    Text3D: ff_label[MAX_FASTFOODS],

    Float: ff_x[MAX_FASTFOODS],
    Float: ff_y[MAX_FASTFOODS],
    Float: ff_z[MAX_FASTFOODS],
    Float: ff_rz[MAX_FASTFOODS],

    ff_id[MAX_FASTFOODS],
    ff_object[MAX_FASTFOODS];

// * Functions *
FF_Create(const playerid)
{
    new
        id = Iter_Alloc(Iter_Fastfoods),
        String: str_query_ff_add;

    GetPlayerPos(playerid, Float: ff_x[id], Float: ff_y[id], Float: ff_z[id]);
    GetPlayerFacingAngle(playerid, Float: ff_rz[id]);

    SetPlayerPos(playerid, Float: (ff_x[id] + 4.0), Float: ff_y[id], Float: ff_z[id]);
    SetPlayerFacingAngle(playerid, Float: ff_rz[id]);

    ff_object[id] = CreateDynamicObject(
        FF_OBJECT_ID, Float: ff_x[id], Float: (ff_y[id] + 0.5), Float: ff_z[id], Float: 0.0, Float: 0.0, Float: (ff_rz[id] + 180.0)
    );

    ff_label[id] = Text3D: fmt_Create3DTextLabel(
        str_format("[Fast food - %d]", (id + 1)), X11_YELLOW,
        Float: ff_x[id], Float: ff_y[id], Float: ff_z[id], Float: 30.0, 0
    );

    str_query_ff_add = String: str_format(
        "INSERT INTO \
            fastfood (ff_x, ff_y, ff_z, ff_rz) \
        VALUES \
            ('%f', '%f', '%f', '%f')",
        Float: ff_x[id], Float: ff_y[id], Float: ff_z[id], Float: (ff_rz[id] + 180.0)
    );

    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_ff_add, "OnFFCreated", "i", id);

    return 1;
}

FF_Nearby(const playerid)
{
    foreach (new i: Iter_Fastfoods) {
        if (IsPlayerInRangeOfPoint(playerid, Float: 2.0, ff_x[i], ff_y[i], ff_z[i])) {
            return 1;
        }
    }

    return 0;
}

FF_Goto(const playerid, const id)
{
    task_await(
        Task: MySQL_QueryS(
            String: str_format(
                "SELECT * FROM fastfood WHERE ff_id = '%d'", id
            )
        )
    );

    if (!cache_num_rows()) {
        return err(playerid, "Invalid fastfood ID!");
    }

    SetPlayerPos(playerid, Float: (ff_x[(id - 1)] + 2.0), Float: ff_y[(id - 1)], Float: ff_z[(id - 1)]);

    return 1;
}