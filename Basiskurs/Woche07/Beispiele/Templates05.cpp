#include <iostream>

/*
friend erlaubt einer externen Funktion, Methode oder Klasse den Zugriff auf die 
privaten und geschützten Member einer Klasse.Der häufigste Einsatz ist, Operatoren 
oder spezielle Funktionen Zugriff zu geben, ohne sie zu Mitgliedern der Klasse zu machen.
Man kann aber auch ganze Klassen oder einzelne Methoden befreunden, z.B.für enge 
Zusammenarbeit oder Fabrikfunktionen.Insgesamt dient friend dazu, Encapsulation 
gezielt und kontrolliert aufzubrechen – nicht nur bei Templates, sondern in allen C++ - Klassen.
Der einzige Zweck von friend ist es, privaten/protected Zugriff für bestimmte externe Funktionen oder Klassen zu ermöglichen.
*/

using namespace std;

template<typename T>
class ComplexNumber
{
    friend ComplexNumber<T> operator+<>(const ComplexNumber<T> z1, const ComplexNumber<T> z2);

private:
    T real;
    T img;

// Ohne Private also mit Public ist friend nicht notwendig: 
// friend hat hier die Funktion, dem freien Operator operator+ Zugriff auf die privaten Member (real und img) der Klasse ComplexNumber zu geben.
//public:
//    T real;
//    T img;

public:
    ComplexNumber(T real, T img) : real(real), img(img)
    {
    }

    void print()
    {
        cout << real << endl;
        cout << img << endl;
    }
};

//Überladung als Template machen
template<typename T>
ComplexNumber<T> operator+(const ComplexNumber<T> z1, const ComplexNumber<T> z2)
{
    return ComplexNumber<T>(z1.real + z2.real, z1.img + z2.img);
}

int main()
{
    ComplexNumber<float> z1(1, 2);
    ComplexNumber<float> z2(3, 2);
    ComplexNumber<float> z3 = z1 + z2;

    z3.print();
}


/*
#include <iostream>

using namespace std;

template<typename T>
class ComplexNum;

template<typename T>
ComplexNum<T> operator-(const ComplexNum<T>& A, const ComplexNum<T>& B);

template<typename T>
ComplexNum<T> operator+(const ComplexNum<T>& A, const ComplexNum<T>& B);

template<typename T>
class ComplexNum {
    T Image;
    T Real;

    friend ComplexNum<T> operator+<>(const ComplexNum<T>& A, const ComplexNum<T>& B);
    friend ComplexNum<T> operator-<>(const ComplexNum<T>& A, const ComplexNum<T>& B);

public:
    ComplexNum(T R = 0, T I = 0) : Real(R), Image(I) {}
    ~ComplexNum() = default;

    void Display() const {
        cout << "Real: " << Real << "\n"
            << "Imaginär: " << Image << "\n\n";
    }
};

template<typename T>
ComplexNum<T> operator+(const ComplexNum<T>& A, const ComplexNum<T>& B) {
    ComplexNum<T> ob(A.Real + B.Real, A.Image + B.Image);
    return ob;
}

template<typename T>
ComplexNum<T> operator-(const ComplexNum<T>& A, const ComplexNum<T>& B) {
    ComplexNum<T> ob(A.Real - B.Rea

*/