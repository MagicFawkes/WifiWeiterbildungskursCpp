
#define AKTIVE_BEISPIEL 0
#define AKTIVE_AUFGABE 3

#if AKTIVE_BEISPIEL == 1
#include "Beispiele/DynSpeicherallozierung.cpp"
#elif AKTIVE_BEISPIEL == 2
#include "Beispiele/AsciiZeichenErmittellnOld.cpp"
#elif AKTIVE_BEISPIEL == 3
#include "Beispiele/AsciiZeichenErmittelln.cpp"
#elif AKTIVE_BEISPIEL == 4
#include "Beispiele/VermutungLieblingsfrucht.cpp"
#elif AKTIVE_BEISPIEL == 5
#include "Beispiele/StringLaengeErmitteln.cpp"
#elif AKTIVE_BEISPIEL == 6
#include "Beispiele/Palidrom.cpp"
#elif AKTIVE_BEISPIEL == 7
#include "Beispiele/GrossInKleinbuchstaben.cpp"
#elif AKTIVE_BEISPIEL == 8
#include "Beispiele/FileZahlenEinlesenArray.cpp"
#elif AKTIVE_BEISPIEL == 9
#include "Beispiele/FileEinlesenUndKlonen.cpp"
#elif AKTIVE_BEISPIEL == 10
#include "Beispiele/FileStringsEinlesenInArraySpeichern.cpp"
#elif AKTIVE_BEISPIEL == 11
#include "Beispiele/ZufallszahlenInArray.cpp"
#endif

#if AKTIVE_AUFGABE == 1
#include "Aufgaben/Aufgabe01.cpp"
#elif AKTIVE_AUFGABE == 2
#include "Aufgaben/Aufgabe02.cpp"
#elif AKTIVE_AUFGABE == 3
#include "Aufgaben/Aufgabe03.cpp"
#elif AKTIVE_AUFGABE == 4
#include "Aufgaben/Aufgabe04.cpp"
#endif
