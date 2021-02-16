#include <iostream>
#include <fstream>
using namespace std;

class Student
{
	int id;
	char letter_grade; // letter_grade can be: ''A', 'B', 'C', 'D', 'E', 'F'
public:
	void ReadInfo(ifstream & input) // note that we passed the ifstream by & (why?)
	{
		input >> id >> letter_grade;
	}
	void WriteInfo(ofstream & output) const // note that we passed the ofstream by & (why?)
	{
		output << id << " " << letter_grade << endl;
	}
	char getGrade() const
	{
		return letter_grade;
	}
};

int main()
{
	// =========== 1- Reading Student Grades from File =========================

	ifstream fin("grades.txt");
	// open the given "grades.txt" file, found in the folder "Examples\Example2"

	// grades file first contains number of students, n
	// then n lines, each line contains the id and the letter_grade of a student
	
	int n;
	Student* students = NULL; // will point to an array of students later

	if (fin.is_open())
	{
		fin >> n;
		students = new Student[n];
		for (int i = 0; i < n; i++)
		{
			students[i].ReadInfo(fin); // we passed the ifstream by reference to ReadInfo
			                           // to read the data members of the student: students[i]
			                           // from the already opened file
		}
		fin.close();
	}

	// =========== 2- Calculating the count of each Grade =========================

	int a, b, c, d, e, f;
	a = b = c = d = e = f = 0; // initialize counts with 0
	for (int i = 0; i < n; i++)
	{
		char grade = students[i].getGrade();
		switch (grade)
		{
		case 'A':
			a++;
			break;
		case 'B':
			b++;
			break;
		case 'C':
			c++;
			break;
		case 'D':
			d++;
			break;
		case 'E':
			e++;
			break;
		case 'F':
			f++;
			break;
		default:
			break;
		}
	}

	// =========== 3- Writing  <Grade vs. Count> then the information of students in an Output File =========================

	ofstream fout("grades_count.txt");

	fout << "Grade A count: " << a << endl;
	fout << "Grade B count: " << b << endl;
	fout << "Grade C count: " << c << endl;
	fout << "Grade D count: " << d << endl;
	fout << "Grade E count: " << e << endl;
	fout << "Grade F count: " << f << endl;

	// print the details of each student
	fout << endl << " ========= [Details] ========= " << endl << endl;
	for (int i = 0; i < n; i++)
	{
		students[i].WriteInfo(fout);
	}

	fout.close();

	// after running this example,
	// open the "grades_count.txt" found inside the folder: "Examples\Example2"
	// and see what's written inside it

	if (students != NULL)
		delete [] students;
}