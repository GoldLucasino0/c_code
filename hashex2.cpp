// Gives hashcode for 5 strings
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
   //To declare a map of K, V pair
   //unsorted_map<K,V> setOfTypeT; 

    string word;
    //A word count 
    unordered_map<string, int> wordCnt;

    //enter 5 words 
    for (int i=0;i<5;i++)
    {   
        cout <<"Enter a word:";
        cin >> word;
        wordCnt[word]++;
          //use operator[] to access value for given key "word": i.e., increement count for word
          //the first accessing wordCnt[word], the value is set to 0
    }   

    for (auto & x: wordCnt)
        cout << x.first <<":"<<x.second <<endl;

    //Practice: You can try to write a code block to remove, lookup a word from the wordCnt
    //find(), count, erase, insert... 


    //Peek inside the implementation: hashtable
     //Display size (number of elements), number of buckets, load factor
        cout <<"\n---------------------------------------\n";
        unsigned size = wordCnt.size();
        cout << "There are " << size << " elements:\n";
        unsigned nbuckets = wordCnt.bucket_count();
        cout << "There are " << nbuckets << " buckets:\n";
        cout <<"Current load factor (size/bucket_count):"<<wordCnt.load_factor()<<endl;

        //Display the size of each bucket (i.e., the length of linked list in each entry of hash table)
        // and elements stored in each bucket
        for (unsigned i=0; i<nbuckets; ++i) {
                std::cout << "  bucket #" << i << " has " << wordCnt.bucket_size(i) << " elements:";
                for (auto & x : wordCnt)
                {   
                        if (wordCnt.bucket(x.first)==i)
                                cout <<x.first;
                }   
                cout <<endl;
        }

        cout <<"\n---------------------------------------\n";


        /************************************************
        //Display the hash policy
        ***********************************************/
        cout <<"When load factor reaches this value, the bucket size is increased and elements are rehashed.\n";
        cout <<"current Max_load_factor is" << wordCnt.max_load_factor()<<endl;
        cout <<"Do you want to change it?";
        char op;
        float loadFactor;
        cin >> op;
        if (op=='y')
        {
                        cout <<"Enter new load factor (a positive float value: ";
                        cin >> loadFactor;
                        wordCnt.max_load_factor(loadFactor);
                        cout <<"Max_load_factor is now " << wordCnt.max_load_factor()<<endl;
        }
        cout <<endl;



}
