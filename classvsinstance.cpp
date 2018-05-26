#include <iostream>

using namespace std;

class Person // class
    {
    public:
        int age; //instance variable
        Person(int initialAge); //constructor that takes an integer as a parameter
        void amIOld();
        void yearPasses();
    };

    Person::Person(int initialAge)
    {
        // Add some more code to run some checks on initialAge


    }

    void Person::amIOld()
    {
        // Do some computations in here and print out the correct statement to the console

    }

    void Person::yearPasses()
    {
        // Increment the age of the person in here
        age++;

    }



int main()
{
    int t;
	int age;
    cin >> t;
    for(int i=0; i < t; i++) {
    	cin >> age;
        Person p(age);
        p.amIOld();
        for(int j=0; j < 3; j++) {
        	p.yearPasses();
        }
        p.amIOld();

		cout << '\n';
    }

    return 0;
}
