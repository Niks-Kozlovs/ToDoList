#include "AddItemForm.h"

System::Void ToDoApp::AddItemForm::okButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	String^ name = this->textBox4->Text;
	String^ priority = this->comboBox1->Text;
	String^ description = this->richTextBox1->Text;
	this->item = gcnew ToDoListItem(name, description, 1, "TODO");
	this->Close();

	//string date = convertToStdString(this->dateTimePicker1->Text); //Pārveido no (System::String uz std::string
	//int hour = (int)this->numericUpDown1->Value;
	//int minute = (int)this->numericUpDown2->Value;
	//int second = (int)this->numericUpDown3->Value;

	//TimeManager time(date, hour, minute, second);

	//string name = convertToStdString(this->textBox4->Text);
	//string priority = convertToStdString(this->comboBox1->Text);
	//string description = convertToStdString(this->richTextBox1->Text);

	////Pābaudes vai viss ir labi
	//if (!time.isDateInPast()) {
	//	MessageBox::Show("The current date is in the past");
	//} else if (name == "" || priority == "") {
	//	MessageBox::Show("Name and/or priority not entered");
	//}
	//else if (name.find('|') != string::npos) {
	//	MessageBox::Show("Name contains an illegal character \"|\"");
	//}
	//else if (!edit) {
	//	/*

	//	Pievienot jaunu itemu

	//	*/

	//		INIReader reader("settings.ini");
	//		if (reader.ParseError() < 0) {
	//			//Error
	//		}
	//		std::string fileLocation = reader.Get("USER", "saveLocation", "") + R"(Lists\)" + convertToStdString(currentListFile) + ".txt";
	//			ofstream file(fileLocation, ios::app | ios::out);
	//		file << time.getTimeFull() << "|" << name << "|" << priority << "|" << description << endl;
	//		file.close();
	//		this->Close();
	//}
	//else {
	//	/*

	//		Rediģēt esošo itemu

	//	*/

	//		INIReader reader("settings.ini");
	//		if (reader.ParseError() < 0) {
	//			MessageBox::Show("Reader parse error");
	//		}
	//		std::string tempFileLocation = defTempFileLocation;
	//		std::string fileLocation = reader.Get("USER", "saveLocation", "") + R"(Lists\)" + convertToStdString(currentListFile) + ".txt";

	//		ifstream file(fileLocation);
	//		ofstream tempFile(tempFileLocation);

	//		int countIndex = 0;

	//		while (!file.eof()) {

	//			std::string buffer;

	//			getline(file, buffer);
	//			if (countIndex == index) {
	//				tempFile << time.getTimeFull() << "|" << name << "|" << priority << "|" << description << endl;
	//			}
	//			else {
	//				tempFile << buffer << endl;
	//			}
	//				countIndex++;
	//		}
	//		
	//		tempFile.close();
	//		file.close();
	//		remove(fileLocation.c_str());
	//		rename(tempFileLocation.c_str(), fileLocation.c_str());
	//		this->Close();
	//	}
}
