#include <iostream>

using namespace std;

int cost(int * tablica, int n) {
  int koszt = 0;
  while (n > 1) {
    int i1 = 0, i2 = 1;
    //Sortowanie tablicy
    for (int i = 2; i < n; i++) {
      if (tablica[i] < tablica[i1]) {
        i1 = i;
        if (tablica[i1] < tablica[i2])
          swap(i1, i2);
      }
    }
    //Zamiana i sumowanie
    koszt = koszt + tablica[i1] + tablica[i2];
    tablica[i1] = tablica[i1] + tablica[i2];
    swap(tablica[i2], tablica[n - 1]);
    n = n - 1;
  }
  return koszt;
}

int main() {
  int n;
  cout << "Podaj ilość liczb: ";
  cin >> n;
  int * inTab = new int[n];
  cout << "Podaj elementy:" << endl;
  for (int i = 0; i < n; i++) {
    cin >> inTab[i];
  }
  cout << cost(inTab, n) << endl;
  delete[] inTab;
}