#pragma once

namespace ToDoApp {

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
	public: String^ answer;
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
	private: System::Windows::Forms::Button^ cancelButton;
	protected:

	private: System::Windows::Forms::Button^ okButton;
	protected:

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
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// cancelButton
			// 
			this->cancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->cancelButton->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->cancelButton->Location = System::Drawing::Point(128, 59);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(70, 35);
			this->cancelButton->TabIndex = 3;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = true;
			this->cancelButton->Click += gcnew System::EventHandler(this, &SimpleInputBox::cancelButton_Click);
			// 
			// okButton
			// 
			this->okButton->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->okButton->Location = System::Drawing::Point(52, 59);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(70, 35);
			this->okButton->TabIndex = 2;
			this->okButton->Text = L"Ok";
			this->okButton->UseVisualStyleBackColor = true;
			this->okButton->Click += gcnew System::EventHandler(this, &SimpleInputBox::okButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->label1->Location = System::Drawing::Point(9, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 16);
			this->label1->TabIndex = 2;
			this->label1->Text = L"label1";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->textBox1->Location = System::Drawing::Point(12, 31);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(186, 22);
			this->textBox1->TabIndex = 1;
			// 
			// SimpleInputBox
			// 
			this->AcceptButton = this->okButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->cancelButton;
			this->ClientSize = System::Drawing::Size(209, 105);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->cancelButton);
			this->Name = L"SimpleInputBox";
			this->Text = L"Please answer!";
			this->Load += gcnew System::EventHandler(this, &SimpleInputBox::SimpleInputBox_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void SimpleInputBox_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void okButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void cancelButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
