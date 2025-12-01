/*
Postfix und präfix zu überladen
*/

#include <iostream>

using namespace std;

int main()
{

}


//#include <iostream>
//
//using namespace std;
//
//template<typename T>
//
//bool isEqual(T x, int y)
//
//{
//
//    cout << "template" << endl;
//
//    return (x == y);
//
//}
//
//template<typename T>
//
//bool isEqual(int x, T y)
//
//{
//
//    cout << "template" << endl;
//
//    return (x == y);
//
//}
//
////template<>
//
////bool isEqual(const char* x, const char* y)
//
////{
//
////    cout << "normal" << endl;
//
////    return strcmp(x,y);
//
////}
//
//
//
//
//int main()
//
//{
//
//    isEqual(5.5, 6);
//
//    /*isEqual("Hello", "Hi");*/
//
//
//
//}
//
//
//#include <iostream>
//using namespace std;
//
//template<typename T>
//void print(T x)
//{
//    cout << x << endl;
//}
//
//template<typename T, typename T1>
//void max(T x, T1 y) {
//    if (sizeof(T) > sizeof(T1))
//        cout << "size of x is bigger" << endl;
//    else
//        cout << "size of y is bigger" << endl;
//}
//
//int main()
//{
//    //print(5);
//    max(5.5, 5);
//}

//#include <iostream>
//using namespace std;
//
//class Myclass {
//
//    friend Myclass operator+(Myclass obj, Myclass obj1);
//    friend Myclass operator*(int m, Myclass obj1);
//
//
//private:
//    int x;
//    void add(int value)
//    {
//        x += value;
//    }
//
//public:
//    Myclass(int value) :x(value) {}
//    void print()
//    {
//        cout << x << endl;
//    }
//
//    //Myclass operator+(Myclass& obj) {
//    //    Myclass obj1(x + obj.x);
//    //    return obj1;
//    //}
//};
//
//Myclass operator+(Myclass obj, Myclass obj1)
//{
//    int x = obj.x + obj1.x;
//    Myclass obj2(x);
//    return obj2;
//}
//
//Myclass operator*(int m, Myclass obj1)
//{
//    Myclass obj2(m * obj1.x);
//    return obj2;
//}
//
//
//
//int main()
//{
//    Myclass obj(10);
//    Myclass obj2(20);
//
//    Myclass obj3 = obj + obj2;
//
//    Myclass obj4 = 2 * obj3;
//    obj.print();
//}