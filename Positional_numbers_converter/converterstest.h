/********** BEGIN_OF_FILE **********/
/* converterstest.h */

#ifndef CONVERTERSTEST_H
#define CONVERTERSTEST_H

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

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
 * funTest() - funkcja przeprowadzajaca test poprawnosci
 * dzialania konwersji liczb. Wykorzystuje tworzenie pliku
 * za pomoca funkcja funCreateTest() a nastepnie korzysta
 * z utworzonego w ten sposob pliku.
 * PRE:
 * - brak.
 * POST:
 * - brak.
 */
void funTest();

#endif // CONVERTERSTEST_H

/* converterstest.h */
/********** END_OF_FILE **********/
