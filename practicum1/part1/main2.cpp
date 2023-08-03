#include <iostream>
#include <cstring>
using namespace std;

struct employee
{
	int employee_no;
	char employee_name[128]; 
};

const int MAX = 5;

bool addemployee(employee*& record);	// creates an employee structure dynamically

// add your function prototypes here
//this function simply prints out the employees stored in the array employees
void outputemployees(employee* []);
//this needs to deallocate the employees that are on the heap
void freeemployees(employee* []);

int main()
{
	employee* employees[MAX];
	int i = 0;

	for (i = 0; i < 5; i++)
	{
		addemployee(employees[i]);
	}
	//cout << "done adding" << endl;
       
	// add function to output employees
	outputemployees(employees);
	//cout << "done outputting" << endl;
		
	// add function to free all employees from the array
	freeemployees(employees);
        
	return 0;
}

// add additional code here.
bool addemployee(employee*& record)//takes in a pointer by reference
{
/*
The function should attempt to allocate an object of type
employee on the heap and assign the value to the pointer. In the event the object can not be
allocated on the heap the function should return false. Otherwise prompt the user for the
employee number and assign it to the appropriate member of the instance. Then prompt
for the employees name and assign to the appropriate member (assume a name is only one
word). Use iostreams for input and output. If everything is successful return the integer
true. Use new to allocate memory on the heap. 
*/
	record = new employee;
	if(record == NULL)
	{
		cout << "Out of memory on heap" << endl;
		return false;
	}
	
	cout << "Enter the employee's number: ";
	cin >> record->employee_no;
	//record->employee_no = number;

	cout << "Enter the employee's name: ";
	cin >> record->employee_name;

	return true;
}

void outputemployees(employee* employees[MAX])
{
	for(int i = 0; i < MAX; i++)
	{
		cout << "Number: " << employees[i]->employee_no << endl
			 << "Name: ";
		int length = strlen(employees[i]->employee_name);
		for(int j = 0; j < length; j++){
			cout << employees[i]->employee_name[j];
		}
		cout << endl;		
	}
}

void freeemployees(employee* employees[MAX])
{
	for(int i = 0; i < MAX; i++)
	{
		delete employees[i];
	}
}



