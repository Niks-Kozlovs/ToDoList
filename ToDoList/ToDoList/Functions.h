#pragma once
#include <string>
#include <iostream>
#include <vector>\

//Pārveidošana
System::String^ convertToSystemString(std::string text);
std::string convertToStdString(System::String^ text);
//Tekst parsing by delimiter
std::vector<std::string> seperateItems(std::string text, std::string delimiter);
