// Author: Vincent Wang
// Date  : 2016/3/16
// Purpose:
//	简单的码表类，参考
//  http://www.cnblogs.com/csonezp/archive/2012/12/25/2833009.html
//  调用方法
//  Stopwatch sw;
// sw.start();
// ....
// sw.stop();
// cout << sw.getMilliseconds() << " ms";

#ifndef GUARD__stopwatch__H
#define GUARD__stopwatch__H

#include <ctime> 

class Stopwatch{
public:
	Stopwatch():starttime(0),stoptime(0) {}
	void start();
	void stop();
	double getMilliseconds();
	double getMicroseconds();
private:
	time_t starttime,stoptime;
};

#endif // GUARD__stopwatch__H
