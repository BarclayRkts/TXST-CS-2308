//Authors DeJa Barclay, Haley Benson
// Date: 10/23/2019
// Assignment Number:4
// CS 2308.003 Fall 2019
// Instructor: Jill Seaman
//
// Functions File.


#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Question.h"

using namespace std;

string answers[4],tempAnswer[4];

//***********************************************************
// Question: sets steam and answers choices to empty
//
// returns: (void)
//***********************************************************
Question::Question()
{
    string stem = "";

    for(int i = 0; i < 4; i++)
    {
        answers[i] = "";
    }

    char key = 'X';

}
//***********************************************************
// Question::Question - sets steam and answers choices to empty
//
// returns: (void)
//***********************************************************
Question::Question(string tempStem,string tempAnswer[], char tempKey)
{
    stem = tempStem;

    for(int i = 0; i < 4; i++)
    {
        answers[i] = tempAnswer[i];
    }

    key = tempKey;
}

//***********************************************************
// setStem: sets a quiz question
//
// question: the question
// returns: (void)
//***********************************************************
void Question::setStem( string tempStem)
{
    stem = tempStem;
}

//***********************************************************
// getStem: get the quiz question
//
// returns: the quiz question
//**********************************************************
string Question::getStem()const
{
    return stem;
}
//***********************************************************
// setAnswers: sets the 4 multiple choice answers
//
// answers[]: an array with 4 elements showing the multiple choice options
// returns: (void)
//***********************************************************

void Question::setAnswers(string tempAnswer[])
{
    for(int i = 0; i < 4; i++)
    {
         answers[i] = tempAnswer[i];
    }
}
//***********************************************************
// getAnswer: gets a particular quiz question multiple choice answer
//
// i: the index of the question option
// returns: the i multiple choice option
//**********************************************************

string Question::getAnswer(int i)
{
        return answers[i];
}
//***********************************************************
// setKey: sets the answer key
//
// _key: the correct answer key
// returns: (void)
//***********************************************************

void Question::setKey(char tempKey)
{
    key = tempKey;
}

//***********************************************************
// Question::getKey gets the answer key
//
// returns: the answer key
//***********************************************************
char Question::getKey()const
{
    return key;
}

//***********************************************************
// Question::ask Compose the stem and answers (but not the key), each on a
//separate line, as a string. Insert the letter A. before the
//first answer, B. before the second answer,and so on (you can
//use char(‘A’+i) to compute the letter for the question at
//index i). Put a period and space after each letter! Return the string.
//***********************************************************

string Question::ask()
{
    string fullStem;

    fullStem = stem;
    fullStem += "\n";
    char letters[4] = {'A', 'B', 'C', 'D'};
    for(int i = 0; i < 4; i++)
    {
        fullStem += letters[i];
        fullStem += ".";
        fullStem += getAnswer(i);
        fullStem += "\n";

    }
    return fullStem;

}
//***********************************************************
//Question::shuffle reorder the answers, in a random way.
// Shuffle is called in the main
//***********************************************************

void Question::shuffle()
{
    char k = getKey();
    int tempk = k-'A';
    //cout << "tempk value " << tempk << endl;
    int spot;
    int newSpot;
    char tempArray[] = {'A', 'B', 'C', 'D'};
    int index =0;
    bool flagOne = false;

    while(index<4&&!flagOne)
    {
      flagOne = true;
      spot = index;
    }
    index++;

    string answerSpot = answers[spot];


    for(int i =0; i < 4; i++)
    {

      newSpot = rand()%4;
      //cout << " newspot " << newSpot << endl;
      if(newSpot == tempk)
      {
          //cout << "inside if" << endl;
          tempk = i;
          char key1 = tempk + 'A';
          //cout << "Vlaue of new key " << key1 << endl;
          setKey(key1);
      }
      else if(tempk == i)
      {
          //cout << "inside else" << endl;
          tempk = newSpot;
          char key1 = tempk + 'A';
          //cout << "Vlaue of new key " << key1 << endl;
          setKey(key1);
      }
       swap(answers[i], answers[newSpot]);
       //cout << getKey() << endl << endl;
    }



}


