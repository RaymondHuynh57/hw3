#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;
//
/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------

struct NotEight{
    bool operator()(const int& value){return value != 8;}
};

struct Odd{
    bool operator()(const int& value){return value & 2 != 0;}
};

struct Even{
    bool operator()(const int& value){return value % 2 == 0;}
};

int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);

    // Test out your linked list code


   Node* list = new Node(3, nullptr);
   list->next = new Node(2, nullptr);
   //list->next->next = new Node(6, nullptr);
   Odd o1;
   Even e1;
	Node* small = (Node*) &list; // set to a non-null address
	Node* large = (Node*) &list; // set to a non-null address
  Node* result = llfilter(list, e1);
	//llpivot(list, small, large, 3);
/*
  if(list == nullptr){
      cout << "LIST IS NULLPTR" << endl;
  }
*/
  cout << "RESULT: ";
  print(result);
  cout << endl;

 /*
  cout << "SMALL: ";
  print(small);
  cout << endl;

  cout << "LARGE: ";
  print(large);
  cout << endl;

  cout << "LIST: ";
  print(list);
  cout << endl;
*/
  return 0;

}
