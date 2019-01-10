// timespan.cpp
// Implementation of class TimeSpan
// Author: Juan Arias
//
// The TimeSpan class represents a duration
// in hours, minutes, seconds, and can:
//	-display
//	-compare for equality, lesser than and greater than
//	-add, subtract and multiply

#include "timespan.h"

// Friend function
// Overloaded output stream operator
// Displays duration in "hour:minutes:seconds"
std::ostream& operator<<(std::ostream &out, const TimeSpan &time) {
	
	out << time.hour <<
		  (time.minute < 10 ? ":0" : ":") << time.minute <<
		  (time.second < 10 ? ":0" : ":") << time.second;

	return out;

}

// Constructs TimeSpan with user inputs for duration
// All values default to 0
TimeSpan::TimeSpan(double userHour, double userMinute, double userSecond)
	
    :hour(0), minute(0),
	second(userHour * MIN_SEC_MAX * MIN_SEC_MAX +
		   userMinute * MIN_SEC_MAX + userSecond) {

	simplify();

}

// Destroys TimeSpan
TimeSpan::~TimeSpan() {
}

// Overloaded equality operator,
// returns true if duration is equal to
// duration of parameter tSpan, false otherwise
bool TimeSpan::operator==(const TimeSpan &tSpan) const {

	return hour == tSpan.hour &&
		   minute == tSpan.minute &&
		   second == tSpan.second;

}

// Overloaded non equality operator,
// returns true if duration not equal to
// duration of parameter tSpan, false otherwise
bool TimeSpan::operator!=(const TimeSpan &tSpan) const {

	return !(*this == tSpan);

}

// Overloaded greater than operator,
// returns true if duration is greater than
// duration of parameter tSpan, false otherwise
bool TimeSpan::operator>(const TimeSpan &tSpan) const {

	return hour > tSpan.hour ||
		   hour == tSpan.hour && minute > tSpan.minute ||
		   hour == tSpan.hour && minute == tSpan.minute && second > tSpan.second;

}

// Overloaded greater than or equal to operator,
// returns true if duration is greater than or equal to
// duration of parameter tSpan, false otherwise
bool TimeSpan::operator>=(const TimeSpan &tSpan) const {

	return *this == tSpan || *this > tSpan;

}

// Overloaded less than operator,
// returns true if duration is less than
// parameter tSpan, false otherwise
bool TimeSpan::operator<(const TimeSpan &tSpan) const {

	return !(*this >= tSpan);

}


// Overloaded less than or equal to operator,
// returns true if duration s less than  or equal to
// duration of parameter tSpan, false otherwise
bool TimeSpan::operator<=(const TimeSpan &tSpan) const {

	return !(*this > tSpan);

}

// Overloaded addition operator,
// returns by value a new TimeSpan with duration that is
// sum of this & parameter tSpan's durations
TimeSpan TimeSpan::operator+(const TimeSpan &tSpan) const {

	return TimeSpan(hour + tSpan.hour,
					minute + tSpan.minute,
					second + tSpan.second);

}

// Overloaded subtraction operator,
// returns by value a new TimeSpan with duration that is
// substraction of parameter tSpan's duration from this duration
TimeSpan TimeSpan::operator-(const TimeSpan &tSpan) const {

	return TimeSpan(hour - tSpan.hour,
					minute - tSpan.minute,
					second - tSpan.second);

}

// Overloaded addition assignment operator,
// adds duration of parameter tSpan,
// returns this by reference
TimeSpan& TimeSpan::operator+=(const TimeSpan &tSpan) {
	
	hour += tSpan.hour;
	minute += tSpan.minute;
	second += tSpan.second;

	simplify();

	return *this;

}

// Overloaded subtraction assignment operator,
// substracts duration of parameter tSpan,
// returns this by reference
TimeSpan& TimeSpan::operator-=(const TimeSpan &tSpan) {
	
	hour -= tSpan.hour;
	minute -= tSpan.minute;
	second -= tSpan.second;

	simplify();

	return *this;

}

// Overloaded multiplication operator,
// returns by a value a TimeSpan with duration that is
// product of parameter factor and this duration
TimeSpan TimeSpan::operator*(int factor) const {

	return TimeSpan(hour * factor, minute * factor, second * factor);
	
}

// Simplifies duration for valid representation,
// uses private helper method loop
void TimeSpan::simplify() {

	loop(second, minute);
	loop(minute, hour);

}

// Loop for simplifying duration,
// uses TimeSpan's static constant MIN_SEC_MAX,
// parameters passed should be fields of this object
void TimeSpan::loop(int &field1, int &field2) {

	while (field1 < 0) {

		field1 = MIN_SEC_MAX + field1;
		--field2;

	}

	while (field1 >= MIN_SEC_MAX) {

		field2 += field1 / MIN_SEC_MAX;
		field1 = field1 % MIN_SEC_MAX;

	}

}
