// * SA-MP stdlib *
#include <a_samp>

#undef MAX_PLAYERS
#undef MAX_PLAYER_NAME
#undef MAX_ACTORS
#undef MAX_VEHICLES

const
	MAX_PLAYERS = (10),
	MAX_PLAYER_NAME = (25),
	MAX_ACTORS = (20),
	MAX_VEHICLES = (500);

// * JIT *
#include <jit>

// * SA-MP util *
#include <string>

// * MySQL *
#include <a_mysql>
#include <env>

// * Crashdetect *
#include <crashdetect>

// * Objects *
#include <streamer>

// * YSI-Includes *
#define YSI_NO_HEAP_MALLOC
#define YSI_NO_VERSION_CHECK
#define YSI_NO_MODE_CACHE
#define YSI_NO_OPTIMISATION_MESSAGE

#include <YSI_Coding\y_timers>
#include <YSI_Server\y_colours>
#include <YSI_Coding\y_inline>

#include <sscanf2>

// * PawnPlus *

#include <PawnPlus>
#include <pp-mysql>

// * Dialogs *
#include <async-dialogs>

// * Modules *
#include <db_init>
#include <cmd_process>
#include <shortcuts>

#include <ban>
#include <accounts>
#include <admin>

#include <warn>

main()
{
    print("Gamemode successfully loaded.");

	printf("JIT is %spresent", (IsJITPresent() ? ("not ") : ("")));
    OnJITCompile();
}

forward OnJITCompile();
public OnJITCompile()
{
	printf("OnJITCompile->JIT is %spresent", (IsJITPresent() ? ("not ") : ("")));
	return 1;
}