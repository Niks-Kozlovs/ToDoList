#include "../View/AddItemForm.h"
#include "../View/AddPriorityForm.h"

System::Void ToDoApp::AddItemForm::cancel_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}

System::Void ToDoApp::AddItemForm::addPriority_Click(System::Object^ sender, System::EventArgs^ e)
{
	AddPriorityForm^ addPriorityForm = gcnew AddPriorityForm();
	if (addPriorityForm->ShowDialog(this) == System::Windows::Forms::DialogResult::OK)
	{
		this->priorities->AddPriority(addPriorityForm->priority);
		this->prioritiesList->DataSource = nullptr;
		this->prioritiesList->DisplayMember = "NameVal";
		this->prioritiesList->ValueMember = "Value";
		this->prioritiesList->DataSource = this->priorities->GetPriorities();
		this->priorities->SavePriorities();
	}
}

System::Void ToDoApp::AddItemForm::okButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	String^ name = this->textBox4->Text;
	int value = Convert::ToInt32(this->prioritiesList->SelectedValue);
	Priority^ priority = this->priorities->GetPriorityByValue(value);
	String^ description = this->descriptionInput->Text;
	int hour = Convert::ToInt32(this->hourInput->Value);
	int minute = Convert::ToInt32(this->minuteInput->Value);
	DateTime time = DateTime::Parse(this->datePicker->Value.ToShortDateString() + " " + hour + ":" + minute + ":00");

	this->item = gcnew ToDoListItem(name, description, priority, time);
	this->Close();
}

System::Void ToDoApp::AddItemForm::AddItem_Load(System::Object^ sender, System::EventArgs^ e)
{
	this->priorities = gcnew Priorities();
	this->prioritiesList->DisplayMember = "NameVal";
	this->prioritiesList->ValueMember = "Value";
	this->prioritiesList->DataSource = this->priorities->GetPriorities();

	if (this->item != nullptr)
	{
		this->textBox4->Text = this->item->name;
		this->descriptionInput->Text = this->item->description;
		this->prioritiesList->SelectedValue = this->item->priority->Value;
		this->datePicker->Value = DateTime(this->item->time->Year, this->item->time->Month, this->item->time->Day);
		this->hourInput->Value = this->item->time->Hour;
		this->minuteInput->Value = this->item->time->Minute;
	}
	else {
		this->datePicker->MinDate = DateTime::Now;
	}
}
