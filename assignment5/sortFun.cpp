/******************************************************************************
 * Author: Kevin Woods
 * Date Created: 10/29/14
 * Last Modification Date: 11/2/14
 * Filename: sortFun.cpp
 *
 * Overview: This program will sort 3 integers from smallest to largest using a
 * function. The function will pass the integers by reference while comparing 
 * the entries to determine the smallest and largest values. The function will 
 * then print the smallest, middle, and largest values.
 *
 * Input: The input for this program is 3 integer values. Non integer values
 * will result in an error message. 
 *
 * Output: The output forthis funtion will be the same 3 integers entered by
 * the user, but arranges from smallest to largest.
 *
 * ****************************************************************************/



#include <iostream>
#include <cmath>

using namespace std;

void sort(int &, int &, int &);

int main()
{
   int a, b, c;

   cout << "Please enter 3 integers to be sorted from smallest to largest:\n";
  
   while (! (cin >> a))
   {
     cin.clear();
     cin.ignore(100, '\n');
     cout << "Error! Please enter a number: " << endl;
   }
   
   while (! (cin >> b))
   {
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Error! Please enter a number: " << endl;
   }

   while (! (cin >> c))
   {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Error! Please enter a number: " << endl;
   }


   sort(a, b, c);

   return 0;
}

void sort(int &x, int &y, int &z)
{
   while (x <= y && x <= z)
   {
      if (y <= z)
      {
         cout << "Smallest number is " << x << endl;
         cout << "Middle number is " << y << endl;
         cout << "Largest number is " << z << endl;
      }
      else  
      {
         cout << "Smallest number is " << x << endl;
         cout << "Middle number is " << z << endl;
         cout << "Largest number is " << y << endl;
      }
   
      break;
   }

   while (x > y && x > z)
   {
      if (y <= z)
      {
         cout << "Smallest number is " << y << endl;
         cout << "Middle number is " << z << endl;
         cout << "Largest number is " << x << endl;
      }
      else
      {
         cout << "Smallest number is " << z << endl;
         cout << "Middle number is " << y << endl;
         cout << "Largest number is " << x << endl;
      } 
   
      break;
   }

   while (x > y && x <= z)
   {
      cout << "Smallest number is " << y << endl;
      cout << "Middle number is " << x << endl;
      cout << "Largest number is " << z << endl;

      break;
   }

   while (x <= y && x > z)
   {
      cout << "Smallest number is " << z << endl;
      cout << "Middle number is " << x << endl;
      cout << "Largest number is " << y << endl;
   
      break;
   }
 
}

   
