#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    mysql_tquery(MySQL: MySQL_GetHandle(), "SELECT * FROM fastfood", "CheckFastFoodExists");

    return Y_HOOKS_CONTINUE_RETURN_1;
}