/******************************************************************************
*   Author: Kevin Woods
*   Date Created: 10/22/14
*   Last Modification Date: 10/26/14
*   Filename: finalist.cpp
*
*   Overview: This program will generate 4 random numbers between 1 and 25.
*   No two numbers will be repeated.
*
*   Input: There is no inpt for this program.
*
*   Output: The output will be 4 random numbers in succession.
*           Ex.  finalist number one is 12
*                finalist number two is 23
*                finalist number three is 5
*                finalist number four is 19
*
******************************************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;


int main()
{
    int finalist1;
    int finalist2;
    int finalist3;
    int finalist4;

    srand(time(0));

    //generates random numbers between 1 and 25
    finalist1= rand() % 25 + 1;
    finalist2 = rand() % 25 + 1;
    finalist3 = rand() % 25 + 1;
    finalist4 = rand() % 25 + 1;

    do
    {
        if (finalist1 == finalist2 || finalist1 == finalist3 ||
            finalist1 == finalist4)
        {
            finalist1 = rand() % 25 + 1;
        }

        else if (finalist2 == finalist3 || finalist2 == finalist4)
        {
        finalist2 = rand() % 25 + 1;
        }

        else
        {
        finalist3 = rand() % 25 + 1;
        }

        //this while should elimate all possible dupilcates
   } while (finalist1 == finalist2 || finalist1 == finalist3 ||
            finalist1 == finalist4 || finalist2 == finalist3 ||
            finalist2 == finalist4 || finalist3 == finalist4);

    cout << "The first finalst is number " << finalist1 << "." << endl;
    cout << "The second finalist is number " << finalist2 << "." << endl;
    cout << "The third finalist is number " << finalist3 << "." << endl;
    cout << "The fourth finalist is number " << finalist4 << "." << endl;

    return 0;

}
