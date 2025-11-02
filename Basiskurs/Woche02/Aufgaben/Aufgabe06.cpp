/*
Aufgabe 6
Erstellen Sie ein Programm zur Kalorienberechnung und -verwaltung für mehrere Personen.
Jede Person hat folgende Eigenschaften:
• Name
• Kalorien, die Sie verbraucht
• Liste der gegessenen Speisen
Das Programm soll dem Benutzer ein Menü mit folgenden Auswahlmöglichkeiten anbieten:
1. Neue Person hinzufügen
• Der Benutzer gibt den Namen der Person ein.
• Anschließend kann er die erste Speise und deren Kalorien hinzufügen.
2. Kalorien und Essen zu einer bestehenden Person hinzufügen
• Der Benutzer wählt eine vorhandene Person aus.
• Danach kann er weitere Speisen und deren Kalorien angeben.
• Die Kalorien werden automatisch zur Gesamtsumme dieser Person addiert.
3. Person löschen
• Der Benutzer kann eine Person anhand ihres Index oder Namens aus der Liste
entfernen.
4. Teilnehmerliste anzeigen
• Zeigt alle Personen mit ihrem Namen, ihren gesamten Kalorien und allen
eingetragenen Speisen an.
5. Programm beenden
• Beim Beenden werden alle Personen nach absteigendem Kalorienverbrauch
sortiert angezeigt (die Person mit den meisten Kalorien zuerst)
*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>
#include <stdio.h>

struct Speise
{
	char essen[40];
	int kalorien;
};

struct Person
{
	char name[40];
	int gesamtKalorien;
	int anzahlSpeisen;
	struct Speise* essenListe;
};

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

struct Speise* erzeugeSpeise(struct Speise* speise, const int* const anzahlSpeisen)
{
	return (Speise*)realloc(speise, (*anzahlSpeisen + 1) * sizeof(struct Speise));
}

struct Person* erzeugePerson(struct Person* person, const int* const anzahlPersonen)
{
	return (Person*)realloc(person, (*anzahlPersonen + 1) * sizeof(struct Person));
}

struct Person* entfernePerson(struct Person* person, const int* const anzahlPersonen)
{
	free(person[*anzahlPersonen -1].essenListe);
	return (Person*)realloc(person, (*anzahlPersonen - 1) * sizeof(struct Person));
}

void sortierePersonen(struct Person* person, const int* const anzahlPersonen)
{
	struct Person temp;

	for (int i = 0; i < *anzahlPersonen; i++)
	{
		for (int j = i + 1; j < *anzahlPersonen; j++)
		{
			if (person[i].gesamtKalorien < person[j].gesamtKalorien)
			{
				temp = person[i];
				person[i] = person[j];
				person[j] = temp;
			}
		}
	}
}

void zeigeTeilnehmer(Person* personen, int* anzahlPersonen)
{
	printf("\nAlle Teilnehmer anzeigen: \n");
	sortierePersonen(personen, anzahlPersonen);

	for (int i = 0; i < *anzahlPersonen; i++)
	{
		printf("\nIndex: %d", i);
		printf("\nName: %s", (personen + i)->name);
		printf("\nGesamt Kalorien: %d", (personen + i)->gesamtKalorien);

		for (int u = 0; u < personen[i].anzahlSpeisen; u++)
		{
			printf("\nEssen: %s", (personen + i)->essenListe[u].essen);
			printf("\nKalorien: %d\n", (personen + i)->essenListe[u].kalorien);
		}
	}
}


int main()
{
	int auswahl;
	struct Person* personen = NULL;
	int anzahlPersonen = 0;

	do
	{
	    auswahl = eingabe("\n1 = Person hinzufuegen \n2 = Kalorien und Essen zu einer Person hinzufuegen \n3 = Teilnehmer loeschen \n4 = Teilnehmer anzeigen \n5 = Beenden\nEingabe: ");

	    switch (auswahl)
	    {
			case 1:
				printf("\nPerson hinzufuegen:");
				personen = erzeugePerson(personen, &anzahlPersonen);

				if (personen == NULL) {
					perror("realloc failed");
					return 1;
				}

				anzahlPersonen++;

				printf("\nBitte Name eingeben: ");
				// klassische Variante – liest nur bis zum ersten Leerzeichen
				//scanf("%s", (teilnehmer + anzahlTeilnehmer - 1)->name);

				// erweiterte Variante – liest die ganze Zeile bis zum Zeilenende (inkl. Leerzeichen),
				// maximal 49 Zeichen, sicherer und platzsparend
				scanf(" %40[^\n]", (personen + anzahlPersonen - 1)->name);
				(personen + anzahlPersonen - 1)->gesamtKalorien = 0;
				(personen + anzahlPersonen - 1)->anzahlSpeisen = 0;
				(personen + anzahlPersonen - 1)->essenListe = NULL;

				break;
			case 2:
				{
					zeigeTeilnehmer(personen, &anzahlPersonen);

					int index = eingabe("\nBitte Index der Person eingeben: ");

					personen[index].essenListe = erzeugeSpeise(personen[index].essenListe, &personen[index].anzahlSpeisen);
					personen[index].anzahlSpeisen++;

					printf("\nBitte Essen eingeben: ");
					scanf(" %40[^\n]", (personen[index].essenListe[personen[index].anzahlSpeisen - 1].essen));

					printf("\nBitte Kalorien eingeben: ");
					scanf("%d", &(personen[index].essenListe[personen[index].anzahlSpeisen - 1].kalorien));

					personen[index].gesamtKalorien += personen[index].essenListe[personen[index].anzahlSpeisen - 1].kalorien;
				}
				break;
			case 3:
				printf("\nTeilnehmer loeschen: \n");
				zeigeTeilnehmer(personen, &anzahlPersonen);

				if (anzahlPersonen > 0)
				{
					int index = eingabe("\nBitte Index der Person eingeben: ");

					struct Person temp;
					temp = personen[index];
					personen[index] = personen[anzahlPersonen-1];
					personen[anzahlPersonen - 1] = temp;

					//teilnehmer = (struct Teilnehmer*)realloc(teilnehmer, (anzahlTeilnehmer - 1) * sizeof(struct Teilnehmer));
					personen = entfernePerson(personen, &anzahlPersonen);

					if (personen == NULL && anzahlPersonen > 1)
					{
						perror("realloc failed");
						return 1;
					}
					anzahlPersonen--;
				}
				break;
			case 4:
				zeigeTeilnehmer(personen, &anzahlPersonen);

				break;
			case 5:
				printf("*********** Programm beenden ***********");
				zeigeTeilnehmer(personen, &anzahlPersonen);

				break;
			default:
				printf("Ungueltige Auswahl. Bitte erneut versuchen.\n");
				break;
	    }

	} while (auswahl != 5);

	return 0;
}


