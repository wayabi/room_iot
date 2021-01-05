import RPi.GPIO as GPIO
import time
import sys
import struct
import os

def single_click():
	print("single")
	os.system("/home/pi/room/event_read/bin/button1.sh")

def double_click():
	print("double")
	os.system("/home/pi/room/event_read/bin/button0.sh")

if __name__ == '__main__':
	gpio_pin = int(sys.argv[1])

	GPIO.setmode(GPIO.BCM)
	GPIO.setup(gpio_pin,GPIO.IN)

	flag_checking = False
	last_checking = time.time()
	last_state = False
	try:
		while True:
			t = time.time()
			state = GPIO.input(gpio_pin) == GPIO.HIGH
			if flag_checking == False:
				if last_state == True and state == False:
					flag_checking = True
					last_checking = t
			else:
				if t - last_checking > 1:
					#timeout
					flag_checking = False
					last_state = False
					single_click()

				if last_state == True and state == False:
					flag_checking = False
					last_state = False
					double_click()
			last_state = state
			time.sleep(0.01)
	except KeyboardInterrupt:
		GPIO.cleanup()
