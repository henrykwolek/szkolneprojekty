//Henryk Wołek IIC
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    double dlugosc, b, c = 0;
    
    do
    {
        cout << "Podaj długość\n";
        cin >> dlugosc;
    } while (dlugosc <= 0);

    for(b = 1; b <= dlugosc; b++)
    {
		c = c+1 / b;
	}
	
    cout << c;
}   