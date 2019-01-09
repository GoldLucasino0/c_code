#include <cstdlib>
#include <iostream>
#include "test.h"
#include <time.h>
using namespace std;

int main(int argc, char** argv) 
{
    Node *tail;
    Node* head = new Node();

    srand(time(NULL));
    int size = (rand() % 100) + 5;
    int total = 0;
    int counter = 0;
    cout << "The total size is: " << size << endl;

    head->setValue(0);
    tail = head;
    Node *newNode = new Node;
    for (int i = 1; i < size; i++)
    {   
        Node *newNode = new Node;
        newNode->setValue(i);
        newNode->setNext(NULL);
        tail->setNext(newNode);
        tail = newNode;
    }   

    cout << head->getNext()->getValue();

    Node* current = head;
    while (current!=NULL)
    {   
        counter += current->getValue();
        cout << current->getValue();
        current = current->getNext();
        total++;
    }   

    cout << "Tracked " << total << " nodes, with a total count of " << counter << endl;

    cout << "Deleted " << total << " nodes. We're done!" << endl;

    return 0;
}
