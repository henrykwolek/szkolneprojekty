#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    string username;
    int wybor;
    cout << "Podaj soje imie\n";
    cin >> username;

    cout << "Witaj " << username << ", wybierz osobę, która cię będzie KRUSZYĆ!!!\n";
    cout << "Opcje: \n\t1)Aleksandra Bogdanowicz-dżalapinio\n\t2)Barbara Salasa\n\t3)Ania Łysoń\n";
    cout << "Wybieraj mądrze...\n\n";

    cin >> wybor;

    if(wybor == 1)
    {
        cout << "Wybrałeś kruszenie na netflixie!!!";
    }
    else if(wybor == 2)
    {
        cout << "Wybrałeś kruszenie w Niemczech!!!";
    }
    else if(wybor == 3)
    {
        cout << "Zapierdalaj do rumii na kruszenie od łysoń!!!";
    }
    else
    {
        cout << "Masz zakola zjebie!";
    }
    
}   