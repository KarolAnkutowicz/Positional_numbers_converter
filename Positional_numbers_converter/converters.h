/********** BEGIN_OF_FILE **********/
/* converters.h */

#ifndef CONVERTERS_H
#define CONVERTERS_H

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
