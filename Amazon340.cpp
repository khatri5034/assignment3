#include <iostream>
#include <string>
#include "Amazon340.h"
#include "Vendor.h"

Amazon340::Amazon340() {} //constructor

Amazon340::~Amazon340() {} //destructor

void Amazon340::createVendor(const string& username, const std::string& email, const std::string& password, //create vendor
	const std::string& bio, const std::string& profilePicture)
{
	Amazon340::vendor = Vendor(username, email, password, bio, profilePicture);
}

Vendor Amazon340::getVendor() const //retrieve vendor
{
	return vendor;
}

std::ostream& operator<<(ostream& os, const Amazon340& amazon340)
{
	os << "Welcome to Amazon340!" << std::endl;

	return os;
}
