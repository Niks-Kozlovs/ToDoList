#include "ToDoList.h"
#include "ToDoListItem.h"

ToDoList::ToDoList(System::String^ filename)
{
	this->filename = filename;
	this->items = gcnew System::Collections::Generic::List<ToDoListItem^>();

	if (!System::IO::File::Exists(filename))
	{
		System::IO::File::CreateText(filename)->Close();
		return;
	}

	System::IO::StreamReader^ reader = System::IO::File::OpenText(filename);
	while (!reader->EndOfStream)
	{
		System::String^ line = reader->ReadLine();
		ToDoListItem^ item = gcnew ToDoListItem(line);
		this->items->Add(item);
	}
	reader->Close();
}

void ToDoList::AddItem(ToDoListItem^ item)
{
	this->items->Add(item);
	this->Save();
}

void ToDoList::RemoveItem(int index)
{
	this->items->RemoveAt(index);
	this->Save();
}

void ToDoList::Save(System::String^ filename)
{
	System::IO::StreamWriter^ writer = System::IO::File::CreateText(filename);
	for each (ToDoListItem ^ item in this->items)
	{
		writer->WriteLine(item->ToString());
	}
	writer->Close();
}

void ToDoList::Save()
{
	this->Save(this->filename);
}
