/*
 * Name: Himanshu Pallath
 * Date Submitted: 3/14/2023
 * Assignment Name: Single Word Anagram Finder
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> loadWordlist(string filename);

/*Implement the following function:
  anagram() takes a word (string) and a wordlist of all words (vector of strings)
  and builds a dictionary/map where the key is a specific number of times each
  letter occurs in a word and the associated value is a vector of strings
  containing all words using those letters (anagrams).
  The value returned is a vector of strings containing the corresponding
  set of anagrams
*/
vector<string> anagram(string word, vector<string> wordlist);

// int main()
// {
//     vector<string> words;
//     vector<string> anagrams;
//     string inputWord;
//     words=loadWordlist("wordlist.txt");
//     cout << "Find single-word anagrams for the following word: ";
//     cin >> inputWord;
//     anagrams = anagram(inputWord, words);
//     for (int i=0; i<anagrams.size(); i++)
//     {
//         cout << anagrams[i] << endl;
//     }
//     return 0;
// }

vector<string> loadWordlist(string filename)
{
    vector<string> words;
    ifstream inFile;
    string word;
    inFile.open(filename);
    if(inFile.is_open())
    {
        while(getline(inFile,word))
        {
            if(word.length() > 0)
            {
                words.push_back(word);
            }
        }
        inFile.close();
    }
    return words;
}

//Implement this function
/**
  This function takes a word (string) and a wordlist of all words (vector of strings)
    and builds a dictionary/map where the key is a specific number of times each
    letter occurs in a word and the associated value is a vector of strings.
    The value returned is a vector of strings containing the corresponding
    set of anagrams
    @param word the word to find anagrams for
    @param wordlist the list of words to search for anagrams
    @return a vector of strings containing the anagrams
*/
vector<string> anagram(string word, vector<string> wordlist) {
    vector<string> anagramList;     // vector to store anagrams
    // iterate through wordlist
    for (int i = 0; i < wordlist.size(); i++) {
        // check if word and wordlist[i] are the same length
        if (wordlist[i].length() == word.length()) {
            unordered_map<char, int> wordMap;      // map to store word
            unordered_map<char, int> wordlistMap;  // map to store wordlist[i]
            // iterate through word and wordlist[i]
            for (int j = 0; j < word.length(); j++) {
                wordMap[word[j]]++;    // increment value of key
                wordlistMap[wordlist[i][j]]++; // increment value of key
            }
            // check if wordMap and wordlistMap are the same
            if (wordMap == wordlistMap) {
                anagramList.push_back(wordlist[i]);
            }
        }
    }
    return anagramList;     // return vector of anagrams
}