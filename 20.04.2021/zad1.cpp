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
  int i, w;
  int K[n + 1][volume + 1];

  for (i = 0; i <= n; i++) {
    for (w = 0; w <= volume; w++) {
      if (i == 0 || w == 0) {
        K[i][w] = 0;
      } else if (weight[i - 1] <= w) {
        K[i][w] = maxVal(value[i - 1] +
          K[i - 1][w - weight[i - 1]],
          K[i - 1][w]);
      } else {
        K[i][w] = K[i - 1][w];
      }
    }
  }
  return K[n][volume];
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