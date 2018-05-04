#pragma once
#include "TimeManager.h"
#include <string>
#include "Functions.h"
#include <fstream>
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
	public:
		AddItem(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
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
			this->button1->Location = System::Drawing::Point(326, 400);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(93, 32);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Cancel";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AddItem::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(235, 400);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(85, 32);
			this->button2->TabIndex = 99;
			this->button2->Text = L"Ok";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AddItem::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(38, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Date";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 75);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Name";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 110);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(52, 17);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Priority";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 145);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(79, 17);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Description";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Cursor = System::Windows::Forms::Cursors::Default;
			this->dateTimePicker1->CustomFormat = L"dd/MM/yyyy";
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker1->Location = System::Drawing::Point(92, 9);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(327, 22);
			this->dateTimePicker1->TabIndex = 1;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 40);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(39, 17);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Time";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(89, 40);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(46, 17);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Hours";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(193, 40);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(57, 17);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Minutes";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(303, 40);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(63, 17);
			this->label8->TabIndex = 13;
			this->label8->Text = L"Seconds";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(92, 72);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(327, 22);
			this->textBox4->TabIndex = 5;
			// 
			// richTextBox1
			// 
			this->richTextBox1->EnableAutoDragDrop = true;
			this->richTextBox1->Location = System::Drawing::Point(92, 142);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(327, 209);
			this->richTextBox1->TabIndex = 8;
			this->richTextBox1->Text = L"";
			// 
			// comboBox1
			// 
			this->comboBox1->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->comboBox1->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Low", L"Medium", L"High" });
			this->comboBox1->Location = System::Drawing::Point(92, 107);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(246, 24);
			this->comboBox1->TabIndex = 6;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(141, 38);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 23, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(47, 22);
			this->numericUpDown1->TabIndex = 2;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(256, 38);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 59, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(47, 22);
			this->numericUpDown2->TabIndex = 3;
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(372, 38);
			this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 59, 0, 0, 0 });
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(47, 22);
			this->numericUpDown3->TabIndex = 4;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(342, 107);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(77, 24);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Add new";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &AddItem::button3_Click);
			// 
			// AddItem
			// 
			this->AcceptButton = this->button2;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->button1;
			this->ClientSize = System::Drawing::Size(433, 444);
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
			this->Name = L"AddItem";
			this->Text = L"AddItem";
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

		ToDoList::Priority addPriority;
		addPriority.ShowDialog();

		this->Enabled = true;
	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	string date = convertToStdString(this->dateTimePicker1->Text); //Pārveido no (System::String uz std::string
	int hour = (int)this->numericUpDown1->Value;
	int minute = (int)this->numericUpDown2->Value;
	int second = (int)this->numericUpDown3->Value;
	
	TimeManager time(date,hour,minute,second);

	string name =convertToStdString(this->textBox4->Text);
	string priority = convertToStdString(this->comboBox1->Text);
	string description = convertToStdString(this->richTextBox1->Text);

	//TODO: Ielikt datuma pārbaudi lai tā nav pagātnē
	if (!time.isDateInPast()) {
		MessageBox::Show("The date entered has passed");
	} else if (name == "" || priority == "") {
		MessageBox::Show("Name and/or priority not entered");
	}
	else if (name.find('|') != string::npos) {
		MessageBox::Show("Name contains an illegal character \"|\"");
	} else {
		INIReader reader("settings.ini");
		if (reader.ParseError() < 0) {
			//Error
		}
		std::string fileLocation = reader.Get("USER", "saveLocation", "list.txt") + "Lists\\list.txt";
		ofstream file(fileLocation, ios::app);
		file << time.getTimeFull() << "|" << name << "|" << priority << "|" << description << endl;
		file.close();
		this->Close();
	}
}
};
}
