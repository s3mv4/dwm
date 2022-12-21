#!/bin/sh
export _JAVA_AWT_WM_NONREPARENTING=1 # For Android Studio
exec setxkbmap -layout dvorak -option caps:swapescape & # Set keyboard layout to Dvorak and swap caps lock with escape for vim
exec picom & # Start the compositor (transparency, blur etc.)
exec feh --bg-fill ~/wallpapers/sailboat.jpg & # Set the wallpaper
exec dwmblocks & # Start the status bar
exec dwm # Start dwm
