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
}

