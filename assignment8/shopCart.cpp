/******************************************************************************
 * Author: Kevin Woods
 * Date Created: 11/19/14
 * Last Modification Date: 11/23/14
 * Filename: shopCart.cpp
 *
 * Overview: 
 * 	This program is a shopping cart where the user may store items, display
 * 	the cart conents, view the total cart price, or quit. The program will
 * 	contain a struct of Item made up of a string called name, double called 
 * 	price, and int called quantity. A separate function will handle each
 * 	individual menu option.
 *
 * Input: 
 * 	The first input for the program will be a menu entry between 1 and 4. 
 * 	There is only a second input if menu option 1 is selected. The input 
 * 	for a new item will be a the name, price, and quantity. 
 *
 * Output:
 *	The ouptput will either be the items currently in the cart if menu 
 *	option 2 is selected, or the total cart price if menu option 3 is 
 *	selected.
 *****************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <iomanip>

using namespace std;

struct Item
{
   string name;
   double price;
   int quantity;
};

void entry(Item[], int);
void contents(Item[], int);
void total(Item[], int);

int main()
{
   int items;
   int f = 0;
   int add;  
   int choice;
   struct Item cart[100]; //create and array from struct Item

   //intialize cart array
   for (int i = 0; i < 100; i++)
   {
      cart[i].name == "";
      cart[i].price == 0;
      cart[i].quantity == 0;
   }
   
   do
   {
      cout << "Welcome to the shopping cart!" << endl;
      cout << "Please select an option below:" << endl;
      cout << "1. Add Item." << endl;
      cout << "2. Display Contents. " << endl;
      cout << "3. Display Total Price. " << endl;
      cout << "4. Quit." << endl;
      cin >> choice;

      while (choice == 1)
      {
         cout << "How many items would you like to add?" << endl;
         
         while (! (cin >> items))
         {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Error! PLease enter a number: ";
         }

         entry(cart, items);
	 
         break;

      }

      //sets correct number of items
      add += items;

      while (choice == 2)
      {
         contents(cart, add);

         break;
      }

      while (choice == 3)
      {
         total(cart, add);

         break;
      }

      while (choice == 4)
      {
         exit(0);
      }


   } while (f == 0);

   return 0;
}

void entry(Item cart[], int items)
{
   for (int i = 0; i < items; i++)
   {
      cout << "Please enter the item name: ";
      cin >> cart[i].name;

      cout << endl << "Please enter the item price: ";
      while (! (cin >> cart[i].price))
      {
         cin.clear();
         cin.ignore(100, '\n');
         cout << "Error! Please enter a valid double (0.0): ";
      }

      cout << endl << "How many of those items would you like to purchase?: ";
      while (! (cin >> cart[i].quantity))
      {
         cin.clear();
         cin.ignore(100, '\n');
         cout << "Error! Please enter an integer: ";
      }
   }


}


void contents(Item cart[], int add)
{

   for (int i = 0; i < add; i++)
   {
      if (cart[i].name != "\0") //loops until null
      {
         cout << endl << "Item Name: " << cart[i].name << endl;
	 cout << "Quantity: " << cart[i].quantity << endl;
	 cout << "Price: $" << fixed << setprecision(2) << cart[i].price << endl;
      }

      else
         break;
   }

}


void total(Item cart[], int add)
{
   double totals = 0;

   for (int i = 0; i < add; i++)
   {
      if (cart[i].price != 0)
      {
         totals += (cart[i].price * cart[i].quantity);
      }

      else if (cart[i].price == 0)
         break;
   }

   cout << "The total price is of all cart items is: $" << fixed 
   << setprecision(2) << totals << endl;
}
