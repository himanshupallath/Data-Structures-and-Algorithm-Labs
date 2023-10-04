/*
 * Name: Himanshu Pallath
 * Date Submitted: 1/27/2023
 * Lab Section: 001
 * Assignment Name: Lab 1: Linked List Based Stacks and Queues
 */
#pragma once

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>
class List{

 private:
  Node<T> * start; //pointer to the first node in this list
  int mySize;  //size (or length) of this list

 public:
  List();
  ~List();
  int size();
  bool empty();
  void insertStart(T);
  void insertEnd(T);
  void insertAt(T, int);
  void removeStart();
  void removeEnd();
  void removeAt(int);
  T getFirst();
  T getLast();
  T getAt(int);
  int find(T);

  //Print the name and this list's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> * iterator = start;
    while(iterator != nullptr){
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below
//Construct an empty list by initializig this list's instance variables
template <class T>
List<T>::List(){
  start = nullptr;
  mySize = 0;
}

//Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List(){
  Node<T> *tempNode;
  while (tempNode->next != nullptr) {
    tempNode = start;
    start = start->next;
    delete tempNode;
  }
}

//Return the size of this list
template <class T>
int List<T>::size(){
  return mySize;
}

//Return true if this list is empty
//Otherwise, return false
template <class T>
bool List<T>::empty(){
  if (size() == 0) {
    return true;
  }
  return false;
}

//Create a new node with value, and insert that new node
//into this list at start
template <class T>
void List<T>::insertStart(T value){
  Node<T> * newNode = new Node<T>(value);
  newNode->next = start;
  start = newNode;
  mySize++;
}

//Create a new node with value, and insert that new node
//into this list at end
template <class T>
void List<T>::insertEnd(T value){
  Node<T> * newNode = new Node<T>(value);
  if (start == nullptr) {
    start = newNode;
  } else {
    Node<T> * tempNode = start;
    while (tempNode->next != nullptr) {
      tempNode = tempNode->next;
    }
    newNode->next = nullptr;
    tempNode->next = newNode;
  }
  mySize++;
}

//Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j){
  Node<T> * tempNode = start;
  Node<T> * prevNode = tempNode;
  Node<T> * newNode = new Node<T>(value);
  int count = 0;
  if (j == 0) {
    insertStart(value);
    delete newNode;
  } else {
    while (count < j) {
      if (tempNode->next != nullptr) {
        prevNode = tempNode;
        tempNode = tempNode->next;
        count++;
      }
    }
    newNode->next = tempNode;
    prevNode->next = newNode; 
  }                                                                                                                                                                                                                                                                                                                                                      
  mySize++;
}

//Remove node at start
//Make no other changes to list
template <class T>
void List<T>::removeStart(){
  Node<T> *tempNode = start;
  start = start->next;
  tempNode = nullptr;
  mySize--;
}

//Remove node at end
//Make no other changes to list
template <class T>
void List<T>::removeEnd(){
  while (start->next->next != nullptr) {
    start = start->next;
  }
  start->next = nullptr;
  mySize--;
}

//Remove node at position j
//Make no other changes to list
template <class T>
void List<T>::removeAt(int j){
  Node<T> * tempNode = start;
  Node<T> * prevNode = tempNode;
  int count = 0;
  if (j == 0) {
    removeStart();
  } else {
    // Loops through the linked list until we get to the j index
    while (count < j) {
      if (tempNode->next != nullptr) {
        prevNode = tempNode;
        tempNode = tempNode->next;
        count++;
      }
    }
    // Removes the node from the list
    prevNode->next = tempNode->next; 
    tempNode = nullptr;
  }                                                                                                                                                                                                                                                                                                                                                      
  mySize++;
}

//Return the value of the first node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst(){
  Node<T> * tempNode = start;
  return tempNode->value;
}

//Return the value of the last node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast(){
  while (start->next != nullptr) {
    start = start->next;
  }
  return start->value;
}

//Return the value of the node at position j in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j){
  Node<T> * tempNode = start;
  for (int i = 0; i < j; i++) {
    tempNode = tempNode->next;
  }
  return tempNode->value;
}

//Return the position of the (first) node whose value is equal to the key
//Otherwise, return -1
template <class T>
int List<T>::find(T key){
	int index = 0;            
  Node<T> *tempNode = start;
  while (tempNode->next != nullptr){
    if (tempNode->value == key){         
      return index;               
    }
    tempNode = tempNode->next;
    index++;  
  }
	return -1;           
}
