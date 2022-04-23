#include <iostream>
#include <iomanip>
#include <complex>
#include <numeric>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace Numeric_lib;

void sqrtPrint();

int main()
{
	//1------------------------------------------
	std::cout << "SIZEOF:\n"
		<< "char: " << sizeof(char) << std::endl
		<< "short: " << sizeof(short) << std::endl
		<< "int: " << sizeof(int) << std::endl
		<< "long: " << sizeof(long) << std::endl
		<< "float: " << sizeof(float) << std::endl
		<< "double: " << sizeof(double) << std::endl
		<< "int*: " << sizeof(int*) << std::endl
		<< "double*: " << sizeof(double*) << std::endl;

	//2------------------------------------------
	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int, 2> d(10, 10);
	Matrix<int, 3> e(10, 10, 10);

	std::cout << "\nMATRIX SIZEOF:\n"
		<< "Matrix<int>(10): " << sizeof(a) << std::endl
		<< "Matrix<int>(100): " << sizeof(b) << std::endl
		<< "Matrix<double>(10): " << sizeof(c) << std::endl
		<< "Matrix<int, 2>(10, 10): " << sizeof(d) << std::endl
		<< "Matrix<int, 3>(10,10,10): " << sizeof(e) << std::endl;

	//3------------------------------------------
	std::cout << "\nMATRIX ELEMENTS:\n"
		<< "Matrix<int>(10): " << a.size() << std::endl
		<< "Matrix<int>(100): " << b.size() << std::endl
		<< "Matrix<double>(10): " << c.size() << std::endl
		<< "Matrix<int, 2>(10, 10): " << d.size() << std::endl
		<< "Matrix<int, 3>(10, 10, 10): " << e.size() << std::endl;

	//4------------------------------------------
	std::cout << "\nEnter 3 ints for square rooting:\n";
	for (int i = 0; i < 3; ++i)
		sqrtPrint();

	//5------------------------------------------
	std::cout << "Enter 10 floats:\n";
	const int elem = 10;
	Matrix<double> md(elem);
	for (int i = 0; i < elem; ++i)
		std::cin >> md[i];

	//6------------------------------------------
	std::cout << "\nEnter m and n: ";
	int m, n;
	std::cin >> m >> n;
	std::cout << std::endl;

	Matrix<double, 2> multTable(m, n);

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			multTable(i, j) = i == 0 || j == 0 ? i + j : i * j;

	for (int i = 0; i < multTable.dim1(); ++i)
	{
		for (int j = 0; j < multTable.dim2(); ++j)
			std::cout << std::setw(5) << multTable(i, j);
		std::cout << std::endl;
	}

	//7------------------------------------------
	std::cout << "\nEnter 10 complex numbers:\n";
	Matrix<std::complex<double>> mcd(10);
	for (int i = 0; i < mcd.size(); ++i)
		std::cin >> mcd[i];

	std::cout << "SUM:\n"
		<< std::accumulate(mcd.data(), mcd.data() + mcd.size(), std::complex<double>{})
		<< std::endl;

	//8------------------------------------------
	std::cout << "\nEnter  6 ints for 2x3 matrix:\n";
	Matrix<int, 2> nm(2, 3);
	for (int i = 0; i < nm.dim1(); ++i)
		for (int j = 0; j < nm.dim2(); ++j)
			std::cin >> nm[i][j];

	std::cout << nm << std::endl;


	std::cin.get();
}

void sqrtPrint()
{
	int num = 0;
	std::cin >> num;
	if (num < 0)
		std::cout << "no square root\n";
	else
		std::cout << sqrt(num) << std::endl;
	//std::cin.get();
}