/*
 * Name: Himanshu Pallath
 * Date Submitted:3/5/2023
 * Lab Section: 001
 * Assignment Name: Lab 5 Spell Checker Using a Hash Table
 */

#include <iostream>
#include "stringset.h"
using namespace std;

Stringset::Stringset() : table(4), num_elems(0), size(4) {}

//Used in test cases and testStringset() in main.cpp, do not modify
vector<list<string>> Stringset::getTable() const
{
    return table;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getNumElems() const
{
    return num_elems;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getSize() const
{
    return size;
}

void Stringset::insert(string word)
{
    //Implement this function
    hash<string> stringHash;
    if (!find(word)) {
        // if the num_elems is equal to the size, then we need to resize the table
        if (size == num_elems) {
            int newSize = size * 2; // double the size
            vector<list<string>> newTable;  // create a new table
            // add the new lists to the new table
            for (int i = 0; i < newSize; i++) {
                list<string> newList;
                newTable.push_back(newList);
            }
            // rehash the elements in the old table to the new table
            for (int i = 0; i < size; i++) {
                list<string> list = table[i];
                while (!list.empty()) {
                    int newIndex = stringHash(list.front()) % newSize;
                    newTable[newIndex].push_back(list.front()); // add the element to the new table
                    list.pop_front();
                }
            }
            table = newTable;   // set the old table to the new table
            size = newSize;    // set the size to the new size
        }
        // insert the word into the table
        int hashValue = stringHash(word) % size;
        num_elems++;    // increment the num_elems
        table[hashValue].push_back(word);
    }
}

bool Stringset::find(string word) const
{
    //Implement this function
    hash<string> stringHash;
    int hashValue = stringHash(word) % size;
    // iterate through the list at the hashValue index
    for (auto i = table[hashValue].begin(); i != table[hashValue].end(); i++) {
        // if the word is found, return true
        if (*i == word) {
            return true;   // found the word
        }
    }
    return false;  // did not find the word
}

void Stringset::remove(string word)
{
    //Implement this function
    hash<string> stringHash;
    int hashValue = stringHash(word) % size;
    // iterate through the list at the hashValue index
    for (auto i = table[hashValue].begin(); i != table[hashValue].end(); i++) {
        // if the word is found, remove it
        if (*i == word) {
            table[hashValue].erase(i); // remove the word
            break;
        }
    }
    num_elems--; // decrement the num_elems
}
