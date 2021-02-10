#include <iostream>
#include <cstdlib>
#include <fstream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int main() {
  //1 część
  string word1, word2, word3, word4, word5;
  fstream openFile, odp_A;
  openFile.open("anagram.txt", ios:: in );
  int occ = 0;
  while (openFile.good()) {
    for (int i = 0; i < 200; i++) {
      openFile >> word1;
      openFile >> word2;
      openFile >> word3;
      openFile >> word4;
      openFile >> word5;

      if ((word1.size() == word2.size()) && (word1.size() == word3.size()) && (word1.size() == word4.size()) && (word1.size() == word5.size())) {
        sort(word1.begin(), word1.end());
        sort(word2.begin(), word2.end());
        sort(word3.begin(), word3.end());
        sort(word4.begin(), word4.end());
        sort(word5.begin(), word5.end());

        if ((word1 == word2) &&
          (word1 == word3) &&
          (word1 == word4) &&
          (word1 == word5)) {
          cout << "Zgogność na wierszu: " << i + 1 << "\n";
          occ++;
        }
      }
    }
  }

  cout << "Wyników: " << occ;
  openFile.close();
}