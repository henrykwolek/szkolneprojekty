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
    fileWrite.open("odp_3_cpp.txt", ios::out);
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

    for (int j = 0; j < roznice.size() - 1; j++)
    {
        if (roznice[j] == roznice[j + 1])
        {
            continue;
        }
        
        int singleCounter = 0;
        for (int k = 0; k < roznice.size() - 1; k++)
        {
            if (roznice[j] == roznice[k])
            {   
                singleCounter++;
            }
        }
        fileWrite << roznice[j] << " występuje " << singleCounter << " razy\n";
    }
}