/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 5;        /* gaps between windows */
static const unsigned int snap      = 0;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int horizpadbar        = 7;        /* horizontal padding for statusbar */
static const int vertpadbar         = 5;        /* vertical padding for statusbar */
static const int vertpad            = 5;       /* vertical padding of bar */
static const int sidepad            = 5;       /* horizontal padding of bar */
static const char *fonts[]          = { "JetBrainsMonoNL Nerd Font:size=10" };
static const char dmenufont[]       = "JetBrainsMonoNL Nerd Font:size=10";
static const char col_gray1[]       = "#2e3440";
static const char col_gray2[]       = "#3b4252";
static const char col_gray3[]       = "#d8dee9";
static const char col_gray4[]       = "#eceff4";
static const char col_cyan[]        = "#5e81ac";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	// { "Gimp",     NULL,       NULL,       0,            1,           -1 },
	// { "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
	{ NULL,       NULL,       NULL,       0,            0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.5;  /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

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
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };

#include <X11/XF86keysym.h>

static const Key keys[] = {
	/* modifier                     key              function        argument */
	{ MODKEY,                       XK_p,            spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return,       spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,            togglebar,      {0} },
	{ MODKEY,                       XK_j,            focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,            focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,            incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,            incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,            setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,            setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return,       zoom,           {0} },
	{ MODKEY,                       XK_Tab,          view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,            killclient,     {0} },
	{ MODKEY,                       XK_t,            setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,            setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,            setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,        setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,        togglefloating, {0} },
	{ MODKEY,                       XK_asterisk,     view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_asterisk,     tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,        focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period,       focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,        tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,       tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_parenleft,                    0)
	TAGKEYS(                        XK_parenright,                   1)
	TAGKEYS(                        XK_braceright,                   2)
	TAGKEYS(                        XK_plus,                         3)
	TAGKEYS(                        XK_braceleft,                    4)
	TAGKEYS(                        XK_bracketright,                 5)
	TAGKEYS(                        XK_bracketleft,                  6)
	TAGKEYS(                        XK_exclam,                       7)
	TAGKEYS(                        XK_equal,                        8)
	{ MODKEY|ShiftMask,             XK_q,            quit,           {0} },
	{ 0, XF86XK_AudioLowerVolume,                    spawn,          SHCMD("pactl set-sink-volume @DEFAULT_SINK@ -5%; kill -35 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioRaiseVolume,                    spawn,          SHCMD("pactl set-sink-volume @DEFAULT_SINK@ +5%; kill -35 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioMute,                           spawn,          SHCMD("pactl set-sink-mute @DEFAULT_SINK@ toggle; kill -35 $(pidof dwmblocks)") },
	{ 0, XF86XK_MonBrightnessDown,                   spawn,          SHCMD("brightnessctl set 5%-; kill -36 $(pidof dwmblocks)") },
	{ 0, XF86XK_MonBrightnessUp,                     spawn,          SHCMD("brightnessctl set 5%+; kill -36 $(pidof dwmblocks)") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
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

