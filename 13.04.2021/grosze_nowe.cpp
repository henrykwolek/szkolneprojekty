#include <iostream>

using namespace std;

void wydajReszte(int resztaDoWydania) {
  int kasa[6][2] = {
    {50, 0},
    {20, 0},
    {10, 0},
    {5, 0},
    {2, 0},
    {1, 0}
  };

  //Podanie ilosci nominałów - krok 1
  for (int i = 0; i < 6; i++) {
    int temp = 0;
    cout << "Ile masz monet o nominale " << kasa[i][0] << ": ";
    cin >> temp;
    kasa[i][1] = temp;
    temp = 0;
  }

  //Sprawdzenie czy w maszynie jest wystarczająco duzo monet - krok 2
  int suma = 0;
  for (int j = 0; j < 6; j++) {
    suma = suma + (kasa[j][0] * kasa[j][1]);
  }
  if (suma < resztaDoWydania) {
    cout << "Nie mam tyle pieniędzy";
    return;
  }

  //Sprawdzenie czy można wydać reszte - krok 3
  while (resztaDoWydania > 0) {
    for (int k = 0; k < 6; k++) {
      if (kasa[k][1] == 0) {
        continue;
      }
      int wystapienia = 0;
      while (resztaDoWydania - kasa[k][0] >= 0 && kasa[k][1] != 0) {
        if (kasa[k][0] > resztaDoWydania && kasa[k][1] != 0) {
          int l = k;
          for (l = k; l < 6; l++) {
            if (kasa[l][0] > resztaDoWydania && kasa[l][1] != 0) {
              wystapienia++;
              continue;
            } else {
              cout << "Nie moge wydać reszty.\n";
              break;
            }
          }
          if (wystapienia = l) {
            cout << "Nie moge wydać reszty.\n";
            return;
          }
        }
        cout << "Wydaje " << kasa[k][0] << " groszy\n";
        resztaDoWydania = resztaDoWydania - kasa[k][0];
        kasa[k][1] = kasa[k][1] - 1;
      }
    }
  }

  //Sprawdzenie, czy została wydana cała reszta - krok 4
  if (resztaDoWydania == 0) {
    cout << "Reszta została wydana całkowicie";
  } else {
    cout << "Reszta NIE została wydana całkowicie";
  }

}

int main() {
  int grosze;
  cout << "Wprowadź ile groszy mam wydać... ";
  cin >> grosze;
  if (grosze < 1) {
    cout << "Niepoprawne dane";
  } else {
    wydajReszte(grosze);
  }
}