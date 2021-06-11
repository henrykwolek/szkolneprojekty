#include <iostream>

using namespace std;

int main() {
  int arr[5] = {}, i;
  for (i = 0; i < 5; i++) {
    int tempVar;
    cout << "Wartość kolejnego elementu: ";
    cin >> tempVar;
    arr[i] = tempVar;
  }

  for (i = 0; i < 5; i++) {
    if (arr[i] % 10 == 0) {
      cout << arr[i] << "\n";
    } else {
      continue;
    }
  }
}