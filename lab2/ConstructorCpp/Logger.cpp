#include <iostream>
#include <chrono>
#include <ctime>
#include "Logger.h"

using namespace std;

void Logger::log(const char* log)
{
	if (debugger)
	{
		char s[26];
		time_t t = chrono::system_clock::to_time_t(now);
		ctime_s(s, sizeof s, &t);
		cout << "Aktualna data: " << s << endl;
		cout << log << endl;
	}
	
	
}

Logger::Logger(bool debug = 0)
{
	debugger = debug;
	now = chrono::system_clock::now();
}

Logger::Logger()
{
	
}