/******************************************************************************
*   Author: Kevin Woods
*   Date Created: 10/22/14
*   Last Modification Date: 10/26/14
*   Filename: retFun.cpp
*
*   Overview: This program will check two strings and return if they have the
*   same values.
*
*   Input: The input for the program are two strings. I accept the input using
*   getline.
*
*   Output: The output will either be true, "Strings are the same", or false,
*   "Strings are not the same".
*
******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

void checkString(string entry1, string entry2);

int main ()
{
    string first;
    string second;

    cout << "This program will compare two strings" << endl;

    checkString(first, second);

    return 0;

}

void checkString(string entry1, string entry2)
{
    cout << "Please enter the first string: " << endl;
    cin >> entry1;
    cout << "Please enter the second string: " << endl;
    cin >> entry2;

    for (int i = 0 ; i < entry1.length(); i++)
    {
        if (entry1.at(i) != entry2.at(i) || entry1.length() != entry2.length())
        {
            cout << "Your strings are not the same." << endl;
        }
        else
        {
            cout << "Your strings are the same!" << endl;
        }

        break;
    }
}
