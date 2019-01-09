#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main(){
   //To declare a set of elements of a type T:
   //unsorted_se<T> setOfTypeT; 

    string word;
    //a set of strings 
    unordered_set<string> setOfWords;
    //What hashfunction is used? If you don't specify, it's the 
    //hash<string>, which is a function object, in which
    //operator() is overloaded 

    //Try out hash<string> function object
    cout <<"Enter a string: ";
    cin >> word;
    cout <<"hashcode for "<<word<<"is: "<<hash<string>()(word)<<endl;
                                                   //^^ call () function 

    cout <<"hashcode for character A: "<<hash<char>() ('A')<<endl;
    cout <<"hashcode for character B: "<<hash<char>() ('B')<<endl;
    cout <<"hashcode for character C: "<<hash<char>() ('C')<<endl;

    cout <<"hashcode for double 3.1415:"<<hash<double>() (3.1415)<<endl;

    //enter 5 words 
    for (int i=0;i<5;i++)
    {   
        cout <<"Enter a word: ";
        cin >> word;
        setOfWords.insert (word);
        cout <<"hashcode for "<<word<<hash<string>()(word)<<endl;
    }   

    for (string s: setOfWords)
        cout << s <<endl;


    //Practice: You can try to write a code block to remove, lookup a word from the set


    //Peek inside the implementation: hashtable
     //Display size (number of elements), number of buckets, load factor
        cout <<"\n---------------------------------------\n";
        unsigned size = setOfWords.size();
        cout << "There are " << size << " elements:\n";
        unsigned nbuckets = setOfWords.bucket_count();
        cout << "There are " << nbuckets << " buckets:\n";
        cout <<"Current load factor (size/bucket_count):"<<setOfWords.load_factor()<<endl;

        //Display the size of each bucket (i.e., the length of linked list in each entry of hash table)
        // and elements stored in each bucket
        for (unsigned i=0; i<nbuckets; ++i) {
                std::cout << "  bucket #" << i << " has " << setOfWords.bucket_size(i) << " elements:";
                for (string s : setOfWords)
                {
                if (setOfWords.bucket(s)==i)
                                cout <<s;
                }
                cout <<endl;
        }

        cout <<"\n---------------------------------------\n";


        /************************************************
        //Display the hash policy
        ***********************************************/
        cout <<"When load factor reaches this value, the bucket size is increased and elements are rehashed.\n";
        cout <<"current Max_load_factor is" << setOfWords.max_load_factor()<<endl;
        cout <<"Do you want to change it? ";
        char op;
        float loadFactor;
        cin >> op;
        if (op=='y')
        {
                        cout <<"Enter new load factor (a positive float value: ";
                        cin >> loadFactor;
                        setOfWords.max_load_factor(loadFactor);
                        cout <<"Max_load_factor is now " << setOfWords.max_load_factor()<<endl;
        }
        cout <<endl;



}
