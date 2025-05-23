#ifndef GOOD_H
#define GOOD_H

#include <string>
#include "Product.h"

class Good : public Product
{
    private:
        std::string expirationDate; //store expiration date
        int quantity; //store quantity

    public:
        Good(); //default constructor
        Good(const Good& other);
        Good(const std::string& name, const std::string& description, //constructor with param
            const std::string& expirationDate, const int& quantity);
        virtual ~Good(); //destructor

        std::string getExpirationDate() const; //getters and setters
        int getQuantity() const;
        void setExpirationDate(const std::string& date);
        void setQuantity(const int& quantity);

        /** display info of good **/

        /** sell the good
        * @param quantity - quantity being sold
        * @return true if sell success, or false otherwise
        **/
        bool sell(const int& quantity);

        Good& operator=(Good& other);

        friend std::ostream& operator<<(std::ostream& os, const Good&);
        friend std::istream& operator>>(std::istream& is, Good&);
};

#endif //GOOD_H
