#pragma once
#include <string>

using namespace std;

class TimeManager
{
private:
	int day, month, year, hour, minute, second;
public:
	TimeManager(std::string dateString, int h, int m, int s);
	TimeManager(std::string timeDateString);
	std::string getTimeFull();
	bool isDateInPast();
	string getTimeDifference();
	void getTimeInValues(int &year, int &month, int &day, int &hour, int &minute, int &second);
};
