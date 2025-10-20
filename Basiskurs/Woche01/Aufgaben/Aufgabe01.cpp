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
void distanzBerechnung(const int x1, const int x2, const int y1, const int y2, double* distanz);

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

void distanzBerechnung(const int x1, const int x2, const int y1, const int y2, double *distanz)
{
    //*distanz = sqrt(((x1 - x2) * (x1 - x2)) + (y1 - y2) * (y1 - y2));

    /* Unterschied einmal bilden; in double casten, um Overflow/Pr‰zisionsverluste zu vermeiden */
    const double dx = x1 - x2;
    const double dy = y1 - y2;

    /* numerisch stabiler als sqrt(dx*dx + dy*dy) */
    // oder mit pow --> *distanz = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    *distanz = hypot(dx, dy);
}

int eingabe(const char* message)
{
    /*int wert;
    printf("%s", message);
    scanf("%d", &wert);

    return wert;*/

    int wert;
    int rc;

    for (;;)
    {
        printf("%s", message);
        rc = scanf("%d", &wert);
        if (rc == 1)
        {
            return wert;
        }

        /* Fehleingabe: Eingabepuffer leeren */
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
        puts("Ungueltige Eingabe, bitte eine ganze Zahl eingeben.");
    }
}

void programmbeschreibung(const char* message)
{
    printf("Funktionsbeschreibung: %s\n", message);
}
