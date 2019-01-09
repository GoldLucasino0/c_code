// Code that removes the middle integer in an array

#include <iostream>
#include <string>
using namespace std;

class node_type
{          
    public:                             
        node_type(int value, node_type *p)
        {   
            data = value; 
            ptr   = p;
        }        
        int data; 
        node_type *ptr;
};
    
void delete_list(node_type **start, int key)
{
    node_type *current, **previous;    
    previous = start;
    current  = *start;

    while((current != NULL) && (key != current->data))
    {    
        previous = &current->ptr;    
        current  = current->ptr;   
    }   

    if (current != NULL)
    {   
        *previous = current->ptr;  
        delete current;
    }   
    return;
}

void print_list(node_type *list) 
{    
    while (list != NULL)    
    {   
        cout << list->data << ' ';
        list = list->ptr;    
    }   
    cout << endl;
}

int main()
{
    node_type *node = new node_type(5, new node_type(10, 
                      new node_type(7, new node_type(14,
                      new node_type(23, NULL)))));

    cout << "Print Linked List: ";
    print_list(node);
    cout<< endl;
    cout << "Removed Node 7: ";
    delete_list(&node, 7);
    print_list(node);

    return 0;
