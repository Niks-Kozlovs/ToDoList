#include "ToDoListItem.h"

ToDoListItem::ToDoListItem(System::String^ name, System::String^ description, int priority, System::String^ time)
{
	this->name = name;
	this->description = description;
	this->priority = priority;
	this->time = time;
}

ToDoListItem::ToDoListItem(System::String^ line)
{
	array<System::String^>^ components = line->Split('|');
	this->name = components[0];
	this->description = components[1];
	this->priority = System::Int32::Parse(components[2]);
	this->time = components[3];
}

System::String^ ToDoListItem::ToString()
{
	return this->name + "|" + this->description + "|" + this->priority + "|" + this->time;
}
