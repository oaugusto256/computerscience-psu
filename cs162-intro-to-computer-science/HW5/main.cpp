/* 
    Created by Alves Silva, Otavio Augusto
    main.cpp - Attendance system 
    CS 162 - Intro to Computer Science 
    Email address: alves2@pdx.edu
    Date: 03/10/2015
*/

#include "class.h"

int intro();			// Function to read the amount of students of each attendance list
int menuOption();		// Function to display a menu for search for a specific student attendance
bool searchAgain();		// Loop function to search for an attendance again
bool executeAgain();	// Loop function to continue using the program


int main()
{
	Attendance	attendanceList;				  // Attendance collection
	int numberStudents;						  // Number of students for each list 
	int numberAttendance;					  // Number of attendance list
	int option;								  // Option for the menu
	char * studentName = new char[SIZE_NAME]; // Student name for search
	
	do{ //	Loop for continue using the program
		numberStudents = intro();			  // Welcome the user and receive the amount of students for the future attendance lists
	
		cout << "\n========================= READ STUDENTS NAME =========================\n";
		for(int i = 0; i < numberStudents; i ++){
			cout <<"\n== #" << i+1 << " STUDENT\n";
			attendanceList.insertStudent();  // Insert each student in the linked list
		}

		system("clear");
	
		cout << "\n======================= READ ATTENDANCE AMOUNT =======================\n";
		cout << "== How many attendance list are you going create: ";
		cin >> numberAttendance; 			 // Receive the amount of lists
		cin.ignore(100, '\n');

		for(int i = 0; i < numberAttendance; i ++){
			cout <<"\n== #" << i+1 << " LIST\n";
			attendanceList.readAttendance(); // Read attendance of each list
		}		

		
		do{ // Loop for continue search attendances
			option = menuOption();			 // Display the menu option
			switch (option)					
			{
				case 1:						 // If the option is 1
					cout << "== Enter a student name to find attendance list: "; // Read student name
					cin.get(studentName, SIZE_NAME, '\n');
					cin.ignore(100, '\n');
					attendanceList.displayInfo(studentName);	// Display the student attendance
					break;				
				case 2:						// If the option is 2
					attendanceList.displayAll();				// Display all students attendance
					break;
				default:					// If not, display an error 
    				cout << "== Invalid option!\n";
					break;
  			}
		}while(searchAgain());
	}while(executeAgain());
	
	return 0;
}

// Welcome the user, receive and return the amount of students
int intro()
{
	int numberStudents;
	system("clear");

	cout << "================================================\n";
	cout << "=============== ATTENDANCE SYSTEM ==============\n";
	cout << "================================================\n\n";

	cout << "===============================================================================\n";
	cout << "= This program simulates an attendance system for a class in which it has a   =\n";
	cout << "= lab and lecture. The program will ask for the amount of students for each   =\n";
	cout << "= attendance list as well as the identifier number for each attendance list.  =\n";
	cout << "= At the end, the program will provide the possibility to show the attendance =\n";
	cout <<	"= of a specific student as well as of all students.                           =\n";
	cout << "===============================================================================\n\n";

	cout << "== Enter the number of students for the class attendence list: ";
	cin >> numberStudents;
	cin.ignore(100, '\n');
	
	system("clear");

	return numberStudents;
}

// Function loop to continue search for student attendances 
bool searchAgain()
{
	char answer[1];
	
	cout << "== Do you want to continue searching attendance list  ? (Y/N) ";
	cin >> answer[0];
	answer[0] = toupper(answer[0]);
	
	cin.ignore(100, '\n');
	if(answer[0] == 'Y')
		return true;
	else
		return false;
}

// Function loop to continue using the programs
bool executeAgain()
{
	char answer[1];

	cout << "== Do you want to continue using the program ? (Y/N) ";
	cin >> answer[0];
	answer[0] = toupper(answer[0]);

	cin.ignore(100, '\n');
	if(answer[0] == 'Y')
		return true;
	else
		return false;
}

// Function to display the menu and receive the user's option
int menuOption()
{
	system("clear");
	int option;

	cout << "=============== ATTENDANCE DISPLAY SYSTEM ==============\n";
	cout << "1. Display a specific student attendance." << endl;
	cout << "2. Display all students attendance.\n" << endl;

	cout << "== Enter the option number: ";

	cin >> option;
	cin.ignore(100, '\n');
	return option;
}
