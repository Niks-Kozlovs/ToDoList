#include "TimeManager.h"
#include <iostream>
#include <msclr\marshal_cppstd.h>


TimeManager::TimeManager(std::string dateString, int hour, int minute,int second)
{	
	int day, month, year;
	if (std::sscanf(dateString.c_str(), "%d/%d/%d", &day, &month, &year) != 3) {

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

	return  msclr::interop::marshal_as< std::string >( day + "/" + month + "/" + year + " " + hour + ":" + minute + ":" + second);
}