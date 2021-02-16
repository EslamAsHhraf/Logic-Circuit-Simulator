
#include <fstream> // do NOT forget to include: #include <fstream> to deal with files
#include <iostream>
// #include <iomanip>
using namespace std;

int main()
{

	// ========================= // 1- Testing ofstream // ========================= //

	//Create an output file stream object for the file "employees.txt"
	//and open it for output (writing)
	// "employees.txt" will be created if it does not already exist in the same directory of the project
	// ios::out is the flag for output mode used for writing
	// ios::app can be used to append to an existing file
	//After running the program once change it to ios::app and notice the difference


	// declare an object of ofstream and open the file for writing in it
	ofstream outEmployeeFile("employees.txt"); // the default flag of ofstream is: 
	                                           // ios::out (don't need to pass it; default)

	// after the previous statement,
	// employees.txt will be create if not already found
	// in the path of: "Examples\Example1" folder --> check it inside that folder

	// from now on, "outEmployeeFile" will be treated exactly as cout
	// but to write in the opened file "employees.txt" not in the console

	// declare some variables
	char employeeName[30];
	double employeeSalary;
	int employeeID= 1;
	char again='y';

	// the following for loop will: 
	// read salary and name of each employee from cin
	// and write its id (incrementing count), salary and name of each employee the file
	// until the "again" becomes != 'y' then exit the loop
	cout<<"Enter employees information"<<endl;
	while(again=='y')
	{
		//Prompt the user to enter the employee information
		cout<<"\nEnter the employee name:";
		cin >> employeeName;
		//cin.getline(employeeName,30,'\n'); //If we need to get a full name with spaces

		cout<<"Enter the employee salary:";
		cin >> employeeSalary;

		// Write the input data to the file stream --> note how it's similar to " cout << "
		outEmployeeFile << employeeID++ << "\t" << employeeSalary << "\t" << employeeName<< endl;

		cout << "Continue?(y/n)";
		cin >> again;

		//cin.ignore(); //Ignore \n in buffer will be needed if we want to get name with spaces and used cin.getline
	} 

	// close the file after using it
	outEmployeeFile.close();

	// ========================= // 2- Testing ifstream // ========================= //

	// Create an input file stream object for the file "employees.txt"
	// and open it for input (reading)
	// "employees.txt" should be in the same directory of the project
	// otherwise it will throw an exception (run-time error) that should be handled (outside the scope of this lab)
	// ios::in is the flag for input mode used for reading


	// declare an object of ifstream and open the file for reading
	ifstream inEmployeeFile("employees.txt"); // the default flag of ifstream is: 
	                                          // ios::in (don't need to pass it; default)

	// note that: to read from a file, the file should be already created before
	// unlike, the ofstream which creates it if not found
	// Note: in general, the input file should be inside the folder of the project 'Examples\Example1'
	// if you provided only the file name as above (not the whole absolute path)

	// from now on, "inEmployeeFile" will be treated exactly as cin
	// but to read from the opened file "employees.txt" not from the console

	cout<<"Employees with salary less than 200:"<<endl;
	cout<<"EmployeeID\t EmployeeName\t EmployeeSalary"<<endl;
	
	// the following reads the employee data from the file
	// and writes them in the console for the employees that have salary < 200
	if(inEmployeeFile.is_open()) //check if the file was found and opened successfully 
	{	
		//Read fields of a record from file in the order they were written
		inEmployeeFile >> employeeID >> employeeSalary; // reads the id and the salary
		inEmployeeFile.getline(employeeName, 30, '\n'); // then getline of the remaining line
		                                                // to read the remaining as the name (even if it contains spaces)

		//While the ifstream doesn't reach the end of file proceed
		while(!inEmployeeFile.eof())
		{
			if(employeeSalary<200)
			{
				cout<< employeeID << "\t" << employeeName << "\t\t" << employeeSalary << endl;
			}
			
			// Read the input data from the file stream --> note how it's similar to " cin >> "
			inEmployeeFile >> employeeID >> employeeSalary;
			inEmployeeFile.getline(employeeName, 30, '\n');
		}

		// close the file after using it
		inEmployeeFile.close();
	}
	else
	{
		cout<<"Error: Could not open the file!"<<endl;
	}

	return 0;
}
