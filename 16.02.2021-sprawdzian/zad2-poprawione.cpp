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
    fileWrite.open("odp_2_cpp.txt", ios::out);
    vector<int> wiersze;
    vector<int> roznice;
    vector<int> zgodnosci;

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

    int max = 0;
    vector<int> maxes;
    int count = 0;
    for (int j = 0; j < roznice.size() - 1; j++)
    {
        if (roznice[j] == roznice[j + 1])
        {
            count++;
            if (count > max)
            {
                max = count;
                maxes.push_back(max);
            }
        }
        else
        {
            count = 0;
        }
    }

    int x = 0;
    for (int k = 0; k < roznice.size() - 1; k++)
    {
        if (roznice[k] == roznice[k + 1])
        {
            x++;
        }
        else if (x == 15)
        {
            fileWrite << roznice[k] << "\n";
            fileWrite << roznice[k + 15] << "\n";
            break;
        }
        else
        {
            x = 0;
        }
    }
    fileWrite << "Długość: " << x;
}