// Author: DeJa Barclay, Grady Katie, Haley Benson, Uyen Nguyen, Christian Cisnernos
// Date: 11/20/2019
// Assignment Number: 6
// CS2308.003 Fall 2019
// Instructor: Jill Seaman
//
#include <string>
#include "Queue.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;


struct Category
{
    int Tsize;
    string name;
    int numPeople;
};

int main ()
{
    //Category train;
    Category Array[100];
    int total =0;
    int elementCount = 0;
    int totalRiders =0; // total on roller coaster

    ifstream fin;
    fin.open("riders.txt");
    if (!fin)
    {
        return -1;
    }
    int numSeats;
    fin >> numSeats;
    while(!fin.eof()) // store iteams in array of strucs
    {

        fin >> Array[elementCount].name;
        //cout << Array[i].name;
        fin >> Array[elementCount].numPeople;
        //cout << Array[i].numPeople;
        Array[elementCount].Tsize = numSeats;
        totalRiders+=  Array[elementCount].numPeople;
        elementCount++;

    }
    fin.close();

    Queue train;
    int tempSIZE=0;
    int numTrain =0;
    //train.size();
    for(int i =0; i < elementCount; i++)
    {
        enqueue : //goto

        if(tempSIZE + Array[i].numPeople <= elementCount )
        {
            tempSIZE += Array[i].numPeople;

                for(int j = 0; j < Array[i].numPeople; j++)
                {
                    train.enqueue(Array[i].name + " " + to_string(j+1));
                }

                if(i == elementCount - 1)
                    goto dequeue;
        }
        else
        {
            dequeue:
            numTrain++;
            cout << "Train #" << numTrain <<endl; //print out people on coaster
            cout << "--------------" << endl;
            do
            {
                cout << train.dequeue() <<endl;
                tempSIZE--;
            }
            while(tempSIZE>0) ;

            cout << endl;

            if(i == elementCount - 1) break;
            goto enqueue;

        }
    }


        //train.enqueue(Array[j].name);

  endd:

    cout << "Total Riders: " << totalRiders << endl;
    cout << "Total Trains: " << numTrain << endl;



}
