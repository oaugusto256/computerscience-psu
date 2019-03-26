/*	-- Algorithm --
	Start the program
		Create a collection of attendance
		Create a variable to hold the user's menu option 
		Create a variable to hold the number of students for a attendance list
		Create a variable to hold the number of attendance list that user will use

		Loop - While the user wants continue using the program	
	
				Ask and receive the amount of student for a attendance list
	
				Insert each student name in the linked list
					Loop - While the number of students isn't reached	
						Read student name								
					End Loop
		
				Read the amount of attendance list that user will use
					Loop - While the number of amount attendance list isn't zero
						Read the students attendance
					
						Loop - While the number of students isn't reached	
							Lab attendance for this student
							Lecture attendance for this student 
						End Loop
	
						Decrease the number of attendance list
					End Loop
				
			Loop - While the user wants to continue searching	
				Display menu options
					If the option is one
						Ask for the student name
						Display the student attendance
					If the option is two
				Display the student attendance information
			End Loop		
		
		End Loop
	End the program
*/

/* 
    Created by Alves Silva, Otavio Augusto
    Class.h - Attendance system 
    CS 162 - Intro to Computer Science 
    Email address: alves2@pdx.edu
    Date: 03/10/2015
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

// Constants to dynamically allocated arrays
const int SIZE_NAME = 20;
const int SIZE_LAB = 10;		
const int SIZE_LECTURE = 10;

// This class manages one individual student attendance
class Student
{
	public:	
		Student(); 	 				// Constructor
		~Student();	 				// Destructor

		void readName();			// Read student name
		char * getName();			// Get student name
		bool isMatch(char * name);	// Check if the name is the same

		void attendLab(int lab_number);			// Attend to a lab class
		void attendLecture(int lecture_number);	// Attend to a lecture class
		void displayInfo();						// Display attendance information of a student
	
	private:
		char * name;				// Pointer to a student name

		int * attended_labs;		// Pointer to a array of attended Lab
		int * attended_lectures;	// Pointer to a array of attended lecture
		
		int current_lab;			// Number of the current lab
		int current_lecture;		// Number of the current lecture				
		
		int max_labs;				// Maximum number of labs			
		int max_lectures;			// Maximum number of lectures
};

// Struct node for a linear linked list
struct node
{
	Student * data; 
	node * next;
};

// This class manages a group of students attendance
class Attendance
{
	public:
		Attendance(); 				// Constructor
		~Attendance();				// Desconstrutor
		
		void insertStudent();			// Read a list of student name
		void readAttendance();			// Read a lab and lecture attendance
		void displayInfo(char * name);  // Check if the name match with the student name and display attendance information
		void displayAll();			// Display attendance information of all students
	private:
		node * head;
};



