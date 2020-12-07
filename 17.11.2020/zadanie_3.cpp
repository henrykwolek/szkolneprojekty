//Henryk Wołek IIC
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int i = 0, p, q;
    srand(time(NULL));
    cout << "Podaj zakres liczb (p, q)\n";
    cin >> p >> q;
    cout << p + rand() % (q-p+1);
}   