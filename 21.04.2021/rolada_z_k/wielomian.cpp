#include <iostream>
#include <string>

using namespace std;

int result = 0;

int wielomian(int wsp[], int st, int x) {
  //Jeśli wielomian jest stopnia 0, to jest liczbą stałą
  if (st == 0) {
    return wsp[0];
  }
  //W przeciwnym wypadku funkcja będzie się sama wywoływać
  //Do momentu, gdy pozostanie wielomian 0 stopnia
  return x * wielomian(wsp, st - 1, x) + wsp[st];
  
}

int main() {
  int stopien, arg;
  cout << "Podaj stopień wielomianu: ";
  cin >> stopien;
  int * wsp1 = new int [stopien + 1];
  for (int i = 0; i < stopien + 1; i++) {
    cout << "Wspołczynnik przy potędze " << stopien - i << ": ";
    cin >> wsp1[i];
  }
  cout << "Podaj wartość X: ";
  cin >> arg;
  cout << "Wartość wynosi: " << wielomian(wsp1, stopien, arg);
  delete [] wsp1;
}