/*
Aufgabe 4
Kontoverwaltung mit Klassen in C++ – Erstelle ein C++-Programm zur Verwaltung eines
einfachen Bankkontos. Das Programm soll eine Klasse Konto enthalten, die grundlegende
Kontofunktionen bereitstellt.
Anforderungen: Die Klasse Konto besitzt die Attribute string inhaber, int kontonummer und
double kontostand. Sie hat einen Konstruktor. Methoden: void einzahlen(double betrag) (erhöht
den Kontostand um den Betrag, falls dieser positiv ist), bool abheben(double betrag) (verringert
den Kontostand um den Betrag, wenn genug Guthaben vorhanden ist, und gibt true zurück,
sonst false) sowie void anzeigen() (gibt alle Kontoinformationen auf der Konsole aus).
In der main()-Funktion soll ein Konto-Objekt erstellt werden, es sollen mehrere Einzahlungen
und Abhebungen durchgeführt werden, und nach jeder Aktion sollen die aktuellen
Kontoinformationen angezeigt werden.
Teste auch eine Abhebung, die fehlschlägt, weil das Guthaben nicht ausreicht.
Überlege was zu private und was zu public gehört und was Sie mit dem Konstruktor machen
sollen. Es sollen 2 Konstruktoren verwendet werden. Einer davon ist der Standardkonstruktor,
der soll nicht verloren werden.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
    printf("Test");
    return 0;
}