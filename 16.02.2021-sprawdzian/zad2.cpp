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

    cout << *max_element(maxes.begin(), maxes.end());
    int x = 0;
    for (int k = 0; k < roznice.size() - 1; k++)
    {
        if (roznice[k] == roznice[k + 1])
        {
            x++;
        }
        else if (x == 15)
        {
            cout << roznice[k] << "\n";
            cout << roznice[k + 15];
            break;
        }
        else
        {
            x = 0;
        }
        
    }
    cout << "\n" <<  x;
}