// Author: DeJa Barclay, Grady Katie, Haley Benson, Ronaldo Amaya
// Date: 11/11/2019
// Assignment Number: 5
// CS2308.003 Fall 2019
// Instructor: Jill Seaman
//
// Represents a list of floating point values.
// Supports adding numbers from a file, displaying and sorting lists of numbers,
// counting and displaying the values greater than n, summing, and finding the
// max and min values and their positions.

#include "FloatList.h"
#include<iostream>
#include <string>
#include <fstream>

//*************************************************
//FloatList: creates an empty list
//*************************************************
FloatList::FloatList()
{
    head = NULL;
}

//*************************************************
// ~FloatList: deallocates all the nodes in the
//list.
//*************************************************

FloatList::~FloatList()
{
    ListNode *p; // traversal ptr
    p = head; //start at head of list
    while (p) {
    delete p; // delete current
    p = p->next; // advance ptr
 }

}

//*************************************************
 //readFile(string f): adds numbers to the end of the list that are read
 //in from a filenamed f. Returns false if the file
 //cannot be opened (otherwise returns true).
//*************************************************

bool FloatList::readFile(string filename)
{
    ifstream fin;
    fin.open(filename.c_str());
    if (!fin)
    {
        return false;
    }

    float x;

    while(!fin.eof())
    {
        fin >> x;
        ListNode *newNode = new ListNode;
        newNode->value = x;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            ListNode *p=head; //p points to what head points to
            while (p->next!=NULL) {
                p = p->next; //makes p point to the next node
            }
            p->next = newNode;
        }
    }
return true;
}

//*************************************************
//displayList(): displays the numbers in the list
// to the screen
//*************************************************

void FloatList::displayList()
{
    ListNode *p =head;

    while(p != NULL)
    {
        cout << p->value << endl;
        p=p->next;
    }
}

//*************************************************
//sum(): returns the sum of all the values in the list.
//*************************************************

float FloatList::sum()
{
    float sum = 0;

    ListNode *p =head;
    while(p != NULL)
    {
        sum +=p->value ;
        p=p->next;
    }

    return sum;
}

//*************************************************
//countOver(float x): returns the total number of
//values in the list that are greater than or equal to x.
//*************************************************

int FloatList::countOver(float x)
{
    float total =0;
    ListNode *p =head;

    while(p != NULL)
    {
       if (p->value > x || p->value == x )
        {
            total++;
            p=p->next;
            //cout <<  total;
        }
        else
            p=p->next;
    }

    return total;
}

//*************************************************
//displayOver(float x, int s) Determines the positions
//of the values in the list that are greater than or equal
// to x. Adds the offset value s to each position and outputs them.
//*************************************************

void FloatList::displayOver(float x, int s)
{
    ListNode *p =head;
    int count = 0;

    while(p != NULL)
    {
        if(p->value >= x)
        {
            cout << count + s << endl;
            p = p->next;
            count++;
        }
        else
        {
            p = p->next;
            count++;
        }


    }
}

//*************************************************
//maxValueWithPosition(int &p) Returns the maximum
//value in the list. Sets p to the position of this value.
//*************************************************

float FloatList::maxValueWithPosition(int &p)
{
    ListNode *cursor =head;
    float temp = 0;
    int counter = 0;
    p = 0;

    while(cursor != NULL)
    {
        if(cursor->value > temp)
        {
            temp = cursor->value;
            cursor= cursor->next;
            counter++;
            p = counter;
        }
        else
        {
            cursor= cursor->next;
            counter++;
        }

    }
    return temp;

}

//*************************************************
//minValueWithPosition(int &p) Returns the minimum
//value in the list. Sets p to the position of this value.
//*************************************************

float FloatList::minValueWithPosition(int &p)
{
    ListNode *x =head;
    float result = maxValueWithPosition(p);
    int counter = 0;
    p = 0;

    while(x != NULL)
    {
        if(x->value < result)
        {
            result = x->value;
            x= x->next;
            counter++;
            p = counter;
        }
        else
        {
                x= x->next;
                counter++;
        }

    }
    return result;
}

//*************************************************
//Define a ListNode * to be the head of a new list (make it the empty list).
//2. Repeat for every node in the original list:
//a. Remove the first node from the original list
//b. Insert this node into the proper position in the new list:
//i. Find the node before and after the insertion point in the new list
//stop at the first node larger than the one you need to insert.
//ii. Modify the new list to insert the old node into the new list
//3. make the old head pointer (now empty) point to the new list!
//*************************************************

void FloatList::sort()
{
    ListNode *newNode = head;

}









