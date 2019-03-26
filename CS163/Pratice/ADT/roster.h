#include <iostream>
#include <cstring>
#include <cctype>
#include "student.h"
using namespace std;

struct node
{
    student a_student;
    node * next;
};

// Groups students together into a roster
class roster
{
    public:
        roster();
        // ~roster();
        
        int add(student & to_add);
        int find(char matching_name[], student & found);
        int display(void);
        
        int append(roster & source);
            
    private:
        node * head;
        node * tail;
};


