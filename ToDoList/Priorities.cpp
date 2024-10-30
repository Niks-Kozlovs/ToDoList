#include <msclr/marshal_cppstd.h>
#include "Priorities.h"
#include "INIReader.h"

void Priorities::AddPriority(int value, System::String^ name)
{
	Priority^ priority = gcnew Priority(value, name);
	this->priorities->Add(priority);
}

void Priorities::AddPriority(Priority^ priority)
{
	this->priorities->Add(priority);
}

Priority^ Priorities::GetPriorityByValue(int value)
{
	for each (Priority ^ priority in this->priorities)
	{
		if (priority->Value == value)
		{
			return priority;
		}
	}
	return gcnew Priority(-1, "Unknown");
}

System::String^ Priorities::GetNameByValue(int value)
{
	for each (Priority ^ priority in this->priorities)
	{
		if (priority->Value == value)
		{
			return priority->NameVal;
		}
	}
	return "Unknown";
}

int Priorities::GetValueByName(System::String^ name)
{
	for each (Priority ^ priority in this->priorities)
	{
		if (priority->NameVal == name)
		{
			return priority->Value;
		}
	}
	return -1;
}

void Priorities::AddFromString(System::String^ line)
{
	array<System::String^>^ parts = line->Split('|');
	this->AddPriority(System::Convert::ToInt32(parts[1]), parts[0]);
}

void Priorities::SavePriorities()
{
	System::IO::StreamWriter^ writer = System::IO::File::CreateText(this->priorityLocation);
	for each (Priority ^ priority in this->priorities)
	{
		writer->WriteLine(priority->NameVal + "|" + priority->Value);
	}
	writer->Close();
}

System::Collections::Generic::List<Priority^>^ Priorities::GetPriorities()
{
	return this->priorities;
}

Priorities::Priorities()
{
	INIReader iniReader = INIReader("settings.ini");
	this->priorityLocation = msclr::interop::marshal_as<System::String^>(iniReader.Get("USER", "saveLocation", "priority.txt") + "\\priority.txt");

	System::IO::StreamReader^ reader = System::IO::File::OpenText(this->priorityLocation);
	while (!reader->EndOfStream)
	{
		System::String^ line = reader->ReadLine();
		this->AddFromString(line);
	}
	reader->Close();
}
