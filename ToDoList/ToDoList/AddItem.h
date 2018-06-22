#pragma once
#define defTempFileLocation reader.Get("USER", "saveLocation", "list.txt") + R"(TempFile.txt)";
#define defPriorityLocation reader.Get("USER", "saveLocation", "priority.txt") + R"(Other\priority.txt)";

//#include <iostream>
#include <stdio.h>
#include "TimeManager.h"
#include <string>
#include "Functions.h"
//#include <fstream>
#include "INIReader.h"
#include "Priority.h"

namespace ToDoList {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddItem
	/// </summary>
	public ref class AddItem : public System::Windows::Forms::Form
	{
	private: bool edit;
	private: String ^ prioritySystem;
	private: int index;
	private: String ^ currentListFile = "";
	public:
		AddItem(String ^ currentListFile) //Make new
		{
			InitializeComponent();
			edit = false;
			this->currentListFile = currentListFile;
			//
			//TODO: Add the constructor code here
			//
		}
		AddItem(std::vector<std::string> listItem, int index, String ^ currentListName) //Edit
		{
			InitializeComponent();
			this->currentListFile = currentListName;
			edit = true;
			this->index = index;
			std::vector<std::string> dateTime;
			std::vector<std::string> values;
			dateTime = seperateItems(listItem.at(0), " ");


			//Pārvēŗš datumu un laiku no string uz int
			values = seperateItems(dateTime.at(0), "/");
			int day = atoi(values.at(0).c_str());
			int month = atoi(values.at(1).c_str());
			int year = atoi(values.at(2).c_str());
			
			values = seperateItems(dateTime.at(1), ":");
			int hour = std::atoi(values.at(0).c_str());
			int minute = std::atoi(values.at(1).c_str());
			int second = atoi(values.at(2).c_str());

			dateTimePicker1->Value = DateTime(year, month, day);
			numericUpDown1->Value = hour;
			numericUpDown2->Value = minute;
			numericUpDown3->Value = second;

			std::string name = listItem.at(1);
			std::string priority = listItem.at(2);
			std::string description = listItem.at(3);

			textBox4->Text = convertToSystemString(name);
			prioritySystem = convertToSystemString(priority); //Neskapēc combobox nepievieno sarakstam lietas ar inicializēšanu, tapēc tas tiek pārvietots uz load metodi
			richTextBox1->Text = convertToSystemString(description);

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddItem()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;

	private: System::Windows::Forms::Label^  label5;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;

	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown3;
	private: System::Windows::Forms::Button^  button3;

	private: System::ComponentModel::IContainer^  components;



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->button1->Location = System::Drawing::Point(286, 301);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(70, 35);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Cancel";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AddItem::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->button2->Location = System::Drawing::Point(212, 301);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(70, 35);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Ok";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AddItem::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->label1->Location = System::Drawing::Point(9, 7);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 16);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Date";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->label2->Location = System::Drawing::Point(9, 61);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Name";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->label3->Location = System::Drawing::Point(9, 89);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 16);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Priority";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->label4->Location = System::Drawing::Point(9, 118);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(73, 16);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Description";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Cursor = System::Windows::Forms::Cursors::Default;
			this->dateTimePicker1->CustomFormat = L"dd/MM/yyyy";
			this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker1->Location = System::Drawing::Point(86, 7);
			this->dateTimePicker1->Margin = System::Windows::Forms::Padding(2);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(270, 22);
			this->dateTimePicker1->TabIndex = 1;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->label5->Location = System::Drawing::Point(9, 32);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(36, 16);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Time";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->label6->Location = System::Drawing::Point(84, 32);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(42, 16);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Hours";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->label7->Location = System::Drawing::Point(162, 32);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(54, 16);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Minutes";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->label8->Location = System::Drawing::Point(258, 32);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(59, 16);
			this->label8->TabIndex = 13;
			this->label8->Text = L"Seconds";
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->textBox4->Location = System::Drawing::Point(86, 58);
			this->textBox4->Margin = System::Windows::Forms::Padding(2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(270, 22);
			this->textBox4->TabIndex = 5;
			// 
			// richTextBox1
			// 
			this->richTextBox1->EnableAutoDragDrop = true;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->richTextBox1->Location = System::Drawing::Point(86, 115);
			this->richTextBox1->Margin = System::Windows::Forms::Padding(2);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(270, 182);
			this->richTextBox1->TabIndex = 8;
			this->richTextBox1->Text = L"";
			// 
			// comboBox1
			// 
			this->comboBox1->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->comboBox1->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(86, 87);
			this->comboBox1->Margin = System::Windows::Forms::Padding(2);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(201, 24);
			this->comboBox1->TabIndex = 6;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->numericUpDown1->Location = System::Drawing::Point(123, 31);
			this->numericUpDown1->Margin = System::Windows::Forms::Padding(2);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 23, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(35, 22);
			this->numericUpDown1->TabIndex = 2;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->numericUpDown2->Location = System::Drawing::Point(220, 31);
			this->numericUpDown2->Margin = System::Windows::Forms::Padding(2);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 59, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(35, 22);
			this->numericUpDown2->TabIndex = 3;
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->numericUpDown3->Location = System::Drawing::Point(321, 31);
			this->numericUpDown3->Margin = System::Windows::Forms::Padding(2);
			this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 59, 0, 0, 0 });
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(35, 22);
			this->numericUpDown3->TabIndex = 4;
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->button3->Location = System::Drawing::Point(291, 87);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(65, 24);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Add new";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &AddItem::button3_Click);
			// 
			// AddItem
			// 
			this->AcceptButton = this->button2;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->button1;
			this->ClientSize = System::Drawing::Size(372, 349);
			this->ControlBox = false;
			this->Controls->Add(this->button3);
			this->Controls->Add(this->numericUpDown3);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"AddItem";
			this->Text = L"AddItem";
			this->Load += gcnew System::EventHandler(this, &AddItem::AddItem_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		//TODO: Pievienot iespēju lietotājam pievienot savas prioritātes, kas balstītos uz ciparu svarīguma
		//1 ir svarīgāks par 2 , kas ir svarīgāks par 3 utt.
		this->Enabled = false;

		ToDoList::Priority priority;
		priority.ShowDialog();



		//Update comboBox
		comboBox1->Items->Clear();

		INIReader reader("settings.ini");
		if (reader.ParseError() < 0) {
			MessageBox::Show("Reader parse error");
		}
		
		std::string location = defPriorityLocation;
		std::ifstream priorityFile(location);


		while (!priorityFile.eof()) {
			std::string buffer;
			std::vector<std::string> items;
			getline(priorityFile, buffer);
			if (buffer == "") { break; }
			items = seperateItems(buffer, "|");
			comboBox1->Items->Add(convertToSystemString(items.at(0)));
		}

		this->Enabled = true;
	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	string date = convertToStdString(this->dateTimePicker1->Text); //Pārveido no (System::String uz std::string
	int hour = (int)this->numericUpDown1->Value;
	int minute = (int)this->numericUpDown2->Value;
	int second = (int)this->numericUpDown3->Value;

	TimeManager time(date, hour, minute, second);

	string name = convertToStdString(this->textBox4->Text);
	string priority = convertToStdString(this->comboBox1->Text);
	string description = convertToStdString(this->richTextBox1->Text);

	//Pābaudes vai viss ir labi
	if (!time.isDateInPast()) {
		MessageBox::Show("The current date is in the past");
	} else if (name == "" || priority == "") {
		MessageBox::Show("Name and/or priority not entered");
	}
	else if (name.find('|') != string::npos) {
		MessageBox::Show("Name contains an illegal character \"|\"");
	}
	else if (!edit) {
		/*

		Pievienot jaunu itemu

		*/

			INIReader reader("settings.ini");
			if (reader.ParseError() < 0) {
				//Error
			}
			std::string fileLocation = reader.Get("USER", "saveLocation", "") + R"(Lists\)" + convertToStdString(currentListFile) + ".txt";
				ofstream file(fileLocation, ios::app | ios::out);
			file << time.getTimeFull() << "|" << name << "|" << priority << "|" << description << endl;
			file.close();
			this->Close();
	}
	else {
		/*

			Rediģēt esošo itemu

		*/

			INIReader reader("settings.ini");
			if (reader.ParseError() < 0) {
				MessageBox::Show("Reader parse error");
			}
			std::string tempFileLocation = defTempFileLocation;
			std::string fileLocation = reader.Get("USER", "saveLocation", "") + R"(Lists\)" + convertToStdString(currentListFile) + ".txt";

			ifstream file(fileLocation);
			ofstream tempFile(tempFileLocation);

			int countIndex = 0;

			while (!file.eof()) {

				std::string buffer;

				getline(file, buffer);
				if (countIndex == index) {
					tempFile << time.getTimeFull() << "|" << name << "|" << priority << "|" << description << endl;
				}
				else {
					tempFile << buffer << endl;
				}
					countIndex++;
			}
			
			tempFile.close();
			file.close();
			remove(fileLocation.c_str());
			rename(tempFileLocation.c_str(), fileLocation.c_str());
			this->Close();
		}
	}
private: System::Void AddItem_Load(System::Object^  sender, System::EventArgs^  e) {
	bool duplicatePriority = false;

	//Update comboBox
	comboBox1->Items->Clear();

	INIReader reader("settings.ini");
	if (reader.ParseError() < 0) {
		MessageBox::Show("Reader parse error");
	}

	std::string location = defPriorityLocation;
	std::ifstream priorityFile(location);

	priorityFile.clear();
	priorityFile.seekg(0, ios::beg);
	while (!priorityFile.eof()) {
		std::string buffer;
		std::vector<std::string> items;
		getline(priorityFile, buffer);
		if (buffer == "") { break; }
		items = seperateItems(buffer, "|");
		comboBox1->Items->Add(convertToSystemString(items.at(0)));

		//Pārbauda lai nebūtu divas vienādas prioritātes
		if (edit && !duplicatePriority) {
			if (convertToSystemString(items.at(0)) == prioritySystem) { duplicatePriority = true; }
		}
	}
	//Pievieno izvēlētas lietas priority ja nav un izvēlas to
	if (edit && !duplicatePriority) {
		comboBox1->Items->Add(prioritySystem);
		comboBox1->SelectedIndex = comboBox1->FindStringExact(prioritySystem);
	}
	else {
		comboBox1->SelectedIndex = comboBox1->FindStringExact(prioritySystem);
	}
}
};
}
