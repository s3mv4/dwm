#!/bin/sh
setxkbmap -layout us -variant dvp -option caps:swapescape &
xset r rate 330 50 &
~/.fehbg &
picom &
dwmblocks &
while true; do
    dwm >/dev/null 2>&1
done
