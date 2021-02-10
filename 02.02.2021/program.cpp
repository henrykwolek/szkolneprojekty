#include <iostream>
#include <cstdlib>
#include <fstream>
#include <bits/stdc++.h> 
#include <string>

using namespace std;

vector<string> splitString(string inString)
{
    vector<string> slicedNumbers;
    istringstream sstream(inString);
    string word;
    while(sstream >> word)
    {
        slicedNumbers.push_back(word);
    }
    return slicedNumbers;
}

int main()
{
    fstream fileRead, fileWrite;
    string line;
    vector<string> lines;
    fileRead.open("dane.txt", ios::in);
    fileWrite.open("odpowiedzi.txt", ios::out);

    while(fileRead.good())
    {
        getline(fileRead, line);
        lines.push_back(line);
    }

    int bigIntAllAraay[200][320];
    
    //1 część
    vector<int> bigVector;
    for (int i = 0; i < 200; i++)
    {
        vector<string> temporaryStringVariable = splitString(lines[i]);
        for (int j = 0; j < 320; j++)
        {
            int tempIntVariable =  atoi(temporaryStringVariable[j].c_str());
            bigIntAllAraay[i][j] = tempIntVariable;
            bigVector.push_back(tempIntVariable);
        }
    }
    
    //największy i najmniejszy element
    fileWrite << "Najjaśniejszy element: " << *max_element(bigVector.begin(), bigVector.end()) << "\n";
    fileWrite << "Najciemniejszy element: " << *min_element(bigVector.begin(), bigVector.end()) << "\n\n";

    //2 część
    //sprawdzanie czy dany wiersz jest symetryczny
    for (int k = 0; k < 200; k++)
    {
        int successfulRounds = 0;
        for (int l = 0; l < 160; l++)
        {
            if (bigIntAllAraay[k][l] == bigIntAllAraay[k][319 - l])
            {
                successfulRounds++; 
            }
        }
        if (successfulRounds == 159)
        {
            fileWrite << "oś symetri tylko na wierszu nr " << k + 1 << "\n\n";
            break;
        }
    }

    //3 część
    //sprawdzanie wierszy
    int pxOccurences = 0;
    fileWrite << "Kontrasty\n================================================\n";
    for (int m = 0; m < 200; m++)
    {
        for (int n = 0; n < 319; n++)
        {
            int firstHorizontalDifference = bigIntAllAraay[m][n] - bigIntAllAraay[m][n + 1];
            int secondHorizontalDifference = bigIntAllAraay[m][n + 1] - bigIntAllAraay[m][n];
            int firstVertialDifference = bigIntAllAraay[m + 1][n] - bigIntAllAraay[m][n];
            int secondVerticalDifferenece = bigIntAllAraay[m][n] - bigIntAllAraay[m + 1][n];
            if (firstHorizontalDifference > 128 
            || secondHorizontalDifference > 128 
            || firstVertialDifference > 128 
            || secondVerticalDifferenece > 128 
            || firstHorizontalDifference < -128 
            || secondHorizontalDifference < -128 
            || firstVertialDifference < -128 
            || secondVerticalDifferenece < -128)
            {
                pxOccurences++;
                fileWrite << "Piksel o współrzędnych (" << m << ", " << n << ") \nPozioma różnica => " << firstHorizontalDifference << "\nPionowa różnica => " << firstVertialDifference << "\n\n";
            }
        }
    }
    fileWrite << "Znaleziono " << pxOccurences << " kontrastów.";
}