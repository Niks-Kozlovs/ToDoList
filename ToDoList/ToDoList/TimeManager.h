#pragma once
#include <string>
ref class TimeManager
{
private:
	int dd, mm, yy, hh, mm, ss;
public:
	TimeManager(std::string dateString, int h, int m, int s);
};

