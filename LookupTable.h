#pragma once
#include <vector>
#include <stdexcept>
class LookupTable
{
public:
	LookupTable(const std::vector<double>& x, const std::vector<double>& y);
	double get(const double t);

private:
	std::vector<double> x;
	std::vector<double> y;
};
