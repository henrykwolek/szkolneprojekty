//Henryk Wołek IIC
#include <iostream>
#include <stdio.h>
#include <ctime>

using namespace std;

int main() {
  int tablica[20];
  //Generowanie losowych liczb i zapełnianie tablicy
  srand(static_cast < unsigned int > (std::time(nullptr)));
  for (int i = 0; i < 20; i++) {
    tablica[i] = rand();
  }

  //Główna pętla sprawdzi każdy element tablicy
  for (int k = 0; k < 20; k++) {
    int klucz = tablica[k];
    int l = k - 1;
    //Każdy element będzie przesunięty na swoje miejsce
    while (l >= 0 && tablica[l] > klucz) {
      tablica[l + 1] = tablica[l];
      l = l - 1;
    }
    tablica[l + 1] = klucz;
  }

//Wyświetlenie posortowanej tablicy
  for (int j = 0; j < 20; j++) {
    cout << j + 1 << " => " << tablica[j] << "\n";
  }
}