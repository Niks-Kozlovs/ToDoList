#include "TimeManager.h"
#include "Functions.h"
#include <iostream>
#include <time.h>


TimeManager::TimeManager(std::string dateString, int hour, int minute,int second)
{	
	int day, month, year;
	if (std::sscanf(dateString.c_str(), "%d/%d/%d", &day, &month, &year) != 3) {
		//Error
	}
	this->day = day;
	this->month = month;
	this->year = year;
	this->hour = hour;
	this->minute = minute;
	this->second = second;
}
std::string TimeManager::getTimeFull()
{
	std::string time;
	if (day < 10) { time += "0"; }
	time += std::to_string(day);
	time += "/";
	if (month < 10) { time += "0"; }
	time += std::to_string(month);
	time += "/";
	time += std::to_string(year);
	time += " ";
	if (hour < 10) { time += "0"; }
	time += std::to_string(hour);
	time += ":";
	if (minute < 10) { time += "0"; }
	time += std::to_string(minute);
	time += ":";
	if (second < 10) { time += "0"; }
	time += std::to_string(second);
	return time;
}

bool TimeManager::isDateInPast()
{
	bool timeIsGood = false;
	time_t timeNow = time(NULL);
	struct tm *aTime = localtime(&timeNow);

	//Datuma pārbaude
	if (this->year > (aTime->tm_year + 1900)) {
		return true;
	} else if ((this->year == (aTime->tm_year + 1900)) && (this->month > (aTime->tm_mon + 1))) {
		return true;
	} else if ((this->year == (aTime->tm_year + 1900)) && (this->month == (aTime->tm_mon + 1)) && ((this->day > aTime->tm_mday))) {
		return true;
	} else if (this->day == aTime->tm_mday) {
		//Nekas nav lai būtu laika pārbaude
	} else {
		return false;
	}
	
	//Laika pārbaude
	if (this->hour > aTime->tm_hour) {
		return true;
	} else if ((this->hour == aTime->tm_hour)&&(this->minute > aTime->tm_min)) {
		return true;
	} else if (((this->hour == aTime->tm_hour) && (this->minute == aTime->tm_min))&&(this->second > aTime->tm_sec)) {
		return true;
	} else {
		return false;
	}


	return false;
}
