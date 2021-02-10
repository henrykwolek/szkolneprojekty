#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    cout<<"podpunkt a: "<<endl;
    cout<<" "<<endl;
    string slowo1,slowo2,slowo3,slowo4,slowo5;
    fstream anagram;
    fstream odpowiedzA;
    anagram.open("anagram.txt", ios::in);
    odpowiedzA.open("OdpowiedzA.txt", ios::out);
    while(anagram.good())
    {
    for(int i=0; i<200; i++)
    {
      anagram>>slowo1;
      anagram>>slowo2;
      anagram>>slowo3;
      anagram>>slowo4;
      anagram>>slowo5;
      if((slowo1.size()== slowo2.size())&&(slowo1.size()== slowo3.size())&&(slowo1.size()== slowo4.size())&&(slowo1.size()==slowo5.size()))
      {
          odpowiedzA<<slowo1<<" "<<slowo2<<" "<<slowo3<<" "<<slowo4<<" "<<slowo5<<endl;
      }
    }
    }

ana