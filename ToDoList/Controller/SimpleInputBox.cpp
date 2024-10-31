#include "../View/SimpleInputBox.h"
System::Void ToDoApp::SimpleInputBox::SimpleInputBox_Load(System::Object^ sender, System::EventArgs^ e)
{
	this->textBox1->Focus();
	this->Text = name;
	label1->Text = message;
}


System::Void ToDoApp::SimpleInputBox::okButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->answer = textBox1->Text;
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}

System::Void ToDoApp::SimpleInputBox::cancelButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}
