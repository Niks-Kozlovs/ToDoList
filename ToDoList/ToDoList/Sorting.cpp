#include "Sorting.h"
#define defPriorityLocation reader.Get("USER", "saveLocation", "priority.txt") + "Other\\priority.txt";

Sorting::Sorting()
{
}

void Sorting::sortItems(vector<vector<string>> information, string sortType, int columns, vector<int> & itemOrder)
{
	switch (columns)
	{
	case 0: sortDate(information, sortType, itemOrder); break;
	case 1: sortText(information, sortType, itemOrder, columns); break;
	case 2: sortPriority(information, sortType, itemOrder); break;
	case 4: sortDate(information, sortType, itemOrder); break; //Sort time left ir tas pats, kas sort date.

	default:
		break;
	}
}

void Sorting::sortDate(vector<vector<string>> information, string sortType, vector<int> & itemOrder)
{
	int i = 0;
	bool isInOrder;
	while (i < itemOrder.size() - 1) {
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
		else if (year == year2 && month < month2) {
			shouldSwap = true;
			isInOrder = false;
		}
		else if (year == year2 && month == month2 && day < day2) { //If days are swapped then it becomes a problem
			shouldSwap = true;
			isInOrder = false;
		}
		else if (year == year2 && month == month2 && day == day2 && timeInSeconds < timeInSeconds2) {
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

	if (sortType == "Low to high") { //reverse
		std::reverse(itemOrder.begin(), itemOrder.end());
	}
}

void Sorting::sortText(vector<vector<string>> information, string sortType, vector<int> & itemOrder, int columnClicked)
{
	int i = 0;
	while (i < itemOrder.size() - 1) {
		int currentItemOrderValue = itemOrder.at(i);
		int currentItemOrderValueNext = itemOrder.at(i + 1);

		std::string name1 = information.at(currentItemOrderValue).at(columnClicked);
		std::string name2 = information.at(currentItemOrderValueNext).at(columnClicked);

		std::transform(name1.begin(), name1.end(), name1.begin(), ::toupper); //Pārveido uz lielajiem burtiem
		std::transform(name2.begin(), name2.end(), name2.begin(), ::toupper);

		if (name1 > name2 ) {
			std::swap(itemOrder.at(i), itemOrder.at(i + 1));
			i = 0;
		}
		else {
			i++;
		}
	}

	if (sortType == "Z-A") { //reverse
		std::reverse(itemOrder.begin(), itemOrder.end());
	}

}

void Sorting::sortPriority(vector<vector<string>> information, string sortType, vector<int> & itemOrder)
{
	vector<priorityValues> priorityValuesVec;

	INIReader reader("settings.ini");
	if (reader.ParseError() < 0) {
		//Parse error
	}
	std::string fileLocation = defPriorityLocation

		ifstream priorityFile(fileLocation);

	while (!priorityFile.eof()) {
		std::string buffer;
		vector<std::string> tempVector;
		priorityValues tempValues;

		getline(priorityFile, buffer);
		if (buffer == "") { break; }
		tempVector = seperateItems(buffer, "|");

		tempValues.name = tempVector.at(0);
		tempValues.value = stoi(tempVector.at(1));

		priorityValuesVec.push_back(tempValues);
	}
	//Sākas sortošana
	int i = 0;
	while (i < itemOrder.size() - 1) {
		int currentItemOrderValue = itemOrder.at(i);
		int currentItemOrderValueNext = itemOrder.at(i + 1);
		
		std::string priority1 = information.at(currentItemOrderValue).at(2);
		std::string priority2 = information.at(currentItemOrderValueNext).at(2);

		int priority1Value;
		int priority2Value;

		bool foundValue1 = false;
		bool foundValue2 = false;

		for (int j = 0; j < priorityValuesVec.size(); j++) {
			if (priorityValuesVec.at(j).name == priority1 || priorityValuesVec.at(j).name == priority2) {
				if (priorityValuesVec.at(j).name == priority1) {
					priority1Value = priorityValuesVec.at(j).value;
					foundValue1 = true;
				}
				else {
					priority2Value = priorityValuesVec.at(j).value;
					foundValue2 = true;
				}
			}
		}

		if (foundValue1 && foundValue2) {
			if (priority1Value < priority2Value) {
				std::swap(itemOrder.at(i), itemOrder.at(i + 1));
				i = 0;
			}
			else {
				i++;
			}
		}
		else if (foundValue2) {
			std::swap(itemOrder.at(i), itemOrder.at(i + 1));
			i = 0;
		}
		else {
			i++;
		}


	}

	if (sortType == "Low to high") { //reverse
		std::reverse(itemOrder.begin(), itemOrder.end());
	}


}



