//Authors DeJa Barclay, Haley Benson
// Date: 10/23/2019
// Assignment Number:4
// CS 2308.003 Fall 2019
// Instructor: Jill Seaman
//
// Driver to test the Question class.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

#include "Question.h"

int main()
{
    Question q[5];
    //Question q1;
    //const int numQuestions = 5;
    char tempKey;
    string temp;
    string tempAr[4];
    ifstream fin;
    fin.open("questions.txt");
    if (!fin)
    {
        cout << "could not open file" << endl;
        return -1;
    }

    for(int i = 0; i < 5; i++ )
    {
        getline(fin,temp);

        q[i].setStem(temp);
        getline(fin,tempAr[0]);
        getline(fin,tempAr[1]);
        getline(fin,tempAr[2]);
        getline(fin,tempAr[3]);
        q[i].setAnswers(tempAr);

        fin >> tempKey;
        q[i].setKey(tempKey);
        fin.ignore();
    }



    for(int i = 0; i < 5; i++ )
    {
        q[i].getStem();
    }

     char answer[5];
    //Displays the Question and Answers/ Answers users enter
    for(int i = 0; i < 5; i++)
    {
        string result = q[i].ask();
        cout << result << endl;
        cout << "Your answer (enter the letter A-D): ";
        cin >> answer[i];
        cout << " " << endl;
    }

    //Display the correct answers
    cout << "Answers: " << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << q[i].getKey() << " ";
    }

    cout << " " << endl;

    // The total number of correct answers
    int count = 0;

    //check if answers are correct
    for(int i = 0; i < 5; i++)
    {
        if(answer[i] == q[i].getKey())
        {
            count ++;

        }
    }

    cout << "Your score out of 5: ";
    cout << count;
    for(int i = 0; i < 5; i++)
    {
        q[i].shuffle();
    }
}
