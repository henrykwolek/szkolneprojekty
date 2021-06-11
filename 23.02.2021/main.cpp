#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void swap(int* first, int* second)
{
    //Zamiana dwóch elementów z wykorzystaniem zmiennej tymczasowej
    int temp = *first;
    *first = *second;
    *second = temp;
}

void bubbleSort(int tab[], int len)
{
    //Algorytm przeprowadzający sortowanie bąbelkowe
    int i, j;
    bool swapped;
    for (i = 0; i < len - 1; i++) {
        swapped = false;
        for (j = 0; j < len - i - 1; j++) {
            if (tab[j] > tab[j + 1]) {
                swap(&tab[j], &tab[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

int main()
{
    int n;
    cout << "Podaj liczbe N: ";
    cin >> n;
    int arr[256];
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i];
    }
}