#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <string>
#include <iostream>
#include <vector>
#include <sstream>

#include <linux/input.h>
#include <sys/wait.h>

using namespace std;

void exec(const char* path)
{
	pid_t pid = fork();
	if(pid < 0){
		return;
	}else if(pid == 0){
		execl(path, NULL);
		return;
	}
	int status;
	waitpid(pid, &status, 0);
}

int main(int argc, char** argv)
{
	string dev = "/dev/input/event";
	stringstream ss;
	ss << dev << *(argv+1);

	FILE* f;
	if((f = fopen(ss.str().c_str(), "rb")) == NULL){
		cout << "no " << ss.str() << endl;
		return 1;
	}

	vector<unsigned char> buf;
	int size_buf = 48;
	buf.resize(size_buf);

	int size;
	while((size = fread(&buf[0], 1, size_buf, f)) > 0){
		int button_state = buf[6] & 0x01;
		int button_id = buf[26];
		if(button_state == 0) continue;
		if(button_id == 114){
			cout << "button0" << endl;
			exec("/home/pi/room/event_read/bin/button0.sh");
		}else if(button_id == 115){
			cout << "button1" << endl;
			exec("/home/pi/room/event_read/bin/button1.sh");
		}
	}

	return 0;
}
