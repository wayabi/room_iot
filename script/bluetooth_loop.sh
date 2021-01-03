#!/bin/sh

while [ 1 ]
do
	echo -e 'power on\nscan on\n' | bluetoothctl
	sleep 3
done