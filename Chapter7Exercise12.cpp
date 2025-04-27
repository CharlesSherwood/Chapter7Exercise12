/*FileName:Chapter7Exercis12.cpp
ProgrammerName:Charles Sherwood
Date:4/2025
Requirements:This Program Should Act A Gradebook and let you
store and calculate students grades.
*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;


vector<string> studentNames;
vector<vector<int>> studentGrades;

// Function prototypes
void welcome();
void Menu();
void AddStudents();
void AddGrades();
void DisplayStudent();
void DisplayFinalGrade();
char calculateLetterGrade(double avg);



//Main that calls the other modules
int main() 
{
    welcome();
    Menu();
    return 0;
}

//Displays A welcome message
void welcome()
{
    cout << "--------------------------------------\n";
    cout << "!!! Welcome To The Student Gradebook !!!\n";
    cout << "--------------------------------------\n\n";
}

//Displays the menu and gets the user input for their choice Sends them to different modules
void Menu()
{
    int choice;
    do 
    {
        cout << "\nMenu:\n";
        cout << "1 - Add Students\n";
        cout << "2 - Add Grades\n";
        cout << "3 - Display Student Name and Grades\n";
        cout << "4 - Display Final Grade Average\n";
        cout << "5 - Exit the Program\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            AddStudents();
            break;
        case 2:
            AddGrades();
            break;
        case 3:
            DisplayStudent();
            break;
        case 4:
            DisplayFinalGrade();
            break;
        case 5:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Please enter a valid option (1–5).\n";
        }
    } while (choice != 5);
}


//Adds students to the gradebook
void AddStudents() 
{
    string name;
    cout << "Enter student names (type 'done' to finish):\n";
    cin.ignore();

    while (true)
    {
        getline(cin, name);
        if (name == "done") break;
        if (!name.empty()) 
        {
            studentNames.push_back(name);
            studentGrades.push_back(vector<int>());
        }
    }
}


//allows you to add grades to students 
void AddGrades() 
{
    if (studentNames.empty())
    {
        cout << "No students found. Please add students first.\n";
        return;
    }

    for (int i = 0; i < studentNames.size(); ++i) 
    {
        cout << "Enter grades for " << studentNames[i] << " (type -1 to stop):\n";
        int grade;
        while (true) 
        {
            cin >> grade;
            if (grade == -1) break;
            if (grade >= 0 && grade <= 100) 
            {
                studentGrades[i].push_back(grade);
            }
            else 
            {
                cout << "Invalid grade. Please enter a value between 0 and 100.\n";
            }
        }
    }
}


//Displays students and their grades
void DisplayStudent() 
{
    if (studentNames.empty()) 
    {
        cout << "No students to display.\n";
        return;
    }

    for (int i = 0; i < studentNames.size(); ++i) 
    {
        cout << studentNames[i] << ": ";
        if (studentGrades[i].empty())
        {
            cout << "No grades entered.\n";
        }
        else 
        {
            for (int grade : studentGrades[i]) 
            {
                cout << grade << " ";
            }
            cout << endl;
        }
    }
}

//Displays the students and their averages 
void DisplayFinalGrade() 
{
    if (studentNames.empty()) 
    {
        cout << "No students to display.\n";
        return;
    }

    for (int i = 0; i < studentNames.size(); ++i)
    {
        if (studentGrades[i].empty())
        {
            cout << studentNames[i] << ": No grades to calculate average.\n";
            continue;
        }

        vector<int> grades = studentGrades[i];
        double sum = 0;
        for (int grade : grades) sum += grade;
        double avg = grades.empty() ? 0 : sum / grades.size();

        cout << studentNames[i] << " Final Average: "
            << fixed << setprecision(2) << avg
            << " (" << calculateLetterGrade(avg) << ")\n";
    }
}


//calculates what the srudents grade would be
char calculateLetterGrade(double avg) 
{
    if (avg >= 90) return 'A';
    if (avg >= 80) return 'B';
    if (avg >= 70) return 'C';
    if (avg >= 60) return 'D';
    return 'F';
}
