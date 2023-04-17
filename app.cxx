/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  app.cxx
 *  Description:  Source file for testing Array class
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  4/17/2023
 *********************************************************************************************************************/
#include <iostream>
#include <stdexcept>
#include "Array.h"
using namespace std;

int main()
{
    Array arr1(5); // five-element Array
    Array arr2;    // 10-elements Array by default

    // print arr1 size and contents
    cout << "Size of Array arr1 is "
         << arr1.getSize()
         << "\nArray after initialization:\n"
         << arr1;

    // print arr2 size and contents
    cout << "\nSize of Array arr2 is "
         << arr2.getSize()
         << "\nArray after initialization:\n"
         << arr2;

    // input and print arr1 and arr2
    cout << "\nEnter 15 elements for array 1 and array 2:" << endl;
    cin >> arr1 >> arr2;

    cout << "\nAfter input, the Arrays contain:\n"
         << "arr1:\n"
         << arr1
         << "arr2:\n"
         << arr2;

    // use overloaded inequality (!=) operator
    cout << "\nEvaluating: arr1 != arr2" << endl;

    if (arr1 != arr2)
        cout << "arr1 and arr2 are not equal" << endl;

    /* create Array arr3 and arr4 using arr1 as an*/
    /* initializer; print size and contents */
    Array arr3(arr1); // invokes copy constructor
    Array arr4 = arr2;

    cout << "\nSize of Array arr3 is "
         << arr3.getSize()
         << "\nArray arr3 after initialization with copy constructor for arr1:\n"
         << arr3;

    cout << "\nSize of Array arr4 is "
         << arr4.getSize()
         << "\nArray arr4 after initialization with copy constructor for arr2:\n"
         << arr4;

    /* use overloaded assignment (=) operator*/ 
    cout << "\nAssigning arr2 to arr1:" << endl;
    arr1 = arr2; // note target Array is smaller

    cout << "arr1:\n"
         << arr1
         << "arr2:\n"
         << arr2;

    // use overloaded equality (==) operator
    cout << "\nEvaluating: arr1 == arr2" << endl;

    if (arr1 == arr2)
        cout << "arr1 and arr2 are equal" << endl;

    // use overloaded subscript operator to create rvalue
    cout << "\narr1[5] is " << arr1[5];

    // use overloaded subscript operator to create lvalue
    cout << "\n\nAssigning 1000 to arr1[5]" << endl;
    arr1[5] = 1000;
    cout << "arr1:\n"
         << arr1;

    // attempt to use out-of-range subscript
    try
    {
        cout << "\nAttempt to assign 1000 to arr1[15]" << endl;
        arr1[30] = 1000; // ERROR: subscript out of range
    }                    // end try
    catch (out_of_range &ex)
    {
        cout << "An exception occurred: " << ex.what() << endl;
    }

    /* those 2 lines are used to avoid Program from flash termination */
    int x;
    cin>>x;
}

/**********************************************************************************************************************
 *  END OF FILE: app.cxx
 *********************************************************************************************************************/
