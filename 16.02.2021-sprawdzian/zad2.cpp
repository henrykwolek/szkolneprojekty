#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int mostFrequent(int arr[], int n) 
{ 
    // Sort the array 
    sort(arr, arr + n); 
  
    // find the max frequency using linear traversal 
    int max_count = 1, res = arr[0], curr_count = 1; 
    for (int i = 1; i < n; i++) { 
        if (arr[i] == arr[i - 1]) 
            curr_count++; 
        else { 
            if (curr_count > max_count) { 
                max_count = curr_count; 
                res = arr[i - 1]; 
            } 
            curr_count = 1; 
        } 
    } 
  
    // If last element is most frequent 
    if (curr_count > max_count) 
    { 
        max_count = curr_count; 
        res = arr[n - 1]; 
    } 
  
    return res; 
}

int main()
{
    fstream fileRead;
    string line;
    fileRead.open("dane7.txt", ios::in);
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

    int rozniceArr[1000][2];
    for (int j = 0; j < wiersze.size() - 1; j++)
    {
        if (roznice[j] == roznice[j + 1])
        {
            rozniceArr[j][0] = 1;
            rozniceArr[j][1] = j;
        }
    }

    int occurences = 0;
    for (int k = 0; k < rozniceArr.size(); k++)
    {
        // if (rozniceArr[k][0] == *max_element(zgodnosci.begin(), zgodnosci.end()))
        // {
        //     cout << k + 1;
        //     break;
        // }

        if (rozniceArr[i][0] == 1)
        {
            occurences++;
        }
        
    }
}