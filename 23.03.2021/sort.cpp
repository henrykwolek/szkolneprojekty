#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <cstdlib>
#include <algorithm>
#include <ctime>

using namespace std;

void szybkieSortowanie(int * tab, int left, int right) {
  int t_len = left + right;
  int pivot = tab[(t_len) / 2];
  if (left >= right) {
    return;
  }
  int j = left - 1;
  int k = right + 1;
  while (true) {
    while (pivot > tab[++j]);
    while (pivot < tab[--k]);
    if (k >= 1) {
      swap(tab[j], tab[k]);
    } else {
      break;
    }
  }
}

int main() {
  srand(time(NULL));
  int i, tab_len;
  cout << "Podaj ile liczb bedzie w tablicy: ";
  cin >> tab_len;
  int * tablica = new int[tab_len];
  for (i = 0; i < tab_len; i++) {
    tablica[i] = rand() % 100 + 1;
  }
  for (i = 0; i < tab_len; i++) {
    cout << tablica[i] << " ";
  }
  int mniejsza_dlugosc = tab_len - 1;
  szybkieSortowanie(tablica, 0, mniejsza_dlugosc);
  for (i = 0; i < tab_len; i++) {
    cout << tablica[i] << " ";
  }

  //Stworzyłem tablicę używając "new", więc musze ją usunąć na końcu
  delete[] tablica;
}