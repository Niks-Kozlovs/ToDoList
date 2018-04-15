#include "Functions.h"
#include <msclr/marshal_cppstd.h>


System::String ^ convertToSystemString(std::string text)
{
	return gcnew System::String(text.c_str());
}

std::string convertToStdString(System::String ^ text)
{
	return msclr::interop::marshal_as< std::string >(text);
}
