/* - Algorithm -
    Start program
        Create constants for the maximum size of some arrays
        Create a struct to group some information about a student
        Create a struct to group some information about an employ
        Put the employ struct into the student struct
        
        Create prototypes of some fuctions
            Fuction to check if the user wants to continue using the program
            Fuction to display all informations
            Fuction to read the name
            Fuction to read college information
            Fuction to read employ information
            Fuction to keep all read fuctions together
        
        Creata a variable to hold the amount of employ that user will enter 
        
        Welcome the program and its purpose 
        
        Loop - Execute while the user wants using the program
            Loop - Execute while the user wants to correct any mistake
                Ask for the user full name
                    Take first and last user name
                 
                Ask the user college information
                    Degree
                    College name
                    GPU 
                Ask how many employment will be entered
                Loop - While the amount is bigger than 3 or less or equal than 0
                    Display an error
                    Ask the last employ information
                        Start date and end date of work
                        Company name
                        Description
                End - Loop
                Display all information for the user checks if it's correct
            End Loop
            
            Check and take the system date
            Write all user information and the current date in an resume.txt file
                Write user name
                Write college information
                Loop - Write each information of each employment list while the count is less than amount of list
                    Write employment information
                    Increase the count
                End Loop
        End loop
        
     End program
*/ 

#include <iostream>
#include <cstring>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

/* 
    Created by Alves Silva, Otavio Augusto
    Program #3 - Resume builder
    CS 162 - Intro to Computer Science 
    Email address: alves2@pdx.edu
    Date: 02/15/2015
*/

const int SIZE = 30;    // Max size of some arrays
const int DESC = 250;   // Max size of description
const int GPA = 5;      // Max size of GPA
const int DATE = 11;    // Max size of date
const int EMPLOY = 3;   // Max amount of a list of employ information 

// Create a grouping for an employee information
struct employInfo
{
    char start[DATE];
    char end[DATE];
    char company[SIZE];
    char description[DESC];  
}; 

// Create a grouping for the student information
struct studentInfo
{
    char first[SIZE];
    char last[SIZE];
    char degree[SIZE];
    char college[SIZE];
    char gpa[GPA];
    employInfo employ[EMPLOY]; 
};

// Prototypes
void intro();                                               //  Welcome the program and its purpose 
void read_name(char [], char []);                           //  Read the user name
void read_collegeInfo(char [], char [], char []);           //  Read the user information about college
void read_employInfo(char [], char [], char [], char []);   //  Read the user employ information 
int read_info(studentInfo & );                              //  Read all user information and return the amount of employ information that will be used
void write_info(studentInfo &, int );                       //  Write the user information in a resume.txt file
void display_info(studentInfo & , int );                    //  Display all user information
bool again();                                               //  Loop fuction to repeat the program
bool correct();                                             //  Loop fuction to check if all user information is correct

int main()
{
    studentInfo person;     // Create a studentInfo variable to keep all information together
    int employAmount;       // Amount of employment that user will enter 
    
    do
    {
        intro();                // Welcome the program for the user     
        do
        {
            employAmount = read_info(person);       // Read all user information
            system("clear");                        // The terminal is clean
            display_info(person, employAmount);     // Display all user information
        }while(correct());                          // Check if all user information is correct
        write_info(person, employAmount);           // Write the user information in a resume.txt file
    }while(again());                                // Check if the user wants to continue using the program
    
    return 0;
}

void intro()
{
    system("clear"); // The terminal is clean
    
    // Welcome the program for the user
    cout << "==================================\n";
    cout << "=          RESUME BUILDER        =\n";     
    cout << "==================================\n\n";
    
    cout << "=========================================================================================\n";
    cout << "= This program will help you to keep track of the vital information of your resume and  =\n";
    cout << "= instead of rewriting it when there are changes, the program will track these changes  =\n";
    cout << "= and save them automatically. The information will be save in a file called resume.txt =\n";
    cout << "=========================================================================================\n\n"; 
}
// Read name information
void read_name(char first[], char last[])
{
    cout <<"Enter your first name: ";
    cin.get(first,SIZE,'\n');
    cin.ignore(100,'\n');

    cout <<"Enter your last name: ";
    cin.get(last,SIZE,'\n');
    cin.ignore(100,'\n');
}

// Read college information
void read_collegeInfo(char degree[], char college[], char gpa[])
{
    cout <<"Enter your degree: ";       
    cin.get(degree,SIZE,'\n');
    cin.ignore(100,'\n');

    cout <<"Enter your college name: ";
    cin.get(college,SIZE,'\n');
    cin.ignore(100,'\n');
    
    cout <<"Enter your current GPA: ";
    cin.get(gpa,GPA,'\n');
    cin.ignore(100,'\n');   
}

// Read employ information 
void read_employInfo(char start[], char end[], char company[], char description[])
{
     cout <<"Enter your company name: ";
     cin.get(company,SIZE,'\n');
     cin.ignore(100,'\n');
     
     cout <<"Enter your start day of work: ";
     cin.get(start,DATE,'\n');
     cin.ignore(100,'\n');

     cout <<"Enter your end day of work: ";
     cin.get(end,DATE,'\n');
     cin.ignore(100,'\n');

     cout <<"Enter the description of your company: ";
     cin.get(description,DESC,'\n');
     cin.ignore(100,'\n');
}

// Call all reading fuctions
int read_info(studentInfo & person)
{
    int amount;                             // Amount of previous works that will be entered
    
    read_name(person.first, person.last);   // Read the user' name 
    read_collegeInfo(person.degree, person.college, person.gpa); // Read the user' college information
   
    cout <<"\nHow many employment information you will enter?" << endl;
    cin >> amount;              
    cin.ignore(100,'\n');
    
    while((amount > 3) || (amount <= 0))    //  While the amount is bigger than three or less or equal than zero
    {
        cout <<"ERROR!, Please enter an amount less or equal then three." << endl;
        cout <<"How many employment information you will enter?" << endl;
        cin >> amount;
        cin.ignore(100,'\n');
    }
    
    
    for(int i = 0; i < amount; ++i)    // Each list will be filled
    {   
        cout << "\n= The " << i+1 << "# employ information = \n";
        read_employInfo(person.employ[i].start, person.employ[i].end, person.employ[i].company, person.employ[i].description); // Read the user' employ information
    }
    
    return amount;
}

void display_info(studentInfo & person, int amount)
{   
    cout << "==========\n";
    cout << "= RESUME =\n";
    cout << "==========\n\n";
    
    // Display all user' information
    cout << "=====================================================================================\n";  
    cout << "\n";
    cout << "= Full name: "<< person.first << " " << person.last << endl;
    cout << "= Degree: "<< person.degree << endl; 
    cout << "= College: " << person.college << endl; 
    cout << "= GPA: " << person.gpa << endl;
    
    cout <<"\n";
    for(int i = 0; i < amount; ++i)         // Display each information of each list
    {
        cout << "= The " << i+1 << "# employ information =" << endl;
        cout << "= Company: " << person.employ[i].company << endl;
        cout << "= First day of work: "<< person.employ[i].start << endl;
        cout << "= Last day of work: " << person.employ[i].end << endl;
        cout << "= Description: "<< person.employ[i].description << endl;
        cout << "\n";
    }   
    cout << "=====================================================================================\n\n"; 
}

void write_info(studentInfo & person, int amount)
{
    ofstream file;                          // Create a ofstream variable for output to a file
    time_t now = time(0);                   // Current date/time based on current system
    tm *ltm = localtime(&now);              // Return a pointer to the tm structure represeting local time
    int year = 1900 + ltm->tm_year;         // Take the current year    
    int month = 1 + ltm->tm_mon;            // Take the current month
    int day = ltm->tm_mday;                 // Take the current day
    
    if(ifstream("resume.txt"))              // If the current directory already have a file called resume.txt 
    {   
        file.open("resume.txt", ios::app);  // The file is opened in the append mode
        file << "\n\n";                     // Write two new lines to distinguish data
    }
    else                                    // If not have
    {
        file.open("resume.txt");            // The file is created 
    }
    
    // Each information is saved in the file
    file << "================ RESUME - DATE: " << month <<"/"<< day <<"/"<< year << " ======================" << endl;
    file << "\n";
    file << "= Full name: "<< person.first << " " << person.last << endl;
    file << "= Degree: "<< person.degree << endl; 
    file << "= College: " << person.college << endl; 
    file << "= GPA: " << person.gpa << endl;
    file << "\n";
    
    for(int i = 0; i < amount; ++i)         // Each information of each list will be saved 
    {
        file << "= The " << i+1 << "# employ information =" << endl;
        file << "= Company: " << person.employ[i].company << endl;
        file << "= First day of work: "<< person.employ[i].start << endl;
        file << "= Last day of work: " << person.employ[i].end << endl;
        file << "= Description: "<< person.employ[i].description << endl;
        file << "\n";
    }   
    file << "================================================================" << endl;
    
    file.close();       // Closes the file currently associated with the object
    file.clear();       // Sets a new value for the stream's internal error state flags
    
    cout << "The information was saved in \"resume.txt\". \n\n";
}

//  It does a loop to check if the user wants to continue using the program
bool again()
{
    char condition[1];  

    cout << "Do you want to continue using the program? (Y/N)\n";
    cin >> condition[0];
    cin.ignore(100,'\n');
    condition[0] = toupper(condition[0]);
    
    if('Y' == condition[0]) // If the answer is YES
    {   
        system("clear");    // The terminal is clean
        return true;        // Boolean value true is returned and the loop continues
    }
    else
    {
        return false;       // Boolean value false is returned and the loop is over
    }
}

//  It does a loop to give a chance for the user checks if the information is correct
bool correct()
{
    char condition[1];

    cout << "The information is correct ? (Y/N)\n";
    cin >> condition[0];
    cin.ignore(100,'\n');
    condition[0] = toupper(condition[0]);
    
    if('Y' == condition[0])     // If the answer is YES         
    {     
        return false;           // Boolean value false is returned and the loop is over
    }
    else
    {
        system("clear");        // The terminal is clean
        return true;            // Boolean value true is returned and the loop continues
    }
}


