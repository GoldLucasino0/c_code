#include <iostream>
#include "heap.h"
using namespace std;

/* arrange values in array a in ascending order
param a: the array
param size: the length of array (# of element)
*/
void heapsort(int a[], int size)
{
        Heap<int> heapInt(a, size);
        for (int i=size-1;i>=0;i--)
                a[i] = heapInt.RemoveRoot();
}

int main()
{
        int data[5]={1,2,3,4,5};
        Heap<int> intHeap (data, 5); 

        if (!intHeap.IsHeap())
                cout <<"Something is wrong!\n";

        //Insert a new element, and test heap property
    

        //Test RemoveRoot.
    

        //Test Modify() to a larger value, to a smaller value 


        //Test heapsort 
}
