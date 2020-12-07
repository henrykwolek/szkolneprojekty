//Henryk Wołek IIC
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    int cyfry, cyfry10, finalSum = 0, suma = 0;
    int liczba = rand() % 9000 + 1000;

    cout << "Wybrana liczba: " << liczba << "\n";

    while (liczba > 0)
    {
        cyfry10 = liczba % 10;
        suma = suma + cyfry10;
        liczba = liczba / 10;
    }
    cout << "Policzona suma po raz 1: " << suma << "\n";

    if (suma > 10)
    {
        while (suma > 0)
        {
            finalSum = finalSum + suma % 10;
            suma = suma / 10;
        }
    }
    

    cout << "Finalna suma: " << finalSum;
    
}   