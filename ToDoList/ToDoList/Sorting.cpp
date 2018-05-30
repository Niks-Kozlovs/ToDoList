#include "Sorting.h"

Sorting::Sorting()
{
}

void Sorting::sortItems(vector<vector<string>> information, string sortType, int columns, vector<int> & itemOrder)
{
	switch (columns)
	{
	case 0: sortDate(information, sortType, itemOrder); break;
	case 1: sortName(information, sortType, itemOrder); break;
	case 2: sortPriority(information, sortType, itemOrder); break;
	case 4: sortTimeLeft(information, sortType, itemOrder); break;

	default:
		break;
	}
}

void Sorting::sortDate(vector<vector<string>> information, string sortType, vector<int> & itemOrder)
{
	int i = 0;
	bool isInOrder;
	while (i < information.size() - 1) {
		isInOrder = true;
		int currentItemOrderValue = itemOrder.at(i);
		int currentItemOrderValueNext = itemOrder.at(i + 1);
		TimeManager time(information.at(currentItemOrderValue).at(0));
		TimeManager time2(information.at(currentItemOrderValueNext).at(0));

		int year, month, day, hour, minute, second; //time info
		int year2, month2, day2, hour2, minute2, second2; //time2 info

		time.getTimeInValues(year, month, day, hour, minute, second);
		time2.getTimeInValues(year2, month2, day2, hour2, minute2, second2);

		int timeInSeconds = hour * 60 * 60 + minute * 60 + second; //Pirmais laiks sekundes
		int timeInSeconds2 = hour2 * 60 * 60 + minute2 * 60 + second2;  //Otrais laiks sekudes

		bool shouldSwap = false;
		//Laika salidzinasana
		if (year > year2) {
			shouldSwap = true;
			isInOrder = false;
		}
		else if (year == year2 && month > month2) {
			shouldSwap = true;
			isInOrder = false;
		}
		else if (year == year2 && month == month2 && day > day2) { //If days are swapped then it becomes a problem
			shouldSwap = true;
			isInOrder = false;
		}
		else if (year == year2 && month == month2 && day == day2 && timeInSeconds > timeInSeconds2) {
			shouldSwap = true;
			isInOrder = false;
		}

		if (shouldSwap) {
			std::swap(itemOrder.at(i), itemOrder.at(i + 1));
			i = 0;
		}
		else {
			i++;
		}
		
	}

	if (sortType == "High to low") { //reverse
		std::reverse(itemOrder.begin(), itemOrder.end());
	}
}

void Sorting::sortName(vector<vector<string>> information, string sortType, vector<int> & itemOrder)
{
	itemOrder = { 2,0,1 };
}

void Sorting::sortPriority(vector<vector<string>> information, string sortType, vector<int> & itemOrder)
{
}

void Sorting::sortTimeLeft(vector<vector<string>> information, string sortType, vector<int> & itemOrder)
{
}


