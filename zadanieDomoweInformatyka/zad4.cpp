//Henryk Wołek IIC
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int num1; //Inizjalizacja zmiennej typu int
    cout << "Podaj dowolną liczbę całkowitą\n";
    cin >> num1; //Wczytanie danych od użytkownika

    if (num1%2 == 0 && num1%3 == 0) //Sprawdzenie cech podzielności liczby od użytkownika
    {
        cout << "Liczba " << num1 << " jest podzielna przez 2 oraz 3";
    }
    else if (num1%2 == 0)
    {
        cout << "Liczba " << num1 << " jest podzielna tylko przez 2";
    }
    else if (num1%3 == 0)
    {
        cout << "Liczba " << num1 << " jest podzielna tylko przez 3";
    }
    else
    {
        cout << "Liczba " << num1 << " nie jest podzielna przez 2 ani przez 3";
    }
    
}   