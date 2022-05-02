//*****************************************************************************************************
//
//		File:			StudentList.cpp
//		
//		Student:		William Gibbs
//
//		Assignment:	 	Program  #4, StudenList
//
//		Course Name:	Data Structures I 
//
//		Course Number:	COSC 3050 - 10
//
//		Due:			September 21, 2020 
//
//
//		This file contains the definition for Student object creation.
//
//		Other files required: 
//			1.	Student.h - definition for Student object creation
//          2.  Node.h - definition for node creation
//			3.  LinkedList.h - functions to modify the linked list
//			
//*****************************************************************************************************

#include <iostream>
#include <fstream>

using namespace std;

#include "Student.h"
#include "LinkedList.h"

//*****************************************************************************************************

char getChoice();
void process(LList < Student > &);
void buildList(LList < Student > &);
void displayStudents(const LList < Student > &);
void countStudents(const LList < Student > &);
void removeStudent(LList < Student > &);
void findStudent(const LList < Student > &);

//*****************************************************************************************************

int main()
{
    
    LList < Student > studentList;
    char choice;

    buildList(studentList);

    do
    {
        process(studentList);
        choice = getChoice();

        switch (toupper(choice))
        {
        case 'A':
            findStudent(studentList);
            break;
        case 'B':
            removeStudent(studentList);
            break;
        case 'C':
            countStudents(studentList);
            break;
        case 'D':
            displayStudents(studentList);
            break;
        case 'Q':
            break;
        default:
            cout << "\nThat was not a valid choice." << endl;
        }
    }while (toupper(choice) != 'Q');

    cout << "Program Terminated.\n" << endl;

    return 0;
}

//*****************************************************************************************************

char getChoice()
{
    char choice;

    cin >> choice;

    return choice;
}

//*****************************************************************************************************

void process(LList < Student >& list)
{
    cout << string(40, '*') << endl;
    cout << "Select a menu option from below..." << endl;
    cout << "A. Search for a student in the list" << endl;
    cout << "B. Remove a student from the list" << endl;
    cout << "C. Count the number of students in the list" << endl;
    cout << "D. Display the list in forward order" << endl;
    cout << "Q. Quit" << endl;
    cout << "Please enter your choice:  ";

}

//*****************************************************************************************************

void buildList(LList < Student >& list)
{
    ifstream studentFile; 
    Student s;
    
    studentFile.open("studentFile1.txt");

    if (studentFile.is_open())
    {
        while (studentFile >> s)
        {
            if (!list.insert(s))
                cout << "\nError retrieving student information" << endl;
        }
    }

    studentFile.close();
}

//*****************************************************************************************************

void displayStudents(const LList < Student > & list)
{
    cout << "\nDisplay all students' info..." << endl;

    if(!list.display())
        cout << "\nError displaying student list" << endl;
}

//*****************************************************************************************************

void countStudents(const LList < Student >& list)
{
    cout << "\nCount the number of students in the list..." << endl;
    cout << "There are currently " << list.getSize() << " students in the list\n" << endl;
}

//*****************************************************************************************************

void removeStudent(LList < Student >& list)
{
    Student s;
    int studentNum;

    cout << "\nEnter student's information for removal..." << endl;
    cout << "Please enter the student's ID number:  ";

    cin >> studentNum;

    s.id = studentNum;

    if (list.retrieve(s).id == 0)
        cout << "Student not found" << endl;
    else
    {
        list.remove(s);
        cout << studentNum << "\nStudent removed.\n" << endl;
    }
}

//*****************************************************************************************************

void findStudent(const LList < Student >& list)
{
    Student s;
    int studentNum;

    cout << "\nSearch for a student in the list..." << endl;
    cout << "Please enter studend ID number:  ";

    cin >> studentNum;

    s.id = studentNum;

    if (list.retrieve(s).id == 0)
        cout << "Student not found" << endl;
    else
        cout << s;
}

//*****************************************************************************************************

/*

****************************************
Select a menu option from below...
A. Search for a student in the list
B. Remove a student from the list
C. Count the number of students in the list
D. Display the list in forward order
Q. Quit
Please enter your choice:  d

Display all students' info...

9743: Johnson, James L
  ENGR 3.15

10236: Andrews, Peter J
  CPSC 2.78

15755: VandenVander, Vanessa V
  HIST 3.74

17424: Nakamura, Toky O
  SOCI 1.95

18264: Lucky, Lucy L
  HIST 2.29

24237: Euler, Lennie L
  MATH 3.83

31631: Aristotle, Alice A
  PHIL 3.1

****************************************
Select a menu option from below...
A. Search for a student in the list
B. Remove a student from the list
C. Count the number of students in the list
D. Display the list in forward order
Q. Quit
Please enter your choice:  c

Count the number of students in the list...
There are currently 7 students in the list

****************************************
Select a menu option from below...
A. Search for a student in the list
B. Remove a student from the list
C. Count the number of students in the list
D. Display the list in forward order
Q. Quit
Please enter your choice:  a

Search for a student in the list...
Please enter studend ID number:  0123
Student not found
****************************************
Select a menu option from below...
A. Search for a student in the list
B. Remove a student from the list
C. Count the number of students in the list
D. Display the list in forward order
Q. Quit
Please enter your choice:  b

Enter student's information for removal...
Please enter the student's ID number:  0123
Student not found
****************************************
Select a menu option from below...
A. Search for a student in the list
B. Remove a student from the list
C. Count the number of students in the list
D. Display the list in forward order
Q. Quit
Please enter your choice:  a

Search for a student in the list...
Please enter studend ID number:  31631

31631: Aristotle, Alice A
  PHIL 3.1
****************************************
Select a menu option from below...
A. Search for a student in the list
B. Remove a student from the list
C. Count the number of students in the list
D. Display the list in forward order
Q. Quit
Please enter your choice:  b

Enter student's information for removal...
Please enter the student's ID number:  31631
31631
Student removed.

****************************************
Select a menu option from below...
A. Search for a student in the list
B. Remove a student from the list
C. Count the number of students in the list
D. Display the list in forward order
Q. Quit
Please enter your choice:  d

Display all students' info...

9743: Johnson, James L
  ENGR 3.15

10236: Andrews, Peter J
  CPSC 2.78

15755: VandenVander, Vanessa V
  HIST 3.74

17424: Nakamura, Toky O
  SOCI 1.95

18264: Lucky, Lucy L
  HIST 2.29

24237: Euler, Lennie L
  MATH 3.83

****************************************
Select a menu option from below...
A. Search for a student in the list
B. Remove a student from the list
C. Count the number of students in the list
D. Display the list in forward order
Q. Quit
Please enter your choice:  c

Count the number of students in the list...
There are currently 6 students in the list

****************************************
Select a menu option from below...
A. Search for a student in the list
B. Remove a student from the list
C. Count the number of students in the list
D. Display the list in forward order
Q. Quit
Please enter your choice:  q
Program Terminated.

D:\OneDrive\Desktop\Webster\FA2020\DataStructures\DataStructures I\Week4\StudentList\Debug\StudentList.exe (process 22932) exited with code 0.
Press any key to close this window . . .


*/