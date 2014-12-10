/******************************************************************************
 * Author: Kevin Woods
 * Date Created: 10/29/14
 * Last Modification Date: 11/02/14
 * Filename: refFun.cpp
 *
 * Overview: This program will check two strings and return if they have the
 * 	same values.
 * 	
 * Input: The input for the program are two strings. I accept the input 
 * 	using getline.
 *
 * Output: The output will either be true, "Strings are the same", or false,
 * "Strings are not the same".
******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

bool checkString(string &, string &);

int main ()
{
    string first;
    string second;

    cout << "This program will compare two strings" << endl;

    checkString(first, second);

    return 0;
}

bool checkString(string &entry1, string &entry2)
{

    cout << "Please enter the first string: " << endl;
    getline(cin, entry1);
    cout << "Please enter the second string: " << endl;
    getline(cin, entry2);

        for (int i = 0 ; i < entry1.length() - 1; ++i)
        {
           if (entry1.at(i) == entry2.at(i) && entry1.length() == entry2.length())
           {
	      cout << "Strings are the same!" << endl;
              return true;
           }
           else
           {
               cout << "Strings are not the same!" << endl;
	       return false;
           }
        }
}
