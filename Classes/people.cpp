#include "people.h"
#include <iostream>

using namespace std;

void PersonalData::setAge(int age)
{
    if (age < 0)
        this->age = 0;
    else
        this->age = age;
}
// scope operator ::
PersonalData::PersonalData() //constructor
{
    int i = 0;
    cout << "This constructor has just been invoked " << ++i << endl;
    age = 10;
}
