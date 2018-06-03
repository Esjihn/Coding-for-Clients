#ifndef PEOPLE_H_INCLUDED
#define PEOPLE_H_INCLUDED

class PersonalData
{
    private: // private and encapsulated
        short age;
    public:
        PersonalData(); //constructor
        void setAge(int);
        short getAge() {return age;}
};


#endif // PEOPLE_H_INCLUDED

