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
{ //Atjauno listView, lai nevajadzētu copy paste
	listView->Items->Clear();
	if (!isFiltered) {
		for (size_t i = 0; i < itemOrder.size(); i++) {
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
		for (size_t i = 0; i < filteredItemOrder.size(); i++) {
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

void createIniFile(std::string location, std::string currentList, std::string firstTimeLaunch)
{ //Izveido ini failu, pat ja tas tiek izdēsts
	std::ofstream settings("settings.ini");
	settings << "[FIRSTTIMELAUNCH]" << std::endl;
	settings << "firstTime=" + firstTimeLaunch << std::endl;
	settings << "[USER]" << std::endl;
	settings << "saveLocation = " + location + '\\' << std::endl;
	settings << "selectedForm = " + currentList;
	settings.close();

}

bool checkIfDuplicate(std::string fileLocation, int column, std::string value) {
	//Pārbauda vai divi stringi ir vienādi
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
	//itemOrder vektors tiek pārveidots uz default (1,2,3,4,...), itemOrder rūpējas kādā secībā rādīt visu.
	itemOrder.clear();
	for (size_t i = 0; i < information.size(); i++) {
		itemOrder.push_back(i);
	}
}

std::vector<std::string> get_all_files_names_within_folder(std::string folder)
{//Saņemt faila nosaukumus kādā vietā
	std::vector<std::string> names;
	std::string search_path = folder + "/*.txt";
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			// read all (real) files in current folder
			// , delete '!' read other 2 default folder . and ..
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				names.push_back(fd.cFileName);
			}
		} while (::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}
	return names;
}

void createFolder(const char * path)
{//Izveidot folder, jo fstream to negrib darīt
	if (!CreateDirectory(path, NULL))
	{
		return;
	}
}

void createRootFolder(const char * path) {
	createFolder(path); //Root folder

	std::string buffer = path + (std::string)"\\Lists"; //Char un char array nevar ielikt kā parametrus vienā funkcijā kopā, tapēc izveidoju string la savienotu abus pirms tā
	createFolder(buffer.c_str());

	buffer = path + (std::string)"\\Other";
	createFolder(buffer.c_str());
}
