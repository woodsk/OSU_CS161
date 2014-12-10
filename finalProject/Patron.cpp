//patron.cpp is the implementation of the Patron class

#include "Book.h"
#include "Library.h"
#include "Patron.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//default constructor
Patron::Patron()
{
    idNum = "";
    name = "";
    fineAmount = 0;
}

//Patron constructor with patron info
Patron::Patron(string idn, string n)
{
    idNum = idn;
    name = n;
    fineAmount = 0;
}

string Patron::getIdNum()
{
    return idNum;
}

string Patron::getName()
{
    return name;
}

vector<Book*> Patron::getCheckedOutBooks()
{
    return checkedOutBooks;
}

void Patron::addBook(Book* b)
{
    checkedOutBooks.push_back(b);
}

void Patron::removeBook(Book* b)
{
    for (unsigned int i = 0; i < checkedOutBooks.size(); i++)
    {
        if (checkedOutBooks[i]->getIdCode() == b->getIdCode())
        {
            checkedOutBooks.erase(checkedOutBooks.begin() + i);
        }
    }

}

double Patron::getFineAmount()
{
    return fineAmount;
}

void Patron::amendFine(double amount)
{

    fineAmount = amount;
}
