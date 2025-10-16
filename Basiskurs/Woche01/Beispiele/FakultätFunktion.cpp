/*
--------------------------------------------------------------------------------
Programm: Fakultätsberechnung in C
m Benutzer ein und berechnet anschließend
die Fakultät dieser Zahl. Die Fakultät (mathematisch: n!) ist das Produkt aller
positiven ganzen Zahlen von 1 bis n. Sie wird definiert als:

    n! = 1 × 2 × 3 × ... × n
und per Definition gilt:
    0! = 1

Beispiel:
    Eingabe: 5
    Berechnung: 1 × 2 × 3 × 4 × 5 = 120
    Ausgabe: Fakultaet: 120

Ablauf des Programms:
1. Der Benutzer wird aufgefordert, eine ganze Zahl einzugeben.
2. Die Eingabe wird in der Variablen „eingabe“ gespeichert.
3. Die Funktion berechneFakultaet() wird mit diesem Wert aufgerufen.
4. Innerhalb der Funktion wird in einer Schleife von 1 bis n multipliziert.
5. Das Ergebnis wird an main() zurückgegeben und ausgegeben.

Hinweis:
- Für negative Zahlen ist die Fakultät mathematisch nicht definiert.
  In diesem Fall gibt das Programm 0 zurück.
- Für große Zahlen kann ein Überlauf auftreten, da der Datentyp
  „unsigned long long“ nur bis ca. 20! korrekt darstellen kann.
- Der Präprozessorbefehl #define _CRT_SECURE_NO_WARNINGS dient nur
  dazu, bei Microsoft Visual Studio bestimmte Warnungen zu unterdrücken.

Erstellt mit Fokus auf:
- Einfache, nachvollziehbare Struktur
- Sichere Eingabe und robuste Berechnung
--------------------------------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Funktionsprototyp: berechnet die Fakultät einer ganzen Zahl
unsigned long long berechneFakultaet(int n);

int main(void)
{
    int eingabe = 0;

    printf("Bitte gib eine ganze Zahl ein: ");
    scanf("%d", &eingabe);

    // Fakultät berechnen und ausgeben
    printf("Fakultaet: %llu\n", berechneFakultaet(eingabe));

    return 0;
}

// Funktion zur Berechnung der Fakultät einer Zahl
unsigned long long berechneFakultaet(int n)
{
    // Negative Zahlen haben keine definierte Fakultät
    if (n < 0)
    {
        printf("Fehler: Die Fakultät ist für negative Zahlen nicht definiert.\n");
        return 0;
    }

    unsigned long long fakultaet = 1;

    // 0! = 1 laut Definition
    for (int i = 1; i <= n; i++)
    {
        fakultaet *= i;
    }

    return fakultaet;
}
