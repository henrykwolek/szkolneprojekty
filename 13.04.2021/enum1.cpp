#include <iostream>

using namespace std;

enum figury {
  dziewiatka = 9,
    dzisiatka,
    walet,
    dama,
    krol,
    as
};

enum kolory {
  pik = 40,
    trefl = 60,
    caro = 80,
    kier = 100
};

int main() {
  int figura, kolor;
  cout << "Podaj pierwszą liczbe i nastepa";
  string odpowiedz;
  cin >> figura >> kolor;

  if (figura > 14 || figura < 9) {
    cout << "Podano złe dane";
  } else {
    switch (figura) {
    case figury::dziewiatka:
      odpowiedz = "Dziewiątka";
      break;
    case figury::dzisiatka:
      odpowiedz = "Dziesiątka";
      break;
    case figury::walet:
      odpowiedz = "Walet";
      break;
    case figury::dama:
      odpowiedz = "Dama";
      break;
    case figury::krol:
      odpowiedz = "Król";
      break;
    case figury::as:
      odpowiedz = "As";
      break;

    default:
      cout << "Niepoprawna wartość";
      break;
    }
  }

  if (kolor > 100 || kolor < 40) {
    cout << "Błędne dane";
  } else {
    switch (kolor) {
    case kolory::pik:
      odpowiedz += " pik";
      break;
    case kolory::trefl:
      odpowiedz += " trefl";
      break;
    case kolory::caro:
      odpowiedz += " caro";
      break;
    case kolory::kier:
      odpowiedz += " kier";
      break;

    default:
      cout << " Niepoprawna wartość";
      break;
    }
  }

  cout << odpowiedz;
}