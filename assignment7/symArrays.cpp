/******************************************************************************
 *  Author: Kevin Woods
 *  Date Created: 11/14/14
 *  Last Modification Date: 11/16/14
 *  Filename: symArrays.cpp
 *
 *  Overview:
 *      This program will determine whether 3 user inputted arrays are
 *      symmetrical or not. The user will define the sizes of 3 arrays using
 *      command line arguments. The program will then prompt the user to enter
 *      values for each element in the arrays. The program will then output
 *      whether each of the arrays are symmetrical or not.
 *
 *  Input
 *      The first input for this program are the sizes (integers) of 3 arrays,
 *      entered by the user as command line arguments. The next input will
 *      be all integers for each element of the 3 arrays.
 *
 *  Output:
 *      The program will output whether array 1, 2, and 3 are symmetrical or
 *      not.
 *
 *****************************************************************************/

#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;


bool symCheck1(int firstArray[], int firstArraySize);
bool symCheck2(int secondArray[], int secondArraySize);
bool symCheck3(int thirdArray[], int thirdArraySize);

int main(int argc, char* argv[])
{

    //input validation found on the discusson boards

    if(argc != 4)
    {
        cout << endl << "Error! Incorrect command line arguments." << endl;

        return 0;
    }

    int firstArraySize;
    int secondArraySize;
    int thirdArraySize;
    int* firstArray;
    int* secondArray;
    int* thirdArray;
    char peek;

    firstArraySize = atoi(argv[1]);
    secondArraySize = atoi(argv[2]);
    thirdArraySize = atoi(argv[3]);

    //dynamically allocate my arraws using new ints

    firstArray = new int[firstArraySize];
    secondArray = new int[secondArraySize];
    thirdArray = new int[thirdArraySize];

    do
    {

        cout << endl << "Enter an array with " << firstArraySize;
        cout << " integers all separated by a space:" << endl;

        for (int i = 0; i < firstArraySize; i++)
        {
            cin >> firstArray[i];
        }
	//read on discussion boards, no totally clear on cin.peek 
        peek = cin.peek();

        if(peek != '\n')
        {
            cin.clear();
            cin.ignore(1000,'\n');
        }

    } while(peek != '\n');

    cout << endl << "Enter an array with " << secondArraySize;
    cout << " integers, each separated by a space:" << endl;

    for (int i = 0; i < secondArraySize; i++)
    {
        cin >> secondArray[i];
    }

    cout << endl << "Enter an array with " << thirdArraySize;
    cout << " integers, each separated by a space:" << endl;

    for (int i = 0; i < thirdArraySize; i++)
    {
        cin >> thirdArray[i];
    }

    if(symCheck1(firstArray, firstArraySize))
    {
        cout << endl << "Array 1 is symmetric." << endl;
    }

    else
    {
        cout << endl << "Array 1 is not symmetric." << endl;
    }

    if(symCheck2(secondArray, secondArraySize))
    {
        cout << endl << "Array 2 is symmetric." << endl;
    }

    else
    {
        cout << endl << "Array 2 is not symmetric." << endl;
    }

    if(symCheck3(thirdArray, thirdArraySize))
    {
        cout << endl << "Array 3 is symmetric." << endl;
    }

    else
    {
        cout << endl << "Array 3 is not symmetric." << endl;
    }

    //deallocate my arrays using delete

    delete [] firstArray;
    delete [] secondArray;
    delete [] thirdArray;

    return 0;
}

bool symCheck1 (int firstArray[], int firstArraySize)
{
    for (int i = 0; i <= ((firstArraySize)/2); ++i)
    {
        if(firstArray[i] != firstArray[firstArraySize - (i+1)])
        {
            return false;
        }
    }

    return true;
}

bool symCheck2 (int secondArray[], int secondArraySize)
{
    for (int i = 0; i <= ((secondArraySize)/2); ++i)
    {
        if(secondArray[i] != secondArray[secondArraySize - (i+1)])
        {
            return false;
        }
    }

    return true;
}

bool symCheck3 (int thirdArray[], int thirdArraySize)
{
    for (int i = 0; i <= ((thirdArraySize)/2); ++i)
    {
        if(thirdArray[i] != thirdArray[thirdArraySize - (i+1)])
        {
            return false;
        }
    }

    return true;
}
