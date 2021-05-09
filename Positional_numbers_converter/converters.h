/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: converters.h
 */

#ifndef CONVERTERS_H
#define CONVERTERS_H

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;


/*
 * funFromTen() - funkcja przeliczajaca liczbe z systemu dziesetnego na inny.
 * PRE:
 * - podanie liczby dziesietnej (argument: aNumber);
 * - podanie podstawy na jaka chcemy zamienic (argument: aBase).
 * POST:(
 * - zwrocenie liczby o zadanej podstawie (typ: unsigned long).
 */
unsigned long long funFromTen(unsigned long long aNumber, unsigned short aBase);

/*
 * funToTen() - funkcja przeliczajaca liczbe na system dziesietny.
 * PRE:
 * - podanie liczby jaka chcemy zamienic (argument: aNumber);
 * - podanie podstawy z jakiej chcemy zamienic (argument: aBase).
 * POST:(
 * - zwrocenie liczby dziesietnej (typ: unsigned long).
 */
unsigned long long funToTen(unsigned long long aNumber, unsigned short aBase);

/*
 * funNumberCheck() - funkcja sprawdzajaca czy wprowadzaona liczba nie
 * posiada niepoprawnych znakow (cyfr wiekszych lub rownych jej podstawie)
 * PRE:
 * - podanie liczby jaka chcemy zamienic (argument: aNumber);
 * - podanie podstawy liczby (argument: aBase).
 * POST:
 * - potwierdzenie lub zaprzeczenie poprawnosci cyfr (typ: bool)
 */
bool funNumberCheck(unsigned long long aNumber, unsigned short aBase);

/*
 * funCreateFileTest() - funkcja tworzaca plik umozliwiajacy
 * przetestowanie poprawnosci dzialania konwersji liczb
 * pomiedzy systemami pozycyjnymi o roznych podstawach.
 * PRE:
 * - brak.
 * POST:
 * - brak.
 */
void funCreateFileTest();

/*
 * void funCreateFileTest(unsigned short parBase1, unsigned short parBase2, unsigned short parExamples) -
 * PRE:
 * - brak.
 * POST:
 * - brak.
 */
void funCreateFileTest(unsigned short parBase1, unsigned short parBase2, unsigned short parExamples);

/*
 * funMainMenu() - funkcja wyswietlajaca menu glowne programu.
 * PRE:
 * - brak;
 * POST:
 * - brak.
 */
void funMainMenu();

/*
 * funHandlingWithoutFile() - funkcja zajmujaca sie obsluga konwersji liczb
 * wprowadzanych z klawiatury (bez obslugi plikow).
 * PRE:
 * - brak;
 * POST:
 * - brak.
 */
void funHandlingWithoutFile();

/*
 * funHandlingWithFile(unsigned short parOption) - funkcja zajmujaca sie
 * obsluga konwersji liczb z plikow.
 * PRE:
 * - podanie numeru rodzaju obslugi - numer rodzaju pliku (argument: parOption);
 * POST:
 * - brak.
 */
void funHandlingWithFile(unsigned short parOption);

/*
 * funConverterHandling() - funkcja obslugujaca konwertowanie liczb
 * w systemach pozycyjnych o podstawach od 2 do 10.
 * PRE:
 * - brak.
 * POST:
 * - brak.
 */
void funConverterHandling();

#endif // CONVERTERS_H

/* converters.h */
/********** END_OF_FILE **********/
