/* *****************************************************************************  
 * Author: Kevin Woods
 * Date Created: 10/10/14
 * Last Modification Date: 10/12/14 
 * Filename: arcade.cpp
 *
 * Overview:
 * 	This program will determine how many coupons you can redeem for candy bars 
 * 	and gumballs.
 *
 * Input:
 * 	The input is one whole number, which is the number of coupons.
 * 	Ex.
 * 	Coupons: 50
 *
 * Output:
 * 	The ouput will say how many candy bars can be redeemd and how many 
 * 	gumballs can be redeemed. It will tell the user if they do not have 
 * 	enough coupons to redeem either.
 * 	Ex.
 * 	Coupons: 5
 * 	Output: You don't have enough coupons for a candy bar. You can get 1
 * 	gumball.
 *
 * 	Coupons: 26
 * 	Output: You can get 2 candy bars and 2 gumballs.
 ******************************************************************************/


#include <iostream>
#include <cmath>

using namespace std;

int main()
{
   int coupons;
   const int candy = 10, gum = 3;

   cout << "How many coupons do you want to redeem?" << endl;
   cin >> coupons;
   cout << "You are redeeming: " << coupons << " coupons." << endl;
   
   if ((coupons/gum) < 1)
   {
   cout << "You don't have enough coupons for a candy bar!" << endl;
   cout << "You don't have enough coupons for a gumball either!" << endl; 
   }
   else if ((coupons/gum) >= 1 && coupons < 10)
   { 
   cout << "You don't have enough coupons for a candy bar!" << endl; 
   cout << "You can redeem your coupons for " 
   << coupons/gum << " gumballs." << endl;
   }   
   else if (coupons >= 10 && (coupons - candy) < 3)
   {
   cout << "You can redeem your coupons for " << coupons/candy
   << " candy bars." << endl;
   cout << "You don't have enough coupons left for a gumball." << endl;
   } 
   else if (coupons >= 10)
   {
   cout << "You can redeem your coupons for " << coupons/candy 
   << " candy bars." << endl;
   cout << "and " << (coupons % candy) / gum << " gumballs." << endl;
   }

   return 0;
}
