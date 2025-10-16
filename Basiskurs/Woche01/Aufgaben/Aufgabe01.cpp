/*
Aufgaben:
Aufgabe 1
Schreiben Sie ein C Programm zur Berechnung der Distanz zwischen 2 Punkte in einem
zweidimensionalen Koordinatensystem. Dies geschieht, indem Sie die Differenz der x und y
Koordinaten jeweils quadrieren, die Quadrate summieren und die Wurzel ziehen. Hier die
Formel.
D = wurzel((x1-x2)≤+(y1-y2)≤)
das Programm soll folgendes besitzen:
ï Eine Funktion, welche dem Benutzer erkl‰rt, was das Programm tut
ï Eine Funktion zur Eingabe der x und y Werte
ï Eine Funktion zur Berechnung der Distanz
Des weiteren definieren Sie eine Variable Distanz in der main Funktion, diese soll ausﬂerhalb der
main ge‰ndert werden (Spoiler: Pointer)
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

void programmbeschreibung(const char* message);
int eingabe(const char* message);
void distanzBerechnung(int x1, int x2, int y1, int y2, double* distanz);

int main()
{
    int x1, x2, y1, y2;
    double distanz;

    programmbeschreibung("Berechnung der Distanz zwischen 2 Punkten X1,Y1 und X2,Y2:");
    x1 = eingabe("Bitte Wert fuer X1 eingeben: ");
    y1 = eingabe("Bitte Wert fuer Y1 eingeben: ");
    x2 = eingabe("Bitte Wert fuer X2 eingeben: ");
    y2 = eingabe("Bitte Wert fuer Y2 eingeben: ");

    distanzBerechnung(x1, x2, y1, y2, &distanz);

    printf("Die Distanz betraegt: %.2f", distanz);

    return 0;
}

void distanzBerechnung(int x1, int x2, int y1, int y2, double *distanz)
{
    *distanz = sqrt(((x1 - x2) * (x1 - x2)) + (y1 - y2) * (y1 - y2));
}

int eingabe(const char* message)
{
    int wert;
    printf("%s", message);
    scanf("%d", &wert);

    return wert;
}

void programmbeschreibung(const char* message)
{
    printf("Funktionsbeschreibung: %s\n", message);
}
