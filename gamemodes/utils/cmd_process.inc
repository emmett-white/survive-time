// By: Southclaws

#if defined CMD
    #undef CMD
#endif

#define CMD:%1(%2) forward cmd_%1(%2); public cmd_%1(%2)
#define ACMD:[%0]%1(%2,%3) CMD:%1(%2,%3) if (get_player_admin(%2) < %0) return 0; else

public OnPlayerCommandText(playerid, cmdtext[])
{
	new
		cmd[30],
		params[127],
		cmdfunction[64],
		result = 1;

	sscanf(cmdtext, "s[30]s[127]", cmd, params);

	for (new i, j = strlen(cmd); i < j; i++) {
		cmd[i] = tolower(cmd[i]);
	}

	format(cmdfunction, 64, "cmd_%s", cmd[1]);

	if(funcidx(cmdfunction) == -1) {
		new
			iLvl = get_player_admin(playerid),
			iLoop = 5;

		while(iLoop > 0) {
			format(cmdfunction, 64, "acmd_%s_%d", cmd[1], iLoop);

			if(funcidx(cmdfunction) != -1) {
				break;
			}

			iLoop--;
		}

		if(iLoop == 0) {
			result = 0;
		}

		if(iLvl < iLoop) {
			result = 5;
		}
	}

	if(result == 1) {
		if(isnull(params)) {
			result = CallLocalFunction(cmdfunction, "is", playerid, "\1");
		}

		else {
			result = CallLocalFunction(cmdfunction, "is", playerid, params);
		}
	}
	
	return 1;
}