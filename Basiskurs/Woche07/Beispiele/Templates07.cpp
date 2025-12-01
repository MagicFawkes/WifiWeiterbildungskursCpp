/*
 *
 *
 */

#include <iostream>

using namespace std;

template<typename T, int N>
class Array {
private:
	T a[N];
public:
	~Array() {}
};

template<>
class Array<const char*, 10>
{
private:
	const char* a[10];
public:
	~Array()
	{

	}

};


int main() {


}