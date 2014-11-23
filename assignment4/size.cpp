/******************************************************************************
*   Author: Kevin Woods
*   Date Created: 10/22/14
*   Last Modification Date: 10/26/14
*   Filename: size.cpp
*
*   Overview: This program will prompt the user to enter their height in
*   inches, weight in pounds, and age in years. Non-number entries will
*   generate error messages. The program will  then calculate anf print the
*   user's hat size, jacket size, and waist size. The program will then ask
*   user if they want to repeat.
*
*   Input: The input will be 2 flaoting point numbers and one integer, such as
*   70.5, 155.8, and 60.
*
*   Output: The output will be 3 floatng point numbers. These numbers will
*   be the result of each function calculation.
*
******************************************************************************/
#include <iostream>
#include <cmath>

using namespace std;

void hat (float, float);
void jacket (float, float, int);
void waist (float, int);

int main()
{
    char again = 'y';

    while (again == 'y' || again == 'Y')
    {

        float height, weight;
        int age;

        cout << "Please enter your height in inches: " << endl;

        while (! (cin >> height))
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Error! Please enter a number: ";
        }

        cout << "Please enter your weight in pounds: " << endl;

        while (! (cin >> weight))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error! Please enter a number: ";
        }

        cout << "Please enter your age in years: " << endl;

        while (! (cin >> age))
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Error! Please enter number: " << endl;
        }

        hat (weight, height);

        jacket (height, weight, age);

        waist (weight, age);

        cout << "Woule you like to repeat the program?" << endl;
        cout << "Enter 'y' for yes, anything else to quit: ";
        cin >> again;

    }

    return 0;

}

void hat (float hat_height, float hat_weight)
{
    float hat_size;
    hat_size = (hat_weight / hat_height) * 2.9;
    cout << "Your hat size is: " << hat_size << endl;
}

void jacket (float jacket_height, float jacket_weight, int jacket_age)
{
    float jacket_size;


    if (jacket_age >= 40)
    {
        jacket_size = (jacket_height*jacket_weight)/288;
        jacket_size = jacket_size + (0.125 * ((jacket_age-40)/10));
    }
    else
    {
        jacket_size = (jacket_height*jacket_weight)/288;
    }

    cout << "Your jacket size is: " << jacket_size << " inches" << endl;

}

void waist (float waist_weight, int waist_age)
{
    float waist_size;

    if (waist_age >= 30)
    {
        waist_size = waist_weight / 5.7;
        waist_size = waist_size + (0.1 * ((waist_age-30)/2));
    }
    else
    {
        waist_size = waist_weight / 5.7;
    }

    cout << "Your waist size is: " << waist_size << " inches" << endl;
}

