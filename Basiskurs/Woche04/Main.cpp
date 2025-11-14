
#define AKTIVE_BEISPIEL 0
#define AKTIVE_AUFGABE 4

#if AKTIVE_BEISPIEL == 1
#include "Beispiele/GrossbuchstabenAuswerten.cpp"
#elif AKTIVE_BEISPIEL == 2
#include "Beispiele/RepeatStringFunktion.cpp"
#elif AKTIVE_BEISPIEL == 3
#include "Beispiele/GreaterVektorFunktion.cpp"
#elif AKTIVE_BEISPIEL == 4
#include "Beispiele/VektorVerschieben.cpp"
#elif AKTIVE_BEISPIEL == 5
#include "Beispiele/NamspacesExamples.cpp"
#elif AKTIVE_BEISPIEL == 6
#include "Beispiele/CustomRealloc.cpp"
#elif AKTIVE_BEISPIEL == 7
#include "Beispiele/StrukturRoboter.cpp"
#elif AKTIVE_BEISPIEL == 8
#include "Beispiele/DatenstrukturVerknüpfung.cpp"+
#elif AKTIVE_BEISPIEL == 9
#include "Beispiele/WortZensierung.cpp"
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
