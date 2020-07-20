
// File Name: Stack.h
//
// Author: DeJa Barclay, Grady Katie, Haley Benson, Uyen Nguyen, Christian Cisnernos
// Date: 11/10/2019
// Assignment Number: 6
// CS 2308.003 Fall 2019
// Instructor: Jill Seaman

#include<cassert>
#include<string>

using namespace std;

class Stack {
    private:
    struct Node
    {
        string str;
        Node* next;
    };

 Node* head; // pointer to top

    public:
        Stack() { head = NULL; } // empty stack
        void push(string x) ;
        string pop();
        bool isEmpty() { return head == NULL;}
};

//*************************************************
// Push pushes the argument onto *
// the stack. *
//*************************************************
inline void Stack::push(string x)
{

     Node *temp = new Node; //allocate new node
     temp->str = x;


     temp->next = head; //insert at head of list
     head = temp;

}
//****************************************************
//  pops the value at the top of the stack off, and
//  returns it.
//****************************************************
inline string Stack::pop()
{
     assert(!isEmpty());

     string result = head->str; //retrieve front item
     Node * temp = head;
     head = head->next; //head points to second item
     delete temp; //deallocate front item

     return result;
}
