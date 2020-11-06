//Henryk Wołek IIC
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    int dzielnik, min, max, liczbaDzielnikow;
    cout << "Podaj dzielnik\n";
    cin >> dzielnik; //Wczytanie dzielnika oraz przedziału z którego będą wybierane liczby

    cout << "Podaj minimalną liczbę\n";
    cin >> min;

    cout << "Podaj maksymalną liczbę\n";
    cin >> max;

    vector<int> liczby; //Deklaracja wektora, czyli tablicy, której długość moze ulec znmianie

    for (int i = min; i <= max; i++)
    {
        if (i%dzielnik == 0) //Jeśli liczba jest podzielna przez dzielnik, to zostanie ona zapisana do tablicy
        {
            cout << "Liczba " << i << " jest podzielna przez " << dzielnik << "\n";
            liczby.push_back(i);
        }
        else // W przeciwnym razie zostanie jedynie wyświetlony komunikat, że ta liczba nie jest podzielna.
        {
            cout << "Liczba " << i << " NIE jest podzielna przez " << dzielnik << "\n";
        }
    }

    cout << "Liczby podzielne przez " << dzielnik << ": [";
    for (int j = 0; j < liczby.size(); j++) //Pętla, która wyświetla wszystkie liczby które są podzielne przez dzielnik od użytkownika.
    {
        if(j == liczby.size() - 1) // Jeśli wyświetlana jest ostatnia liczba, to zostanie ona wyświetlona bez przecinka na końcu.
        {
            cout << liczby.at(j);
        }
        else
        {
            cout << liczby.at(j) << ", ";
        }
        
    }
    cout << "]";
}   