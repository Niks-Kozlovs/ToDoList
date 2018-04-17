#include "Functions.h"
#include <msclr/marshal_cppstd.h>


System::String ^ convertToSystemString(std::string text)
{
	return gcnew System::String(text.c_str());
}

std::string convertToStdString(System::String ^ text)
{
	return msclr::interop::marshal_as< std::string >(text);
}

std::vector<std::string> seperateItems(std::string text, std::string delimiter)
{
	std::vector<std::string> information;
	auto start = 0U;
	auto end = text.find(delimiter);
	while (end != std::string::npos) {
		information.push_back(text.substr(start, end - start));
		start = end + delimiter.length();
		end = text.find(delimiter, start);
	}

	information.push_back(text.substr(start, end));

	return information;
}
