#include "../View/MoreInfo.h"

System::Void ToDoApp::MoreInfo::MoreInfo_Load(System::Object^ sender, System::EventArgs^ e)
{
	itemName->Text = item->name;
	itemDate->Text = item->time->ToLongDateString();
	itemPriority->Text = item->priority->NameVal;
	itemDescription->Text = item->description;
}

System::Void ToDoApp::MoreInfo::okButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}