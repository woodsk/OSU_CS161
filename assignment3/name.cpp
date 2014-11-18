/******************************************************************************
* Author: Kevin Woods
* Date Created: 10/17/14
* Last Modification Date: 10/19/14
* Filename: name.cpp
*
* Overview:
*       This program will prompt the user to enter their full name. It will
*       then print our the name in the following format: Last, First MI.
*
* Input:
*       The program accepts input all on one line. The program will accept any
*       input, there is no error checking for numbers, etc.
*
* Output:
*       The ouput will all be on one line in the following format:
*       Last, First MI.
*
******************************************************************************/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    string full;

    cout << "Please enter your first name, middle name, & last name: "
    << endl;

    getline(cin, full);

    //there is a likely a way to do this with only 1 space variable
    int first_space;
    int middle_space;
    int last_space;
    string first;
    string middle;
    string last;


    first_space = full.find(' ', 0);
    first = full.substr(0, first_space);

    //not sure how to skip this if there is no middle name
    middle_space = full.find(' ', first_space + 1);
    middle = full.substr(first_space + 1, middle_space);

    last_space = full.find(' ', middle_space +1);
    last = full.substr(middle_space + 1, last_space);


    middle = middle.at(0);

    //only works if 3 names are given :(

    cout << "Your name is: " << endl;
    cout << last << ", " << first << " " << middle << "." << endl;

    return 0;
}
