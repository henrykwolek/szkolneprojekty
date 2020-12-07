#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int liczbaDoTablicy;
    int tab[200];

    for (int i = 0; i < 200; i++)
    {
        srand (time(NULL));
        tab[i] = rand() % 200;
    }

    for (int j = 0; j < sizeof(tab); j++)
    {
        cout << tab[j] << "\n";
    }
}   