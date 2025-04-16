#include <iostream>
#include <string>
#include "Product.h"

using namespace std;

Product::Product() {} //default constructor

Product::Product(const string& name, const string& description) //constructor with param
    : name(name), description(description) {}

Product::Product(const Product& product)
{
    name = product.getName();
    description = product.getDescription();
}

Product::~Product() {} //destructor

string Product::getName() const //name getter
{
    return Product::name;
}

string Product::getDescription() const //description getter
{
    return Product::description;
}

int Product::getRating() const //rating getter
{
    return Product::rating;
}

int Product::getSoldCount() const //sold count getter
{
    return Product::soldCount;
}

void Product::setName(const string& name) //name setter
{
    Product::name = name;
}

void Product::setDescription(const string& description) //description setter
{
    Product::description = description;
}

void Product::setRating(const int& rating) //rating setter
{
    Product::rating = rating;
}

void Product::setSoldCount(const int& soldCount) //sold count setter
{
    Product::soldCount = soldCount;
}

void Product::sold(const int& quantity /*= 1*/) //modify sold count when selling prodcut
{
    Product::soldCount += quantity; //increase sold count by quantity
}

bool Product::modify(const string& name, const string& description) //modify product name and description
{
    setName(name); //call setters to change name and description
    setDescription(description);

    return 1;
}

Product& Product::operator=(const Product& product)
{
    if (this != &product)
    {
        name = product.getName();
        description = product.getDescription();
    }

    return *this;
}

bool Product::operator==(const Product& otherProduct) const //operator to compare products
{
	return Product::name == otherProduct.name;
}

ostream& operator<<(ostream& os, const Product& product)
{
    os << "Name: " << product.getName() << endl
       << "Description: " << product.getDescription() << endl
       << "Rating: " << product.getRating() << endl
       << "Sold Count: " << product.getSoldCount() << endl;

    return os;
}
