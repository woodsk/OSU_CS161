/******************************************************************************
 * Author: Kevin Woods
 * Date Created: 10/15/14
 * Last Modification Date: 10/19/14
 * Filename: randNum2.cpp
 *
 * Overview:
 *      This prgram wll prompt the user to enter a minimum and maximum range
 *      for a random number. The program will then  print a randome number
 *      between the given min and max values.
 *
 * Input:
 *      The input is 2 parts, low and high (min and max). Integers are the only
 *      accepted input. Negative numbers will be accepted also.
 *
 * Output:
 *      The output is a random number between the given low and high values.
 *
 * ****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

    int low;
    int high;

    cout << "This program will generate a random number " << endl;
    cout << "between a specified range." << endl;
    cout << "Please enter the minimum range value: " << endl;

    //I should have a check here to reject floating point numbers
    while (! (cin >> low))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Error! Please enter a number: " << endl;
    }

    cout << "Please enter the maximum range value: " << endl;

    //this works, but the check to ensure low < high might be better earlier
    while (! (cin >> high) || low >= high)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Error! Please enter a number higher than " <<
        low << ": " << endl;

    }

    cout << "The random number will be between " << low << " and "
    << high << "." << endl;

    srand(time(0));

    int random;

    for (int i = 0; i < 1; i++)
    {
        random =(((rand() % (high-low)) + 1) + low);
    }

    cout << "The random number is: " << random << "." << endl;

    return 0;
}
