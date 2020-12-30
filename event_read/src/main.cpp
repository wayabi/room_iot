#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <iostream>
#include <vector>
#include <sstream>

#include <linux/input.h>

#include "Util.h"

using namespace std;

int main(int argc, char** argv)
{
	string dev = "/dev/input/event";
	stringstream ss;
	ss << dev << *(argv+1);

	FILE* f;
	if((f = fopen(ss.str().c_str(), "rb")) == NULL){
		cout << "no " << dev << endl;
		return 1;
	}

	vector<unsigned char> buf;
	int size_buf = 48;
	buf.resize(size_buf);

	int size;
	while((size = fread(&buf[0], 1, size_buf, f)) > 0){
		cout << (int)buf[0] << ", " << (int)buf[29] << endl;
		int button_state = buf[6] & 0x01;
		int button_id = buf[26];
		cout << "button_id:" << button_id << ", state:" << button_state << endl;
		Util::hexdump(cout, &buf[0], size_buf);
	}

	return 0;
}
