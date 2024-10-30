#include "ToDoListItem.h"
#include "Priorities.h"

ToDoListItem::ToDoListItem(System::String^ name, System::String^ description, Priority^ priority, System::DateTime^ time)
{
	this->name = name;
	this->description = description;
	this->priority = priority;
	this->time = time;
}

ToDoListItem::ToDoListItem(System::String^ line)
{
	Priorities^ priorities = gcnew Priorities();
	array<System::String^>^ components = line->Split('|');
	int priorityVal = System::Int32::Parse(components[2]);
	this->name = components[0];
	this->description = components[1];
	this->priority = priorities->GetPriorityByValue(priorityVal);
	this->time = System::DateTime::Parse(components[3]);
}

System::String^ ToDoListItem::ToString()
{
	return this->name + "|" + this->description + "|" + this->priority->Value + "|" + this->time->ToString();
}

System::Windows::Forms::ListViewItem^ ToDoListItem::toListViewItem()
{
	System::Windows::Forms::ListViewItem^ listViewItem = gcnew System::Windows::Forms::ListViewItem(this->time->ToShortDateString());
	System::TimeSpan^ timeLeft = this->time->Subtract(System::DateTime::Now);

	listViewItem->SubItems->Add(this->name);
	listViewItem->SubItems->Add(this->priority->NameVal);
	listViewItem->SubItems->Add(this->description);
	listViewItem->SubItems->Add(
		(timeLeft->Days > 0 ? timeLeft->Days + "d" : "") +
		(timeLeft->Hours > 0 ? timeLeft->Hours + "h" : "") +
		(timeLeft->Minutes > 0 ? timeLeft->Minutes + "m" : "")
	);
	listViewItem->Tag = this;
	return listViewItem;
}
