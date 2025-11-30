/*
Aufgabe 4:
Implementiere eine Queue (FIFO) mit zwei Stacks.
Anforderungen:
1. Implementiere eine Klasse Stack
2. Die Queue KLASSE muss die Standardoperationen unterstützen:
• enqueue(x): fügt das Element x am Ende der Queue hinzu
• dequeue(): entfernt das erste Element der Queue und gibt es zurück
• front(): gibt das erste Element zurück, ohne es zu entfernen
• empty(): prüft, ob die Queue leer ist
Ziel:
• Die Operationen sollen so effizient wie möglich sein.
Hinweis:
• Ein Stack arbeitet nach dem LIFO-Prinzip (Last In, First Out).
• Eine Queue arbeitet nach dem FIFO-Prinzip (First In, First Out).
• Überlege, wie du durch das Verschieben von Elementen zwischen den beiden Stacks
das FIFO-Verhalten einer Queue nachbilden kannst.
Kleine Hilfe:
class Stack {
Code
};
Class Queue{
private:
Stack stack_in;
Stack stack_out;
public:
Code
};
*/

#include <stdio.h>

class Stack
{
public:
    void enqueue(int x)
    {
	    
    }
    void dequeue()
    {

    }
    void front()
    {
	    
    }
    void empty()
    {
	    
    }
};

class Queue 
{
private:
    Stack stack_in;
    Stack stack_out;
public:

};
int main()
{
    printf("Test");
    return 0;
}