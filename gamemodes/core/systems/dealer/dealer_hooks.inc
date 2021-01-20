#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    mysql_tquery(MySQL: MySQL_GetHandle(), "SELECT * FROM dealers", "check_dealer_exists");

    return Y_HOOKS_CONTINUE_RETURN_1;
}