#!/bin/bash
# Commands to rotate teh screen
xrandr --output LVDS1 --rotate normal   -display :0.0

# xinpput
#xinput --list-props "Fujitsu Component USB Touch Panel"
#normal
xinput set-prop "Fujitsu Component USB Touch Panel" "Evdev Axis Inversion" 0, 0
xinput set-prop "Fujitsu Component USB Touch Panel" "Evdev Axes Swap" 0

#Evdev Axis Calibration (300):   139, 3695, 279, 2700
xinput set-prop "Fujitsu Component USB Touch Panel" "Evdev Axis Calibration" 139, 3695, 279, 2700

xinput set-prop "PS/2 Generic Mouse" "Evdev Axis Inversion" 0, 0
xinput set-prop "PS/2 Generic Mouse" "Evdev Axes Swap" 0

#PS/2 Generic Mouse
