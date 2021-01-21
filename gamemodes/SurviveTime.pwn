/**
  * TODO: Drug effects
  * TODO: ...
*/

// * SA-MP stdlib *
// #include <openmp>
#include <a_samp>

#undef MAX_PLAYERS
#undef MAX_PLAYER_NAME
#undef MAX_ACTORS
#undef MAX_VEHICLES

const
	MAX_PLAYERS = 10,
	MAX_PLAYER_NAME = 25,
	MAX_ACTORS = 20,
	MAX_VEHICLES = 500;

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
#include <YSI_Data\y_bit>

#include <sscanf2>

// * PawnPlus *

#include <PawnPlus>
#include <pp-mysql>

// * Dialogs *
#include <async-dialogs>

// * Vehicle framework *
#include <vehicle_framework>

// * pawn-chrono *
#include <chrono>

// * Modules *
#include <db_init>
#include <cmd_process>
#include <shortcuts>
#include <vehicles>
#include <ban>
#include <spawn>
#include <accounts>
#include <warn>
#include <mute>
#include <chat>
#include <report>
#include <ui>
#include <help>
#include <vehicle>
#include <admin>

#include <dealer>

main()
{
	printf("JIT is %spresent", (IsJITPresent() ? ("not ") : ("")));
    OnJITCompile();

	new
		Timestamp: ts = Timestamp: Now(),
		ts_format[24];

	TimeFormat(Timestamp: ts, ISO6801_TIME, ts_format, sizeof ts_format);
	printf("Gamemode successfully loaded at %s", ts_format);
}

public OnGameModeInit()
{
	SetWeather(0);
	SetWorldTime(0);
	EnableStuntBonusForAll(0);
	DisableInteriorEnterExits();
	UsePlayerPedAnims();

	// Loading vehicles
	LoadStaticVehiclesFromFile("vehicles/ls_airport.txt");
	LoadStaticVehiclesFromFile("vehicles/ls_gen_inner.txt");
	LoadStaticVehiclesFromFile("vehicles/ls_gen_outer.txt");
	LoadStaticVehiclesFromFile("vehicles/ls_law.txt");
	LoadStaticVehiclesFromFile("vehicles/red_country.txt");

	return 1;
}

forward OnJITCompile();
public OnJITCompile()
{
	printf("OnJITCompile->JIT is %spresent", (IsJITPresent() ? ("not ") : ("")));
	return 1;
}