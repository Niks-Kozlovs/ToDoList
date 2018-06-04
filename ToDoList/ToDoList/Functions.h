#pragma once
#include <string>
#include <iostream>
#include <vector>\
//Random funkcijas kuras var izmantot dažādos gadijumos

//Pārveidošana
System::String^ convertToSystemString(std::string text);
std::string convertToStdString(System::String^ text);

//Tekst parsing by delimiter
std::vector<std::string> seperateItems(std::string text, std::string delimiter);
//void updateListView(System::Windows::Forms::ListView^ listView, std::vector<std::vector<std::string>> information);
void updateListView(System::Windows::Forms::ListView^ listView, std::vector<std::vector<std::string>> & information, std::vector<int> & itemOrder, std::vector<int> &filteredItemOrder, bool isFiltered);

void createIniFile(std::string location);

bool checkIfDuplicate(std::string fileLocation, int column, std::string value);

void resetItemOrder(std::vector<std::vector<std::string>> & information, std::vector<int>& itemOrder);

