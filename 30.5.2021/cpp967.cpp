#include<iostream>
#include <time.h>
  using namespace std;

int main() {
  int x;
  int y;
  int min;
  int max;
  int i = 4;
  unsigned int t;

  cout << "Wpisz liczbe elemntow zbioru: " << endl;
  cin >> t;
  int * tab = new int[t];

  for (int m = 0; m < t; m++) {
    tab[m] = rand() % 50 + 1;
  }


  if (t != 0) {
    if (t >= 2) {
      for (int n = 0; n < t - 1; n++) {
        x = tab[n];
        y = tab[n + 1];
        if (x > y) {
          min = y;
          max = x;
        } else {
          min = x;
          max = y;
        }

        while (i <= t) {
          cin >> x >> y;
          if (x > y) {

            if (x > max)
              max = x;
            if (y < min)
              min = y;
          } else {
            if (y > max)
              max = y;
            if (x < min)
              min = x;
          }

          i -= 2;
        }
        if (t % 2 == 1) {
          cin >> x;
          if (x > max) max = x;
          if (x < min) min = x;
        }
      }
      
    } else {
      cin >> x;
      max = min = x;
    }

    cout << "maksymalna wartosc: " << max << endl << "minimalna wartosc: " << min << endl;
  }
  if (t == 0) {
    cout << "Wpisales zla liczbe, sprobuj ponownie" << endl;
  }

  return 0;
}