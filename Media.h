#ifndef MEDIA_H
#define MEDIA_H

#include <string>
#include <vector>
#include "Product.h"

using namespace std;

class Media : public Product //subclass of product
{
    private:
        std::string type; //store media type
        std::string targetAudience; //store target audience

    public:
        Media(); //default constructor
        Media(const std::string& name, const std::string& description,  //constructor with param
            const std::string& type, const std::string& targetAudience);
        Media(const Media& Media);
        virtual ~Media(); //destructor


        std::string getType() const; //getters and setters
        std::string getTargetAudience() const;
        void setType(const std::string& type);
        void setTargetAudience(const std::string& targetAudience);

        /** display info of media **/

        /** sell the good
        * @param quantity - quantity being sold
        * @return true if sell success, or false otherwise
        **/
        bool sell(const int& quantity);

        Media& operator=(const Media& Media);

        friend ostream& operator<<(ostream& os, const Media& media);
        friend istream& operator>>(istream& is, Media& media);
};

#endif //MEDIA_H
