/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: converters.cpp
 */

#include "converters.hpp"

using namespace std;

unsigned short vDataRecord;

/*
 * unsigned long long funFromTen(unsigned long long aNumber, unsigned short aBase)
 */
unsigned long long funFromTen(unsigned long long aNumber, unsigned short aBase)
{
    unsigned long long fResult = 0, fRest = 0, fIndex = 1; // zdefiniowanie zmiennych: koncowy wynik, reszta z dzielenia oraz pozycja danej cyfry
    do
    {
        fRest = aNumber % aBase; // wyznaczenie reszty z dzielenia
        fResult += fRest * fIndex; // dodanie wartosci do wyniku
        aNumber = (aNumber - fRest) / aBase; // nowa wartosc liczby do dzielenia
        fIndex *= 10; // nowa potega
    } while (aNumber > 0); // petle powtarzamy dopoki mamy liczbe dodatnia
    return fResult; // zwrocenie wyniku
}

/*
 * unsigned long long funToTen(unsigned long long aNumber, unsigned short aBase)
 */
unsigned long long funToTen(unsigned long long aNumber, unsigned short aBase)
{
    unsigned long long fResult = 0, fRest = 0, fIndex = 1; // zdefiniowanie zmiennych: koncowy wynik, reszta z dzielenia oraz pozycja danej cyfry
    do
    {
        fRest = aNumber % 10; // wyznaczenie reszty z dzielenia
        fResult += fRest * fIndex; // dodanie do rezultatu
        aNumber = (aNumber - fRest) / 10; // nowa liczba startowa
        fIndex *= aBase; // nowy index
    } while (aNumber > 0); // petle powtarzamy dopoki mamy liczbe dodatnia
    return fResult; // zwrocenie wyniku
}

/*
 * funNumberCheck(unsigned long long aNumber, unsigned short aBase)
 */
bool funNumberCheck(unsigned long long aNumber, unsigned short aBase)
{
    unsigned long long fRest = 0; // zdefiniowanie zmiennej okreslajacej reszte z dzielenia calkowitoliczbowego
    do
    {
        fRest = aNumber % 10; // wyznaczenie reszty z dzielenia
        if (fRest >= aBase) // sprawdzenie czy reszta jest wieksza niz podstawa
            return false; // jesli tak to wystepuje niedozwolony znak
        aNumber = (aNumber - fRest) / 10; // nadanie nowej wartosci wyjsciowej
    } while (aNumber > 0);  // petle powtarzamy dopoki mamy liczbe dodatnia
    return true; // zwracamy "true" jesli wszystkie znaki w liczbie sa dozwolone
}

/*
 * void funCreateFileTest()
 */
void funCreateFileTest()
{
    unsigned short vLengthNumber = 0, vDigit = 0; // zdefiniowanie zmiennych okreslajacych: liczbe cyfr, wartosc cyfry
    long long vNumber, vExponent; // zadeklarowanie zmiennych okreslajacych: zamieniana liczbe, potege podstawy
    vDataRecord = 0; // ustanowienie wartosci zmiennej globalnej
    srand(time_t(NULL) + (unsigned int)&vNumber); // generowanie liczb pseudolosowych
    ofstream strOut; // utworzenie strumienia wpisywania do pliku
    strOut.open("test1.txt"); // otwarcie strumienia
    for (unsigned short i = 2; i <= 10; i++) // z tej bazy zamieniamy
    {
        for (unsigned short j = 2; j <= 10; j++) // na te baze zamieniamy
        {
            if (i == j) // pomijamy zamiany w ramach tej samej bazy
                continue; // przejscie do kolejnego cyklu petli
            else
            {
                vDataRecord++; // zwiekszenie sie liczby zestawow danych
                vExponent = 1; // ustanowienie poczatkowej potegi
                vNumber = 0; // ustanowienie poczatkowej wartosci zamienianej liczby
                vLengthNumber = rand() % 3 + 3; // wylosowanie dlugosci ciagu cyfr
                for (unsigned short k = 0; k < vLengthNumber; k++) // przejscie po wszystkich cyfrach
                {
                    vDigit = rand() % i; // losowanie cyfry
                    if ((k == 0) && (vDigit == 0)) // sprawdzamy czy we wskazanym miejscu mamy zero
                        vDigit++; // jesli tak to inkrementujemy liczbe cyfr
                    vNumber += vExponent * vDigit; // w dodawaniu kazda liczbe traktujemy...
                    vExponent *= 10;               // ... jak liczbe dziesietna
                    if (k == (vLengthNumber - 1)) // sprawdzamy czy jestesmy na miejscu ostatniej cyfry
                        strOut << vNumber << " " << i << " " << j << endl; // jesli tak to wypisujemy liczbe oraz podstawy: bazowa i docelowa
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
    unsigned short vLengthNumber = 0, vDigit = 0; // zdefiniowanie zmiennych okreslajacych: liczbe cyfr, wartosc cyfry
    long long vNumber, vExponent; // zadeklarowanie zmiennych okreslajacych: zamieniana liczbe, potege podstawy
    vDataRecord = 0; // ustanowienie wartosci zmiennej globalnej
    ofstream strOut; // utworzenie strumienia wpisywania do pliku
    strOut.open("test2.txt"); // otwarcie strumienia
    srand(time(NULL)); // generowanie liczb pseudolosowych
    for (unsigned short i = 0; i < parExamples; i++) // liczba przejsc przez petle jest rowna liczbie przykladow
    {
        vDataRecord++; // inkrementacja liczby przykladow
        vExponent = 1; // ustanowienie potegi
        vNumber = 0; // ustanowienie poczatkowej wartosci zmienianej liczby
        vLengthNumber = rand() % 6 + 1; // wylosowanie dlugosci ciagu cyfr
        for (unsigned short j = 0; j < vLengthNumber; j++) // przejscie po wszystkich cyfrach
        {
            vDigit = rand() % parBase1; // losowanie cyfry
            if ((j == 0) && (vDigit == 0)) // sprawdzamy czy we wskazanym miejscu mamy zero
                vDigit++; // jesli tak to inkrementujemy liczbe cyfr
            vNumber += vExponent * vDigit; // w dodawaniu kazda liczbe traktujemy...
            vExponent *= 10;               // ... jak liczbe dziesietna
            if (j == (vLengthNumber - 1)) // sprawdzamy czy jestesmy na miejscu ostatniej cyfry
                strOut << vNumber << " " << parBase1 << " " << parBase2 << endl; ; // jesli tak to wypisujemy liczbe oraz podstawy: bazowa i docelowa
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
    cout << "Jaki tryb programu uruchomic?" << endl // wypisanie glownego menu programu
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
    unsigned long long vNumber1, vNumber2; // zadeklarowanie zmiennych: liczby zamienianej i wynikowej
    unsigned short vBase1, vBase2; //  zadeklarowanie zmiennych: podstawy zamienianej i docelowej
    for (;;) // nieskonczona petla
    {
        cout << "Podaj liczbe ktora chcesz zamienic: ";
        cin >> vNumber1; // wczytanie liczby, ktora chcemy zamienic
        if (vNumber1 == 0) // wczytanie zera powoduje wyjscie z programu
            break;
        cout << "Jej podstawe: ";
        cin >> vBase1; // wczytanie podstawy podanej liczby
        if ((vBase1 < 2) || (vBase1 > 10)) // sprawdzenie poprawnosci wprowadzenia podstawy
        {
            cerr << "Nieprawidlowa podstawa!" << endl << endl; // komunikat o nieprawidlowej podstawie
            continue;
        }
        cout << "Oraz podstawe na jaka chcesz zamienic: ";
        cin >> vBase2; // wczytanie podstawy na jaka chcemy zamienic
        if ((vBase2 < 2) || (vBase2 > 10)) // sprawdzenie poprawnosci wprowadzenia podstawy
        {
            cerr << "Nieprawidlowa podstawa!" << endl << endl;  // komunikat o nieprawidlowej podstawie
            continue;
        }
        if (funNumberCheck(vNumber1, vBase1)) // sprawdzenie poprawnosci podanej liczby i jej podstawy
        {
            if (vBase1 == vBase2) // obie podstawy sa rowne
                vNumber2 = vNumber1; // wowczas wynikowa liczba bedzie rowna bazowej
            else if ((vBase1 == 10) && (vBase2 != 10)) // zamiana z liczby dziesietnej
                vNumber2 = funFromTen(vNumber1, vBase2); // wywolanie zamiany z systemu dziesietnego na inny
            else if ((vBase1 != 10) && (vBase2 == 10)) // zamiana na liczbe dziesietna
                vNumber2 = funToTen(vNumber1, vBase1); // wywolanie zamiany na system dziesietny z innego
            else // obie liczby nie beda w systemie dziesietnym
                vNumber2 = funFromTen(funToTen(vNumber1, vBase1), vBase2); // wywolania zamian, posrednie uzycie systemu dziesietnego
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
    unsigned long long vNumber1, vNumber2; // zadeklarowanie zmiennych: liczby zamienianej i wynikowej
    unsigned short vBase1, vBase2, vExamples; // zadeklarowanie zmiennych: podstawy bazowej, podstawy wynikowej i liczby przykladowe
    ifstream strIn; // utworzenie strumienia odczytywania z pliku
    if (parOption == 2) // sprawdzenie opcji wywolanie
    {
        funCreateFileTest(); // stworzenie pliku testowego
        strIn.open("test1.txt"); // otwarcie pliku
    }
    else
    {
        cout << "Podaj podstawe z jakies zamieniac (2-10)" << endl
            << "Podstawa bazowa: ";
        cin >> vBase1; // podanie podstawy bazowej
        cout << "Podaj podstawa na jaka zamieniac (2-10)" << endl
            << "Podstawa docelowa: ";
        cin >> vBase2; // podanie podstawy docelowej
        cout << "Podaj liczbe przykladow" << endl
            << "Liczba przykladow: ";
        cin >> vExamples; // podanie liczby przykladow
        if ((vBase1 < 2) || (vBase1 > 10) || (vBase2 < 2) || (vBase2 > 10)) // sprawdzenie poprawnosci podania podstaw
            cerr << "Niepoprawny zestaw argumentow!" << endl; // wyswietlenie komunikatu o bledzie
        else // przypadek poprawnego podania zestawu argumentow
        {
            funCreateFileTest(vBase1, vBase2, vExamples); // stworzenie pliku testowego
            strIn.open("test2.txt"); // otwarcie pliku
            for (unsigned short i = 0; i < vDataRecord; i++) // przejscie po wszystkich zestawach danych
            {
                strIn >> skipws >> vNumber1 >> vBase1 >> vBase2; // wczytanie liczby zamienianej, podstawy bazowej i podstawy docelowej
                if (vBase1 == vBase2) // sprawdzmay czy obie podstawy sa rowne
                    vNumber2 = vNumber1; // jesli tak to wyniki tez beda rowne
                else if ((vBase1 == 10) && (vBase2 != 10)) // zamiana z liczby dziesietnej
                    vNumber2 = funFromTen(vNumber1, vBase2); // wywolanie zamiany z systemu dziesietnego
                else if ((vBase1 != 10) && (vBase2 == 10)) // zamiana na liczbe dziesietna
                    vNumber2 = funToTen(vNumber1, vBase1); // wywolanie zamiany na system dziesietny
                else // obie liczby nie beda w systemie dziesietnym
                    vNumber2 = funFromTen(funToTen(vNumber1, vBase1), vBase2); // wywolanie zamiany z posrednim uzyciem systemu dziesietnego
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
    unsigned short vOption; // zadeklarowanie zmiennej okreslajacej wybrana opcje
    funMainMenu(); // wyswietlenie menu glownego
    cout << "Numer opcji: ";
    cin >> vOption; // podanie numeru opcji
    if ((vOption == 2) || (vOption == 3)) // sprawdzenie cZy chcemy operowac na plikach
        funHandlingWithFile(vOption); // jesli tak to wywolujemy odpowienia obsluge
    else if (vOption != 1) // sprawdzamy czy w ogole podana opcja jest poprawna
        cerr << "Podany numer jest nieprawidlowy!" << endl; // jesli nie to wyswietlamy odpowiedni komunikat
    else // jesli wszystko jest ok...
        funHandlingWithoutFile(); // ...to pozostaje nam ostatnia opcja - biezace zamiany wprowadzanych recznie przykladow
}

/* converters.cpp */
/********** END_OF_FILE **********/


