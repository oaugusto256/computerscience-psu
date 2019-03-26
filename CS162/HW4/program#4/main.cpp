/* 
    Created by Alves Silva, Otavio Augusto
    Program #4 - Attendance system: Program to simulate an attendance system of a class with lab and lecture
    CS 162 - Intro to Computer Science 
    Email address: alves2@pdx.edu
    Date: 03/03/2015
*/

#include "class.h"

int intro();			 // Welcome the program to the user and receive the number of students for the attendance list
int attendance_amount(); // Function that will receive the amount of attendance list which the user is going to use 
bool again();			 // Loop fuction to repeat the program

int main()
{	
	int num_students;		//	Number of the students for the attendance list
	int num_attendance;		//	Number of attendance list
	
	do{
		num_students = intro();				   // Welcome the user and receive the amount of students for the future attendance lists
		Attendance cs162(num_students);		   // Create a attendance collection with the number of students
		cs162.Read_StudentName();			   // Read all students name 
		num_attendance = attendance_amount();  // Receive the amount of attendance list that will be used
		do{
			cs162.Read_Attendance();		   // Read attendance
			num_attendance -= 1;			   // Amount of attendance list is decreased
		}while(num_attendance > 0);			   // The amount of attendance list is bigger than zero 
		cs162.Display_All();				   // Display the students attendance information
	}while(again());						   // Ask the user if he wants to continue using the program

	system("clear");		// The terminal is clean
}

// Welcome the user, receive and return the amount of students
int intro()
{
	int num_students;
	system("clear");

	cout << "================================================\n";
	cout << "=============== ATTENDANCE SYSTEM ==============\n";
	cout << "================================================\n\n";

	cout << "=============================================================================\n";
	cout << "= This program simulates an attendance system for a class in which it has a =\n";
	cout << "= lab and lecture. The program will ask for the amount of students for each =\n";
	cout << "= attendance list as well as the identifier number for each attendance list.=\n";
	cout << "= At the end, the program will display the attendance of all students.      =\n";
	cout << "=============================================================================\n\n";
	
	cout << "== Enter the number of students for the class attendence list: ";
	cin >> num_students;
	cin.ignore(100, '\n');
	
	system("clear");

	return num_students;
}

// Receive and return the amount of attendance list that user will use
int attendance_amount()
{
	int amount;
	system("clear");

	cout << "== How many attendance list are you going create: ";
	cin >> amount;
	cin.ignore(100, '\n');

	return amount;	
}

// Function loop to continue using the programs
bool again()
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
