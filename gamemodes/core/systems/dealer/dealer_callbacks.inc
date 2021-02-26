forward OnDealerCreated(const dealerid);
public OnDealerCreated(const dealerid)
{
    dealer_id[dealerid] = cache_insert_id();
    return 1;
}

forward CheckDealerExists();
public CheckDealerExists()
{
    for (new i; i < cache_num_rows(); ++i) {
        new id = Iter_Alloc(Iter_Dealers);
        
        cache_get_value_name_int(i, "dealer_id", dealer_id[id]);
        cache_get_value_name(i, "dealer_name", dealer_name[id]);
        cache_get_value_name_int(i, "dealer_skin", dealer_skin[id]);
        cache_get_value_name_float(i, "dealer_x", dealer_x[id]);
        cache_get_value_name_float(i, "dealer_y", dealer_y[id]);
        cache_get_value_name_float(i, "dealer_z", dealer_z[id]);
        cache_get_value_name_float(i, "dealer_a", dealer_a[id]);

        dealer_actor[id] = CreateActor(
            dealer_skin[id], Float: dealer_x[id], Float: dealer_y[id], Float: dealer_z[id], Float: dealer_a[id]
        );

        new String: str_dealer_label = String: str_format("[DEALER (%d) %s]\n/dealer", dealer_id[id], dealer_name[id]);
        dealer_label[id] = Text3D: fmt_Create3DTextLabel(
            str_dealer_label, X11_YELLOW,
            Float: dealer_x[id], Float: dealer_y[id], Float: dealer_z[id], Float: 30.0, 0
        );
    }

    return 1;
}