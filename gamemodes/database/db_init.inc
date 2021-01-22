#include <YSI_Coding\y_hooks>

// * Variables *
static
    MySQL: db_handle;

// * Hooks *
hook OnGameModeInit()
{
    DB_CreateConnection();
    pp_use_funcidx(true);

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnGameModeExit()
{
    if (!mysql_close(db_handle)) {
        print("Failed to terminate the database connection. Please check this.");
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}

// * Functions *
static DB_CreateConnection()
{
    static
        env_hostname[10],
        env_username[5],
        env_database[15];


    if (Env_Has("MYSQL_HOSTNAME")) {
        Env_Get("MYSQL_HOSTNAME", env_hostname);
    }

    if (Env_Has("MYSQL_USERNAME")) {
        Env_Get("MYSQL_USERNAME", env_username);
    }

    if (Env_Has("MYSQL_DATABASE")) {
        Env_Get("MYSQL_DATABASE", env_database);
    }

    new MySQLOpt: options = mysql_init_options();
    mysql_set_option(options, AUTO_RECONNECT, true);
    mysql_set_option(options, MULTI_STATEMENTS, true);
    mysql_set_option(options, POOL_SIZE, 2);

    db_handle = mysql_connect(env_hostname, env_username, "", env_database, options);

    if (mysql_errno(db_handle) != 0) {
        print("[MySQL]: Can't connect to database!");
        
        SendRconCommand("exit");
        return 1;
    }

    print("Database successfully initialised.");

    return 1;
}

// OnQueryError - REQUIRED
public OnQueryError(errorid, const error[], const callback[], const query[], MySQL:handle)
{
    return 1;
}

stock MySQL: MySQL_GetHandle()
{
    return db_handle;
}

stock Task: MySQL_Query(const query[])
{
    return mysql_aquery(MySQL_GetHandle(), query, true);
}

stock Task: MySQL_QueryS(ConstStringTag:query)
{
    return mysql_aquery_s(MySQL_GetHandle(), query, true);
}