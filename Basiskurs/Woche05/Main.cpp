
#define AKTIVE_BEISPIEL 0
#define AKTIVE_AUFGABE 2

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
#elif AKTIVE_BEISPIEL == 6
#include "Beispiele/AbstrakteKlassen.cpp"
#elif AKTIVE_BEISPIEL == 7
#include "Beispiele/SensorAbstrakteKlassen.cpp"
#elif AKTIVE_BEISPIEL == 8
#include "Beispiele/UniquePointer.cpp"
#elif AKTIVE_BEISPIEL == 9
#include "Beispiele/StaticMethoden.cpp"
#elif AKTIVE_BEISPIEL == 10
#include "Beispiele/BibliothekVerwaltung.cpp"
#elif AKTIVE_BEISPIEL == 11
#include "Beispiele/OperatorOverloading.cpp"
#elif AKTIVE_BEISPIEL == 12
#include "Beispiele/Textverwaltungssystem.cpp"
#endif

#if AKTIVE_AUFGABE == 1
#include "Aufgaben/AufgabeUno.cpp"
#elif AKTIVE_AUFGABE == 2
#include "Aufgaben/Fightclub.cpp"
#elif AKTIVE_AUFGABE == 3
#include "Aufgaben/Medienverwaltung.cpp"
#endif
