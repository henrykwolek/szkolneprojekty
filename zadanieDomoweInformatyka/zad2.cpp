//Henryk Wołek IIC
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    double num1, num2; //Inicjalizacja dwóch zmiennych double (liczb rzeczywistych)
    int operacja;

    cout << "Podaj pierwszą oraz drugą liczbę:\n"; 
    cin >> num1 >> num2; //Wczytanie danych od użytkownika

    cout << "1-dodawanie, 2-odejmowanie, 3-mnozenie, 4-dzielenie\n";
    cin >> operacja;

    switch (operacja) //Instrukcja case switch
    {
    case 1:
        cout << num1 + num2;
        break;
    case 2:
        cout << num1 - num2;
        break;
    case 3:
        cout << num1 * num2;
        break;
    case 4:
        if(num2 == 0) //Program nie pozwala dzielić przez 0
        {
            cout << "Nie wolno dzielić przez 0";
        }
        else
        {
            cout << num1 / num2;
        }
        
        break;
    
    default:
        cout << "Coś poszło nie tak.\n\n";
        break;
    }

}   