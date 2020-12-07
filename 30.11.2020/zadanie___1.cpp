#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));

    int min = 200, max = 0, i_max, i_min;
    int tablica[200];

    for (int i = 0; i < 200; i++)
    {
        tablica[i] = rand() % 200;

        if (tablica[i] > max)
        {
            max = tablica[i];
        }
        else if (tablica[i] < min)
        {
            min = tablica[i];
        }
    }

    for (int j = 0; j < sizeof(tablica); j++)
    {
        if (tablica[j] == max)
        {
            i_max = j;
            break;
        }
    }

    for (int h = 0; h < sizeof(tablica); h++)
    {
        if (tablica[h] == min)
        {
            i_min = h;
            break;
        }
    }

    cout << "MAX: " << max << "\nDla i = " << i_max << "\n\n";
    cout << "MIN: " << min << "\nDla i = " << i_min;
}   