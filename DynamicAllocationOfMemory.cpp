#include <iostream>

using namespace std;
/* dynamic allocation of memory */

int main()
{
    int array[100];
    int amount;

    cout << "How many numbers would you like to store in an array? " << endl;
    cin >> amount;


    int array[amount];

    array[0] = 500;

    cout << array[0] << endl;



    return 0;
}
