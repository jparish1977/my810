#!/bin/bash
# Commands to rotate teh screen
xrandr --output LVDS1 --rotate inverted -display :0.0

# xinput
#xinput --list-props "Fujitsu Component USB Touch Panel"
#inverted
xinput set-prop "Fujitsu Component USB Touch Panel" "Evdev Axis Inversion"  0, 1 
xinput set-prop "Fujitsu Component USB Touch Panel" "Evdev Axes Swap" 0

#Evdev Axis Calibration (300):   139, 3695, 279, 2700
#xinput set-prop "Fujitsu Component USB Touch Panel" "Evdev Axis Calibration" 3695, 139, 279, 2700
xinput set-prop "Fujitsu Component USB Touch Panel" "Evdev Axis Calibration" 3695, 139, 279, 2600

xinput set-prop "PS/2 Generic Mouse" "Evdev Axis Inversion" 0, 0
xinput set-prop "PS/2 Generic Mouse" "Evdev Axes Swap" 0

#PS/2 Generic Mouse
