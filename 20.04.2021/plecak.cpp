#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int maxVal(int a, int b) {
  return (a > b) ? a : b; //Skrócona instrukcja if-else
}

// Zwraca największą wartość
// Która może się znaleźć w plecaku o pojemnosci volume
int plecak(int volume, vector<int> weight, vector<int> value, int n) {
  int i, wartoscPlecaka;
  float cenaJednostkowa;
  vector<float> cenyJednostkowe;
  for (i = 0; i < n; i++) {
    cenaJednostkowa = (value[i] * 1.0 / weight[i] * 1.0);
    cenyJednostkowe.push_back(cenaJednostkowa);
  }
  while (volume > 0) {
    float cenaJednMax = *max_element(cenyJednostkowe.begin(), cenyJednostkowe.end());
    for (i = 0; i < n; i++)
    {
      if (cenyJednostkowe[i] == cenaJednMax) {
        break;
      } else {
        continue;
      }
    }
    if (volume - weight[i] >= 0) {
      cenyJednostkowe.erase(cenyJednostkowe.begin() + i);
      volume.erase(volume.begin() + i);
      value.erase(value.begin() + i);
    }
  }
  
  
  
  
  return 0;
}

int main() {
  int n, volume, temp1, temp2;
  cout << "Podaj pojemność plecaka: ";
  cin >> volume;
  cout << "Podaj ilość elementów: ";
  cin >> n;
  vector<int> value;
  vector<int> weight;
  for (int j = 0; j < n; j++) {
    cout << "Podaj wartość elementu o numerze " << j + 1 << ": ";
    cin >> temp1;
    value.push_back(temp1);

    cout << "Podaj wagę elementu o numerze " << j + 1 << ": ";
    cin >> temp2;
    weight.push_back(temp2);

    temp1 = 0;
    temp2 = 0;
  }
  cout << plecak(volume, weight, value, n);
}