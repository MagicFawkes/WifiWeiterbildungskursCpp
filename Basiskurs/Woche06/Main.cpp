
#define AKTIVE_BEISPIEL 4
#define AKTIVE_AUFGABE 0

#if AKTIVE_BEISPIEL == 1
#include "Beispiele/VerketteteListenCStyle.cpp"
#elif AKTIVE_BEISPIEL == 2
#include "Beispiele/VerketteteListenCppStyle.cpp"
#elif AKTIVE_BEISPIEL == 3
#include "Beispiele/StackPopPush.cpp"
#elif AKTIVE_BEISPIEL == 4
#include "Beispiele/StackPopPushList.cpp"
#endif

#if AKTIVE_AUFGABE == 1
#include "Aufgaben/Aufgabe01.cpp"
#elif AKTIVE_AUFGABE == 2
#include "Aufgaben/Aufgabe02.cpp"
#endif
