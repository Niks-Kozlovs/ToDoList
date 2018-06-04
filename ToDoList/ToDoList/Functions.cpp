#include "Functions.h"
#include <fstream>
#include <msclr/marshal_cppstd.h>


System::String ^ convertToSystemString(std::string text)
{
	return gcnew System::String(text.c_str());
}

std::string convertToStdString(System::String ^ text)
{
	return msclr::interop::marshal_as< std::string >(text);
}

std::vector<std::string> seperateItems(std::string text, std::string delimiter) //Atdala lietas starp kurām ir tekts, kas ir ievadīts parametrā delimiter
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

void updateListView(System::Windows::Forms::ListView^ listView, std::vector<std::vector<std::string>> & information, std::vector<int> & itemOrder, std::vector<int> & filteredItemOrder, bool isFiltered) 
{
	listView->Items->Clear();
	if (!isFiltered) {
		for (int i = 0; i < itemOrder.size(); i++) {
			int j = 0;
			int itemPlace = itemOrder.at(i);
			listView->Items->Add(convertToSystemString(information[itemPlace][j]));
			for (j = 1; j < listView->Columns->Count - 1; j++) {
				listView->Items[i]->SubItems->Add(convertToSystemString(information[itemPlace][j]));
			}
			listView->Items[i]->SubItems->Add("");
		}
	}
	else {
		for (int i = 0; i < filteredItemOrder.size(); i++) {
			int j = 0;
			int itemPlace = filteredItemOrder.at(i);
			listView->Items->Add(convertToSystemString(information[itemPlace][j]));
			for (j = 1; j < listView->Columns->Count - 1; j++) {
				listView->Items[i]->SubItems->Add(convertToSystemString(information[itemPlace][j]));
			}
			listView->Items[i]->SubItems->Add("");
		}
	}
}

void createIniFile(std::string location)
{
	std::ofstream settings("settings.ini");
	settings << "[FIRSTTIMELAUNCH]" << std::endl;
	settings << "firstTime=false" << std::endl;
	settings << "[USER]" << std::endl;
	settings << "saveLocation = " + location + '\\';
	settings << "selectedForm = ";
	settings.close();

}

bool checkIfDuplicate(std::string fileLocation, int column, std::string value) {
	std::ifstream file(fileLocation);
	std::vector<std::string> info;
	while (!file.eof()) {
		std::string buffer;

		getline(file, buffer);
		if (buffer == "") { return false; } //Faila beigas vai ir tuks
		info = seperateItems(buffer, "|");
		if (value == info.at(column)) {
			return true;
		}
	}
	return false;
}

void resetItemOrder(std::vector<std::vector<std::string>>& information, std::vector<int>& itemOrder)
{
	itemOrder.clear();
	for (int i = 0; i < information.size(); i++) {
		itemOrder.push_back(i);
	}
}
