/********** BEGIN_OF_FILE **********/
/* converters.cpp */

#include "converters.h"

using namespace std;

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
 * funConverterHandling()
 */
void funConverterHandling()
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
    cout << endl << "Do zobaczenia!" << endl;
}


/* converters.cpp */
/********** END_OF_FILE **********/

