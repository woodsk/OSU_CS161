/******************************************************************************
 *  Author: Kevin Woods
 *  Date Created: 11/13/14
 *  Last Modification Date: 11/16/14
 *  Filename:   sameSum.cpp
 *
 *  Overview:
 *      This program will prompt the user to enter the size of a 2D array. The
 *      user will then be prompted to enter values for each element of the
 *      array. The program will then sum the rows, columns, and diagonals, and
 *      return to the user whether all of the sums are equal or not.
 *
 *  Input:
 *      The first input for the program will be an integer for the size (rows,
 *      columns) of the 2D array. The next inputs will all be integers that
 *      fill each element of the array.
 *
 *  Output:
 *      The output will either be that all of the sums are equal (true) or that
 *      all of the sums are not equal (false).
 *
 *****************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

bool checkAll(int**, int*);

bool checkRowsCols(int**, int*, int*);

bool checkDiag(int**, int*, int);

int **pullArray(int**, int*);

int arraySize();

void fillArray(int**, int*);

int main()
{

    cout << "Please enter the size of your array (ex. 4 for 4x4 array): ";
    cout << endl;

    int **inputArray;

    int *inputSize;
    inputSize = new int;

    inputArray = pullArray(inputArray, inputSize);

    if(checkAll(inputArray, inputSize))
    {
	cout << "The sums of the rows, columns, and diagonals are all equal!";
        cout << endl;
    }

    else
    {
	cout << "The sums of the rows, columns, and diagonals are not all ";
	cout<< "equal." << endl;
    }

    return 0;
}

bool checkAll(int **inputArray, int *inputSize)
{
    int *checkTemp;

    checkTemp = new int;

    return (checkRowsCols(inputArray, inputSize, checkTemp)
            && checkDiag(inputArray, inputSize, *checkTemp));
}

//check sums of rows and colums
bool checkRowsCols(int **inputArray, int *inputSize, int *checkTemp)
{
    for (int row = 0; row < *inputSize; row++)
    {
	int  check1 = 0, check2 = 0;

	for (int col = 0; col < *inputSize; col++)
        {
    	    check1 += inputArray[row][col];
    	    check2 += inputArray[col][row];
	}

	if (row == 0)
        {
	    *checkTemp = check1;
	}
	
        else
        {
	    if (*checkTemp != check1 || *checkTemp != check2)
	    {
            	return false;
	    }
	}

    return true;
    }
}

//checks sum of diagonals
bool checkDiag(int **inputArray, int *inputSize, int checkTemp)
{
    int check = 0;

    for (int row = 0, col = 0; row < *inputSize; row++, col++)
    {
        check += inputArray[row][col];
    }

    if (checkTemp != check)
    {
        return false;
    }

    check = 0;

    for (int row = *inputSize - 1, col = 0; row >= 0; row--, col++)
    {
        check += inputArray[row][col];
    }

    if (checkTemp != check)
    {
        return false;
    }

    return true;
}

int **pullArray(int **inputArray, int *inputSize)
{
    *inputSize = arraySize();

    inputArray = new int*[*inputSize];

    for (int i = 0; i < *inputSize; i++)
    {
        *(inputArray + i) = new int[*inputSize];
    }

    fillArray(inputArray, inputSize);

    return inputArray;
}

int arraySize()
{
    int tempSize = 0;
    
    do
    {
        if(cin >> tempSize)
        {
            if (cin.peek()!= '\n')
            {
	        tempSize = 0;
		cin.ignore(100,'\n');
    	    }
        }
	
        else
        {
	    cin.clear();
	    cin.ignore(100,'\n');
        }

    } while (tempSize <= 0);

    cout << endl;

    return tempSize;
}

//fills row and column for input prompt
void fillArray(int **inputArray, int *inputSize)
{
    char again;

    //increment rows
    for (int row = 0; row < *inputSize; row++)
    {
        int col = 0;

        while (col < *inputSize)
        {
            cout << "Please enter an integer for space [" << row;
            cout << "][" << col << "]: ";

            //input validation and increment columns
            if(cin >> inputArray[row][col])
            {
                cin.ignore(100,'\n');
                col++;
            }
    
            else
            {
                cin.clear();
                cin.ignore(100,'\n');
                cout << "Error! Please enter a number: " << endl;
            }
        }
    }

    cout << endl;

    cout << "Your array is: " << endl;

    //displays array
    for (int row = 0; row < *inputSize; row++)
    {
        cout << "[";

        for (int col = 0; col < *inputSize; col++)
        {
            cout << setw(3) << inputArray[row][col];

            if (col == *inputSize -1)
            {
                cout << "]";
            }

            else
            {
                cout << "][";
            }
        }

        cout << endl;

    }

    cout << endl;

    return;
}
