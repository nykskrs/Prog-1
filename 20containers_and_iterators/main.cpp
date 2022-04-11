#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <list>
#include <array>
#include <string>

template<typename C>
void print(const C& c, const std::string& s = "")
{
	std::cout << s << '\t';
	for (auto& a : c)
		std::cout << a << ' ';
	std::cout << std::endl;
}

template<typename C>
void increment(C& c, int n = 1)
{
	for (auto& a : c)
		a += n;
}

//6-----------------------------
template<typename Iter1, typename Iter2>
Iter2 myCopy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	for (Iter1 p = f1; p != e1; ++p)
		*f2++ = *p;
	return f2;
}

int main()
try
{
	constexpr int size = 10;
	//1-------------------------
	int arr[size];
	for (int i = 0; i < size; ++i)
		arr[i] = i;
	print(arr, "built in array[]: ");

	std::array<int, size> std_arr;
	for (int i = 0; i < size; ++i)
		std_arr[i] = i;
	print(std_arr, "std::array<int>: ");

	//2-------------------------
	std::vector<int> v;
	for (int i = 0; i < size; ++i)
		v.push_back(i);
	print(v, "std::vector<int>: ");

	//3-------------------------
	std::list<int> li;
	for (int i = 0; i < size; ++i)
		li.push_back(i);
	print(li, "std::list<int>: ");

	std::cout << std::endl;

	//4--------------------------
	std::array<int, size> arr2 = std_arr;
	std::vector<int> v2 = v;
	std::list<int> li2 = li;
	print(arr2, "std::array<int>: ");
	print(v2, "std::vector<int>: ");
	print(li2, "std::list<int>: ");

	std::cout << std::endl;

	//5--------------------------
	increment(arr2, 2);
	increment(v2, 3);
	increment(li2, 5);
	print(arr2, "array + 2");
	print(v2, "vector + 3");
	print(li2, "list + 5");

	std::cout << std::endl;

	//7---------------------------
	myCopy(arr2.begin(), arr2.end(), v2.begin());
	myCopy(li2.begin(), li2.end(), arr2.begin());
	print(arr2, "array copied: ");
	print(v2, "vector copied: ");
	//print(li2, "list copied: ");

	std::cout << std::endl;

	//8----------------------------
	std::vector<int>::iterator vit;
	vit = std::find(v2.begin(), v2.end(), 3);
	if (vit != v2.end())
		std::cout << "3 found at position: " << std::distance(v2.begin(), vit) << std::endl;
	else
		std::cout << "3 not found\n";

	std::list<int>::iterator lit;
	lit = std::find(li2.begin(), li2.end(), 27);
	if (lit != li2.end())
		std::cout << "27 found at position: " << std::distance(li2.begin(), lit) << std::endl;
	else
		std::cout << "27 not found\n";

	std::cin.get();
}
catch (const std::exception& e)
{
	std::cerr << "Exception: " << e.what() << std::endl;
	return 1;
}
catch (...)
{
	std::cerr << "Unknoen exception\n";
	return 2;
}