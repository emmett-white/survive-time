forward OnFFCreated(const id);
public OnFFCreated(const id)
{
    ff_id[id] = cache_insert_id();
    return 1;
}

forward CheckFastFoodExists();
public CheckFastFoodExists()
{
    for (new i; i < cache_num_rows(); ++i) {
        new
            id = Iter_Alloc(Iter_Fastfoods);

        cache_get_value_name_int(i, "ff_id", ff_id[id]);
        cache_get_value_name_float(i, "ff_x", ff_x[id]);
        cache_get_value_name_float(i, "ff_y", ff_y[id]);
        cache_get_value_name_float(i, "ff_z", ff_z[id]);
        cache_get_value_name_float(i, "ff_rz", ff_rz[id]);

        ff_object[id] = CreateDynamicObject(
            FF_OBJECT_ID, Float: ff_x[id], Float: (ff_y[id] + 0.5), Float: ff_z[id], Float: 0.0, Float: 0.0, Float: ff_rz[id]
        );

        ff_label[id] = Text3D: fmt_Create3DTextLabel(
            str_format("[Fast food - %d]", ff_id[id]), X11_YELLOW,
            Float: ff_x[id], Float: ff_y[id], Float: ff_z[id], Float: 30.0, 0
        );
    }

    return 1;
}