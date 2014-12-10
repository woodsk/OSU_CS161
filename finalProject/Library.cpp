//library.cpp is the implementation of the Library class

#include "Book.h"
#include "Library.h"
#include "Patron.h"

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

//default constructor
Library::Library()
{
    currentDate = 0;
    members.reserve(100);
	holdings.reserve(100);
}

//function to list books on shelf
void Library::listBooks()
{
    cout << endl << "Library Books:" << endl;
    
    for (unsigned int i = 0; i < holdings.size(); i++)
    {
        cout << endl << "Book ID: " << holdings[i].getIdCode() << endl;
        cout << "Title: " << holdings[i].getTitle() << endl;
        cout << "Author: " << holdings[i].getAuthor() << endl;
    }
}

//function to list patrons
void Library::listPatrons()
{
    cout << endl << "Library Members:" << endl;
    
    for (unsigned int j = 0; j < members.size(); j++)
    {
        cout << endl << "Name: " << members[j].getName() << endl;
        cout << "Member ID: " << members[j].getIdNum() << endl;
    }
}

//function for adding books
void Library::addBook()
{
    string idc, t, a;
    
    cin.clear();
    cin.ignore(100, '\n');

    cout << endl << "Book ID: ";
    getline(cin, idc);
    
    for (unsigned int i = 0; i < holdings.size(); i++)
    {
        while (idc == holdings[i].getIdCode())
        {
            cout << endl << "Book ID taken. Please enter a new Book ID: ";
            getline(cin, idc);
        }
    }
    
    cout << "Book Title: ";
    getline(cin, t);
    
    cout << "Book Author: ";
    getline(cin, a);
    
    //create newbook object from inputs, push to holdings vector
    Book newBook(idc, t, a);
    holdings.push_back(newBook);

}

// function to add a new member
void Library::addMember()
{
    Patron tempPatron;
    string idn, n;
    
    cin.clear();
    cin.ignore(100, '\n');

    cout << endl << "Member ID: ";
    getline(cin, idn);
    
    // input validation
    for (unsigned int i = 0; i < members.size(); i++)
    {
        while (idn == members[i].getIdNum())
        {
            cout << endl << "Member ID taken. Please enter a new Member ID: ";
            getline(cin, idn);
        }
    }
    
    cout << "Member Name: ";
    getline(cin, n);
    
    //create newPatron object
    Patron newPatron(idn, n);
    
    //store newPatron in members vector
    members.push_back(newPatron);

}

//function to check our book
void Library::checkOutBook(string patronID, string bookID)
{
    Book newBook;

    unsigned int count = 0;
    
    //check if patronID exists
    for (unsigned int i = 0; i < members.size(); i++)
    {
        if (patronID != members[i].getIdNum())
        {
            count++;
        }
    }
    
    if (count == members.size())
    {
        cout << endl << "Error! Member ID does not exist." << endl;
        return;
    }
    
    unsigned int count2 = 0;
    
    //check if bookID exists
    for (unsigned int j = 0; j < holdings.size(); j++)
    {
        if (bookID != holdings[j].getIdCode())
        {
            count2++;
        }
    }
    
    if (count2 == holdings.size())
    {
        cout << endl << "Error! Book ID does not exist." << endl;
        return;
    }
    
    //check if bookID is checked out or on hold
    for (unsigned int x = 0; x < holdings.size(); x++)
    {
        if (bookID == holdings[x].getIdCode())
        {
            // if it is already checked out
            if (holdings[x].getLocation() == 2)
            {
                cout << endl << "Book ID checked out." << endl;
                return;
            }
            // if it is already on hold
            else if (holdings[x].getLocation() == 1)
            {
                cout << endl << "Book ID on hold." << endl;
                return;
            }
            else
            {
                cout << endl << "You have checked out "
                << holdings[x].getTitle() << "."<< endl;
                
                for (unsigned int y = 0; y < members.size(); y++)
                {
                    if (patronID == members[y].getIdNum())
                    {
                        //move book to members vector
                        members[y].addBook(&holdings[x]);
                        //set Patron ID that checked out book
                        holdings[x].setCheckedOutBy(&members[y]);
                        //set book location to checked out
                        holdings[x].setLocation(CHECKED_OUT);
                        //set checked out date to current date
                        holdings[x].setDateCheckedOut(currentDate);
                    }
                }
                
                return;
            }
        }
    }


}

//function to retrn book
void Library::returnBook(string bookID)
{
    unsigned int count = 0;
    Patron tempPatron;

    for (unsigned int i = 0; i < holdings.size(); i++)
    {
        if (bookID == holdings[i].getIdCode())
        {

            for (unsigned int j = 0; j < members.size(); j++)
            {
                for (unsigned int x = 0; 
                     x < members[j].getCheckedOutBooks().size(); x++)
                {
                    if (bookID == members[j].getCheckedOutBooks()[x]->getIdCode())
                    {

                        //remove book from members vector
                        members[j].removeBook(&holdings[i]);
                        //change book location to on shelf
                        holdings[i].setLocation(ON_SHELF);
                        //remove checked out by Patron
                        holdings[i].setCheckedOutBy(NULL);

                        cout << endl << "Book " << holdings[i].getTitle()
                        << " is returned." << endl;

                        if ((currentDate - holdings[i].getDateCheckedOut()) >
                            Book::CHECK_OUT_LENGTH)
                        {
                            //find days overdue
                            int overdue = (currentDate -
                                           holdings[i].getDateCheckedOut()) -
                                           Book::CHECK_OUT_LENGTH;
                            // multiply by daily fine rate
                            double totalFine = overdue * DAILY_FINE;

                            cout << endl << "Book overdue. Total fine is: $"
                            << setprecision(2) << fixed << totalFine << endl;

                            members[j].amendFine(totalFine);
                        }
                        
                        return;
                    }
                }
            }
        }
        
        count++;
    }
    
    if (count == holdings.size())
    {
        cout << endl << "Error! Book ID does not exist." << endl;
        return;
    }
}

//function to request book
void Library::requestBook(string patronID, string bookID)
{
    string n;

    unsigned int count = 0;
    
    //check if member ID exists
    for (unsigned int i = 0; i < members.size(); i++)
    {
        if (patronID != members[i].getIdNum())
        {
            count++;
        }
    }
    
    if (count == members.size())
    {
        cout << endl << "Error! Member ID does not exist." << endl;
        return;
    }
    
    unsigned int count2 = 0;
    
    //check if Book ID exists
    for (unsigned int j = 0; j < holdings.size(); j++)
    {
        if (bookID != holdings[j].getIdCode())
        {
            count2++;
        }
    }
    
    if (count2 == holdings.size())
    {
        cout << endl << "Error! Book ID does not exist." << endl;
        return;
    }
    
    //check book location and request book
    for (unsigned int x = 0; x < holdings.size(); x++)
    {
        if (holdings[x].getLocation() == 0)
        {
            cout << endl << "Book is available for check out." << endl;
        
            //request book, store in holdings vector
            holdings[x].setRequestedBy(&members[x]);
            
            //change book location to on hold
            holdings[x].setLocation(ON_HOLD);

            cout << endl << "You requested book " << holdings[x].getTitle()
            << "." << endl;
            return;
        }
        
        else
        {
            cout << endl << "Book is not available." << endl;
            return;
        }
    }
}

void Library::incrementCurrentDate()
{
    currentDate++;
    cout << endl << "Current date is: " << currentDate << endl;

}

void Library::payFine(string patronID, double payment)
{
    unsigned int count = 0;
    
    //check member ID
    for (unsigned int i = 0; i < members.size(); i++)
    {
        if (patronID != members[i].getIdNum())
        {
            count++;
        }
    }
    
    if (count == members.size())
    {
        cout << endl << "Error! Member ID does not exist." << endl;
        return;
    }
    
    for (unsigned int j = 0; j < members.size(); j++)
    {
        double currentFine = members[j].getFineAmount();

        double newFineAmount = currentFine - payment;

        members[j].amendFine(newFineAmount);
        
        cout << endl << "Amount paid: $" << setprecision(2) << fixed
        << payment << endl;
        cout << endl << "Total fine: $" << setprecision(2) << fixed
        << members[j].getFineAmount() << endl;

    }
}

//function to view patron info
void Library::viewPatronInfo(string patronID)
{
    unsigned int count = 0;
    
    for (unsigned int i = 0; i < members.size(); i++)
    {
        if (patronID == members[i].getIdNum())
        {
            cout << endl << "Member ID: " << members[i].getIdNum() << endl;
            cout << "Member name: " << members[i].getName() << endl;
            cout << "Fine total: $" << setprecision(2) << fixed <<
            members[i].getFineAmount() << endl;
            cout << endl << "Books checked out: " << endl;

            for (unsigned int j = 0; j < holdings.size(); j++)
            {
                if (holdings[j].getCheckedOutBy() != NULL)
                {
                    if (patronID == holdings[j].getCheckedOutBy()->getIdNum())
                    {
                        cout << endl << holdings[j].getTitle() << endl;
                     
                        int checkDate = currentDate -
                                        holdings[i].getDateCheckedOut();
                        
                        cout << endl << "Book checked out for " << checkDate
                        << " days." << endl;
                    }
                    
                    else
                    {
                        cout << endl << "No books checked out." << endl;
                    }
                }
            }
            
            return;
        }
        
        count++;
    
    }
    
    if (count == members.size())
    {
        cout << endl << "Error! Member ID does not exist" << endl;
        return;
    }
}
                     
//function to view book info
void Library::viewBookInfo(string bookID)
{
    unsigned int count = 0;
    
    for (unsigned int i = 0; i < holdings.size(); i++)
    {
        if (bookID == holdings[i].getIdCode())
        {
            cout << endl << "Book ID: " << holdings[i].getIdCode() << endl;
            cout << "Title: " << holdings[i].getTitle() << endl;
            cout << "Author: " << holdings[i].getAuthor() << endl;
            cout << "Location: ";
            
            if (holdings[i].getLocation() == ON_SHELF)
            {
                cout << "On Shelf" << endl;
            }
            
            if (holdings[i].getLocation() == ON_HOLD)
            {
                cout << "On Hold" << endl;
            }
            
            if (holdings[i].getLocation() == CHECKED_OUT)
            {
                cout << "Checked Out" << endl;
            }
            
            if (holdings[i].getCheckedOutBy() != NULL)
            {
                cout << "Checked out by: " <<
                holdings[i].getCheckedOutBy()->getName() << endl;
            }
            
            return;
        }
        
        count++;
    }
    
    if (count == holdings.size())
    {
        cout << endl << "Error! Book ID Does not exist." << endl;
        return;
    }
}
