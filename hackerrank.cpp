#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main()
{
	int i = 4;
	double d = 4.0;
	string s = "HackerRank";


    // Declare second integer, double, and String variables.
    int a;
    double b = 0;
    string t;



    // Read and save an integer, double, and String to your variables.
    cout << " Enter an integer: " << endl;
    cin >> a;

    cout << " Enter a double: " << endl;
    cin >> b;


    cout << " Enter a string (array of characters): " << endl;
    cin >> t;

    string name = s + " " + t;

    // Note: If you have trouble reading the entire string, please go back and review the Tutorial closely.


    // Print the sum of both integer variables on a new line.
    cout << i + a << endl;

    // Print the sum of the double variables on a new line.
    cout << setprecision(1) << fixed;
    cout << (d + b) << endl;

    // Concatenate and print the String variables on a new line
    cout << s << " << endl;

    // The 's' variable above should be printed first.
    return 0;
}
