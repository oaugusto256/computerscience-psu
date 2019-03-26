#include "student.h"

student::student()
{
    name = NULL;
}

int student::create_student(char * name)
{
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
    
    return 1;
}

int student::display(void)
{
    cout << name << endl;
    return 1;
}

int student::copy_student(const student & copy_from)
{
    if(!copy_from.name)
        return 0;        
    
    if(name)
    {
        delete [] name;
        name = NULL;
    }
    
    if(copy_from.name)
    {
        name = new char[strlen(copy_from.name)+1];
        strcpy(name, copy_from.name);
    }
    
    return 1;
}

int student::retrieve(char * matching_name, student & found)
{
    if(!name || !matching_name)
        return 0;
    
    if(!strcmp(name, matching_name))
    {
        if(found.name)
        {
            delete [] found.name;
            found.name = NULL;
        }
        
        if(name)
        {
            found.name = new char[strlen(matching_name)+1];
            strcpy(found.name, name);
        }
    }
    
    return 1;
}

