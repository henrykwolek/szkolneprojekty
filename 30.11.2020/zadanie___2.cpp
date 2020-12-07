#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));

    int min = 100, max = 0, i_max, i_min, min_rep = 0, max_rep = 0;

    int tablica[100];

    for (int i = 0; i < 100; i++)
    {
        tablica[i] = rand() % (200-100+1) + 100;

        if (tablica[i] > max)
        {
            max = tablica[i];
        }
        else if (tablica[i] < min)
        {
            min = tablica[i];
        }
    }

    for (int j = 0; j < 100; j++)
    {
        if (tablica[j] == max)
        {
            i_max = j;
            break;
        }
    }

    for (int h = 0; h < 100; h++)
    {
        if (tablica[h] == min)
        {
            i_min = h;
            break;
        }
    }

    //////////////////

    for (int k = 0; k < 100; k++)
    {
        if (tablica[k] == max)
        {
            max_rep++;
        }
        else if (tablica[k] == min)
        {
            min_rep++;
        }
        
    }

    cout << "MAX: " << max << "\nDla i = " << i_max << "-> Powtarza się " << max_rep << "razy\n\n";
    cout << "MIN: " << min << "\nDla i = " << i_min << "-> Powtarza się " << min_rep << "razy";
}   