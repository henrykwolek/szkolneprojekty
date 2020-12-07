//Henryk Wołek IIC
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int i = 0;
    while (i < 10)
    {
        cout << rand() % 1000 << "\n";
        i++;
    }
    
    
}   