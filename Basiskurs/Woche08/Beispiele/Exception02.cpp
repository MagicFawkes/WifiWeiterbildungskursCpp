/*

*/

#include <iostream>
#include <string>

using namespace std;

class divnull_exception : public exception
{
public:
	const char* what() const noexcept
	{
		return "Division durch 0";
	}	
};

class zahlzugross_exception : public exception
{
public:
	const char* what() const noexcept
	{
		return "Zahl groesser 100";
	}
};

class istkeinezahl_exception: public exception
{
private:
	string i;
public:
	istkeinezahl_exception(const std::string& i)
		: i("Eingabewert ist keine Zahl: " + i)
	{
	}

	const char* what() const noexcept override
	{
		return i.c_str();
	}
};

bool istZahl(const string& s);

int main()
{
	string i;
	string u;

	cout << "Bitte Zahl 1 eingebebn: ";
	cin >> i;

	cout << "Bitte Zahl 2 eingebebn: ";
	cin >> u;
	
	try
	{
		if (!istZahl(i))
		{
			throw istkeinezahl_exception(i);
		}

		if (!istZahl(u))
		{
			throw istkeinezahl_exception(u);
		}

		int zahl1 = std::stoi(i);
		std::cout << "Zahl1 = " << zahl1 << std::endl;

		int zahl2 = std::stoi(u);
		std::cout << "Zahl2 = " << zahl2 << std::endl;

		if (zahl1 > 100 || zahl2 > 100)
		{
			throw zahlzugross_exception();
		}
	}
	catch (istkeinezahl_exception& e)
	{
		cout << "Exception aufgetreten: " << e.what();
	}
	catch (zahlzugross_exception& e)
	{
		cout << "Exception aufgetreten: " << e.what();
	}
	catch (divnull_exception& e)	
	{
		cout << "Exception aufgetreten: " << e.what();
	}
	catch (exception& e)
	{
		cout << "Exception aufgetreten: " << e.what();
	}
	catch (...)
	{
		cout << "allgemeiner Fehler";
	}
}

bool istZahl(const string& s)
{
	if (s.empty()) 
		return false;

	size_t i = 0;

	for (; i < s.length(); i++)
		if (!std::isdigit(s[i]))
			return false;

	return true;
}
