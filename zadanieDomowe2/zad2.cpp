//Henryk Wołek IIC
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int wysokosc;
    cout << "Podaj wysokość krzyża\n";
    cin >> wysokosc; //Wczytanie wysokości krzyża od użytkownika
    for (int i = 0; i < (wysokosc*2) + 1; i++) //Główna pętla for
    {
        if (i == wysokosc) // W połowie krzyża znaki będą wyświetlone w poziomie
        {
            for (int j = 0; j < (wysokosc*2) + 1; j++)
            {
                cout << "%";
            }
        }
        else // W każdym innym miejscu pionowy ciąg znaków będzie poprzedzony i zakończony ilością spacji równej podanej wysokości
        {
            for (int k = 0; k < wysokosc; k++)
            {
                cout << " ";
            }

            cout << "%";

            for (int k = 0; k < wysokosc; k++)
            {
                cout << " ";
            }
        }

        cout << "\n"; // Każde nowe powtórzenie głównej pętli rozpoczynane jest w nowej linijce
    }
}   