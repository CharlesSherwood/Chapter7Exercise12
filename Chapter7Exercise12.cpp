/*FileName:Chapter7Exercis12.cpp
ProgrammerName:Charles Sherwood
Date:4/2025
Requirements:This Program Should Act A Gradebook and let you
store and calculate students grades.
*/
#include<vector>
#include <iostream>
#include<iomanip>
#include<string>
using namespace std;


void welcome();
void GetInfo();
int NumberOfStudents();
int Menu();
void AddStudents();
void AddGrades();
void DisplayStudent();
void DisplayFinalGrade();


int main()
{

	welcome();
	Menu();

	int NumOfstudents = NumberOfStudents();
	GetInfo();






}


int Menu()
{
	int Choice;
	do
	{
		cout << "1-Add Students\n";
		cout << "2-Add Grades\n";
		cout << "3-Display Student Name and Grade\n";
		cout << "4-Display Final Grade Average\n";
		cout << "5-Exit The Program.\n";
		cin >> Choice;

		switch (Choice)
		{
		case 1:
		{
			AddStudents();
		}
		break;
		case 2:
		{

			AddGrades();
		}
		break;
		case 3:
		{
			DisplayStudent();

		}
		break;
		case 4:
		{
			DisplayFinalGrade();
		}
		break;
		default:
		{
			cout << "Please Enter A Valid Option\n";
			cin >> Choice;
			while (Choice < 1 || Choice>5)
			{
				cout << "Please Enter A Valid Option\n";
			}
		}



		}
	} while (Choice != 5);
}



void welcome()
{
	cout << "--------------------------------------\n";
	cout << "!!!Welcome To The Student Gradebook!!!";
	cout << "--------------------------------------\n";

}

void GetInfo()
{
	const int Size = 50;
	int Total = 0;
	cout << "How Many Students Do You Have:" << endl;
	string Name[Size];
	Total++;
	cout << "Please Enter The Name Of Student" << Total << endl;
	for (int Index=0; Index < Size; Index++)
	{
		getline(cin, Name[Size]);
		Name[Size] = Name[Index];
		cout << Name[Index];
	}
	


}


int NumberOfStudents()
{
	int NumOfStudents;
	cout << "How Many Students Will you beentering into the gradebook today: ";
	cin >> NumOfStudents;
	return NumOfStudents;
}


void AddStudents()
{

}


void AddGrades()
{

}


void DisplayStudent()
{

}


void DisplayFinalGrade()
{

}
 