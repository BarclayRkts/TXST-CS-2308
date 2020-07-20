//Authors DeJa Barclay, Haley Benson
// Date: 10/23/2019
// Assignment Number:4
// CS 2308.003 Fall 2019
// Instructor: Jill Seaman
//
// Class File
#include <string>

using namespace std;

class Question
{
    private:
        string stem;
        string answers[4];
        char key;

    public:
        Question();
        Question(string tempStem, string tempAnswer[], char tempKey);


        // Set and get the quiz question
        void setStem(string stem);
        string getStem() const;

        //Set and get an array of 4 possible multiple choice answers
        void setAnswers(string answer[4]);
        string getAnswer(int i) ;

        // Set and get the correct answer option
        void setKey(char key);
        char getKey() const;

        void shuffle();
        string ask();
};
