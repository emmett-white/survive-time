// * Messages *
#define err(%0,%1) SendClientMessage(%0, X11_ORANGE, "* Error: "WHITE""%1)
#define usage(%0,%1) SendClientMessage(%0, X11_ORANGE, "* Usage: "WHITE""%1)
#define info(%0,%1) SendClientMessage(%0, X11_ORANGE, "* Info: "WHITE""%1)

#define fmt_err(%0,%1,%2) va_SendClientMessage(%0, X11_ORANGE, "* Error: "WHITE""%1,%2)
#define fmt_info(%0,%1,%2) va_SendClientMessage(%0, X11_ORANGE, "* Info: "WHITE""%1,%2)

// * Configs *
#if defined MAX_WARNS
    #undef MAX_WARNS
#else
    /**
      * <summary>There are actually 5 warns, but when player gets 5 warns</summary>
      * <summary>he will be automatically banned.</summary>
    */
    const MAX_WARNS = (4);
#endif

const MAX_MUTE_MINUTES = (9999);

#define MAX_REASON_TEXT  64
#define MAX_TEXT_MESSAGE 128

#define PRESSED(%0) \
    (((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))