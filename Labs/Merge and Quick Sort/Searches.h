/*
 * Name: Himanshu Pallath
 * Date Submitted: 2/20/2023
 * Lab Section: 001
 * Assignment Name: Lab 4: Searching and Sorting
 */

#pragma once
#include <iostream>
#include <vector>
using namespace std;

/**
    This function implements the linear search algorithm by looping through the array
    and checking if the current element is equal to the target. If it is, return the
    index of the element. If it is not, continue looping through the array. If the
    target is not found, return -1.
    @param data - the vector to search through
    @param target - the value to search for
    @return - the index of the target if found, -1 if not found
*/
template <class T>
int linearSearch(std::vector<T> data, T target){
    // Loop through the vector and check if the current element is equal to the target
    for (unsigned int i = 0; i < data.size(); i++) {
        if (data[i] == target) {
            return i;
        }
    }
    return -1;
}

/**
    This function implements the binary search algorithm by looping through the array
    and checking if the current element is equal to the target. If it is, return the
    index of the element. If it is not, continue looping through the array. If the
    target is not found, return -1.
    @param data - the vector to search through
    @param target - the value to search for
    @return - the index of the target if found, -1 if not found
*/
template <class T>
int binarySearch(std::vector<T> data, T target){
    int lowIndex = 0;               // index of the first element
    int highIndex = data.size();    // index of the last element
    int size = data.size();         // size of the vector
    // Loop through the vector and check if the current element is equal to the target
    for (int i = 0; i < size; i++) {
        int midIndex = (highIndex + lowIndex) / 2;  // index of the middle element
        // If the target is greater than the middle element, set the low index to the middle index + 1
        if (data[midIndex] < target) {
            lowIndex = midIndex + 1;
        }
        // If the target is less than the middle element, set the high index to the middle index - 1
        if (data[midIndex] > target) {
            highIndex = midIndex - 1;
        }
        // If the target is equal to the middle element, return the middle index
        if (data[midIndex] == target) {
            return midIndex;
        }
    }
    return -1; // If the target is not found, return -1
}
