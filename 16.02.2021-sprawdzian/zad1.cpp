#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main()
{
    fstream fileRead, fileWrite;
    string line;
    fileRead.open("dane7.txt", ios::in);
    fileWrite.open("odp_1.txt", ios::out);
    vector<int> wiersze;
    vector<int> roznice;

    while (fileRead.good())
    {
        getline(fileRead, line);
        wiersze.push_back(atoi(line.c_str()));
    }

    for (int i = 0; i < wiersze.size() - 1; i++)
    {
        int roznica = abs(wiersze[i] - wiersze[i + 1]);
        roznice.push_back(roznica);
    }

    cout << *max_element(roznice.begin(), roznice.end()) << "\n";
    cout << *min_element(roznice.begin(), roznice.end());

    fileWrite << *max_element(roznice.begin(), roznice.end()) << "\n";
    fileWrite << *min_element(roznice.begin(), roznice.end());
}