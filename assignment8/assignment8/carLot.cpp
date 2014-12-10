/******************************************************************************
 * Author: Kevin Woods
 * Date Created: 11/21/14
 * Last Modification Date: 11/23/14
 * Filename: carLot.cpp
 *
 * Overview: 
 * 	This program will track cars purchased and sold at a car lot. The 
 * 	program will pompt the user to add a new car, list the current 
 * 	inventory, print the profit for a given month, or quit. The program
 * 	will then accept entries wil car make, model, and price. The program
 * 	will ask if any car has been sold, then accept the date of sale and 
 * 	sale price if it has. 
 *
 * Input:
 * 	The first input is a menu entry between 1 and 4. The next input only
 * 	occurs if menu option 1 is selcted. The user will input the car's
 * 	make, model, and price. The user will enter sale inforamtion if the
 * 	car sold. If menu option 3 is selcted, the user will enter a month
 * 	and year to display the profit for. 
 *
 * Output: 
 * 	The output will either be the current inventory if menu option 2 is
 * 	selected, or the profit for a given month if menu option 3 is selected.
 *****************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Date 
{
   int day;
   int month;
   int year;
};

struct Car
{
   string make;
   string model;
   int year;
   Date datePurchased;
   double purchasePrice;
   bool isSold;
   Date dateSold;
   double salePrice;
};

bool dateValid(int year, int month, int day)
{
   //validate year number is correct
   if(year < 0 || year > 2015)
      return false;
   //validate month number is correct
   if(month < 1 ||month > 12)
      return false;
   //an array to store the max days in each month
   int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
   
   if(day < 1 || day > days[month-1])
      return false;

   return true;
}

vector<Car> addEntry(vector<Car> entry)
{
   Car newCar;
   int year, month, day;
	
   //ask user for input
   cout << endl << "Enter the car make: ";
   cin >> newCar.make;
	
   cout << "Enter the car model: ";
   cin >> newCar.model;
	
   cout << "Enter the model year: ";
   cin >> year;

   while(!dateValid(year, 1, 1))
   {
      cout << "Error! Year not valid." << endl;
      cout << "Please enter the model year: ";
      cin >> year;
   }

   newCar.year = year;
	
   cout << "Enter the date of purchase (YYYY MM DD): ";
   cin >> year >> month >> day;

   while(!dateValid(year, month, day))
   {
   cout << "Error! Date not valid." << endl;
   cout<< "Enter the date of purchase (YYYY MM DD): ";
   cin >> year >> month >> day;
   }
  
   newCar.datePurchased.year = year;
   newCar.datePurchased.month = month;
   newCar.datePurchased.day = day;

   //purchase price
   cout << "Enter the purchase price: ";
   cin >> newCar.purchasePrice;

   //already sold
   int sold;
   cout << "Is this car already sold? 1 for yes, 0 for no: ";
   cin >> sold;
	
   if(sold)
   {
      newCar.isSold = true;
      cout << "Enter the date of sale (YYYY MM DD): ";
      cin >> year >> month >> day;
      
      while(!dateValid(year, month, day))
      {
         cout << "Error! Date not valid.";
         cout << "Enter the date of purchase (YYYY MM DD): ";
         cin >> year >> month >> day;
      }
      
      newCar.dateSold.year = year;
      newCar.dateSold.month = month; 
      newCar.dateSold.day = day;

      //sale price
      cout << "Enter the sale price: ";
      cin >> newCar.salePrice;
   }
   else
   {
      newCar.isSold = false;
   }
   
   entry.push_back(newCar);
   cout <<  "Add entry complete!" << endl;

   return entry;
}

void listInventory(vector<Car> entry)
{
   cout << "List of inventory." << endl;
   
   int total = 0;
   
   for(int i = 0; i< entry.size(); i++)
   {
      if(entry[i].isSold == false)
      {
         cout << "Make: " << entry[i].make << endl;
         cout << "Model: "<< entry[i].model << endl;
         cout << "Year: "<< entry[i].year << endl;
         cout << "Date Purchased: " << entry[i].datePurchased.year
         << "/" << entry[i].datePurchased.month << "/" 
         << entry[i].datePurchased.day << endl;
         cout << "Purchase Price: " << fixed << setprecision(2)
         << entry[i].purchasePrice << endl << endl;

         total ++;
      }
   }

   cout << "There are " << total << " cars in inventory" << endl;
}

void profit(vector<Car> entry)
{
   double totalProfit = 0;
   int year, month;
   cout << "Enter the year of profit: ";
   cin >> year;

   while(!dateValid(year, 1, 1))
   {
      cout << "Error! Year not valid." << endl;
      cout << "Enter the year of profit: ";
      cin >> year;
   }
	
   cout << "Enter the month of profit: ";
   cin >> month;

   while(!dateValid(1, month, 1))
   {
      cout << "Error! Month not valid." << endl;
      cout << "Enter the month of profit: ";
      cin >> month;
   }

   for(int i = 0; i< entry.size(); i++)
   {
      if(entry[i].isSold==true && entry[i].dateSold.year == year && 
         entry[i].dateSold.month == month)
      {
         totalProfit += entry[i].salePrice - entry[i].purchasePrice;
      }
   }

   cout << "The total profit is " << fixed <<setprecision(2) << totalProfit
    << endl;
}

int main()
{
   vector<Car> entry;
   int choice;

   cout << "Welcome to the car lot!" << endl;
   cout << "1: Add entry" <<  endl;
   cout << "2: List current inventory" << endl;
   cout << "3: Profit for a month" << endl;
   cout << "0: Quit" << endl;
   cin >> choice;

   while(choice != 0)
   {
      switch(choice)
      {
         case 1:
         entry = addEntry(entry);
	 break;
		
         case 2:
	 listInventory(entry);
	 break;

	 case 3:
	 profit(entry);
         break;
	
         default:
         cout << "Error! Invalid menu selection." << endl;
	}
		
        cout << "Please select a valid entry: " << endl;
	cout << "1: Add entry" << endl;
        cout << "2: List current inventory" << endl;
        cout << "3: Profit for a month" << endl;
        cout << "0: Quit"<<endl;
	cin >> choice;
   }
	
   return 0;
}
