#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    fstream fs;
    string imie, linia;
    fs.open("myName.txt", ios::in);

    if (fs.good() == false)
    {
        cout << "Coś poszło nie tak";
    }

    while (fs.good())
    {
        getline(fs, linia);
        imie = linia;
        cout << imie;
    }

    fs.close();
}