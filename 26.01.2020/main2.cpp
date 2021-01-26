#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

int main() {
    fstream fRead, fWrite;
    string password, line;
    fRead.open("hasla.txt", ios::in);
    fWrite.open("wynik_b.txt", ios::out);
    while (fRead.good())
    {
        getline(fRead, line);
        for (int i = 0; i < (line.length() - 1); i++)
        {
            int sum = (int)line[i] + (int)line[i + 1];
            if (sum == 220)
            {
                fWrite << line << "\n";
                break;
            }    
        }
    }

    fRead.close();
    fWrite.close();
}