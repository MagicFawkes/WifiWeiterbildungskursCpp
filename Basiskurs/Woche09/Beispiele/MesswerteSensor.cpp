/*
Aufgabe
Ein System sammelt Messwerte eines Sensors.

Die Werte werden in einem std::vector<int> gespeichert und müssen gefiltert, transformiert, ausgewertet und protokolliert werden – ohne eigene Klassen oder Funktoren, nur mit Lambdas.


Teil 1 – Initialisierung
Erstelle einen std::vector<int> namens messwerte
Gib alle Messwerte mit std::for_each und einer Lambda-Expression auf der Konsole aus.

Teil 2 – Filtern mit Capture
Definiere eine Variable schwellwert mit dem Wert 10.
Erstelle mit std::copy_if einen neuen Vektor gefiltert, der nur Messwerte größer als schwellwert enthält.
Der Schwellwert muss per Lambda-Capture verwendet werden.

Teil 3 – Stateful Lambda (mutable)
Verwende std::for_each mit einer mutable Lambda, die:
jeden Wert auf der Konsole ausgibt
intern mitzählt, wie viele Werte ausgegeben wurden
Gib nach dem Durchlauf die Anzahl der ausgegebenen Werte aus.
Der Zähler darf nicht außerhalb der Lambda verändert werden.

Teil 4 – Lambda als Callback

implementiere folgende Funktion:
void verarbeite(

    const std::vector<int>& daten,

    const std::function<void(int)> callback

);

mithilfe von Funktionspointern, Funktoren und Lambda

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void verarbeite(const std::vector<int>& daten, const std::function<void(int)> callback)
{
	
}

int main()
{
    std::vector<int> messwerte = { 2,1,10,5, 6 };
    std::for_each(messwerte.begin(), messwerte.end(), [](const int& p)->void {
	    std::cout << p << std::endl;
        });

    int schwellwert = 10;

    std::vector<int> messwerte2;
    std::copy_if(messwerte.begin(), messwerte.end(), std::back_inserter(messwerte2), [schwellwert](int wert) ->bool {          // Lambda-Capture
        return wert > schwellwert;
        });

    for (int messwert : messwerte2)
    {
        std::cout << messwert << std::endl;
    }

    int x = 0;

    std::for_each(messwerte2.begin(), messwerte2.end(), [x]() mutable ->void
        {
            x++;
	        std::cout << "Wert: " << x << std::endl;
        });
}

