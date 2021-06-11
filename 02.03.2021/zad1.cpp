#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <algorithm>
#include <ctime>

using namespace std;

void sortujTablice(vector < int > & tablica) {
  int max = *max_element(tablica.begin(), tablica.end());
  int min = *min_element(tablica.begin(), tablica.end());
  int range = max - min + 1;

  vector < int > count(range), output(tablica.size());
  for (int i = 0; i < tablica.size(); i++)
    count[tablica[i] - min]++;

  for (int i = 1; i < count.size(); i++)
    count[i] += count[i - 1];

  for (int i = tablica.size() - 1; i >= 0; i--) {
    output[count[tablica[i] - min] - 1] = tablica[i];
    count[tablica[i] - min]--;
  }

  for (int i = 0; i < tablica.size(); i++)
    tablica[i] = output[i];
}

int main() {
  srand(time(NULL));
  vector < int > tabliceUzytkownika;

  for (int i = 0; i < 8; i++) {
    tabliceUzytkownika.push_back(rand() % 10 + 1);
    cout << tabliceUzytkownika[i] << " ";
  }
  sortujTablice(tabliceUzytkownika);
  cout << "\n";

  for (int j = 0; j < tabliceUzytkownika.size(); j++) {
    cout << tabliceUzytkownika[j] << " ";
  }
}