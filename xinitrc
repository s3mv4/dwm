#!/bin/sh
export _JAVA_AWT_WM_NONREPARENTING=1 # For Android Studio
exec setxkbmap -layout us -variant dvp -option caps:swapescape & # Set keyboard layout to Dvorak and swap caps lock with escape for vim
exec picom & # Start the compositor (transparency, blur etc.)
exec feh --bg-fill ~/wallpapers/gruvbox-linux.png & # Set the wallpaper
exec dwmblocks & # Start the status bar
# Start dwm in a loop
while true; do
    dwm >/dev/null 2>&1
done
