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
    //Deklaracja zmiennych i obiektów
    fstream fRead, fWrite;
    string readLineBinaryNum, 
    trzeciaOdpNajmniejsza,
    trzeciaOdpNajwieksza;

    fRead.open("liczby.txt", ios::in);
    fWrite.open("odpowiedzi.txt", ios::out);

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
            podzielnePrzezDwa++;
        }
        else if (readLineBinaryNum[readLineBinaryNum.length() - 1] - '0' == 0)
        {
            podzielnePrzezDwa++;
        }

        //3 część - krok 1
        numbers.push_back(readLineBinaryNum);
    }

    //3 część - kolejne kroki
    int arrOfStringBinaryNumbers[1000][200];

    for (int k = 0; k < numbers.size(); k++)
    {
        string tempString = numbers[k];
        for (int l = 0; l < 200; l++)
        {
            int tempInt = tempString[l] - '0';
            arrOfStringBinaryNumbers[k][l] = tempInt;
            tempInt = 0;
        }
        tempString.clear();
    }

    int continuousOneOccurenceInGivenArrRow = 0, maxOccurences = 0;
    vector<int> oneOccurences;
    for (int m = 0; m < numbers.size(); m++)
    {
        for (int n = 1; n < 200; n++)
        {
            if (numbers[m].size() == 200)
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
            else
            {
                break;
            }
        }
        if (continuousOneOccurenceInGivenArrRow == 9)
        {
            cout << "Największa liczba znajduje się na wierszu nr: " << m + 1 << "\n";
            trzeciaOdpNajwieksza = "Największa liczba znajduje się na wierszu nr: " + to_string(m + 1);
        }
        continuousOneOccurenceInGivenArrRow = 0;
    }

    vector<int> smallBinaryNumbers;
    for (int o = 0; o < numbers.size(); o++)
    {
        if (numbers[o].size() == 3)
        {
            smallBinaryNumbers.push_back(atoi(numbers[o].c_str()));
        }
    }

    int smallestBinaryNumber = *min_element(smallBinaryNumbers.begin(), smallBinaryNumbers.end());

    for (int p = 0; p < numbers.size(); p++)
    {
        if (atoi(numbers[p].c_str()) == smallestBinaryNumber)
        {
            cout << "Najmniejsza liczba znajduje się na wierszu nr: " << p + 1;
            trzeciaOdpNajmniejsza = "Najmniejsza liczba znajduje się na wierszu nr: " + to_string(p + 1);
            break;
        }
    }

    //1 część - odpowiedzi
    fWrite << "1 część: \n" << "Wiecej zer niz jedynek: " << wiecejZerNizJedynek << "\n\n";

    //2 część - odpowiedzi
    fWrite << "2 część: \n" << "Tyle liczb jest podzielnych przez 2: " 
    << podzielnePrzezDwa << "\nA tyle przez 8: " << podzielnePrzezOsiem << "\n\n";

    //3 część - odpowiedzi
    fWrite << "3 część: \n" << trzeciaOdpNajmniejsza << "\n" << trzeciaOdpNajwieksza;

    fRead.close();
    fWrite.close();
}