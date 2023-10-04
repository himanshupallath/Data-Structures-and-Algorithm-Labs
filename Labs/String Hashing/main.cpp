/*
 * Name: Himanshu Pallath
 * Date Submitted:3/5/2023
 * Lab Section: 001
 * Assignment Name: Lab 5 Spell Checker Using a Hash Table
 */
 
 #include "stringset.h"
 #include <iostream>
 #include <fstream>
 
 void testStringset(Stringset& words);
 void loadStringset(Stringset& words, string filename);
 vector<string> spellcheck(const Stringset& words, string word);
 
//  int main()
//  {
//      Stringset wordlist;
//      testStringset(wordlist);
//      return 0;
//  }
 
 void testStringset(Stringset& words)
 {
     string choice;
     string word;
     do
     {
         cout << "I: insert word" << endl;
         cout << "F: find word" << endl;
         cout << "R: remove word" << endl;
         cout << "P: print words in stringset" << endl;
         cout << "Q: quit" << endl;
         cin >> choice;
         switch (choice[0])
         {
             case 'I':
             case 'i':
                cout << "Enter word to insert: ";
                cin >> word;
                words.insert(word);
                break;
             case 'F':
             case 'f':
                cout << "Enter word to find: ";
                cin >> word;
                if (words.find(word))
                {
                    cout << word << " in stringset" << endl;
                }
                else
                {
                    cout << word << " not in stringset" << endl;
                }
                break;
             case 'R':
             case 'r':
                cout << "Enter word to remove: ";
                cin >> word;
                words.remove(word);
                break;
             case 'P':
             case 'p':
                vector<list<string>> t = words.getTable();
                int numWords = words.getNumElems();
                int tSize = words.getSize();
                for(int i=0; i<tSize; ++i)
                {
                    list<string>::iterator pos;
                    for (pos = t[i].begin(); pos != t[i].end(); ++pos)
                    {
                        cout << *pos << endl;
                    }
                }
                cout << "Words: " << numWords << endl;
         }
     } while (choice[0] != 'Q' && choice[0] != 'q');
 }
 
 void loadStringset(Stringset &words, string filename) {
     //Implement this function
     ifstream infile;
     infile.open(filename);     // Opens the file
     string word;
     // Reads the file until the end
     while (infile >> word) {
         words.insert(word);    // Inserts the word into the stringset
     }
     infile.close(); 
 }
 
 vector<string> spellcheck(const Stringset &words, string word){
     vector<string> suggestions;    // Vector to store suggestions
     string alphabet = "abcdefghijklmnopqrstuvwxyz"; // Alphabet to check for suggestions
     // Checks for suggestions by replacing each letter in the word with each letter in the alphabet
     for (int i = 0; i < word.length(); i++) {
        string newWord = word;
        for (int j = 0; j < alphabet.length(); j++) {
            newWord[i] = alphabet[j];
            // Checks if the new word is in the stringset and if it is not the same as the original word
            if (words.find(newWord) && newWord != word) {
                suggestions.push_back(newWord); // Adds the new word to the suggestions vector
            }
        }
     }
     return suggestions;   // Returns the suggestions vector
 }
