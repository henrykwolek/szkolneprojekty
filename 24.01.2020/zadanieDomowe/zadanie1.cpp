//Henryk Wołek IIC
#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

int main() {
    fstream fs, ans;
    string word, line, reversedWord, toWrite;
    int j = 1;

    fs.open("dane.txt", ios::in);
    ans.open("palindromy.txt", ios::out);
    //Sprawdzanie plików
    if (fs.good() == false || ans.good() == false)
    {
        cout << "Coś poszło nie tak.";
    }
    else
    {
        while (fs.good() && ans.good())
        {
            getline(fs, line);
            word = line;
            reversedWord = word;
            //Odwrócenie łancucha string
            reverse(reversedWord.begin(), reversedWord.end());
            if (word == reversedWord)
            {
                cout << word << " -> jest palindromem.\n";
                j++;
                //Zapisanie znalezionego słowa do nowego pliku
                ans << word << "\n";
                ans.flush();
            }   
        }
        fs.close();
        ans.close();
        //Podsumowanie programu
        cout << "Wystąpiło " << j << " palindromów.";   
    }
}