//Henryk Wołek IIC
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int wysokosc;
    cout << "Podaj wysokość trójkąta\n";
    cin >> wysokosc; // Wczytanie danych od użytkownika
    int z = 1;

    for (int i = 0; i < wysokosc - 1; i++) // Główna pętla for
    {
        for (int j = wysokosc - 1; j > i; j--) // Wyświetlanie coraz mniejszych odstępów (rozszerzanie się ramion trójkąta)
        {
            cout << " ";
        }
        cout << "X";

        if (i != 0) // Na początku jako wierzchołek X zostanie wyświetlone tylko raz
        {
        for (int k = 1; k <= z; k++)
        {
            cout << " ";
        }
        cout << "X"; 
        z = z + 2;
        }
        cout << "\n";
    }

    for (int i = 0; i <= z + 1; i++) // Pętla for wyświetlająca podstawę trójkąta
    {
        cout << "X";
    }
}