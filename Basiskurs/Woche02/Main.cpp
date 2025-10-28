
#define AKTIVE_BEISPIEL 0
#define AKTIVE_AUFGABE 1

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
#endif