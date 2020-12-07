//Henryk Wołek IIC
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int i = 0, liczbaUzytkownika;
    srand(time(NULL));

    while (1)
    {
        int j = rand() % 20 + 10;
        cout << "Zgadnij licznę:\n";
        cin >> liczbaUzytkownika;
        if (liczbaUzytkownika != j)
        {
            if (liczbaUzytkownika > j)
            {
                cout << "Troche przesadziłeś. Spróbuj dalej\n";
            }
            else
            {
                cout << "Troche za mało. Spróbuj dalej\n";
            }
        }
        else
        {
            cout << "Gratulacje, zgadłeś.";
            break;
        }
    }
    
    
}   