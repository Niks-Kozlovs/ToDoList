#pragma once
#include "ToDoListItem.h"
#include "Priorities.h"

namespace ToDoApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddItem
	/// </summary>
	public ref class AddItemForm : public System::Windows::Forms::Form
	{
	public:
		AddItemForm()
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		AddItemForm(ToDoListItem^ item)
		{
			InitializeComponent();
			this->item = item;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddItemForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ cancel;
	private: System::Windows::Forms::Button^ okButton;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::RichTextBox^ descriptionInput;
	private: System::Windows::Forms::ComboBox^ prioritiesList;
	private: System::Windows::Forms::NumericUpDown^ hourInput;
	private: System::Windows::Forms::NumericUpDown^ minuteInput;
	private: System::Windows::Forms::Button^ addPriority;
	private: System::Windows::Forms::DateTimePicker^ datePicker;
	private: System::ComponentModel::IContainer^ components;
	private: Priorities^ priorities;
	public: ToDoListItem^ item;

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
			System::Windows::Forms::Label^ label5;
			System::Windows::Forms::Label^ label6;
			System::Windows::Forms::Label^ label7;
			this->cancel = (gcnew System::Windows::Forms::Button());
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->descriptionInput = (gcnew System::Windows::Forms::RichTextBox());
			this->prioritiesList = (gcnew System::Windows::Forms::ComboBox());
			this->hourInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->minuteInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->addPriority = (gcnew System::Windows::Forms::Button());
			this->datePicker = (gcnew System::Windows::Forms::DateTimePicker());
			label1 = (gcnew System::Windows::Forms::Label());
			label2 = (gcnew System::Windows::Forms::Label());
			label3 = (gcnew System::Windows::Forms::Label());
			label4 = (gcnew System::Windows::Forms::Label());
			label5 = (gcnew System::Windows::Forms::Label());
			label6 = (gcnew System::Windows::Forms::Label());
			label7 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hourInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->minuteInput))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			label1->AutoSize = true;
			label1->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			label1->Location = System::Drawing::Point(9, 12);
			label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			label1->Name = L"label1";
			label1->Size = System::Drawing::Size(34, 16);
			label1->TabIndex = 2;
			label1->Text = L"Date";
			// 
			// label2
			// 
			label2->AutoSize = true;
			label2->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			label2->Location = System::Drawing::Point(9, 65);
			label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			label2->Name = L"label2";
			label2->Size = System::Drawing::Size(41, 16);
			label2->TabIndex = 3;
			label2->Text = L"Name";
			// 
			// label3
			// 
			label3->AutoSize = true;
			label3->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			label3->Location = System::Drawing::Point(9, 93);
			label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			label3->Name = L"label3";
			label3->Size = System::Drawing::Size(48, 16);
			label3->TabIndex = 4;
			label3->Text = L"Priority";
			// 
			// label4
			// 
			label4->AutoSize = true;
			label4->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			label4->Location = System::Drawing::Point(9, 121);
			label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			label4->Name = L"label4";
			label4->Size = System::Drawing::Size(72, 16);
			label4->TabIndex = 5;
			label4->Text = L"Description";
			// 
			// label5
			// 
			label5->AutoSize = true;
			label5->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			label5->Location = System::Drawing::Point(9, 36);
			label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			label5->Name = L"label5";
			label5->Size = System::Drawing::Size(35, 16);
			label5->TabIndex = 8;
			label5->Text = L"Time";
			// 
			// label6
			// 
			label6->AutoSize = true;
			label6->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			label6->Location = System::Drawing::Point(83, 36);
			label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			label6->Name = L"label6";
			label6->Size = System::Drawing::Size(41, 16);
			label6->TabIndex = 10;
			label6->Text = L"Hours";
			// 
			// label7
			// 
			label7->AutoSize = true;
			label7->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			label7->Location = System::Drawing::Point(176, 36);
			label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			label7->Name = L"label7";
			label7->Size = System::Drawing::Size(53, 16);
			label7->TabIndex = 11;
			label7->Text = L"Minutes";
			// 
			// cancel
			// 
			this->cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->cancel->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->cancel->Location = System::Drawing::Point(286, 304);
			this->cancel->Margin = System::Windows::Forms::Padding(2);
			this->cancel->Name = L"cancel";
			this->cancel->Size = System::Drawing::Size(70, 35);
			this->cancel->TabIndex = 10;
			this->cancel->Text = L"Cancel";
			this->cancel->UseVisualStyleBackColor = true;
			this->cancel->Click += gcnew System::EventHandler(this, &AddItemForm::cancel_Click);
			// 
			// okButton
			// 
			this->okButton->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->okButton->Location = System::Drawing::Point(212, 304);
			this->okButton->Margin = System::Windows::Forms::Padding(2);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(70, 35);
			this->okButton->TabIndex = 9;
			this->okButton->Text = L"Ok";
			this->okButton->UseVisualStyleBackColor = true;
			this->okButton->Click += gcnew System::EventHandler(this, &AddItemForm::okButton_Click);
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->textBox4->Location = System::Drawing::Point(86, 62);
			this->textBox4->Margin = System::Windows::Forms::Padding(2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(270, 22);
			this->textBox4->TabIndex = 5;
			// 
			// descriptionInput
			// 
			this->descriptionInput->EnableAutoDragDrop = true;
			this->descriptionInput->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->descriptionInput->Location = System::Drawing::Point(86, 118);
			this->descriptionInput->Margin = System::Windows::Forms::Padding(2);
			this->descriptionInput->Name = L"descriptionInput";
			this->descriptionInput->Size = System::Drawing::Size(270, 182);
			this->descriptionInput->TabIndex = 8;
			this->descriptionInput->Text = L"";
			// 
			// prioritiesList
			// 
			this->prioritiesList->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->prioritiesList->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->prioritiesList->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->prioritiesList->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->prioritiesList->FormattingEnabled = true;
			this->prioritiesList->Location = System::Drawing::Point(86, 89);
			this->prioritiesList->Margin = System::Windows::Forms::Padding(2);
			this->prioritiesList->Name = L"prioritiesList";
			this->prioritiesList->Size = System::Drawing::Size(201, 24);
			this->prioritiesList->TabIndex = 6;
			// 
			// hourInput
			// 
			this->hourInput->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->hourInput->Location = System::Drawing::Point(128, 34);
			this->hourInput->Margin = System::Windows::Forms::Padding(2);
			this->hourInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 23, 0, 0, 0 });
			this->hourInput->Name = L"hourInput";
			this->hourInput->Size = System::Drawing::Size(41, 22);
			this->hourInput->TabIndex = 2;
			// 
			// minuteInput
			// 
			this->minuteInput->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->minuteInput->Location = System::Drawing::Point(233, 34);
			this->minuteInput->Margin = System::Windows::Forms::Padding(2);
			this->minuteInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 59, 0, 0, 0 });
			this->minuteInput->Name = L"minuteInput";
			this->minuteInput->Size = System::Drawing::Size(41, 22);
			this->minuteInput->TabIndex = 3;
			// 
			// addPriority
			// 
			this->addPriority->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->addPriority->Location = System::Drawing::Point(291, 89);
			this->addPriority->Margin = System::Windows::Forms::Padding(2);
			this->addPriority->Name = L"addPriority";
			this->addPriority->Size = System::Drawing::Size(65, 24);
			this->addPriority->TabIndex = 7;
			this->addPriority->Text = L"Add new";
			this->addPriority->UseVisualStyleBackColor = true;
			this->addPriority->Click += gcnew System::EventHandler(this, &AddItemForm::addPriority_Click);
			// 
			// datePicker
			// 
			this->datePicker->Cursor = System::Windows::Forms::Cursors::Default;
			this->datePicker->CustomFormat = L"dd/MM/yyyy";
			this->datePicker->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->datePicker->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->datePicker->Location = System::Drawing::Point(86, 7);
			this->datePicker->Margin = System::Windows::Forms::Padding(2);
			this->datePicker->Name = L"datePicker";
			this->datePicker->Size = System::Drawing::Size(270, 22);
			this->datePicker->TabIndex = 1;
			// 
			// AddItemForm
			// 
			this->AcceptButton = this->okButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->cancel;
			this->ClientSize = System::Drawing::Size(372, 349);
			this->ControlBox = false;
			this->Controls->Add(this->addPriority);
			this->Controls->Add(this->minuteInput);
			this->Controls->Add(this->hourInput);
			this->Controls->Add(this->prioritiesList);
			this->Controls->Add(this->descriptionInput);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(label7);
			this->Controls->Add(label6);
			this->Controls->Add(label5);
			this->Controls->Add(this->datePicker);
			this->Controls->Add(label4);
			this->Controls->Add(label3);
			this->Controls->Add(label2);
			this->Controls->Add(label1);
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->cancel);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"AddItemForm";
			this->Text = L"AddItemForm";
			this->Load += gcnew System::EventHandler(this, &AddItemForm::AddItem_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hourInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->minuteInput))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void cancel_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void addPriority_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void okButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AddItem_Load(System::Object^ sender, System::EventArgs^ e);
	};
}
