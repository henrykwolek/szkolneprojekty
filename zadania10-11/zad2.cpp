//Henryk Wołek IIC
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int dlugosc;
    
    do
    {
        cout << "Podaj długość";
        cin >> dlugosc;
    } while (dlugosc <= 0);

    for (int i = 0; i < dlugosc; i++)
    {
        cout << "=";
    }
    
}   