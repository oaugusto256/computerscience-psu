#include "roster.h"

const int SIZE = 100;

bool again();

int main()
{
    char name[SIZE];
    
    student a_student;
    roster a_roster;
    
    do
    {    
        cout <<"Please enter the student name: ";
        cin.get(name, SIZE, '\n'); cin.ignore(SIZE,'\n');
        if (a_student.create_student(name))
            if(!a_roster.add(a_student))
                cerr << "ERROR! Unable to add student!" << endl;
    }while(again());        
   
    if(!a_roster.display())
        cout << "Error roster is empty!" << endl;
        
    cout <<"Please enter the student name to find: ";
    cin.get(name, SIZE, '\n'); cin.ignore(SIZE,'\n');  
    if(a_roster.find(name, a_student))
    {
        cout << "We found!" << endl;
            if(!a_student.display())
                cout << "ERROR! Unable to display!" << endl;
    }
    else
    {
        cout << "No match found!" << endl; 
    }
}

bool again()
{
    bool condition;
    char answer;
    
    cout << "Add another student ? (Y/N)" << endl;
    cin >> answer;
    cin.ignore(100, '\n');
    
    if(answer == 'Y')
        condition = true;
    else
        condition = false;
    
    return condition;
};
