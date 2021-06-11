#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    int rand(), tab[20], licz[28], n, i, j, min=28, max=0;
    int p=0;
    int q=28;

    cout<<"Podaj wielkosc zbioru do 20"<<endl;
    cin>>n;

    while(n>20)
    {
        cout<<"Blad, podaj jeszcze raz"<<endl;
        cin>>n;
    }

    for(i=0; i<n; i++)
    {
        tab[i]=p+rand()%(q-p+1);
    }

    for(i=0; i<n; i++)
    {
        cout<<tab[i]<<", ";
    }

    for(j=0; j<n; j++)
    {
        if(tab[j]>max)
        {
            max=tab[j];
        }

        if(tab[j]<min)
        {
            min=tab[j];
        }
    }

    cout<<endl<<"minimalna: "<<min<<endl<<"maksymalna: "<<max;

    for(j=0; j<=q; j++)
    {
        licz[j]=0;
    }

    for(j=0; j<n; j++)
    {
        licz[tab[j]]++;
    }
    cout<<endl;

    cout<<"kubelki:";
    for(j=0; j<n; j++)
    {
        cout<<"["<<j<<":"<<licz[j]<<"]";
    }

    cout<<endl;

    for(i=max; i>=min; i--)
    {
        if(licz[i]>0)
        {
            for(j=licz[i]; j>0; j--) {
              cout<<i<<", ";
            }
        }
    }
    system ("PAUSE");
    return 0;
}