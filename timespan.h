// timespan.h
// Specifications/header file for class TimeSpan
// Authors: Yusuf Pisan & Juan Arias
//
// The TimeSpan class represents a duration
// in hours, minutes, seconds, and can:
//	-display
//	-compare for equality, lesser than and greater than
//	-add, subtract and multiply

#ifndef TIMESPAN_H
#define TIMESPAN_H

#include <iostream>

class TimeSpan {

	// Maximum minutes and seconds
	static const int MIN_SEC_MAX = 60;

	// Friend function
	// Overloaded output stream operator
	// Displays duration in "hour:minutes:seconds"
	friend std::ostream& operator<<(std::ostream &out, const TimeSpan &tSpan);

public:

	// Constructs TimeSpan with user inputs for duration
	// All values default to 0
	explicit TimeSpan(double userHour = 0, double userMinute = 0, double userSecond = 0);

	// Destroys TimeSpan
	virtual ~TimeSpan();

	// Overloaded equality operator,
	// returns true if duration is equal to
	// duration of parameter tSpan, false otherwise
	bool operator==(const TimeSpan &tSpan) const;

	// Overloaded non equality operator,
	// returns true if duration not equal to
	// duration of parameter tSpan, false otherwise
	bool operator!=(const TimeSpan &tSpan) const;

	// Overloaded greater than operator,
	// returns true if duration is greater than
	// duration of parameter tSpan, false otherwise
	bool operator>(const TimeSpan &tSpan) const;

	// Overloaded greater than or equal to operator,
	// returns true if duration is greater than or equal to
	// duration of parameter tSpan, false otherwise
	bool operator>=(const TimeSpan &tSpan) const;

	// Overloaded less than operator,
	// returns true if duration is less than
	// parameter tSpan, false otherwise
	bool operator<(const TimeSpan &tSpan) const;


	// Overloaded less than or equal to operator,
	// returns true if duration s less than  or equal to
	// duration of parameter tSpan, false otherwise
	bool operator<=(const TimeSpan &tSpan) const;

	// Overloaded addition operator,
	// returns by value a new TimeSpan with duration that is
	// sum of this & parameter tSpan's durations
	TimeSpan operator+(const TimeSpan &tSpan) const;

	// Overloaded subtraction operator,
	// returns by value a new TimeSpan with duration that is
	// substraction of parameter tSpan's duration from this duration
	TimeSpan operator-(const TimeSpan &tSpan) const;

	// Overloaded addition assignment operator,
	// adds duration of parameter tSpan,
	// returns this by reference
	TimeSpan& operator+=(const TimeSpan &tSpan);

	// Overloaded subtraction assignment operator,
	// substracts duration of parameter tSpan,
	// returns this by reference
	TimeSpan& operator-=(const TimeSpan &tSpan);

	// Overloaded multiplication operator,
	// returns by a value a TimeSpan with duration that is
	// product of parameter factor and this duration
	TimeSpan operator*(int factor) const;

private:

	// Duration fields
	int hour, minute, second;

	// Simplifies duration for valid representation
	void simplify();

	// Loop for simplifying duration
	void loop(int &field1, int &field2);

};
#endif
