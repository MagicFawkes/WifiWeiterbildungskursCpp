
#define AKTIVE_BEISPIEL 0
#define AKTIVE_AUFGABE 5

#if AKTIVE_BEISPIEL == 1
#include "Beispiele/LedUmschaltung.cpp"
#elif AKTIVE_BEISPIEL == 2
#include "Beispiele/Roboterturnier.cpp"
#elif AKTIVE_BEISPIEL == 3
#include "Beispiele/ZahlenTauschPointer.cpp"
#endif

#if AKTIVE_AUFGABE == 1
#include "Aufgaben/Aufgabe01-dyn.cpp"
#elif AKTIVE_AUFGABE == 100
#include "Aufgaben/Aufgabe01-static.cpp"
#elif AKTIVE_AUFGABE == 2
#include "Aufgaben/Aufgabe02.cpp"
#elif AKTIVE_AUFGABE == 3
#include "Aufgaben/Aufgabe03.cpp"
#elif AKTIVE_AUFGABE == 4
#include "Aufgaben/Aufgabe04.cpp"
#elif AKTIVE_AUFGABE == 5
#include "Aufgaben/Aufgabe05.cpp"
#elif AKTIVE_AUFGABE == 6
#include "Aufgaben/Aufgabe06.cpp"
#elif AKTIVE_AUFGABE == 7
#include "Aufgaben/Aufgabe07.cpp"
#endif
