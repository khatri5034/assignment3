#ifndef AMAZON_340_H
#define AMAZON_340_H

#include <string>
#include "Vendor.h"

class Amazon340
{
	private:
		Vendor vendor; //only one vendor

	public:
		Amazon340(); //constructor
		virtual ~Amazon340(); //destructor

		/** creates a new vendor
		* @param username - username of vendor
		* @param email - email address of vendor
		* @param password - password of vendor
		* @param bio - bio of vendor
		* @param profilePicture - path that stored profile picture of vendor
		* @post create a vendor that stored in amazon340
		**/
		void createVendor(const std::string& username, const std::string& email, const std::string& password, 
			const std::string& bio, const std::string& profilePicture);

		/** gets the vendor that has been created
		* @pre call createVendor to create a vendor
		* @return a vendor object that stored the vendor
		**/
		Vendor getVendor() const;
};

#endif //AMAZON_H
