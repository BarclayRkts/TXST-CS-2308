//File Name: assign2_dnb53.cpp
//
// Author: DeJa Barclay
// Date: 9/25/2019
// Assignment Number: 2
// CS 2308 Fall 2019
// Instructor: Jill Seaman
//
//The program prompts user to input a number 1 -5 to select a option to complete,
// 1.Display the events sorted by ID number., 2.Display the events sorted by the time of event.,
// 3.Print the person's name given his/her ID number. 4.Compute the total time a person was in the
// lab given his/her ID number. and 5. Quit. The program prompts user to input a number 1 -5 to
// select a category to complete a option. then sorts or searches and displays the dataset
// then sorts or searches and displays the dataset appropriately .


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


const int ARRAY_SIZE = 100; // make case numbers named constants

struct data
{
    int ID;
    string name;
    int totalTime;
};

// Prototypes for each function

void sortID(data arr[], int);
void sortTime(data arr[], int);
void lookUp(data arr[], int);
void computeTotal(data arr[], int);

//*************************************************
// int main: reads the data from dataset.txt. Stores
// the data in the array of structures. Displays the
// Menu and reads in users choice.
// data arr[ARRAY_SIZE] = stores the values f
//*************************************************

int main()
{
    int counter =0;
    char seperator;
    int choice; // Menu Choice

    // Constants for the Menu options
    const int CHOICE1 = 1,
             CHOICE2 = 2,
             CHOICE3 = 3,
             CHOICE4 = 4,
             CHOICE5 = 5;


    data arr[ARRAY_SIZE];

    ifstream fin;
    fin.open("dataset.txt");

    if(!fin)
    {
        cout << " could not open file" << endl;
        return -1;
    }

    int hours = 0;
    int mins =0;

     while (fin >> arr[counter].ID)  //while the input of the next number succeeds
    {
        fin >> arr[counter].name;
        fin >> hours;
        fin >> seperator;
        fin >> mins;

        arr[counter].totalTime = hours * 60 + mins;

        counter++;
    }

   // Set up numeric output formatting.
   cout << fixed << showpoint << setprecision(2);

   do
   {
      // Display the menu.
      cout << "\n\t\tMenu\n\n"
           << "1. Display the events sorted by ID number.\n"
           << "2. Display the events sorted by the time of event.\n"
           << "3. Print the person's name given his/her ID number. \n"
           << "4. Compute the total time a person was in the lab given his/her ID number.\n"
           << "5. Quit" << endl
           << "Enter your choice: ";
      cin >> choice;

      // Validate the menu selection.
      while (choice < 1 || choice > 5)
      {
         cout << "Please enter a valid menu choice: ";
         cin >> choice;
      }

         // Respond to the user's menu selection.
         switch (choice)
         {
            case CHOICE1:
                sortID(arr, counter);
                break;
            case CHOICE2:
                sortTime(arr, counter);
                break;
            case CHOICE3:
                lookUp(arr, counter);
                break;
            case CHOICE4:
                computeTotal(arr, counter);
                break;
            case CHOICE5:
                cout << "Exiting the program.." << endl;
                break;

         }


      }
      while (choice != 5);
      return 0;
   }

//*************************************************
// sortID : This function performs an ascending
// order bubble sort on array. size is the number
// of elements in the array.
//*************************************************

void sortID(data arr[],int SIZE)
{
    int hrs;
    int minutes;
    bool swap;
    data temp;

    do
        {
        swap = false;
        for(int i = 0; i < (SIZE -1); i++)
        {
            if(arr[i].ID > arr[i+1].ID)
            {
                temp = arr[i];
                arr[i] = arr [i+1];
                arr[i+1] = temp;
                swap = true;
            }
        }
    } while (swap);


        for (int i = 0; i < SIZE; i++){
        cout << setw(6) << arr[i].ID << setw(12) ;
        cout << right << fixed << arr[i].name << setw(8) ;

        hrs = arr[i].totalTime/ 60;
        minutes = arr[i].totalTime % 60;
        if(minutes < 10){
          cout << right <<  hrs << ":" << "0" << minutes << endl;;
        }
        else{
            cout <<  hrs << ":" << minutes << endl;
        }
    }

}

//*************************************************
// sortTime: This function performs an ascending
// order bubble sort on array. size is the number
// of elements in the array.
// arr stores the data that is read into the array
//*************************************************

void sortTime(data arr[],int SIZE)
{
    int  hrs;
    int minutes;
    bool swap;
    data temp;

    do
        {
        swap = false;
        for(int i = 0; i < (SIZE -1); i++)
        {
            if(arr[i].totalTime > arr[i+1].totalTime)
            {
                temp = arr[i];
                arr[i] = arr [i+1];
                arr[i+1] = temp;
                swap = true;
            }
        }
    } while (swap);

        for (int i = 0; i < SIZE; i++){
         cout << setw(6) << arr[i].ID << setw(12) ;
        cout << right << fixed << arr[i].name << setw(8);

        hrs = arr[i].totalTime/ 60;
        minutes = arr[i].totalTime % 60;
        if(minutes < 10){
          cout <<  hrs << ":" << "0" << minutes << endl;;
        }
        else{
            cout <<  hrs << ":" << minutes << endl;
        }
    }

}


//*************************************************
// lookUp: Sorts by Time first then function performs a
// binary search on an integer array. array, which
// has a maximum of size elements,is searched for the
// number stored in empID. If the number is found, its
// array subscript is returned.
// arr stores the data that is read into the array
//*************************************************

void lookUp(data arr[],int SIZE)
{
     //int value;
    int empID;
    cout << "Enter the employee ID you wish to search for: ";
    cin >> empID;

    int first = 0,             // First array element
    last = SIZE - 1,       // Last array element
    middle,                // Mid point of search
    position = -1;         // Position of search value
    bool found = false;        // Flag

    bool swap;
    data temp;

        do
            {
            swap = false;
            for(int i = 0; i < (SIZE -1); i++)
            {
                if(arr[i].ID > arr[i+1].ID)
                {
                    temp = arr[i];
                    arr[i] = arr [i+1];
                    arr[i+1] = temp;
                    swap = true;
                }
            }
        } while (swap);


       while (!found && first <= last)
       {
          middle = (first + last) / 2;     // Calculate mid point
          if (arr[middle].ID == empID)      // If value is found at mid
          {
             found = true;
             position = middle;
          }
          else if (arr[middle].ID > empID)  // If value is in lower half
             last = middle - 1;
          else
             first = middle + 1;           // If value is in upper half
       }
        //cout << position << endl;
        if (!found)
        {
            cout << "No person found with ID: " <<  empID << endl;
        }
        else
        {
            cout << "The name of the person with ID " << empID
        << " is: " << arr[position].name << endl;

        }

}

//*************************************************
// lookUp: The function performs a binary search on
// an integer array. array, which has a maximum of
// size elements,is searched for the
// number stored in empID. The position of the
// empID is used to look for when the person arrives
// and exits the lab and computes the total time the
// person was in the lab.
// arr stores the data that is read into the array
//*************************************************

void computeTotal(data arr[],int SIZE)
{
    int totalLab;
    int twolab;
    int mins;
    int hours;
    int empID;
    cout << "Enter the employee ID you wish to search for: ";
    cin >> empID;

    int first = 0,             // First array element
       last = SIZE - 1,       // Last array element
       middle,                // Mid point of search
       position = -1;         // Position of search value
   bool found = false;        // Flag

   while (!found && first <= last)
   {
      middle = (first + last) / 2;     // Calculate mid point
      if (arr[middle].ID == empID)      // If value is found at mid
      {
         found = true;
         position = middle;
      }
      else if (arr[middle].ID > empID)  // If value is in lower half
         last = middle - 1;
      else
         first = middle + 1;           // If value is in upper half

   }

    twolab  =arr[position + 1].totalTime;

    totalLab = arr[position].totalTime - twolab;


        hours = totalLab/ 60;
        mins = totalLab % 60;
        //cout << mins << endl;
        if(mins < 10){
          cout <<  hours << ":" << "0" << mins << endl;;
        }
        else{
            cout <<  hours << ":" << mins << endl;
        }

}
