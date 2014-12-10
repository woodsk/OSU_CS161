#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
 
using namespace std;
 
int dec2Bin(int);
int binConvert (string, int, int);

int main() 
{
   int choice;
   
   do {
   
      cout << "1: Convert Decimal to Binary" << endl;
      cout << "2: Convert Binary to Decimal" << endl;
      cout << "3: Exit Program" << endl;
      cout << "\nPlease enter an option: ";
      cin >> choice;

      if (choice == 1)
      {
         int dec1;
 
         cout << "Enter a non-negative integer value: ";
         cin >> dec1;
   
	 if (dec1 < 0)
	 { 
	 cout << "\nInvalid Entry." << endl;
	 }
	 else 
	 {
         cout << "\nDecimal " << dec1 << " = ";
         dec2Bin(dec1);
         cout << " Binary" << endl;
         }
      }
      else if (choice == 2)
      {
         string bin1;
         int binPosition = 0, binLength = 0;
         
         cout << "Enter a binary number: " << endl;
         getline(cin, bin1);

         for (int i = 0; i <bin1.length(); i++)
         {  
            if (bin1.at(i) != 1 || bin1.at(i) != 0)
            { 
               cout << "Invalid Entry" <<endl;
               cin.clear();
               cin.ignore(100, '\n');
               
               getline(cin, bin1);
            }
            else 
            {
               binConvert(bin1, binPosition, binLength);
            }
         }
      } 
      else 
      {
         cout << "Please enter 1, 2, or 3: ";
         cin >> choice;
      }  
   } while (choice != 3); 

   return 0;
}

int dec2Bin(int dec1) 
{
   int remainder;
   remainder = dec1 % 2;
   dec1 = dec1 / 2;
	
   if (dec1 > 0)
   {
      dec2Bin(dec1);
   }
   else if (dec1 = 0)
   {
      return 0;
   }
 
   string binary;
   ostringstream convert;
   convert << remainder;
   binary = convert.str();
   
   cout << binary;  
}

int binConvert(string bin2, unsigned int position, int length)
{
   
   int decimal;

   if (position < length)
   {
      if (bin2[length-position-1] == '1')
      {
         decimal = pow(2, position);
      }
      
      return decimal + binConvert(bin2, ++position, length);
   }

      return decimal;
}

