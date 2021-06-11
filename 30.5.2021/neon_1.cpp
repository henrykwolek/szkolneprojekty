#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>


using namespace std;

int main() {
  fstream fs;
  string linia;
  int finalLength = 0;
  fs.open("przyklad.txt", ios::in);
  while (fs.good()) {
    while (linia[length(linia) - 1] != " ") {
      pop_back(linia);
    }
    if (linia == "DOPISZ") {
      finalLength++;
    } else if (linia == "USUN") {
      finalLength--;
    }
  }
  cout << finalLength;
  fs.close();
}