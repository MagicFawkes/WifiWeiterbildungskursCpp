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

    friend ComplexNum<T> operator+ <> (const ComplexNum<T>& A, const ComplexNum<T>& B);
    friend ComplexNum<T> operator- <> (const ComplexNum<T>& A, const ComplexNum<T>& B);
public:

    ComplexNum(T R = 0, T I = 0) :Real(R), Image(I) {}
    ~ComplexNum() = default;


    void Display() const {
        cout << "Real: " << Real << "\n" << "Imaginär: " << Image << "\n\n";
    }
};

template<typename T>
ComplexNum<T> operator+(const ComplexNum<T>& A, const ComplexNum<T>& B) {
    ComplexNum<T> ob(A.Real + B.Real, A.Image + B.Image);
    return ob;
}

template<typename T>
ComplexNum<T> operator-(const ComplexNum<T>& A, const ComplexNum<T>& B) {
    ComplexNum<T> ob(A.Real - B.Real, A.Image - B.Image);
    return ob;
}

int main() {

    ComplexNum<int> I1(2, 6);
    ComplexNum<int> I2(5, 9);

    auto Result = I1 + I2;
    Result.Display();

    ComplexNum<double> D1(2.54, 6.22);
    ComplexNum<double> D2(5.09, 9.44);

    auto Result2 = D1 - D2;
    Result2.Display();

}