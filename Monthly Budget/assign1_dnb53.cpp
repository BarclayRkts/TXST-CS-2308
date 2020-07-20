//File Name: assign1_dnb53.cpp
//
// Author: DeJa Barclay
// Date: 9/11/2019
// Assignment Number: 1
// CS 2308.003 Fall 2019
// Instructor: Jill Seaman
//
// This program displays a table with 6 categories totaling to a
// student's monthly budget. For each category, the table includes the
// allocated amount, amount spent, and if user is over or under budget.
// The program prompts user to input the amount spent in each category,
// then calculates and displays the total spent and the total amount
// over or under for the entire monthly budget.


#include <iostream>
#include <iomanip>


using namespace std;

// structures for each category

struct Category
{
    string name;
    double allocated;
    double spent;
};

//Prototypes for each function

void getAmount(Category infoArray[]);
void displayAmount(Category infoArray[]  );
void overUnder(Category infoArray[]);

int main()
{

    Category infoArray[6];

    getAmount(infoArray);


}

//*************************************************
// getAmount : asks and receives information
// from user on which category to select and how
// much was spent
// infoArray items holds each items information
//*************************************************

void getAmount(Category infoArray[] )
{
        infoArray[0].name = {"Housing"};
        infoArray[1].name = {"Utilities"};
        infoArray[2].name = {"Transportation"};
        infoArray[3].name = {"Food"};
        infoArray[4].name = {"Entertainment"};
        infoArray[5].name= {"Miscellaneous"};

        infoArray[0].spent = 0.00;
        infoArray[1].spent = 0.00;
        infoArray[2].spent = 0.00;
        infoArray[3].spent = 0.00;
        infoArray[4].spent = 0.00;
        infoArray[5].spent = 0.00;

        infoArray[0].allocated = {500.00};
        infoArray[1].allocated = {150.00};
        infoArray[2].allocated = {50.00};
        infoArray[3].allocated = {250.00};
        infoArray[4].allocated = {150.00};
        infoArray[5].allocated = {50.00};

    int choice = 0;
    do
    {
        cout << "Enter the number of a category to record money spent or "
         << endl
         << "7 to display the table or" << endl
         << "8 to quit." << endl;
        cin >> choice;

        double amount=0;

        switch(choice)
        {
        case 1 :
            cout << "Please enter the amount to add to that category:" << endl;
            cin >> amount;
            infoArray[0].spent = infoArray[0].spent+amount;
            break;
        case 2 :
            cout << "Please enter the amount to add to that category:" << endl;
            cin >> amount;
            infoArray[1].spent = infoArray[1].spent+amount;
            break;
        case 3 :
            cout << "Please enter the amount to add to that category:" << endl;
            cin >> amount;
                infoArray[2].spent = infoArray[2].spent+amount;
            break;
        case 4 :
            cout << "Please enter the amount to add to that category:" << endl;
            cin >> amount;
            infoArray[3].spent = infoArray[3].spent+amount;
            break;
        case 5 :
            cout << "Please enter the amount to add to that category:" << endl;
           cin >> amount;
                infoArray[4].spent = infoArray[4].spent+amount;
            break;
        case 6 :
            cout << "Please enter the amount to add to that category:" << endl;
            cin >> amount;
                infoArray[5].spent = infoArray[5].spent+amount;
            break;
        case 7 :
            displayAmount( infoArray);
            break;
        case 8 :
            overUnder(infoArray);

            break;

        }
    }
    while(choice != 8);

}

//*************************************************
// displayAmount: Displays all six categories in a
// table with allocated, spent, and over/under totals.
// infoArray items holds each item information
//*************************************************

void displayAmount(Category infoArray[])
{
    double difference[6]; // allocated - spent for each category
    double Allocatedtotal = infoArray[1].allocated + infoArray[2].allocated + infoArray[3].allocated //allocated total
    + infoArray[4].allocated + infoArray[5].allocated;
    for(int i = 0; i < 7; i++)
    {
        difference[i] = infoArray[i].allocated - infoArray[i].spent;

        if(difference[i] < Allocatedtotal)
        {
            difference[i] = -1 *difference[i];

        }
    }
    cout << right << setw(15) << "Category" << setw(20) << "Allocated" << setw(10) << "Spent" << setw(10) << "Amt over" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << left << "1. " << setw(25) << infoArray[0].name << setw(12) << setprecision(2) << fixed <<infoArray[0].allocated  << setw(10) <<infoArray[0].spent << difference[0] << endl;
    cout << left << "2. " << setw(25) << infoArray[1].name  << setw(12) <<infoArray[1].allocated  << setw(10) <<infoArray[1].spent << difference[1] << endl;
    cout << left << "3. " << setw(25) << infoArray[2].name  << setw(12) <<infoArray[2].allocated  << setw(10) <<infoArray[2].spent << difference[2] << endl;
    cout << left << "4. " << setw(25) << infoArray[3].name  << setw(12) <<infoArray[3].allocated  << setw(10) <<infoArray[3].spent << difference[3] << endl;
    cout << left << "5. " << setw(25) << infoArray[4].name  << setw(12) <<infoArray[4].allocated  << setw(10) <<infoArray[4].spent << difference[4] << endl;
    cout << left << "6. " << setw(25) << infoArray[5].name  << setw(12) <<infoArray[5].allocated  << setw(10) <<infoArray[5].spent << difference[5] << endl;

}

//*************************************************
//OverUnder:determines the total spent in each
// category and if user went over/under budget.
// infoArrays items holds each item information
//*************************************************

void overUnder(Category infoArray[])
{
    double total = 0.00; // total of all spent
    double Allocatedtotal =0.00; // total of all allocated budget
    double budget = 0.00; // allocated budget - allocated spent

    total = infoArray[0].spent + infoArray[1].spent + infoArray[2].spent + infoArray[3].spent + infoArray[4].spent + infoArray[5].spent;
    Allocatedtotal =  infoArray[0].allocated + infoArray[1].allocated + infoArray[2].allocated + infoArray[3].allocated + infoArray[4].allocated + infoArray[5].allocated;
    budget = Allocatedtotal - total;
    if (total > Allocatedtotal)
    {
        cout << "For the month you are over budget by $" << budget << endl;
    }
    else
        cout << "For the month you are under budget by $" << budget << endl;


}


