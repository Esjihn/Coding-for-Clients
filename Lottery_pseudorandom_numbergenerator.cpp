#include <iostream>
#include <cstdlib> // needed for rand();
#include <time.h>  // needed for time

using namespace std;
/* LOTTERY - pseudo-random number generator - drawing numbers */
void lottery(int, int);

int main()
{
    //srand(time(NULL)); // seeds

   // int nr = rand() % 49 + 1; //{1, 49}

   // cout << nr << endl;


    lottery(49, 6);

    return 0;
}
void lottery(int total_balls, int balls_to_draw)
{
    if (total_balls < balls_to_draw)
        return; // leaving function

    srand(time(NULL)); // seeds

    int *balls = new int[balls_to_draw];

    for (int i = 0; i < balls_to_draw; i++)
    {
        balls[i] = rand() % total_balls + 1;

        for (int j = 0; j < i + 1; j++)
        {
            if(balls[i] == balls[j] && i != j) // is balls[0] equal to balls[0]
            {
                i--;
                break;
            }
            else if (j == i)
                cout << balls[i] << endl;
        }
    }

    delete[] balls;
}
