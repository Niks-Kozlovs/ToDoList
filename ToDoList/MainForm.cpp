#include <fstream>
#include <msclr/marshal_cppstd.h>
#include "MainForm.h"
#include "ToDoList.h"
#include "Functions.h"
#include "INIReader.h"
#include "SimpleInputBox.h"

System::Void ToDoApp::MainForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	////Atslēdz, lai lietotājs nevar neko darīt kamēr pievieno jaunu informāciju
//this->Enabled = false;
////Izveido un parāda jaunu form priekš informācijas ievades
////Tā izskatīsies labāk nekā piepildīt galveno form ar dažādiem text boxiem
//AddItem^ addItem = gcnew AddItem(convertToSystemString(currentListFile));
//addItem->ShowDialog();
////Pēc form aizstaisīšanas galvenais form atkal tiek ieslēgts
//this->Enabled = true;

////Pārnes saņemto informāciju (ja tāda ir) uz listview.
////Iztīra visu no listview, lai tas neatkārtotos divas reizes
//std::vector<std::string> list;
//std::string buffer;
//INIReader reader("settings.ini");
//if (reader.ParseError() < 0) {
//	MessageBox::Show("Reader parse error");
//}
//std::string fileLocation = defLocation
//	//MessageBox::Show(convertToSystemString(fileLocation));
//ifstream file(fileLocation);
//int i = 0;

//information.clear();
//while (!file.eof()) {
//	getline(file, buffer);
//	if (buffer == "") { break; }
//	std::vector<std::string> text;
//	text = seperateItems(buffer, "|");
//	information.push_back(text);
//	i++;
//}
//file.close();

//resetItemOrder(information, itemOrder);

//if (clickedColumn != -1) { //Ja ir sortots
//	Sorting sortItem;
//	std::string sortType = convertToStdString(comboBox1->Text);

//	sortItem.sortItems(information, sortType, clickedColumn, itemOrder);
//}

//if (isFiltered) {
//	std::string textToFilter = convertToStdString(textBox1->Text);
//	filterItemOrder.clear();
//	for (size_t i = 0; i < itemOrder.size(); i++) {
//		std::string textToCheck = information.at(itemOrder.at(i)).at(clickedColumn);
//		std::transform(textToCheck.begin(), textToCheck.end(), textToCheck.begin(), ::toupper);
//		std::transform(textToFilter.begin(), textToFilter.end(), textToFilter.begin(), ::toupper);
//		//name.find('|') != string::npos
//		if (textToCheck.find(textToFilter) != string::npos) {
//			filterItemOrder.push_back(itemOrder.at(i));
//		}
//	}

//	isFiltered = true;
//} 

//updateListView(listView1, information, itemOrder, filterItemOrder, isFiltered);

//for (i = 0; i < listView1->Items->Count; i++) {
//	TimeManager date(convertToStdString(listView1->Items[i]->SubItems[0]->Text));
//	listView1->Items[i]->SubItems->Add(convertToSystemString(date.getTimeDifference()));
//}

}

System::Void ToDoApp::MainForm::listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (this->listView1->SelectedItems->Count == 1) {
		button2->Enabled = true; //More info poga varēs tikai parādīt informāciju par vienu lietu
		button3->Enabled = true;
		button4->Enabled = true;
	}
	else if (this->listView1->SelectedItems->Count > 1) {
		//button3->Enabled = true;
		//button2->Enabled = false;

	}
	else {
		button2->Enabled = false;
		button3->Enabled = false;
		button4->Enabled = false;
	}
}

System::Void ToDoApp::MainForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	//this->Enabled = false;

	//MoreInfo^ moreInfo = gcnew MoreInfo(information.at(listView1->FocusedItem->Index));
	//moreInfo->ShowDialog();
	////Pogas vajag atslēgt, jo kad aiztaisas logs, tad nekas no saraksta nav izvēlēts, bet uz pogām vēl var uzpiest
	//button2->Enabled = false;
	//button3->Enabled = false;
	//button4->Enabled = false;
	//this->Enabled = true;

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
	//MessageBox::Show(e->Column.ToString()); //Tells which column was clicked
		//MessageBox::Show(this->listView1->FocusedItem->Index.ToString());
	if (listView1->Items->Count > 1) {
		clickedColumn = e->Column;
		label1->Text = "Selected: " + listView1->Columns[clickedColumn]->Text;
		//Set combobox parameters
		comboBox1->Items->Clear();

		comboBox1->Text = "";

		comboBox1->Enabled = true;
		textBox1->Enabled = true;

		switch (clickedColumn)
		{
		case 0:
			//Date
			comboBox1->Items->Add("High to low");
			comboBox1->Items->Add("Low to high");
			textBox1->Enabled = true;
			break;
		case 1:
			//Name
			comboBox1->Items->Add("A-Z");
			comboBox1->Items->Add("Z-A");
			textBox1->Enabled = true;
			break;
		case 2:
			//Priority
			comboBox1->Items->Add("High to low");
			comboBox1->Items->Add("Low to high");
			textBox1->Enabled = true;
			break;
		case 3:
			//Description (Nav ko kartot tapec disable)
			comboBox1->Enabled = false;
			textBox1->Enabled = true;
			break;
		case 4:
			//Time left
			comboBox1->Items->Add("High to low");
			comboBox1->Items->Add("Low to high");
			textBox1->Enabled = true;
			break;
		default:
			break;
		}
	}
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
}

void ToDoApp::MainForm::handleFirstTimeLaunch(System::String^& location, System::String^& listName)
{
	System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog = gcnew System::Windows::Forms::FolderBrowserDialog();
	MessageBox::Show("Program has noticed this is the first time you are launching this program. Please choose save location!");
	if (folderBrowserDialog->ShowDialog() != System::Windows::Forms::DialogResult::OK) {
		MessageBox::Show("No location selected. Exiting.");
		exit(0);
	}

	MessageBox::Show("Please choose a name for the list!");
	SimpleInputBox^ form = gcnew SimpleInputBox("Please enter the name of the list:", "Default");
	form->ShowDialog();

	location = folderBrowserDialog->SelectedPath;
	listName = form->TextBoxValue;
	createIniFile(location, listName);
	createRootFolder(location);
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
