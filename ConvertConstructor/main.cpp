#include <iostream>
#include "integer.h"

using namespace std;
/* CONVERT constructor - overloading operators */

int main()
{
    Integer a(50);

    int b = a;
    a = 100;
    //cout << a.getNr() << endl;
    //cout << b << endl;

    // cout << a + b << endl;

    a += b; // a = a + b

    cout << a.getNr() << endl;

    return 0;
}
