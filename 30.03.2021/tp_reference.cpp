#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
		struct galeria
		{
			string kraj="";
			string miasto="";
			int x[70]={0};
			int y[70]={0};
		};
		galeria galerie[50];
		
		fstream plik;
		plik.open("galerie_przyklad.txt",ios::in);
		if(plik.good())
		{
			for(int i=0;i<50;i++)
			{
			plik>>galerie[i].kraj;
			plik>>galerie[i].miasto;
			for(int j=0;j<70;j++)
				{
				plik>>galerie[i].x[j];
				plik>>galerie[i].y[j];
				}
			}
		}
int ile=0;
bool wystapienie=false;
ofstream wynik1;
wynik1.open("wynik_A.txt");
for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
			{
				if(galerie[i].kraj==galerie[j].kraj)
					{
						if(j<i)
						{
							wystapienie=true;
							break;
						}
					ile++;
					}
			}
			if(wystapienie==false)
			{
				wynik1<<galerie[i].kraj<<"  "<<ile<<endl;
			}
			ile=0;
			wystapienie=false;
	}
return 0;
}