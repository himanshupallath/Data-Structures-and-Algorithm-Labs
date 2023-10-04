/*
 * Name: Himanshu Pallath
 * Date Submitted: 4/15/2023
 * Assignment Name: Min-Heap Implementation
 */

#include <iostream>
#include <vector>
#include "minHeap.h"

using namespace std;

// This is the constructor that builds the heap from bottom-up
minHeap::minHeap(vector<int> data) {
    heap = data;
    // build the heap from bottom-up
    for (int i = heap.size() - 1; i >= 0; i--) {
       siftDown(i);
    }
}

// This function inserts a value into the heap
void minHeap::insert(int value) {
    heap.push_back(value);
    siftUp(heap.size() - 1);
}

// This function removes the minimum value from the heap
int minHeap::removeMin() {
    int min = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    siftDown(0);
    return min;
}

// This function maintains the heap property by sifting up
void minHeap::siftUp(int pos) {
    if (pos == 0) {
        return;
    }
    int parent = (pos - 1) / 2;
    if (heap[parent] > heap[pos]) {
        int temp = heap[parent];
        heap[parent] = heap[pos];
        heap[pos] = temp;
        siftUp(parent);
    }
}

// This function maintains the heap property by sifting down
void minHeap::siftDown(int pos) {
    int left = 2 * pos + 1;
    int right = 2 * pos + 2;
    if (left >= heap.size()) {
        return;
    }
    int min = left;
    if (right < heap.size() && heap[right] < heap[left]) {
        min = right;
    }
    if (heap[pos] > heap[min]) {
        int temp = heap[pos];
        heap[pos] = heap[min];
        heap[min] = temp;
        siftDown(min);
    }
}

 