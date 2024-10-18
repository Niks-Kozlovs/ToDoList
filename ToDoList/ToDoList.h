#pragma once
#include "ToDoListItem.h"
ref class ToDoList
{
public:
	ToDoList(System::String^ filename);
	void AddItem(ToDoListItem^ item);
	void RemoveItem(int index);
	void Save(System::String^ filename);
private:
	System::String^ filename;
	System::String^ listName;
	System::Collections::Generic::List<ToDoListItem^>^ items;
	void Save();
};

