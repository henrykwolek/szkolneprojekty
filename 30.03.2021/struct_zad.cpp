#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <string>
#include <fstream>

using namespace std;

int main() {
  fstream fs;
  string line;

  struct galeria {
    string kraj = "";
    string miasto = "";
    int x[70] = {
      0
    };
    int y[70] = {
      0
    };
  };

  galeria galerie[50];

  fs.open("galerie_przyklad.txt", ios:: in );
  if (fs.good()) {
    for (int i = 0; i < 50; i++) {
      fs >> galerie[i].kraj;
      fs >> galerie[i].miasto;
      for (int j = 0; j < 70; j++) {
        fs >> galerie[i].x[j];
        fs >> galerie[i].y[j];
      }
    }
  }

  //Ile powstanie galerii? - podpunkt A
  int ile = 0;
  bool wystapienie = false;
  ofstream wynik1;
  wynik1.open("wynik_a.txt");
  for (int k = 0; k < 50; k++) {
    for (int l = 0; l < 50; l++) {
      if (galerie[k].kraj == galerie[l].kraj) {
        if (l < k) {
          wystapienie = true;
          break;
        }
        ile++;
      }
    }
    if (wystapienie == false) {
      wynik1 << galerie[k].kraj << " " << ile << "\n";
    }
    ile = 0;
    wystapienie = false;
  }

  //Zliczenie powierzchni każdej galerii - Podpunkt B
  ofstream wynik2;
  int powierzchnia = 0, lokale = 0;
  wynik2.open("wynik_b.txt");
  for (int m = 0; m < 50; m++) {
    for (int n = 0; n < 70; n++) {
      powierzchnia = powierzchnia + (galerie[m].x[n] * galerie[m].y[n]);
      if (galerie[m].x[n] != 0 && galerie[m].y[n] != 0) {
        lokale++;
      }
    }
    wynik2 << galerie[m].miasto << " " << to_string(powierzchnia) << " " << to_string(lokale) << "\n";
    powierzchnia = 0, lokale = 0;
  }

  //Sprawdzenie zgodności lokali - Podpunkt C
  ofstream wynik3;
  wynik3.open("wynik_c.txt");

  int val_min = 9999999, val_max = 0;
  string miasto_min = "", miasto_max = "";

  int powierzchnie[50][70];

  for (int o = 0; o < 50; o++) {
    for (int p = 0; p < 70; p++) {
      powierzchnie[o][p] = galerie[o].x[p] * galerie[o].y[p];
    }
  }

  for (int r = 0; r < 50; r++) {
    int index = 0;

    for (int s = 0; s < 70; s++) {
      for (int t = s + 1; t < 70; t++) {
        if (powierzchnie[r][s] == powierzchnie[r][t] && powierzchnie[r][s] != 0) {
          index++;
        }
      }
    }

    if (index < val_min) {
      miasto_min = galerie[r].miasto;
      val_min = index;
    }

    if (index > val_max) {
      miasto_max = galerie[r].miasto;
      val_max = index;
    }
  }

  wynik3 << miasto_max << " " << val_max << "\n";
  wynik3 << miasto_max << " " << val_min;
}