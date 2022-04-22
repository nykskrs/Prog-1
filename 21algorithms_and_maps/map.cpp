#include <iostream>
#include <map>
#include <numeric>

//3-------------------------------------------
template<typename T, typename U>
void print(const std::map<T, U>& m)
{
	std::cout << "CONTENT:\n";

	for (const auto& a : m)
		std::cout << a.first << '\t' << a.second << std::endl;
	std::cout << "END\n";
}

//5-------------------------------------------
void read(std::map<std::string, int>& m)
{
	std::string s;
	int i = 0;

	std::cout << "\nEnter 10 string-int pairs:\n";

	while (m.size() < 10) 
	{
		std::cin >> s >> i;
		m.insert(std::make_pair(s, i));
	}
	std::cin.get();
}

template<class T>
struct MapAdd
{
	T operator()(T v, const std::pair<std::string, T>& p)
	{
		return v + p.second;
	}
};

int main()
try
{
	//1------------------------------------------
	std::map<std::string, int> msi;

	//2------------------------------------------
	msi["lecture"] = 21;
	msi["book"] = 24;
	msi["knife"] = 16;
	msi["bread"] = 58;
	msi["phone"] = 4;
	msi["water"] = 82;
	msi["wine"] = 38;
	msi["pillow"] = 14;
	msi["picture"] = 83;
	msi["can"] = 69;

	//3---------------------------------------
	print(msi);

	//4---------------------------------------
	msi.erase(msi.begin(), msi.end());

	print(msi);

	//6---------------------------------------
	read(msi);

	//7---------------------------------------
	print(msi);

	//8---------------------------------------
	int msiSum = 0;
	msiSum = std::accumulate(msi.begin(), msi.end(), msiSum, MapAdd<int>());

	std::cout << "Sum of integers: " << msiSum << std::endl;

	//9---------------------------------------
	std::map<int, std::string> mis;

	//10--------------------------------------
	for (const auto& a : msi)
		mis[a.second] = a.first;

	//11--------------------------------------
	print(mis);

	std::cin.get();
}
catch (std::exception& e)
{
	std::cerr << "Exception: " << e.what() << std::endl;
	std::cin.get();
	return 1;
}
catch (...)
{
	std::cerr << "Some exception\n";
	std::cin.get();
	return 2;
}