#include <iostream>
#include <chrono>
#include "Stopper.h"

using namespace std;

Stopper::Stopper()
{
	czas = 0;
}

void Stopper::Start()
{
	start = chrono::high_resolution_clock::now();
}

void Stopper::Stop()
{	
	czas = czas + chrono::duration_cast<chrono::duration<double>>
	(chrono::high_resolution_clock::now() - start).count();
}

void Stopper::Reset()
{
	czas = 0;
}

double Stopper::Get_time()
{
	return czas;
}

Stopper::~Stopper()
{

}