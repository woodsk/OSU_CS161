/******************************************************************************
*   Author: Kevin Woods
*   Date Created: 10/22/14
*   Last Modification Date: 10/26/14
*   Filename: randFun.cpp
*
*   Overview: This program will prompt the user to enter a nimimum and maximum
*   value for a random number. The program will then generate a random number,
*   and print that number to the screen.
*
*   Input: The input will be two integers, such as 40 and 80. Non-integers
*   input will result in an error.
*
*   Output: The output will be a random integer between the given minimum and
*   maximum values.
*
******************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int random (int, int);

int main()
{
    int range_low, range_high;

    cout << "Random Number Generator" << endl;
    cout << "Please enter the minimum possible value of the random number" <<
    endl;
    
    while (! (cin >> range_low))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Error! Please enter a number: " << endl;
    }

    cout << "Please enter the maximum possible value of the random number" <<
    endl;

    while (! (cin >> range_high) || range_high <= range_low)
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "Error! Please enter a number higher than " << range_low << 
	": "<< endl;
    }
    
    random (range_low, range_high);

    return 0;
}

int random (int rand_low, int rand_high)
{

    int number;

    srand(time(0));
    number = (((rand() % (rand_high-rand_low)) + 1) + rand_low);
    cout << "The random number is: " << number << endl;

}

