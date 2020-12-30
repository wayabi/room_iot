#!/bin/sh

ip=$1
flag=$2

tplink-smarthome-api -D send ${ip}:9999 '{"system":{"set_relay_state":{"state":'${flag}'}}}'
		
