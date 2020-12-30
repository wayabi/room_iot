#!/bin/sh

while [ 1 ]
do
	./heat_board.sh 0
	flag=`cat ./flag_heat_board`
	./heat_board.sh ${flag}
	echo "heat_flag ${flag}"
	sleep 5
	if [ ${flag} ]; then
		sleep 1200
	fi
done

