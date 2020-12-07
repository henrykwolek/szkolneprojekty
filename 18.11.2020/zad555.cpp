//Henryk Wołek IIC
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int an, n, a1, r;
    cout << "Podaj wyraz ciągu: ";
    cin >> an;
    cout << "Który to był wyraz? ";
    cin >> n;
    cout << "Podaj różnicę: ";
    cin >> r;

    a1 = an - (r * (n - 1));

    cout << "=======\nWyniki\n=======\n";
    cout << "Pierwszy wyraz a1: " << a1 << "\n";
    
    cout << "Drugi wyraz: " << a1 + r * (2-1) << "\n";
    cout << "Trzeci wyraz: " << a1 + r * (3-1) << "\n"; 
    cout << "Czwarty wyraz: " << a1 + r * (4-1) << "\n";  
}   