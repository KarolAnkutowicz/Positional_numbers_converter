/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: converters.cpp
 */

#include "converters.h"

using namespace std;

unsigned short vDataRecord;

/*
 * unsigned long long funFromTen(unsigned long long aNumber, unsigned short aBase)
 */
unsigned long long funFromTen(unsigned long long aNumber, unsigned short aBase)
{
    unsigned long long fResult = 0, fRest = 0, fIndex = 1;
    do
    {
        fRest = aNumber % aBase; // wyznaczenie reszty z dzielenia
        fResult += fRest * fIndex; // dodanie wartosci do wyniku
        aNumber = (aNumber - fRest) / aBase; // nowa wartosc liczby do dzielenia
        fIndex *= 10; // nowa potega
    } while (aNumber > 0);
    return fResult;
}

/*
 * unsigned long long funToTen(unsigned long long aNumber, unsigned short aBase)
 */
unsigned long long funToTen(unsigned long long aNumber, unsigned short aBase)
{
    unsigned long long fResult = 0, fRest = 0, fIndex = 1;
    do
    {
        fRest = aNumber % 10; // wyznaczenie reszty z dzielenia
        fResult += fRest * fIndex; // dodanie do rezultatu
        aNumber = (aNumber - fRest) / 10; // nowa liczba startowa
        fIndex *= aBase; // nowy index
    } while (aNumber > 0);
    return fResult;
}

/*
 * funNumberCheck(unsigned long long aNumber, unsigned short aBase)
 */
bool funNumberCheck(unsigned long long aNumber, unsigned short aBase)
{
    unsigned long long fRest = 0;
    do
    {
        fRest = aNumber % 10; // wyznaczenie reszty z dzielenia
        if (fRest >= aBase) // sprawdzenie czy reszta jest wieksza niz podstawa
            return false; // jesli tak to wystepuje niedozwolony znak
        aNumber = (aNumber - fRest) / 10; // nadanie nowej wartosci wyjsciowej
    } while (aNumber > 0);
    return true;
}

/*
 * void funCreateFileTest()
 */
void funCreateFileTest()
{
    unsigned short vLengthNumber = 0, vDigit = 0;
    long long vNumber, vExponent;
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
                vExponent = 1;
                vNumber = 0;
                vLengthNumber = rand() % 3 + 3; // wylosowanie dlugosci ciagu cyfr
                for (unsigned short k = 0; k < vLengthNumber; k++)
                {
                    vDigit = rand() % i; // losowanie cyfry
                    if ((k == 0) && (vDigit == 0))
                        vDigit++;
                    vNumber += vExponent * vDigit; // w dodawaniu kazda liczbe traktujemy...
                    vExponent *= 10;               // ... jak liczbe dziesietna
                    if (k == (vLengthNumber - 1))
                        strOut << vNumber << " " << i << " " << j << endl;
                }
            }
        }
    }
    strOut.close(); // zamkniecie strumienia
}

/*
 * void funCreateFileTest(unsigned short parBase1, unsigned short parBase2, unsigned short parExamples)
 */
void funCreateFileTest(unsigned short parBase1, unsigned short parBase2, unsigned short parExamples)
{
    unsigned short vLengthNumber = 0, vDigit = 0;
    long long vNumber, vExponent;
    vDataRecord = 0;
    ofstream strOut; // utworzenie strumienia wpisywania do pliku
    strOut.open("test2.txt"); // otwarcie strumienia
    srand(time(NULL)); // generowanie liczb pseudolosowych
    for (unsigned short i = 0; i < parExamples; i++)
    {
        vDataRecord++;
        vExponent = 1;
        vNumber = 0;
        vLengthNumber = rand() % 6 + 1; // wylosowanie dlugosci ciagu cyfr
        for (unsigned short j = 0; j < vLengthNumber; j++)
        {
            vDigit = rand() % parBase1; // losowanie cyfry
            if ((j == 0) && (vDigit == 0))
                vDigit++;
            vNumber += vExponent * vDigit; // w dodawaniu kazda liczbe traktujemy...
            vExponent *= 10;               // ... jak liczbe dziesietna
            if (j == (vLengthNumber - 1))
                strOut << vNumber << " " << parBase1 << " " << parBase2 << endl;
        }
    }
    strOut.close(); // zamkniecie strumienia
}

/*
 * funMainMenu() - funkcja wyswietlajaca menu glowne programu.
 * PRE:
 * - brak;
 * POST:
 * - brak.
 */
void funMainMenu()
{
    cout << "Jaki tryb programu uruchomic?" << endl
         << "1 - reczne wprowadzanie danych" << endl
         << "2 - generowanie pliku ze wszystkimi konwersjami" << endl
         << "3 - generowanie pliku ze wskazana konwersja i liczba przykladow"
         << endl << endl;
}

/*
 * funHandlingWithoutFile()
 */
void funHandlingWithoutFile()
{
    unsigned long long vNumber1, vNumber2;
    unsigned short vBase1, vBase2;
    for (;;)
    {
        cout << "Podaj liczbe ktora chcesz zamienic: ";
        cin >> vNumber1; // wczytanie liczby, ktora chcemy zamienic
        if (vNumber1 == 0) // wczytanie zera powoduje wyjscie z programu
            break;
        cout << "Jej podstawe: ";
        cin >> vBase1; // wczytanie podstawy podanej liczby
        if ((vBase1 < 2) || (vBase1 > 10)) // sprawdzenie poprawnosci wprowadzenia podstawy
        {
            cerr << "Nieprawidlowa podstawa!" << endl << endl;
            continue;
        }
        cout << "Oraz podstawe na jaka chcesz zamienic: ";
        cin >> vBase2; // wczytanie podstawy na jaka chcemy zamienic
        if ((vBase2 < 2) || (vBase2 > 10)) // sprawdzenie poprawnosci wprowadzenia podstawy
        {
            cerr << "Nieprawidlowa podstawa!" << endl << endl;
            continue;
        }
        if (funNumberCheck(vNumber1, vBase1)) // sprawdzenie poprawnosci podanej liczby i jej podstawy
        {
            if (vBase1 == vBase2) // obie podstawy sa rowne
                vNumber2 = vNumber1;
            else if ((vBase1 == 10) && (vBase2 != 10)) // zamiana z liczby dziesietnej
                vNumber2 = funFromTen(vNumber1, vBase2);
            else if ((vBase1 != 10) && (vBase2 == 10)) // zamiana na liczbe dziesietna
                vNumber2 = funToTen(vNumber1, vBase1);
            else // obie liczby nie beda w systemie dziesietnym
                vNumber2 = funFromTen(funToTen(vNumber1, vBase1), vBase2);
            cout << endl << vNumber1 << " (" << vBase1 << ") = "
                 << vNumber2 << " (" << vBase2 << ")" << endl << endl; // wypisanie wyniku
        }
        else
            cout << endl << "Podana liczba zawiera bledne znaki!" << endl << endl;
    }
}

/*
 * funHandlingWithFile(unsigned short parOption)
 */
void funHandlingWithFile(unsigned short parOption)
{
    unsigned long long vNumber1, vNumber2;
    unsigned short vBase1, vBase2, vExamples;
    ifstream strIn; // utworzenie strumienia odczytywania z pliku
    if (parOption == 2)
    {
        funCreateFileTest(); // stworzenie pliku testowego
        strIn.open("test1.txt"); // otwarcie pliku
    }
    else
    {
        cout << "Podaj podstawe z jakies zamieniac (2-10)" << endl
             << "Podstawa bazowa: ";
        cin >> vBase1;
        cout << "Podaj podstawa na jaka zamieniac (2-10)" << endl
             << "Podstawa docelowa: ";
        cin >> vBase2;
        cout << "Podaj liczbe przykladow" << endl
             << "Liczba przykladow: ";
        cin >> vExamples;
        if ((vBase1 < 2) || (vBase1 > 10) || (vBase2 < 2) || (vBase2 > 10))
            cout << "Niepoprawny zestaw argumentow!" << endl;
        else
        {
            funCreateFileTest(vBase1, vBase2, vExamples); // stworzenie pliku testowego
            strIn.open("test2.txt"); // otwarcie pliku
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
        }
        strIn.close(); // zamkniecie strumienia
    }
}

/*
 * funConverterHandling() - funkcja obslugujaca konwertowanie liczb
 * w systemach pozycyjnych o podstawach od 2 do 10.
 * PRE:
 * - brak.
 * POST:
 * - brak.
 */
void funConverterHandling()
{
    unsigned short vOption;
    funMainMenu();
    cout << "Numer opcji: ";
    cin >> vOption;
    if ((vOption == 2) || (vOption == 3))
        funHandlingWithFile(vOption);
    else if (vOption != 1)
        cout << "Podany numer jest nieprawidlowy!" << endl;
    else
        funHandlingWithoutFile();
}

/* converters.cpp */
/********** END_OF_FILE **********/

