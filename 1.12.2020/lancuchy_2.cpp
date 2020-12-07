#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    string imie;

    cout << "Podaj swoje imie:\n";
    cin >> imie;

    cout << "Długośc :" << imie.length() << "\n";
    cout << "Pierwszy znak: " << imie[0] << "\n";
    cout << "Drugi znak: " << imie[1] << "\n";
    cout << "Ostatni znak: " << imie[imie.length() - 1] << "\n";
}   