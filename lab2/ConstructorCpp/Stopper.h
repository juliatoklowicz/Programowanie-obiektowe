#ifndef STOPPER_H
#define STOPPER_H

#include <chrono>
using namespace std;

class Stopper
{
private:
	chrono::high_resolution_clock::time_point start;
	double czas;
public:
	Stopper();
	~Stopper();
	void Start();
	void Stop();
	void Reset();
	double Get_time();
};
#endif