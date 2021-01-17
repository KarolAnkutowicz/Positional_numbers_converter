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
    for (unsigned short i = 0; i < parExamples; i++)
    {

    }
}


/*
 * void funTest1()
 */
void funTest1()
{
    long long vNumber1, vNumber2;
    unsigned short vBase1, vBase2;
    funCreateFileTest1(); // stworzenie pliku testowego
    ifstream strIn; // utworzenie strumienia odczytywania z pliku
    strIn.open("test1.txt"); // otwarcie pliku
    for (unsigned short i = 0; i < vDataRecord; i++) // przejscie po wszystkich zestawach danych
    {
        strIn >> skipws >> vNumber1 >> vBase1 >> vBase2;
        //cout << vNumber1 << " " << vBase1 << " " << vBase2 << endl;
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
