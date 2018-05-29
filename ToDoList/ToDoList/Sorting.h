#pragma once
#include <string>
#include <vector>
#include "TimeManager.h"
//#include "Functions.h"


using namespace std;

class Sorting {
public:
	Sorting();
	void sortItems(vector<vector<string>> information, string sortType, int columns, vector<int> itemOrder);
	void sortDate(vector<vector<string>> information, string sortType, vector<int> itemOrder);
	void sortName(vector<vector<string>> information, string sortType, vector<int> itemOrder);
	void sortPriority(vector<vector<string>> information, string sortType, vector<int> itemOrder);
	void sortTimeLeft(vector<vector<string>> information, string sortType, vector<int> itemOrder);

};