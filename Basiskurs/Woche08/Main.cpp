
#define AKTIVE_BEISPIEL 7
#define AKTIVE_AUFGABE 0

#if AKTIVE_BEISPIEL == 1
#include "Beispiele/Exception01.cpp"
#elif AKTIVE_BEISPIEL == 2
#include "Beispiele/Exception02.cpp"
#elif AKTIVE_BEISPIEL == 3
#include "Beispiele/BinaereSuche01.cpp"
#elif AKTIVE_BEISPIEL == 4
#include "Beispiele/Linearesearch.cpp"
#elif AKTIVE_BEISPIEL == 5
#include "Beispiele/Bubblesort.cpp"
#elif AKTIVE_BEISPIEL == 6
#include "Beispiele/SelectionSort.cpp"
#elif AKTIVE_BEISPIEL == 7
#include "Beispiele/InsertionSort.cpp"
#endif

#if AKTIVE_AUFGABE == 1
#include "Aufgaben/Aufgabe01.cpp"
#elif AKTIVE_AUFGABE == 2
#include "Aufgaben/Aufgabe02.cpp"
#endif
