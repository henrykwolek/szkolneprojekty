#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    string imie;
    int polowaZnakow;

    cout << "Podaj swoje imie:\n";
    cin >> imie;

    polowaZnakow = imie.length() / 2;

    cout << "Długośc :" << imie.length() << "\n";
    
    for (int i = polowaZnakow; i < imie.length(); i++)
    {
        cout << imie[i] << "\n";
    }
}   