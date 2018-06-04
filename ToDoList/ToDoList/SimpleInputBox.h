#pragma once

namespace ToDoList {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SimpleInputBox
	/// </summary>
	public ref class SimpleInputBox : public System::Windows::Forms::Form
	{
	public: String ^ message;
	public: String ^ name;
	public: bool answered = false;
	public: property System::String^ TextBoxValue
	{
		System::String^ get()
		{
			if (answered) {
				return textBox1->Text;
			}
			else {
				return "";
			}
		}
		void set(System::String^ text)
		{
			label1->Text = text;
		}
	}
	public:
		SimpleInputBox(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		SimpleInputBox(String ^ message, String ^ name) {
			InitializeComponent();
			this->name = name;
			this->message = message;
			

		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SimpleInputBox()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(126, 84);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Cancel";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &SimpleInputBox::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(15, 84);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Ok";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &SimpleInputBox::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"label1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(15, 40);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(186, 20);
			this->textBox1->TabIndex = 3;
			// 
			// SimpleInputBox
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(213, 119);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"SimpleInputBox";
			this->Text = L"Please answer!";
			this->Load += gcnew System::EventHandler(this, &SimpleInputBox::SimpleInputBox_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void SimpleInputBox_Load(System::Object^  sender, System::EventArgs^  e) {
		this->Text = name;
		label1->Text = message;
	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	answered = true;
	this->Close();
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
};
}
