/******************************************************************************
 *  Author: Kevin Woods
 *  Date Created: 11/28/14
 *  Last Modification Date: 11/30/14
 *  Filename: shopCart2.cpp
 *
 * Overview:
 *	 This program is a shopping cart where the user may store items, display
 * 	 the cart conents, view the total cart price, or quit. The program will
 *  	 contain a struct of Item made up of a string called name, double called
 * 	 price, and int called quantity. A separate function will handle each
 *  	 individual menu option.
 *
 * Input:
 *	The first input for the program will be a menu entry between 1 and 4.
 * 	There is only a second input if menu option 1 is selected. The input
 * 	for a new item will be a the name, price, and quantity.
 *
 * Output:
 *	The ouptput will either be the items currently in the cart if menu
 *	option 2 is selected, or the total cart price if menu option 3 is
 *	selected.
 *****************************************************************************/

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdlib.h>

using namespace std;

class Item
{
    private:
        string name;
	double price;
	int quantity;

    public:
	string getName() const
	{
            return name;
	}

        double getPrice() const
        {
            return price;
	}

        int getQuantity() const
        {
            return quantity;
        }

	// Item constructor
	Item (string n, double p, int q)
	{
	    name = n;
	    price = p;
	    quantity = q;
	}
};

class ShoppingCart
{
    private:
        // cart vecotr to hold items
	vector <Item> cart;

    public:
        void addItem(string name, double price, int quantity)
        {
	    cart.push_back (Item (name, price, quantity));
	}

	void listItems();
	double totalPrice() const;
};

// list cart inventory
void ShoppingCart::listItems()
{
    string name;
    double price;
    int quantity;

    //display settings
    int dxQty = 7;
    int dxName = 7;
    int dxPrice = 7;
    int dxSubtotal = 19;

    // headers
    cout << endl << right << setw(dxQty) << "Quantity";
    cout << " ";
    cout << right << setw(dxName) << "Item";
    cout << right << setw(dxPrice) << "Price";
    cout << right << setw(dxSubtotal) << "Subtotal" << endl;

    for (int i = 0; i < cart.size(); i++)
    {
	name = cart[i].getName();
	quantity = cart[i].getQuantity();
	price = cart[i].getPrice();

	cout << right << setw(dxQty) << quantity << " ";
	cout << setw(dxName) << right << name;
	cout << setw(dxPrice) << setprecision(2) << showpoint << fixed << right
        << price;
	cout << setw(dxSubtotal) << price * quantity << endl << endl;
    }
}

// cart total price
double ShoppingCart::totalPrice() const
{
    int quantity;
    double price;
    double total = 0;

	// increment total
    for (int i = 0; i < cart.size(); i++)
    {
	price = cart[i].getPrice();
	quantity = cart[i].getQuantity();
	total += quantity * price;
    }

    return total;
}

// add item function
void addItem (ShoppingCart &cart)
{
    string name;
    double price;
    int quantity;

    cout << endl << "Item name: ";
    cin >> name;

    cout << "Item price: ";

    while (! (cin >> price))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Error! Please enter a valid price: ";
    }

    cout << "Item quantity: ";

    while (! (cin >> quantity))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Error! Please enter a valid quantity: ";
    }

    cart.addItem(name, price, quantity);
}

// prints the total amount of all items in the shopping cart
void cartTotal (const ShoppingCart &cart)
{
    // print the total
    cout << "Total: $" << cart.totalPrice() << setprecision(2) <<showpoint
    << fixed << endl;
}

int main ()
{
    ShoppingCart shoppingCart;

    int menuChoice = 0;

    cout << endl << "Welcome to the Shopping Cart!" << endl;

    do
    {
        cout << endl << "1. Add item" << endl;
	cout << "2. Display items in cart" << endl;
        cout << "3. Display total price" << endl;
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

	switch (menuChoice)
	{
            case 1:
            {
                addItem(shoppingCart);
            }
            case 2:
            {
                shoppingCart.listItems();
	        break;
            }
            case 3:
            {
                cartTotal(shoppingCart);
		break;
            }
	    case 4:
	    {
		exit(EXIT_SUCCESS);
		break;
	    }
	}

    } while (menuChoice != 4);

    return 0;
}
