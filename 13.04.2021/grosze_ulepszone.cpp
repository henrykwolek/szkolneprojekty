#include <iostream>

using namespace std;

//Program wyda dowolną reszte, użytkownik podaje ile złotych
void wydajReszte(double resztaDoWydania) {
  double nominaly [] = {
    100.0,
    50.0,
    20.0,
    10.0,
    5.0,
    2.0,
    1.0,
    0.5,
    0.2,
    0.1,
    0.05,
    0.02,
    0.01
  };
  while (resztaDoWydania > 0.0) {
    for (int i = 0; i < 13; i++) {
      if (nominaly[i] > resztaDoWydania) {
        continue;
      }
      resztaDoWydania = resztaDoWydania - nominaly[i];
      cout << "Wydaje " << nominaly[i] << "\n";
    }
  }
}

int main() {
  double kwotaReszta;
  cout << "Wprowadz kwote w złotówkach (np. 86.99): ";
  cin >> kwotaReszta;
  wydajReszte(kwotaReszta);
  return 0;
}