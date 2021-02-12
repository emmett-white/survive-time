#if defined _INC_cmd_prefix_inc
	#endinput
#endif
#define _INC_cmd_prefix_inc

#include <a_samp>

static
    gCommandPrefix[2];

/**
  * Functions
 */
stock cp_ChangeCommandPrefix(const prefix[] = 0x2f) // 0x2f = `/` (default cmd prefix)
{
    strcopy(gCommandPrefix, prefix);

    return 1;
}

public OnPlayerText(playerid, text[])
{
    if (text[0] == '$') {
        return SendClientMessage(playerid, -1, "$ is called");
    }

    #if defined cp_OnPlayerText
		return OnPlayerText(playerid, text[]);
	#else
		return 1;
	#endif
}

#if defined _ALS_OnPlayerText
	#undef OnPlayerText
#else
	#define _ALS_OnPlayerText
#endif

#define OnPlayerText cp_OnPlayerText
#if defined cp_OnPlayerText
	forward cp_OnPlayerText(playerid, text[]);
#endif