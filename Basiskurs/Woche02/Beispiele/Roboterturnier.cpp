/*

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include "src/BinaryFunktionen.h"

int eingabe(const char* message);

struct Teilnehmer
{
    char name[30];
    int punkte;
};

int main()
{
    int auswahl;
    struct Teilnehmer* teilnehmer = NULL;
    int anzahlTeilnehmer = 0;

    do
    {
        auswahl = eingabe("1 = Teilnehmer hinzufuegen, \n2 = Alle Teilnehmer anzeigen, \n3 = Teilnehmer loeschen, \n4 = Beenden\nEingabe: ");

        switch (auswahl)
        {
			case 1:
                printf("Teilnehmer hinzufügen: \n");
                teilnehmer = (Teilnehmer*)realloc(teilnehmer, (anzahlTeilnehmer + 1) * sizeof(Teilnehmer));

                if (teilnehmer == NULL) {
                    perror("realloc failed");
                    return 1;
                }

                anzahlTeilnehmer++;

                printf("\nBitte Name eingeben:");
                scanf("%s", (teilnehmer + anzahlTeilnehmer - 1)->name);

                printf("\nBitte Punkte eingeben:");
                scanf("%d", &(teilnehmer + anzahlTeilnehmer - 1)->punkte);

				break;
            case 2:
                printf("Alle Teilnehmer anzeigen: \n");

                for (int i=0; i< anzahlTeilnehmer; i++)
                {
                    printf("\nName: %s", (teilnehmer + i)->name);
                    printf("\nPunkte: %d\n", (teilnehmer + i)->punkte);
                }
                break;
            case 3:
                printf("Teilnehmer löschen: \n");

				if (anzahlTeilnehmer != 0)
                teilnehmer = (Teilnehmer*)realloc(teilnehmer, (anzahlTeilnehmer - 1) * sizeof(Teilnehmer));
                anzahlTeilnehmer--;
                break;
            case 4:
                printf("Programm beenden.\n");
                break;
			default:
                printf("Ungueltige Auswahl. Bitte erneut versuchen.\n");
				break;
        }

    } while (auswahl != 4);
	

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
