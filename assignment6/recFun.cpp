/******************************************************************************
 * Author: Kevin Woods
 * Date Created: 11/01/14
 * Last Modification Date: 11/02/14
 * Filename: recFun.cpp
 *
 * Overview: This program will prompt the user to enter a number. It will then 
 * print the number in the fibonacci sequence.
 *
 * Input: The input will justbe one integer. Number over ~40 result in a fairly
 * lengthy calculation time to return the fibonacci number.
 *
 * Output: The output will be the given number's fibnacci value.
 *
 *****************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

int fibonacci (int);

int main()
{
   int x;

   cout << "This program will return the fibonacci number of the given entry" 
   << endl;
   cout << "Please enter a number (smaller is better!)" << endl;
   
   while (! (cin >> x))
   {
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Error! Please enter a number: " << endl;
   }


   cout << fibonacci(x) << endl;
   
   return 0;

}

int fibonacci(int n)
{
   if (n <= 0)
   {
      return 0;
   }
   else if (n == 1)
   {
      return 1;
   }
   else 
   {
      return fibonacci(n-1) + fibonacci(n - 2);
   }
}
