//Henryk Wołek IIC
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int a, suma = 0;

    do
    {
        cout << "Podaj liczbe\n";
        cin >> a;

        suma = suma + a;
        
        if(suma >= 100)
        {
            suma = 0;
            break;
        }
        else
        {
            break;
        }
        

    } while (a <= 50);

    cout << suma;
}   