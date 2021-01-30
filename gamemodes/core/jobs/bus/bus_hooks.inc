#include <YSI_Coding\y_hooks>

static
    tmpobjid,
    Bus_Vehicle[4],

    Text3D: Bus_Label[4];

hook OnGameModeInit()
{
    tmpobjid = CreateDynamicObject(18766, 1190.392578, -1837.261718, 14.350311, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 18996, "mattextures", "sampblack", 0x00000000);
    tmpobjid = CreateDynamicObject(18766, 1190.392578, -1827.331787, 14.350311, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 18996, "mattextures", "sampblack", 0x00000000);
    tmpobjid = CreateDynamicObject(18766, 1190.392578, -1817.372436, 14.350311, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 18996, "mattextures", "sampblack", 0x00000000);
    tmpobjid = CreateDynamicObject(18766, 1190.392578, -1807.422851, 14.350311, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 18996, "mattextures", "sampblack", 0x00000000);
    tmpobjid = CreateDynamicObject(18766, 1286.971069, -1837.261718, 14.350311, 0.000007, 0.000000, 89.999977, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 18996, "mattextures", "sampblack", 0x00000000);
    tmpobjid = CreateDynamicObject(18766, 1286.971069, -1827.331787, 14.350311, 0.000007, 0.000000, 89.999977, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 18996, "mattextures", "sampblack", 0x00000000);
    tmpobjid = CreateDynamicObject(18766, 1286.971069, -1817.372436, 14.350311, 0.000007, 0.000000, 89.999977, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 18996, "mattextures", "sampblack", 0x00000000);
    tmpobjid = CreateDynamicObject(18766, 1286.971069, -1807.422851, 14.350311, 0.000007, 0.000000, 89.999977, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 18996, "mattextures", "sampblack", 0x00000000);
    tmpobjid = CreateDynamicObject(18766, 1286.971069, -1797.543945, 14.350311, 0.000007, 0.000000, 89.999977, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 18996, "mattextures", "sampblack", 0x00000000);
    tmpobjid = CreateDynamicObject(18766, 1286.971069, -1788.305419, 14.350311, 0.000007, 0.000000, 89.999977, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 18996, "mattextures", "sampblack", 0x00000000);
    tmpobjid = CreateDynamicObject(18766, 1281.821533, -1783.815185, 14.350311, 0.000007, 0.000000, 179.999969, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 18996, "mattextures", "sampblack", 0x00000000);
    tmpobjid = CreateDynamicObject(18766, 1281.631103, -1841.772827, 14.350311, 0.000007, 0.000000, 179.999969, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 18996, "mattextures", "sampblack", 0x00000000);
    tmpobjid = CreateDynamicObject(18766, 1195.701538, -1841.762817, 14.350311, 0.000007, 0.000000, 179.999969, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 18996, "mattextures", "sampblack", 0x00000000);
    tmpobjid = CreateDynamicObject(18766, 1202.110473, -1841.762817, 14.350311, 0.000007, 0.000000, 179.999969, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 18996, "mattextures", "sampblack", 0x00000000);
    tmpobjid = CreateDynamicObject(18766, 1225.180786, -1841.762817, 14.350311, 0.000007, 0.000000, 179.999969, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 18996, "mattextures", "sampblack", 0x00000000);
    tmpobjid = CreateDynamicObject(18766, 1235.120239, -1841.762817, 14.350311, 0.000007, 0.000000, 179.999969, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 18996, "mattextures", "sampblack", 0x00000000);
    tmpobjid = CreateDynamicObject(18766, 1244.970458, -1841.762817, 14.350311, 0.000007, 0.000000, 179.999969, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 18996, "mattextures", "sampblack", 0x00000000);
    tmpobjid = CreateDynamicObject(18766, 1254.799926, -1841.762817, 14.350311, 0.000007, 0.000000, 179.999969, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 18996, "mattextures", "sampblack", 0x00000000);
    tmpobjid = CreateDynamicObject(18766, 1258.369995, -1841.762817, 14.350311, 0.000007, 0.000000, 179.999969, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 18996, "mattextures", "sampblack", 0x00000000);
    tmpobjid = CreateDynamicObject(7914, 1241.601684, -1841.872680, 14.711424, 0.000000, 0.000000, -0.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterialText(tmpobjid, 0, "{FFFFFF}BUS STATION", 80, "Ariel", 20, 1, 0x00000000, 0x00000000, 1);
    
    tmpobjid = CreateDynamicObject(19123, 1219.823242, -1841.613525, 13.061433, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(19123, 1207.512939, -1841.613525, 13.061433, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(19123, 1263.723266, -1841.613525, 13.061433, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(19123, 1276.243164, -1841.613525, 13.061433, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 

    // Vehicles
    Bus_Vehicle[0] = AddStaticVehicleEx(431, 1280.0828000, -1799.9475000, 13.3989000, 180.0000000, -1, -1, 10000);
    Bus_Vehicle[1] = AddStaticVehicleEx(431, 1274.4136000, -1799.9475000, 13.3989000, 180.0000000, -1, -1, 10000);
    Bus_Vehicle[2] = AddStaticVehicleEx(431, 1268.1949000, -1799.9475000, 13.3989000, 180.0000000, -1, -1, 10000);
    Bus_Vehicle[3] = AddStaticVehicleEx(431, 1262.3354000, -1799.9475000, 13.3989000, 180.0000000, -1, -1, 10000);

    for (new i = 0; i < 4; ++i) {
        Bus_Label[i] = CreateDynamic3DTextLabel(
            "BUS VEHICLE", X11_YELLOW,
            Float: 0.0, Float: 0.0, Float: 0.0, Float: 30.0,
            INVALID_PLAYER_ID, Bus_Vehicle[i]
        );
    }

    CreateDynamicPickup(1210, 1, Float: 1222.0521, Float: -1812.2341, Float: 16.5938);
    CreateDynamicPickup(1275, 1, Float: 1216.5745, Float: -1812.1322, Float: 16.5938);

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 673, 1256.2266, -1839.9766, 12.5234, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 1249.5078, -1840.3828, 12.3516, 0.25);
    RemoveBuildingForPlayer(playerid, 647, 1235.8359, -1839.8125, 14.0703, 0.25);
    RemoveBuildingForPlayer(playerid, 647, 1192.8281, -1839.8125, 14.0703, 0.25);
    RemoveBuildingForPlayer(playerid, 647, 1244.5000, -1839.8125, 14.0703, 0.25);
    RemoveBuildingForPlayer(playerid, 647, 1284.9766, -1839.8125, 14.0703, 0.25);
    RemoveBuildingForPlayer(playerid, 673, 1200.8828, -1839.1250, 12.5234, 0.25);
    RemoveBuildingForPlayer(playerid, 673, 1227.5547, -1839.1250, 12.5234, 0.25);
    RemoveBuildingForPlayer(playerid, 647, 1192.8281, -1829.2813, 14.0703, 0.25);
    RemoveBuildingForPlayer(playerid, 647, 1284.9766, -1828.4219, 14.0703, 0.25);
    RemoveBuildingForPlayer(playerid, 673, 1192.6172, -1826.9531, 12.5234, 0.25);
    RemoveBuildingForPlayer(playerid, 673, 1284.8906, -1823.8594, 12.5234, 0.25);
    RemoveBuildingForPlayer(playerid, 647, 1284.9766, -1820.7422, 14.0703, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 1286.3047, -1808.6094, 12.3516, 0.25);
    RemoveBuildingForPlayer(playerid, 647, 1284.9766, -1796.8984, 14.0703, 0.25);

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    if (Bus_ValidVeh(vehicleid))
    {
        if (Player_GetJob(playerid) != _:E_PLAYER_JOB_BUS) {
            ClearAnimations(playerid);
            GameTextForPlayer(playerid, "~r~You can't drive that vehicle!", 2000, 3);
        }
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}

Bus_ValidVeh(vehid)
{
    for (new i = 0; i < sizeof Bus_Vehicle; ++i) {
        if (vehid == Bus_Vehicle[i]) {
            return 1;
        }
    }

    return 0;
}