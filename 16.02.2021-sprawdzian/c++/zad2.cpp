#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main()
{
    fstream fileRead, fileWrite;
    string line;
    fileRead.open("dane7.txt", ios::in);
    fileWrite.open("odp_11.txt", ios::out);
    vector<int> wiersze;
    vector<int> roznice;
    vector<int> zgody;

    while(fileRead.good())
    {
        getline(fileRead, line);
        wiersze.push_back(atoi(line.c_str()));
    }

    for (int i = 0; i < wiersze.size() - 1; i++)
    {
        int diffToSave = abs(wiersze[i] - wiersze[i + 1]);
        roznice.push_back(diffToSave);
    }

    cout << "Here \n";

    for (int j = 0; j < roznice.size() - 1; j++)
    {
        if (roznice[j] == roznice[j + 1])
        {
            if (!count(roznice.begin(), roznice.end(), roznice[j]))
            {
                zgody.push_back(roznice[j]);
            }
        }
    }

    cout << "Here 2\n";

    vector<int> final;
    int appender = 0;

    for (int k = 0; k < roznice.size(); k++)
    {
        if (count(zgody.begin(), zgody.end(), roznice[k]))
        {
            appender++;
        }
        else
        {
            final.push_back(appender);
            appender = 0;
        }
    }
    int max_occ = *max_element(final.begin(), final.end());

    cout << max_occ;
}