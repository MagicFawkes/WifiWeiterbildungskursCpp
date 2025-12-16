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

    lambdaHello();

    double a = 254;
    double b = 12;

    double (*lambda1)(double, double) = [](double a, double b)->double
        {
            return a / b;
        };

    //auch Möglich, Capture wäre dann hier okay
    std::function<double(double, double)> lambda2 = [](double a, double b)->double
        {
            return a / b;
        };

    std::cout << lambda1(a, b) << std::endl;
    std::cout << lambda2(a, b) << std::endl;

    //weitere Varianten mit Capture, Wert verändern darin daher Adressoperator &c (ohne Adressoperator wäre :
    int c = 22;
    std::function<double(double, double)> lambda3 = [&c](double a, double b)->double 
        {
            c++;
            return (a / b) + c;
        };

    std::cout << lambda3(a, b) << std::endl;

    //weitere Varianten mit Capture, Wert verändern ohne Adressoperator dafür Kopie und Mutable, damit er verändert werden kann
    int d = 22;
    std::function<double(double, double)> lambda4 = [d](double a, double b) mutable ->double
        {
            d++;
            return (a / b) + d;
        };

    std::cout << lambda4(a, b) << std::endl;
    std::cout << d << std::endl;
    // d außen ist unverändert (22)
}

