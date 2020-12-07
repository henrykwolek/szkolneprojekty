//Henryk Wołek IIC
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int x, i, y, z, min, max;
	y=30;
	z=90;
	srand(time(NULL));

    for (i = 0; i < 30; i++){
    	x = 30 + rand() % (90 - 30 + 1);
    	if(x >= y)
        {
    		y = x;
		}
		else if(x <= z)
        {
			z = x;	
		}
	}
	cout << "MAX: " << y << "\n";
	cout << "MIN: " << z;
    
}   