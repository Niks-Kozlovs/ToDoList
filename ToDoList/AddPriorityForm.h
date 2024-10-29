#pragma once
#include "Priorities.h"

namespace ToDoApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddPriorityForm
	/// </summary>
	public ref class AddPriorityForm : public System::Windows::Forms::Form
	{
	public:
		AddPriorityForm(void)
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
		~AddPriorityForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ okButton;
	private: System::Windows::Forms::Button^ cancelButton;
	protected:




	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	public:
		Priority^ priority;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::Label^ label1;
			System::Windows::Forms::Label^ label2;
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			label1 = (gcnew System::Windows::Forms::Label());
			label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			label1->AutoSize = true;
			label1->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			label1->Location = System::Drawing::Point(9, 7);
			label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			label1->Name = L"label1";
			label1->Size = System::Drawing::Size(41, 16);
			label1->TabIndex = 2;
			label1->Text = L"Name";
			// 
			// label2
			// 
			label2->AutoSize = true;
			label2->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			label2->Location = System::Drawing::Point(7, 36);
			label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			label2->Name = L"label2";
			label2->Size = System::Drawing::Size(39, 16);
			label2->TabIndex = 3;
			label2->Text = L"Value";
			// 
			// okButton
			// 
			this->okButton->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->okButton->Location = System::Drawing::Point(57, 76);
			this->okButton->Margin = System::Windows::Forms::Padding(2);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(70, 35);
			this->okButton->TabIndex = 3;
			this->okButton->Text = L"Ok";
			this->okButton->UseVisualStyleBackColor = true;
			this->okButton->Click += gcnew System::EventHandler(this, &AddPriorityForm::okButton_Click);
			// 
			// cancelButton
			// 
			this->cancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->cancelButton->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->cancelButton->Location = System::Drawing::Point(131, 76);
			this->cancelButton->Margin = System::Windows::Forms::Padding(2);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(70, 35);
			this->cancelButton->TabIndex = 4;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = true;
			this->cancelButton->Click += gcnew System::EventHandler(this, &AddPriorityForm::cancelButton_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->textBox1->Location = System::Drawing::Point(57, 5);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(144, 22);
			this->textBox1->TabIndex = 1;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->numericUpDown1->Location = System::Drawing::Point(57, 36);
			this->numericUpDown1->Margin = System::Windows::Forms::Padding(2);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2147483647, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(144, 22);
			this->numericUpDown1->TabIndex = 2;
			// 
			// AddPriorityForm
			// 
			this->AcceptButton = this->okButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->cancelButton;
			this->ClientSize = System::Drawing::Size(210, 120);
			this->ControlBox = false;
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(label2);
			this->Controls->Add(label1);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->okButton);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"AddPriorityForm";
			this->Text = L"AddPriorityForm";
			this->Load += gcnew System::EventHandler(this, &AddPriorityForm::AddPriorityForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void okButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void cancelButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void AddPriorityForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
