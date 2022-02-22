#!/usr/bin/env bash

IN_USER=$1
[ -z "$1" ] && IN_USER=$(id -un)

[ "$UID" -eq 0 ] || exec sudo "$0" "$IN_USER"

groupadd -f uinput
usermod -a -G uinput $IN_USER

echo "KERNEL==\"uinput\", GROUP=\"uinput\", MODE:=\"0660\"" > /etc/udev/rules.d/99-input.rules

echo "Please reboot to allow permissions to update"