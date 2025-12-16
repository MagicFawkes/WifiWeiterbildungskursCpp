/*
Schreibe eine Lambda-Expression, die:
zwei int-Werte addiert
das Ergebnis zurückgibt
Weise sie einer Variablen zu und rufe sie auf.
*/

#include <iostream>
#include <functional>

int main()
{
    int a = 10;
    int b = 20;

	// mit Function Library Capture ist hier möglich
    std::function<int(int, int)> lambda1 = [](int a, int b)->int
        {
            return a + b;
        };

    //oder auch möglich
    auto lambda2 = [](int a, int b)->int
        {
            return a + b;
        };

    //oder mit Funkjtionspointer auch möglich wenn Capture NICHT verwendet wird
    int (*lambda3)(int, int) = [](int a, int b)->int
        {
            return a + b;
        };

    std::cout << lambda1(a, b) << std::endl;
    std::cout << lambda2(a, b) << std::endl;
    std::cout << lambda3(a, b) << std::endl;
}

