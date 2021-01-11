#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

class Logger
{
private:
	chrono::system_clock::time_point now;
	bool debugger;
public:
	void log(const char* log);
	Logger(bool debug);
	Logger();
};

#endif