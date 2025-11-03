
#define AKTIVE_BEISPIEL 5
#define AKTIVE_AUFGABE 0

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
#endif

#if AKTIVE_AUFGABE == 1
#include "Aufgaben/Aufgabe01.cpp"
#elif AKTIVE_AUFGABE == 2
#include "Aufgaben/Aufgabe02.cpp"
#endif
