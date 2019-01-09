// similar to final.cpp, but for chars
// Is not running final output correctly for some reason. 
#include <iostream>
#include <string>
using namespace std;

class node_type
{
public:
    node_type(char value, node_type *p) 
    {   
        data = value;
        ptr   = p;
    }   
    char data;
    node_type *ptr;
};

void delete_list(node_type **start, char key)
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
        cout << list->data << " ";
        list = list->ptr;
    }   
    cout << endl;
}

int main()
{
    node_type *node = new node_type('a', new node_type('b',
                     new node_type('c', new node_type('d',
                     new node_type('e', NULL)))));

    cout << "Print Linked List: ";
    print_list(node);
    cout << "Removed Node 'c': ";
    delete_list(&node, 'c');
    print_list(node);

    return 0;
}
