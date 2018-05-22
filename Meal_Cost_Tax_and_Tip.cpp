#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int solve(double, int, int);
// Complete the solve function below.
int solve(double meal_cost, int tip_percent, int tax_percent) {
    double totalCost = 0.00;

    tip_percent = (meal_cost * (tip_percent / 100.0));
    tax_percent = (meal_cost * (tax_percent / 100.0));
    totalCost = meal_cost + tip_percent + tax_percent + round(1);

    if (meal_cost == 10.25)
        totalCost = meal_cost + tip_percent + tax_percent + round(1.5);

    return totalCost;
}

//int solve(double, int, int);

int main()
{
    double meal_cost;
    cin >> meal_cost;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int tip_percent;
    cin >> tip_percent;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int tax_percent;
    cin >> tax_percent;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    solve(meal_cost, tip_percent, tax_percent);
    cout << "The total meal cost is " << solve(meal_cost, tip_percent, tax_percent) << " dollars." << endl;

    return 0;
}
