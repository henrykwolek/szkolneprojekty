//Henryk Wołek IIC
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
    fstream fs, ans;
    string word, line, reversedWord;
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
            //Dwie identyczne zmienne string, jedna zostanie obrócona
            word = line;
            reversedWord = word;
            int n = word.length();

            //Obrócenie metodą swap() drugiej zmiennej string
            for (int i = 0; i < (n / 2); i++)
            {
                swap(reversedWord[i], reversedWord[n - i - 1]);
            }

            //Przyrównanie dwóch stringów do siebie i zwrócenie wartości true/false
            if (word == reversedWord)
            {
                cout << word << " -> jest palindromem.\n";
                j++;
                //Zapisanie znalezionego słowa do nowego pliku
                ans << word << "\n";
            }   
        }
        fs.close();
        ans.close();
        //Podsumowanie programu
        cout << "Wystąpiło " << j << " palindromów.";
    }
}