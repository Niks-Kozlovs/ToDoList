#include "Functions.h"

void createIniFile(System::String^ location, System::String^ currentList)
{
	System::IO::StreamWriter^ writer = System::IO::File::CreateText("settings.ini");
	writer->WriteLine("[USER]");
	writer->WriteLine("saveLocation = " + location);
	writer->WriteLine("selectedForm = " + currentList);
	writer->Close();
}

void createRootFolder(System::String^ path) {
	System::IO::Directory::CreateDirectory(path + "\\Lists");
	System::IO::File::CreateText(path + "\\priority.txt")->Close();
}
