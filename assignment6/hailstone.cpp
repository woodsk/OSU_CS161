/******************************************************************************
 * Author: Kevin Woods
 * Date Created: 11/01/14
 * Last Modification Date: 11/02/14
 * Filename: recFun.cpp
 *
 * Overview: This program will use a recursive function to perform the hailstone 
 * sequence with a given number. The program will then print how many steps were
 * needed until it returned 1.
 *
 * Input: The input for this program will just be one integer. Non integer
 * entries will result in an error message.
 *
 * Output: The output will be the numbr of steps perfromed during the hailstone
 * sequence on the given number until 1 is returned.
 *
 * ***************************************************************************/



#include <iostream>
#include <cmath>

using namespace std;

int hailstone(int, int);

int main()
{
   cout << "This program will pefrom the hailstone sequence on a given number" 
   << endl;
   cout << "It will print the number of steps until 1 is returned." << endl;

   int num;

   while (! (cin >>num))
   {
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Error! Please enter a number: " << endl;
   }  

   cout << hailstone(num, 0) << " steps until 1 is returned." << endl;

   return 0;
}

int hailstone(int x, int count)
{

   ++count;   
   if (x == 1)
   {
      return count;
   }
   else
   {
      if (x % 2 == 0)
      {
         x /= 2;
         count = hailstone(x, count);

      }
      else
      {
         x = x*3+1;
         count = hailstone(x, count);
       }

   }

   return count;
}
