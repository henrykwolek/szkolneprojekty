#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    string password = "fchn";
    string userPassword;
        
    for (int i = 0; i < 5; i++)
    {
        cout << "Podaj hasło:\n";
        cin >> userPassword;

        if (userPassword == password)
        {
            cout << "Gratulacje, zgadłeś hasło!!!\n";
            break;
        }
        else if (userPassword != password && i != 4)
        {
            cout << "Niestety nie zgadłeś hasła. Oto podpowiedź:\n";
            cout << "Podpowiedź: litera numer " << i << ": " << password[i] << "\n";
        }
        else if (i == 4)
        {
            cout << "Niestety nie zgadłeś hasła. Poprawne hasło to: " << password << "\n";
            break;
        } 
    }
}   