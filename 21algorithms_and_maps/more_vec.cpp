#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>

struct LessThan
{
private:
	double v;
public:
	LessThan(double vv) : v{ vv } { }
	bool operator()(const double val) { return val < v; }
};

template<typename C>
void print(const C& c, char sep = '\n')
{
	std::cout << "CONTENT:\n"
		<<"=============================\n";

	for (const auto& a : c)
		std::cout << a << sep;

	std::cout << "END\n=============================\n";
}

int main()
{
	//1------------------------------------------
	const std::string iname{ "input_float.txt" };
	std::ifstream ifs{ iname };
	if (!ifs) throw std::runtime_error("Couldn't open file: " + iname);
	
	std::vector<double> vd;
	for (double d; ifs >> d;)
		vd.push_back(d);

	//2------------------------------------------
	print(vd);

	//3------------------------------------------
	std::vector<int> vi(vd.size());
	std::copy(vd.begin(), vd.end(), vi.begin());


	//4------------------------------------------
	for (int i = 0; i < vd.size(); ++i)
		std::cout << vd[i] << '\t' << vi[i] << std::endl;

	//5------------------------------------------
	double doubleSum = std::accumulate(vd.begin(), vd.end(), 0.0);

	std::cout << "std::vector<double> sum: " << doubleSum << std::endl;

	//6------------------------------------------
	double sumDiff = std::inner_product(vd.begin(), vd.end(), vi.begin(), 0.0, std::plus<double>(), std::minus<double>());

	std::cout << "Difference between sum of vd and sum of vi: " << sumDiff << std::endl;

	//7------------------------------------------
	std::reverse(vd.begin(), vd.end());

	print(vd);

	//8------------------------------------------
	double vdMean = doubleSum / vd.size();

	std::cout << "Mean of vd: " << vdMean << std::endl;

	//9------------------------------------------
	std::vector<double> vd2;

	for (const auto& a : vd)
	{
		if (a < vdMean)
			vd2.push_back(a);
	}
	print(vd2);

	//10-----------------------------------------

	print(vd);


	std::cin.get();
}