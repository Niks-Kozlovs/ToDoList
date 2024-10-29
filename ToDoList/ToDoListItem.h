#pragma once
#include "Priorities.h"
ref class ToDoListItem
{
public:
	System::String^ name;
	System::String^ description;
	Priority^ priority;
	System::DateTime^ time;

public:
	ToDoListItem(System::String^ name, System::String^ description, Priority^ priority, System::DateTime^ time);
	ToDoListItem(System::String^ line);
	System::Windows::Forms::ListViewItem^ ToDoListItem::toListViewItem();
	System::String^ ToString() override;
};
