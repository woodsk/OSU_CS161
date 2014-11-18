/*******************************************************************************
 * Author: Kevin Woods
 * Date Created: 10/10/14
 * Last Modification Date: 10/12/14
 * Filename: arcade2.cpp
 *
 * Output:
 * 	 This program will tell the user how many candy bars and/or gumballs
 * 	 can be redeemed from a certain amount of coupons.
 *
 * Input:
 * 	The input will be a whole number.
 * 	Coupons: 50
 *
 * Output:
 * 	If coupons is less than 3, no candy or gumballs are earned. 
 * 	If coupons is between 3 and 9, no candy and coupons/gum gumballs are
 * 	earned. If coupons is more than 9, coupons/candy are earned. the
 * 	remainder of coupons/candy, divided by 3 is the number of gumballs
 * 	earned. IF there are coupons left, print value to user.
 * 	Ex.
 * 	Input: 48
 * 	Output: 4 candy bars, 3 gumballs, and 2 remaining.
******************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
   int coupons;

   cout << "How many coupons do you want to redeem?" << endl;
   cin >> coupons;
   cout << "You are redeeming: " << coupons << " coupons." << endl;
   
   int candy = 0, gum = 0;
   
   while (coupons >= 10) 
   {
      candy++;
      coupons = coupons - 10;
      
   }
   while (coupons >= 3)
   {
      gum++;
      coupons = coupons - 3;
   }

   cout << "You can redeem your coupons for " << candy << " candy bars, " 
   << endl;
   cout << "and " << gum << " gumballs." << endl;
   cout << "You have " << coupons << " coupons left over." << endl;

   return 0;

}
