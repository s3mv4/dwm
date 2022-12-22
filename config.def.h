/* See LICENSE file for copyright and license details. */

/* custom variables */
#define TERMINAL "st"
#define BROWSER "firefox"
#define BROWSERCLASS "firefox"
#define ANDROID "android-studio"
#define ANDROIDCLASS "jetbrains-studio"

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int gappx     = 7;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Hack Nerd Font:style=Regular:size=10", "monospace:size=10" };
static const char dmenufont[]       = "Hack Nerd Font:style=Regular:size=10";

//static const char col_gray1[]       = "#222222";
//static const char col_gray2[]       = "#444444";
//static const char col_gray3[]       = "#bbbbbb";
//static const char col_gray4[]       = "#eeeeee";
//static const char col_cyan[]        = "#005577";
//static const char *colors[][3]      = {
//    /*               fg         bg         border   */
//    [SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
//    [SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
//};


/* gruvbox colors */
/* normal */
#define BG          "#282828"
#define N_RED       "#cc241d"
#define N_GREEN     "#98971a"
#define N_YELLOW    "#d79921"
#define N_BLUE      "#458588"
#define N_PURPLE    "#b16286"
#define N_AQUA      "#689d6a"
#define N_GRAY      "#a89984"
/* bright */
#define B_GRAY      "#928374"
#define B_RED       "#fb4934"
#define B_GREEN     "#b8bb26"
#define B_YELLOW    "#fabd2f"
#define B_BLUE      "#83a598"
#define B_PURPLE    "#d3869b"
#define B_AQUA      "#8ec07c"
#define FG          "#ebdbb2"



static const char norm_fg[]         = FG;
static const char norm_bg[]         = BG;
static const char norm_border[]     = N_GRAY;
static const char sel_fg[]          = FG;
static const char sel_bg[]          = N_AQUA;
static const char sel_border[]      = N_AQUA;
static const char *colors[][3]      = {
    /*               fg         bg          border   */
    [SchemeNorm] = { norm_fg,   norm_bg,    norm_border },
    [SchemeSel]  = { sel_fg,    sel_bg,     sel_border  },
};

/* tagging */
static const char *tags[] = { "", "", "3", "4", "5", "6", "7", "", "" };

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      instance    title       tags mask     isfloating   monitor */
    { BROWSER,    NULL,       NULL,       1 << 8,       0,           -1 },
    { ANDROIDCLASS,    NULL,       NULL,       1 << 7,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[]=",      tile },    /* first entry is default */
    { "><>",      NULL },    /* no layout function means floating behavior */
    { "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", norm_bg, "-nf", norm_fg, "-sb", sel_bg, "-sf", sel_fg, NULL };
static const char *termcmd[]  = { TERMINAL, NULL };
static const char *lockcmd[]  = { "slock", NULL };
static const char *browcmd[]  = { BROWSER, NULL };
static const char *andrcmd[]  = { ANDROID, NULL };

/* include special keys */
#include <X11/XF86keysym.h>

static Key keys[] = {
    /* modifier                     key        function        argument */
    { MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
    { MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
    { MODKEY,                       XK_x,      spawn,          {.v = lockcmd } },
    { MODKEY,                       XK_w,      spawn,          {.v = browcmd } },
    { MODKEY,                       XK_a,      spawn,          {.v = andrcmd } },

    { MODKEY,                       XK_b,      togglebar,      {0} },
    { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
    { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
    { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
    { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
    { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
    { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
    { MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
    { MODKEY,                       XK_Tab,    view,           {0} },
    { MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
    { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
    { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
    { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
    { MODKEY,                       XK_space,  setlayout,      {0} },
    { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
    { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
    { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
    { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
    { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },

    { MODKEY,                       XK_g,      setgaps,        {.i = -1 } },
    { MODKEY|ShiftMask,             XK_g,      setgaps,        {.i = +1 } },

    { 0, XF86XK_AudioMute,                         spawn,          SHCMD("pamixer -t; kill -35 $(pidof dwmblocks)") },
    { 0, XF86XK_AudioRaiseVolume,                  spawn,          SHCMD("pamixer --allow-boost -i 2; kill -35 $(pidof dwmblocks)") },
    { 0, XF86XK_AudioLowerVolume,                  spawn,          SHCMD("pamixer --allow-boost -d 2; kill -35 $(pidof dwmblocks)") },
    { 0, XF86XK_MonBrightnessUp,                   spawn,          SHCMD("sudo xbacklight -inc 2; kill -36 $(pidof dwmblocks)") },
    { 0, XF86XK_MonBrightnessDown,                 spawn,          SHCMD("sudo xbacklight -dec 2; kill -36 $(pidof dwmblocks)") },
    TAGKEYS(                        XK_1,                      0)
        TAGKEYS(                        XK_2,                      1)
        TAGKEYS(                        XK_3,                      2)
        TAGKEYS(                        XK_4,                      3)
        TAGKEYS(                        XK_5,                      4)
        TAGKEYS(                        XK_6,                      5)
        TAGKEYS(                        XK_7,                      6)
        TAGKEYS(                        XK_8,                      7)
        TAGKEYS(                        XK_9,                      8)
        { MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
    { ClkWinTitle,          0,              Button2,        zoom,           {0} },
    { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

