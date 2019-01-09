// Display the hashcode for 5 strings
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

struct stringHasher
{
        size_t operator() (const string & obj) const
        {   
                size_t sum=0;
                for (int i=0;i<obj.length();i++)
                        sum+=obj[i];
                return sum;
        }   
};

int main(){
   //To declare a set of elements of a type T:
   //unsorted_se<T> setOfTypeT; 

    string word;
    //a set of strings 
    unordered_set<string,stringHasher> setOfWords;
    

    //enter 5 words 
    //Is abc and cba hashed to same code? 
    for (int i=0;i<5;i++)
    {   
        cout <<"Enter a word:";
        cin >> word;
        setOfWords.insert (word);
        cout <<"hashcode for "<<stringHasher()(word)<<endl;
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
        cout <<"Do you want to change it?";
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
