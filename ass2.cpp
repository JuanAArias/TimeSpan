// ass2.cpp
// Test functions for class TimeSpan
// Authors: Yusuf Pisan & Juan Arias

#include <iostream>
#include <sstream>
#include <cassert>
#include "timespan.h"

// testing constructor
void test1() {
	
	TimeSpan ts(1, 20, 30);
	std::stringstream ss;
	ss << ts;
	assert(ss.str() == "1:20:30");

	TimeSpan ts2(4, -20, -90);
	ss.str("");
	ss << ts2;
	assert(ss.str() == "3:38:30");

	TimeSpan ts3(1.5, 30.5, -90);
	ss.str("");
	ss << ts3;
	assert(ss.str() == "1:59:00");

	TimeSpan ts4(0, 0.07, 0);
	ss.str("");
	ss << ts4;
	assert(ss.str() == "0:00:04");

}

// testing equality, addition, subtraction, multiplication
void test2() {
	TimeSpan ts(1, 20, 30);
	TimeSpan ts2(1, 20, 30);
	TimeSpan ts3(0, 0, 0);
	assert(ts == ts2);
	assert(!(ts != ts2));
	assert(ts != ts3);
	assert((ts + ts + ts) == (ts2 * 3));
	assert((ts * 5) == (ts2 * 4) + ts2);
	assert((ts * 5) == (ts2 * 6) - ts2);
	assert((ts + ts - ts) == ((ts2 * 2) - ts));
	assert((ts - ts2) == ts3);
	assert((ts3 * 5) == ts3);

}

// testing constructor, addition assignment &
// subtraction assignment
void test3() {

	// default parameter check
	TimeSpan ts1, ts2(0), ts3(0, 0), ts4(0, 0, 0);
	assert(ts1 == ts2 && ts2 == ts3 && ts3 == ts4);

	// addition assignment overload test
	TimeSpan ts5(22, 30, 30), ts6(2, 15, 5);

	ts5 += ts6;

	std::stringstream ss;
	ss << ts5;
	assert(ss.str() == "24:45:35");

	ts5 += ts1;

	ss.str("");
	ss << ts5;
	assert(ss.str() == "24:45:35");

	ts5 += ts6 - ts6 - ts6;

	ss.str("");
	ss << ts5;
	assert(ss.str() == "22:30:30");

	//subtraction assignment overload test
	TimeSpan ts7(3, 20, 40), ts8(2, 10, 20);

	ts7 -= ts8;

	ss.str("");
	ss << ts7;
	assert(ss.str() == "1:10:20");

	ts8 -= ts7;

	ss.str("");
	ss << ts8;
	assert(ss.str() == "1:00:00");

}

// testing greather than, greater than or equal,
// less than, less than or equal
void test4() {

	TimeSpan ts1, ts2(0, -5), ts3(0, 0, 1), ts4(0, 1, -60);
	
	assert(ts1 > ts2 && ts3 > ts1);
	assert(ts1 >= ts2 && ts1 >= ts4);
	assert(ts2 < ts1 && ts1 < ts3);
	assert(ts2 <= ts1 && ts1 <= ts4);


}

// run all tests for TimeSpan class
void testAll() {
	test1();
	test2();
	test3();
	test4();
}

// check testing for TimeSpan class
int main() {
	testAll();
	std::cout << "Done." << std::endl;
	return 0;

}
