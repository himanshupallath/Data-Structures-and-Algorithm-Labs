/*
 * Name: Himanshu Pallath
 * Date Submitted: 3/20/2023
 * Lab Section: 001
 * Assignment Name: Lab 7
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <assert.h>

#include "binarySearchTree.h"

using namespace std;

void fix_size(Node *T)
{
  T->size = 1;
  if (T->left) T->size += T->left->size;
  if (T->right) T->size += T->right->size;
}

// insert key k into tree T, returning a pointer to the resulting tree
Node *insert(Node *T, int k)
{
  if (T == nullptr) return new Node(k);
  if (k < T->key) T->left = insert(T->left, k);
  else T->right = insert(T->right, k);
  fix_size(T);
  return T;
}

// returns a vector of key values corresponding to the inorder traversal of T (i.e., the contents of T in sorted order)
vector<int> inorder_traversal(Node *T)
{
  vector<int> inorder;
  vector<int> rhs;
  if (T == nullptr) return inorder;
  inorder=inorder_traversal(T->left);
  inorder.push_back(T->key);
  rhs=inorder_traversal(T->right);
  inorder.insert(inorder.end(), rhs.begin(), rhs.end());
  return inorder;
}

// return a pointer to the node with key k in tree T, or nullptr if it doesn't exist
Node *find(Node *T, int k) {
  //Implement Node *find(Node *T, int k)
  Node *tempPtr = nullptr;
  if (T == nullptr) {
    return nullptr;   // not found
  } else if (T->key == k) {
    return T;  // found
  } else if (k < T->key) {
    tempPtr = find(T->left, k); // search left subtree
  } else {
    tempPtr = find(T->right, k); // search right subtree
  }
  return tempPtr;
}

// return pointer to node of rank r (with r'th largest key; e.g. r=0 is the minimum)
Node *select(Node *T, int r)
{
  assert(T!=nullptr && r>=0 && r<T->size);

  //Implement Node *select(Node *T, int r)
  int rootRank = T->left ? T->left->size : 0;   // rank of root
  if (r == rootRank) {
    return T;     // found it
  } else if (r < rootRank) {
    return select(T->left, r);    // search left subtree
  } else if (r > rootRank){
    return select(T->right, r - rootRank - 1);   // search right subtree
  } else {
    return nullptr;  // not found
  }
}

// Join trees L and R (with L containing keys all <= the keys in R)
// Return a pointer to the joined tree.  
Node *join(Node *L, Node *R)
{
  // choose either the root of L or the root of R to be the root of the joined tree
  // (where we choose with probabilities proportional to the sizes of L and R)
  
  // Implement Node *join(Node *L, Node *R)
  Node *tempPtr = nullptr;
  if (L == nullptr) {
    return R;  // if L is empty, return R
  } else if (R == nullptr) {
    return L;  // if R is empty, return L
  } else {
    int Lsize = L->size;
    int Rsize = R->size;
    int totalSize = Lsize + Rsize;
    int randNum = rand() % totalSize;   // random number between 0 and totalSize-1
    if (randNum < Lsize) {  // if random number is less than Lsize, then choose L as root
      tempPtr = L;
      tempPtr->right = join(L->right, R);
    } else {  // if random number is greater than Lsize, then choose R as root
      tempPtr = R;
      tempPtr->left = join(L, R->left);
    }
    fix_size(tempPtr);  // fix size of tempPtr
    return tempPtr;     // return tempPtr
  }
}

// remove key k from T, returning a pointer to the resulting tree.
// it is required that k be present in T
Node *remove(Node *T, int k)
{
  assert(T != nullptr);
  
  //Implement Node *remove(Node *T, int k)
  Node *tempPtr = nullptr;
  if (T->key == k) {
    tempPtr = join(T->left, T->right);  // join left and right subtrees
    delete T;  // delete T
    return tempPtr; // return tempPtr
  } else if (k < T->key) {
    T->left = remove(T->left, k);   // search left subtree
  } else {
    T->right = remove(T->right, k); // search right subtree
  }
  return T;   // return T
}

// Split tree T on key k into tree L (containing keys <= k) and a tree R (containing keys > k)
void split(Node *T, int k, Node **L, Node **R)
{
  //Implement void split(Node *T, int k, Node **L, Node **R)
  if (T == nullptr) {
    // If T is null then both subtrees are null
    *L = nullptr; 
    *R = nullptr;
    return;
  } 
  if (T->key <= k) {  // if key of T is less than or equal to k
    split(T->right, k, &(T->right), R);
    *L = T;
  } else {  // if key of T is greater than k
    split(T->left, k, L, &(T->left));
    *R = T;
  }
  
  fix_size(T);
}

// insert key k into the tree T, returning a pointer to the resulting tree
Node *insert_random(Node *T, int k)
{
  // If k is the Nth node inserted into T, then:
  // with probability 1/N, insert k at the root of T
  // otherwise, insert_random k recursively left or right of the root of T
  
  ///Implement Node *insert_random(Node *T, int k)
  if (T == nullptr) {   // if T is null, then create a new node
    Node *newNode = new Node(k);
    fix_size(newNode);
    return newNode;
  }
  int randNum = rand() % (T->size + 1);   // random number between 0 and T->size
  if (randNum == 0) {   // if random number is 0, then insert k at the root of T
    Node* new_root = new Node(k);
    split(T, k, &new_root->left, &new_root->right);
    fix_size(new_root);
    return new_root;
  } else {
    if (k > T->key) {   // if k is greater than key of T, then insert k to the right of T
      T->right = insert_random(T->right, k);    
    } else { // if k is less than or equal to key of T, then insert k to the left of T
      T->left = insert_random(T->left, k);
    }
    fix_size(T);  // fix size of T
    return T;    // return T
  }
}

void printVector(vector<int> v)
{
    for (int i=0; i<v.size(); i++) {
      cout << v[i] << endl;
    }
}
/*
int main(void)
{
  vector<int> inorder;
  vector<int> A(10,0);
  
  // put 0..9 into A[0..9] in random order
  for (int i=0; i<10; i++) A[i] = i;
  for (int i=9; i>0; i--) swap(A[i], A[rand()%i]);
  cout << "Contents of A (to be inserted into BST):\n";
  printVector(A);
  
  // insert contents of A into a BST
  Node *T = nullptr;
  for (int i=0; i<10; i++) T = insert(T, A[i]);
  
  // print contents of BST (should be 0..9 in sorted order)
  cout << "Contents of BST (should be 0..9 in sorted order):\n";
  inorder=inorder_traversal(T);
  printVector(inorder);

  // test select
  for (int i=0; i<10; i++) {
    Node *result = select(T, i);
    if (!result || result->key != i) cout << "Select test failed for select(" << i << ")!\n";
  }

  // test find: Elements 0..9 should be found; 10 should not be found
  cout << "Elements 0..9 should be found; 10 should not be found:\n";
  for (int i=0; i<11; i++) 
    if (find(T,i)) cout << i << " found\n";
    else cout << i << " not found\n";

  // test split
  
  Node *L, *R;
  split(T, 4, &L, &R);
  cout << "Contents of left tree after split (should be 0..4):\n";
  inorder=inorder_traversal(L);
  printVector(inorder);
  cout << "Left tree size " << L->size << "\n";
  cout << "Contents of right tree after split (should be 5..9):\n";
  inorder=inorder_traversal(R);
  printVector(inorder);
  cout << "Right tree size " << R->size << "\n";
  
  // test join
  T = join(L, R);
  cout << "Contents of re-joined tree (should be 0..9)\n";
  inorder=inorder_traversal(T);
  printVector(inorder);
  cout << "Tree size " << T->size << "\n";
  
  // test remove
  for (int i=0; i<10; i++) A[i] = i;
  for (int i=9; i>0; i--) swap(A[i], A[rand()%i]);
  for (int i=0; i<10; i++) {
    T = remove(T, A[i]);
    cout << "Contents of tree after removing " << A[i] << ":\n";
    inorder=inorder_traversal(T);
    printVector(inorder);
    if (T != nullptr)
      cout << "Tree size " << T->size << "\n";
  }

  // test insert_random
  cout << "Inserting 1 million elements in order; this should be very fast...\n";
  for (int i=0; i<1000000; i++) T = insert_random(T, i);
  cout << "Tree size " << T->size << "\n";
  cout << "Done\n";
  
  return 0;
}
*/

