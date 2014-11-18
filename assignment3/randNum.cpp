/******************************************************************************
 * Author: Kevin Woods
 * Date Created: 10/14/14
 * Last Modification Date: 10/19/14
 * Filename: randNum.cpp
 *
 * Overview:
 *      This program will print 10 random numbers
 *
 * Input:
 *      There is no input for this program!
 *
 * Output:
 *      The output will be 10 random nuumber between 1 - 99
 * ****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

    //I'm still not sure why the program prints the same random numbers
    //without using this piece
    srand(time(0));

    for ( int i = 1; i <= 10; i++)
    {
        //I used % 100 to restrict the output to numbers under 100
        cout << rand() % 100<< endl;
    }

    return 0;
}
