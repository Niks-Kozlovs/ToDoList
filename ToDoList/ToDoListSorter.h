#pragma once
ref class ToDoListSorter :
    System::Collections::IComparer
{
public:

    ToDoListSorter();
    virtual int Compare(System::Object^ x, System::Object^ y);

public:
    /// <summary>
    /// Specifies the column to be sorted
    /// </summary>
    int ColumnToSort;

    /// <summary>
    /// Specifies the order in which to sort (i.e. 'Ascending').
    /// </summary>
    System::Windows::Forms::SortOrder OrderOfSort;

    /// <summary>
    /// Case insensitive comparer object
    /// </summary>
    System::Collections::CaseInsensitiveComparer^ ObjectCompare;

    property int SortColumn;
    property System::Windows::Forms::SortOrder SortOrder;
};

