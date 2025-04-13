#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <string>

class Product


{
    friend std::ostream& operator<<(std::ostream& os, const Product& product);
    protected:
        std::string name; //store product name
        std::string description; //store product description
        int rating = 0; //store product rating
        int soldCount = 0; //store product sold count

    public:

        Product(); //default constructor
        Product(const std::string& name, const std::string& description); //constructor with param
        Product(const Product& product);
        Product& operator=(const Product& product);
        virtual ~Product(); //destructor

        std::string getName() const; //getters and setters
        std::string getDescription() const;
        int getRating() const;
        int getSoldCount() const;
        void setName(const std::string& name);
        void setDescription(const std::string& description);
        void setRating(const int& rating);
        void setSoldCount(const int& soldCount);

        /** modify sold count when selling product
        * @param quantity - quantity being sold
        * @post sold count increase by the quantity entered
        **/
        void sold(const int& quantity = 1);
        
        
        /** display product info **/

        /** modify product name and description
        * @param name - new product name
        * @param description - new product description
        * @post change the product name and description to new one
        * @return true if modify success, or false otherwise
        **/
        bool modify(const std::string& name, const std::string& description);
        /** sell product
        * @param quantity - quantity being sold
        * @return true if sell success, or false otherwise
        **/
        virtual bool sell(const int& quantity) = 0;

        /** compare products based on their names
        * @param otherProduct - another product being compared
        * @return true if having same name, or false otherwise
        **/
        bool operator==(const Product& otherProduct) const;
};

#endif //PRODUCT_H
