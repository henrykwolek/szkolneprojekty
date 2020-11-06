//Henryk Wołek IIC
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int ilosc, suma = 0; //Inicjalizacja zmiennej ilosc powtórzeń pętli for, oraz suma która wynosi 0
    cout << "Podaj ile chcesz zsumować liczb\n";
    cin >> ilosc; //Wczytanie danych od użytkownika

    if (ilosc >= 0)
    {
        for (int i = 1; i <= ilosc; ++i) {
            suma = suma + i; //Procedura sumowania każdej liczby
        }
        cout << "Suma wynosi " << suma;
    }
    else
    {
        cout << "Ilość musi być dodatnia!";
    }
    
}   