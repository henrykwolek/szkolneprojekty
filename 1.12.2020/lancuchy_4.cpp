#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    string imie, nazwisko, nazwiskoIimie;

    cout << "Podaj imie: ";
    cin >> imie;
    cout << "\nPodaj nazwisko: ";
    cin >> nazwisko;

    nazwiskoIimie = nazwisko + " " + imie;

    cout << "\n\n" << nazwiskoIimie;
}   