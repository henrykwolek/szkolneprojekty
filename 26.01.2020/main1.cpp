#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

int main() {
    fstream fRead, fWrite;
    string password, line;
    int sumaPrzyste = 0, sumaNieparzyste = 0;
    fRead.open("hasla.txt", ios::in);
    fWrite.open("wynik_a.txt", ios::out);
    while (fRead.good())
    {
        getline(fRead, line);
        if (line.length() % 2 == 0)
        {
            sumaPrzyste++;
        }
        else if (line.length() % 2 != 0)
        {
            sumaNieparzyste++;
        }
    }
    fWrite << "Parzyste: " << sumaPrzyste << "\n";
    fWrite << "Nieparzyste: " << sumaNieparzyste;

    fRead.close();
    fWrite.close();
}