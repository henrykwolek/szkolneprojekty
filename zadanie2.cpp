#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int i, j;
    for (i = 0; i < 18; i++)
    {
        for (j = 0; j <= i; j++)
        {
            cout << "X";
        }
        cout << "\n";
    }
    
}   