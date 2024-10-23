#pragma once
ref class ToDoListItem
{
public:
	System::String^ name;
	System::String^ description;
	int priority;
	System::String^ time;

public:
	ToDoListItem(System::String^ name, System::String^ description, int priority, System::String^ time);
	ToDoListItem(System::String^ line);
	System::String^ ToString() override;
};
