#!/bin/sh

cd /home/pi/room/tp-link
./desktop.sh 1
echo 1 > flag_heat_board
./heat_board.sh 1
echo "2" > /home/pi/room/server/a
