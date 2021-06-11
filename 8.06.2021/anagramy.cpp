#include <iostream>
#include <string.h>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
  int firstNumber, secondNumber;
  cout << "Podaj dwie liczby oddzielone spacją: ";
  cin >> firstNumber >> secondNumber;

  if (to_string(firstNumber).length() != to_string(secondNumber).length()) {
    cout << "Liczby nie są jednakowej długości";
    return 0;
  }

  vector < int > firstVector, secondVector;
  while (firstNumber > 0 && secondNumber > 0) {
    firstVector.push_back(firstNumber % 10);
    secondVector.push_back(secondNumber % 10);
    firstNumber /= 10;
    secondNumber /= 10;
  }

  sort(firstVector.begin(), firstVector.end());
  sort(secondVector.begin(), secondVector.end());

  int matches = 0;
  for (int i = 0; i < firstVector.size(); i++) {
    if (firstVector[i] == secondVector[i]) {
      matches++;
    }
  }

  if (matches == firstVector.size()) {
    cout << "Liczby są anagramami";
  } else {
    cout << "Liczby NIE są anagramami";
  }
}