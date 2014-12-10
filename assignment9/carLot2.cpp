/******************************************************************************
 *  Author: Kevin Woods
 *  Date Created: 11/29/14
 *  Last Modification Date: 11/30/14
 *  Filename: carLot2.cpp
 *
 * Overview:
 *      This program will track cars purchased and sold at a car lot. The
 *      program will pompt the user to add a new car, list the current
 *      inventory, print the profit for a given month, or quit. The program
 *      will then accept entries wil car make, model, and price. The program
 *      will ask if any car has been sold, then accept the date of sale and
 *      sale price if it has.
 *
 * Input:
 *      The first input is a menu entry between 1 and 4. The next input only
 *      occurs if menu option 1 is selcted. The user will input the car's
 *      make, model, and price. The user will enter sale inforamtion if the
 *      car sold. If menu option 3 is selcted, the user will enter a month
 *      and year to display the profit for.
 *
 * Output:
 *      The output will either be the current inventory if menu option 2 is
 *      selected, or the profit for a given month if menu option 3 is selected.
 *
******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <math.h>

using namespace std;

// create a class called Date
class Date
{
    private:
        int day;
        int month;
        int year;

    public:
        Date();
        Date(int, int, int);
        int getMonth();
        int getDay();
        int getYear();
};

// create a class called Car
class Car
{
    private:
        string make;
        string model;
        int year;
        double purchasePrice;
        double salePrice;
        bool isSold;

    public:
	// constructors to create Car object
        Car();
        Car(string, string, int, Date, double, bool, Date, double);
        Car(string, string, int, Date, double, bool);
        Date datePurchased;
        Date dateSold;

        string getMake();
        string getModel();
        int getYear();
        double getPurchasePrice();
        bool getIsSold();
        double getSalePrice();
        double getProfit();
};

// create a class called CarLot
class CarLot
{
    private:
        vector<Car> inventory;

    public:
        // Car class parameter, adds car to inventory
        void addCar(Car);
        void listCurrentInv();
        double getMonthProfit(int, int);
};

int main()
{
    CarLot carLot;
    Car newCar;
    Date dateSold;
    Date datePurchased;
    int purchaseDay, purchaseMonth, purchaseYear, soldDay, soldMonth, soldYear,
    modelYear, profitMonth, profitYear;
    string make, model;
    double userSalePrice, userPurchasePrice;
    char sold;
    bool is_sold;

    cout << endl << "Welcome to the Car Lot!" << endl << endl;
    
    int menuChoice = 0;
 
    do 
    {
        cout << endl << "1. Add entry" << endl;
        cout << "2. List current inventory" << endl;
        cout << "3. Display month profit" << endl;
        cout << "4. Quit" << endl << endl;
        cout << "Please enter a menu option: ";

        // validate the input for the menu choice
        while(! (cin >> menuChoice))
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid Entry! Please select a menu option: ";
        }

        while(menuChoice < 1 || menuChoice > 4)
        {
            cout << "Invalid entry! Please select a menu option: ";
            cin >> menuChoice;
        }

        // interpret user input
        switch (menuChoice)
        {
                // add entry
            case 1:
            {
                cout << "Enter the car make: ";
                cin >> make;

                cout << "Enter the car model: ";
                cin >> model;

                cout << "Enter the model year: ";
		
                while (! (cin >> modelYear))
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Invalid year! Please enter a valid year: ";
                }

                cout << endl << "When was the car purchased?" << endl;
                cout << "Purchase month: ";
                
                while (! (cin >> purchaseMonth))
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Invalid month! Please enter a valid month: ";
                }

                cout << "Purchase day: ";
                
                while (! (cin >> purchaseDay))
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Invalid day! Please enter a valid day: ";
                }

                cout << "Purchase year: ";
                
                while (! (cin >> purchaseYear))
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Invalid year! Please enter a valid year: ";
                }
                
                //datePurchased object
                Date datePurchased(purchaseMonth, purchaseDay, purchaseYear);

                cout << "Purchase price: ";
		
                while(! (cin >> userPurchasePrice))
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Invalid Entry! Please enter a valid price: ";
                }

                cout << endl << "Has the car sold?" << endl;
                cout << "Enter 'y' for yes, anything else for no." << endl;
                cin >> sold;

                // if sold ask for date sold and sale price
                if (sold == 'y' || sold == 'Y')
                {
                    is_sold = true;

                    cout << "Sale price: ";
		    
                    while(! (cin >> userSalePrice))
                    {
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Invalid Entry! Please enter a valid price: ";
                    }
		    
                    cout << "When was the car sold?" << endl;
                    cout << "Sold month: ";
		    
                    while(! (cin >> soldMonth))
                    {
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Invalid Entry! Please enter a valid month: ";
                    }

                    cout << "Sold day: ";
		    
                    while(! (cin >> soldDay))
                    {
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Invlaid Entry! Please enter a valid day: ";
                    }

                    cout << "Sold year: ";
		    
                    while(! (cin >> soldYear))
                    {
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Invalid Entry! Please enter a valid year: ";
                    }

                    // create the dateSold object
                    Date dateSold(soldMonth, soldDay, soldYear);

                    // create Car object
                    Car newCar(make, model, modelYear, datePurchased,
                    userPurchasePrice, is_sold, dateSold, userSalePrice);

                    // pass car object into carLot object and store in vector
                    carLot.addCar(newCar);
                }

                else
                {
                    is_sold = false;

                    // create Car object
                    Car newCar(make, model, modelYear, datePurchased,
                    userPurchasePrice, is_sold);

                    carLot.addCar(newCar);
                }
                
                break;
            }
	
            // list current inventory
            case 2:
            {
                carLot.listCurrentInv();
                break;
            }

            // month profit
            case 3:
            {
                cout << "What month's profit do you want to find?" << endl;
                cout << "Profit month: ";
                
                while(! (cin >> profitMonth))
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Invalid Entry! Please enter a valid month: ";
                }
            
                cout << "Profit year: ";
                
                while(! (cin >> profitYear))
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Invalid Entry! Please enter a valid year: ";
                }
                
                cout << endl << "The profit for " << profitMonth << "/"
                << profitYear << " is: $ " << fixed << setprecision(2)
                << carLot.getMonthProfit(profitMonth, profitYear) << endl;

                break;
            }
			
            // quit program
            case 4:
            {
                exit(EXIT_SUCCESS);
                break;
            }
        }

    } while(menuChoice != 4);

    return 0;
}

// Date class constructor, creates default values for Date object
Date::Date()
{
    month = day = year = 0;
}

// Date class constructor, parameters for Date object
Date::Date(int inputMonth, int inputDay, int inputYear)
{
    day = inputDay;
    month = inputMonth;
    year = inputYear;

    while(year < 0 || year > 2015)
    {
        cout << "Invalid year! Please enter a year from 1 - 2015: ";
        cin >> year;
    }

    while(month < 1 || month > 12)
    {
        cout << "Invalid month! Please enter a month from 1-12: ";
        cin >> month;
    }

    // validate day input
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || 
	month == 10 || month == 12)
    {
        while(day < 1 || day > 31)
        {
            cout << "Invalid day! Please enter a day from 1-31: ";
    	    cin >> day;
        }
    }

    else if (month == 2)
    {
        while(day < 1 || day > 29)
        {
            cout << "Invalid day!. Please enter a day from 1-29: ";
            cin >> day;
        }
    }

    else
    {
        while(day < 1 || day > 30)
        {
            cout << "Invalid day! Please enter a day from 1-30: ";
            cin >> day;
        }
    }
}

//function for Date class to display month
int Date::getMonth()
{
    return month;
}

//function for Date class to display day
int Date::getDay()
{
    return day;
}

//function for Date class to display year
int Date::getYear()
{
    return year;
}

// Car class function implementation
Car::Car()
{
    make = " ";
    model = " ";
    year = 0;
    Date datePurchased;
    purchasePrice = 0;
    isSold = false;
}

// Car class constructor, sets values equal to user inputs

Car::Car(string inputMake, string inputModel, int inputYear,
        Date inputDatePurchased, double inputPurchasePrice, bool inputIsSold,
        Date inputDateSold, double inputSalePrice)
{
    make = inputMake;
    model = inputModel;
    year = inputYear;
    datePurchased = inputDatePurchased;
    purchasePrice = inputPurchasePrice;
    isSold = inputIsSold;
    dateSold = inputDateSold;
    salePrice = inputSalePrice;
}

Car::Car(string inputMake, string inputModel, int inputYear, 
        Date inputDatePurchased, double inputPurchasePrice, bool inputIsSold)
{
    make = inputMake;
    model = inputModel;
    year = inputYear;
    datePurchased = inputDatePurchased;
    purchasePrice = inputPurchasePrice;
    isSold = inputIsSold;
}

//function for Car class to display make
string Car::getMake()
{
    return make;
}

//function for Car class to display model
string Car::getModel()
{
    return model;
}

//function for Car class to display year
int Car::getYear()
{
    return year;
}

//function for Car class to display purchase price
double Car::getPurchasePrice()
{
    return purchasePrice;
}

// bool function for Car class isSold
bool Car::getIsSold()
{
    return isSold;
}

//function for Car class to display month profit
double Car::getProfit()
{
    if (isSold == true)
    {
        return (salePrice - purchasePrice);
    }
    else
        return NAN;
}

// adds car to inventory
 void CarLot::addCar(Car car)
{
    inventory.push_back(car);
}

// function for Car class to list inventory vector
void CarLot::listCurrentInv()
{
    int length = inventory.size();
    int carCount = 0;

    cout << endl << "Current Inventory" << endl;

    // loop through vector and display inventory
    for (int i = 0; i < length; i++)
    {
        if (inventory[i].getIsSold() == false)
        {
            // display basic information about the car
            cout << "Make: " << inventory[i].getMake() << endl;
            cout << "Model: " << inventory[i].getModel() << endl;
            cout << "Year: " << inventory[i].getYear() << endl;
            cout << "Date Purchased: " << inventory[i].datePurchased.getMonth()
            << "/" << inventory[i].datePurchased.getDay() << "/"
            << inventory[i].datePurchased.getYear() << endl;
            cout << "Purchase Price: $" << fixed << setprecision(2)
            << inventory[i].getPurchasePrice() << endl;

            carCount++;	// increase the number of cars in the inventory
        }
    }
    
    cout << endl << "There are " << carCount << " cars in inventory" << endl;
}

// function for CarLot class to display month profit
double CarLot::getMonthProfit(int month, int year)
{
    //variable for loop
    int length = inventory.size();
    double profit = 0;

    for (int i = 0; i < length; i++)
    {
        if (inventory[i].getIsSold() == true &&
	    inventory[i].dateSold.getMonth() == month && 
	    inventory[i].dateSold.getYear() == year)
        {
            profit += inventory[i].getProfit();
        }
    }
    
    return profit;
}
