//Autor: Henryk Wołek IIC
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <bits/stdc++.h> 
#include <string>
#include <numeric>

using namespace std;

int main()
{
    //Deklaracja zmiennych i obiektów
    fstream fRead, fWrite;
    string readLineBinaryNum, 
    trzeciaOdpNajmniejsza,
    trzeciaOdpNajwieksza;

    fRead.open("liczby.txt", ios::in);
    fWrite.open("odpowiedzi.txt", ios::out);

    vector<string> numbers;
    int liczbyParzyste = 0, 
    wiecejZerNizJedynek = 0, 
    podzielnePrzezDwa = 0, 
    podzielnePrzezOsiem = 0;

    while (fRead.good())
    {
        //1 część
        int liczbaZer = 0, liczbaJedynek = 0;
        getline(fRead, readLineBinaryNum);
        for (int j = 0; j < readLineBinaryNum.length(); j++)
        {
            //Zsumowanie ilości zer i jedynek
            if ((readLineBinaryNum[j] - '0') == 0)
            {
                liczbaZer++;
            }
            else
            {
                liczbaJedynek++;
            }
        }
        //Porównanie i jeśli jest więcej zer niż jedynek, ilość takich liczb zwiększy się o 1
        if (liczbaZer > liczbaJedynek)
        {
            wiecejZerNizJedynek++;
        }

        //2 część

        //Sprawdzenie, czy dana liczba ma na końcu 3 zera, tym samym będąc podzielna przez 8
        if (readLineBinaryNum[readLineBinaryNum.length() - 1] - '0' == 0
         && readLineBinaryNum[readLineBinaryNum.length() - 2] - '0' == 0 
         && readLineBinaryNum[readLineBinaryNum.length() - 3] - '0' == 0)
        {
            podzielnePrzezOsiem++;
            //Liczba podzielna przez 8 to zawsze liczba podzielna przez 2!
            podzielnePrzezDwa++;
        }
        //Jeśli ma na końcu tylko jedno zero, to jest podzielna przez 2, ale nie przez 8
        else if (readLineBinaryNum[readLineBinaryNum.length() - 1] - '0' == 0)
        {
            podzielnePrzezDwa++;
        }

        //3 część - krok 1
        
        //Zapisanie wszystkich wczytanych liczb do kontenera typu vector
        numbers.push_back(readLineBinaryNum);
    }

    //3 część - kolejne kroki

    //Deklaracja tablicy dwuwymiarowej int[] o ilości wierszy 1000 (ilość wczytanych liczb) i ilości kolumn 200 (największa długość liczby)
    //Praca z tablicą dwuwymiarową znacznie ułatwiła mi rozwiązanie tego właśnie problemu gdy nie miałem do dyspozycji zmiennej liczbowej
    //Z powodu pracy z tak dużymi liczbami
    int arrOfStringBinaryNumbers[1000][200];

    //Wpisywanie do tablicy
    for (int k = 0; k < numbers.size(); k++)
    {
        //Zmienne tymczasowe w każdym powtórzeniu pętli przybierają odpowiednią wartość. Gdy pętla zaczyna się na nowo, obie są resetowane
        string tempString = numbers[k];
        //Pętla for ze zmienną "k" ma za zadanie obsłużyć każdy wiersz. Wykona się ona tyle razy, ile liczb jest w pliku "liczby.txt" (w tym przypadku dokładnie 1000 razy)
        for (int l = 0; l < 200; l++)
        {
            //Pętla ze zmienną "l" obsługuje kolejne kolumny w wierszu obsługiwanym w danym momencie przez pętle ze zmienną "k"
            //Wpisuje ona do każdej komórki w wierszu wyznaczonym przez zmienną "k", oraz w kolumne "l" odpowiednią cyfrę
            int tempInt = tempString[l] - '0';
            arrOfStringBinaryNumbers[k][l] = tempInt;
            //Resetowanie tymczasowej zmiennej liczbowej int
            tempInt = 0;
        }
        //Resetowanie tymczasowej zmiennej tekstowej string
        tempString.clear();
    }

    //Szukanie największej liczby
    //Tutaj opierałem się o metodę, którą opisze poniżej.
    //Napisałem pętle, która znalazła około 350 liczb które mają długość 200 cyfr
    //Chcąc zamienić je na system dziesiętny, zaczniemy od początku z największą potęgą dwójki
    //Gdy jednak natrafimy na 0, to "przegapiamy" daną potęgę dwójki, np liczba binarna 10001 (17) jest mniejsza od 11001 (31)
    //Oczywiście każda ze wszystkich 1000 liczb ma na początku 1, ale to nie ma tutaj duzego znaczenia.
    //Szukałem więc nieprzerwanego ciągu jedynek, który rozpoczynał się na miejscu drugiej cyfry od lewej (pomijając pierwszą cyfre, bo wszędzie jest identyczna).
    //Taki nieprzerwany ciąg jedynek licząc od początku liczby oznacza, że na pewno mamy doczynienia z liczbą conajmniej tak dużą jak 2^199.
    //Zrobiłem swoje obliczenia, które wykazały, że gdy zsumuje wszystkie potęgi dwójki od 0 do 64, to otrzymam 127. Zatem nieważne jest co dana liczba ma na dalszych miejscach, ponieważ już tego nie nadrobi.
    //Dlatego szukałem liczb o długości 200, a wśród nich najdłuższego, nieprzerwanego ciągu jedynek, który gwarantował największą wartość dziesiętną danej liczby.
    //Napisałem więc pętle, która sprawdziła, że jest tylko jedna taka liczba, i tych jedynek jest dokładnie 9, nie licząc początkowej.
    //Dzięki temu mogłem sprawdzić poniższą kombinacją dwóch pętli for na jakim wierszu się znajduje.

    //Zmienna int która zlicza nieprzerwane występowanie jedynek
    int continuousOneOccurenceInGivenArrRow = 0, maxOccurences = 0;
    vector<int> oneOccurences;
    //Ta pętla sprawdzi każdą liczbę z każdego wiersza pliku
    for (int m = 0; m < numbers.size(); m++)
    {
        //Natomiast ta pętla będzie sprawdzała zawartość poszczególnej liczby (sprawdzi cyfry)
        for (int n = 1; n < 200; n++)
        {
            //Zliczanie ciągu jedynek odbędzie się tylko wtedy, gdy liczba ma długość 200
            if (numbers[m].size() == 200)
            {
                //Jeśli dla danej liczby cyfra od indexu 1 (druga cyfra od lewej) wynosi 1, to zmienna int zwiększy się o 1
                if (arrOfStringBinaryNumbers[m][n] == 1)
                {
                    continuousOneOccurenceInGivenArrRow++;
                }
                else
                {
                    //Jeśli w jakikolwiek sposób ciąg jedynek zostanie przerwany (wystąpi 0), to pętla zakończy się w tym momencie
                    break;
                }
            }
            else
            {
                //Jeśli natomiast liczba nie ma 200 cyfr, pętla jest pomijana
                break;
            }
        }
        if (continuousOneOccurenceInGivenArrRow == 9)
        {
            //Jeśli program odnajdzie liczbę, gdzie występuje ciąg dziewięciu jedynek nie licząc z początkową cyfrą, wyświetli się komunikat
            //Deklaracja zmiennej string, która umożliwi zapisanie do pliku
            cout << "Największa liczba znajduje się na wierszu nr: " << m + 1 << "\n";
            trzeciaOdpNajwieksza = "Największa liczba znajduje się na wierszu nr: " + to_string(m + 1);
        }
        //Za każdym powtórzeniem dużej pętli for resetowana jest zmienna licząca ilość jedynek w ciągu
        //oneOccurences.push_back(continuousOneOccurenceInGivenArrRow);
        // maxOccurences = *max_element(oneOccurences.begin(), oneOccurences.end());

        //W powyższy sposób znalazłem największy nieprzerwany ciąg jedynek który wynosi 9 cyfr
        continuousOneOccurenceInGivenArrRow = 0;
    }

    //Szukanie najmniejszej liczby

    //vector<int> binaryNumbersLengths;
    //Poprzez stworzenie powyższego wektora zbadałem, że liczba o najmniejszej długości ma tylko 3 cyfry i jest ich 5
    vector<int> smallBinaryNumbers;
    for (int o = 0; o < numbers.size(); o++)
    {
        if (numbers[o].size() == 3)
        {
            //Napisałem pętle for, która zbadała, że najmniejsza ilość cyfr jaką posiada liczba to 3
            //Zatem jeśli wystąpi liczba o ilości cyfr 3, zostanie ona wpisana do vectora jako int
            smallBinaryNumbers.push_back(atoi(numbers[o].c_str()));
        }
        //binaryNumbersLengths.push_back(numbers[o].size());
        //Zostały one wpisany powyższą linią i metoda *min_element() wskazała najmniejszą długosć wynoszącą 3
    }

    //Ta funkcja znajdzie najmniejszą wartość jaka istnieje wśród wczytanych 1000 liczb
    int smallestBinaryNumber = *min_element(smallBinaryNumbers.begin(), smallBinaryNumbers.end());

    for (int p = 0; p < numbers.size(); p++)
    {
        //Jeśli ta wartość zostanie napotkana, zostanie zadeklarowana zmienna string i pętla zakończy się
        if (atoi(numbers[p].c_str()) == smallestBinaryNumber)
        {
            cout << "Najmniejsza liczba znajduje się na wierszu nr: " << p + 1;
            trzeciaOdpNajmniejsza = "Najmniejsza liczba znajduje się na wierszu nr: " + to_string(p + 1);
            break;
        }
    }

    //Wpisanie odpowiedzi - podsumowanie

    //1 część - odpowiedzi
    fWrite << "1 część: \n" << "Wiecej zer niz jedynek: " << wiecejZerNizJedynek << "\n\n";

    //2 część - odpowiedzi
    fWrite << "2 część: \n" << "Tyle liczb jest podzielnych przez 2: " 
    << podzielnePrzezDwa << "\nA tyle przez 8: " << podzielnePrzezOsiem << "\n\n";

    //3 część - odpowiedzi
    fWrite << "3 część: \n" << trzeciaOdpNajmniejsza << "\n" << trzeciaOdpNajwieksza;
    



    //cout << "Najmniejsza długość to " << *min_element(binaryNumbersLengths.begin(), binaryNumbersLengths.end()); <-- wynikiem tej linii kodu jest 3
    
    

    // if (arrOfStringBinaryNumbers[m][1] == 1 
    //     && arrOfStringBinaryNumbers[m][2] == 1
    //     && arrOfStringBinaryNumbers[m][3] == 1
    //     && arrOfStringBinaryNumbers[m][4] == 1
    //     )
    //     {
    //         cout << arrOfStringBinaryNumbers[m][1] 
    //         << arrOfStringBinaryNumbers[m][2] 
    //         << arrOfStringBinaryNumbers[m][3] 
    //         << arrOfStringBinaryNumbers[m][4] 
    //         << " dla pozycji: " << m << "\n";
    //     }
    
    


    



    fRead.close();
    //cout << "Podzielne przez 2: " << podzielnePrzezDwa << "\nPodzielne przez 8: " << podzielnePrzezOsiem << "\n";
    //cout << "Wiecej 0 niż 1: " << wiecejZerNizJedynek << "\n";

    //cout << "Ile liczb ma długość 200: " << najwiekszeLiczby.size();
}