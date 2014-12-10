/*******************************************************************************
 *  Author: Kevin Woods
 *  Date Created: 12/4/14
 *  Last Modification Date: 12/7/14
 *  Filename: menu.cpp
 *
 *  Overview:
 *      This program is a Library simulator. There are three classes: Book,
 *      Patron, and Library. Each class is defined in a separate header file
 *      and implemented in a separate .cpp file. The user will be presented with
 *      the following menu:
 *          1. List Books
 *          2. List Members
 *          3. Add Book
 *          4. Add Member
 *          5. Check Out Book
 *          6. Return Book
 *          7. Request Book
 *          8. Pay Fine
 *          9. View Member Info
 *          10. View Book Info
 *          11. Increment Current Date
 *          12. Quit
 *
 *  Input:
 *      The first input will be a menu option between 1 and 12. The next inputs
 *      will depend on the menu selection. Menu choices 1 and 2 result in no 
 *      input. Menu choice 3 will prompt the user to input Book ID, Book Title, 
 *      and Book Author (all strings). Menu choice 4 will prompt the user to 
 *      enter Member ID and Member Name. Menu choice 5 will prompt the user to
 *      enter their Member ID and a Book ID to check out. Menu choice 6 will
 *      prompt the user to enter their Member ID and a Book ID to return. Menu 
 *      choice 7 will prompt the user to enter their Member ID and a Book ID to
 *      request to hold. Menu choice 8 will prompt the member id and a payment
 *      amount. Menu choice 9 will prompt a member id. Menu choice 10 will 
 *	prompt a book id. Menu choice 11 and 12 have no inputs.
 *
 *  Output:
 *	The menu is printed first and repeated after every action is completed.
 *	Menu choice 1 outputs a list of library books. Menu choice 2 outputs a 
 *	list of library members. Menu choice 3 ouputs book id, title, and 
 *	author prompts. Menu choice 4 outputs member id and name prompts. Menu
 *	choice 5 outputs member id and book id prompts, then prints the
 *	selected book has been checked out. Menu choice 6 prompts a book id,
 *	then prints the entered book id has been returned. Menu choice 7
 *	outputs member id and book id prompts, and prints the entered book
 *	is on hold. Menu choice 8 outputs member id and payment prompts, then
 *	prints the new total fine for the member. Menu choice 9 outputs the
 *	given member's info. Menu choice 10 outputs the given book's info.
 *	Menu choice 11 prints out the new current date. Menu choice 12 prints
 *	"Goodbye" and quits the program.
 *
 ******************************************************************************/
 


#include "Book.h"
#include "Patron.h"
#include "Library.h"

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    Library library;
    int choice = 0;
    double pay;
    string idn, idc;
    

    cout << endl << "Welcome to the library." << endl;
    
    do
    {
        cout << endl << "1. List Books" << endl;
        cout << "2. List Members" << endl;
        cout << "3. Add Book" << endl;
        cout << "4. Add Member" << endl;
        cout << "5. Check Out Book" << endl;
        cout << "6. Return Book" << endl;
        cout << "7. Request Book" << endl;
        cout << "8. Pay Fine" << endl;
        cout << "9. View Member Info" << endl;
        cout << "10. View Book Info" << endl;
        cout << "11. Increment Current Date" << endl;
        cout << "12. Quit" << endl << endl;
        cout << "Enter a menu option: ";
        
        while(!(cin >> choice))
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << endl << "Error! Please enter a valid menu option: ";
        }
        
        if (choice < 1 || choice > 12)
        {
            cout << endl << "Error! Please enter a valid menu option: ";
           
            while(!(cin >> choice))
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << endl << "Error! Please enter a valid menu option: ";
            }
        }
        
        switch (choice)
        {
            case 1:
            {
                library.listBooks();
                break;
            }

            case 2:
            {
                library.listPatrons();
                break;
            }
                
            case 3:
            {
                library.addBook();
                break;
            }

            case 4:
            {
                library.addMember();
                break;
            }

            case 5:
            {
                cin.ignore(100, '\n');
                
                cout << endl << "Enter Member ID: ";
                getline(cin, idn);
                cout << "Enter Book ID: ";
                getline(cin, idc);

                library.checkOutBook(idn, idc);
                break;
            }

            case 6:
            {
                cin.ignore(100, '\n');
                
                cout << endl << "Enter Book ID: ";
                getline(cin, idc);
                
                library.returnBook(idc);
                break;
            }

            case 7:
            {
                cin.ignore(100, '\n');
                
                cout << endl << "Enter Member ID: ";
                getline(cin, idn);
                
                cout << "Enter Book ID: ";
                getline(cin, idc);
       
                library.requestBook(idn, idc);
                break;
            }

            case 8:
            {
                cin.ignore(100, '\n');
                
                cout << endl << "Enter Member ID: ";
                getline(cin, idn);
        
                cout << endl << "Enter payment amount: $";
                
                while(!(cin >> pay))
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Error!. Enter a valid amount (0.0): ";
                }
        
                library.payFine(idn, pay);
                break;
            }

            case 9:
            {
                cin.ignore(100, '\n');
                
                cout << endl << "Enter Member ID: ";
                getline(cin, idn);

                library.viewPatronInfo(idn);
                break;
            }

            case 10:
            {
                cin.ignore(100, '\n');
                
                cout << endl << "Book ID: ";
                getline(cin, idc);

                library.viewBookInfo(idc);
                break;
            }
    
            case 11:
            {
                library.incrementCurrentDate();
                break;
            }

            case 12:
            {
                cout << endl << "Goodbye!" << endl;
                exit(EXIT_SUCCESS);
            }
        }

    } while(choice != 12);
    
    return 0;
}
