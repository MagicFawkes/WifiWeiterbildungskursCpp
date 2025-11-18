/*

*/

#include <iostream>
using namespace std;

class complexnumber {
public:
    float real;
    float img;

    complexnumber(float real, float img) {
        this->real = real;
        this->img = img;
    }

    complexnumber operator+(const complexnumber& c) const {
        return complexnumber(real + c.real, img + c.img);
    }
};

int main() {
    complexnumber z1(1.0f, 1.0f);
    complexnumber z2(0.0f, 1.0f);

    complexnumber z3 = z1 + z2;

    cout << z3.real << endl; // Ausgabe: 1
    return 0;
}
