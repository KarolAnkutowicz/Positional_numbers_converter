/********** BEGIN_OF_FILE **********/
/* converterstest.cpp */

#include "converters.h"
#include "converterstest.h"

using namespace std;

unsigned short vDataRecord;

/*
 * void funCreateFileTest1()
 */
void funCreateFileTest1()
{
    unsigned short vLengthNumber = 0, vDigit = 0;
    long long vNumber, vPotega;
    vDataRecord = 0;
    srand(time_t(NULL)+(unsigned int)&vNumber); // generowanie liczb pseudolosowych
    ofstream strOut; // utworzenie strumienia wpisywania do pliku
    strOut.open("test1.txt"); // otwarcie strumienia
    for (unsigned short i = 2; i <= 10; i++) // z tej bazy zamieniamy
    {
        for (unsigned short j = 2; j <= 10; j++) // na te baze zamieniamy
        {
            if (i == j) // pomijamy zamiany w ramach tej samej bazy
                continue;
            else
            {
                vDataRecord++; // zwiekszenie sie liczby zestawow danych
                vPotega = 1;
                vNumber = 0;
                vLengthNumber = rand() % 3 + 3; // wylosowanie dlugosci ciagu cyfr
                for (unsigned short k = 0; k < vLengthNumber; k++)
                {
                    vDigit = rand() % i; // losowanie cyfry
                    if ((k == 0) && (vDigit == 0))
                        vDigit++;
                    vNumber += vPotega * vDigit; // w dodawaniu kazda liczbe traktujemy...
                    vPotega *= 10;               // ... jak liczbe dziesietna
                    if (k == (vLengthNumber - 1))
                        strOut << vNumber << " " << i << " " << j << endl;
                }
            }
        }
    }
    strOut.close(); // zmakniecie strumienia
}

/*
 * void funCreateFileTest2(unsigned short parBase1, unsigned short parBase2, unsigned short parExamples)
 */
void funCreateFileTest2(unsigned short parBase1, unsigned short parBase2, unsigned short parExamples)
{
    unsigned short vLengthNumber = 0, vDigit = 0;
    long long vNumber, vPotega;
    vDataRecord = 0;
    ofstream strOut; // utworzenie strumienia wpisywania do pliku
    strOut.open("test2.txt"); // otwarcie strumienia
    srand(time(NULL)); // generowanie liczb pseudolosowych
    for (unsigned short i = 0; i < parExamples; i++)
    {
        vDataRecord++;
        vPotega = 1;
        vNumber = 0;
        vLengthNumber = rand() % 6 + 1; // wylosowanie dlugosci ciagu cyfr
        for (unsigned short j = 0; j < vLengthNumber; j++)
        {
            vDigit = rand() % parBase1; // losowanie cyfry
            if ((j == 0) && (vDigit == 0))
                vDigit++;
            vNumber += vPotega * vDigit; // w dodawaniu kazda liczbe traktujemy...
            vPotega *= 10;               // ... jak liczbe dziesietna
            if (j == (vLengthNumber - 1))
                strOut /*cout*/ << vNumber << " " << parBase1 << " " << parBase2 << endl;
        }
    }
    strOut.close(); // zmakniecie strumienia
}


/*
 * void funTest(unsigned short parTypeTest)
 */
void funTest(unsigned short parTypeTest)
{
    long long vNumber1, vNumber2;
    unsigned short vBase1, vBase2;
    ifstream strIn; // utworzenie strumienia odczytywania z pliku
    if (parTypeTest == 1)
    {
        funCreateFileTest1(); // stworzenie pliku testowego
        strIn.open("test1.txt"); // otwarcie pliku
    }
    else
    {
        funCreateFileTest2(2, 10, 10); // stworzenie pliku testowego
        strIn.open("test2.txt"); // otwarcie pliku
    }
    for (unsigned short i = 0; i < vDataRecord; i++) // przejscie po wszystkich zestawach danych
    {
        strIn >> skipws >> vNumber1 >> vBase1 >> vBase2;
        if (vBase1 == vBase2) // obie podstawy sa rowne
            vNumber2 = vNumber1;
        else if ((vBase1 == 10) && (vBase2 != 10)) // zamiana z liczby dziesietnej
            vNumber2 = funFromTen(vNumber1, vBase2);
        else if ((vBase1 != 10) && (vBase2 == 10)) // zamiana na liczbe dziesietna
            vNumber2 = funToTen(vNumber1, vBase1);
        else // obie liczby nie beda w systemie dziesietnym
            vNumber2 = funFromTen(funToTen(vNumber1, vBase1), vBase2);
        cout << vNumber1 << " (" << vBase1 << ") = "
             << vNumber2 << " (" << vBase2 << ")" << endl << endl; // wypisanie wyniku
    }
    strIn.close(); // zamkniecie strumienia
}

/* converterstest.cpp */
/********** END_OF_FILE **********/
