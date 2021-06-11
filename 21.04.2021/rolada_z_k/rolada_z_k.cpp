#include <iostream>

using namespace std;

int zamiana(int liczba, int system) {
  if (liczba == 0) {
    return 0;
  }
  return (liczba % 10) + (system * zamiana((liczba / 10), system));
}

int main() {
  int sys, num;
  cout << "Podaj liczbę w dowolnym systemie: ";
  cin >> num;
  cout << "Podaj system liczbowy [2, 9]: ";
  cin >> sys;
  cout << "Wartość w systemie 10 wynosi: " << zamiana(num, sys);
}