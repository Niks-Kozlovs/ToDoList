#pragma once
#include"AddItem.h"
#include"Functions.h"
#include<vector>
std::vector <std::vector <std::string>> information;


namespace ToDoList {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^  listView1;
	protected:
	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader2;
	private: System::Windows::Forms::ColumnHeader^  columnHeader3;
	private: System::Windows::Forms::ColumnHeader^  columnHeader4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  settingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  changeFontToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  changeSaveLocationToolStripMenuItem;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
	private: System::Windows::Forms::ToolStripComboBox^  toolStripComboBox1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader5;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::ToolStripMenuItem^  changeUpdateRateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripTextBox^  toolStripTextBox1;
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
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->changeFontToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripComboBox1 = (gcnew System::Windows::Forms::ToolStripComboBox());
			this->changeSaveLocationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->changeUpdateRateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripTextBox1 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
				this->columnHeader1, this->columnHeader2,
					this->columnHeader3, this->columnHeader4, this->columnHeader5
			});
			this->listView1->FullRowSelect = true;
			this->listView1->Location = System::Drawing::Point(12, 31);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(702, 612);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			this->listView1->ColumnClick += gcnew System::Windows::Forms::ColumnClickEventHandler(this, &Form1::listView1_ColumnClick);
			this->listView1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listView1_SelectedIndexChanged);
			this->listView1->Enter += gcnew System::EventHandler(this, &Form1::listView1_Enter);
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Date";
			this->columnHeader1->Width = 123;
			// 
			// columnHeader2
			// 
			this->columnHeader2->DisplayIndex = 2;
			this->columnHeader2->Text = L"Name";
			this->columnHeader2->Width = 129;
			// 
			// columnHeader3
			// 
			this->columnHeader3->DisplayIndex = 3;
			this->columnHeader3->Text = L"Priority";
			this->columnHeader3->Width = 98;
			// 
			// columnHeader4
			// 
			this->columnHeader4->DisplayIndex = 4;
			this->columnHeader4->Text = L"Description";
			this->columnHeader4->Width = 170;
			// 
			// columnHeader5
			// 
			this->columnHeader5->DisplayIndex = 1;
			this->columnHeader5->Text = L"Time left";
			this->columnHeader5->Width = 75;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Pixel));
			this->button1->Location = System::Drawing::Point(767, 49);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(200, 200);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Add new item";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(974, 49);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(200, 200);
			this->button2->TabIndex = 2;
			this->button2->Text = L"More info";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(767, 255);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(134, 59);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Delete item";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->settingsToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1226, 28);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->exitToolStripMenuItem });
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(44, 24);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::F4));
			this->exitToolStripMenuItem->Size = System::Drawing::Size(161, 26);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->changeFontToolStripMenuItem,
					this->changeSaveLocationToolStripMenuItem, this->changeUpdateRateToolStripMenuItem
			});
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(74, 24);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// changeFontToolStripMenuItem
			// 
			this->changeFontToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripComboBox1 });
			this->changeFontToolStripMenuItem->Name = L"changeFontToolStripMenuItem";
			this->changeFontToolStripMenuItem->Size = System::Drawing::Size(225, 26);
			this->changeFontToolStripMenuItem->Text = L"Change font";
			// 
			// toolStripComboBox1
			// 
			this->toolStripComboBox1->Name = L"toolStripComboBox1";
			this->toolStripComboBox1->Size = System::Drawing::Size(121, 28);
			this->toolStripComboBox1->Enter += gcnew System::EventHandler(this, &Form1::toolStripComboBox1_Enter);
			// 
			// changeSaveLocationToolStripMenuItem
			// 
			this->changeSaveLocationToolStripMenuItem->Name = L"changeSaveLocationToolStripMenuItem";
			this->changeSaveLocationToolStripMenuItem->Size = System::Drawing::Size(225, 26);
			this->changeSaveLocationToolStripMenuItem->Text = L"Change save location";
			this->changeSaveLocationToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::changeSaveLocationToolStripMenuItem_Click);
			// 
			// changeUpdateRateToolStripMenuItem
			// 
			this->changeUpdateRateToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripTextBox1 });
			this->changeUpdateRateToolStripMenuItem->Name = L"changeUpdateRateToolStripMenuItem";
			this->changeUpdateRateToolStripMenuItem->Size = System::Drawing::Size(225, 26);
			this->changeUpdateRateToolStripMenuItem->Text = L"Change update rate";
			// 
			// toolStripTextBox1
			// 
			this->toolStripTextBox1->Name = L"toolStripTextBox1";
			this->toolStripTextBox1->Size = System::Drawing::Size(100, 27);
			// 
			// folderBrowserDialog1
			// 
			this->folderBrowserDialog1->SelectedPath = L"C:\\Users\\sloppynick3\\Documents\\To do list";
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AcceptButton = this->button1;
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1226, 677);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"To Do List";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		//Atslēdz, lai lietotājs nevar neko darīt kamēr pievieno jaunu informāciju
		this->Enabled = false;
		//Izveido un parāda jaunu form priekš informācijas ievades
		//Tā izskatīsies labāk nekā piepildīt galveno form ar dažādiem text boxiem
		ToDoList::AddItem addItemForm;
		addItemForm.ShowDialog();
		//Pēc form aizstaisīšanas galvenais form atkal tiek ieslēgts
		this->Enabled = true;

		//Pārnes saņemto informāciju (ja tāda ir) uz listview.
		//Iztīra visu no listview, lai tas neatkārtotos divas reizes
		std::vector<std::string> list;
		std::string buffer;
		INIReader reader("settings.ini");
		if (reader.ParseError() < 0) {
			MessageBox::Show("Reader parse error");
		}
		std::string fileLocation = reader.Get("USER", "saveLocation", "list.txt") + "Lists\\list.txt";
		MessageBox::Show(convertToSystemString(fileLocation));
		ifstream file(fileLocation);
		int i = 0;

		information.clear();
		while (!file.eof()) {
			getline(file, buffer);
			if (buffer == "") { break; }
			std::vector<std::string> text;
			text = seperateItems(buffer, "|");
			information.push_back(text);
			i++;
		}
		file.close();

		updateListView(listView1, information);
		for (int i = 0; i < listView1->Items->Count; i++) {
			TimeManager date(convertToStdString(listView1->Items[i]->SubItems[0]->Text));
			listView1->Items[i]->SubItems->Add(convertToSystemString(date.getTimeDifference()));
		}
	}
private: System::Void listView1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	if (this->listView1->SelectedItems->Count == 1) {
		button2->Enabled = true; //More info poga varēs tikai parādīt informāciju par vienu lietu
		button3->Enabled = true;
	}
	else if (this->listView1->SelectedItems->Count > 1) {
		//button3->Enabled = true;
		//button2->Enabled = false;

	} else {
		button2->Enabled = false;
		button3->Enabled = false;
	}
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	//TODO: Make a form for more info and display it there from the list
}
private: System::Void listView1_Enter(System::Object^  sender, System::EventArgs^  e) {
	timer1->Start();
	information.clear();
	std::vector<std::string> list;
	std::string buffer;
	INIReader reader("settings.ini");
	if (reader.ParseError() < 0) {
		MessageBox::Show("Reader parse error");
	}
	std::string fileLocation = reader.Get("USER", "saveLocation", "list.txt") + "Lists\\list.txt";
	ifstream file(fileLocation);
	int i = 0;

	while (!file.eof()) {
		getline(file, buffer);
		if (buffer == "") { break; }
		std::vector<std::string> text;
		text = seperateItems(buffer, "|");
		information.push_back(text);
		i++;
	}
	file.close();

	updateListView(listView1, information);
	for (int i = 0; i < listView1->Items->Count; i++) {
		TimeManager date1(convertToStdString(listView1->Items[i]->SubItems[0]->Text));
		listView1->Items[i]->SubItems->Add(convertToSystemString(date1.getTimeDifference()));
	}
}
private: System::Void listView1_ColumnClick(System::Object^  sender, System::Windows::Forms::ColumnClickEventArgs^  e) {
	MessageBox::Show(e->Column.ToString()); //Tells which column was clicked
	MessageBox::Show(this->listView1->FocusedItem->Index.ToString());
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	//Dzes ara no saraksta
	int index = this->listView1->FocusedItem->Index;
	listView1->SelectedItems[0]->Remove();

	//Vector update
	information.erase(information.begin() + index);


	//File update
	INIReader reader("settings.ini");
	if (reader.ParseError() < 0) {
		//Error
	}
	std::string fileLocation = reader.Get("USER", "saveLocation", "list.txt") + "Lists\\list.txt";
	ofstream file(fileLocation);

	for (size_t i = 0; i < information.size(); i++) {
		for (size_t j = 0; j < information.at(i).size() - 1; j++) {
			file << information.at(i).at(j) << "|";
		}
		file << information.at(i).at(information.at(i).size()-1) << endl;
	}
	information.clear();
}
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	exit(0);
}
private: System::Void changeSaveLocationToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (folderBrowserDialog1->ShowDialog().ToString() == "OK") {
		createIniFile(convertToStdString(folderBrowserDialog1->SelectedPath));
		MessageBox::Show("The program will now close for the changes to take effect");
		exit(0);
	}
}
private: System::Void toolStripComboBox1_Enter(System::Object^  sender, System::EventArgs^  e) {
	//Show list of fonts
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	for (int i = 0; i < listView1->Items->Count; i++) {
		TimeManager date(convertToStdString(listView1->Items[i]->SubItems[0]->Text));
		listView1->Items[i]->SubItems[4]->Text=convertToSystemString(date.getTimeDifference());
		if (listView1->Items[i]->SubItems[4]->Text == "Time has passed") { //Ja laiks ir pagajis, tad true
			//Make item red
		}
	}
}
};
}