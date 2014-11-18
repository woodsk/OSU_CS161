/******************************************************************************
 * Author: Kevin Woods
 * Date Created: 10/14/14
 * Last Modification Date: 10/19/14
 * Filename: loop.cpp
 *
 * Overview:
 *      This program will prompt the user to enter 2 separate strings.
 *      It will then compare the strings character by character. If all of
 *      the characters match, it will print that the strings are the same.
 *      If there is a difference between characters, it will print that the
 *      strings are not equal.
 *
 * Input:
 *      The input is 2 separate strings. The program will accept any type of
 *      input.
 *
 * Output:
 *      The output will either be "The strins are equal" or "The strings are
 *      not equal", depending if the strings are an exact match or not.
 * ****************************************************************************/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    string first;
    string second;

    cout << "This program will compare two strings" << endl;
    cout << "Please enter the first string: " << endl;
    getline(cin, first);
    cout << "Please enter the second string: " << endl;
    getline(cin, second);

    for (int i = 0; i < first.length(); i++)
    {
        //this should compare each string character by character
        if (first.at(i) != second.at(i))
        {
            cout << "Your strings are not the same." << endl;
        }

        else
        {
            cout << "Your strings are the same!" << endl;
        }

        //not sure if this is the right place to put the break
        break;

    }

    return 0;

}
