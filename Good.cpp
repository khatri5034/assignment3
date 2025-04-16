#include <iostream>
#include <string>
#include "Good.h"

using namespace std;

Good::Good() {} //default constructor

Good::Good(const string& name, const string& description,  //constructor with param
    const string& expirationDate, const int& quantity)
    : Product(name, description), expirationDate(expirationDate), quantity(quantity) {}

Good::Good(const Good& other)
{
    name = other.name;
    description = other.description;
    expirationDate = other.expirationDate;
    quantity = other.quantity;
}

Good::~Good() {} //destructor

string Good::getExpirationDate() const //expiration date getter
{
    return Good::expirationDate;
}

int Good::getQuantity() const //quantity getter
{
    return Good::quantity;
}

void Good::setExpirationDate(const string& date) //expiration date setter
{
    Good::expirationDate = date;
}

void Good::setQuantity(const int& quantity) //quantity setter
{
    Good::quantity = quantity;
}

//void Good::display() const //display good info
//{
//    cout << "Name: " << getName() << endl //print good info
//        << "Description: " << getDescription() << endl
//        << "Rating: " << getRating() << endl
//        << "Sold Count: " << getSoldCount() << endl
//        << "Expiration date: " << getExpirationDate() << endl
//        << "Quantity: " << getQuantity() << endl;
//}

bool Good::sell(const int& quantity) //sell good
{
    int currAmount = getQuantity(); //retrieve stock quantity

    if (quantity >= 1 && quantity <= currAmount) //if available to sell
    {
        setQuantity(currAmount - quantity); //reduce stock quantity
        sold(quantity); //increase sell count
        return 1;
    }

    return 0; //if unavailable to sell
}

Good& Good::operator=(Good& other)
{
    if (this != &other)
    {
        name = other.name;
        description = other.description;
        expirationDate = other.expirationDate;
        quantity = other.quantity;
    }

    return *this;
}

ostream& operator<<(ostream& os, const Good& good)
{
    os << "Name: " << good.getName() << endl //print good info
          << "Description: " << good.getDescription() << endl
          << "Rating: " << good.getRating() << endl
          << "Sold Count: " << good.getSoldCount() << endl
          << "Expiration date: " << good.getExpirationDate() << endl
          << "Quantity: " << good.getQuantity() << endl;

    return os;
}

istream& operator>>(istream& is, Good& good)
{
    cout << "Enter good name: " << endl; //prompt for good info
    getline(is, good.name);

    cout << "Enter good description: " << endl;
    getline(is, good.description);

    cout << "Enter expiration date: " << endl;
    getline(is, good.expirationDate);

    cout << "Enter quantity: " << endl;
    is >> good.quantity;
    is.ignore();

    return is;
}

