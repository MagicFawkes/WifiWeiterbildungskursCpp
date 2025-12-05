/*
Implementieren Sie ein Programm das einen Boden (Klasse Floor) von farbigen Kacheln
(Klasse Tile) solange prüft und dabei Kacheln markiert und austauscht bis nur noch Kacheln
einer bestimmten Farbe vorhanden sind.
Übersicht
• Zu Beginn des Programms wird ein neues Floor-Objekt angelegt, dabei wird das Objekt
mit einem zweidimensionalen Feld von Pointern auf Tile-Objekte
initialisiert. Implementieren Sie den Konstruktor der Klasse Floor.
• Im Konstruktor der Floor-Klasse soll der Boden zufällig mit BlueTile- und GreenTile-
Objekten befüllt werden, die beiden Klassen, als auch die RedTile Klasse, sollen von
der abstrakten Klasse Tile erben. Definieren Sie die rein virtuelle getColor- und
mark- Funktion in der Klasse Tile, führen Sie dann die Vererbung an die drei
Kindklassen durch und implementieren Sie dann deren Konstruktoren und
getColor und mark-Methoden.
• Danach werden solange zufällige Kacheln des zweidimensionalen Feldes markiert und
getauscht indem die mark- und getColor-Funktion der Kacheln durch die mark- und
replace-Funktion des Bodes aufgerufen wird, bis der Boden nur mehr aus roten Kacheln
besteht. Implementieren Sie die mark- und replace-Funktion der Floor-Klasse und
zur Prüfung, ob der Boden bereits nur noch aus roten Kacheln besteht, die isRed-
Funktion.
• Implementieren Sie auch die print-Funktion, zur Ausgabe der Bodens. Passen Sie
die display-Funktion der Klasse Tile an.
• Während der Ausführung der mark- und replace-Funktion kann es zu Exceptions
kommen, implementieren Sie dafür eine entsprechende Fehlerbehandlung in der
main-Funktion.
• Zum Schluss soll natürlich auch jeglicher Speicher korrekt freigegeben
werden, implementieren Sie dazu den Destruktor der Klasse Floor.
Aufgaben
Abstrakte Klasse Tile
Definieren Sie folgende rein virtuelle Funktionen für die abstrakte Klasse:
• getColor(): Die Funktion soll ein einzelnes Zeichen zurückgeben.
• mark(): Die Funktion soll den marked-Wert setzen.
Passen Sie die Funktion display so an das statt X die entsprechende Farbe ausgegeben wird.
Klasse RedTile
Definieren Sie die Klasse RedTile, die von Tile erben soll. Implementieren Sie folgende
Funktionen für die Klasse:
• Konstruktor(): Der marked-Wert des Objekts soll auf false gesetzt werden.
• mark(): Die Funktion setzt marked auf false.
• getColor(): Die Funktion soll das Zeichen ’R’ zurückgeben.
Klasse BlueTile
Definieren Sie die Klasse BlueTile, die von Tile erben soll. Implementieren Sie folgende
Funktionen für die Klasse:
• Konstruktor(): Der marked-Wert des Objekts soll auf false oder true gesetzt werden mit
einer 50:50 Wahrscheinlichkeit.
o Zur Berechnung der 50:50 Chance soll die Rand-Funktion verwendet
werden. rand()
• mark(): Die Funktion setzt marked auf true.
• getColor(): Die Funktion soll das Zeichen ’B’ zurückgeben.
Klasse GreenTile
Definieren Sie die Klasse GreenTile, die von Tile erben soll. Implementieren Sie folgende
Funktionen für die Klasse:
• Konstruktor(): Der marked-Wert des Objekts soll auf true gesetzt werden.
• mark(): Die Funktion setzt marked auf true.
• getColor(): Die Funktion soll das Zeichen ’G’ zurückgeben.
Klasse Floor
Die Klasse soll ein zweidimensionales Feld enthalten die aus Tile-Pointern besteht, damit dann
über Polymorphismus auf RedTile-, BlueTile- und GreenTile Objekte zugegriffen werden kann.
Implementieren Sie folgende Funktionen für die Klasse:
• Konstruktor: Der Konstruktor erstellt einen 3x3 Feld und befüllt dieses dann mit blauen
und grünen Kacheln, dabei soll mit einer 50:50 Wahrscheinlichkeit BlueTileund
GreenTile-Objekte erstellt werden.
• Destruktor: Der Destruktor gibt den Speicher, der im Konstruktor für das Feld
beansprucht wurde wieder frei.
• print(): Gibt den Boden in einem 3x3 Raster aus indem von jeder Kachel die display-
Funktion der Klasse Tile aufgerufen wird.
• mark(int x, int y): Es wird die mark-Funktion der Kachel aufgerufen, die sich an den
Koordinaten x/y des Bodens befindet.
• replace(int x, int y): Falls sich an den Koordinaten x/y des Bodens eine grüne Kachel
befindet wird sie durch eine neue blaue Kachel ersetzt. Andernfalls, falls sich an den
Koordinaten x/y des Bodens eine blaue Kachel befindet und diese markiert ist wird sie
durch eine neue rote Kachel ersetzt. Nutzen Sie die Funktionen getColor und isMarked
der von Tile vererbten Klassen.
• isRed(): Die Funktion soll prüfen ob der Boden nur noch aus RedTile-Objekte besteht
und dementsprechend true retournieren, wenn das der Fall ist, ansonsten false.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
    printf("Test");
    return 0;
}