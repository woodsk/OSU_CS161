/******************************************************************************
*   Author: Kevin Woods
*   Date Created: 10/22/14
*   Last Modification Date: 10/26/14
*   Filename: mpg.cpp
*
*   Overview: This program will prompt the user to enter the number of liters
*   used and the number of miles driven. It will then use a contact to convert
*   that number to miles and print miles to the screen.
*
*   Input: The input will be two numbers such as 10.5 and 500, I've used double
*   variables in this program.
*
*   Output: The output will just be the number of miles. The program will then
*   ask teh user if they would like to repeat.
*
******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

const float lpg = 0.264179;

void convert (float, float);

int main()
{
    char again = 'y';

    while (again == 'Y' || again == 'y')
    {
        float litres, miles;

        cout << "MPG Converter" << endl;
        cout << "Please enter the number of litres your car has used: " << endl;

        while (! (cin >> litres) || litres == 0)
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Error! Please enter a number: ";
        }

        cout << "Please enter the number of miles you have driven: " << endl;

        while (! (cin >> miles))
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Error! Please enter a number: ";
        }

        convert(litres, miles);

        cout << "Would you like to start over?" << endl;
        cout << "Enter 'y' for yes, anything else to quit." << endl;
	cin >> again;

    }

    return 0;
}

void convert (float litres_used, float miles_driven)
{
    float mpg;

    mpg = miles_driven / (litres_used * lpg);
    cout << "You have averaged " << mpg << " miles per gallon." << endl;
}
