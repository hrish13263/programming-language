//intArray.cpp 
/*Program 5: A program employed to demonstrate the 
 * overloading of operators for array assignments etc. (Header and driver provided to us) 
 * CS 320
 * Hrishikesh M cssc 2644
 * Date: 11/23/2020 */

#include <iostream>
#include <iomanip>
#include "string.h"         // warnings issued whether this or <string>
#include <fstream>          
#include <stdlib.h>
#include "intArray.h"

using namespace std;
using std::ostream;


/* A default constructor, no arguments
 *     This makes an array of 10 elements starting from index '0' to '9' */
IntArray::IntArray(){
    size = 10;
    lo = 0;
    hi = 9;
    pA = new int[10];
    
    
    for (int i = 0; i < size; i++){
        pA[i] = 0;
    }
}

/* Following constructor definition to make an array 
 * from '0' to 'size-1' index*/
IntArray::IntArray(int size){
    this ->size = size;
    lo = 0;
    hi = size - 1;
    pA = new int[size];
    
   
    for (int i = 0; i < size; i++){
        pA[i] = 0;
    }
}

/* The constructor with given lower and upper index of the arrays
 * It makes an array utilizing the lower and upper index given*/
IntArray::IntArray(int lowerIndex, int upperIndex){
    lo = lowerIndex;
    hi = upperIndex;
    if (lowerIndex > upperIndex){
        cout << "Error- the Lower Index > the Upper Index"<<endl;
        cout << "Pausing" << endl;
        return;
    }
    size = hi - lo + 1;
    pA = new int[size];
    
    for (int i = 0; i < size; i++){
        pA[i] = 0;
    }
}

/* Following is definition of copy constructor
 * each entry and index range duplicated as mentioned*/
IntArray::IntArray(const IntArray& copyArray){
    size = copyArray.size;
    pA = new int[size];

    
    for (int i = 0; i < size; i++){
        pA[i] = copyArray.pA[i];
    }
}

/* destructor*/
IntArray::~IntArray(){
    delete [] pA;
}


/* == operator is overloaded 
 *checks if two array objects elements are same
 *0 returned  means false
 *1 returned means true*/
int IntArray:: operator==(const IntArray& rhs) {
    int initial = rhs.lo;
    
    if (size != rhs.size){
        return 0;
    }
    else{
       
        for (int i = 0; i < size; i++){
            if( pA[i] != rhs.pA[i]){
                return 0;
            }
            initial++;
        }
    }
    return 1;
}

/* != operator overloaded
 * checks if the intArray objects are not equal
 * returns 0 if false
 * returns 1 if true*/
int IntArray:: operator!=(const IntArray& rhs) {
    if(*this == rhs){
        return 0;
    }
    return 1;
}
/* '[] operator overloading*/
int& IntArray:: operator[](int index){
    if ((index < lo) || (index > hi)){
        cout << "Error- The index is out of bounds: arr[" << index <<
"]" << endl;
        cout << "Pause for halt" << endl;
        return pA[0];
    }
    return pA[index - lo];
    
}

/* '=' operator is overloaded
 * one objected is assigned to another*/
IntArray& IntArray::operator=(const IntArray& rhs){
    if(&rhs !=this){
        if (size != rhs.size){
            cout << "Error-The sizes of array do not match" << endl;
            cout << "Pause for halt" << endl;
            return *this;
        }
        for (int i = 0; i < size; i++){
            pA[i] = rhs.pA[i];
        }
    }
    return *this;
}

/* overloading + operator
 * the sum of two arrays asssigned to another one*/
IntArray IntArray::operator+(const IntArray& rhs){
    if(size != rhs.size){
        cout << "Error- The sizes of array do not match" << endl;
        cout << "Pause for halt" << endl;
        size = rhs.size;
    }
    for (int i = 0; i < size; i++){
        pA[i] = pA[i] + rhs.pA[i];
    }
    return *this;
}

/* overloading += operator
 * calculates the sum of two arrays and assigns it back to initial array*/
IntArray& IntArray::operator+=(const IntArray& rhs){
    if(size != rhs.size){
        cout << "Error: Sizes of arrays are not matching." << endl;
        cout << "Pause for halt " << endl;
        size = rhs.size;
    }
    for (int i = 0; i < size; i++){
        pA[i] = pA[i] + rhs.pA[i];
    }
    return *this;
}



/* Overloading '<<' operator, used to print elements of the array*/
ostream& operator<<(ostream &output, const IntArray& arr){
    for (int i = 0; i < arr.size; i++){
        output << arr.name[0] << "[" << (i+arr.lo) << "] = " << arr.pA[i] << endl;
    }
    return output;
}



void IntArray::setName(char *name){
    this->name = name;
}


void IntArray::getName(){
    std::cout << name;
}


int IntArray::high(){
    return hi;
}


int IntArray::low(){
    return lo;
}

