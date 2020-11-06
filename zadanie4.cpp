#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int i, j, g;
    for (i = 0; i < 18; i++)
    {
        for (g = 0; g < i; g++)
        {
            cout << " ";
        }
        for (j = 18; j > i; j--)
        {
            cout << "X";
        }
        cout << "\n";
    }
}   