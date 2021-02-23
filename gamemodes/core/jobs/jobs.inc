static
    char_job[MAX_PLAYERS],
    
    BitArray: JOB_EQUIPMENT<MAX_PLAYERS>;

enum E_PLAYER_JOBS {
    E_PLAYER_JOB_NONE = 0,
    E_PLAYER_JOB_BUS
};

// * Get/Set functions *
stock Player_SetJob(const playerid, const int)
{
    char_job[playerid] = int;

    new String: str_query_job_update = String: str_format(
        "UPDATE characters SET char_job = '%d' WHERE char_name = '%e'",
        Player_GetJob(playerid), ReturnPlayerName(playerid)
    );

    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_job_update);

    return 1;
}

stock Player_SetJobEquipment(const playerid, bool: status = true)
{
    Bit_Set(JOB_EQUIPMENT, playerid, status);
    
    return 1;
}

stock Player_GetJob(const playerid)
{
    return char_job[playerid];
}

stock Player_GetJobEquipment(const playerid)
{
    return Bit_Get(JOB_EQUIPMENT, playerid);
}

#include <job_commands>
#include <bus>