#include "AddPriorityForm.h"
#include "Priorities.h"
System::Void ToDoApp::AddPriorityForm::okButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->priority = gcnew Priority(Convert::ToInt32(this->numericUpDown1->Value), this->textBox1->Text);
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}
System::Void ToDoApp::AddPriorityForm::cancelButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}