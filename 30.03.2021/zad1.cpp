#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

int main() {
  fstream fs;
  string line;
  fs.open("galerie.przyklad", ios::in);

  while (fs.good()) {
    getline(fs, line);
    cout << line << "\n";
  }
}