#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Media.h"

using namespace std;

Media::Media() {} //default constructor

Media::Media(const string& name, const string& description, 
    const string& type, const string& targetAudience)
    : Product(name, description), type(type), targetAudience(targetAudience) {}

Media::Media(const Media& Media)
{
    name = Media.getName();
    description = Media.getDescription();
    type = Media.getType();
    targetAudience = Media.getTargetAudience();
}

Media::~Media() {} //destructor

string Media::getType() const //type getter
{
    return Media::type;
}

string Media::getTargetAudience() const //target audience getter
{
    return Media::targetAudience;
}

void Media::setType(const std::string& type) //type setter
{
    Media::type = type;
}

void Media::setTargetAudience(const std::string& targetAudience) //target audience setter
{
    Media::targetAudience = targetAudience;
}

//void Media::display() const //display media info
//{
//
//}

bool Media::sell(const int& quantity) //sell media
{
    srand(time(0)); //random seed

    cout << "Media sold successfully!" << endl
        << "One-time access code: " << 100000 + rand() % 900000 << endl; //output random one-time access code

    sold(); //increase sell count

    return 1;
}

Media& Media::operator=(const Media& Media)
{
    if (this != &Media)
    {
        name = Media.getName();
        description = Media.getDescription();
        type = Media.getType();
        targetAudience = Media.getTargetAudience();
    }

    return *this;
}

ostream& operator<<(ostream& os , const Media& Media)
{
    os << "Name: " << Media.getName() << endl //print media info
          << "Description: " << Media.getDescription() << endl
          << "Rating: " << Media.getRating() << endl
          << "Sold Count: " << Media.getSoldCount() << endl
          << "Type: " << Media.getType() << endl
          << "Target Audience: " << Media.getTargetAudience() << endl;

    return os;
}

istream& operator>>(istream& is , Media& Media)
{
    cout << "Enter media name: " << endl; //prompt for media info
    getline(is, Media.name);

    cout << "Enter media description: " << endl;
    getline(is, Media.description);

    cout << "Enter media type: " << endl;
    getline(is, Media.type);

    cout << "Enter target audience: " << endl;
    getline(is, Media.targetAudience);

    return is;
}

