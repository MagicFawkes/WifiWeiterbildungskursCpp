
#define AKTIVE_BEISPIEL 2
#define AKTIVE_AUFGABE 0

#if AKTIVE_BEISPIEL == 1
#include "Beispiele/Funktionspointer01.cpp"
#elif AKTIVE_BEISPIEL == 2
#include "Beispiele/Funktionspointer02.cpp"
#elif AKTIVE_BEISPIEL == 2
#include "Beispiele/Exception02.cpp"
#endif

#if AKTIVE_AUFGABE == 1
#include "Aufgaben/Aufgabe01.cpp"
#elif AKTIVE_AUFGABE == 2
#include "Aufgaben/Aufgabe02.cpp"
#endif
