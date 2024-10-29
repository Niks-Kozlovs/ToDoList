#pragma once

 ref class Priority
{
private:
    int _value;
    System::String^ _name;

public:
	Priority(int value, System::String^ name)
	{
		_value = value;
		_name = name;
	}


	property int Value
	{
		int get()
		{
			return _value;
		}
	}

	property System::String^ NameVal
	{
		System::String^ get()
		{
			return _name;
		}
	}
};

ref class Priorities
{
private:
    System::Collections::Generic::List<Priority^>^ priorities = gcnew System::Collections::Generic::List<Priority^>();
    System::String^ priorityLocation;
    void AddFromString(System::String^ line);
public:
    Priorities();
    void AddPriority(int value, System::String^ name);
	void Priorities::AddPriority(Priority^ priority);
    System::String^ GetNameByValue(int value);
	Priority^ Priorities::GetPriorityByValue(int value);
    int GetValueByName(System::String^ name);
    void SavePriorities();
    System::Collections::Generic::List<Priority^>^ GetPriorities();
};
