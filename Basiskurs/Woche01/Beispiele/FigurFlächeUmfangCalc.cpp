
/*
================================================================================
Programm zur Berechnung von Umfang und Fl�che verschiedener geometrischer Figuren
================================================================================

Beschreibung:
Dieses Programm erm�glicht dem Benutzer die Berechnung von Umfang und Fl�che
verschiedener geometrischer Formen: Kreis, Rechteck, Dreieck und Quadrat.

Ablauf:
1. Der Benutzer wird wiederholt aufgefordert, eine Figur auszuw�hlen.
   - 1 = Kreis
   - 2 = Rechteck
   - 3 = Dreieck
   - 4 = Quadrat
   - 0 = Beenden des Programms
2. Je nach Auswahl werden die entsprechenden Eingabewerte (z. B. Seitenl�ngen,
   Durchmesser) abgefragt.
3. Die Berechnungen werden in eigenen Funktionen durchgef�hrt:
   - `kreisBerechnung()` berechnet Umfang und Fl�che eines Kreises.
   - `rechteckBerechnung()` berechnet Umfang und Fl�che eines Rechtecks.
   - `dreieckBerechnung()` berechnet Umfang und Fl�che eines rechtwinkligen Dreiecks.
   - `quadratBerechnung()` berechnet Umfang und Fl�che eines Quadrats.
4. Das Ergebnis (Umfang und Fl�che) wird anschlie�end auf der Konsole ausgegeben.
5. Der Benutzer kann beliebig viele Berechnungen durchf�hren, bis er `0` eingibt.

Besonderheiten:
- Das Programm verwendet Zeiger (`float*`), um die berechneten Werte von
  Umfang und Fl�che direkt in den aufrufenden Funktionskontext zur�ckzuschreiben.
- Die globale Variable `pi` enth�lt den N�herungswert 3.1415926 f�r Kreisberechnungen.
- Eingaben werden �ber die Funktion `eingabe()` abgefragt und als `float` zur�ckgegeben.
- Texte werden �ber `ausgabeAuswahl()` ausgegeben, um eine einheitliche Struktur zu wahren.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

const double pi = 3.1415926;

float eingabe(const char* message);
void ausgabeAuswahl(const char* message);
void kreisBerechnung(float* umfang, float* fl�che, float durchmesser);
void rechteckBerechnung(float* umfang, float* fl�che, float a, float b);
void dreieckBerechnung(float* umfang, float* fl�che, float a, float b, float c);
void quadratBerechnung(float* umfang, float* fl�che, float a);

int main()
{
    int figur;
    float umfang = 0, fl�che = 0;

    do
    {
        figur = (int)eingabe("1=Kreis, \n2=Rechteck, \n3=Dreieck, \n4=Quadraht \n0=Beenden \nBitte Figur auswaehlen:  ");

        if (figur == 1)
        {
            ausgabeAuswahl("\nKreis ausgewaehlt:");
            float durchmesser = eingabe("\nBitte Durchmesser eingeben: ");
            kreisBerechnung(&umfang, &fl�che, durchmesser);
        }
        else if (figur == 2)
        {
            ausgabeAuswahl("\nRechteck rechtwinkelig ausgewaehlt:");
            float a = eingabe("\nBitte Laenge A eingeben: ");
            float b = eingabe("Bitte Laenge B eingeben: ");
            rechteckBerechnung(&umfang, &fl�che, a , b);
        }
        else if (figur == 3)
        {
            ausgabeAuswahl("\nDreieck ausgewaehlt:");
            float a = eingabe("\nBitte Laenge A eingeben: ");
            float b = eingabe("Bitte Laenge B eingeben: ");
            float c = eingabe("Bitte Laenge C eingeben: ");
            dreieckBerechnung(&umfang, &fl�che, a, b, c);
        }
        else if (figur == 4)
        {
            ausgabeAuswahl("\nQuadrat ausgewaehlt:");
            float a = eingabe("\nBitte Laenge A eingeben: ");
            quadratBerechnung(&umfang, &fl�che, a);
        }
        else if (figur == 0)
        {
            ausgabeAuswahl("Programm Beenden\n");
		}

        if (figur == 1 || figur == 2 || figur == 3 || figur == 4)
        {
            printf("Umfang: %.2f\n", umfang);
            printf("Flaeche: %.2f\n\n", fl�che);
        }

	} while (figur != 0);

    return 0;
}

void quadratBerechnung(float* umfang, float* fl�che, float a)
{
    *umfang = 4 * a;
    *fl�che = a * a;
}

void dreieckBerechnung(float* umfang, float* fl�che, float a, float b, float c)
{
    *umfang = a + b + c;
    *fl�che = (a * b)/2;
}

void rechteckBerechnung(float* umfang, float* fl�che, float a, float b)
{
	*umfang = 2 * (a + b);
	*fl�che = a * b;
}

void kreisBerechnung(float* umfang, float* fl�che, float durchmesser)
{
    *umfang = durchmesser * pi;
	*fl�che = (durchmesser * durchmesser) * pi /4;
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
