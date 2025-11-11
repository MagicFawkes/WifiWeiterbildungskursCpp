/*
Namespace Beispiele
*/

#include <iostream>

struct ExampleStruct
{
    float a= 5.23f;
    float b = 6.23f;
};

namespace math1
{
    using namespace std;

    void Add(int a, int b)
	{
        cout << "Value inside namespace example: " << a + b << endl;
    }
}

namespace math2
{
    void Add(float a, float b)
    {
        std::cout << "Value inside namespace example: " << a + b << std::endl;
    }
}

namespace math3
{
    void Add(struct ExampleStruct scruct)
    {
        std::cout << "Value inside namespace example: " << scruct.a + scruct.b << std::endl;
    }
}

int main()
{
	//using namespace math1;
    //Add(4,9);

    //using namespace math2;
    //Add(25.23f,92.f);

	using namespace math3;
    struct ExampleStruct example;
    Add(example);

	return 0;
}