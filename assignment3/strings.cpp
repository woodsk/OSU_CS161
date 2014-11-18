/******************************************************************************
 * Author: Kevin Woods
 * Date Created: 10/14/14
 * Last Modification Date: 10/19/14
 * Filename: strings.cpp
 *
 * Overview:
 *      This program will prompt the user to enter a string. The program will
 *      print out the string character by character forwards and backwards.
 *      Finally, the program will print the number of letters in the string.
 *
 * Input:
 *      The input is accepted all on one line as one string. Example input is:
 *      tree, 93870958732, tree rock fence, 7&0()u. Any input is accepted
 *
 * Output:
 *      The ouput will simply be the input string, printed character by
 *      character on a new line. The program then prints the string character
 *      by character in reverse. zFInally, the program prints the number of
 *      letters in the string.
 * ****************************************************************************/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{

    string my_str;

    cout << "Please enter a string of characters: " << endl;
    getline(cin, my_str);

    for ( int i = 0; i < my_str.length(); i++)
    {
        cout << my_str.at(i) << endl;
    }

// this wasn;t too difficult after thinking about the value of i at this point
    for (int i = my_str.length() - 1 ; i <= my_str.length(); i--)
    {
        cout << my_str.at(i) << endl;
    }

// this might be better at the beginning of the program?
    int letters = 0;

    for (int i = 0; i < my_str.length(); i++)
    {

        if (isalpha (my_str.at(i)) > 0)
        {
            letters++;
        }

    }

    cout << "Your string contains " << letters << " letters." << endl;

    return 0;
}
