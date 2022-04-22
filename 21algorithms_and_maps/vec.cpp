#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include <algorithm>

// 1-------------------------------------------
struct Item
{
	std::string name;
	int iid;
	double value;
};

std::ostream &operator<<(std::ostream &os, const Item &it)
{
	return os << it.name << '\t'
			  << it.iid << '\t'
			  << it.value << '\n';
}

std::istream &operator>>(std::istream &is, Item &it)
{
	std::string ss;
	int ii;
	double dd;
	is >> ss >> ii >> dd;
	Item itt{ss, ii, dd};
	it = itt;
	return is;
}

// 4-------------------------------------------
struct CompByDecrValue
{
	bool operator()(const Item &a, Item &b)
	{
		return a.value > b.value;
	}
};

// 5-------------------------------------------
struct SmallerThan
{
private:
	double val;

public:
	SmallerThan(double vv) : val{vv} {}
	bool operator()(const Item &x) const { return x.value < val; }
};

// 6-------------------------------------------
struct CompByName
{
private:
	std::string name;

public:
	CompByName(const std::string &nn) : name{nn} {}
	bool operator()(const Item &x) const { return x.name == name; }
};

// 7-------------------------------------------
struct CompByiid
{
private:
	int iid;

public:
	CompByiid(int id) : iid(id) {}
	bool operator()(const Item &x) const { return x.iid == iid; }
};

template <typename C>
void print(const C &c, char sep = ' ')
{
	for (const auto &a : c)
		std::cout << a << sep;
	std::cout << std::endl;
}

int main()
try
{
	// 1------------------------------------------
	const std::string iname{"input.txt"};

	std::ifstream ifs{iname};
	if (!ifs)
		throw std::runtime_error("Couldn't read from file: " + iname);

	std::vector<Item> vi;
	for (Item ii; ifs >> ii;)
		vi.push_back(ii);

	for (int i = 0; i < vi.size(); i++)
		std::cout << vi[i];
	std::cout << '\n';

	// 8------------------------------------------
	std::list<Item> li(vi.size());
	std::copy(vi.begin(), vi.end(), li.begin());

	// 2------------------------------------------
	std::sort(vi.begin(), vi.end(),
			  [](const Item &a, const Item &b)
			  { return a.name < b.name; });

	// 3------------------------------------------
	std::sort(vi.begin(), vi.end(),
			  [](const Item &a, const Item &b)
			  { return a.iid < b.iid; });

	// 4------------------------------------------
	std::sort(vi.begin(), vi.end(), CompByDecrValue());
	for (int i = 0; i < vi.size(); i++)
		std::cout << vi[i];
	std::cout << '\n';

	// 5---------------------------------------
	Item tmp{"horse shoe", 99, 12.34};
	vi.insert(std::find_if(vi.begin(), vi.end(), SmallerThan(tmp.value)), tmp);

	tmp = Item{"Cannon S400", 9988, 499.95};
	vi.insert(std::find_if(vi.begin(), vi.end(), SmallerThan(tmp.value)), tmp);

	// 6------------------------------------------
	vi.erase(std::find_if(vi.begin(), vi.end(), CompByName("wine")));
	vi.erase(std::find_if(vi.begin(), vi.end(), CompByName("lighter")));

	// 7---------------------------------------
	vi.erase(std::find_if(vi.begin(), vi.end(), CompByiid(22)));
	vi.erase(std::find_if(vi.begin(), vi.end(), CompByiid(94)));

	// 8---------------------------------------
	print(li);

	li.sort([](const Item &a, const Item &b)
			{ return a.name < b.name; });
	li.sort([](const Item &a, const Item &b)
			{ return a.iid < b.iid; });
	li.sort([](const Item &a, const Item &b)
			{ return a.value > b.value; });
	print(li);

	tmp = {"horse shoe", 99, 1.34};
	li.insert(std::find_if(li.begin(), li.end(), SmallerThan(tmp.value)),
			  tmp);

	tmp = {"Canon S400", 9988, 499.95};
	li.insert(std::find_if(li.begin(), li.end(), SmallerThan(tmp.value)),
			  tmp);

	li.erase(std::find_if(li.begin(), li.end(), CompByName("wine")));
	li.erase(std::find_if(li.begin(), li.end(), CompByName("lighter")));

	li.erase(std::find_if(li.begin(), li.end(), CompByiid(22)));
	li.erase(std::find_if(li.begin(), li.end(), CompByiid(94)));

	print(li);

	std::cin.get();
}
catch (std::exception &e)
{
	std::cerr << " Exception: " << e.what() << std::endl;
	std::cin.get();
	return 1;
}
catch (...)
{
	std::cerr << "Some exception\n";
	std::cin.get();
	return 2;
}