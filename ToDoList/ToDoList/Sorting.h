#pragma once
#include <string>
#include <vector>
#include "TimeManager.h"
//#include "Functions.h"


using namespace std;

class Sorting {
public:
	Sorting();
	void sortItems(vector<vector<string>> information, string sortType, int columns, int *& itemOrder);
	void sortDate(vector<vector<string>> information, string sortType, int *& itemOrder);
	void sortName(vector<vector<string>> information, string sortType, int *& itemOrder);
	void sortPriority(vector<vector<string>> information, string sortType, int *& itemOrder);
	void sortTimeLeft(vector<vector<string>> information, string sortType, int *& itemOrder);

};