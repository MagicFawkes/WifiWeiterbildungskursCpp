/*
------------------------------------------------------------
 Programm: LED-Bit-Operationen mit Benutzereingabe

 Dieses Programm demonstriert den Umgang mit Binärzahlen (Bits)
 und LED-Darstellung in C.
 Der Benutzer gibt einen ganzzahligen Wert ein, der als Bitmuster
 interpretiert wird (z. B. 101010 für LED an/aus-Zustände).

 Ablauf:
 1. Der Benutzer wird aufgefordert, einen Wert für die LEDs einzugeben.
 2. Dieser Wert wird in der Variable `ledStatus` gespeichert.
 3. Mit `led_inverter_v2()` werden alle Bits invertiert (1 → 0, 0 → 1),
    und die Anzahl der verwendeten Bits wird über `counter` zurückgegeben.
 4. Anschließend wird mit `led_an_aus_ausgabe()` der neue LED-Zustand
    (ein/aus) visuell ausgegeben.
 5. Mit `printf_binary()` wird das Ergebnis zusätzlich als Binärzahl angezeigt.

 Abhängigkeiten:
 - Die Funktionen `led_inverter_v2`, `led_an_aus_ausgabe` und `printf_binary`
   sind in "src/BinaryFunktionen.h" deklariert und in einer zugehörigen
   Quelldatei implementiert.

 Zweck:
 - Dieses Programm dient zur Demonstration von Bit-Operationen,
   insbesondere dem Invertieren von Bits und der Interpretation
   von Ganzzahlen als LED-Muster.
------------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "src/BinaryFunktionen.h"

int eingabe(const char* message);

int main()
{
	int ledStatus = eingabe("Geben Sie einen Wert fuer die LEDs ein: ");
    //printf_binary(ledStatus, 10);
    //led_an_aus_ausgabe(ledStatus, 10);

    //edStatus = led_inverter(ledStatus);
    //led_an_aus_ausgabe(ledStatus, 10);

    int counter;
    ledStatus = led_inverter_v2(ledStatus, &counter);
    led_an_aus_ausgabe(ledStatus, counter);
    printf_binary(ledStatus, counter);

    return 0;
}

int eingabe(const char* message)
{
    int wert;
    int result;

    printf("%s", message);
    result = scanf("%d", &wert);

	if (result != 1) 
    {
        // Handle input error, e.g., set default value or print error
        printf("Ungueltige Eingabe. Standardwert 0 wird verwendet.\n");
        wert = 0;
    }

    return wert;
}
