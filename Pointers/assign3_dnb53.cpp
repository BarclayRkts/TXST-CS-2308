//File Name: assign3_dnb53.cpp
//
// Author: DeJa Barclay, Annalise Martinez
// Date: 10/09/2019
// Assignment Number: 3
// CS 2308 Fall 2019
// Instructor: Jill Seaman

#include <iostream>
#include <iomanip>

using namespace std;

bool isSorted(int *arr , int);
double pizza (int people, int *pizzas, int *slices);
int *doubleReverse(int *arr , int);
int *shiftX(int *arr, int , int );
int *subArray(int *arr, int start , int length );
int *duplicateArray(int *arr, int );

//*************************************************
// int main: prints out all the data returned from
// the functions.
// int array1[] = stores the test data for array 1
// int array2[] = stores the test data for array 2
// int array3[] = stores the test data for array 3
//*************************************************

int main()
{
    int SIZE = 8; // size of the array

    int array1[] = {1,2,3,4,5,6,7,8};
    int array2[] = {8,7,6,5,4,3,2,1};
    int array3[] = {1,2,3,5,4,6,7,8};

    cout << "Testing isSorted: " << endl;
    cout << "Test Data array 1: 1 2 3 4 5 6 7 8" << endl;
    cout << "Expected result: true" << endl;

    bool result = isSorted(array1, SIZE);

    if(result == 0)
        cout << "Actual result: " << setw(7) << "false" << endl;
    else
        cout << "Actual result: " << setw(6) << "true" << endl;

     cout << "     " << endl;

    cout << "Testing isSorted: " << endl;
    cout << "Test Data array 2: 8 7 6 5 4 3 2 1" << endl;
    cout << "Expected result: false" << endl;


    result = isSorted(array2, SIZE);

    if(result == 0)
        cout << "Actual result: " << setw(7) << "false" << endl;
    else
        cout << "Actual result: " << setw(6) << "true" << endl;

    cout << "     " << endl;

    cout << "Testing isSorted: " << endl;
    cout << "Test Data array 3: 1 2 3 5 4 6 7 8" << endl;
    cout << "Expected result: false" << endl;


    result = isSorted(array3, SIZE);

    if(result == 0)
        cout << "Actual result: " << setw(7) << "false" << endl;
    else
        cout << "Actual result: " << setw(6) << "true" << endl;

// -------------------------------------------------------------------------------
    cout << "     " << endl;

    int people = 25,
        pizzas,
        slices;

    cout << "Testing Pizza for " << people << " people:" << endl
         << "Expected result: 112.80  p: 9  s: 3" << endl;

    double results = pizza (people, &pizzas , &slices);

     cout << "Actual results:  " << fixed << setprecision(2) << results << "  p: " << pizzas
         << "  s: " << slices << endl << endl;
// --------------------------------------------------------------------------------

    int *reverse = doubleReverse(array1, SIZE);
    cout << "testing doubleReverse:" << endl;
    cout << "test data: 1 2 3 4 5 6 7 8 " << endl;
    cout << "Expected result: 1 2 3 4 5 6 7 8 8 7 6 5 4 3 2 1" <<endl;
    cout << "Actual result: ";
    cout << setw(3);
    for(int i = 0; i < SIZE*2; i++)
    {
        cout << reverse[i] << " ";
    }
// --------------------------------------------------------------------------------
     cout << "     " << endl;

    int x = 4;
    cout << "   " << endl;
    int *shift = shiftX(array1, SIZE , x);
    cout << "testing shiftX:" << endl;
    cout << "test data: 1 2 3 4 5 6 7 8 " << endl << "and 4" << endl;
    cout << "Expected result: -1 -1 -1 -1 1 2 3 4 5 6 7 8" << endl;
    cout << "Actual result: " ;
    cout << setw(4);

    for(int i = 0; i < SIZE + x; i++)
    {
        cout << shift[i] << " ";
    }
// --------------------------------------------------------------------------------
    cout << "     " << endl;

    cout << "     " << endl;

    cout << "testing subArray:" << endl;
    cout << "test data: 1 2 3 4 5 6 7 8" << endl;
    cout << "start: 3 length: 4" << endl;
    cout << "Expected result: 4 5 6 7" << endl;
    cout << "Actual result: ";

    int start = 3;
    int length = 4;
    int *subArr = subArray(array1, start, length);

    cout << setw(3);

    for(int i = 0; i < length; i++)
    {
         cout << subArr[i] << " ";
    }

}

//*************************************************
// isSorted : : takes an array of integers and its
//size as arguments. Returns true if the
//elements of the array are already in ascending order,
//and false if they are not.
// arr = array1
//*************************************************

bool isSorted (int *arr , int SIZE )
{
    int  *arrPTR = arr;

    for(int i =0; i < SIZE - 1; i++)
    {
        if(*(arrPTR + i) > *(arrPTR+i + 1))
        {
            return false;

        }

    }

    return true;

}

//*************************************************
// pizza: Calculates the total slices, number of
//pizzas and number of total slices and return the
//values.
//*************************************************

double pizza (int people, int *pizzas , int *slices)
{

     int totalSlices = people * 3;
     *pizzas = totalSlices / 8;
     *slices = totalSlices % 8;
     return *pizzas * 11.95 + *slices * 1.75;


}

//*************************************************
// doubleReverse: takes an int array and the
//array's size as arguments. It create a new
//array that is twice the size of the argument array.
//The function copies the contents of the argument
//array to the first half of the new array, and again to
//the second half of the new array, but in reverse order.
//The function should return a pointer to the new array.
// arr = array1 in main
//*************************************************

int *doubleReverse (int *arr, int SIZE)
{
    int counter =SIZE-1;

    int *newArray = new int[SIZE * 2];

    for(int i =0; i < SIZE; i++)
    {
        newArray[i] = arr[i];
    }
    for(int i = SIZE; i < SIZE*2; i++)
    {
        newArray[i] = arr[counter];
        counter --;
    }

    return newArray;
    delete[] newArray;
}

//*************************************************
// shiftX: takes an int array, the array’s size, and
//an integer value (x) as arguments. The function
//creates a new array that is x elements larger
//than the argument array. The first x elements of the
//new array should be set to -1. The remaining
//elements should contain the elements from the
//original array in the original order. The function
//should return a pointer to the new array.
//*************************************************

int *shiftX(int *arr, int SIZE, int x )
{
    int *newArray = new int[SIZE + x];

    for(int i =0; i < x; i++)
    {
        newArray[i] = -1;

    }

    for(int i =x, j=0; i < SIZE+x;j++, i++)
    {
        newArray[i] = arr[j];
    }
    return newArray;
    delete[] newArray;
}

//*************************************************
// subArray:  takes an int array, a start index and
// a length as arguments. It creates a new array that
// is a copy of the elements from the original array
// starting at the start index, and has length equal
// to the length argument.
//*************************************************

int *subArray (int *arr, int start, int length)
{

     int *result = duplicateArray(arr + start, length);

     return result;
}

//*************************************************
// duplicateArray: dulicates the original array and
// creates a new array.
//*************************************************

int *duplicateArray (int *arr, int size)
{

     int *newArray;

     if (size <= 0) //size must be positive
     return NULL; //NULL is 0, an invalid address

     newArray = new int [size]; //allocate new array

     for (int index = 0; index < size; index++)
     newArray[index] = arr[index]; //copy to new array

     return newArray;
}

