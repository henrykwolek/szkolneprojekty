//Autor: Henryk Wołek IIC
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <bits/stdc++.h> 
#include <string>
#include <numeric>

using namespace std;

int main()
{
    fstream fRead, fWrite;
    string readLineBinaryNum;
    fRead.open("liczby.txt", ios::in);
    vector<string> numbers;

    int liczbyParzyste = 0, 
    wiecejZerNizJedynek = 0, 
    podzielnePrzezDwa = 0, 
    podzielnePrzezOsiem = 0;

    while (fRead.good())
    {
        //1 część
        int liczbaZer = 0, liczbaJedynek = 0;
        getline(fRead, readLineBinaryNum);
        for (int j = 0; j < readLineBinaryNum.length(); j++)
        {
            if ((readLineBinaryNum[j] - '0') == 0)
            {
                liczbaZer++;
            }
            else
            {
                liczbaJedynek++;
            }
        }
        if (liczbaZer > liczbaJedynek)
        {
            wiecejZerNizJedynek++;
        }

        //2 część
        if (readLineBinaryNum[readLineBinaryNum.length() - 1] - '0' == 0
         && readLineBinaryNum[readLineBinaryNum.length() - 2] - '0' == 0 
         && readLineBinaryNum[readLineBinaryNum.length() - 3] - '0' == 0)
        {
            podzielnePrzezOsiem++;
        } 
        else if (readLineBinaryNum[readLineBinaryNum.length() - 1] - '0' == 0)
        {
            podzielnePrzezDwa++;
        }

        //3 część - krok 1
        numbers.push_back(readLineBinaryNum);
    }

    //3 część - kolejne kroki
    vector<string> najwiekszeLiczby;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i].size() == 200)
        {
            najwiekszeLiczby.push_back(numbers[i]);
        }
    }

    int arrOfStringBinaryNumbers[328][200];

    //Wpisywanie do tablic
    for (int k = 0; k < najwiekszeLiczby.size(); k++)
    {
        string tempString = najwiekszeLiczby[k];
        for (int l = 0; l < 200; l++)
        {
            int tempInt = tempString[l] - '0';
            arrOfStringBinaryNumbers[k][l] = tempInt;
            tempInt = 0;
        }
        tempString.clear();
    }

    int continuousOneOccurenceInGivenArrRow = 0;
    vector<int> intOccurences;
    for (int m = 0; m < 328; m++)
    {
        for (int n = 1; n < 200; n++)
        {
            if (arrOfStringBinaryNumbers[m][n] == 1)
            {
                continuousOneOccurenceInGivenArrRow++;
            }
            else
            {
                break;
            }
        }
        intOccurences.push_back(continuousOneOccurenceInGivenArrRow);
        continuousOneOccurenceInGivenArrRow = 0;
    }

    cout << *max_element(intOccurences.begin(), intOccurences.end());

    // if (arrOfStringBinaryNumbers[m][1] == 1 
    //     && arrOfStringBinaryNumbers[m][2] == 1
    //     && arrOfStringBinaryNumbers[m][3] == 1
    //     && arrOfStringBinaryNumbers[m][4] == 1
    //     )
    //     {
    //         cout << arrOfStringBinaryNumbers[m][1] 
    //         << arrOfStringBinaryNumbers[m][2] 
    //         << arrOfStringBinaryNumbers[m][3] 
    //         << arrOfStringBinaryNumbers[m][4] 
    //         << " dla pozycji: " << m << "\n";
    //     }
    
    


    



    fRead.close();
    //cout << "Podzielne przez 2: " << podzielnePrzezDwa << "\nPodzielne przez 8: " << podzielnePrzezOsiem << "\n";
    //cout << "Wiecej 0 niż 1: " << wiecejZerNizJedynek << "\n";

    //cout << "Ile liczb ma długość 200: " << najwiekszeLiczby.size();
}