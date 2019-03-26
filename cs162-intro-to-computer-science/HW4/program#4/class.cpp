/* 
    Created by Alves Silva, Otavio Augusto
    Class.cpp - Attendance system 
    CS 162 - Intro to Computer Science 
    Email address: alves2@pdx.edu
    Date: 03/03/2015
*/

#include "class.h"

Student::Student()		// Constructor - initialize the data members
{
	name = new char[SIZE_NAME];
	
	attended_labs = new int[SIZE_LAB];
	attended_lectures = new int[SIZE_LECTURE];

	current_lecture = 0;						
	current_lab = 0;
		
	max_labs = SIZE_LAB;
	max_lectures = SIZE_LECTURE;
}

Student::~Student() 	// Destructor 
{
	delete [] name;
	name = NULL;	
	
	delete [] attended_labs;
	attended_labs = NULL;
	
	delete [] attended_lectures;
	attended_lectures = NULL;
}

void Student::readName() 	// Read Student name
{
	cout << "== Please, enter the student name: ";
	cin.get(name, SIZE_NAME, '\n');
	cin.ignore(100, '\n');
}

char * Student::getName() 	// Get student name
{
	return name;
}

int  Student::getCurrent_Lecture() // Get the current lecture number
{
	return current_lecture;
}

int  Student::getCurrent_Lab() 	   // Get the current lab number
{
	return current_lab;
}

void Student::Attend_Lab(int lab_number)	// Attend to a lab class number
{
	if(current_lab < max_labs)				// If the current lab number is less then  maximum number of labs
	{			
		attended_labs[current_lab] = lab_number;	// Attended lab array element of the current lab receive the lab number
		current_lab += 1;							// Increase the current lab number
		cout << "== The Lab attendance was added!";
	}
	else
	{
		cout << "The maximum number of Lab has been reached!" << endl; 
	}
}

void Student::Attend_Lecture(int lecture_number)	// Attend to a lecture class number
{
	if(current_lecture < max_lectures)				// If the current lecture number is less then maximum number of lecture
	{
		attended_lectures[current_lecture] = lecture_number;	// Attended lecture array element of the current lecture receive the lecture number
		current_lecture += 1;									// Increase the current lecture number
		cout << "== The Lecture attendance was added!";
	}
	else
	{
		cout << "The maximum number of Lab has been reached!" << endl; 
	}
}

void Student::Display(char student_name[])	// Display student attendance information if the student exist
{
	if(strcmp(name, student_name) == 0)		// Check the student name
		Display();							// Display attendance information
	else
		cout << "\n== The student " << student_name << " doesn't exist!" << endl;
}

void Student::Display()		// Display student attendance information 
{	
	cout << "\n== The student " << name << " attended these classes." << endl;
	
	cout << "Labs: ";		// Print each lab in the attended lab array
	for(int i = 0; i < current_lab; i++)
		cout << "#" <<attended_labs[i] << ". ";
	cout << "\n";

	cout << "Lectures: ";	// Print each lecture in the attended lecture array
	for(int i = 0; i < current_lecture; i++)
		cout << "#" << attended_lectures[i] << ". ";
	cout << "\n";
}



Attendance::Attendance(int num_student) // Constructor - initialize the data members
{
	max_student	= num_student;
	students = new Student[num_student];
	this -> num_student = 0;
}


Attendance::~Attendance() // Destructor
{
	delete [] students;
	students = NULL;
}

void Attendance::Read_StudentName() // Read all student names
{
	if(num_student <= max_student)	// Check if the number of students is less than maximum students
	{	
		cout << "\n============================ READ STUDENTS NAME ============================\n";
		for(int i = 0; i < max_student; i++) // Loop to go through all the list of students
		{	
			cout <<"\n== #" << i+1 << " STUDENT ";
			students[i].readName();			 // Read each student name
			num_student += 1;				 // Increase the amount of students
		}
	}

	system("clear");
}

void Attendance::Read_Attendance()	// Read the lab and lecture attendance 
{	
	char answer[1];					// Char variable to check the attendance confirmation YES or NO
	int attendance_identifier = 0;	// Integer variable to hold the identifier number for the current attendance list

	cout <<	"== Enter an identifier number for this attendance list: "; // Ask for the current identifier number
	cin >> attendance_identifier;										// Receive the current identifier number
	cin.ignore(100, '\n');

	cout << "============================ ATTENDANCE #" << attendance_identifier << " ============================\n";
	if(num_student <= max_student) // Check if the number of students is less than maximum students
	{	
		cout << "\n== LAB ATTENDANCE #" << attendance_identifier << endl; // Lab attendance
		for(int i = 0; i < max_student; i++) // Loop to go through all the list of students
		{
			cout <<"\n== The student " << students[i].getName() << " is present for the lab #" << attendance_identifier <<" ? (Y/N) "; // Ask if the student is present
			cin >> answer[0];	// Receive the answer
			cin.ignore(100, '\n');
			answer[0] = toupper(answer[0]);

			if('Y' == answer[0])	// If the student is present
				students[i].Attend_Lab(attendance_identifier); // Student attend to the lab
			else
				cout << "== Absent!";
			cout << "\n";
		}
		
		cout << "\n== LECTURE ATTENDANCE #" << attendance_identifier << endl; // Lecture attendance
		for(int i = 0; i < max_student; i++) // Loop to go through all the list of students
		{	
			cout <<"\n== The student " << students[i].getName() << " is present for the lecture #" << attendance_identifier <<" ? (Y/N) "; // Ask if the student is present
			cin >> answer[0];	// Receive the answer
			cin.ignore(100, '\n');
			answer[0] = toupper(answer[0]);
	
			if('Y' == answer[0])	// If the student is present
				students[i].Attend_Lecture(attendance_identifier); // Student attend to the Lecture
			else
				cout << "== Absent!";
			cout << "\n";	
		}
	}
	system("clear");
}

void Attendance::Display_Attendance(char student_name[])
{
	cout << "\n===================== ATTENDANCE =========================\n";
	for(int i = 0; i < max_student; i++) // Loop to go through all the list of students
	{
		if(strcmp(students[i].getName(), student_name) == 0) // If the student name match 
			students[i].Display(student_name);				 // Check student attendance information
	}
	cout << "\n==========================================================\n";
}
void Attendance::Display_All()
{
	cout << "\n===================== ATTENDANCE =========================\n";
	for(int i = 0; i < max_student; i++) // Loop to go through all the list of students
	{
		students[i].Display();			// Check student attendance information
	}
	cout << "\n==========================================================\n";
}

