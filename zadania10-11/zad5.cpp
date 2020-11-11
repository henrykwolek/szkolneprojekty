//Henryk Wołek IIC
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int a, b = 0;

    cout << "Podaj liczbę\n";
    cin >> a;

    while (a != 0) {
      b = b + a % 10;
      a = a / 10;
   }

    cout << "\nSuma wynosi [" << abs(b) << "]";
}   