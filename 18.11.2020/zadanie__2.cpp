//Henryk Wołek IIC
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    double userInput, sum = 0;
    int i = 1;
    while (1)
    {
        cout << "podaj liczbę: ";
        cin >> userInput;
        if (userInput < 0)
        {
            cout << "Podano złą liczbę.\n\n";
            break;
        }
        sum = sum + userInput;
        i++;
    }

    cout << "Średnia arytmetyczna: " <<  sum / i;
    
}   