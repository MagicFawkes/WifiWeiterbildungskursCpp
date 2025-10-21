/*

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include "src/TurnierFunktionen.h"

int eingabe(const char* message);

int main()
{
    int auswahl;
    struct Teilnehmer* teilnehmer = NULL;
    int anzahlTeilnehmer = 0;

    do
    {
        auswahl = eingabe("\n1 = Teilnehmer hinzufuegen \n2 = Alle Teilnehmer anzeigen \n3 = Teilnehmer loeschen \n4 = Teilnehmer sortieren \n5 = Beenden\nEingabe: ");

        switch (auswahl)
        {
			case 1:
                printf("\nTeilnehmer hinzufuegen:");
                //teilnehmer = (struct Teilnehmer*)realloc(teilnehmer, (anzahlTeilnehmer + 1) * sizeof(struct Teilnehmer));
				teilnehmer = erzeugeTeilnehmer(teilnehmer, &anzahlTeilnehmer);

                if (teilnehmer == NULL) {
                    perror("realloc failed");
                    return 1;
                }

                anzahlTeilnehmer++;

                printf("\nBitte Name eingeben: ");
                // klassische Variante – liest nur bis zum ersten Leerzeichen
                //scanf("%s", (teilnehmer + anzahlTeilnehmer - 1)->name);

                // erweiterte Variante – liest die ganze Zeile bis zum Zeilenende (inkl. Leerzeichen),
                // maximal 49 Zeichen, sicherer und platzsparend
                scanf(" %40[^\n]", (teilnehmer + anzahlTeilnehmer - 1)->name);

                printf("Bitte Punkte eingeben: ");
                scanf("%d", &(teilnehmer + anzahlTeilnehmer - 1)->punkte);

				break;
            case 2:
                printf("\nAlle Teilnehmer anzeigen: \n");

                for (int i=0; i< anzahlTeilnehmer; i++)
                {
                    printf("\nName: %s", (teilnehmer + i)->name);
                    printf("\nPunkte: %d\n", (teilnehmer + i)->punkte);
                }
                break;
            case 3:
                printf("\nTeilnehmer loeschen: \n");

				if (anzahlTeilnehmer > 0)
				{
                    //teilnehmer = (struct Teilnehmer*)realloc(teilnehmer, (anzahlTeilnehmer - 1) * sizeof(struct Teilnehmer));
					teilnehmer = entferneTeilnehmer(teilnehmer, &anzahlTeilnehmer);

                    if (teilnehmer == NULL && anzahlTeilnehmer > 1)
                    {
                        perror("realloc failed");
                        return 1;
                    }
                    anzahlTeilnehmer--;
				}
                break;
            case 4:
                printf("\nTeilnehmer sortieren: \n");
                teilnehmer = sortiereTeilnehmer(teilnehmer, &anzahlTeilnehmer);
                break;
            case 5:
                printf("Programm beenden.\n");
                break;
			default:
                printf("Ungueltige Auswahl. Bitte erneut versuchen.\n");
				break;
        }

    } while (auswahl != 5);
	

    return 0;
}