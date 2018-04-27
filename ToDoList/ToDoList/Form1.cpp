#include"stdafx.h"
#include<fstream>

using namespace ToDoList;
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main()
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ToDoList::Form1 mainForm;
	// Create the main window and run it
	Application::Run(%mainForm);
	return 0;
}
