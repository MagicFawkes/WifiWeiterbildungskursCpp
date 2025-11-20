/*

1 Fight Club
Implementieren Sie eine Vererbungsstruktur, die als Basis f¨ur ein textbasiertes Beat-em’-
up-Spiel dient. Charaktere sollen rundenweise gegeneinander antreten k¨onnen. Weiters soll
es m¨oglich sein, den Charakteren verschiedene F¨ahigkeiten zuzuordnen, die dann im Kampf
genutzt werden k¨onnen.
Folgende Punkte m¨ussen dabei beachtet werden:
• Nutzen Sie Vererbung und teilen Sie den Code auf.
• Verwenden Sie sinnvolle Klassen. Beachten Sie dabei die richtige Verwendung von Zugriffsmodifikatoren, Gettern/Settern, den verschiedenen Konstruktoren und Destruktoren sowie der sinnvollen Strukturierung von Funktionen und Daten. Bilden Sie Ihre
Klassen in einem entsprechenden Diagramm ab.
• Uberpr¨ufen Sie alle Parameter¨ubergaben an Funktionen und Benutzereingaben auf ¨
Fehler und verhindern Sie so, dass Ihr Programm bei ung¨ultigen Eingaben nicht mehr
richtig funktioniert, Eingaben sollen so lange wiederholt werden, bis sie korrekt sind
und der Spielfluss erst dann fortgesetzt werden.
• Testen Sie Ihren Code ausgiebig und ber¨ucksichtigen Sie Randbedingungen.
Stufe 1
Zu Beginn soll es m¨oglich sein, aus zumindest zwei vorgefertigten Charakteren zu w¨ahlen oder
einen eigenen Charakter zu erstellen, jeder Charakter soll dabei zwei F¨ahigkeiten besitzen.
Die F¨ahigkeiten sollen bei der Charaktererstellung gew¨ahlt werden k¨onnen, implementieren
Sie also mehr als zwei F¨ahigkeiten.
Wurden zwei Charaktere gew¨ahlt, sollen diese danach rundenweise unter Verwendung ihrer
F¨ahigkeiten gegeneinander k¨ampfen. Der Kampf soll so lange andauern, bis einer der Charaktere besiegt wurde.
Gestalten Sie die Regeln f¨ur den Kampf selbst.
Nach einem Kampf soll es m¨oglich sein, wieder neue Charaktere zu w¨ahlen oder zu erstellen
und diese gegeneinander antreten zu lassen.
Weiters soll es eine M¨oglichkeit geben, sich die Anzahl der Siege und Niederlagen aller
Charaktere anzusehen.
Stufe 2
Erm¨oglichen Sie es Personen, gegen den Computer oder gegeneinander anzutreten und auch
Teams zu bilden, die als Klassen implementiert werden. Teams sollen aus mehreren Charakteren bestehen und dann in Team-K¨ampfen gegeneinander antreten k¨onnen. Gestalten Sie
auch hier die Regeln selbstst¨andig.
Stufe 3
Erweitern Sie Ihr Spiel um zumindest zwei Entscheidungsb¨aume als Klassen implementiert,
die den Charakteren bei der Erstellung zugeordnet werden k¨onnen. Diese B¨aume sollen das
Verhalten der Charaktere im Kampf ver¨andern und sich deutlich voneinander unterscheiden.
Bewertung
Aspekt Bewertung
Vererbung/Klassen 20%
Diagramm 10%
Fehlerpr¨ufung 10%
Stufe 1 30%
Stufe 2 15%
Stufe 3 15%
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
    printf("Test");
    return 0;
}