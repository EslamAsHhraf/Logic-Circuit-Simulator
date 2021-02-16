/*																		  
Data Structures and Algorithms Lab 3
Module -Files

File: Files.cpp

This is a program that  shows how to read and write text files
*/


#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//Create an output file stream object for the file "employees.txt"
	//and open it for output (writing)
	// "employees.txt" will be created if it does not already exist in the same directory of the project
	// ios::out is the flag for output mode used for writing
	// ios::app can be used to append to an existing file
	//After running the program once change it to ios::app and notice the difference

	ofstream outF("out.txt",ios::out);
	ifstream inF("in.txt",ios::in);
	
	int noOfElements;
	double* arr1;
	double* arr2;
	double* arr3;
	char name[30];
	int employeeID= 1;
	if(!inF.is_open())
	{
		cout<<"Couldn't Open Input File"<<endl;
		return -1;
	}
	inF>>name>>noOfElements;
	arr1= new double[noOfElements];
	arr2= new double[noOfElements];
	//arr3= new double[noOfElements];
	for (int i = 0; i < noOfElements; i++)
	{
		inF>>arr1[i]>>arr2[i];
	}


	inF.close();
	for (int i = 0; i < noOfElements; i++)
	{
		outF<<arr1[i] * arr2[i]<<endl;
	}
	outF<<"Thanks "<< name<<endl;
	outF.close();

	cout<<"Program Finished: "<<name;

	return 0;
}
