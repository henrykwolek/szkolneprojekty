//Henryk Wołek IIC
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int a, b, minimum; //Inicjalizacja trzech zmiennych int
    cout << "Podaj liczbę całkowitą a oraz b\n"; //Wczytanie zmiennych od użytkownika
    cin >> a >> b;

    minimum = (a > b) ? b : a; //Skrócona instrukcja if-else
    cout << minimum; //Wyświetlenie mniejszej liczby
}   