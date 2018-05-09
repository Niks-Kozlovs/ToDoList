#pragma once
#define defPriorityLocation reader.Get("USER", "saveLocation", "priority.txt") + "Other\\priority.txt";
//#include "stdafx.h"
#include <string>
#include <fstream>
#include "Functions.h"
#include "INIReader.h"

namespace ToDoList {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Priority
	/// </summary>
	public ref class Priority : public System::Windows::Forms::Form
	{
	public:
		Priority(void)
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
		~Priority()
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
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(165, 99);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(79, 37);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Ok";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Priority::button1_Click);
			// 
			// button2
			// 
			this->button2->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button2->Location = System::Drawing::Point(12, 99);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(79, 37);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Priority::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(45, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Name";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 44);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Value";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(76, 6);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(168, 22);
			this->textBox1->TabIndex = 1;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(76, 44);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2147483647, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(168, 22);
			this->numericUpDown1->TabIndex = 2;
			// 
			// Priority
			// 
			this->AcceptButton = this->button1;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->button2;
			this->ClientSize = System::Drawing::Size(256, 161);
			this->ControlBox = false;
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Priority";
			this->Text = L"Priority";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) { //Ok clicked
		std::string name = convertToStdString(textBox1->Text);
		int value = (int)numericUpDown1->Value;
		std::string strValue = std::to_string(value);

		INIReader reader("settings.ini");
		if (reader.ParseError() < 0) {
			MessageBox::Show("Reader parse error");
		}
		std::string priorityLocation = defPriorityLocation;

		if (checkIfDuplicate(priorityLocation, 0, name)) {
			MessageBox::Show("This name is taken");
		}
		else {
			std::ofstream priority(priorityLocation, std::ios::app);

			priority << name << "|" << value << std::endl;

			priority.close();
			this->Close();
		}

	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
};
}
