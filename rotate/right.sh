#!/bin/bash
# Commands to rotate teh screen
xrandr --output LVDS1 --rotate right    -display :0.0


# xinpput
#xinput --list-props "Fujitsu Component USB Touch Panel"

#right
xinput set-prop "Fujitsu Component USB Touch Panel" "Evdev Axis Inversion" 0, 1
xinput set-prop "Fujitsu Component USB Touch Panel" "Evdev Axes Swap" 1

xinput set-prop "PS/2 Generic Mouse" "Evdev Axis Inversion" 1, 0
xinput set-prop "PS/2 Generic Mouse" "Evdev Axes Swap" 1

#PS/2 Generic Mouse
