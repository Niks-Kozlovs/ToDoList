#include "ToDoListSorter.h"
#include "ToDoListItem.h"

ToDoListSorter::ToDoListSorter()
{
    ColumnToSort = 0;

    OrderOfSort = System::Windows::Forms::SortOrder::None;

    ObjectCompare = gcnew System::Collections::CaseInsensitiveComparer();
}

int ToDoListSorter::Compare(System::Object^ x, System::Object^ y)
{
    //Cast to listViewItem
	System::Windows::Forms::ListViewItem^ listviewX = (System::Windows::Forms::ListViewItem^)x;
	System::Windows::Forms::ListViewItem^ listviewY = (System::Windows::Forms::ListViewItem^)y;

	ToDoListItem^ itemX = (ToDoListItem^)listviewX->Tag;
	ToDoListItem^ itemY = (ToDoListItem^)listviewY->Tag;

	// Compare the two items
	int compareResult = 0;
	switch (ColumnToSort)
	{
	case 0:
		compareResult = itemX->time->CompareTo(itemY->time);
		break;
	case 1:
		compareResult = itemX->name->CompareTo(itemY->name);
		break;
	case 2:
		compareResult = itemX->priority->CompareTo(itemY->priority);
		break;
	case 3:
		compareResult = itemX->description->CompareTo(itemY->description);
		break;
	}

	if (OrderOfSort == System::Windows::Forms::SortOrder::Ascending)
	{
		return compareResult;
	}
	if (OrderOfSort == System::Windows::Forms::SortOrder::Descending)
	{
		return (-compareResult);
	}

	return 0;
}
