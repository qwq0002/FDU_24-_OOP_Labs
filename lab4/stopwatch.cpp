#include "Stopwatch.h"

void Stopwatch::start(){
	starttime = clock();
}

void Stopwatch::stop(){
	stoptime = clock();
}

double Stopwatch::getMilliseconds(){
	return (stoptime-starttime)*1000.0/CLK_TCK;
}

double Stopwatch::getMicroseconds(){
	return (stoptime-starttime)*1.0/CLK_TCK;
}