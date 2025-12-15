
#define AKTIVE_BEISPIEL 11
#define AKTIVE_AUFGABE 0

#if AKTIVE_BEISPIEL == 1
#include "Beispiele/Funktionspointer01.cpp"
#elif AKTIVE_BEISPIEL == 2
#include "Beispiele/Funktionspointer02.cpp"
#elif AKTIVE_BEISPIEL == 3
#include "Beispiele/Lambda01.cpp"
#elif AKTIVE_BEISPIEL == 4
#include "Beispiele/LambdaQuadrieren.cpp"
#elif AKTIVE_BEISPIEL == 5
#include "Beispiele/FunktionspointerQuadrieren.cpp"
#elif AKTIVE_BEISPIEL == 6
#include "Beispiele/Functor01.cpp"
#elif AKTIVE_BEISPIEL == 7 
#include "Beispiele/Functor02.cpp"
#elif AKTIVE_BEISPIEL == 8
#include "Beispiele/RemoveIfSortTransform.cpp"
#elif AKTIVE_BEISPIEL == 9
#include "Beispiele/RemoveIfSortTransformFunctor.cpp"
#elif AKTIVE_BEISPIEL == 10
#include "Beispiele/FunctorMitTemplates.cpp"
#elif AKTIVE_BEISPIEL == 11
#include "Beispiele/Functor03.cpp"
#endif

#if AKTIVE_AUFGABE == 1
#include "Aufgaben/Aufgabe01.cpp"
#elif AKTIVE_AUFGABE == 2
#include "Aufgaben/Aufgabe02.cpp"
#endif
