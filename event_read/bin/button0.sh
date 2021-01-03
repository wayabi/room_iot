#!/bin/sh

cd /home/pi/room/tp-link
./desktop.sh 0
echo 0 > flag_heat_board
./heat_board.sh 0
echo "1" > /home/pi/room/server/a
