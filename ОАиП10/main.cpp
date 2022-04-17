
#include <iostream>
#include <stdexcept>

bool IsNatural(int number)
{
	return number >= 1;
}

int ToBase(int p, int number)
{
	const int MIN_BASE = 2;
	const int MAX_BASE = 9;

	if (p < MIN_BASE || p > MAX_BASE)
	{
		throw std::invalid_argument("Argument p was out of range");
	}
	if (IsNatural(number) == false)
	{
		throw std::invalid_argument("Received number wasn't natural");
	}

	int quotient = static_cast<int>(number / p);
	if (quotient != 0)
	{
		return 10 * ToBase(p, quotient) + (number % p);
	}
	else
	{
		return number % p;
	}
}

int main()
{
	try
	{
		std::cout << "Number (in base 10) = ";
		int number = 0;
		std::cin >> number;

		std::cout << "p = ";
		int base = 0;
		std::cin >> base;

		std::cout << std::endl << "Number (in base " << base << "): " 
				<< ToBase(base, number) << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
