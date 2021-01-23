static
    BitArray: VEHICLE_SPAWNED<MAX_PLAYERS>;

ADMIN_COMMAND:[1]ban(playerid, const params[])
{
    extract params -> new targetid, string: reason[MAX_REASON_TEXT]; else {
        return usage(playerid, "/ban [targetid] [reason]");
    }

    BanPlayer(targetid, playerid, reason);

    return 1;
}

ADMIN_COMMAND:[1]unban(playerid, const params[])
{
    if (isnull(params)) {
        return usage(playerid, "/unban [name]");
    }

    UnbanPlayer(playerid, params);

    return 1;
}

ADMIN_COMMAND:[1]kick(playerid, const params[])
{
    extract params -> new targetid, string: reason[MAX_REASON_TEXT]; else {
        return usage(playerid, "/kick [targetid] [reason]");
    }

    if (targetid == playerid) {
        return err(playerid, "You can't kick yourself!");
    }

    GameTextForPlayer(targetid, "~r~KICKED", 10000, 3);

    va_SendClientMessageToAll(
        X11_RED, "* Kick: "WHITE"Player %s has been kicked from this server. Reason: %s",
        ReturnPlayerName(targetid), reason
    );

    Kick(targetid);

    return 1;
}

ADMIN_COMMAND:[1]cc(playerid, const params[])
{
    if (isnull(params)) {
        return usage(playerid, "/cc [line(s)]");
    }

    for (new i = 0; i < strval(params); ++i) {
        SendClientMessageToAll(-1, " ");
    }

    SendClientMessageToAll(-1, "Chatbox cleared.");

    return 1;
}

ADMIN_COMMAND:[1]mute(playerid, const params[])
{
    extract params -> new targetid, string: reason[MAX_REASON_TEXT], minutes; else {
        return usage(playerid, "/mute [targetid] [reason] [minutes]");
    }

    MutePlayer(playerid, targetid, reason, minutes);
    
    return 1;
}

ADMIN_COMMAND:[1]unmute(playerid, const params[])
{
    if (isnull(params)) {
        return usage(playerid, "/unmute [targetid]");
    }

    UnMutePlayer(playerid, strval(params));

    return 1;
}

ADMIN_COMMAND:[1]veh(playerid, const params[])
{
    if (isnull(params)) {
        return usage(playerid, "/veh [vehicle id (400-611)]");
    }

    if (!(400 <= strval(params) <= 611)) {
        return err(playerid, "Invalid vehicle ID!");
    }

    static
        x, y, z, a,
        vehicleid;

    if (!Bit_Get(VEHICLE_SPAWNED, playerid)) {
        GetPlayerPos(playerid, Float: x, Float: y, Float: z);
        GetPlayerFacingAngle(playerid, Float: a);

        vehicleid = CreateVehicle(strval(params), Float: x, Float: y, Float: z, Float: a, 0, 0, 0);   
        PutPlayerInVehicle(playerid, vehicleid, 0);
    
        Bit_Let(VEHICLE_SPAWNED, playerid);

        return 1;
    }

    Bit_Set(VEHICLE_SPAWNED, playerid, false);
    DestroyVehicle(vehicleid);

    return 1;
}

ADMIN_COMMAND:[1]pm(playerid, const params[])
{
    extract params -> new targetid, string: text[MAX_TEXT_MESSAGE]; else {
        return usage(playerid, "/pm [targetid] [text]");
    }

    va_SendClientMessage(playerid, X11_RED, "* PM: "WHITE"%s: %s", ReturnPlayerName(targetid), text);
    va_SendClientMessage(targetid, X11_RED, "* PM: "WHITE"%s: %s", ReturnPlayerName(playerid), text);

    return 1;
}

ADMIN_COMMAND:[1]a(playerid, const params[])
{
    if (isnull(params)) {
        return usage(playerid, "/a [text]");
    }

    foreach (new i: Player) {
        if (Admin_GetLevel(i)) {
            va_SendClientMessage(i, X11_RED, "* Admin-Chat: "WHITE"(%d)%s: %s", i, ReturnPlayerName(i), params);
        }
    }

    return 1;
}

ADMIN_COMMAND:[1]kill(playerid, const params[])
{
    extract params -> new targetid, string: reason[MAX_REASON_TEXT]; else {
        return usage(playerid, "/kill [targetid] [reason]");
    }

    SetPlayerHealth(targetid, Float: 0.0);

    fmt_info(targetid, "Admin %s killed you. Reason: %s.", ReturnPlayerName(playerid), reason);
    fmt_info(playerid, "You've killed player %s. Reason: %s.", ReturnPlayerName(targetid), reason);

    return 1;
}

ADMIN_COMMAND:[1]gotodealer(playerid, const params[])
{
    if (isnull(params)) {
        return usage(playerid, "/gotodealer [dealer id]");
    }

    Dealer_Goto(playerid, strval(params));

    return 1;
}

ADMIN_COMMAND:[1]pos(playerid, const params[])
{
	extract params -> new Float: x, Float: y, Float: z; else {
        return usage(playerid, "/pos [x] [y] [z]");
    }
    
	SetPlayerPos(playerid, Float: x, Float: y, Float: z);

	return 1;
}

ADMIN_COMMAND:[1]fv(playerid, const params[])
{
    RepairVehicle(GetPlayerVehicleID(playerid));
    SetVehicleHealth(GetPlayerVehicleID(playerid), Float: 0x4479c000);
    
    return 1;
}