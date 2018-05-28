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
TimeManager::TimeManager(std::string timeDateString)
{
	std::vector<std::string> times; //Date and time
	times = seperateItems(timeDateString, " ");
	int day, month, year, hour, minute, second;
	if (std::sscanf(times.at(0).c_str(), "%d/%d/%d", &day, &month, &year) != 3) {
		//Error
	}
	if (std::sscanf(times.at(1).c_str(), "%d:%d:%d", &hour, &minute, &second) != 3) {
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

std::string TimeManager::getTimeDifference()
{
	int dayNow, monthNow, yearNow, hourNow, minuteNow, secondNow;
	std::string timeLeft = "";
	//Get time now
	time_t timeNow = time(NULL);
	struct tm *aTime = localtime(&timeNow);

	yearNow = aTime->tm_year + 1900;
	monthNow = aTime->tm_mon + 1;
	dayNow = aTime->tm_mday;

	hourNow = aTime->tm_hour;
	minuteNow = aTime->tm_min;
	secondNow = aTime->tm_sec;

	//Combine strings for total time left
	//Pārbaudes ir domātas, lai nerādītos 0 gadi, 0 minūtes, utt
	bool isDayToday = true;
	if (this->year > yearNow) {
		timeLeft += to_string(this->year - yearNow) + " years ";
		isDayToday = false;
	}
	if (this->month > monthNow) {
		timeLeft += to_string(this->month - monthNow) + " months ";
		isDayToday = false;
	}
	if (this->day > dayNow) {
		timeLeft += to_string(this->day - dayNow) + " days ";
		isDayToday = false;
	}
	if (isDayToday) {
		int timeInSeconds = 0;
		timeInSeconds += this->hour * 60 * 60;
		timeInSeconds += this->minute * 60;
		timeInSeconds += this->second;
		//Get difference
		timeInSeconds -= hourNow * 60 * 60;
		timeInSeconds -= minuteNow * 60;
		timeInSeconds -= secondNow;
		if (timeInSeconds > 0) {
			if (timeInSeconds / 3600) {
				timeLeft += to_string(timeInSeconds / 3600) + " hours ";
				timeInSeconds = timeInSeconds % 3600;
			}
			if (timeInSeconds / 60) {
				timeLeft += to_string(timeInSeconds / 60) + " minutes ";
				timeInSeconds = timeInSeconds % 60;
			}
			if (timeInSeconds) {
				timeLeft += to_string(timeInSeconds) + " seconds ";
			}
		}
	}
	if (timeLeft == "") { timeLeft = "Time has passed"; }
	return timeLeft;
}

void TimeManager::getTimeInValues(int & year, int & month, int & day, int & hour, int & minute, int & second)
{
	year = this->year;
	month = this->month;
	day = this->day;

	hour = this->hour;
	minute = this->minute;
	second = this->second;
}
