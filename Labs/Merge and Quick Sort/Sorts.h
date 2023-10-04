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
    This function prints out the contents of a vector from the first index to the last index.
    @param lst - the vector to print
    @param first - the first index to print
    @param last - the last index to print
*/
template <class T>
void printVector(std::vector<T> lst, int first, int last) {
    cout<<"[";
    // Loop through the vector and print out each element
    for (int i = first; i < last; i++) {
        cout<<lst[i]<<", ";
    }
    cout<<"]"<<endl;
}

/**
    This function implements the merge sort algorithm by splitting the vector into two
    halves, sorting each half, and then merging the two halves together.
    @param lst - the vector to sort
    @return - the sorted vector
*/
template <class T>
vector<T> MergeSort(vector<T> half1, vector<T> half2) {
    vector<T> sorted;   // sorted vector
    int leftSize = half1.size();    // size of left half
    int rightSize = half2.size();   // size of right half
    int firstHalf = 0;    // index of first half
    int secondHalf = 0;   // index of second half
    
    // This loop compares the elements of the two halves and adds the smaller element
    while (firstHalf < leftSize && secondHalf < rightSize) {
        // If the element in the first half is smaller, add it to the sorted vector
        if (half1[firstHalf] <= half2[secondHalf]) {
            sorted.push_back(half1[firstHalf]);
            firstHalf++;
        } 
        // If the element in the second half is smaller, add it to the sorted vector
        else {
            sorted.push_back(half2[secondHalf]);
            secondHalf++;
        }
    }
    // This loop adds the remaining elements of the first half to the sorted vector
    while (firstHalf < leftSize) {
        sorted.push_back(half1[firstHalf]);
        firstHalf++;
    }
    // This loop adds the remaining elements of the second half to the sorted vector
    while (secondHalf < rightSize) {
        sorted.push_back(half2[secondHalf]);
        secondHalf++;
    }
    return sorted;  // return the sorted vector
}

/**
    This function is a helper function for the merge sort algorithm. It splits the vector
    into two halves and then calls the merge sort function to sort and merge the two halves.
    @param lst - the vector to sort
    @return - the sorted vector
*/
template <class T>
vector<T> split(std::vector<T> &lst) {
    vector<T> Half1;    // first half of the vector
    vector<T> Half2;    // second half of the vector

    // This loop splits the vector into two halves
    for (unsigned int i = 0; i < lst.size(); i++) {
        if (i < lst.size()/2) {
            Half1.push_back(lst[i]);    // add element to first half
        } else {
            Half2.push_back(lst[i]);    // add element to second half
        }
    }

    // This loop recursively calls the split function on the two halves
    if (Half1.size() != 1) {
        Half1 = split(Half1);
    }
    if (Half2.size() != 1) {
        Half2 = split(Half2);
    }

    // This loop calls the merge sort function to sort and merge the two halves
    vector<T> merged = MergeSort(Half1, Half2);
    return merged;  // return the sorted vector
}

/**
    This function runs the  merge sort algorithm. It calls the split function to split the 
    vector into two halves and then calls the merge sort function to sort and merge the two 
    halves.
    @param lst - the vector to sort
    @return - the sorted vector
*/
template <class T>
std::vector<T> mergeSort(std::vector<T> lst){
    vector<T> merged = split(lst);  // call the split function
    return merged;
}

/**
    This function implements the quick sort algorithm by choosing a pivot value, moving
    all values less than the pivot value to the left of the pivot, and all values greater
    than the pivot value to the right of the pivot. It then recursively calls the quick
    sort function on the left and right halves of the vector.
    @param lst - the vector to sort
    @param first - the first index of the vector
    @param last - the last index of the vector
*/
template <class T>
void QuickSort(std::vector<T> &lst, int first, int last) {
    // This loop recursively calls the quick sort function on the left and right halves
    if (last - first > 0) {
        int pivotIndex = first;         // pivot index
        T pivotValue = lst[first];      // pivot value
        T currentValue;                 // current value
        // This loop moves all values less than the pivot value to the left of the pivot
        for (int i = first; i < last+1; i++) {
            currentValue = lst[i];    // current value
            // If the current value is less than the pivot value, swap the current value
            if (currentValue < pivotValue) {
                pivotIndex++;
                // Swap the current value and the pivot value
                T tempValue = currentValue;
                lst[i] = lst[pivotIndex];
                lst[pivotIndex] = tempValue;
            }
        }
        // Swap the pivot value and the pivot index
        T tempValue = lst[first];
        lst[first] = lst[pivotIndex];
        lst[pivotIndex] = tempValue;
        // Recursively call the quick sort function on the left and right halves
        QuickSort(lst, 0, pivotIndex-1);
        QuickSort(lst, pivotIndex+1, last);
    }
}

/**
    This function runs the quick sort algorithm. It calls the quick sort function to sort
    the vector.
    @param lst - the vector to sort
    @return - the sorted vector
*/

template <class T>
std::vector<T> quickSort(std::vector<T> lst){
    QuickSort(lst, 0, lst.size()-1);    // call the quick sort function
    return lst;
}