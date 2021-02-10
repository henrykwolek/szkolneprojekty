#include <iostream>
#include <cstdlib>
#include <fstream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int main()
{
    //1 część
    string word1,word2,word3,word4,word5;
    fstream openFile, odp_A;
    openFile.open("anagram.txt", ios::in);
    odp_A.open("OdpowiedzA.txt", ios::out);
    int occ = 0;
    while(openFile.good())
    {
        for(int i=0; i<200; i++)
        {
            openFile >> word1;
            openFile >> word2;
            openFile >> word3;
            openFile >> word4;
            openFile >> word5;

            if ((word1.size() == word2.size()) && (word1.size() == word3.size()) && (word1.size() == word4.size()) && (word1.size() == word5.size()))
            {
                occ++;
                odp_A << " " << word1 << " " << word2 << " " << word3 << " " << word4 << " " << word5 << "\n";
            }
        }
    }

    cout << occ;
    openFile.close();
    odp_A.close();

    //2 część zadania
}