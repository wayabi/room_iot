#!/bin/bash
sleep 5
while [ 1 ]
do
	{
		printf 'power on\n\n'
		sleep 2
		printf 'scan on\n\n'
		sleep 2
		printf 'quit\n\n'
	} | bluetoothctl
	sleep 10
done