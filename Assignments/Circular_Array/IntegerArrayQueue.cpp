#include "IntegerArrayQueue.h"

// This is the enqueue method that adds a value to the queue if it's not full
bool IntegerArrayQueue::enqueue(int value) {
    // This checks to see if the queue is full
    if (front == (back+2)%size) {
        return false;   // If full return false
    } else {    // If not full
        back = (back+1)%size;   // Increment back
        array[back] = value;    // Add the value to the queue
        printArrayQueue();
        cout<<endl;
        return true;            // Returns true
    }
}

// This is the dequeue method that removes a value from the queue if it's not empty
int IntegerArrayQueue::dequeue() {
    if (back == (front-2)%size) {   // If queue if empty
        return 0;   // Return 0 if empty
    } else {    // If not empty
        cout<<"Front: "<<front<<endl;
        cout<<"Back: "<<back<<endl;
        int value = array[front];   // Gets the value from front
        array[front] = 0;           // Set that value to zero
        front = (front+1)%size;     // Increments the front
        printArrayQueue();
        cout<<endl;
        return value;               // Returns the value
    }
}