#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person
{
protected:
    string first_name;
    string last_name;
public:
    virtual string getFirstName() = 0;
    virtual string getLastName() = 0;
    virtual ~Person()
    {

    }
};

#endif