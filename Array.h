/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Array.h
 *  Description:  Header file for Array class -> used to seperated interfacing from implementation
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  4/17/2023
 *********************************************************************************************************************/

#ifndef ARRAY_H
#define ARRAY_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <iostream>

/**********************************************************************************************************************
 *  CLASS HEADERS
 *********************************************************************************************************************/
class Array
{
    /* Overloaded extraction stream operator*/
    friend std::istream &operator>>(std::istream &, Array &);
    /* Overloaded insertion stream operator*/
    friend std::ostream &operator<<(std::ostream &, const Array &);

public:
    /* Class default constructor*/
    explicit Array(size_t arraySize = 10);
    /* Class copy constructor*/
    Array(const Array &);
    /* Class destrucotr*/
    ~Array();
    /* Getter function*/
    size_t getSize(void);

    /* Overloaded function decleration*/
    /* Overloaded assignment operator
     *const return to prevent the in-correct behavior -->assigning (x=y)=z which means --> assigning y to x then z to x
     */
    const Array &operator=(const Array &);

    /* Overloaded equality operator*/
    bool operator==(const Array &) const;

    /* in-equality operator --> defined in class decleration to apply inline function*/
    bool operator!=(const Array &r_operand) const
    {
        return !(*this == r_operand); // using equality overloaded operator
    }

    /* Overloading subscript operator returning const to be used as rvalue with checking vlaid range*/
    int operator[](const int) const;

    /* Overloading subscript operator returning reference to be used as lvalue with checking vlaid range*/
    int &operator[](const int);

    /* private data members and functions*/
private:
    size_t size; // size_t in c std means unsigned int --> prefered to use with array size and indices
    int* ptr; // pointer to the first allocated array location 
};

#endif /* ARRAY_H */
/**********************************************************************************************************************
 *  END OF FILE: Array.h
 *********************************************************************************************************************/
