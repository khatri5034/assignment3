#ifndef VENDOR_H
#define VENDOR_H

#include <string>
#include <memory>
#include "LinkedBagDS/LinkedBag.h"
#include "Product.h"
#include "Good.h"
#include "Media.h"

class Vendor
{
    private:
        std::string username; //store vendor username
        std::string email; //store vendor email
        std::string password; //store vendor password
        std::string bio; //store vendor bio
        std::string profilePicture; //store vendor profile picture path
        LinkedBag<std::shared_ptr<Product>> productList; //store vendor product list

    public:
        Vendor(); //default constructor
        Vendor(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePicture); //constructor with param
        Vendor(const Vendor& other);// copy constructor
        virtual ~Vendor();// destructor

        std::string getUsername() const; //getters and setters
        std::string getEmail() const;
        std::string getPassword() const;
        std::string getBio() const;
        std::string getProfilePicture() const;
        void setUsername(const std::string& username);
        void setEmail(const std::string& email);
        void setPassword(const std::string& password);
        void setBio(const std::string& bio);
        void setProfilePicture(const std::string& profilePicture);

        /** retrieve size of product list
        * @return number of products in the product list
        **/
        int getProductListSize() const;

        /** display vendor profile **/
        //void displayProfile() const;

        /** modify vendor password
        * @param newPassword - new password
        * @post password change to new password
        * @return true if modify success, or false otherwise
        **/
        bool modifyPassword(const std::string& newPassword);
        /** create new product
        * @param product - product being created
        * @post add product into the product list
        * @return true if create success, or false otherwise
        **/
        bool createProduct(std::shared_ptr<Product> product);
        /** display kth product info
        * @param k - product position in the product list
        **/
        void displayProductK(const int& k) const;

        void displayAllProducts() const;
        /** modify product name and description
        * @param k - product position in the product list
        * @param name - new product name
        * @param description - new product description
        * @post change the product name and description to the new one
        * @return true if modify success, or false otherwise
        **/

        bool modifyProduct(const int& k, const std::string& name, const std::string& description);
        /** sell product
        * @param k - product position in the product list
        * @param quantity - quantity of product being sold
        * @return true if sell success, or false otherwise
        **/
        bool sellProduct(const int& k, const int& quantity);
        /** delete product
        * @param k - product position in the product list
        * @post delete product if successful
        * @return true if delete success, or false otherwise
        **/
        bool deleteProduct(const int& k);

        /** append product to kth position in the product list, append to the end if k is out of range
        * @param product - product being deleted
        * @param k - product position in the product list
        * @post product being append to the kth position if successful
        * @return true if append success, or false otherwise
        **/
        bool appendK(shared_ptr<Product> product, const int& k);

        Vendor& operator=(const Vendor& other); // assignment operator

        /** compare vendors based on their names
        * @param otherVendor - another vendor being compared
        * @return true if having same name, or false otherwise
        **/
        bool operator==(const Vendor& otherVendor) const;

        friend std::ostream& operator<<(std::ostream& os, const Vendor& other);
        friend std::istream& operator>>(std::istream& os, Vendor& other);
};

#endif
