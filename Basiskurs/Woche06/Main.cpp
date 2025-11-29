
#define AKTIVE_BEISPIEL 0
#define AKTIVE_AUFGABE 2

#if AKTIVE_BEISPIEL == 1
#include "Beispiele/VerketteteListenCStyle.cpp"
#elif AKTIVE_BEISPIEL == 2
#include "Beispiele/VerketteteListenCppStyle.cpp"
#elif AKTIVE_BEISPIEL == 3
#include "Beispiele/StackPopPush.cpp"
#elif AKTIVE_BEISPIEL == 4
#include "Beispiele/StackPopPushStruct.cpp"
#elif AKTIVE_BEISPIEL == 5
#include "Beispiele/StackPopPushStructV2.cpp"
#elif AKTIVE_BEISPIEL == 6
#include "Beispiele/QueueMitArray.cpp"
#elif AKTIVE_BEISPIEL == 7
#include "Beispiele/QueueMitKlasse.cpp"
#elif AKTIVE_BEISPIEL == 8
#include "Beispiele/QueueMitLinkedLists.cpp"
#elif AKTIVE_BEISPIEL == 9
#include "Beispiele/QueueMitLinkedListsV2.cpp"
#elif AKTIVE_BEISPIEL == 10
#include "Beispiele/QueueStackPalidrom.cpp"
#elif AKTIVE_BEISPIEL == 11
#include "Beispiele/QueueDrucker.cpp"
#elif AKTIVE_BEISPIEL == 12
#include "Beispiele/VerketteteListenDoppeltCStyle.cpp"
#elif AKTIVE_BEISPIEL == 13
#include "Beispiele/VerketteteListenBaum.cpp"
#elif AKTIVE_BEISPIEL == 14
#include "Beispiele/VerketteteListenDoppeltVerbinden.cpp"
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
