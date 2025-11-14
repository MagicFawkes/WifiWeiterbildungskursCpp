/*
Aufgabe 3
Erstelle eine Klasse Student. Jeder Student soll einen Namen, eine Anzahl an Noten und einen
Notendurchschnitt haben. Der Benutzer soll in der Lage sein, die Anzahl der Studenten sowie
pro Studenten die Anzahl der Noten bestimmen (Dies wird nur einmal festgelegt). Am Ende des
Programmes sollen alle Studenten mit ihren jeweiligen Namen und Noten sowie
Notendurchschnitt sortiert ausgegeben werden

Lösung mit new[] und delete[], da vector nicht erlaubt oder noch nicht gelernt
*/

#include <iostream>
#include <string>

class student
{
public:
	std::string namen;
	float notendurchschnitt;
	int *noten;
	int anzahlNoten;
};

void studentenSortieren(student* studenten, int anzahl);

int main()
{
	int anzahlStudenten;
	student *studenten;

	std::cout << "Bitte Anzahl der Studenten eingeben: ";
	std::cin >> anzahlStudenten;
	
	studenten = new student[anzahlStudenten];

	for (int i = 0; i < anzahlStudenten; i++)
	{
		std::cout << "\nBitte Namen eingeben: ";
		std::cin >> studenten[i].namen;

		std::cout << "Bitte Anzahl der Noten eingeben: ";
		std::cin >> studenten[i].anzahlNoten;

		studenten[i].noten = new int[studenten[i].anzahlNoten];

		int noteSumme = 0;

		for (int u = 0; u < studenten[i].anzahlNoten; ++u)
		{
			std::cout << "Bitte Note eingeben: ";
			std::cin >> studenten[i].noten[u];
			noteSumme += studenten[i].noten[u];
		}
		studenten[i].notendurchschnitt = (float)noteSumme / studenten[i].anzahlNoten;
	}

	studentenSortieren(studenten, anzahlStudenten);

	std::cout << "\n**********Studenten sortiert nach Notendurchschnitt aufsteigend**********\n";

	for (int i = 0; i < anzahlStudenten; i++)
	{
		std::cout << "\nName: ";
		std::cout << studenten[i].namen;

		std::cout << "\nAnzahl Noten: ";
		std::cout << studenten[i].anzahlNoten;

		for (int u = 0; u < studenten[i].anzahlNoten; ++u)
		{
			std::cout << "\nNote: ";
			std::cout << studenten[i].noten[u];
		}

		std::cout << "\nNotendurchschnitt: ";
		std::cout << studenten[i].notendurchschnitt;

		delete[] studenten[i].noten;
	}

	delete[] studenten;

    return 0;
}

void studentenSortieren(student* studenten, int anzahl)
{
	student tmp;

	for (int i = 0; i < anzahl; ++i)
	{
		for (int u = i+1; u < anzahl; ++u)
		{
			if (studenten[i].notendurchschnitt > studenten[u].notendurchschnitt)
			{
				tmp = studenten[i];
				studenten[i] = studenten[u];
				studenten[u] = tmp;
			}
		}
	}
}