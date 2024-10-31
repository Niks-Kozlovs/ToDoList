#pragma once
#include "../Model/ToDoListItem.h"

namespace ToDoApp {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MoreInfo
	/// </summary>
	public ref class MoreInfo : public System::Windows::Forms::Form
	{
	public:
		MoreInfo(void)
		{
			InitializeComponent();
			MessageBox::Show("Error! No variables passed for this form!");
		}
		MoreInfo(ToDoListItem^ item)
		{
			InitializeComponent();
			this->item = item;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MoreInfo()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::RichTextBox^ itemDescription;
	private: System::Windows::Forms::Label^ itemName;
	private: System::Windows::Forms::Label^ itemDate;
	private: System::Windows::Forms::Label^ itemPriority;
	private: System::Windows::Forms::Button^ okButton;
	private: System::ComponentModel::Container^ components;
	public:	ToDoListItem^ item;

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
			System::Windows::Forms::Label^ label1;
			System::Windows::Forms::Label^ label2;
			System::Windows::Forms::Label^ label3;
			System::Windows::Forms::Label^ label4;
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MoreInfo::typeid));
			this->itemDescription = (gcnew System::Windows::Forms::RichTextBox());
			this->itemName = (gcnew System::Windows::Forms::Label());
			this->itemDate = (gcnew System::Windows::Forms::Label());
			this->itemPriority = (gcnew System::Windows::Forms::Label());
			this->okButton = (gcnew System::Windows::Forms::Button());
			label1 = (gcnew System::Windows::Forms::Label());
			label2 = (gcnew System::Windows::Forms::Label());
			label3 = (gcnew System::Windows::Forms::Label());
			label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			label1->AutoSize = true;
			label1->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			label1->Location = System::Drawing::Point(4, 13);
			label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			label1->Name = L"label1";
			label1->Size = System::Drawing::Size(45, 16);
			label1->TabIndex = 0;
			label1->Text = L"Name:";
			// 
			// label2
			// 
			label2->AutoSize = true;
			label2->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			label2->Location = System::Drawing::Point(4, 43);
			label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			label2->Name = L"label2";
			label2->Size = System::Drawing::Size(38, 16);
			label2->TabIndex = 1;
			label2->Text = L"Date:";
			// 
			// label3
			// 
			label3->AutoSize = true;
			label3->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			label3->Location = System::Drawing::Point(4, 74);
			label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			label3->Name = L"label3";
			label3->Size = System::Drawing::Size(52, 16);
			label3->TabIndex = 2;
			label3->Text = L"Priority:";
			// 
			// label4
			// 
			label4->AutoSize = true;
			label4->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			label4->Location = System::Drawing::Point(4, 105);
			label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			label4->Name = L"label4";
			label4->Size = System::Drawing::Size(76, 16);
			label4->TabIndex = 3;
			label4->Text = L"Description:";
			// 
			// itemDescription
			// 
			this->itemDescription->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->itemDescription->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->itemDescription->EnableAutoDragDrop = true;
			this->itemDescription->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->itemDescription->Location = System::Drawing::Point(85, 105);
			this->itemDescription->Margin = System::Windows::Forms::Padding(2);
			this->itemDescription->Name = L"itemDescription";
			this->itemDescription->ReadOnly = true;
			this->itemDescription->Size = System::Drawing::Size(246, 171);
			this->itemDescription->TabIndex = 4;
			this->itemDescription->Text = L"";
			// 
			// itemName
			// 
			this->itemName->AutoSize = true;
			this->itemName->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->itemName->Location = System::Drawing::Point(82, 13);
			this->itemName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->itemName->Name = L"itemName";
			this->itemName->Size = System::Drawing::Size(0, 16);
			this->itemName->TabIndex = 1;
			// 
			// itemDate
			// 
			this->itemDate->AutoSize = true;
			this->itemDate->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->itemDate->Location = System::Drawing::Point(82, 43);
			this->itemDate->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->itemDate->Name = L"itemDate";
			this->itemDate->Size = System::Drawing::Size(0, 16);
			this->itemDate->TabIndex = 2;
			// 
			// itemPriority
			// 
			this->itemPriority->AutoSize = true;
			this->itemPriority->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->itemPriority->Location = System::Drawing::Point(82, 74);
			this->itemPriority->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->itemPriority->Name = L"itemPriority";
			this->itemPriority->Size = System::Drawing::Size(0, 16);
			this->itemPriority->TabIndex = 3;
			// 
			// okButton
			// 
			this->okButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->okButton->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->okButton->Location = System::Drawing::Point(281, 287);
			this->okButton->Margin = System::Windows::Forms::Padding(2);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(70, 35);
			this->okButton->TabIndex = 5;
			this->okButton->Text = L"Ok";
			this->okButton->UseVisualStyleBackColor = true;
			this->okButton->Click += gcnew System::EventHandler(this, &MoreInfo::okButton_Click);
			// 
			// MoreInfo
			// 
			this->AcceptButton = this->okButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->okButton;
			this->ClientSize = System::Drawing::Size(362, 333);
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->itemPriority);
			this->Controls->Add(this->itemDate);
			this->Controls->Add(this->itemName);
			this->Controls->Add(this->itemDescription);
			this->Controls->Add(label4);
			this->Controls->Add(label3);
			this->Controls->Add(label2);
			this->Controls->Add(label1);
			this->Icon = gcnew System::Drawing::Icon(L"Resources/Logo.ico");
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MoreInfo";
			this->Text = L"MoreInfo";
			this->Load += gcnew System::EventHandler(this, &MoreInfo::MoreInfo_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MoreInfo_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void okButton_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
