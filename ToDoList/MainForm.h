#pragma once
#include "ToDoList.h"
namespace ToDoApp {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ buttonAddItem;
	private: System::Windows::Forms::Button^ moreInfoButton;
	private: System::Windows::Forms::Button^ deleteButton;
	private: System::Windows::Forms::Button^ editButton;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ changeSaveLocationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ addNewListToolStripMenuItem;
	private: System::Windows::Forms::ComboBox^ listSelector;
	private: System::Windows::Forms::TextBox^ filterInput;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::ListView^ toDoListView;
	private: ToDoList^ toDoList;
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
			System::Windows::Forms::Label^ label4;
			System::Windows::Forms::Label^ label3;
			System::Windows::Forms::GroupBox^ groupBox2;
			System::Windows::Forms::MenuStrip^ menuStrip1;
			System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
			System::Windows::Forms::ToolStripMenuItem^ settingsToolStripMenuItem;
			System::Windows::Forms::ToolStripMenuItem^ listsToolStripMenuItem;
			System::Windows::Forms::ColumnHeader^ columnHeader1;
			System::Windows::Forms::ColumnHeader^ columnHeader2;
			System::Windows::Forms::ColumnHeader^ columnHeader3;
			System::Windows::Forms::ColumnHeader^ columnHeader4;
			System::Windows::Forms::ColumnHeader^ columnHeader5;
			this->editButton = (gcnew System::Windows::Forms::Button());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			this->moreInfoButton = (gcnew System::Windows::Forms::Button());
			this->buttonAddItem = (gcnew System::Windows::Forms::Button());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->changeSaveLocationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addNewListToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toDoListView = (gcnew System::Windows::Forms::ListView());
			this->filterInput = (gcnew System::Windows::Forms::TextBox());
			this->listSelector = (gcnew System::Windows::Forms::ComboBox());
			label4 = (gcnew System::Windows::Forms::Label());
			label3 = (gcnew System::Windows::Forms::Label());
			groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			listsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
			groupBox2->SuspendLayout();
			menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label4
			// 
			label4->AutoSize = true;
			label4->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			label4->Location = System::Drawing::Point(587, 253);
			label4->Name = L"label4";
			label4->Size = System::Drawing::Size(32, 16);
			label4->TabIndex = 13;
			label4->Text = L"List:";
			// 
			// label3
			// 
			label3->AutoSize = true;
			label3->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			label3->Location = System::Drawing::Point(587, 199);
			label3->Name = L"label3";
			label3->Size = System::Drawing::Size(36, 16);
			label3->TabIndex = 8;
			label3->Text = L"Filter";
			// 
			// groupBox2
			// 
			groupBox2->Controls->Add(this->editButton);
			groupBox2->Controls->Add(this->deleteButton);
			groupBox2->Controls->Add(this->moreInfoButton);
			groupBox2->Controls->Add(this->buttonAddItem);
			groupBox2->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			groupBox2->Location = System::Drawing::Point(581, 34);
			groupBox2->Name = L"groupBox2";
			groupBox2->Size = System::Drawing::Size(260, 150);
			groupBox2->TabIndex = 15;
			groupBox2->TabStop = false;
			groupBox2->Text = L"Main controls";
			// 
			// editButton
			// 
			this->editButton->Enabled = false;
			this->editButton->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->editButton->Location = System::Drawing::Point(9, 82);
			this->editButton->Margin = System::Windows::Forms::Padding(2);
			this->editButton->Name = L"editButton";
			this->editButton->Size = System::Drawing::Size(120, 60);
			this->editButton->TabIndex = 3;
			this->editButton->Text = L"Edit";
			this->editButton->UseVisualStyleBackColor = true;
			this->editButton->Click += gcnew System::EventHandler(this, &MainForm::editButton_Click);
			// 
			// deleteButton
			// 
			this->deleteButton->Enabled = false;
			this->deleteButton->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->deleteButton->Location = System::Drawing::Point(133, 83);
			this->deleteButton->Margin = System::Windows::Forms::Padding(2);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(120, 60);
			this->deleteButton->TabIndex = 4;
			this->deleteButton->Text = L"Delete item";
			this->deleteButton->UseVisualStyleBackColor = true;
			this->deleteButton->Click += gcnew System::EventHandler(this, &MainForm::deleteButton_Click);
			// 
			// moreInfoButton
			// 
			this->moreInfoButton->Enabled = false;
			this->moreInfoButton->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->moreInfoButton->Location = System::Drawing::Point(133, 19);
			this->moreInfoButton->Margin = System::Windows::Forms::Padding(2);
			this->moreInfoButton->Name = L"moreInfoButton";
			this->moreInfoButton->Size = System::Drawing::Size(120, 60);
			this->moreInfoButton->TabIndex = 2;
			this->moreInfoButton->Text = L"More info";
			this->moreInfoButton->UseVisualStyleBackColor = true;
			this->moreInfoButton->Click += gcnew System::EventHandler(this, &MainForm::moreInfoButton_Click);
			// 
			// buttonAddItem
			// 
			this->buttonAddItem->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonAddItem->Location = System::Drawing::Point(9, 18);
			this->buttonAddItem->Margin = System::Windows::Forms::Padding(2);
			this->buttonAddItem->Name = L"buttonAddItem";
			this->buttonAddItem->Size = System::Drawing::Size(120, 60);
			this->buttonAddItem->TabIndex = 1;
			this->buttonAddItem->Text = L"Add new item";
			this->buttonAddItem->UseVisualStyleBackColor = true;
			this->buttonAddItem->Click += gcnew System::EventHandler(this, &MainForm::buttonAddItem_Click);
			// 
			// menuStrip1
			// 
			menuStrip1->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				fileToolStripMenuItem, settingsToolStripMenuItem,
					listsToolStripMenuItem
			});
			menuStrip1->Location = System::Drawing::Point(0, 0);
			menuStrip1->Name = L"menuStrip1";
			menuStrip1->Padding = System::Windows::Forms::Padding(5, 2, 0, 2);
			menuStrip1->Size = System::Drawing::Size(981, 24);
			menuStrip1->TabIndex = 4;
			menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			fileToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->exitToolStripMenuItem });
			fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			fileToolStripMenuItem->Size = System::Drawing::Size(40, 20);
			fileToolStripMenuItem->Text = L"File";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::F4));
			this->exitToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::exitToolStripMenuItem_Click);
			// 
			// settingsToolStripMenuItem
			// 
			settingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->changeSaveLocationToolStripMenuItem });
			settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			settingsToolStripMenuItem->Size = System::Drawing::Size(67, 20);
			settingsToolStripMenuItem->Text = L"Settings";
			// 
			// changeSaveLocationToolStripMenuItem
			// 
			this->changeSaveLocationToolStripMenuItem->Name = L"changeSaveLocationToolStripMenuItem";
			this->changeSaveLocationToolStripMenuItem->Size = System::Drawing::Size(197, 22);
			this->changeSaveLocationToolStripMenuItem->Text = L"Change save location";
			this->changeSaveLocationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::changeSaveLocationToolStripMenuItem_Click);
			// 
			// listsToolStripMenuItem
			// 
			listsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->addNewListToolStripMenuItem });
			listsToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			listsToolStripMenuItem->Name = L"listsToolStripMenuItem";
			listsToolStripMenuItem->Size = System::Drawing::Size(47, 20);
			listsToolStripMenuItem->Text = L"Lists";
			// 
			// addNewListToolStripMenuItem
			// 
			this->addNewListToolStripMenuItem->Name = L"addNewListToolStripMenuItem";
			this->addNewListToolStripMenuItem->Size = System::Drawing::Size(145, 22);
			this->addNewListToolStripMenuItem->Text = L"Add new list";
			this->addNewListToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::addNewListToolStripMenuItem_Click);
			// 
			// toDoListView
			// 
			this->toDoListView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
				columnHeader1, columnHeader2,
					columnHeader3, columnHeader4, columnHeader5
			});
			this->toDoListView->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->toDoListView->FullRowSelect = true;
			this->toDoListView->HideSelection = false;
			this->toDoListView->Location = System::Drawing::Point(10, 25);
			this->toDoListView->Margin = System::Windows::Forms::Padding(2);
			this->toDoListView->Name = L"toDoListView";
			this->toDoListView->Size = System::Drawing::Size(562, 490);
			this->toDoListView->TabIndex = 9;
			this->toDoListView->UseCompatibleStateImageBehavior = false;
			this->toDoListView->View = System::Windows::Forms::View::Details;
			this->toDoListView->ColumnClick += gcnew System::Windows::Forms::ColumnClickEventHandler(this, &MainForm::listView1_ColumnClick);
			this->toDoListView->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::listView1_SelectedIndexChanged);
			this->toDoListView->Enter += gcnew System::EventHandler(this, &MainForm::listView1_Enter);
			// 
			// columnHeader1
			// 
			columnHeader1->Text = L"Date";
			columnHeader1->Width = 123;
			// 
			// columnHeader2
			// 
			columnHeader2->DisplayIndex = 2;
			columnHeader2->Text = L"Name";
			columnHeader2->Width = 129;
			// 
			// columnHeader3
			// 
			columnHeader3->DisplayIndex = 3;
			columnHeader3->Text = L"Priority";
			columnHeader3->Width = 98;
			// 
			// columnHeader4
			// 
			columnHeader4->DisplayIndex = 4;
			columnHeader4->Text = L"Description";
			columnHeader4->Width = 170;
			// 
			// columnHeader5
			// 
			columnHeader5->DisplayIndex = 1;
			columnHeader5->Text = L"Time left";
			columnHeader5->Width = 75;
			// 
			// filterInput
			// 
			this->filterInput->AcceptsReturn = true;
			this->filterInput->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->filterInput->Location = System::Drawing::Point(590, 216);
			this->filterInput->Name = L"filterInput";
			this->filterInput->Size = System::Drawing::Size(160, 22);
			this->filterInput->TabIndex = 6;
			this->filterInput->TextChanged += gcnew System::EventHandler(this, &MainForm::filterInput_TextChanged);
			// 
			// listSelector
			// 
			this->listSelector->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->listSelector->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->listSelector->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->listSelector->FormattingEnabled = true;
			this->listSelector->Location = System::Drawing::Point(590, 269);
			this->listSelector->Name = L"listSelector";
			this->listSelector->Size = System::Drawing::Size(121, 24);
			this->listSelector->Sorted = true;
			this->listSelector->TabIndex = 8;
			this->listSelector->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::listSelector_SelectedIndexChanged);
			// 
			// MainForm
			// 
			this->AcceptButton = this->buttonAddItem;
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(981, 542);
			this->Controls->Add(this->filterInput);
			this->Controls->Add(label3);
			this->Controls->Add(groupBox2);
			this->Controls->Add(label4);
			this->Controls->Add(this->listSelector);
			this->Controls->Add(this->toDoListView);
			this->Controls->Add(menuStrip1);
			this->MainMenuStrip = menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MainForm";
			this->Text = L"To Do List";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainForm::MainForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			groupBox2->ResumeLayout(false);
			menuStrip1->ResumeLayout(false);
			menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void buttonAddItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void moreInfoButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void listView1_Enter(System::Object^ sender, System::EventArgs^ e);
		System::Void listView1_ColumnClick(System::Object^ sender, System::Windows::Forms::ColumnClickEventArgs^ e);
		System::Void deleteButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void changeSaveLocationToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e);
		System::Void editButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void button5_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void filterInput_TextChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void addNewListToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e);
		void LoadList(System::String^ listName, System::String^ location);
		void populateListView();
		void handleFirstTimeLaunch(System::String^& location, System::String^& listName);
		System::Void MainForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
		System::Void listSelector_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	};
};
