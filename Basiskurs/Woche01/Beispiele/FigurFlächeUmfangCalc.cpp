
/*
================================================================================
Programm zur Berechnung von Umfang und Fläche verschiedener geometrischer Figuren
================================================================================

Beschreibung:
Dieses Programm ermöglicht dem Benutzer die Berechnung von Umfang und Fläche
verschiedener geometrischer Formen: Kreis, Rechteck, Dreieck und Quadrat.

Ablauf:
1. Der Benutzer wird wiederholt aufgefordert, eine Figur auszuwählen.
   - 1 = Kreis
   - 2 = Rechteck
   - 3 = Dreieck
   - 4 = Quadrat
   - 0 = Beenden des Programms
2. Je nach Auswahl werden die entsprechenden Eingabewerte (z. B. Seitenlängen,
   Durchmesser) abgefragt.
3. Die Berechnungen werden in eigenen Funktionen durchgeführt:
   - `kreisBerechnung()` berechnet Umfang und Fläche eines Kreises.
   - `rechteckBerechnung()` berechnet Umfang und Fläche eines Rechtecks.
   - `dreieckBerechnung()` berechnet Umfang und Fläche eines rechtwinkligen Dreiecks.
   - `quadratBerechnung()` berechnet Umfang und Fläche eines Quadrats.
4. Das Ergebnis (Umfang und Fläche) wird anschließend auf der Konsole ausgegeben.
5. Der Benutzer kann beliebig viele Berechnungen durchführen, bis er `0` eingibt.

Besonderheiten:
- Das Programm verwendet Zeiger (`float*`), um die berechneten Werte von
  Umfang und Fläche direkt in den aufrufenden Funktionskontext zurückzuschreiben.
- Die globale Variable `pi` enthält den Näherungswert 3.1415926 für Kreisberechnungen.
- Eingaben werden über die Funktion `eingabe()` abgefragt und als `float` zurückgegeben.
- Texte werden über `ausgabeAuswahl()` ausgegeben, um eine einheitliche Struktur zu wahren.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

const double pi = 3.1415926;

float eingabe(const char* message);
void ausgabeAuswahl(const char* message);
void kreisBerechnung(float* umfang, float* fläche, float durchmesser);
void rechteckBerechnung(float* umfang, float* fläche, float a, float b);
void dreieckBerechnung(float* umfang, float* fläche, float a, float b, float c);
void quadratBerechnung(float* umfang, float* fläche, float a);

int main()
{
    int figur;
    float umfang = 0, fläche = 0;

    do
    {
        figur = (int)eingabe("1=Kreis, \n2=Rechteck, \n3=Dreieck, \n4=Quadraht \n0=Beenden \nBitte Figur auswaehlen:  ");

        if (figur == 1)
        {
            ausgabeAuswahl("\nKreis ausgewaehlt:");
            float durchmesser = eingabe("\nBitte Durchmesser eingeben: ");
            kreisBerechnung(&umfang, &fläche, durchmesser);
        }
        else if (figur == 2)
        {
            ausgabeAuswahl("\nRechteck rechtwinkelig ausgewaehlt:");
            float a = eingabe("\nBitte Laenge A eingeben: ");
            float b = eingabe("Bitte Laenge B eingeben: ");
            rechteckBerechnung(&umfang, &fläche, a , b);
        }
        else if (figur == 3)
        {
            ausgabeAuswahl("\nDreieck ausgewaehlt:");
            float a = eingabe("\nBitte Laenge A eingeben: ");
            float b = eingabe("Bitte Laenge B eingeben: ");
            float c = eingabe("Bitte Laenge C eingeben: ");
            dreieckBerechnung(&umfang, &fläche, a, b, c);
        }
        else if (figur == 4)
        {
            ausgabeAuswahl("\nQuadrat ausgewaehlt:");
            float a = eingabe("\nBitte Laenge A eingeben: ");
            quadratBerechnung(&umfang, &fläche, a);
        }
        else if (figur == 0)
        {
            ausgabeAuswahl("Programm Beenden\n");
		}

        if (figur == 1 || figur == 2 || figur == 3 || figur == 4)
        {
            printf("Umfang: %.2f\n", umfang);
            printf("Flaeche: %.2f\n\n", fläche);
        }

	} while (figur != 0);

    return 0;
}

void quadratBerechnung(float* umfang, float* fläche, float a)
{
    *umfang = 4 * a;
    *fläche = a * a;
}

void dreieckBerechnung(float* umfang, float* fläche, float a, float b, float c)
{
    *umfang = a + b + c;
    *fläche = (a * b)/2;
}

void rechteckBerechnung(float* umfang, float* fläche, float a, float b)
{
	*umfang = 2 * (a + b);
	*fläche = a * b;
}

void kreisBerechnung(float* umfang, float* fläche, float durchmesser)
{
    *umfang = durchmesser * pi;
	*fläche = (durchmesser * durchmesser) * pi /4;
}

void ausgabeAuswahl(const char* message)
{
    printf("%s", message);
}

float eingabe(const char* message)
{
    float wert;
    printf("%s", message);
    scanf("%f", &wert);

    return wert;
}
