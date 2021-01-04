// * Messages *
#define err(%0,%1) SendClientMessage(%0, X11_ORANGE, "* Error: "WHITE""%1)
#define usage(%0,%1) SendClientMessage(%0, X11_ORANGE, "* Usage: "WHITE""%1)
#define info(%0,%1) SendClientMessage(%0, X11_ORANGE, "* Info: "WHITE""%1)

#define fmt_err(%0,%1,%2) va_SendClientMessage(%0, X11_ORANGE, "* Error: "WHITE""%1,%2)
#define fmt_info(%0,%1,%2) va_SendClientMessage(%0, X11_ORANGE, "* Info: "WHITE""%1,%2)