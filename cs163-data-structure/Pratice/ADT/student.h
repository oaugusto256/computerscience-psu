#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class student
{
    public:
        student(void);
        //~student();
        
        int create_student(char * name);
        int display(void);
		
        int copy_student(const student & copy_from);
        int retrieve(char * matching_name, student & found);
        
    private:
        char * name;
};


