#include "roster.h"

roster::roster()
{
    head = tail  = NULL;
}

int roster::add(student & to_add)
{
    if(head == NULL)
    {
        head = tail = new node;
        tail->next = NULL;
    }
    else if(tail != NULL)
    {
        tail->next = new node;
        tail = tail->next;
        tail->next = NULL;
    }
    
    return (tail->a_student).copy_student(to_add);
}

int roster::find(char matching_name[], student & found)
{
    if(!head)
        return 0;
    
    bool success = false;
    node * current = head;
    
    while(current && !success)
    {
        success = current->a_student.retrieve(matching_name, found);
        current = current-> next;
    }
    
    return success;
}

int roster::display(void)
{
    node * current = head;
    if(current)
    {
        while(current)
        {
            cout << current->a_student.display();
            current = current->next;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}
