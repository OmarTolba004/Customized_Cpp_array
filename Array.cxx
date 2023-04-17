/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Array.cxx
 *  Description:  Array class implementation
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  4/17/2023
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <iostream>
#include <iomanip> // for setw();
#include "Array.h"
using namespace std;

/**********************************************************************************************************************
 *  CLASS FRIEND DEFINITIONS
 *********************************************************************************************************************/

/* Overloaded insertion stream operator*/
istream &operator>>(istream &input, Array &arr)
{
    size_t i; // size_t in c std means unsigned int --> prefered to use with array size and indices
    for (i = 0; i < arr.size; i++)
    {
        input >> arr.ptr[i];
    }
    return input; // enables cascading
}

ostream &operator<<(ostream &output, const Array &arr)
{
    size_t i;
    for (i = 0; i < arr.size; i++)
    {
        output << setw(12) << arr.ptr[i]; // setw() wroks as stream manipulator
        if ((i + 1) % 4 == 0)
        {
            output << endl;
        }
    }
    output << endl; // inserting newling
    return output;  // enables cascading
}

/**********************************************************************************************************************
 *  CLASS MEMBER FUNCTION DEFINITIONS
 *********************************************************************************************************************/

/* Getter function*/
size_t Array::getSize(void)
{
    return (*this).size;
}

/* Class default constructor*/
Array::Array(size_t arraySize)
    : size(arraySize > 0 ? arraySize : throw invalid_argument("Array size must be greater than 0")),
      ptr(new int[size])
{
    /* initializing the whole array with zeros*/
    size_t i;
    for (i = 0; i < (*this).size; i++)
    {
        ptr[i] = 0;
    }
}

/* Class copy constructor*/
Array::Array(const Array &arrToCopy)
    : size(arrToCopy.size),
      ptr(new int[arrToCopy.size]) // new dynaminc allocation with array to copy size
{
    /* Copying data*/
    size_t i;
    for (i = 0; i < arrToCopy.size; i++)
    {
        (*this).ptr[i] = arrToCopy.ptr[i];
    }
}
/* Class destrucotr*/
Array::~Array()
{
    /* De-allocating memory*/
    delete[] ptr;
}

/* Overloaded function decleration*/
/* Overloaded assignment operator
 *const return to prevent the in-correct behavior -->assigning (x=y)=z which means --> assigning y to x then z to x
 */
const Array &Array::operator=(const Array &arr)
{
    if (&arr != this) // avoid self assignment
    {
        if ((*this).size != arr.size)
        {
            /* re-allocating new memory for this object*/
            delete[] ptr;
            (*this).size = arr.size;
            (*this).ptr = new int[arr.size];
        }
        /* Copy element by element*/
        size_t i;
        for (i = 0; i < (*this).size; i++)
        {
            (*this).ptr[i] = arr.ptr[i];
        }
    }

    return *this; // allow operand cascading
}

/* Overloaded equality operator*/
bool Array::operator==(const Array &arr) const
{
    /* Checking if not equal in size*/
    if ((*this).size != arr.size)
    {
        return false;
    }

    /* Checking element by element*/
    size_t i;
    for (i = 0; i < (*this).size; i++)
        if ((*this).ptr[i] != arr.ptr[i])
        {
            return false;
        }
    return true;
}

/* Overloading subscript operator returning const to be used as rvalue with checking vlaid range*/
int Array::operator[](const int index) const
{
    if (index < 0 || index > ((*this).size - 1))
    {
        throw out_of_range("index inserted is out of Array range");
    }
    return (*this).ptr[index];
}

/* Overloading subscript operator returning reference to be used as lvalue with checking vlaid range*/
int &Array::operator[](const int index)
{
    if (index < 0 || index > ((*this).size - 1))
    {
        throw out_of_range("index inserted is out of Array range");
    }
    return (*this).ptr[index];
}

/**********************************************************************************************************************
 *  END OF FILE: Array.cxx
 *********************************************************************************************************************/
