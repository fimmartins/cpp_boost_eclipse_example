/* Implementation for the Time Class (Time.cpp) */
#include <iostream>
#include <iomanip>
#include "TimeInit.hpp"    // include header of Time class
using namespace std;

// Constructor with default values. No input validation
TimeInit::TimeInit(int h, int m, int s) {
	hour = h;
	minute = m;
	second = s;
}

// public getter for private data member hour
int TimeInit::getHour() const {
	return hour;
}

// public setter for private data member hour. No input validation
void TimeInit::setHour(int h) {
	hour = h;
}

// public getter for private data member minute
int TimeInit::getMinute() const {
	return minute;
}

// public setter for private data member minute. No input validation
void TimeInit::setMinute(int m) {
	minute = m;
}

// public getter for private data member second
int TimeInit::getSecond() const {
	return second;
}

// public setter for private data member second. No input validation
void TimeInit::setSecond(int s) {
	second = s;
}

// Set hour, minute and second. No input validation
void TimeInit::setTime(int h, int m, int s) {
	hour = h;
	minute = m;
	second = s;
}

// Print this Time instance in the format of "hh:mm:ss", zero filled
void TimeInit::print() const {
	cout << setfill('0');    // zero-filled, need <iomanip>, sticky
	cout << setw(2) << hour // set width to 2 spaces, need <iomanip>, non-sticky
			<< ":" << setw(2) << minute << ":" << setw(2) << second << endl;
}

// Increase this instance by one second
void TimeInit::nextSecond() {
	++second;
	if (second >= 60) {
		second = 0;
		++minute;
	}
	if (minute >= 60) {
		minute = 0;
		++hour;
	}
	if (hour >= 24) {
		hour = 0;
	}
}
