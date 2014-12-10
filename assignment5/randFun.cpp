/******************************************************************************
*   Author: Kevin Woods
*   Date Created: 10/28/14
*   Last Modification Date: 11/2/14
*   Filename: randFun.cpp
*
*   Overview: This program will generate a random number between a given min 
*   and max value using a function.
*
*   Input: The input for this program will be two integer values for the 
*   minimum and maximum range of the random number. The iput is passed by
*   reference in this program.
*
*   Output: The output of this function is a random integer between the defined
*   minimum and maximum range.
*
******************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void rand_int (const int &min, const int &max, int &val);
//references

int main()
{

   int low, high, num;

    cout << "Random number generator." << endl;
    cout << "Please enter a minimum value: " << endl;
    
    while (! (cin >> low))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Error! Please enter a number: " << endl;
    }

    cout << "Please enter a maximum value: " << endl;
    
    while (! (cin >> high) || low >= high)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Error! Please enter a number higher than " <<
        low << ": " << endl;

    }

    rand_int(low, high, num);

    return 0;
}


void rand_int(const int &min, const int &max, int &val)
{

    cout << "Your random number is ";
    srand(time(0));
    val = (((rand() % (max-min)) + 1) + min);
    cout << val << endl;

}
