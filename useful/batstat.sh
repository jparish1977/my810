#!/bin/bash
echo BATTERY STATUS
upower -i $(upower -e | grep -E "BAT|bat") | grep -E "tech|state|to\ full|percentage"
