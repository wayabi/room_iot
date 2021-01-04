#!/bin/bash
sleep 5
while [ 1 ]
do
	#echo -e 'power on\nscan on\n' | bluetoothctl
	{
		printf 'power on\n\n'
		sleep 2
		printf 'scan on\n\n'
		sleep 2
		printf 'quit\n\n'
	} | bluetoothctl
	sleep 3
done