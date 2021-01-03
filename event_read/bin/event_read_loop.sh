#!/bin/sh

event=$1
while [ 1 ]
do
	../a.out ${event}
	sleep 5
done
