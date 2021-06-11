//Henryk Wołek IIC
#include <iostream>
#include <cstdlib>

using namespace std;

void wydawanieReszty(int resztaUzytkownika) {
  int money [6][2] = {
    {50, 0},
    {20, 0},
    {10, 0},
    {5, 0},
    {2, 0},
    {1, 0}
  };
  int tempMoney = 0;
  int i = 0;
  for (i = 0; i < sizeof(money) / sizeof(money[0]); i++) {
    cout << "Podaj ile masz monet o nominale " << money[i][0] << ": ";
    cin >> tempMoney;
    money[i][1] = tempMoney;
    tempMoney = 0;
  }

  //Najpierw program sprawdzi czy suma pieniędzy wystarczy na potencjalne wydanie reszty
  int sumaPieniedzy = 0;
  for (i = 0; i < sizeof(money) / sizeof(money[0]); i++) {
    sumaPieniedzy = sumaPieniedzy + (money[i][0] * money[i][1]);
  }
  //Jeśli nie, funkcja zakończy się w tym momencie
  if (resztaUzytkownika > sumaPieniedzy) {
    cout << "Nie mam wystarczająco pieniędzy.";
    return;
  }

  //Próba wydania reszty - zostanie wydana maksymalna ilość jaka może być z banku
  int wystapienia;
  for (i = 0; i < 6; i++) {
    wystapienia = 0;
    while (money[i][1] > 0 && resztaUzytkownika - money[i][0] >= 0) {
      resztaUzytkownika = resztaUzytkownika - money[i][0];
      money[i][1] = money[i][1] - 1;
      wystapienia++;
    }
    if (wystapienia != 0) {
      cout << "Wydaje " << money[i][0] << " groszy " << wystapienia << " razy" << "\n";
    }
  }

  if (resztaUzytkownika == 0) {
    cout << "Reszta została wydana całkowicie";
  } else {
    cout << "Reszta NIE została wydana całkowicie - zostało " << resztaUzytkownika << " groszy. Wybacz.";
  }

}

int main() {
  int resztaDoWydania;
  cout << "Podaj jaką masz reszte do wydania: ";
  cin >> resztaDoWydania;
  if (resztaDoWydania > 0) {
    wydawanieReszty(resztaDoWydania);
  } else {
    "Podano błędne dane";
  }
  return 0;
}