#if defined MAX_WARNS
    #undef MAX_WARNS
#else
    /*
      * <summary>There are actually 5 warns, but when player gets 5 warns</summary>
      * <summary>he will be automatically banned.</summary>
    */
    const MAX_WARNS = (4);
#endif

new
    player_warn_num[MAX_PLAYERS] = 0,
    player_warn_reason[MAX_PLAYERS][MAX_WARNS][64];