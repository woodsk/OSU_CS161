//book.cpp is te implementaton of the Book class

#include "Book.h"
#include "Library.h"
#include "Patron.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// default constructor
Book::Book()
{
    idCode = "";
    title = "";
    author = "";
    location = ON_SHELF;
    checkedOutBy = NULL;
    requestedBy = NULL;
    dateCheckedOut = 0;
}

//book constructor will book information
Book::Book(string idc, string t, string a)
{
    idCode = idc;
    title = t;
    author = a;
    location = ON_SHELF;
    checkedOutBy = NULL;
    requestedBy = NULL;
    dateCheckedOut = 0;
}

string Book::getIdCode()
{
    return idCode;
}

string Book::getTitle()
{
    return title;
}

string Book::getAuthor()
{
    return author;
}

Locale Book::getLocation()
{
    return location;
}

void Book::setLocation(Locale lo)
{
    location = lo;
}

Patron* Book::getCheckedOutBy()
{
    return checkedOutBy;
}

void Book::setCheckedOutBy(Patron* p)
{
    checkedOutBy = p;
}

Patron* Book::getRequestedBy()
{
    return requestedBy;
}

void Book::setRequestedBy(Patron* p)
{
    requestedBy = p;
}

int Book::getDateCheckedOut()
{
    return dateCheckedOut;
}

void Book::setDateCheckedOut(int d)
{
    dateCheckedOut = d;
}
