#pragma once
#include "ToDoListItem.h"
ref class ToDoList
{
public:
	ToDoList(System::String^ filename);
	void AddItem(ToDoListItem^ item);
	void RemoveItem(int index);
	void Save(System::String^ filename);
	void Save();
	System::Collections::Generic::List<ToDoListItem^>^ items;
private:
	System::String^ filename;
	System::String^ listName;
};

