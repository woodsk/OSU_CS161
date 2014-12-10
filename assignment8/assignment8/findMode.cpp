/******************************************************************************
 *  Author: Kevin Woods
 *  Date Created: 11/19/14
 *  Last Modification Date: 11/23/14
 *  Filename: findMode.cpp
 *
 *  Overview:
 *      This program will calculate the mode from a given set of integers. 
 *      The integers will be stored in a vector, and the mode returned with 
 *      a vector.
 *
 *  Input:
 *      The first input is the number of integers to be calculated. The 
 *      following input will be each separate integer to be calculated.
 *
 *  Output:
 *      The output will be the mode of the given set of integers.
 *
 *****************************************************************************/

#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <vector>

using namespace std;

vector<int> findMode(vector<int> values)
{
    int count = 0;
    int maxNum = 0;
    int number = values.at(0);
    
    cout << "Mode(s): " << endl;
    
    sort(values.begin(), values.end());
    
    vector<int> mode;
    
    for(int i = 0; i < values.size(); i++)
    {
        
        if(number == values.at(i))
        {
            count++;
            
            if(count > maxNum)
            {
                maxNum = count;
            }
        }
        else
        {
            if(count > maxNum)
            {
                maxNum = count;
            }
            number = values.at(i);
            count = 1;
        }
    }
    
    count = 0;
    number = values.at(0);
    
    for(int i = 0; i < values.size(); i++)
    {
        if(number == values.at(i))
        {
            count++;
            
            if(count == maxNum)
            {
                mode.push_back(number);
            }
        }
        else
        {
            number = values.at(i);
            count = 1;
            
            if(count == maxNum)
            {
                mode.push_back(number);
            }
        }
    }
    
    return mode;
}


int main()
{
    vector<int> numbers;
    int numberCount = 0;
    
    cout << "Enter each integer you with to find the mode for." << endl;
    cout << "Enter a new line to calculate the mode of the given integers."
    << endl;

    int entry;
    int temp;
        
    cout << "Number " << numberCount << ": ";

    while (! (cin >> entry))
    {
       cin.clear();
       cin.ignore(100, '\n');
       cout << "Error! Enter an integer: ";
    }
            
    
    
    if(numbers.size() > 0)
    {
        vector<int> mode = findMode(numbers);
        
        for(int i = 0; i < mode.size(); i++)
        {
            cout << mode.at(i) << endl;
        }
    }
    else
    {
        cout << "No numbers to calculate" << endl;
    }
    
    return 0;
}
