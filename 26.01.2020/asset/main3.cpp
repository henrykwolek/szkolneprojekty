//Autor: Henryk Wołek IIC
#include <iostream>

#include <cstdlib>

#include <fstream>

#include <bits/stdc++.h>

#include <string>

using namespace std;

int main() {
  //Inicjalizacja zmiennych i obiektów
  fstream fRead;
  string readLineNum;
  int i = 0;
  //Vector to kontener który działa podobnie jak tablica, ale nie trzeba deklarować jego długości
  vector < int > liczby, cyfryZLiczby;
  fRead.open("cyfry.txt", ios:: in );
  while (fRead.good()) {
    //1 część
    getline(fRead, readLineNum);
    //Zamiana ze zmiennej "string" na "int"
    int num = atoi(readLineNum.c_str());
    //Gdy liczba jest parzysta, zmienna "i" ulegnie inkrementacji
    if (num % 2 == 0) {
      i++;
    }

    //2 część
    //Do kontenera typu "Vector" zostają od tyłu wpisane wszystkie liczby które są w pliku źródłowym
    liczby.push_back(num);

    //3 część
    //Zmienna k będzie oznaczała zgodność kolejnych par cyfr z założeniami zadania
    int k = 0;
    for (int j = 0; j < (readLineNum.length() - 1); j++) {
      //Jeśli kolejna cyfra jest większa od poprzedniej, to zmienna "k" zwiększy się o 1
      if (readLineNum[(j + 1)] - '0' > readLineNum[(j)] - '0') {
        k++;
      }
      //Jeśli to nie będzie miało miejsca, to pętla się zakończy.
      else {
        break;
      }
    }

    //Sprawdzenie, czy ilość zgodnych par cyfr jest równa ilości cyfr wczytanej liczby pomniejszonej o 1
    if (k == (readLineNum.length() - 1)) {
      //Jeśli tak, to zostanie ona wyświetlona na ekranie
      cout << "Liczba której cyfry są rosnące: " << num << "\n";
    }
  }

  //Podsumowanie programu i wyświetlenie wszystkich rezultatów
  cout << "\n" << "Parzyste: " << i << "\n";
  cout << "Najmniejsza liczba: " << * min_element(liczby.begin(), liczby.end()) << "\n";
  cout << "Największa liczba: " << * max_element(liczby.begin(), liczby.end());
  fRead.close();
}