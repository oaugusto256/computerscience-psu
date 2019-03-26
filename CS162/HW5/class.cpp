/* 
    Created by Alves Silva, Otavio Augusto
    Class.cpp - Attendance system 
    CS 162 - Intro to Computer Science 
    Email address: alves2@pdx.edu
    Date: 03/10/2015
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


bool Student::isMatch(char * name) // Check if the name is the same
{
	if (strcmp(this->name, name) == 0)
		return true;
	else
		return false;
}

void Student::attendLab(int lab_number)	// Attend to a lab class number
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

void Student::attendLecture(int lecture_number)	// Attend to a lecture class number
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

void Student::displayInfo() // Display student attendance information
{
	cout << "== The student " << name << " attended these classes." << endl;
	
	cout << "Labs: ";		// Print each lab in the attended lab array
	for(int i = 0; i < current_lab; i++)
		cout << "#" <<attended_labs[i] << ". ";
	cout << "\n";

	cout << "Lectures: ";	// Print each lecture in the attended lecture array
	for(int i = 0; i < current_lecture; i++)
		cout << "#" << attended_lectures[i] << ". ";
	cout << "\n";

	cout << "\n";
}

Attendance::Attendance()  // Constructor - initialize the data members
{
	head = NULL;
}

Attendance::~Attendance() // Destructor - delete all nodes in the linear linked list
{	
	if(!head)
	{
    	return;
	}

	else 
	{ 
		while(head != NULL)
		{
   		node * temp = head -> next;
    	delete head;
    	head = temp; 
		}	
	}
}

void Attendance::insertStudent() // Insert students in the linear linked list and read name 
{
	if (head == NULL) 		    // If doesn't exist a student in the list
	{
		node * currentStudent = head;
		head = new node;
		head->data = new Student;
		head->data->readName();
		head->next = currentStudent;
	}
	else					   // If the list already has a student at the begginer
	{						   // It goes until the final of the list and add at the last node
		node * currentStudent = head;
		while(currentStudent -> next)
		{
			currentStudent = currentStudent -> next;		
		}
		node * add = new node;
		add -> data = new Student;
		add -> data -> readName();
		currentStudent -> next = add;
		add -> next = NULL; 
	}
}

void Attendance::readAttendance()
{
	node * currentStudent = head;
	char answer[1];					// Char variable to check the attendance confirmation YES or NO
	int attendance_identifier = 0;	// Integer variable to hold the identifier number for the current attendance list

	cout <<	"== Enter an identifier number for this attendance list: "; // Ask for the current identifier number
	cin >> attendance_identifier;										// Receive the current identifier number
	cin.ignore(100, '\n');

	cout << "\n== LAB ATTENDANCE #" << attendance_identifier << endl; // Lab attendance
	while(currentStudent != NULL)
	{
		cout <<"\n== The student " << currentStudent->data->getName() << " is present for the lab #" << attendance_identifier <<" ? (Y/N) "; 
		cin >> answer[0];					// Receive the answer
		cin.ignore(100, '\n');
		answer[0] = toupper(answer[0]);
		
		if('Y' == answer[0])				// If the student is present
			currentStudent->data->attendLab(attendance_identifier); // Student attend to the lab
		else
			cout << "== Absent!";
		
		cout << "\n";	
		currentStudent = currentStudent->next;	// Traverse
	}

	currentStudent = head;
	
	cout << "\n== LECTURE ATTENDANCE #" << attendance_identifier << endl; // Lecture attendance
	while(currentStudent != NULL)
	{	
		cout <<"\n== The student " << currentStudent->data->getName() << " is present for the lecture #" << attendance_identifier <<" ? (Y/N) ";
		cin >> answer[0];	// Receive the answer
		cin.ignore(100, '\n');
		answer[0] = toupper(answer[0]);

		if('Y' == answer[0])	// If the student is present
			currentStudent->data->attendLecture(attendance_identifier); // Student attend to the Lecture
		else
			cout << "== Absent!";
		
		cout << "\n";	
		currentStudent = currentStudent->next;	// Traverse
	}

	system("clear");
}

void Attendance::displayInfo(char * name) // Display an individual student
{
	system("clear");

	node * currentStudent = head;		  // Current is head
	bool done = false;
    cout << "\n====================== ATTENDANCE LIST ======================\n" << endl;

    while ((currentStudent != NULL) && (done != true)) // While the list isn't over or done is false
    {
		if(currentStudent->data->isMatch(name))  // Try to match
		{
	 		currentStudent->data->displayInfo(); // Display student info
			done = true;						 // Loop is done
		}
		currentStudent = currentStudent->next;   // Traverse
   	}

	if (done == false)	// If the student doesn't exist
	{
		cout << "The student " << name << " doesn't exist!" << endl;
	}

	cout << "=============================================================" << endl;
}

void Attendance::displayAll() 
{
	system("clear");
	node * current = head;		 // Current is head

	cout << "\n====================== ATTENDANCE LIST ======================\n" << endl;
	
	while (current != NULL)		// While the list isn't over
	{
		current->data->displayInfo();	// Display  student info
		current = current->next; 		// Traverse
	}

	cout << "=============================================================" << endl;
}
