#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    string imie;
    
    cout << "Podaj imie:\n";
    cin >> imie;

    if (imie.length() <= 5)
    {
        if (imie[0] == 'A' || imie[imie.length() - 1] == 'a')
        {
            cout << "Gratulacje!!\n";
        }
        
    }
    else
    {
        cout << "Niestety coś poszło nie tak\n";
    }
    
}   