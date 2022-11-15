# Needed packages
```acpilight (brightness)```
```pamixer (volume)```
```feh (wallpaper)```

# Default programs (change in config.def.h)
```st (terminal) (my github repo)```
```librewolf (browser) (AUR)```
```dmenu (run prompt) (suckless)```
```slock (screen locker) (suckless)```
```dwmblocks (statusbar) (my github repo)```

# Add Nerd Font to .local/share/fonts to use icons for dwmblocks
```cp fonts/* ~/.local/share/fonts```

# You also need to be able to run sudo without password (add this to your sudoers file)
```$USER ALL=(ALL) NOPASSWD: ALL```

# Run this command to copy the xinitrc, picom config and wallpaper to their needed location
```cp xinitrc ~/.xinitrc && cp picom.conf ~/.config/picom.conf && cp wall.jpg ~/.wall.jpg```
