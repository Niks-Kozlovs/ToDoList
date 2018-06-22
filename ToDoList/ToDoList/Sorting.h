#pragma once
#include <string>
#include <vector>
#include "TimeManager.h"
#include "Functions.h"
#include "INIReader.h"
#include <algorithm>
#include <fstream>
//#include "Functions.h"

//Dažādi sorting algoritmi, kas tiek izmanotti (pēc nosaukuma un pēc vērtības)
struct priorityValues
{
	std::string name;
	int value;
};


using namespace std;

class Sorting {
public:
	Sorting();
	void sortItems(vector<vector<string>> & information, string sortType, int columns, vector<int> & itemOrder);
	void sortDate(vector<vector<string>> & information, string sortType, vector<int> & itemOrder);
	void sortText(vector<vector<string>> & information, string sortType, vector<int> & itemOrder, int columnClicked);
	void sortPriority(vector<vector<string>> & information, string sortType, vector<int> & itemOrder);

};