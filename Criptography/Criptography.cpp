// Criptography.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include "CongruenceClass.h"
#include "LongInteger.h"

int EasyGcd(int first_number, int second_number) {
	int auxiliar = 0;
	while (second_number != 0)
	{
		auxiliar = second_number;
		second_number = first_number % second_number;
		first_number = auxiliar;
	}
	return first_number;
}

LongInteger Gcd(LongInteger first_number, LongInteger second_number)
{
	while (!(first_number == second_number))
	{
		if (first_number > second_number)
		{
			first_number = first_number - second_number;
		}
		else
		{
			second_number = second_number - first_number;
		}
	}
	return first_number;
}

std::string cEZar_cypher(std::string sentence, char shift)
{
	CongruenceClass x(26);
	CongruenceClass n(shift - 'A' + 1, 26);
	char one_letter;
	int length = sentence.length();
	for (int i = 0; i < length; i++)
	{
		one_letter = sentence[i];
		if (one_letter == ' ')
		{
			continue;
		}
		x = one_letter - 'A';
		x = x - n;
		sentence[i] = 'A' + x.GetValue();
	}
	return sentence;
}

std::string cEZar_decypher(std::string sentence, char shift)
{
	shift = 2 * 'A' - shift - 2;
	return cEZar_cypher(sentence, shift);
}

int* int_to_bits(int power) {
	int length = ceil(log2(power));
	if (ceil(log2(power) == log2(power)))
	{
		length++;
	}
	int* result = new int[length];
	for (int i = 0; i < length; i++)
	{
		result[i] = power % 2;
		power = power / 2;
	}
	return result;
}

double ruski(double number, int power) {
	int z = 1;
	int l = floor(log2(power));
	int* bits = nullptr;
	if (power == 0)
	{
		return 0;
	}
	if (power < 0)
	{
		power = -power;
		number = 1 / number;
	}
	if (power >= 1)
	{
		bits = int_to_bits(power);
	}
	for (int i = l; i >= 0; i--)
	{
		z = (z*z);
		if (bits[i] == 1)
		{
			z = (int)(z * number);
		}
	}
	return z;
}

int pollard(int n)
{
	int a = 2;
	int b = 2;
	int d = 1;
	while (d == 1)
	{
		a = a * a - 1;
		a %= n;
		b = (b*b - 1)*(b*b - 1) - 1;
		b %= n;
		d = EasyGcd(abs(a - b), n);
	}
	if (d == n)
	{
		return -1;
	}
	else
	{
		return d;
	}
}

void pollard_wrapp(int n)
{
	int result = pollard(n);
	if (result == -1)
	{
		std::cout << "Nu se poate factoriza" << std::endl;
	}
	else
	{
		std::cout << "Stiati ca " << n << " = " << result << " * " << n / result << "?" << std::endl;
	}
}

bool pratt(int n)
{
	if (n == 2)
	{
		return false;
	}
	if (n == 3)
	{
		return false;
	}
	for (int x = 1; x < n; x++)
	{
		if ((int)ruski(x, n - 1) % n == 1)
		{

		}
	}
	return false;
}

int miller_rabin(int n)
{
	//pasul 1
	if (n % 2 == 1) 
	{
		std::cout << "Numarul " << n << " este compus" << std::endl;
		return 0;
	}
	//pasul 2
	int l = 0;
	int m = n - 1;
	//pasul 3
	do
	{
		l = l + 1;
		m = m / 2;
	} while (m % 2 == 0); //pasul 4
	//pasul 5
	int j = 0;
	int x = 0;
	//pasul 6
	do
	{
		if (j < l)
		{
			j++;
			x = 2;
		}
		else
		{
			std::cout << "Numarul " << n << " este probabil prim" << std::endl;
			return 1;
		}
	} while ((int)ruski(x, m) % n == 1 || EasyGcd(x,n));
	//pasul 7
	if (1<EasyGcd(x,n)<n)
	{
		return 0;
		std::cout << "Numarul " << n << " este compus" << std::endl;
	}
	//pasul 8
	int i = 0;
	//pasul 9
	if ((int)ruski(x, 2 * i*m) % n == n - 1)
	{
		std::cout << "Numarul " << n << " este compus" << std::endl;
	}
	else
	{

	}
}

int main()
{
	std::string inmultire = LongInteger::KaratsubaMultiply("1495", "876");
	LongInteger _a("213");
	LongInteger _b("450");
	_a = _b * _a;
	std::string chipher = "THE CHRISS BROWN FOX JUMPS OVER THE SNOOP DOG";
	chipher = cEZar_cypher(chipher, 'F');
	chipher = cEZar_decypher(chipher, 'F');
	int pow2_10 = ruski(2, 10);
	std::string fake_a;
	std::string fake_b;
	while (1)
	{
		std::cout << "Serviti a: ";
		std::cin >> fake_a;
		std::cout << "Serviti b: ";
		std::cin >> fake_b;
		LongInteger a(fake_a);
		LongInteger b(fake_b);
		std::cout << "Floor a/b: " << LongInteger::ActualFractionFloor(a, b) << std::endl;
	}

	//pollard_wrapp(10403);

	return 0;
}

