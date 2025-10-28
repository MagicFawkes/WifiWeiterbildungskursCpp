
#define AKTIVE_BEISPIEL 0
#define AKTIVE_AUFGABE 1

#if AKTIVE_BEISPIEL == 1
#include "Beispiele/Beispiel01.cpp"
#elif AKTIVE_BEISPIEL == 2
#include "Beispiele/Beispiel02.cpp"
#endif

#if AKTIVE_AUFGABE == 1
#include "Aufgaben/Aufgabe01.cpp"
#elif AKTIVE_AUFGABE == 2
#include "Aufgaben/Aufgabe02.cpp"
#endif
