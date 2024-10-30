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
		button3->Enabled = true;
		button4->Enabled = true;
	}
	else if (this->toDoListView->SelectedItems->Count > 1) {
		//button3->Enabled = true;
		//button2->Enabled = false;

	}
	else {
		moreInfoButton->Enabled = false;
		button3->Enabled = false;
		button4->Enabled = false;
	}
}

System::Void ToDoApp::MainForm::moreInfoButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	ToDoListItem^ item = this->toDoList->items[this->toDoListView->SelectedItems[0]->Index];
	MoreInfo^ moreInfo = gcnew MoreInfo(item);
	moreInfo->ShowDialog(this);
}

System::Void ToDoApp::MainForm::listView1_Enter(System::Object^ sender, System::EventArgs^ e)
{
	//timer1->Start();
	//information.clear();
	//std::vector<std::string> list;
	//std::string buffer;
	//INIReader reader("settings.ini");
	//if (reader.ParseError() < 0) {
	//	MessageBox::Show("Reader parse error");
	//}
	//std::string fileLocation = "defLocation"; //Saņem faila vietu no config faila
	//ifstream file(fileLocation);
	//int i = 0;

	//while (!file.eof()) {
	//	getline(file, buffer);
	//	if (buffer == "") { break; }
	//	std::vector<std::string> text;
	//	text = seperateItems(buffer, "|");
	//	information.push_back(text);
	//	i++;
	//}

	//if (clickedColumn == -1) { //Ja ir sortots
	//	resetItemOrder(information, itemOrder);
	//}
	//else {
	//	Sorting sortItem;
	//	std::string sortType = convertToStdString(comboBox1->Text);

	//	sortItem.sortItems(information, sortType, clickedColumn, itemOrder);
	//}

	//file.close();

	//updateListView(listView1, information, itemOrder, filterItemOrder, isFiltered);
	//for (int i = 0; i < listView1->Items->Count; i++) {
	//	TimeManager date1(convertToStdString(listView1->Items[i]->SubItems[0]->Text));
	//	listView1->Items[i]->SubItems->Add(convertToSystemString(date1.getTimeDifference())); //Pievieno sarakstā
	//}
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

System::Void ToDoApp::MainForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	////Dzes ara no saraksta
	//int index = this->listView1->FocusedItem->Index;
	//listView1->SelectedItems[0]->Remove();

	////Vector update
	//information.erase(information.begin() + itemOrder.at(index)); //Paņem vajadzīgo indeksu no itemOrder un izdēš to
	//itemOrder.erase(itemOrder.begin() + index); //Pēc tam izdzēš to indeksu no itemOrder, tas nozīmē, ka var izdēst pat ja ir sortots un filtrēts


	////File update
	//INIReader reader("settings.ini");
	//if (reader.ParseError() < 0) {
	//	//Error
	//}
	//std::string fileLocation = "defLocation";
	//ofstream file(fileLocation);

	//for (size_t i = 0; i < information.size(); i++) {
	//	for (size_t j = 0; j < information.at(i).size() - 1; j++) {
	//		file << information.at(i).at(j) << "|";
	//	}
	//	file << information.at(i).at(information.at(i).size() - 1) << endl;
	//}
	//information.clear();
}

System::Void ToDoApp::MainForm::changeSaveLocationToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	//Programmai vajag iziet, savādāk saglabāšanās vieta netiek atjaunināta neskapēc
//if (folderBrowserDialog1->ShowDialog().ToString() == "OK") {
//	createIniFile(convertToStdString(folderBrowserDialog1->SelectedPath), currentListFile);
//	MessageBox::Show("The program will now close for the changes to take effect");
//	exit(0);
//}
}

System::Void ToDoApp::MainForm::timer1_Tick(System::Object^ sender, System::EventArgs^ e)
{
	//for (int i = 0; i < listView1->Items->Count; i++) {
	//	TimeManager date(convertToStdString(listView1->Items[i]->SubItems[0]->Text));
	//	listView1->Items[i]->SubItems[4]->Text = convertToSystemString(date.getTimeDifference());
	//	if (listView1->Items[i]->SubItems[4]->Text == "Time has passed") { //Ja laiks ir pagajis, tad true
	//		//Make item red
	//	}
	//}
}

System::Void ToDoApp::MainForm::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	//AddItem^ edit = gcnew AddItem(information.at(listView1->FocusedItem->Index), (int)listView1->FocusedItem->Index, convertToSystemString(currentListFile));
//edit->ShowDialog();

//button2->Enabled = false;
//button3->Enabled = false;
//button4->Enabled = false;

}

System::Void ToDoApp::MainForm::comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	//Sorting sortItem;
	//std::string sortType = convertToStdString(comboBox1->Text);
	//if (!isFiltered) {
	//	sortItem.sortItems(information, sortType, clickedColumn, itemOrder);
	//}
	//else {
	//	sortItem.sortItems(information, sortType, clickedColumn, filterItemOrder);
	//}

	//updateListView(listView1, information, itemOrder, filterItemOrder, isFiltered);

}

System::Void ToDoApp::MainForm::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	//comboBox1->Enabled = false;
	//comboBox1->Items->Clear();
	//comboBox1->Text = "";

	//textBox1->Text = "";
	//textBox1->Enabled = false;

	//label1->Text = "Selected: None";
	//clickedColumn = -1;
	//isFiltered = false;

	//filterItemOrder.clear();
	//resetItemOrder(information, itemOrder);

	//updateListView(listView1, information, itemOrder, filterItemOrder, isFiltered);
}

System::Void ToDoApp::MainForm::textBox1_TextChanged_1(System::Object^ sender, System::EventArgs^ e)
{
	//std::string textToFilter = convertToStdString(textBox1->Text);
	//filterItemOrder.clear();
	//for (size_t i = 0; i < itemOrder.size(); i++) {
	//	std::string textToCheck = information.at(itemOrder.at(i)).at(clickedColumn);
	//	std::transform(textToCheck.begin(), textToCheck.end(), textToCheck.begin(), ::toupper);
	//	std::transform(textToFilter.begin(), textToFilter.end(), textToFilter.begin(), ::toupper);

	//	if (textToCheck.find(textToFilter) != string::npos) {
	//		filterItemOrder.push_back(itemOrder.at(i));
	//	}
	//}

	//isFiltered = true;
	//updateListView(listView1, information, itemOrder, filterItemOrder, isFiltered);
}

System::Void ToDoApp::MainForm::addNewListToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	////Add new list
	////Izveido un parāda jaunu logu informācijas ievadei
	//SimpleInputBox^ form = gcnew SimpleInputBox("Please enter the name of the list:", "New list");
	//this->Enabled = false;
	//form->ShowDialog();
	////Saņem no tā vērtības, kad ok tika uzspiests
	//String^ textFromForm = form->TextBoxValue;
	//this->Enabled = true;
	//std::string listName = convertToStdString(textFromForm);


	//INIReader reader("settings.ini");
	//if (reader.ParseError() < 0) {
	//	MessageBox::Show("Reader parse error");
	//}

	//std::string selectedSaveLocation = "defLocationNoEnding";
	//std::string saveLocation = selectedSaveLocation + listName + ".txt";
	//fstream fileCreate(saveLocation, ios::in | ios::out | ios::app);
	//fileCreate.close();

	//comboBox2->Items->Add(convertToSystemString(listName));
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
	////Tiek nomainīts uz citu sarakstu
	//currentListFile = convertToStdString(comboBox2->Text);


	////Copy paste no load metodes :(
	//information.clear();
	//std::vector<std::string> list;
	//std::string buffer;
	//INIReader reader("settings.ini");
	//if (reader.ParseError() < 0) {
	//	MessageBox::Show("Reader parse error");
	//}
	//std::string fileLocation = "defLocation";
	//ifstream file(fileLocation);
	//int i = 0;

	//while (!file.eof()) {
	//	getline(file, buffer);
	//	if (buffer == "") { break; }
	//	std::vector<std::string> text;
	//	text = seperateItems(buffer, "|");
	//	information.push_back(text);
	//	i++;
	//}

	//if (clickedColumn == -1) {
	//	resetItemOrder(information, itemOrder);
	//}
	//else {
	//	Sorting sortItem;
	//	std::string sortType = convertToStdString(comboBox1->Text);

	//	sortItem.sortItems(information, sortType, clickedColumn, itemOrder);
	//}

	//file.close();

	//updateListView(listView1, information, itemOrder, filterItemOrder, isFiltered);
	//for (int i = 0; i < listView1->Items->Count; i++) {
	//	TimeManager date1(convertToStdString(listView1->Items[i]->SubItems[0]->Text));
	//	listView1->Items[i]->SubItems->Add(convertToSystemString(date1.getTimeDifference()));
	//}
}
