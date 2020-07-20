// Author: DeJa Barclay, Grady Katie, Haley Benson, Uyen Nguyen, Christian Cisnernos
// Date: 11/20/2019
// Assignment Number: 6
// CS2308.003 Fall 2019
// Instructor: Jill Seaman
//

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

//******************************************************
//  Creates the class Queue  and its variables
//******************************************************

class Queue {
private:
    const static int QUEUESIZE = 100;  // capacity of queue

    string queueArray[QUEUESIZE]; // in a circular queue:
    int front;  // Subscript of the element at the front of the queue
    int rear;  // Subscript of the element at the rear of the queue
    int numItems;// Number of items in the queue
public:
    Queue() {front = 0; rear = -1; numItems = 0;};
    void enqueue(string); //must wraparound when end of array encountered
    string dequeue();     //must wraparound when end of array encountered
    bool isEmpty();
    bool isFull();
    void size();  //returns the number of elements in the queue
};

//******************************************************
// Dequeue removes the value at the front of the *
// queue and returns the value. *
//******************************************************

string Queue::dequeue()
{
    assert(!isEmpty());

    string result = queueArray[front];
    front = (front+1)%QUEUESIZE;
    numItems--;

    return result;
}

//******************************************************
// Enqueue inserts a value at the rear of the queue. *
//******************************************************

void Queue::enqueue(string name)
{
    assert(!isFull());

    rear = (rear+1)%QUEUESIZE;
    queueArray[rear] = name;
    numItems++;
    //cout << "en" <<endl;
}

//******************************************************
// isEmpty returns true if the queue is empty, *
// otherwise false. *
//******************************************************

bool Queue::isEmpty()
{
    return numItems==0;
}

//******************************************************
// isFull returns true if the queue is full, otherwise *
// false. *
//******************************************************

bool Queue::isFull()
{
    return numItems==QUEUESIZE;
}

//******************************************************
// Displays the size of the array and iteams in array
//
//******************************************************

void Queue:: size()
{

     int i=front;
    for (int c=0; c<numItems;  c++)
    {
        cout << queueArray[i] << " ";
        i=(i+1)%QUEUESIZE;
    }
    cout << endl;
}
