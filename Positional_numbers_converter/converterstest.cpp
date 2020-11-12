/********** BEGIN_OF_FILE **********/
/* converterstest.cpp */

#include "converters.h"
#include "converterstest.h"

using namespace std;

unsigned short vDataRecord;

/*
 * void funCreateFileTest()
 */
void funCreateFileTest()
{
    unsigned short vLengthNumber = 0, vDigit = 0;
    long long vNumber, vPotega;
    vDataRecord = 0;
    srand(time_t(NULL)+(unsigned int)&vNumber); // generowanie
    ofstream strOut;
    strOut.open("test.txt");
    for (unsigned short i = 2; i <= 10; i++)
    {
        for (unsigned short j = 2; j <= 10; j++)
        {
            if (i == j)
                continue;
            else
            {
                vDataRecord++;
                vPotega = 1;
                vNumber = 0;
                vLengthNumber = rand() % 3 + 3;
                for (unsigned short k = 0; k < vLengthNumber; k++)
                {
                    vDigit = rand() % i;
                    if ((k == 0) && (vDigit == 0))
                        vDigit++;
                    vNumber += vPotega * vDigit;
                    vPotega *= 10;
                    if (k == (vLengthNumber - 1))
                        strOut << vNumber << " " << i << " " << j << endl;
                }
            }
        }
    }
    strOut.close();
}

/*
 * void funTest()
 */
void funTest()
{
    long long vNumber1, vNumber2;
    unsigned short vBase1, vBase2;
    funCreateFileTest();
    ifstream strIn;
    strIn.open("test.txt");
    for (unsigned short i = 0; i < vDataRecord; i++)
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
             << vNumber2 << " (" << vBase2 << ")" << endl; // wypisanie wyniku
    }
    strIn.close();
}

/* converterstest.cpp */
/********** END_OF_FILE **********/
