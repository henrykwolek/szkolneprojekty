#include <iostream>
using namespace std;
int main()
{
    int a = 25, b;

    for(b=1; b<=a; b++)
    {
        for(int x=a-1; x>=b; x--)
        {
            cout<<" ";
        }

        for(int x=1; x<=b; x++)
        {
            cout<<"X ";
        }
    }
}