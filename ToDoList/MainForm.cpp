#include <fstream>
#include <msclr/marshal_cppstd.h>
#include "MainForm.h"
#include "ToDoList.h"
#include "Functions.h"
#include "INIReader.h"
#include "SimpleInputBox.h"
#include "AddItemForm.h"
#include "ToDoListSorter.h"
#include "MoreInfo.h"

System::Void ToDoApp::MainForm::listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (this->toDoListView->SelectedItems->Count == 1) {
		moreInfoButton->Enabled = true; //More info poga varēs tikai parādīt informāciju par vienu lietu
		deleteButton->Enabled = true;
		editButton->Enabled = true;
	}
	else if (this->toDoListView->SelectedItems->Count > 1) {
		deleteButton->Enabled = true;
		editButton->Enabled = false;
		moreInfoButton->Enabled = false;
	}
	else {
		moreInfoButton->Enabled = false;
		deleteButton->Enabled = false;
		editButton->Enabled = false;
	}
}

System::Void ToDoApp::MainForm::moreInfoButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	ToDoListItem^ item = dynamic_cast<ToDoListItem^>(this->toDoListView->SelectedItems[0]->Tag);
	MoreInfo^ moreInfo = gcnew MoreInfo(item);
	moreInfo->ShowDialog(this);
}

System::Void ToDoApp::MainForm::listView1_Enter(System::Object^ sender, System::EventArgs^ e)
{
}

System::Void ToDoApp::MainForm::listView1_ColumnClick(System::Object^ sender, System::Windows::Forms::ColumnClickEventArgs^ e)
{
	ToDoListSorter^ sorter = dynamic_cast<ToDoListSorter^>(toDoListView->ListViewItemSorter);
	if (e->Column == sorter->ColumnToSort)
	{
		// Reverse the sorting order if the same column is clicked
		if (sorter->OrderOfSort == System::Windows::Forms::SortOrder::Ascending)
		{
			sorter->OrderOfSort = System::Windows::Forms::SortOrder::Descending;
		}
		else
		{
			sorter->OrderOfSort = System::Windows::Forms::SortOrder::Ascending;
		}
	}
	else
	{
		sorter->ColumnToSort = e->Column;
		sorter->OrderOfSort = System::Windows::Forms::SortOrder::Ascending;
	}

	toDoListView->Sort();
}

System::Void ToDoApp::MainForm::deleteButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	toDoListView->BeginUpdate();
	for each (ListViewItem^ item in toDoListView->SelectedItems) {
        ToDoListItem^ itemToRemove = dynamic_cast<ToDoListItem^>(item->Tag);
		toDoList->RemoveItem(itemToRemove);
		toDoListView->Items->Remove(item);
	}
	toDoListView->EndUpdate();

}

System::Void ToDoApp::MainForm::changeSaveLocationToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
}

System::Void ToDoApp::MainForm::timer1_Tick(System::Object^ sender, System::EventArgs^ e)
{
}

System::Void ToDoApp::MainForm::editButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	ToDoListItem^ oldItem = dynamic_cast<ToDoListItem^>(this->toDoListView->SelectedItems[0]->Tag);
	AddItemForm^ edit = gcnew AddItemForm(oldItem);
	edit->ShowDialog(this);
	if (edit->DialogResult == System::Windows::Forms::DialogResult::OK) {
		ToDoListItem^ updatedItem = edit->Item;
		this->toDoList->UpdateItem(oldItem, updatedItem);
		this->toDoList->Save();
		this->populateListView();
	}
}

System::Void ToDoApp::MainForm::comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
}

System::Void ToDoApp::MainForm::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
}

System::Void ToDoApp::MainForm::filterInput_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	System::String^ filterText = filterInput->Text;
	if (filterText == "") {
		populateListView();
		return;
	}

	toDoListView->Items->Clear();
	for each (ToDoListItem ^ item in toDoList->items) {
		if (item->ToString()->Contains(filterText)) {
			toDoListView->Items->Add(item->toListViewItem());
		}
	}
}

System::Void ToDoApp::MainForm::addNewListToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
}

System::Void ToDoApp::MainForm::MainForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	std::ifstream file("settings.ini");
	String^ location;
	String^ listName;
	if (!file.good()) {
		handleFirstTimeLaunch(location, listName);
	}
	else {
		INIReader reader("settings.ini");
		location = msclr::interop::marshal_as<System::String^>(reader.Get("USER", "saveLocation", ""));
		listName = msclr::interop::marshal_as<System::String^>(reader.Get("USER", "selectedForm", "Default"));
	}

	this->Text = "ToDoList - " + listName;
	this->toDoList = gcnew ToDoList(location + "\\Lists\\" + listName + ".txt");
    cli::array<System::String^>^ fileNames = System::IO::Directory::GetFiles(location + "\\Lists\\");
	for (int i = 0; i < fileNames->Length; i++) {
		fileNames[i] = System::IO::Path::GetFileNameWithoutExtension(fileNames[i]);
	}
	listSelector->Items->AddRange(fileNames);
	listSelector->SelectedItem = listName;

	toDoListView->ListViewItemSorter = gcnew ToDoListSorter();

	populateListView();
}

void ToDoApp::MainForm::populateListView()
{
	this->toDoListView->Items->Clear();
	for each (ToDoListItem ^ item in this->toDoList->items) {
		this->toDoListView->Items->Add(item->toListViewItem());
	}
}

void ToDoApp::MainForm::handleFirstTimeLaunch(System::String^& location, System::String^& listName)
{
	System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog = gcnew System::Windows::Forms::FolderBrowserDialog();
	MessageBox::Show("Program has noticed this is the first time you are launching this program. Please choose save location!");
	if (folderBrowserDialog->ShowDialog(this) != System::Windows::Forms::DialogResult::OK) {
		MessageBox::Show("No location selected. Exiting.");
		exit(0);
	}

	MessageBox::Show("Please choose a name for the list!");
	SimpleInputBox^ form = gcnew SimpleInputBox("Please enter the name of the list:", "Default");
	form->ShowDialog(this);

	location = folderBrowserDialog->SelectedPath;
	listName = form->TextBoxValue;
	createIniFile(location, listName);
	createRootFolder(location);
}

System::Void ToDoApp::MainForm::buttonAddItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	AddItemForm^ addItemForm = gcnew AddItemForm();
	addItemForm->ShowDialog(this);

	if (addItemForm->DialogResult != System::Windows::Forms::DialogResult::OK) {
		return;
	}

	ToDoListItem^ item = addItemForm->Item;
	toDoList->AddItem(item);
	this->toDoListView->Items->Add(item->toListViewItem());
}

System::Void ToDoApp::MainForm::MainForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
	INIReader reader("settings.ini");
	if (reader.ParseError() < 0) {
		MessageBox::Show("Reader parse error");
	}
	std::string fileLocation = "defLocationNoEnding";
}

System::Void ToDoApp::MainForm::comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
}
