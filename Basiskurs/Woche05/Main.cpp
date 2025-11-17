
#define AKTIVE_BEISPIEL 5
#define AKTIVE_AUFGABE 0

#if AKTIVE_BEISPIEL == 1
#include "Beispiele/EinfacherKonstruktor.cpp"
#elif AKTIVE_BEISPIEL == 2
#include "Beispiele/Kopierkonstruktor.cpp"
#elif AKTIVE_BEISPIEL == 3
#include "Beispiele/Parameterkonstruktor.cpp"
#elif AKTIVE_BEISPIEL == 4
#include "Beispiele/StudentFunktion.cpp"
#elif AKTIVE_BEISPIEL == 5
#include "Beispiele/Reiskocher.cpp"
#endif

#if AKTIVE_AUFGABE == 1
#include "Aufgaben/Aufgabe01.cpp"
#elif AKTIVE_AUFGABE == 2
#include "Aufgaben/Aufgabe02.cpp"
#endif
