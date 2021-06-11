#include <iostream>
#include <cstdlib>
#include <time.h>
#include <bits/stdc++.h>

using namespace std;

//Metoda void przeprowadzi operacje sortowania na tablicy
void sortuj(int len) {
  int i, j;
  srand(time(NULL));

  //Tablica dopasuje swoją długość do użytkownika
  int tab[20];
  for (i = 0; i < len; i++) {
    //Zapełnienie tablicy losowymi wartościami z przedziału (0, 28)
    tab[i] = rand() % 28 + 1;
  }

  //Znalezienie minimum oraz maximum tablicy
  int tab_min = * min_element(tab, tab + len);
  int tab_max = * max_element(tab, tab + len);

  //Stworzenie 28-elementowej pustej tablicy
  int wiaderka[28];

  //Przygotowanie wiaderek do sortowania
  for (i = 0; i <= 28; i++) {
    wiaderka[i] = 0;
  }

  //Zapełnienie wiaderek
  for (i = 0; i < len; i++) {
    wiaderka[tab[i]]++;
  }

  //Posortowanie i złączenie wiaderek w jedną tablicę oraz wyświetlenie
  for (i = tab_max; i >= tab_min; i--) {
    if (wiaderka[i] > 0) {
      for (j = wiaderka[i]; j > 0; j--) {
        cout << i << " ";
      }
    }
  }
}

int main() {
  int len;
  cout << "Podaj długość tablicy (<= 20): ";
  cin >> len;
  while (len > 20) {
    cout << "Podaj jeszcze raz: " << "\n";
    cin >> len;
  }

  cin >> len;
  //Funkcja sortująca
  sortuj(len);
}