/*
Schreibe eine Lambda-Expression, die:
keinen Parameter hat
"Hallo Lambda" auf der Konsole ausgibt
Schreibe eine Lambda-Expression, die:
zwei double-Werte dividiert
den Rückgabetyp explizit angibt
*/

#include <iostream>
#include <functional>

int main()
{
    //oder auch möglich
    auto lambdaHello = []()->void
        {
            std::cout << "Hello" << std::endl;
        };

    //oder mit Funkjtionspointer auch möglich wenn Capture NICHT verwendet wird
    int (*lambda3)(int, int) = [](int a, int b)->int
        {
            return a + b;
        };

    lambdaHello();

    double a = 254;
    double b = 12;

    double (*lambda1)(double, double) = [](double a, double b)->double
        {
            return a / b;
        };

    std::cout << lambda1(a, b);
}

