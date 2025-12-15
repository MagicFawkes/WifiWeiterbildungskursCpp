/*
  Funktionsobjekte sind Functoren also gleiche Bezeichnung
*/

#include <vector>
#include <algorithm>
#include <iostream>

struct print {
	template<typename T>

	void operator()(const T& value) const
	{
		std::cout << value << std::endl;
	}
};

int main()
{
	std::vector<float> a = { 1,2,3,4,5 };
	std::for_each(a.begin(), a.end(), print());
}

