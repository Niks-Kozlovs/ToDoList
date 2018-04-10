#include "TimeManager.h"



TimeManager::TimeManager(std::string dateString, int h, int m, int s)
{
	int month;
	int day;
	int year;
	if (std::sscanf(dateString.c_str(), "%d/%d/%d", &day, &month, &year) != 3) {
		
	}
}
