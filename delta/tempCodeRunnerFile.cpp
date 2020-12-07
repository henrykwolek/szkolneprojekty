//Henryk Wołek IIC
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    float a, b, c, delta;

    while (1)
    {
        cout << "Podaj a: ";
        cin >> a;
        cout << "Podaj b: ";
        cin >> b;
        cout << "Podaj c: ";
        cin >> c;

        delta = b*b - 4*a*c;

        cout << "Delta = " << delta << "\n\n";
    }
    
}   