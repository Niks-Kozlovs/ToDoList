#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <Windows.h>
//Random funkcijas kuras var izmantot dažādos gadijumos

//Pārveidošana
System::String^ convertToSystemString(std::string text);
std::string convertToStdString(System::String^ text);

//Tekst parsing by delimiter
std::vector<std::string> seperateItems(std::string text, std::string delimiter);
//void updateListView(System::Windows::Forms::ListView^ listView, std::vector<std::vector<std::string>> information);
void updateListView(System::Windows::Forms::ListView^ listView, std::vector<std::vector<std::string>> & information, std::vector<int> & itemOrder, std::vector<int> &filteredItemOrder, bool isFiltered);

void createIniFile(std::string location, std::string currentList, std::string firstTimeLaunch);

bool checkIfDuplicate(std::string fileLocation, int column, std::string value);

void resetItemOrder(std::vector<std::vector<std::string>> & information, std::vector<int>& itemOrder);

std::vector<std::string> get_all_files_names_within_folder(std::string folder);

void createFolder(const char * path);
void createRootFolder(const char * path); //Creates main folder and subfolders