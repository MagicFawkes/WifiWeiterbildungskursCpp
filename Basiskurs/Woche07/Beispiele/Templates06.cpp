#include <iostream>

// 1) Vorwärtsdeklaration der Klassentemplate
// -----------------------------------------
// Hier sagst du dem Compiler erstmal nur:
// "Es gibt eine Template-Klasse TemplateNumber mit Typparameter T."
template<typename T>
class TemplateNumber;

// 2) Vorwärtsdeklaration der Funktions-TEMPLATE operator+
// -------------------------------------------------------
// Hier deklarierst du die freie (nicht zur Klasse gehörende) Funktion als TEMPLATE.
// Wichtig: Überall außerhalb der Klasse musst du TemplateNumber<T> mit <T> schreiben.
template<typename T>
TemplateNumber<T> operator+(TemplateNumber<T> obj1, TemplateNumber<T> obj2);
//           ^^^              ^^^^^^^^^^^^^^^^         ^^^^^^^^^^^^^^^^
//           |                 hier jeweils mit <T>    hier auch


// 3) Definition der Klassentemplate
// ---------------------------------
template<typename T>
class TemplateNumber
{
    // 3a) Friend-Deklaration des Funktions-TEMPLATES
    // ----------------------------------------------
    // Das hier ist der knifflige Teil:
    //
    // - TemplateNumber<T> : Rückgabetyp, mit <T>, weil die Klasse ein Template ist.
    //   (Man KÖNNTE hier auch nur TemplateNumber schreiben, siehe Kommentar unten.)
    //
    // - operator+ <> : Das <> sagt dem Compiler:
    //   "Ich meine genau DIE Funktions-TEMPLATE 'operator+' von oben."
    //
    // - Die Parameter sind TemplateNumber<T>, also die gleiche Spezialisierung.
    //
    // WICHTIG:
    // - Hier ist operator+<> korrekt.
    // - operator+<T> wäre hier FALSCH.
    friend TemplateNumber<T> operator+<>(TemplateNumber<T> obj1, TemplateNumber<T> obj2);       //Weil <> in der Friend-Deklaration dem Compiler sagt, dass es sich um genau die bereits deklarierte Funktions-Template handelt, ohne die Template-Argumente explizit anzugeben – deshalb muss man <> hinschreiben, aber leer lassen.
    //                      ^^           ^^^^^^^^^^^^^^^^           ^^^^^^^^^^^^^^^^
    //                      |            alle mit <T>
    //                      |
    //                      <> = "das ist eine Template-Funktion, nimm das T der Klasse"


public:
    // Hier sind die Member public, daher wäre friend eigentlich nicht nötig,
    // weil jede Funktion sowieso auf real und img zugreifen darf.
    // Für das Verständnis lassen wir friend aber drin.
    T real;
    T img;

public:
    TemplateNumber(T real, T img) : real(real), img(img)
    {
    }

    T getReal() const
    {
        return real;
    }

    T getImg() const
    {
        return img;
    }
};


// 4) Definition der Funktions-TEMPLATE operator+
// ----------------------------------------------
// Hier definierst du das Funktions-TEMPLATE, das oben vorwärts deklariert wurde.
// WICHTIG:
// - Hier gibt es KEIN operator+<> oder <T> hinter dem Namen.
// - Hier schreibst du ganz normal das Template so, wie immer:
template<typename T>
TemplateNumber<T> operator+(TemplateNumber<T> obj1, TemplateNumber<T> obj2)
{
    // Hier verwendest du T ganz normal, weil es der Templateparameter der Funktion ist:
    T real = obj1.getReal() + obj2.getReal();
    T img = obj1.getImg() + obj2.getImg();

    TemplateNumber<T> ob(real, img);
    return ob;
}

int main()
{
	TemplateNumber<float>z1(1, 2);
	TemplateNumber<float>z2(2, 3);
	TemplateNumber<float>z3 = z1 + z2;
}