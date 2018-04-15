#pragma once
#include <string>
System::String^ convertToSystemString(std::string text);
std::string convertToStdString(System::String^ text);

