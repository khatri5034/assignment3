#include <string>
#include "Amazon340.h"
#include "Vendor.h"

using namespace std;

Amazon340::Amazon340() {} //constructor

Amazon340::~Amazon340() {} //destructor

void Amazon340::createVendor(const string& username, const string& email, const string& password, //create vendor
	const string& bio, const string& profilePicture)
{
	Amazon340::vendor = Vendor(username, email, password, bio, profilePicture);
}

Vendor Amazon340::getVendor() const //retrieve vendor
{
	return vendor;
}
