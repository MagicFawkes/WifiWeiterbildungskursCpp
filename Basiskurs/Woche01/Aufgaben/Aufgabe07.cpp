/*
Schreiben Sie ein C Programm, welches die Lohnsteuer eines Angestellten berechnen soll. Der
benutzer soll sein jährliches Gehlat in Brutto eingeben und sein Netto Gehalt und die bezahlten
Lohnsteuer erfahren.
Das Programm soll folgendes besitzen:
• Eine Funktion zur Speicherung der Eingabe
• Eine Funktion zur Berechnung der Lohnsteuer. Diese Funktion ist eine void Funktion (kein
Wert wird returniert, alle Variablen sollen in der main definiert werden)
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int eingabe(const char* message);
void ermittleNettoGehalt(int bruttoGehalt, float* lohnsteuer, float* SVBeitraege);

int main()
{
	float nettoGehalt = 0, lohnsteuer = 0, SVBeitraege = 0;
	int bruttoGehalt = eingabe("Bitte geben Sie Ihr jaehrliches Brutto-Gehalt ein: ");

	ermittleNettoGehalt(bruttoGehalt, &lohnsteuer, &SVBeitraege);

    printf("Bruttogehalt: EUR %d \nLohnsteuer: EUR %.2f\nSV-Beitraegen: EUR %.2f\nNettogehalt: EUR %.2f\n", 
		bruttoGehalt, lohnsteuer, SVBeitraege, (float)bruttoGehalt - lohnsteuer - SVBeitraege);

    return 0;
}


void ermittleNettoGehalt(int bruttoGehalt, float *lohnsteuer, float *SVBeitraege)
{
	*SVBeitraege = bruttoGehalt * 0.1812f;

	float steuerpfEinkommen = bruttoGehalt - *SVBeitraege;

	if (steuerpfEinkommen > 103072)
	{
		*lohnsteuer += (steuerpfEinkommen - 103072) * 0.50f;
		steuerpfEinkommen = 103072;
	}
	if (steuerpfEinkommen > 69166)
	{
		*lohnsteuer += (steuerpfEinkommen - 69166) * 0.48f;
		steuerpfEinkommen = 69166;
	}
	if (steuerpfEinkommen > 35836)
	{
		*lohnsteuer += (steuerpfEinkommen - 35836) * 0.40f;
		steuerpfEinkommen = 35836;
	}
	if (steuerpfEinkommen > 21617)
	{
		*lohnsteuer += (steuerpfEinkommen - 21617) * 0.30f;
		steuerpfEinkommen = 21617;
	}
	if (steuerpfEinkommen > 13308)
	{
		*lohnsteuer += (steuerpfEinkommen - 13308) * 0.20f;
		steuerpfEinkommen = 13308;
	}
}

int eingabe(const char* message)
{
    int wert;

    printf("%s", message);
    scanf("%d", &wert);

    return wert;
}
