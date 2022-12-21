# Needed packages
```acpilight (brightness)```
```pamixer (volume)```
```feh (wallpaper)```
```picom (compositor)```

# Default programs (change in config.def.h)
```st (terminal) (my github repo)```
```firefox (browser) (standard repo)```
```dmenu (run prompt) (suckless)```
```slock (screen locker) (my github repo)```
```dwmblocks (statusbar) (my github repo)```

# Add Nerd Font to .local/share/fonts to use icons for dwmblocks
```cp fonts/* ~/.local/share/fonts```

# You also need to be able to run sudo without password (add this to your sudoers file)
```$USER ALL=(ALL) NOPASSWD: ALL```

# Run this command to copy the xinitrc, picom config and wallpapers to their needed location
```cp xinitrc ~/.xinitrc && cp picom.conf ~/.config/picom.conf && cp -r wallpapers ~/wallpapers```

# Use ```xev``` for keycodes for your keybindings
